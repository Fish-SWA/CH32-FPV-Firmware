#ifndef __ST7789_H
#define __ST7789_H			

#include "debug.h"
//============================���������á�=================================

//��ʾ����
#define ST7789_DIR   1  //0��
//#define ST7789_DIR   2  //90��
//#define ST7789_DIR   3  //180��
//#define ST7789_DIR   4  //270��

#if ST7789_DIR == 2 || ST7789_DIR == 4
	#define ST7789_WIDTH 172
	#define ST7789_HEIGHT 320
#else
	#define ST7789_WIDTH 320
	#define ST7789_HEIGHT 172
#endif

#define ST7789_CMD  0       //д����
#define ST7789_DATA 1       //д����

//============================�����Ŷ��塿=================================
#define  ST7789_BL_PORT GPIOE
#define  ST7789_BL_PIN GPIO_Pin_3
#define  ST7789_BL_Ctrl(n)  GPIO_WriteBit(ST7789_BL_PORT, ST7789_BL_PIN, n);

#define SPI_PORT         GPIOB
#define SPI_SCLK_PIN     GPIO_Pin_3
#define SPI_MOSI_PIN     GPIO_Pin_5
#define SPI_MISO_PIN     GPIO_Pin_4

#define I8080_DC_PORT    GPIOE
#define I8080_DC_PIN     GPIO_Pin_2

#define ST7789_CS_PORT        GPIOA
#define ST7789_CS_PIN         GPIO_Pin_15
#define GT30L32S4W_CS_PORT    GPIOE
#define GT30L32S4W_CS_PIN     GPIO_Pin_1

#define ST7789_SET_CS()        GPIO_WriteBit(ST7789_CS_PORT, ST7789_CS_PIN, Bit_SET)
#define ST7789_RESET_CS()      GPIO_WriteBit(ST7789_CS_PORT, ST7789_CS_PIN, Bit_RESET)
#define GT30L32S4W_SET_CS()    GPIO_WriteBit(GT30L32S4W_CS_PORT, GT30L32S4W_CS_PIN, Bit_SET)
#define GT30L32S4W_RESET_CS()  GPIO_WriteBit(GT30L32S4W_CS_PORT, GT30L32S4W_CS_PIN, Bit_RESET)

#define I8080_DC(n)         GPIO_WriteBit(I8080_DC_PORT, I8080_DC_PIN, n)

//��ɫ
typedef enum
{
    color_WHITE = 0xFFFF, //��ɫ
    color_BLACK = 0x0000, //��ɫ
    color_BLUE = 0x001F, //��ɫ
    color_BRED = 0XF81F, //��ɫ
    color_GRED = 0XFFE0, //����ɫ
    color_GBLUE = 0X07FF, //����ɫ
    color_RED = 0xF800, //��ɫ
    color_GREEN = 0x07E0, //��ɫ
    color_CYAN = 0x7FFF, //����ɫ
    color_YELLOW = 0xFFE0, //��ɫ
    color_BROWN = 0XBC40, //��ɫ
    color_BRRED = 0XFC07, //�غ�ɫ
    color_GRAY = 0X8430, //��ɫ
    color_DARKBLUE = 0X01CF,//����ɫ
    color_LIGHTBLUE = 0X7D7C, //ǳ��ɫ
    color_GRAYBLUE = 0X5458, //����ɫ
    color_LIGHTGREEN = 0X841F, //ǳ��ɫ
    color_LGRAY = 0XC618, //ǳ��ɫ(PANNEL),���屳��ɫ
    color_LGRAYBLUE = 0XA651, //ǳ����ɫ(�м����ɫ)
    color_LBBLUE = 0X2B12, //ǳ����ɫ(ѡ����Ŀ�ķ�ɫ)
}color_t;//RGB565


typedef enum
{
//GB2312
    SIZE_CHN_12x12 = 0x000000,
    SIZE_CHN_16x16 = 0x02C9D0,
    SIZE_CHN_24x24 = 0x068190,
    SIZE_CHN_32x32 = 0x0EDF00,

    SIZE_ASCII_5x7 = 0x1DDF80,
    SIZE_ASCII_7x8 = 0x1DE280,
    SIZE_ASCII_6x12 = 0x1DBE00,
    SIZE_ASCII_8x16 = 0x1DD780,
    SIZE_ASCII_12x24 = 0x1DFF00,
    SIZE_ASCII_16x32 = 0x1E5A50,
}GT30L32S4W_BaseADDR_t;

void ST7789_Init();
void ST7789_FillColor(unsigned int x, unsigned int y, unsigned int width, unsigned int height, color_t color);

void ST7789_DrawPic(unsigned int x, unsigned int y, unsigned int width, unsigned int height, const unsigned char *_data);
void ST7789_DrawDot(unsigned int x, unsigned int y, color_t color, unsigned char bold);
void ST7789_DrawLine(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, color_t color, unsigned char bold);
void ST7789_DrawRectangle(unsigned int x, unsigned int y, unsigned int width, unsigned int height, color_t color, unsigned char bold, FunctionalState NewState);
void ST7789_DrawCircle(unsigned int x, unsigned int y, unsigned int radius, color_t color, unsigned char bold, FunctionalState fill);
void ST7789_ShowChar(unsigned int x, unsigned int y, unsigned char chr, color_t color_background, color_t color_foreground, GT30L32S4W_BaseADDR_t SIZE);
void ST7789_ShowNum(unsigned int x, unsigned int y, signed long num, unsigned char len, color_t color_background, color_t color_foreground, GT30L32S4W_BaseADDR_t SIZE_);
void ST7789_ShowNumf(unsigned int x, unsigned int y, float num, unsigned char len, color_t color_background, color_t color_foreground, GT30L32S4W_BaseADDR_t SIZE);
void ST7789_ShowString(unsigned int x, unsigned int y, const char *chr, color_t color_background, color_t color_foreground, GT30L32S4W_BaseADDR_t SIZE);
void ST7789_ShowCHN(unsigned int x, unsigned int y, unsigned char *chr, color_t color_background, color_t color_foreground, GT30L32S4W_BaseADDR_t SIZE);

#endif
  
