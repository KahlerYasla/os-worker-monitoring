/* This program forks off two threads which share an integer,
   on which there is a race condition. */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//global degisken
int value=0;
void *threadfonk(int tid)
{

    for (int var = 0; var < 1000000; ++var) {
       value=1;
       //sleep(tid);
        sleep(1);
       if(value==0)
       printf("%d. Deneme %d. Thread Value Set= %d\n",var,tid, value);

       value=0;
      //sleep(tid);
      sleep(1);
       if(value==1)
       printf("%d. Deneme %d. Thread Value Reset= %d\n",var, tid, value);

    }

  return NULL;
}


int main(int argc, char **argv)
{
  pthread_t tids[2];
  void * status;

  pthread_create(tids, NULL, threadfonk, 1);
  pthread_create(tids+1, NULL, threadfonk, 2);

  pthread_join(tids[0], &status);
  pthread_join(tids[1], &status);

  exit(0);

  return 0;
}

