#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
	
/**
 * create_file - function that creates a file
 * @filename: is the name of the file to create
 * @text_content: is a NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
int fd, ret_val, len = 0;
mode_t mode = S_IRUSR | S_IWUSR;

if (filename == NULL)
return (-1);

if (text_content != NULL)
while (text_content[len] != '\0')
len++;

fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
if (fd == -1)
return (-1);

if (text_content != NULL)
{
ret_val = write(fd, text_content, len);
if (ret_val == -1)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}
