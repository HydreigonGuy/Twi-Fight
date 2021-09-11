/*
** EPITECH PROJECT, 2021
** Adrien Lib
** File description:
** read_file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int check_for_empty_file(char *contents)
{
    if (contents[0] == '\0') {
        free(contents);
        return (1);
    }
    return (0);
}

char *read_file(char *file_name)
{
    int file_descriptor = open(file_name, O_RDONLY);
    char *file_content = NULL;
    struct stat buffer;

    if (file_descriptor == -1)
        return (NULL);
    if (stat(file_name, &buffer) == -1)
        return (NULL);
    file_content = malloc(sizeof(char) * (buffer.st_size + 1));
    if (!file_content)
        return (NULL);
    if (read(file_descriptor, file_content, buffer.st_size) == -1) {
        free(file_content);
        return (NULL);
    }
    if (check_for_empty_file(file_content))
        return (NULL);
    file_content[buffer.st_size] = '\0';
    close(file_descriptor);
    return (file_content);
}