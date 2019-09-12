#include<ulib.h>
int main(u64 arg1, u64 arg2, u64 arg3, u64 arg4, u64 arg5)
{
    int pid;
    char buf1[20];
    char *file1="test.txt";
    char *file2="test2.txt";
    char *file3="test3.txt";

    char *buf = "Hello, I am file!";
    int fd_1 = open(file1, O_CREAT|O_RDWR, O_READ|O_WRITE);
    printf("%d\n",get_stats());
    
    int fd_2 = open(file1, O_RDONLY); 
    printf("%d %d\n",get_stats(),fd_2);
    
    int fd_3 = open(file1, O_RDWR); 
    printf("%d %d\n",get_stats(),fd_3);
    
    int fd_4 = open(file1, O_WRONLY); 
    printf("%d %d\n",get_stats(),fd_4);
    
    int fd_5 = open(file2, O_CREAT|O_RDWR, O_READ);
    printf("%d %d\n",get_stats(),fd_5); 
    
    int fd_6 = open(file2, O_CREAT|O_RDWR, O_READ|O_WRITE);
    printf("%d %d\n",get_stats(),fd_6);

    int fd_7 = open(file2, O_CREAT|O_WRONLY, O_READ|O_WRITE);
    printf("%d %d\n",get_stats(),fd_7); 

int fd_8 = open(file2, O_CREAT|O_RDONLY, O_READ|O_WRITE);
    printf("%d %d\n",get_stats(),fd_8); 

int fd_9 = open(file3, O_CREAT|O_RDONLY, O_WRITE);
    printf("%d %d\n",get_stats(),fd_9); 
    
    int fd_10 = open(file3, O_CREAT|O_RDWR, O_READ|O_WRITE);
    printf("%d %d\n",get_stats(),fd_10);

    int fd_11 = open(file3, O_CREAT|O_WRONLY, O_READ|O_WRITE);
    printf("%d %d\n",get_stats(),fd_11); 

int fd_12 = open(file3, O_CREAT|O_RDONLY, O_READ|O_WRITE);
    printf("%d %d\n",get_stats(),fd_12); 


    close(fd_1);
    printf("%d\n",get_stats()); 
    close(fd_2);
    printf("%d\n",get_stats()); 
    close(fd_3);
    //Below printf will be printing 3 because of Standard file descriptor(STDIN, STDOUT, STDERROR)
    printf("%d\n",get_stats());
    return 0;
}
