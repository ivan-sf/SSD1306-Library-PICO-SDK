#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "Fonts.h"
#include "DisplaySSD1306.h"

#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15

struct RenderArea FrameArea = {
    .StartColumn = 0,
    .EndColumn = SSD1306_WIDTH - 1,
    .StartPage = 0,
    .EndPage = SSD1306_NumberOfPages - 1
};

uint8_t ssd[SSD1306_BufferLength];

int main(){
    stdio_init_all();

    i2c_init(I2C_PORT, 400 * 1000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    Calculate_RenderArea_BufferLength(&FrameArea);

    SSD1306_Init();

    //SSD1306_DrawLine(ssd, 10, 50, 100, 50, SSD1306_COLOR_WHITE);

    //SSD1306_DrawRectangle(ssd, 10, 10, 90, 30, SSD1306_COLOR_WHITE);

    SSD1306_DrawFilledRectangle(ssd, 10, 10, 90, 30, SSD1306_COLOR_WHITE);

    //SSD1306_DrawTriangle(ssd, 64, 30, 100, 50, 64, 50, SSD1306_COLOR_WHITE);

    //SSD1306_DrawFilledTriangle(ssd, 10, 5, 90, 50, 10, 50, SSD1306_COLOR_WHITE);

    //SSD1306_DrawCircle(ssd, 64, 32, 20, SSD1306_COLOR_WHITE);

    //SSD1306_DrawFilledCircle(ssd, 10, 10, 5, SSD1306_COLOR_WHITE);

    //SSD1306_DrawArc(ssd, 64, 32, 20, 180, 0, SSD1306_COLOR_WHITE);

    //SSD1306_SetChar(ssd, 120, 32, '&', &Font_7x10, SSD1306_COLOR_WHITE);

    //SSD1306_SetString(ssd, 0, 0, "WXYZ", &Font_16x26, SSD1306_COLOR_WHITE);

    //SSD1306_SetStringWrapped(ssd, 0, 0, "ABCD\nWXYZ", &Font_7x10, SSD1306_COLOR_WHITE);

    /*SSD1306_DrawFilledRectangle(ssd, 10, 10, 90, 40, SSD1306_COLOR_WHITE);

    SSD1306_Render(ssd, &FrameArea);

    sleep_ms(3000);

    SSD1306_DrawFilledTriangle(ssd, 15, 15, 60, 15, 40, 40, SSD1306_COLOR_BLACK);

    SSD1306_Render(ssd, &FrameArea);

    sleep_ms(3000);

    SSD1306_DrawFilledCircle(ssd, 75, 30, 10, SSD1306_COLOR_BLACK);

    SSD1306_Render(ssd, &FrameArea);

    sleep_ms(3000);

    SSD1306_DrawArc(ssd, 75, 30, 15, 90, 270, SSD1306_COLOR_BLACK);

    SSD1306_Render(ssd, &FrameArea);
    
    sleep_ms(1500);

    SSD1306_Clear(ssd, &FrameArea);*/

    /*SSD1306_SetChar(ssd, 0, 0, 'A', &Font_7x10, SSD1306_COLOR_WHITE);

    SSD1306_Render(ssd, &FrameArea);

    sleep_ms(5000);

    SSD1306_SetString(ssd, 0, 15, "VIRTUS", &Font_11x18, SSD1306_COLOR_WHITE);

    SSD1306_Render(ssd, &FrameArea);

    sleep_ms(5000);

    SSD1306_SetStringWrapped(ssd, 0, 40, "VIR\nTUS", &Font_7x10, SSD1306_COLOR_WHITE);

    SSD1306_Render(ssd, &FrameArea);

    sleep_ms(3000);

    SSD1306_Clear(ssd, &FrameArea);*/

    SSD1306_Render(ssd, &FrameArea);

    sleep_ms(3000);

    SSD1306_Invert(true);

    sleep_ms(3000);

    SSD1306_Clear(ssd, &FrameArea);

    sleep_ms(3000);

    SSD1306_OFF();

    sleep_ms(3000);

    SSD1306_ON();

    while(1){

    }
}
