int hanzi[][16][8]={
{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x08,0x10,0x07,0x00},
	{0x06,0x0C,0x06,0x00,0x07,0x0E,0x04,0x00},
	{0x03,0x06,0x0C,0x00,0x03,0x04,0x08,0x18},
	{0x00,0x00,0x8F,0xFC,0x00,0x7F,0xD0,0x00},
	{0x20,0x88,0x10,0x10,0x30,0x88,0x3F,0xF8},
	{0x19,0x08,0x40,0x30,0x19,0x18,0x80,0x60},
	{0x09,0x1F,0xC0,0x40,0x01,0x18,0xC1,0x80},
	{0x02,0x18,0xC1,0x80,0x02,0x18,0x81,0x80},
	{0x02,0x18,0x81,0x88,0x06,0x10,0xBF,0xFC},
	{0x04,0x10,0x81,0x80,0x3C,0x30,0x81,0x80},
	{0x0C,0x30,0x81,0x80,0x0C,0x21,0x81,0x80},
	{0x0C,0x61,0x81,0x80,0x0C,0x41,0x81,0x80},
	{0x1C,0xC1,0x81,0x80,0x1C,0x93,0x01,0x80},
	{0x0D,0x0F,0x0F,0x80,0x02,0x06,0x03,0x00},
	{0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"游",0*/
	},{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x40,0x00,0x00,0x00,0x70,0x00},
	{0x00,0x00,0x64,0x00,0x00,0x00,0x63,0x80},
	{0x00,0x00,0x61,0xC0,0x00,0x18,0x60,0xE0},
	{0x3F,0xFC,0x60,0x60,0x00,0x18,0x60,0x00},
	{0x00,0x30,0x60,0x18,0x00,0x30,0x21,0xFC},
	{0x00,0x3B,0xFE,0x00,0x10,0x34,0x30,0x00},
	{0x0C,0x20,0x30,0x20,0x06,0x60,0x30,0x70},
	{0x03,0x60,0x30,0x60,0x01,0xC0,0x10,0xC0},
	{0x00,0xC0,0x19,0xC0,0x00,0xE0,0x19,0x80},
	{0x01,0xF0,0x1B,0x00,0x01,0x30,0x0E,0x00},
	{0x03,0x38,0x0C,0x04,0x02,0x18,0x1E,0x04},
	{0x04,0x08,0x37,0x04,0x0C,0x08,0x63,0x08},
	{0x08,0x01,0x81,0x88,0x10,0x03,0x00,0xEC},
	{0x20,0x04,0x00,0x7C,0x40,0x18,0x00,0x3C},
	{0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00},/*"戏",1*/
	},{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x08,0x00,0x01,0x80,0x0E,0x00},
	{0x01,0x80,0x0C,0x00,0x01,0x80,0x0C,0x00},
	{0x03,0x00,0x0C,0x00,0x03,0x00,0x0C,0x18},
	{0x02,0x07,0xFF,0xFC,0x04,0x10,0x0C,0x00},
	{0x04,0x1C,0x0C,0x00,0x08,0x30,0x0C,0x00},
	{0x18,0x60,0x0C,0x00,0x3F,0xE0,0x0C,0x00},
	{0x1C,0xC0,0x0C,0x20,0x01,0x83,0xFF,0xF0},
	{0x01,0x00,0x00,0x00,0x02,0x00,0x00,0x00},
	{0x04,0x01,0x00,0x20,0x08,0x79,0xFF,0xF0},
	{0x1F,0x81,0x80,0x30,0x1C,0x01,0x80,0x20},
	{0x00,0x01,0x80,0x20,0x00,0x01,0x80,0x20},
	{0x00,0x19,0x80,0x20,0x00,0xE1,0x80,0x20},
	{0x0F,0x81,0x80,0x20,0x3C,0x01,0xFF,0xE0},
	{0x10,0x01,0x80,0x20,0x00,0x01,0x80,0x20},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00},/*"结",2*/
	},{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x01,0xC0,0x00},
	{0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x18},
	{0x3F,0xFF,0xFF,0xFC,0x00,0x01,0x80,0x00},
	{0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x00},
	{0x02,0x01,0x80,0x80,0x03,0xFF,0xFF,0xE0},
	{0x03,0x01,0x80,0xC0,0x03,0x01,0x80,0xC0},
	{0x03,0x01,0x80,0xC0,0x03,0x01,0x80,0xC0},
	{0x03,0x01,0x80,0xC0,0x03,0xFF,0xFF,0xC0},
	{0x03,0x07,0xC0,0xC0,0x03,0x0F,0xA0,0x00},
	{0x00,0x0D,0xB0,0x00,0x00,0x19,0x90,0x00},
	{0x00,0x31,0x88,0x00,0x00,0x61,0x8E,0x00},
	{0x00,0xC1,0x87,0x00,0x01,0x81,0x83,0xC0},
	{0x03,0x01,0x81,0xF0,0x06,0x01,0x80,0x7C},
	{0x18,0x01,0x80,0x30,0x20,0x01,0x80,0x00},
	{0x00,0x01,0x00,0x00,0x00,0x00,0x00,0x00},/*"束",3*/
	},{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x01,0x00,0x20,0x00,0x01,0xC0,0x18,0x00},
	{0x01,0x80,0x0C,0x00,0x01,0x80,0x0C,0x00},
	{0x01,0x82,0x0C,0x08,0x01,0x83,0xFF,0xFC},
	{0x01,0xA2,0x00,0x18,0x3F,0xF6,0x00,0x10},
	{0x01,0x8E,0x38,0x20,0x01,0x80,0x30,0x00},
	{0x01,0x80,0x30,0x00,0x01,0x90,0x60,0x00},
	{0x01,0xA0,0x60,0x18,0x01,0xDF,0xFF,0xFC},
	{0x03,0x80,0xC0,0xC0,0x0F,0x80,0x80,0xC0},
	{0x3D,0x81,0x81,0x80,0x39,0x81,0x01,0x80},
	{0x11,0x83,0x01,0x80,0x01,0x83,0x03,0x00},
	{0x01,0x80,0xE3,0x00,0x01,0x80,0x1E,0x00},
	{0x01,0x80,0x07,0x00,0x01,0x80,0x0D,0xC0},
	{0x01,0x80,0x38,0xF0,0x01,0x80,0x60,0x38},
	{0x1F,0x81,0xC0,0x18,0x07,0x0E,0x00,0x08},
	{0x02,0x30,0x00,0x00,0x00,0x00,0x00,0x00},/*"按",4*/
	},{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x03,0x00,0x00,0x00,0x1F,0x80},
	{0x00,0x1F,0xF8,0x00,0x03,0xE1,0x80,0x00},
	{0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x30},
	{0x1F,0xFF,0xFF,0xF8,0x00,0x01,0x80,0x00},
	{0x00,0x01,0x81,0x00,0x01,0xFF,0xFF,0xC0},
	{0x01,0x81,0x81,0x80,0x01,0x81,0x81,0x80},
	{0x01,0x81,0x81,0x80,0x01,0xFF,0xFF,0x80},
	{0x01,0x81,0x81,0x80,0x01,0x81,0x81,0x80},
	{0x01,0x81,0x81,0x80,0x01,0xFF,0xFF,0x80},
	{0x01,0x81,0x81,0x80,0x00,0x01,0x80,0x00},
	{0x00,0x01,0x80,0x00,0x00,0x01,0x80,0xC0},
	{0x07,0xFF,0xFF,0xE0,0x00,0x01,0x80,0x00},
	{0x00,0x01,0x80,0x00,0x00,0x01,0x80,0x18},
	{0x3F,0xFF,0xFF,0xFC,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"重",5*/
	},{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x80,0x00,0x00,0x00,0xC0,0x00,0x30},
	{0x00,0x60,0x00,0xF8,0x00,0x63,0x1F,0x80},
	{0x1F,0xFF,0x98,0x00,0x04,0x08,0x18,0x00},
	{0x06,0x0E,0x18,0x00,0x03,0x0C,0x18,0x00},
	{0x03,0x08,0x18,0x00,0x01,0x10,0x18,0x00},
	{0x01,0x11,0x98,0x18,0x3F,0xFF,0xDF,0xFC},
	{0x00,0x60,0x18,0xC0,0x00,0x60,0x18,0xC0},
	{0x00,0x60,0x18,0xC0,0x00,0x63,0x10,0xC0},
	{0x1F,0xFF,0x90,0xC0,0x00,0x60,0x10,0xC0},
	{0x00,0x60,0x10,0xC0,0x06,0x68,0x30,0xC0},
	{0x06,0x66,0x30,0xC0,0x0C,0x63,0x20,0xC0},
	{0x0C,0x63,0x60,0xC0,0x08,0x61,0x60,0xC0},
	{0x10,0x60,0xC0,0xC0,0x24,0x60,0x80,0xC0},
	{0x43,0xE1,0x00,0xC0,0x00,0xC2,0x00,0xC0},
	{0x00,0x84,0x00,0x80,0x00,0x00,0x00,0x00},/*"新",6*/
	},{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x20},
	{0x00,0x00,0x00,0x70,0x1F,0xFF,0xFF,0xF8},
	{0x00,0x30,0x0C,0x00,0x00,0x30,0x0C,0x00},
	{0x00,0x30,0x0C,0x00,0x00,0x30,0x0C,0x00},
	{0x00,0x30,0x0C,0x00,0x00,0x30,0x0C,0x00},
	{0x00,0x30,0x0C,0x00,0x00,0x30,0x0C,0x00},
	{0x00,0x30,0x0C,0x18,0x3F,0xFF,0xFF,0xFC},
	{0x00,0x30,0x0C,0x00,0x00,0x30,0x0C,0x00},
	{0x00,0x30,0x0C,0x00,0x00,0x30,0x0C,0x00},
	{0x00,0x30,0x0C,0x00,0x00,0x20,0x0C,0x00},
	{0x00,0x60,0x0C,0x00,0x00,0x60,0x0C,0x00},
	{0x00,0xC0,0x0C,0x00,0x00,0x80,0x0C,0x00},
	{0x01,0x00,0x0C,0x00,0x02,0x00,0x0C,0x00},
	{0x04,0x00,0x0C,0x00,0x18,0x00,0x0C,0x00},
	{0x20,0x00,0x08,0x00,0x00,0x00,0x00,0x00},/*"开",7*/
	},{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x01,0x00,0x08,0x00,0x01,0xC0,0x0E,0x00},
	{0x01,0x80,0x1C,0x00,0x01,0x80,0x18,0x00},
	{0x01,0x80,0x10,0x00,0x03,0x00,0x30,0x00},
	{0x03,0x00,0x20,0xC0,0x03,0x08,0x60,0x60},
	{0x3F,0xFC,0x40,0x38,0x02,0x08,0x80,0x1C},
	{0x06,0x19,0x81,0xFC,0x06,0x19,0xFE,0x0C},
	{0x04,0x19,0x80,0x08,0x04,0x18,0x00,0x00},
	{0x0C,0x10,0x00,0x00,0x0C,0x30,0x80,0x10},
	{0x08,0x30,0xFF,0xF8,0x18,0x20,0xC0,0x30},
	{0x18,0x60,0xC0,0x30,0x0C,0x60,0xC0,0x30},
	{0x03,0x40,0xC0,0x30,0x00,0xE0,0xC0,0x30},
	{0x00,0xB8,0xC0,0x30,0x01,0x9C,0xC0,0x30},
	{0x03,0x0C,0xC0,0x30,0x06,0x00,0xFF,0xF0},
	{0x0C,0x00,0xC0,0x30,0x10,0x00,0xC0,0x30},
	{0x20,0x00,0x80,0x00,0x00,0x00,0x00,0x00},/*"始",8*/
	},{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x80,0x00,0x00,0x00,0xE0,0x00,0x00},
	{0x00,0xC0,0x00,0x00,0x01,0x80,0x00,0x00},
	{0x01,0x80,0x00,0x30,0x03,0x07,0xFF,0xF8},
	{0x02,0x08,0x0C,0x00,0x06,0x0C,0x0C,0x00},
	{0x04,0x18,0x0C,0x00,0x08,0x18,0x0C,0x00},
	{0x10,0xB0,0x0C,0x00,0x3F,0x60,0x0C,0x00},
	{0x10,0x40,0x0C,0x00,0x00,0x80,0x0C,0x00},
	{0x01,0x80,0x0C,0x00,0x03,0x00,0x0C,0x00},
	{0x06,0x04,0x0C,0x00,0x0C,0x78,0x0C,0x00},
	{0x1F,0x80,0x0C,0x00,0x1C,0x00,0x0C,0x00},
	{0x08,0x00,0x0C,0x00,0x00,0x02,0x0C,0x00},
	{0x00,0x1C,0x0C,0x00,0x00,0xE0,0x0C,0x00},
	{0x0F,0x80,0x0C,0x18,0x1C,0x1F,0xFF,0xFC},
	{0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"红",9*/
	},{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x02,0x00,0x00,0x00,0x03,0x80,0x00},
	{0x00,0x07,0x00,0x00,0x00,0x06,0x00,0x00},
	{0x00,0x0C,0x00,0x00,0x00,0x08,0x00,0x40},
	{0x03,0xFF,0xFF,0xE0,0x03,0x00,0x00,0x60},
	{0x03,0x00,0x00,0x60,0x03,0x00,0x00,0x60},
	{0x03,0x00,0x00,0x60,0x03,0x00,0x00,0x60},
	{0x03,0x00,0x00,0x60,0x03,0x00,0x00,0x60},
	{0x03,0x00,0x00,0x60,0x03,0xFF,0xFF,0xE0},
	{0x03,0x00,0x00,0x60,0x03,0x00,0x00,0x60},
	{0x03,0x00,0x00,0x60,0x03,0x00,0x00,0x60},
	{0x03,0x00,0x00,0x60,0x03,0x00,0x00,0x60},
	{0x03,0x00,0x00,0x60,0x03,0x00,0x00,0x60},
	{0x03,0x00,0x00,0x60,0x03,0xFF,0xFF,0xE0},
	{0x03,0x00,0x00,0x60,0x03,0x00,0x00,0x60},
	{0x02,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"白",10*/
	},{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x06,0x00,0x00,0x00,0x03,0x80,0x00},
	{0x00,0x01,0x80,0x00,0x00,0x01,0xC0,0x00},
	{0x00,0x00,0x80,0x00,0x00,0x00,0x00,0x18},
	{0x3F,0xFF,0xFF,0xFC,0x00,0x06,0x00,0x00},
	{0x00,0x06,0x00,0x00,0x00,0x06,0x00,0x00},
	{0x00,0x06,0x00,0x00,0x00,0x06,0x00,0x80},
	{0x00,0x07,0xFF,0xC0,0x00,0x06,0x01,0x80},
	{0x00,0x04,0x01,0x80,0x00,0x0C,0x01,0x80},
	{0x00,0x0C,0x01,0x80,0x00,0x08,0x03,0x00},
	{0x00,0x18,0x03,0x00,0x00,0x10,0x03,0x00},
	{0x00,0x30,0x03,0x00,0x00,0x20,0x03,0x00},
	{0x00,0x60,0x03,0x00,0x00,0xC0,0x02,0x00},
	{0x01,0x80,0x06,0x00,0x03,0x01,0x86,0x00},
	{0x04,0x00,0x7E,0x00,0x18,0x00,0x3C,0x00},
	{0x20,0x00,0x30,0x00,0x00,0x00,0x00,0x00},/*"方",11*/
	},{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x00,0x04,0x00,0x08,0x10,0x06,0x00},
	{0x0F,0xF8,0x06,0x00,0x0C,0x30,0x86,0x00},
	{0x0C,0x30,0xE6,0x00,0x0C,0x30,0xC6,0x00},
	{0x0C,0x30,0x86,0x00,0x0C,0x30,0x86,0x00},
	{0x0C,0x31,0x86,0x10,0x0F,0xF1,0xFF,0xF8},
	{0x0C,0x31,0x06,0x00,0x0C,0x33,0x06,0x00},
	{0x0C,0x32,0x06,0x00,0x0C,0x32,0x06,0x00},
	{0x0C,0x34,0x06,0x00,0x0F,0xF0,0x06,0x00},
	{0x0C,0x30,0x06,0x30,0x0C,0x31,0xFF,0xF8},
	{0x0C,0x30,0x06,0x00,0x0C,0x30,0x06,0x00},
	{0x08,0x30,0x06,0x00,0x08,0x30,0x06,0x00},
	{0x08,0x30,0x06,0x00,0x18,0x30,0x06,0x00},
	{0x10,0x30,0x06,0x00,0x11,0x30,0x06,0x08},
	{0x20,0xF7,0xFF,0xFC,0x20,0x60,0x00,0x00},
	{0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"胜",12*/
	},{
	{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	{0x00,0x01,0x00,0x10,0x00,0x07,0x80,0x18},
	{0x00,0x7F,0x00,0x18,0x1F,0xB0,0x00,0x18},
	{0x00,0x30,0x08,0x18,0x00,0x30,0x0E,0x18},
	{0x00,0x30,0x0C,0x18,0x00,0x30,0x0C,0x18},
	{0x00,0x30,0xCC,0x18,0x3F,0xFF,0xEC,0x18},
	{0x00,0x30,0x0C,0x18,0x00,0x70,0x0C,0x18},
	{0x00,0x70,0x0C,0x18,0x00,0x78,0x0C,0x18},
	{0x00,0xF6,0x0C,0x18,0x01,0xB3,0x8C,0x18},
	{0x01,0xB1,0xCC,0x18,0x03,0x30,0xCC,0x18},
	{0x06,0x30,0x8C,0x18,0x04,0x30,0x0C,0x18},
	{0x08,0x30,0x0C,0x18,0x10,0x30,0x08,0x18},
	{0x20,0x30,0x00,0x18,0x00,0x30,0x00,0x18},
	{0x00,0x30,0x00,0x18,0x00,0x30,0x06,0x38},
	{0x00,0x30,0x01,0xF8,0x00,0x30,0x00,0x70},
	{0x00,0x20,0x00,0x20,0x00,0x00,0x00,0x00},/*"利",13*/
	}
};


