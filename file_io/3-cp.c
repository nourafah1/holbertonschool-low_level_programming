#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * close_file - closes a file descriptor
 * @fd: file descriptor
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_file - copies content from one file to another
 * @file_from: source file descriptor
 * @file_to: destination file descriptor
 * @from_name: source file name
 * @to_name: destination file name
 */
void copy_file(int file_from, int file_to, char *from_name, char *to_name)
{
	ssize_t r, w;
	char buffer[BUFFER_SIZE];

	r = read(file_from, buffer, BUFFER_SIZE);
	while (r > 0)
	{
		w = write(file_to, buffer, r);
		if (w == -1 || w != r)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to_name);
			exit(99);
		}
		r = read(file_from, buffer, BUFFER_SIZE);
	}
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from_name);
		exit(98);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (file_to == -1)
	{
		close_file(file_from);
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	copy_file(file_from, file_to, argv[1], argv[2]);
	close_file(file_from);
	close_file(file_to);
	return (0);
}
