#pragma once
#include <windows.h>
#include <stdbool.h>

#define log_log(...) log_wirte(GIT_LOG, __VA_ARGS__)
#define log_success(...) log_wirte(GIT_SUCCESS, __VA_ARGS__)
#define log_warning(...) log_wirte(GIT_WARNING, __VA_ARGS__)
#define log_error(...) log_wirte(GIT_ERROR, __VA_ARGS__)

char git_log_path[MAX_PATH] = {0};      //log路径

typedef enum e_error
{
    GIT_SUCCESS = 0,
    GIT_LOG,
    GIT_WARNING,
    GIT_ERROR,
};

void get_current_time(char *buf_time, bool cn_zh);//获取当前时间，可以是中文

char *get_log_path();//设置log文件夹

void log_wirte(enum e_error error, char *format, ...);//提示及写入log文件