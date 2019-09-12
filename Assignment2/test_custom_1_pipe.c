#include<ulib.h>


int main(u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5)
{
  int pid;
  char buf1[20];
  char buf2[4095];
  int pipes[2];

  if(pipe(pipes) == -1)
  {
    return 0;
  }

  pid = fork();
  
  if(pid == 0){
     char *buf = "Hello, I am file!";
     close(pipes[0]);
     printf("C:%d\n", write(pipes[1], buf, 17));
     sleep(10);
      for(int i=0;i<4095;i++){
        buf2[i]='0';
      }
     printf("C:%d\n", write(pipes[1], buf2, 4095));

     // Below printf will be printing -1, Because read fd is closed already
     printf("C:%d\n", read(pipes[0], buf1, 5));
     exit(0);
  }else{
     sleep(5);
     close(pipes[1]);
     
     printf("P:%d\n", read(pipes[0], buf1, 20));
     sleep(50);
     printf("P:%d\n", read(pipes[0], buf2, 4095));

    // Below printf will be printing -1, Because write fd is closed already
     printf("P:%d\n", write(pipes[1], buf1, 10));
     buf1[20] = 0;
     printf("P:%s\n", buf1);
     close(pipes[0]);
  }
}
