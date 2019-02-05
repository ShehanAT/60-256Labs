#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
 
int isprime(int n) {
    int i;
    if (n <= 1) {return 0;}
    for (i=2; i*i <= n; i++) {
    if (n % i == 0){ return 0;}   
    }
    return 1;
}
int main(int argc, char *argv[]){
    pid_t npid;
    int fd1 = open("./data.txt", O_CREAT | O_RDWR , 0777);
   // npid = fork();//child process in now 93420 for npid
    int num;
    char buffer[2];
    char buffer2[2];
    printf("Enter number from 1 to 15\n");
    scanf("%s", &buffer);
    num = atoi(&buffer);
    //itoa(num, buffer, 2);
    // for ( int i = 0; i < 2 ; i++ )
    // {
    //     buffer[i] = num % 10;
    // }
    npid = fork();
    if(num < 15 && num > 1){
        if(npid > 0){
            fd1 = open("/Users/shehanatukorala/Desktop/Desktop/60-256Labs/data.txt", O_CREAT | O_RDWR , 0777);
            //num = num + '0';
            write(fd1, &buffer, 8);
            close(fd1);
            exit(0);
        } 
        if(npid == 0){
            sleep(1);
            fd1 = open("/Users/shehanatukorala/Desktop/Desktop/60-256Labs/data.txt", O_CREAT | O_RDWR , 0777);
            if(read(fd1, &buffer2, 8) < 0){
                printf("An error occured\n");
            }
            printf("%s\n", buffer2);
            int i = atoi(&buffer2);
            if(isprime(i)){
                printf("%d is a prime number", i);
            }else{
                printf("%d is not a prime number", i);
            }
            close(fd1);
            exit(0);
        }
    }else{
        perror("Invalid Number");
    }
   // exit(0);
}
