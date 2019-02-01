#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
void writeFunction();
void getFile1Dimens();
void getFile2Dimens();
unsigned convertHeightToInt(char a[], unsigned b);
unsigned convertWidthToInt(char a[], unsigned b);
unsigned concatenate(unsigned x, unsigned y);
void getDimens();
	int fd1, fd2, fd3;
	char file2Height[10], file2Width[100];
	unsigned file2H, file2W;
	char file1Height[10], file1Width[10];
	unsigned file1H, file1W;
	char* buffer2[100];
	unsigned count;
int main(int argc, char *argv[]){
	getFile1Dimens();
	getFile2Dimens();
	writeFunction();
	
}
void getFile1Dimens(){
	fd1 = open("../stop11.ppm", O_RDONLY);//change before submit
	fd2 = open("../stop12.ppm", O_RDONLY);//change before submit
	lseek(fd1, 0, SEEK_SET);
	read(fd1, &buffer2, 100);
	char *p = buffer2;
	int counter =0;
	while(*p){
		 if ( isdigit(*p)  && isdigit(*(p+1))) {
        	// Found a number
			counter++;
        	long val = strtol(p, &p, 10); // Read number
			if(counter == 1){
				file1W = val;
			}
			if(counter == 2){
				file1H = val;
			}
        	//printf("%ld\n", val); // and print it.
    	} else {
        // Otherwise, move on to the next character.
        	p++;
    	}
	}
}
void getFile2Dimens(){
	fd2 = open("../stop12.ppm", O_RDONLY);//change before submit
	lseek(fd2, 0, SEEK_SET);
	read(fd2, &buffer2, 100);
	char *p = buffer2;
	int counter =0;
	while(*p){
		 if ( isdigit(*p)  && isdigit(*(p+1))) {

			counter++;
        	long val = strtol(p, &p, 10); // Read number
			if(counter == 1){
				file2W = val;
			}
			if(counter == 2){
				file2H = val;
			}
     
    	} else {
 
        	p++;
    	}
	}

}


void writeFunction(){
	fd1 = open("../stop11.ppm", O_RDONLY);//change before submit
	fd2 = open("../stop12.ppm", O_RDONLY);//change before submit
	fd3 = open("../stop13.ppm", O_CREAT | O_WRONLY , 0777);//change before submit
	 char buffer[3];
	lseek(fd1, 0, SEEK_SET);
	lseek(fd3, 0, SEEK_SET);
	printf("%d %d\n", file1W, file1H);
	printf("%d %d\n", file2W, file2H);
	for(int i = 0;  i < file1H*3; i++){
		for(int j = 0 ; j < file1W*3; j++){
			read(fd1, buffer, 3);
			write(fd3, &buffer, 3);
		}
	}
	 int counter = (file1W - file2W)*3;
	 lseek(fd3,counter+61, SEEK_SET);//CHANGE 61 TO 15 
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



