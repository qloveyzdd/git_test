#pragma once
#include <stdbool.h>

typedef struct
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
} simple_c_guid;

void normalization_guid(simple_c_guid *c_guid); //初始化guid

bool create_guid(simple_c_guid *c_guid); //生成guid

void guid_to_string(char *buf, const simple_c_guid *c_guid); //将guid设置成字符串

void string_to_guid(simple_c_guid *c_guid, const char *buf); //将字符串设置成guid