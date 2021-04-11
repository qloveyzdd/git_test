#pragma once
#include "Core/simple_array_c_macro.h"

typedef struct
{
    char data[256];
} str_node;

SIMPLE_ARRAY_C_STRUCT(simple_c_string, str_node);

//初始化
void init_string(simple_c_string *array_c);
//删除
void destroy_string(simple_c_string *array_c);
//添加
void add_string(const char *in_data, simple_c_string *array_c);
//打印
void printf_string(simple_c_string *array_c);
//返回某一段
char *get_string(int in_index, simple_c_string *array_c);
//拆分，并放入结构体
void dismantling_string(char *in_data,const char *str_sub,simple_c_string *array_c);