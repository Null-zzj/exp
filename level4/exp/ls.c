/*************************************************************************
	@File Name: ls.c
	@Author: Null-zzj
	@Mail:  
	@Created Time: Fri Jun 30 16:14:57 2023
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <dirent.h>
#include <sys/types.h>
int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("input err");
		return -1;
	}	
	
	DIR* dp = opendir(argv[1]);
	if(dp == NULL)
	{	
		perror("dir");
	}
	struct dirent* sdp;
	while((sdp = readdir(dp)) != NULL)
	{
		printf("%s\n", sdp->d_name);
	}



	return 0;
}
