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
void dismantling_string(const char *in_data, const char *str_sub, simple_c_string *array_c);
//按照特定字符切割字符串，并按照序号返回相应的字符串
char *dismantling_string_by_index(char *buf,const char *split_str,const char *sub_str,int index);