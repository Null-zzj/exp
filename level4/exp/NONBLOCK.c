/*************************************************************************
	> File Name: NONBLOCK.c
	> Author: hank
	> Mail: zhenghuanke@hikvision.com 
	> Created Time: Fri Jun 30 13:12:35 2023
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>


int main(int argc, char *argv[])
{
	char buf[128] = {0};
	int flag;

	flag = fcntl(STDIN_FILENO, F_GETFD);
	if(flag == -1)
	{
		perror("fcntl get");
		return -1;
	}
	flag |= O_NONBLOCK;
	
	int ret = fcntl(STDIN_FILENO, D_SETFD, flag);
	if(ret == -1)
	{
		perror("fcntl set");
		return -1;
	}
tothis:
	ret = read(STDIN_FILENO, buf, sizeof(buf));
	

	return 0;
}
