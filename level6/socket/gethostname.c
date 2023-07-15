#include <stdio.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main()
{
    struct hostent* hp = gethostbyname("www.baidu.com");
    if(NULL == hp)
    {
        herror("gethostbytename");
        return -1;
    }

    printf("hname: %s\n", hp->h_name);
    
    char **p = hp->h_aliases;
    while(*p)
    {
        printf("h_aliases: %s\n", *p);
        p++;
    }


    switch (hp->h_addrtype)
    {
        case AF_INET: printf("IPv4\n"); break;
        case AF_INET6: printf("IPv6\n"); break;
        default: break;
    }

    p = hp->h_addr_list;
    while(*p)
    {
        struct in_addr addr;
        addr.s_addr = *(int*)(*p);
        printf("addr_list: %s\n", inet_ntoa(addr));
        p++;
    }



    return 0;
}
