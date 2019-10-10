#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd = open("../text.txt",O_RDWR);
	if(fd == -1)
		return 1;

	char buffer[100];
	int size = read(fd,buffer,sizeof(buffer)-1);
	if(size == -1)
		return 1;

	buffer[size] = '\0';
	printf("data read:%s\n",buffer);

	sprintf(buffer,"hello world write from file I/O using linux c");

	size = write(fd,buffer,45);
	if(size == -1)
		return -1;
	close(fd);
	fd = open("../text.txt",O_RDONLY);

	size = read(fd,buffer,sizeof(buffer)-1);
        if(size == -1)
                return 1;

        buffer[size] = '\0';
        printf("data read:%s\n",buffer);

	close(fd);
	return 0;

}

