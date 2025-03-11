#ifndef SSD1306_H
#define SSD1306_H

#include "Fonts.h"
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "hardware/i2c.h"

/* endereco I2C do display SSD1306 */
#ifndef SSD1306_I2C_ADDRESS
#define SSD1306_I2C_ADDRESS 0x3C
//#define SSD1306_I2C_ADDRESS 0x7A
#endif

/* comprimento do display SSD1306 */
#ifndef SSD1306_WIDTH
#define SSD1306_WIDTH 128
#endif

/* altura do display */
#ifndef SSD1306_HEIGHT
#define SSD1306_HEIGHT 64
#endif

#define SSD1306_Set_MemoryMode 0x20
#define SSD1306_Set_ColumnAddress 0x21
#define SSD1306_Set_PageAddress 0x22
#define SSD1306_Set_Display_StartLine 0x40
#define SSD1306_Set_Contrast 0x81
#define SSD1306_Set_ChargePump 0x8D
#define SSD1306_Set_SegmentRemap 0xA0
#define SSD1306_Set_EntireOn 0xA4
#define SSD1306_Set_AllOn 0xA5
#define SSD1306_Set_NormalDisplay 0xA6
#define SSD1306_Set_InverserDisplay 0xA7
#define SSD1306_Set_MuxRatio 0xA8
#define SSD1306_Set_Display 0xAE
#define SSD1306_Set_CommonOutputDirection 0xC0
#define SSD1306_Set_CommonOutputDirection_Flip 0xC8
#define SSD1306_Set_Offset 0xD3
#define SSD1306_Set_ClockDivideRatio 0xD5
#define SSD1306_Set_Precharge 0xD9
#define SSD1306_Set_CommonPinConfiguration 0xDA
#define SSD1306_Set_VCOMH_DeselectLevel 0xD8

#define SSD1306_PageHeight 8
#define SSD1306_NumberOfPages (SSD1306_HEIGHT / SSD1306_PageHeight)
#define SSD1306_BufferLength (SSD1306_NumberOfPages * SSD1306_WIDTH)

#define SSD1306_WriteMode 0xFE
#define SSD1306_ReadMode 0xFF

#define SSD1306_RIGHT_HORIZONTAL_SCROLL              0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL               0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL  0x2A
#define SSD1306_DEACTIVATE_SCROLL                    0x2E // Stop scroll
#define SSD1306_ACTIVATE_SCROLL                      0x2F // Start scroll
#define SSD1306_SET_VERTICAL_SCROLL_AREA             0xA3 // Set scroll range

#define SSD1306_NORMALDISPLAY       0xA6 // display em estado normal
#define SSD1306_INVERTDISPLAY       0xA7 // inverte o estado de cada pixel

struct RenderArea {
    uint8_t StartColumn;
    uint8_t EndColumn;
    uint8_t StartPage;
    uint8_t EndPage;
    int BufferLength;
};

typedef struct {
    uint8_t Width, Height, Pages, Address;
    i2c_inst_t * i2c_port;
    bool external_vcc;
    uint8_t *ram_buffer;
    size_t bufsize;
    uint8_t port_buffer[2];
} SSD1306_t;


typedef enum {
    SSD1306_COLOR_BLACK = 0x00, /* cor preta para o pixel (apagado) */
    SSD1306_COLOR_WHITE = 0x01 /* cor banca para o pixel (aceso) */
} SSD1306_COLOR_t;

void Calculate_RenderArea_BufferLength(struct RenderArea *area);

void SSD1306_SendCommand(uint8_t command);

void SSD1306_SendCommand_List(uint8_t *ssd, int number);

void SSD1306_SendBuffer(uint8_t ssd[], int buffer_length);

void SSD1306_Init();

void SSD1306_Render(uint8_t *ssd, struct RenderArea *area);

void SSD1306_SetPixel(uint8_t *ssd, int X, int Y, SSD1306_COLOR_t color);

void SSD1306_DrawLine(uint8_t *ssd, int X0, int Y0, int X1, int Y1, SSD1306_COLOR_t color);

void SSD1306_DrawRectangle(uint8_t *ssd, uint16_t x, uint16_t y, uint16_t w, uint16_t h, SSD1306_COLOR_t color);

void SSD1306_DrawFilledRectangle(uint8_t *ssd, uint16_t x, uint16_t y, uint16_t w, uint16_t h, SSD1306_COLOR_t color);

void SSD1306_DrawTriangle(uint8_t *ssd, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, SSD1306_COLOR_t color);

void SSD1306_DrawFilledTriangle(uint8_t *ssd, uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t x3, uint16_t y3, SSD1306_COLOR_t color);

void SSD1306_DrawCircle(uint8_t *ssd, int16_t x_center, int16_t y_center, int16_t radius, SSD1306_COLOR_t color);

void SSD1306_DrawFilledCircle(int8_t *ssd, int16_t x_center, int16_t y_center, int16_t radius, SSD1306_COLOR_t color);

void SSD1306_DrawArc(uint8_t *ssd, uint16_t x_center, uint16_t y_center, uint16_t radius, uint16_t start_angle, uint16_t end_angle, SSD1306_COLOR_t color);

void SSD1306_SetChar(uint8_t *ssd, int16_t x, int16_t y, uint8_t character, FontDef_t* Font, SSD1306_COLOR_t color);

void SSD1306_SetString(uint8_t *ssd, int16_t x, int16_t y, const char *str, FontDef_t* Font, SSD1306_COLOR_t color);

void SSD1306_SetStringWrapped(uint8_t *ssd, int16_t x, int16_t y, const char *str, FontDef_t* Font, SSD1306_COLOR_t color);

void SSD1306_Clear(uint8_t *ssd, struct RenderArea *area);

#endif