int shuzi[10][8][8]={
{  
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x03,0xE0,0x06,0x30},
    {0x0C,0x18,0x18,0x0C,0x18,0x0C,0x18,0x04},
    {0x30,0x06,0x30,0x06,0x30,0x06,0x30,0x06},
    {0x30,0x06,0x30,0x06,0x30,0x06,0x30,0x06},
    {0x30,0x06,0x18,0x04,0x18,0x0C,0x18,0x0C},
    {0x0C,0x18,0x06,0x30,0x03,0xE0,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"0",0*/
},{
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x80,0x01,0x80},
    {0x1F,0x80,0x01,0x80,0x01,0x80,0x01,0x80},
    {0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80},
    {0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80},
    {0x01,0x80,0x01,0x80,0x01,0x80,0x01,0x80},
    {0x01,0x80,0x03,0xC0,0x1F,0xF8,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"1",1*/
},{
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x07,0xE0,0x08,0x38},
    {0x10,0x18,0x20,0x0C,0x20,0x0C,0x30,0x0C},
    {0x30,0x0C,0x00,0x0C,0x00,0x18,0x00,0x10},
    {0x00,0x20,0x00,0x40,0x00,0x80,0x01,0x00},
    {0x02,0x00,0x04,0x04,0x08,0x04,0x10,0x04},
    {0x20,0x0C,0x3F,0xF8,0x3F,0xF8,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"2",2*/
},{
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x07,0xC0,0x18,0x70},
    {0x30,0x30,0x30,0x18,0x30,0x18,0x30,0x18},
    {0x00,0x18,0x00,0x30,0x00,0x60,0x03,0xC0},
    {0x00,0x70,0x00,0x18,0x00,0x08,0x00,0x0C},
    {0x00,0x0C,0x30,0x0C,0x30,0x0C,0x30,0x08},
    {0x30,0x18,0x18,0x30,0x07,0xC0,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"3",3*/
},{
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x30,0x00,0x70},
    {0x00,0x70,0x00,0xF0,0x01,0x70,0x01,0x70},
    {0x02,0x70,0x06,0x70,0x04,0x70,0x08,0x70},
    {0x08,0x70,0x10,0x70,0x20,0x70,0x20,0x70},
    {0x7F,0xFE,0x00,0x70,0x00,0x70,0x00,0x70},
    {0x00,0x70,0x00,0x70,0x00,0x70,0x03,0xFE},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"4",4*/
},{
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x0F,0xFC,0x0F,0xFC},
    {0x08,0x00,0x08,0x00,0x08,0x00,0x10,0x00},
    {0x10,0x00,0x13,0xE0,0x14,0x30,0x18,0x18},
    {0x10,0x08,0x00,0x0C,0x00,0x0C,0x00,0x0C},
    {0x00,0x0C,0x30,0x0C,0x30,0x0C,0x20,0x18},
    {0x20,0x18,0x10,0x30,0x0F,0xC0,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"5",5*/
},{
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x01,0xF0,0x03,0x08},
    {0x04,0x0C,0x08,0x0C,0x18,0x00,0x18,0x00},
    {0x10,0x00,0x30,0x00,0x31,0xF0,0x36,0x18},
    {0x3C,0x0C,0x38,0x06,0x30,0x06,0x30,0x06},
    {0x30,0x06,0x30,0x06,0x18,0x06,0x18,0x04},
    {0x0C,0x0C,0x06,0x18,0x03,0xE0,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"6",6*/
},{
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x1F,0xFC,0x1F,0xFC},
    {0x38,0x08,0x30,0x10,0x20,0x10,0x20,0x20},
    {0x00,0x20,0x00,0x40,0x00,0x40,0x00,0x80},
    {0x00,0x80,0x00,0x80,0x01,0x00,0x01,0x00},
    {0x01,0x00,0x03,0x00,0x03,0x00,0x03,0x00},
    {0x03,0x00,0x03,0x00,0x03,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"7",7*/
},{
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x07,0xE0,0x0C,0x30},
    {0x18,0x18,0x30,0x0C,0x30,0x0C,0x30,0x0C},
    {0x38,0x0C,0x1C,0x18,0x0E,0x10,0x07,0xE0},
    {0x0D,0xE0,0x18,0x70,0x30,0x38,0x60,0x1C},
    {0x60,0x0C,0x60,0x0C,0x60,0x0C,0x60,0x0C},
    {0x30,0x18,0x18,0x30,0x07,0xC0,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"8",8*/
},{
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x07,0xC0,0x18,0x20},
    {0x30,0x10,0x30,0x18,0x60,0x08,0x60,0x0C},
    {0x60,0x0C,0x60,0x0C,0x60,0x0C,0x60,0x1C},
    {0x30,0x3C,0x18,0x6C,0x0F,0x8C,0x00,0x0C},
    {0x00,0x18,0x00,0x18,0x00,0x18,0x30,0x30},
    {0x30,0x60,0x30,0xC0,0x0F,0x80,0x00,0x00},
    {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},/*"9",9*/
}
};
