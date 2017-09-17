/*
;************************************************************************************************************
;*					��Ƽ��˾
;*                                     	     �
;*
;*                            	     http://www.techshine.com
;*
;*--------------------------------------------- ��Ϣ ----------------------------------------------------
;*
;* ���: app_lcd.c
;* �� : �ļΪS3C2410Ӳƽ̨�LCD����
;* �� :
;*-------------------------------------------- ��汾�Ϣ -------------------------------------------------
;* ����: ARMС�
;* ����: 2004/09/09
;* 汾�� : V1.0.1
;*-------------------------------------------- �ʷ汾�Ϣ -------------------------------------------------
;* ��� : ARMС�
;* �� : 2004/09/09
;* 汾�� : v1.0.0
;*-----------------------------------------------------------------------------------------------------------
;*-----------------------------------------------------------------------------------------------------------
;************************************************************************************************************
;*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "typeMatrix.c"
#define SIZE 30
#define chang 450

int NUM = 1;

unsigned long backgroundColor=0xffffff;

struct zuobiao {
	int x;
	int y;
}date;
/*定义一个结构体*/

struct qi {
	int x;
	int y;
	int num;
};
struct zuobiao tmp;
struct zuobiao buf[13][13];
struct qi src[13][13];
struct arg
{
	unsigned long a;
	unsigned long b;
	unsigned long c;
	unsigned long d;
	unsigned long color;
};

void background(int fd) {// /*画棋盘*/
	int i;
	struct arg argA = { 30,30,420,0 };
	
	for (i = 1; i <= 15; i++) {
		ioctl(fd, 1, (unsigned long)&argA);
		argA.b = i * 30+30;
	}
	argA.b = 30;
	for (i = 1; i <= 15; i++) {
		ioctl(fd, 2, (unsigned long)&argA);
		argA.a = i * 30+30;
	}
}
void draw_Char(int x,int y,int fd_lcd,int rowCount,int ch[][8],unsigned long color){
	char binary[8];
	int temp,h=x,v=y;
	int i,j,k;
	struct arg arg8; 

	for (i=0;i<rowCount;i++){
		for (j=0;j<8;j++){
			temp=ch[i][j];
			if(j%(rowCount/4)==0){
				v++;
				h=x;
			}

			// hex to binary
			for(k=7;k>=0;k--){
				binary[k]=temp%2;
				temp/=2;
			}
			// draw pixel
			for(k=0;k<8;k++){
				arg8.a=h;
				arg8.b=v;
				if(binary[k]==1){
					arg8.color=color;
					ioctl(fd_lcd,9,(unsigned long)&arg8);
				}
				else{
					arg8.color=backgroundColor;
					ioctl(fd_lcd,10,(unsigned long)&arg8);
				}
				h++;
			}
		}
	}
}
void coordinate(void) {// /*将棋盘上的点存入数组*/
	int i, j;
	int m = 0, n = 0;
	for (i = SIZE; i < chang; i++) {
		for (j = SIZE; j < chang; j++) {
			if ((j = chang - SIZE) || ((j%SIZE) == 0) || ((i%SIZE) == 0)) {
				if (((j%SIZE) == 0) && ((i%SIZE) == 0)) {
					date.x = i;
					date.y = j;
					buf[m][n] = date;
					src[m][n].x = buf[m][n].x;
					src[m][n].y = buf[m][n].y;
					src[m][n].num = 0;
					if ((m == 13) && (n == 13)) {
						return;
					}
					n++;
					if (n == 13) {
						n = 0;
						m++;
					}
				}
			}
		}
	}
}


void draw_flag(int fd) {/*获胜标志*/
	int i;
	// struct arg argBh = { 30,90,450,270};
	// ioctl(fd, 7, (unsigned long)&argBh);
	for(i=0;i<=3;i++){
		draw_Char(480+i*30,60,fd,16,hanzi[i],0x99cc00);
	}
	draw_Char(450,120,fd,16,hanzi[4],0x99cc00);
	draw_Char(480,120,fd,8,shuzi[3],0x99cc00);
	draw_Char(510,120,fd,16,hanzi[5],0x99cc00);
	draw_Char(540,120,fd,16,hanzi[6],0x99cc00);
	draw_Char(570,120,fd,16,hanzi[7],0x99cc00);
	draw_Char(600,120,fd,16,hanzi[8],0x99cc00);
}

