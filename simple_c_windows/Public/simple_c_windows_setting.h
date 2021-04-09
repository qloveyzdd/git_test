#pragma once
#include <windows.h>

typedef enum
{
    SIMPLE_BLACK = 0,
    SIMPLE_BLUE,
    SIMPLE_GREEN,
    SIMPLE_LIGHT_BLUE,
    SIMPLE_RED,
    SIMPLE_VIOLET,
    SIMPLE_YELLOW,
    SIMPLE_WHITE,
    SIMPLE_GREY,
} simple_console_cmd_w_color;

//修改背景颜色
void set_console_w_color(simple_console_cmd_w_color font_color,simple_console_cmd_w_color background_color);