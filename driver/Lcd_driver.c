/*
;************************************************************************************************************
;*				        �������Ǵ�ʢ�Ƽ����޹�˾
;*                                     	     ��    ��    ��
;*
;*                                 	     http://www.techshine.com
;*
;*--------------------------------------------- �ļ���Ϣ ----------------------------------------------------
;*
;* �ļ����� : LCDdriver.c
;* �ļ����� : ���ļ�ΪS3C2410Ӳ��ƽ̨���þ��庯���ĳ�ʼ����
;* ����˵�� :
;*-------------------------------------------- ���°汾��Ϣ -------------------------------------------------
;* �޸����� : ARM����С��
;* �޸����� : 2005/09/12
;* �汾���� : V1.0.1
;*-------------------------------------------- ��ʷ�汾��Ϣ -------------------------------------------------
;* �ļ����� : ARM����С��
;* �������� : 2004/04/20
;* �汾���� : v1.0.0
;*-----------------------------------------------------------------------------------------------------------
;*-----------------------------------------------------------------------------------------------------------
;************************************************************************************************************
;*/
#include <linux/config.h>
#include <linux/utsname.h>
#include <linux/kernel.h>
#include <linux/major.h>
#include <linux/string.h>
#include <linux/fcntl.h>
#include <linux/slab.h>
#include <linux/timer.h>
#include <linux/init.h>
#include <linux/poll.h>

#include <linux/errno.h>

#include <linux/sched.h>
#include <linux/tty.h>
#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/mm.h>

#include <asm/uaccess.h>
#include <asm/hardware.h>

#include <asm/io.h>

#include <asm/irq.h>

#include <asm/system.h>

#include <asm/proc/pgtable.h>

#include <linux/poll.h>

#include <asm/memory.h>



#include <asm/arch/smdk.h>
#include "def.h"

#define MVAL		(13)
#define MVAL_USED 	(0)
#define M5D(n) ((n) & 0x1fffff)	// To get lower 21bits
#define CLKVAL_TFT_640480 	(1)
#define HOZVAL_TFT_640480	(639)
#define LINEVAL_TFT_640480	(479)
#define LCD_XSIZE_TFT_640480 	(640)	
#define LCD_YSIZE_TFT_640480 	(480)

#define        LCDFRAMEBUFFER    vLCD_BASE                 //_NONCACHE_STARTADDRESS 


#define VBPD_640480		((33-1)&0xff)
#define VFPD_640480		((10-1)&0xff)
#define VSPW_640480		((2-1) &0x3f)
#define HBPD_640480		((48-1)&0x7f)
#define HFPD_640480		((16-1)&0xff)
#define HSPW_640480		((96-1)&0xff)
typedef unsigned long 	tOff;
#define        XY2OFF(x,y) 	 (tOff)((tOff)y*(tOff)640 + (x))

#define        READ_MEM(Off, Data)    Data = LCD_READ_MEM(Off)
#define        WRITE_MEM(Off, Data)   LCD_WRITE_MEM(Off, Data)

#define        GETPIXEL(x, y)         GetPixelIndex(x, y)
#define        SETPIXEL(x, y, c)      SetPixel(x, y, c)

U32  save_rGPCUP, save_rGPCDAT, save_rGPCCON;
U32  save_rGPDUP, save_rGPDDAT, save_rGPDCON;



U16 LCD_COLOR;
U16 LCD_BKCOLOR;

#define LCD_MAJOR 	60 

/*
*************************************************************************************************************
- �������� : void CloseLCD(struct inode * inode, struct file * file)
- ����˵�� : LCD�ر�
- ������� : struct inode * inode, struct file * file
- ������� : 0
*************************************************************************************************************
*/
static void CloseLCD(struct inode * inode, struct file * file)
{
	printk("LCD is closed\n");
	return;
}

/*
*************************************************************************************************************
- �������� : static int OpenLCD(struct inode * inode, struct file * file)
- ����˵�� : LCD��
- ������� : struct inode * inode, struct file * file
- ������� : 0
*************************************************************************************************************
*/
static int OpenLCD(struct inode * inode, struct file * file)
{
	printk("LCD is open\n");
	return 0;
}