void white_win(int fd) {//白方赢
	draw_flag(fd);

}
void red_win(int fd) {//红方赢
	draw_flag(fd);
}
void win_or_lose(int fd) {//判赢
	int m, n;
	for (m = 0; m < 10; m++) {
		for (n = 0; n < 10; n++) {
			if ((src[m][n].num == 1) && (src[m][n + 1].num == 1) && (src[m][n + 2].num == 1) && (src[m][n + 3].num == 1) && (src[m][n + 4].num == 1)) {
				white_win(fd);
			}
			if ((src[m][n].num == 1) && (src[m + 1][n].num == 1) && (src[m + 2][n].num == 1) && (src[m + 3][n].num == 1) && (src[m + 4][n].num == 1)) {
				white_win(fd);
			}
			if ((src[m][n].num == 1) && (src[m + 1][n + 1].num == 1) && (src[m + 2][n + 2].num == 1) && (src[m + 3][n + 3].num == 1) && (src[m + 4][n + 4].num == 1)) {
				white_win(fd);
			}
			if ((src[m][n].num == 2) && (src[m][n + 1].num == 2) && (src[m][n + 2].num == 2) && (src[m][n + 3].num == 2) && (src[m][n + 4].num == 2)) {
				red_win(fd);
			}
			if ((src[m][n].num == 2) && (src[m + 1][n].num == 2) && (src[m + 2][n].num == 2) && (src[m + 3][n].num == 2) && (src[m + 4][n].num == 2)) {
				red_win(fd);
			}
			if ((src[m][n].num == 2) && (src[m + 1][n + 1].num == 2) && (src[m + 2][n + 2].num == 2) && (src[m + 3][n + 3].num == 2) && (src[m + 4][n + 4].num == 2)) {
				red_win(fd);
			}
		}
	}
	for (m = 9; m >= 0; m--) {
		for (n = 13; n >= 4; n--) {
			if ((src[m][n].num == 1) && (src[m + 1][n - 1].num == 1) && (src[m + 2][n - 2].num == 1) && (src[m + 3][n - 3].num == 1) && (src[m + 4][n - 4].num == 1)) {
				white_win(fd);
			}
			if ((src[m][n].num == 2) && (src[m + 1][n - 1].num == 2) && (src[m + 2][n - 2].num == 2) && (src[m + 3][n - 3].num == 2) && (src[m + 4][n - 4].num == 2)) {
				red_win(fd);
			}
		}
	}
}
void qikuang(int fd,struct arg argB1,struct arg argB2,struct arg argB3) {//棋框1 
	int m,n;
	struct arg argC2;
	struct arg arg1;
	// 清屏
	//ioctl(fd, 6, (unsigned long)&arg1);
	background(fd);

	ioctl(fd, 1, (unsigned long)&argB1);
	ioctl(fd, 1, (unsigned long)&argB2);
	ioctl(fd, 2, (unsigned long)&argB1);
	ioctl(fd, 2, (unsigned long)&argB3);
}
void qikuang2(int fd,struct arg argB1,struct arg argB2,struct arg argB3) {//棋框2 用来覆盖棋框1
	ioctl(fd, 11, (unsigned long)&argB1);
	ioctl(fd, 11, (unsigned long)&argB2);
	ioctl(fd, 21, (unsigned long)&argB1);
	ioctl(fd, 21, (unsigned long)&argB3);
}


void xuanweizhi(int fd) {//选位置 + 下子
	int fd1;
	int i;
	int m,n;
	struct arg argB2 = { 45,75,30 };
	struct arg argB1 = { 45,45,30 };
	struct arg argB3 = { 75,45,30 };
	struct arg arg6 = { 0,0,639,479 };
	//struct arg argB={225,220,30,30};
	struct arg argC = { };
	if ((fd1 = open("/dev/Kbd7279", 0)) < 0)
	{
		printf("cannot open /dev/Kbd7279\n");
		exit(0);
	}

	while (1) {
		i = ioctl(fd1, 0, 0);
		
		if (i == 6) {//上
			if ((argB1.b-30 )>30) {
				qikuang2(fd,argB1,argB2,argB3);
				argB1.b -= 30;
				argB2.b -= 30;
				argB3.b -= 30;
			}
			qikuang(fd,argB1,argB2,argB3);
		}
		if(i == 3){//重开
			for(m=0;m<=13;m++){
				for(n=0;n<=13;n++){
					src[m][n].num=0;
				}
			}
			ioctl(fd, 6, (unsigned long)&arg6);	
			background(fd);
			xuanweizhi(fd);
			//coordinate();
		}
		if (i == 4) {//下
			if ((argB1.b + 30) <420) {
				qikuang2(fd,argB1,argB2,argB3);
				argB1.b += 30;
				argB2.b += 30;
				argB3.b += 30;
			}
			qikuang(fd,argB1,argB2,argB3);
		}
		if (i == 9) {//左
			//argB1.a -= 30;
			if ((argB1.a -30)>30) {
				qikuang2(fd,argB1,argB2,argB3);
				argB1.a -= 30;
				argB2.a -= 30;
				argB3.a -= 30;
			}
			qikuang(fd,argB1,argB2,argB3);
		}
		if (i == 1) {//右
			if ((argB1.a + 30) <420) {
				qikuang2(fd,argB1,argB2,argB3);
				argB1.a += 30;
				argB2.a += 30;
				argB3.a += 30;
			}
			qikuang(fd,argB1,argB2,argB3);				
		}
		if (i == 5) {

			 argC.a = argB1.a + 15;
			 argC.b = argB1.b + 15;
			 argC.c = 15;
			 //ioctl(fd, 5, (unsigned long)&argC);
			m=argC.a/30;
			n=argC.b/30;
			// if (src[m][n].num !=0 )
			// 	return ;
			if (src[m][n].num == 0) {
				if (NUM == 1) {// 1 == NUM NUM.equal()
					src[m][n].num = 1;
					ioctl(fd, 5, (unsigned long)&argC);
					NUM = 2;
				
					
				}
				else {
					src[m][n].num = 2;
					ioctl(fd, 15, (unsigned long)&argC); 
					NUM = 1;
					
				}
			}
			win_or_lose(fd);	
			qikuang(fd,argB1,argB2,argB3);				
		}	
}
}
int main(void)
{
	int fd;
	int NUM = 1;
	struct arg arg6 = { 0,0,639,479 };
	// struct arg arg7 = { 100,100,500,400 };
	// struct arg arg8, arg9;

	struct zuobiao tmp;
	struct zuobiao buf[14][14];
	struct qi src[14][14];
	struct zuobiao cur[14][14];
	/*定义结构体变量*/

	if ((fd = open("/dev/S3C2410LCD", 0)) < 0)
	{
		printf("cannot open /dev/S3C2410LCD\n");
		exit(0);
	};
	//开始

	ioctl(fd, 6, (unsigned long)&arg6);	
	background(fd);
	xuanweizhi(fd);
	coordinate();
	close(fd);
	return 0;
}
