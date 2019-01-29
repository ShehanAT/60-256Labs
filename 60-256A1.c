#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
void writeFunction();
void getDimens();
	double fileSize1 = 0, fileSize2 = 0, fileSize3 = 0; 
	double fd1, fd2, fd3;
	char height1[100], width1[100];
	int height2, width2;
	char buffer2[3];
int main(int argc, char *argv[]){
	


	//getDimens();
	writeFunction();
	// lseek(fd2, 0, SEEK_SET);
	// lseek(fd3, fileSize2, SEEK_SET);
	// read(fd2, buffer, fileSize2);
	// write(fd3, &buffer, fileSize2);
   
}
void getDimens(){
	fd1 = open("/Users/shehanatukorala/Desktop/Desktop/img1.ppm", O_RDONLY);
	fd2 = open("/Users/shehanatukorala/Desktop/Desktop/img2.ppm", O_RDONLY);
	fd3 = open("/Users/shehanatukorala/Desktop/Desktop/img3.ppm", O_CREAT | O_WRONLY , 0755);
	lseek(fd2, 0, SEEK_SET);
	read(fd1, &height1, 60);
	lseek(fd1, 0, SEEK_SET);
	lseek(fd3, 0, SEEK_SET);
	write(fd3, &height1, 60);
	write(fd3, "\n", 1);
	lseek(fd3, 60, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);
	read(fd2, &height1, 60);
	write(fd3, &height1, 60);
while(read(fd2, &buffer2, 1) > 0){
		fileSize2++;//fd1 file size
	}
	printf("%d\n", fileSize2);
	printf("%s\n", height1);
	printf("%s\n", width1);

	height2 = (int)height1;
	width2 = (int) width1;
}
void writeFunction(){
	fd1 = open("/Users/shehanatukorala/Desktop/Desktop/img1.ppm", O_RDONLY);
	fd2 = open("/Users/shehanatukorala/Desktop/Desktop/img2.ppm", O_RDONLY);
	fd3 = open("/Users/shehanatukorala/Desktop/Desktop/img3.ppm", O_CREAT | O_WRONLY | O_TRUNC , 0755);
	while(read(fd1, &buffer2, 3) > 0){
		fileSize1++;//fd1 file size
	}
	while(read(fd2, &buffer2, 3) > 0){
		fileSize2++;
	}
	printf("fileSize1: %f, fileSize2: %f", fileSize1, fileSize2);
//img1 dimens: 1080 792 = 855360
//img2 dimens: 1001 667 = 667667
	char buffer[3];
	lseek(fd1, 0, SEEK_SET);
	lseek(fd3, -fileSize2, SEEK_END);
	for(int i = 0;  i < fileSize1; i++){
		read(fd1, buffer, 3);
		write(fd3, &buffer, 3);
	}
	double count = 2.5;
	double counter = (fileSize1*2.5);
	lseek(fd3, -counter, SEEK_END);
	lseek(fd2, 0, SEEK_SET);
	for(int j = 0 ; j < 5; j++){
		for(int i =0; i < 1001; i++){
				read(fd2, buffer, 3);
				write(fd3, &buffer, 3);
		}
		lseek(fd3, -(counter+((1080-1001)*3)), SEEK_END);
	}		
	
	
	//	counter+= 792;
//	lseek(fd3, counter, SEEK_SET);
	//	
	//}
	
	
	// for(int i = 0; i < 1001; i++){
	// 	read(fd2, buffer, 3);
	// 	write(fd3, &buffer, 3);
	// }


	close(fd1);
    close(fd2);
    close(fd3);
}
