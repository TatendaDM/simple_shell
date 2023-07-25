#include "shell.h"

/**
 * sigintHandler - Handles the SIGINT signal
 * @sig_num: The signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused)) int sig_num)
{
    _puts("\n");
    _puts("$ ");
    _putchar(BUF_FLUSH);
}

/**
 * readBuffer - Reads data into a buffer
 * @info: Parameter struct
 * @buffer: Buffer to store data
 * @size: Size of the buffer
 *
 * Return: Number of bytes read
 */
ssize_t readBuffer(info_t *info, char *buffer, size_t *size)
{
    ssize_t bytesRead = 0;

    if (*size)
        return 0;

    bytesRead = read(info->readfd, buffer, READ_BUF_SIZE);
    if (bytesRead >= 0)
        *size = bytesRead;

    return bytesRead;
}

/**
 * processInputBuffer - Processes the input buffer for linked or chained commands
 * @info: Parameter struct
 * @buffer: Address of the buffer
 * @length: Address of the length variable
 *
 * Return: Number of bytes read
 */
ssize_t processInputBuffer(info_t *info, char **buffer, size_t *length)
{
    ssize_t bytesRead = 0;
    size_t length_p = 0;

    if (!*length) { /* If there is nothing left in the buffer, fill it */
        free(*buffer);
        *buffer = NULL;
        signal(SIGINT, sigintHandler);
#if USE_GETLINE
        bytesRead = getline(buffer, &length_p, stdin);
#else
        bytesRead = _getline(info, buffer, &length_p);
#endif
        if (bytesRead > 0) {
            if ((*buffer)[bytesRead - 1] == '\n') {
                (*buffer)[bytesRead - 1] = '\0'; /* Remove trailing newline */
                bytesRead--;
            }
            info->linecount_flag = 1;
            remove_comments(*buffer);
            build_history_list(info, *buffer, info->histcount++);
            /* if (_strchr(*buffer, ';')) is this a command chain? */
            {
                *length = bytesRead;
                info->cmd_buf = buffer;
            }
        }
    }
    return bytesRead;
}

/**
 * getInput - Retrieves input from the user
 * @info: Parameter struct
 *
 * Return: Number of bytes read
 */
ssize_t getInput(info_t *info)
{
    static char *chainBuffer; /* The ';' command chain buffer */
    static size_t currentIndex, chainIndex, bufferLength;
    ssize_t bytesRead = 0;
    char **bufferPointer = &(info->arg), *currentPosition;

    _putchar(BUF_FLUSH);
    bytesRead = processInputBuffer(info, &chainBuffer, &bufferLength);
    if (bytesRead == -1) { /* If the value of bytesRead is -1, indicating EOF */
        return -1;
    }
    if (bufferLength) { /* If there are remaining commands in the chain buffer */
        chainIndex = currentIndex; /* Set the value of chainIndex to the current position in the buffer */
    }
    currentPosition = chainBuffer + currentIndex; /* Get pointer for return */

    check_chain(info, chainBuffer, &chainIndex, currentIndex, bufferLength);
    while (chainIndex < bufferLength) { /* Iterate to semicolon or end */
        if (is_chain(info, chainBuffer, &chainIndex))
            break;
        chainIndex++;
    }

    currentIndex = chainIndex + 1; /* Increment past nulled ';' */
    if (currentIndex >= bufferLength) { /* Reached end of buffer? */
        currentIndex = bufferLength = 0; /* Reset position and length */
        info->cmd_buf_type = CMD_NORM;
    }

    *bufferPointer = currentPosition; /* Pass back pointer to current command position */
    return _strlen(currentPosition); /* Return length of current command */
}
