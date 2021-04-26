#include "..\Public\log.h"
#include <direct.h>
#include <stdio.h>
#include "..\Public\git.h"

void get_current_time(char *buf_time, bool cn_zh)
{
    char buf[256] = {0};
    if (cn_zh == true)
    {
        SYSTEMTIME sys;
        GetLocalTime(&sys);
        char p_time[5];
        _ltoa(sys.wYear, p_time, 10);
        strcpy(buf, p_time);
        strcat(buf, "年");
        _ltoa(sys.wMonth, p_time, 10);
        strcat(buf, p_time);
        strcat(buf, "月");
        _ltoa(sys.wDay, p_time, 10);
        strcat(buf, p_time);
        strcat(buf, "日");
        _ltoa(sys.wHour, p_time, 10);
        strcat(buf, p_time);
        strcat(buf, "时");
        _ltoa(sys.wMinute, p_time, 10);
        strcat(buf, p_time);
        strcat(buf, "分");
        _ltoa(sys.wSecond, p_time, 10);
        strcat(buf, p_time);
        strcat(buf, "秒");
    }
    else if (cn_zh == false)
    {
        SYSTEMTIME sys;
        GetLocalTime(&sys);
        char p_time[5];
        _ltoa(sys.wYear, p_time, 10);
        strcpy(buf, p_time);
        _ltoa(sys.wMonth, p_time, 10);
        strcat(buf, p_time);
        _ltoa(sys.wDay, p_time, 10);
        strcat(buf, p_time);
        _ltoa(sys.wHour, p_time, 10);
        strcat(buf, p_time);
        _ltoa(sys.wMinute, p_time, 10);
        strcat(buf, p_time);
        _ltoa(sys.wSecond, p_time, 10);
        strcat(buf, p_time);
    }

    strcpy(buf_time, buf);
}

char *get_log_path()
{
    if (git_log_path[0] == '\0') //判读log是否存在
    {
        char *p = get_git_project_path();

        char tmp_path[256] = {0}; //临时路径存储
        strcpy(tmp_path,p);
        strcat(tmp_path,"log\\");
        _mkdir(tmp_path); //创建log文件夹

        char buf[256] = {0};
        get_current_time(buf, 0);

        strcat(tmp_path, buf);
        strcat(tmp_path, ".txt");

        FILE *hfile = NULL;
        if ((hfile = fopen(tmp_path, "a+")) != NULL)
        {
            strcpy(git_log_path, tmp_path);
            fclose(hfile);
        }
        else
        {
            printf("创建日志失败！！");
        }
    }
    return git_log_path;
}

void log_wirte(enum e_error error, char *format, ...)
{
    char *p = get_log_path();
    FILE *hfile = NULL;
    if ((hfile = fopen(p, "a+")) != NULL)
    {
        char error_str[64] = {0};
        switch (error)
        {
        case GIT_SUCCESS:
            strcpy(error_str, "成功");
            break;
        case GIT_LOG:
            strcpy(error_str, "LOG");
            break;
        case GIT_WARNING:
            strcpy(error_str, "警告");
            break;
        case GIT_ERROR:
            strcpy(error_str, "失败");
            break;
        }

        char buf[1024] = {0};
        va_list args;
        va_start(args, format);
        vsnprintf(buf, 1024 - 1, format, args);
        strcat(buf, "\n");
        va_end(args);
        buf[1024 - 1] = '\0';

        char tmp_time[128] = {0};
        get_current_time(tmp_time, 1);

        char text_buf[1024] = {0};
        get_printf(text_buf, "[%s][%s]%s \r\n", error_str, tmp_time, buf);

        printf(text_buf);
        fprintf(hfile, buf);
        fclose(hfile);
    }
}