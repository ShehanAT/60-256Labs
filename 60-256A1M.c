#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
void writeFunction();
unsigned convertHeightToInt(char a[], unsigned b);
unsigned convertWidthToInt(char a[], unsigned b);
unsigned concatenate(unsigned x, unsigned y);
void getDimens();
	int fd1, fd2, fd3;
	char file2Height[10], file2Width[100];
	unsigned file2H, file2W;
	char file1Height[10], file1Width[10];
	unsigned file1H, file1W;
	char buffer2[3];
	unsigned count;
int main(int argc, char *argv[]){
	getDimens();
	file2H = (int)convertHeightToInt(file2Height, file2H);
	file2W = (int)convertWidthToInt(file2Width, file2W);
	file1H = (int)convertHeightToInt(file1Height, file1H);
	file1W = (int)convertWidthToInt(file1Width, file1W);
	writeFunction();
	
}
void getDimens(){
	fd1 = open("../stop11.ppm", O_RDONLY);//change before submit
	fd2 = open("../stop12.ppm", O_RDONLY);//change before submit
	lseek(fd2, 48, SEEK_SET);//change before submit
	read(fd2, &file2Width, 4);
	lseek(fd2, 53, SEEK_SET);//change before submit
	read(fd2, &file2Height, 3); 
	lseek(fd1, 48, SEEK_SET);//change before submit
	read(fd1, &file1Width, 4);
	lseek(fd1, 53, SEEK_SET);//change before submit
	read(fd1, &file1Height, 3);

}
void writeFunction(){
	fd1 = open("../stop11.ppm", O_RDONLY);//change before submit
	fd2 = open("../stop12.ppm", O_RDONLY);//change before submit
	fd3 = open("../stop13.ppm", O_CREAT | O_WRONLY , 0777);//change before submit
	 char buffer[3];
	lseek(fd1, 0, SEEK_SET);
	lseek(fd3, 0, SEEK_SET);
	
	for(int i = 0;  i < file1W; i++){
		for(int j = 0 ; j < file1W; j++){
			read(fd1, buffer, 3);
			write(fd3, &buffer, 3);
		}
	}
	 int counter = (file1W - file2W)*3;
	 lseek(fd3,counter+61, SEEK_SET);
	 lseek(fd2, 61, SEEK_SET);
	int quit = 1;
	int f2Width = 0;
	
	for(int i = 0 ; i < file2H; i++){
		for(int j= 0 ; j < file2W; j++){
			read(fd2, buffer, 3);
			write(fd3, buffer, 3);
		}
		lseek(fd3, (counter), SEEK_CUR);
	}
	close(fd1);
    close(fd2);
    close(fd3);
}

unsigned concatenate(unsigned x, unsigned y){
	unsigned pow = 10;
//	printf("%d, %d\n",x,y);
	while(y >= pow){
		pow *= 10;
		printf("%d\n", y);
	}
	return x * pow + y;
}
unsigned convertHeightToInt(char a[],  unsigned b){
	unsigned count;
	b = (int)a[0]-'0';
	for(int i = 1 ; i< 3; i++){
		b = concatenate(b, (int)a[i]-'0');
	}
	return b;
}
unsigned convertWidthToInt(char a[],  unsigned b){
	unsigned count;
	b = (int)a[0]-'0';
	for(int i = 1 ; i< 4; i++){
		b = concatenate(b, (int)a[i]-'0');
	}
	return b;
}
