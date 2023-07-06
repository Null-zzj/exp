/*********************************************
* @FileName: ls-l.c
* @Author: Null-zzj
* @Mail: zj.zhu.cn@gmail.com
* @CreatedTime: Sun Jul 02 20:40:47 2023
* @Descript:
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<time.h>
#include<dirent.h>
#include<string.h>

void printFileMessage(char* filename, char* filename1)
{
	struct stat buf;
	int ret = stat(filename, &buf);

	switch(buf.st_mode & S_IFMT)
    {
        case S_IFSOCK: printf("s"); break;
        case S_IFLNK: printf("l"); break;
        case S_IFREG: printf("-"); break;
        case S_IFBLK: printf("b"); break;
        case S_IFDIR: printf("d"); break;
        case S_IFCHR: printf("c"); break;
        case S_IFIFO: printf("p"); break;
    }

    printf(buf.st_mode & S_IRUSR ? "r" : "-");
    printf(buf.st_mode & S_IWUSR ? "w" : "-");
    printf(buf.st_mode & S_IXUSR ? "x" : "-");

    printf(buf.st_mode & S_IRGRP ? "r" : "-");
    printf(buf.st_mode & S_IWGRP ? "w" : "-");
    printf(buf.st_mode & S_IXGRP ? "x" : "-");    
    
    printf(buf.st_mode & S_IROTH ? "r" : "-");
    printf(buf.st_mode & S_IWOTH ? "w" : "-");
    printf(buf.st_mode & S_IXOTH ? "x" : "-");

    printf("   %-4ld", buf.st_nlink);
    printf(" zzj  zzj  ");
    printf("%-9ld", buf.st_size);

    struct tm*  tim = localtime(&buf.st_ctim.tv_sec);
    char buff[20];
    strftime(buff, sizeof(buff), "%b %d %R", tim);

    printf("%s %s\n", buff, filename1);
    
}


int main(int argc, char *argv[])
{
    DIR* dp;
    if(argc >= 2)
        dp = opendir(argv[1]);
    else
        dp = opendir(".");
    
    char buf[1024] = {0};
    struct dirent *sdp;
    while((sdp = readdir(dp)) != NULL)
    {
        sprintf(buf, "%s/%s", argv[1], sdp->d_name);
        printFileMessage(buf, sdp->d_name);
    }
    closedir(dp);

	return 0;
}
