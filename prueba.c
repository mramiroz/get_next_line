#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd = open("archivo.txt", O_RDONLY);
	int n;
	n = read(fd, 0, BUFFER_SIZE);
	printf("%i\n", n);
	n = read(fd, 0, BUFFER_SIZE);
	printf("%i\n", n);
}