/*
*************************************************************************************************************
- �������� : static int LCDIoctl(struct inode *inode,struct file * file,unsigned int cmd,unsigned long arg)
- ����˵�� : LCD�������
- ������� :
- ������� : 0
*************************************************************************************************************
*/
static int LCDIoctl(struct inode *inode, struct file *file, unsigned long cmd, unsigned long arg)
{
	//char color;
	struct para
	{
		unsigned long a;
		unsigned long b;
		unsigned long c;
		unsigned long d;
		unsigned long color;
	}*p_arg;

	switch (cmd)
	{
	case 0:
		printk("set color\n");
		printk("LCD_COLOR =%x\n", LCD_COLOR);
		return 1;

	case 1:
		
		Set_Color(0xFF0000);
		p_arg = (struct para *)arg;
		LCD_DrawHLine(p_arg->a, p_arg->b, p_arg->c);	// draw h_line
		return 1;
	case 11:
	
		Set_Color(0xD9Db4D);
		p_arg = (struct para *)arg;
		LCD_DrawHLine(p_arg->a, p_arg->b, p_arg->c);	// draw h_line
		return 1;
	case 2:

		p_arg = (struct para *)arg;
		Set_Color(0xFF0000);
		LCD_DrawVLine(p_arg->a, p_arg->b, p_arg->c);	// draw v_line
		return 1;
	case 21:
		
		p_arg = (struct para *)arg;
		Set_Color(0xD9Db4D);
		LCD_DrawVLine(p_arg->a, p_arg->b, p_arg->c);	// draw v_line
		return 1;
	case 3:
		printk("drwa circle\n");
		p_arg = (struct para *)arg;
		Set_Color(0xFF0000);
		LCD_DrawCircle(p_arg->a, p_arg->b, p_arg->c);	// draw circle
		return 1;
	case 4:
		printk("draw rect\n");
		p_arg = (struct para *)arg;
		Set_Color(0xFF0000);
		LCD_FillRect(p_arg->a, p_arg->b, p_arg->c, p_arg->d);      // draw rect
		return 1;

	case 5:
		printk("draw fillcircle\n");
		p_arg = (struct para *)arg;
		Set_Color(0xFF0000);
		LCD_FillCircle(p_arg->a, p_arg->b, p_arg->c);// draw fillcircle
		return 1;
	
	case 15:
		printk("draw fillcircle\n");
		p_arg = (struct para *)arg;
		Set_Color(0xFFFFFF);
		LCD_FillCircle(p_arg->a, p_arg->b, p_arg->c);// draw fillcircle
		return 1;	
	
	case 6:
		printk("LCD is clear\n");
		Set_Color(0xd9db4d);
		LCD_Clear(0, 0, 639, 479);     // clear screen
		return 1;

	case 7:
		printk("draw rect\n");
		p_arg = (struct para *)arg;
		Set_Color(0xFFFFFF);
		LCD_FillRect(p_arg->a, p_arg->b, p_arg->c, p_arg->d);      // draw rect
		return 1;

	case 8:
		p_arg = (struct para *)arg;
		Set_Color(0xFF0000);
		LCD_DrawPixel(p_arg->a,p_arg->b);
		return 1;
	case 9:
		p_arg = (struct para *)arg;
		Set_Color(p_arg->color);
		LCD_DrawPixel(p_arg->a,p_arg->b);
		return 1;

	case 10:
		p_arg = (struct para *)arg;
		Set_Color(p_arg->color);
		LCD_DrawPixel(p_arg->a,p_arg->b);
		return 1;
	default:
		return -EINVAL;
	}
	return 1;
}

/*
*************************************************************************************************************
- �������� : struct file_operations LCD_fops
- ����˵�� : �ļ��ṹ
- ������� : ��
- ������� : ��
*************************************************************************************************************
*/
static struct file_operations LCD_fops =
{
	ioctl:	   LCDIoctl,           	/* ioctl */
	open : OpenLCD,    		/* just a selector for the real open */
	release : CloseLCD,            /* release */
};

