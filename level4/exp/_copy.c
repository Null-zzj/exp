#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main(int argc, char* argv[])
{
	if(argc != 3)
	{
		printf("input err");
		return -1;
	}

	int fd1 = open(argv[1], O_RDONLY);
	if(fd1 == -1)
	{
		perror("read");
	}
	int fd2 = open(argv[2], O_WRONLY | O_CREAT, 0664);	
	if(fd2 == -1)
	{
		perror("read");
	}
	char buf[1024] = {0};
	int ret;
	while((ret = read(fd1, buf, sizeof(buf))) != 0)
	{
		if(ret == -1){
			perror("read");
			return -1;
		}
		write(fd2, buf, ret);
	}


	return 0;
}
