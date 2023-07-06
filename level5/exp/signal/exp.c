/*********************************************
 * @FileName: signal.c
 * @Author: Null-zzj
 * @Mail: zj.zhu.cn@gmail.com
 * @CreatedTime: Tue Jul 04 11:30:20 2023
 * @Descript:
 */

#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void letsgo(int sig);
void stopbus(int sig);
void getout(int sig);
void getSIGINT(int sig);
void getSIGQUIT(int sig);
void getSIGTSTP(int sig);
void driver();
void ticketseller();

pid_t pid;
int main(int argc, char *argv[]) {

  if ((pid = fork()) < 0)
    ;
  else if (pid == 0)
    ticketseller();

  driver();

  return 0;
}

void letsgo(int sig) { printf("let’s gogogo\n"); }

void stopbus(int sig) { printf("stop the bus\n"); }

void getout(int sig) { printf("please get off the bus\n"); }

void getSIGINT(int sig) { kill(getppid(), SIGUSR1); }

void getSIGQUIT(int sig) { kill(getppid(), SIGUSR2); }

void getSIGTSTP(int sig) { kill(getpid() + 1, SIGUSR1); }

void driver() {
  signal(SIGTSTP, getSIGTSTP);
  signal(SIGUSR1, letsgo);
  signal(SIGUSR2, stopbus);
  while (1)
    ;
}

void ticketseller() {
  signal(SIGINT, getSIGINT);
  signal(SIGQUIT, getSIGQUIT);
  signal(SIGUSR1, getout);
  while (1)
    ;
}