/*
*************************************************************************************************************
- �������� : U16  LCD_Init(U8 Lcd_Bpp)
- ����˵�� : LCDӲ����ʼ������
- ������� :
- ������� : ��
*************************************************************************************************************
*/
U16  Setup_LCDInit(void)
{
	long i; U16* base;

	save_rGPCCON = GPCCON;
	save_rGPCDAT = GPCDAT;
	save_rGPCUP = GPCUP;
	save_rGPDCON = GPDCON;
	save_rGPDDAT = GPDDAT;
	save_rGPDUP = GPDUP;
	GPCUP = 0xffffffff; // Disable Pull-up register
	GPCCON = 0xaaaaaaaa; //Initialize VD[7:0],LCDVF[2:0],VM,VFRAME,VLINE,VCLK,LEND 
	GPDUP = 0xffffffff; // Disable Pull-up register
	GPDCON = 0xaaaaaaaa; //Initialize VD[23:8]

	LCDCON1 = (CLKVAL_TFT_640480 << 8) | (MVAL_USED << 7) | (3 << 5) | (12 << 1) | 0;
	// TFT LCD panel,16bpp TFT,ENVID=off
	LCDCON2 = (VBPD_640480 << 24) | (LINEVAL_TFT_640480 << 14) | (VFPD_640480 << 6) | (VSPW_640480);
	LCDCON3 = (HBPD_640480 << 19) | (HOZVAL_TFT_640480 << 8) | (HFPD_640480);
	LCDCON4 = (MVAL << 8) | (HSPW_640480);
	LCDCON5 = (1 << 11) | (1 << 9) | (1 << 8) | (1);	//FRM5:6:5,HSYNC and VSYNC are inverted

	LCDADDR1 = ((0x33800000 >> 22) << 21) | M5D(0x33800000 >> 1);

	LCDADDR2 = M5D(((U8)0x33800000 + (640 * 480 * 2)) >> 1);

	LCDADDR3 = 0x0;
	LCDINTMSK |= (3); // MASK LCD Sub Interrupt
	LCDLPCSEL &= (~7); // Disable LPC3600
	TPAL = 0; // Disable



	Lcd_PowerEnable(0, 1);
	// Lcd_EnvidOnOff(1);
	Lcd_EnvidOnOff(1);
	base = (U16*)vLCD_BASE;
	for (i = 0; i < 640 * 480 * 2; i += 2)
	{
		*base++ = 0x0ee0;
	}
	return 0;

}

/*
*************************************************************************************************************
- �������� : U16 LCD_READ_MEM(U32 off)
- ����˵�� : ���Ӳ���Ķ��㺯��
- ������� : x,y,c
- ������� : ��
*************************************************************************************************************
*/

U16 LCD_READ_MEM(U32 off)
{
	return (*((U16*)LCDFRAMEBUFFER + (off)));
}

/*
*************************************************************************************************************
- �������� : void LCD_WRITE_MEM( U32 off,U8 Data)
- ����˵�� : ���Ӳ���Ļ��㺯��
- ������� : x,y,c
- ������� : ��
*************************************************************************************************************
*/
void LCD_WRITE_MEM(U32 off, U16 Data)
{
	(*((U16*)LCDFRAMEBUFFER + (off))) = Data;
}
/*
*************************************************************************************************************
- �������� : static void SetPixel(U16 x,U16 y,int c)
- ����˵�� : ���Ӳ���Ļ��㺯��
- ������� : x,y,c
- ������� : ��
*************************************************************************************************************
*/
static void SetPixel(U16 x, U16 y, U32 c)
{
	tOff Off = XY2OFF(x, y);
	WRITE_MEM(Off, c);
}

/*
*************************************************************************************************************
- �������� : void LCD_DrawPixel  (U16 x, U16 y)
- ����˵�� : ���㺯��
- ������� : x,y
- ������� : ��
*************************************************************************************************************
*/
void LCD_DrawPixel(U16 x, U16 y)
{
	SETPIXEL(x, y, LCD_COLOR);
}



/*
*************************************************************************************************************
- �������� : U32 GetPixelIndex(U16 x, U16 y)
- ����˵�� : ���Ӳ���ĵõ������ɫ�ĺ���
- ������� : x,y
- ������� : color
*************************************************************************************************************
*/
U32 GetPixelIndex(U16 x, U16 y)
{
	U32 col;
	U16 Data;
	tOff Off = XY2OFF(x, y);
	READ_MEM(Off, Data);
	col = Data;
	return col;
}


/*
*************************************************************************************************************
- �������� : U32 LCD_GetPixel(U16 x, U16 y)
- ����˵�� : �õ���ֵ�ĺ���
- ������� : x,y
- ������� : colof
*************************************************************************************************************
*/
U32 LCD_GetPixel(U16 x, U16 y)
{
	return GETPIXEL(x, y);
}

/*
*************************************************************************************************************
- �������� : void LCD_DrawHLine  (U16 x0, U16 y,  U16 x1)
- ����˵�� : ��ˮƽ�ߺ���
- ������� : x,y,x1
- ������� : ��
*************************************************************************************************************
*/
void LCD_DrawHLine(U16 x0, U16 y0, U16 x1)
{
	x1+=x0;
	while (x0 <= x1)
	{
		SETPIXEL(x0, y0, LCD_COLOR);
		x0++;
	}
}

