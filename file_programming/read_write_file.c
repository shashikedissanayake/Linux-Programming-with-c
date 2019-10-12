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

	sprintf(buffer,"hello world write from file I/O using linux c\n");

	size = write(fd,buffer,47);
	if(size == -1)
		return -1;
	if(lseek(fd,0,SEEK_SET) == -1)
		return -1;

	size = read(fd,buffer,sizeof(buffer)-1);
        if(size == -1)
                return 1;

        buffer[size] = '\0';
        printf("data read:%s\n",buffer);

	close(fd);
	return 0;

}

