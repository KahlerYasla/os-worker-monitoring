#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int strtoint( char* charnums)
{
 int number=0;
 int index=0;
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {

    if(!number)
        number= ( (int) charnums[index]) - 48;
    else
    {
        number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
         }
         else
         {
            number=-1;
            printf("\nGecersiz islem");
            break;
         }
 }
 return number;
}



int main(int argc, char *argv[])
{

  char s[1000];
  int pipefd[2];
  //pipefd[0]=strtoint(argv[0]);
 // pipefd[1]=strtoint(argv[1]);
    printf("Alt program:getpid: %d  getpppid: %d\n", getpid(), getppid());
    fgets(s, 1000, stdin);
    write(4, s, strlen(s));




    return 0;
}