/*
*************************************************************************************************************
- �������� : void LCD_DrawVLine  (U16 x, U16 y0,  U16 y1)
- ����˵�� : ����ֱ�ߺ���
- ������� : x,y,x1
- ������� : ��
*************************************************************************************************************
*/
void LCD_DrawVLine(U16 x0, U16 y0, U16 y1)
{
	y1+=y0;
	while (y0 <= y1)
	{
		SETPIXEL(x0, y0, LCD_COLOR);
		y0++;
	}
}

/*
*************************************************************************************************************
- �������� : void LCD_FillRect(U16 x0, U16 y0, U16 x1, U16 y1)
- ����˵�� : �����κ���
- ������� : x0,y0,x1,y1
- ������� : ��
*************************************************************************************************************
*/
void LCD_FillRect(U16 x0, U16 y0, U16 x1, U16 y1)
{
	y1 = y0 + y1;
	for (; y0 <= y1; y0++)  LCD_DrawHLine(x0, y0, x0 +  x1);
}

/*
*************************************************************************************************************
- �������� : void LCD_Clear(U16 x0, U16 y0, U16 x1, U16 y1)
- ����˵�� :  ��������
- ������� : x0,y0,x1,y1
- ������� : ��
*************************************************************************************************************
*/
void LCD_Clear(U16 x0, U16 y0, U16 x1, U16 y1)
{
	for (; y0 <= y1; y0++)
	{
		LCD_DrawHLine(x0, y0, x1);
	}
}
/*
*************************************************************************************************************
- �������� : static  void DrawPoint(U16 x0,U16 y0, U16 xoff, U16 yoff)
- ����˵�� : �������㺯��
- ������� : x,y
- ������� : ��
*************************************************************************************************************
*/
static  void _DrawPoint(U32 x0, U32 y0, U32 xoff, U32 yoff)
{
	LCD_DrawPixel(x0 + xoff, y0 + yoff);
	LCD_DrawPixel(x0 - xoff, y0 + yoff);
	LCD_DrawPixel(x0 + yoff, y0 + xoff);
	LCD_DrawPixel(x0 + yoff, y0 - xoff);

	if (yoff)
	{
		LCD_DrawPixel(x0 + xoff, y0 - yoff);
		LCD_DrawPixel(x0 - xoff, y0 - yoff);
		LCD_DrawPixel(x0 - yoff, y0 + xoff);
		LCD_DrawPixel(x0 - yoff, y0 - xoff);
	}
}

/*
*************************************************************************************************************
- �������� : void LCD_DrawCircle(U16 x0, U16 y0, U16 r)
- ����˵�� : ��Բ����
- ������� : x,y
- ������� : ��
*************************************************************************************************************
*/
void LCD_DrawCircle(U32 x0, U32 y0, U32 r)
{
	U32 i;
	U32 imax = ((int)((int)r * 707)) / 1000 + 1;
	U32 sqmax = (int)r*(int)r + (int)r / 2;
	U16 y = r;

	_DrawPoint(x0, y0, r, 0);

	for (i = 1; i <= imax; i++)
	{
		if ((i*i + y*y) > sqmax)
		{
			_DrawPoint(x0, y0, i, y);
			y--;
		}
		_DrawPoint(x0, y0, i, y);
	}
}
/*
*************************************************************************************************************
- �������� : void LCD_FillCircle(U16 x0, U16 y0, U16 r)
- ����˵�� : ���Բ����
- ������� : x,y
- ������� : ��
*************************************************************************************************************
*/
void LCD_FillCircle(U16 x0, U16 y0, U16 r)
{
	U32 i;
	U32 imax = ((int)((int)r * 707)) / 1000 + 1;
	U32 sqmax = (int)r*(int)r + (int)r / 2;
	U16 x = r;

	LCD_DrawHLine(x0 - r, y0, 2*r);

	for (i = 1; i <= imax; i++)
	{
		if ((i*i + x*x) > sqmax)
		{
			if (x > imax)
			{
				LCD_DrawHLine(x0 - i + 1, y0 + x, 2*(i - 1));
				LCD_DrawHLine(x0 - i + 1, y0 - x, 2*(i - 1));
			}
			x--;
		}
		LCD_DrawHLine(x0 - x, y0 + i, 2*x);
		LCD_DrawHLine(x0 - x, y0 - i, 2*x);
	}
}
/*
*************************************************************************************************************
- �������� : Log2Phy(int Color)
- ����˵�� : �߼���ɫתʵ����ɫ����
- ������� : color
- ������� : ��
*************************************************************************************************************
*/

