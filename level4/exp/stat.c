/*************************************************************************
	@File Name: stat.c
	@Author: Null-zzj
	@Mail:  
	@Created Time: Fri Jun 30 13:49:26 2023
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat buf;
	int ret = stat("1.txt", &buf);
    
    // switch(buf.st_mode & S_IFMT)
    // {
    //     case S_IFSOCK: printf("s"); break;
    //     case S_IFLNK: printf("l"); break;
    //     case  S_IFREG: printf("-"); break;
    //     case S_IFBLK: printf("b"); break;
    //     case  S_IFDIR: printf("d"); break;
    //     case  S_IFCHR: printf("c"); break;
    //     case  S_IFIFO: printf("p"); break;
    // }


        printf("%o\n", buf.st_mode);
        printf("%o\n", S_IRWXU);
        printf("%o\n", S_IRUSR);
        printf("%o\n", buf.st_mode & S_IRWXU);
        printf("%x\n", buf.st_mode & S_IRWXU == S_IRUSR);
        
        
  

    






	

	return 0;
}
