#pragma once

//从头查找单字符
void remove_char_start(char *str, const char sub_char);
//从尾查找单字符
void remove_char_end(char *str, const char sub_char);
//在字符串中查找出现的字符的位置
int find_string(char *str, const char *sub_str);
//在字符串中删除出现的多字符
void remove_string_start(char *str, const char *sub_str);
//在字符串中替换出现的单字符
void replace_char_inline(char *str, const char sub_char_a, const char sub_char_b);
//按照printf形式合并字符
int get_printf(char *buf, char *format, ...);
//按照printf形式合并字符(标准)
int get_printf_s(char *out_buf, char *format, ...);
//切割字符串
char *string_mid(char *out_buf,const char *in_buf,const int start,const int count);