U16 Log2Phy(U32 Color)
{
	U32 r, g, b;
	b = Color & 255;
	g = (Color >> 8) & 255;
	r = Color >> 16;
	b = b / 8;
	g = g / 4;
	r = r / 8;
	return b + (g << 5) + (r << 11);


}
/*
*************************************************************************************************************
- �������� : LCD_Log2Phy(int Color)
- ����˵�� : �߼���ɫתʵ����ɫ�ϲ㺯��
- ������� : color
- ������� : ��
*************************************************************************************************************
*/

U16 LCD_Log2Phy(U32 Color)
{
	U16 PhyColor;

	PhyColor = Log2Phy(Color);

	return PhyColor;
}
/*
*************************************************************************************************************
- �������� : void Set_Color(int color)
- ����˵�� : �趨��ɫ���ϲ㺯��
- ������� : color
- ������� : ��
*************************************************************************************************************
*/

void Set_Color(U32 color)
{

	LCD_SetColor(LCD_Log2Phy(color));

}
/*
*************************************************************************************************************
- �������� : void Set_Color(int color)
- ����˵�� : �趨��ɫ����
- ������� : color
- ������� : ��
*************************************************************************************************************
*/
void LCD_SetColor(U16 PhyColor)
{
	LCD_COLOR = PhyColor;
}
/*
*************************************************************************************************************
- �������� : void Set_Color(int color)
- ����˵�� : �趨��ɫ���ϲ㺯��
- ������� : color
- ������� : ��
*************************************************************************************************************
*/

void Set_BkColor(U32 color)
{

	LCD_SetBkColor(LCD_Log2Phy(color));

}
/*
*************************************************************************************************************
- �������� : void Set_Color(int color)
- ����˵�� : �趨��ɫ����
- ������� : color
- ������� : ��
*************************************************************************************************************
*/
void LCD_SetBkColor(U16 PhyColor)
{
	LCD_BKCOLOR = PhyColor;
}

/*
*************************************************************************************************************
- �������� : int LCDInit(void)
- ����˵�� : ע��LCD�豸
- ������� : ��
- ������� : 0,��-EBUSY
*************************************************************************************************************
*/
int __init  LCD_Init(void)
{
	int     result;

	Setup_LCDInit();
	printk("Registering S3C2410LCD Device\t--- >\t");
	result = register_chrdev(LCD_MAJOR, "S3C2410LCD", &LCD_fops);//ע���豸

	if (result < 0)
	{
		printk(KERN_INFO"[FALLED: Cannot register S3C2410LCD_driver!]\n");
		return -EBUSY;
	}
	else
		printk("[OK]\n");

	printk("Initializing S3C2410LCD Device\t--- >\t");
	printk("[OK]\n");

	printk("S3C2410LCD Driver Installed.\n");
	return 0;
}

/*
*************************************************************************************************************
- �������� : LCD_CstnOnOff
- ����˵�� : �򿪺͹ر�lcd�豸
- ������� : ��
- ������� : ��
*************************************************************************************************************
*/

static void Lcd_EnvidOnOff(int onoff)
{
	if (onoff == 1)
		LCDCON1 |= 0x1; // ENVID=ON
	else
		LCDCON1 = LCDCON1 & 0x3fffe; // ENVID Off
}



static void Lcd_PowerEnable(int invpwren, int pwren)
{
	//GPG4 is setted as LCD_PWREN
	GPGUP = GPGUP&(~(1 << 4)) | (1 << 4); // Pull-up disable
	GPGCON = GPGCON&(~(3 << 8)) | (3 << 8); //GPG4=LCD_PWREN
	//Enable LCD POWER ENABLE Function
	LCDCON5 = LCDCON5&(~(1 << 3)) | (pwren << 3);   // PWREN
	LCDCON5 = LCDCON5&(~(1 << 5)) | (invpwren << 5);   // INVPWREN
}



/*
*************************************************************************************************************
- �������� : LCD_Exit
- ����˵�� : ж��lcd�豸
- ������� : ��
- ������� : ��
*************************************************************************************************************
*/
void __exit LCDdriver_Exit(void)
{
	int i; U16* base;
	base = (U16*)vLCD_BASE;
	for (i = 0; i < 640 * 480 * 2; i += 2)
	{
		*base++ = 0x0000;
	}
	Lcd_EnvidOnOff(0);
	unregister_chrdev(LCD_MAJOR, "S3C2410LCD");
	printk("You have uninstall The LCD Driver succesfully,\n if you want to install again,please use the insmod command \n");
}

module_init(LCD_Init);
module_exit(LCDdriver_Exit);
/*
*****************************************************************************************************************
**                                                  �����ļ�                                                   **
*****************************************************************************************************************
*/
