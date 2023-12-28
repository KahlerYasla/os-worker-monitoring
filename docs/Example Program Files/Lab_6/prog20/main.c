#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[],char ** envp)
{
    char *newargv[2];
      int i;

      newargv[0] = "Maasallah";
      newargv[1] = "3";
      newargv[2] = NULL;

      printf("Ana program:getpid: %d  getpppid: %d\n", getpid(), getppid());
      int f;
      f= fork();
      if(f==0)
      {
          printf("Ana program: Exec calisti\n");

          i = execve("prog20_2", newargv,envp);
          perror("exec2: execve failed\n");

      }
      else
      {
          printf("Ana: Alt programı bekliyorum...\n");
          wait(&i); // forku bekle

          printf("Ana program: alt program bitirdi\n");

      }


    return 0;
}
