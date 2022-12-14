#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	static char *ptr;
	
	int fd = open("archivo.txt", O_RDONLY);
	int nb = read(fd, ptr, 2);
	printf("%s", ptr);
}