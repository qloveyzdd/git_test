#include <stdio.h>
#include <io.h>
#include <direct.h>
#include "simple_c_string_algorithm\simple_c_string_algorithm.h"

char git_path[260] = {0};
char git_log_path[260] = {0};

char *get_log_path()
{
    if (git_log_path[0] = '\0')
    {
        char tmp_path[256] = {0};
        strcat(tmp_path, ".\\log\\");
        _mkdir(tmp_path);
        time_t now_time = time(NULL);

        struct tm *t_tm = localtime(&now_time);
        time_t mk_time = mktime(t_tm);

        char buf[256] = {0};
        char *p_time = _ltoa(mk_time, buf, 10);

        strcat(tmp_path, p_time);
        strcat(tmp_path, ".txt");

        FILE *hfile = NULL;
        if ((hfile = fopen(tmp_path, "a+")) != NULL)
        {
            strcpy(git_log_path, tmp_path);
            fclose(hfile);
        }
    }
    return git_log_path;
}

char *get_git_init()
{
    if (git_path[0] == '\0')
    {
        char tmp_path[256] = {0};
        strcat(tmp_path, ".\\git\\");
        _mkdir(tmp_path);
        strcat(tmp_path, "git.txt");
        FILE *hfile = NULL;
        if ((hfile = fopen(tmp_path, "a+")) != NULL)
        {
            strcpy(git_path, tmp_path);
            fclose(hfile);
        }
    }
    return git_path;
}

char *get_current_time()
{
    return ctime(__TIME__);
}

void log_wirte(const char *content)
{
    char *p = get_log_path();
    FILE *hfile = NULL;
    if ((hfile = fopen(p, "a+")) != NULL)
    {
        char buf[1024] = {0};

        char *p = get_current_time();
        remove_char_end(p, '\n');

        strcpy(buf, "[");
        strcat(buf, p);
        strcat(buf, "] ");
        strcat(buf, content);
        strcat(buf, "\r\n");

        printf(buf);
        fprintf(hfile, buf);

        fclose(hfile);
    }
}

void main()
{
    //初始化

    //循环
    char input_buff[1024] = {0};
    int b_exit = 0;
    while (!b_exit)
    {
        printf("输入指令：\r\n");
        printf("\r\n");
        fgets(input_buff, 1024, stdin);
        if (strstr(input_buff, "exit"))
        {
            b_exit = 1;
        }
        else if (strstr(input_buff, "git init"))
        {
            char *p = get_log_path();
            log_wirte("当前git初始化成功");
        }
    }

    //退出
    printf("退出 \r\n");
}