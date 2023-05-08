#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - function that reads a text file
 * and prints it to the POSIX standard output.
 * @filename: pointer to the filename
 * @letters: is the number of letters it should read and print
 * Return: 0 if filename is Null
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
ssize_t num_read = 0;
char *buf = malloc(sizeof(char) * (letters + 1));
int fd;

if (filename == NULL || buf == NULL)
{
free(buf);
return (0);
}
fd = open(filename, O_RDONLY);
if (fd == -1)
{
free(buf);
return (0);
}
num_read = read(fd, buf, letters);
if (num_read == -1)
{
free(buf);
close(fd);
return (0);
}
buf[num_read] = '\0';
num_read = write(STDOUT_FILENO, buf, num_read);
if (num_read == -1 || num_read != (ssize_t) letters)
{
free(buf);
close(fd);
return (0);
}
free(buf);
close(fd);
return (num_read);
}
