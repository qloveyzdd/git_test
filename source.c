#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <windows.h>
#include "simple_c_string_algorithm\simple_c_string_algorithm.h"
#include "simple_c_windows\simple_c_windows.h"
#include "simple_c_array\simple_c_array.h"
#include "simple_c_helper_file\simple_c_helper_file.h"

const char git_local_cofg_file[MAX_PATH] = "C:\\local_git\\"; //配置文件路径

char git_path[MAX_PATH] = {0};          //git路径
char git_log_path[MAX_PATH] = {0};      //log路径
char git_remote_origin[MAX_PATH] = {0}; //获取远端路径

char gir_local_cofg_filename[MAX_PATH] = {0}; //配置文件名称

typedef struct fgit_user //  用户信息
{
    char name[MAX_PATH];
    char password[MAX_PATH];
    char email[MAX_PATH];
};
struct fgit_user user;

void get_current_time(char *buf_time, int cn_zh)
{
    char buf[256] = {0};
    if (cn_zh == 1)
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
    else if (cn_zh == 0)
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
        char tmp_path[256] = {0}; //临时路径存储
        strcat(tmp_path, ".\\log\\");
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

void log_wirte(const char *content)
{
    char *p = get_log_path();
    FILE *hfile = NULL;
    if ((hfile = fopen(p, "a+")) != NULL)
    {
        char buf[1024] = {0};
        char tmp_time[128] = {0};
        get_current_time(tmp_time, 1);
        // remove_char_end(p, '\n');
        strcpy(buf, "[");
        strcat(buf, tmp_time);
        strcat(buf, "] ");
        strcat(buf, content);
        strcat(buf, "\r\n");
        printf(buf);
        fprintf(hfile, buf);
        fclose(hfile);
    }
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

void init_engine()
{
    char cofg_path_buf[MAX_PATH] = {0};
    _mkdir(git_local_cofg_file);
    strcpy(cofg_path_buf, git_local_cofg_file);
    strcat(cofg_path_buf, "git_confg.ini");

    if (_access(cofg_path_buf, 0) == -1) //判断文件是否存在
    {
        create_file(cofg_path_buf);
    }
    else
    {
        char buf_cofg[1024 * 10] = {0};
        FILE *f = NULL;
        int file_size = 0;
        if ((f = fopen(cofg_path_buf, "a")) != NULL)
        {
            if ((file_size = fread(buf_cofg, sizeof(char), sizeof(buf_cofg), f)) > 0)
            {
                simple_c_string c_str_sentence;
                dismantling_string(file_size, "\n", &c_str_sentence);
                for (int i = 0; i < c_str_sentence.size; i++)
                {
                    char *tmp = get_string(i, &c_str_sentence);
                    if (strstr(tmp, "name="))
                    {
                        simple_c_string c_str_param;
                        dismantling_string(tmp, "=", &c_str_param);
                        char *value = get_string(1, &c_str_param);
                        strcpy(user.name, value);
                        destroy_string(&c_str_param);
                    }
                    else if (strstr(tmp, "password="))
                    {
                        simple_c_string c_str_param;
                        dismantling_string(tmp, "=", &c_str_param);
                        char *value = get_string(1, &c_str_param);
                        strcpy(user.password, value);
                        destroy_string(&c_str_param);
                    }
                    else if (strstr(tmp, "remote_origin="))
                    {
                        simple_c_string c_str_param;
                        dismantling_string(tmp, "=", &c_str_param);
                        char *value = get_string(1, &c_str_param);
                        strcpy(git_remote_origin, value);
                        destroy_string(&c_str_param);
                    }
                }

                destroy_string(&c_str_sentence);
            }
        }
    }
}

void exit_engine()
{
    set_console_w_color(SIMPLE_BLUE, 0);
    printf("退出 \r\n");
}

void engine_loop()
{
    char input_buff[1024] = {0}; //指令输入缓存
    int b_exit = 0;              //退出符
    while (!b_exit)
    {
        set_console_w_color(SIMPLE_BLUE, 0);
        printf("输入指令：\r\n");
        printf("\r\n");
        set_console_w_color(SIMPLE_GREEN, 0);
        fgets(input_buff, 1024, stdin);
        if (strstr(input_buff, "exit"))
        {
            b_exit = 1;
        }
        else if (strstr(input_buff, "git init"))
        {
            char *p = get_git_init();
            log_wirte("当前git初始化成功");
        }
        else if (strstr(input_buff, "git remote add origin"))
        {
            simple_c_string c_string;
            dismantling_string(input_buff, " ", &c_string);

            char *sentence = get_string(4, &c_string);
            remove_char_end(sentence, '\n');

            strcpy(git_remote_origin, sentence);

            char cat[256] = {0};
            strcat(cat, "远端路径为：");
            strcat(cat, sentence);

            log_wirte(cat);

            destroy_string(&c_string);
        }
        else if (strstr(input_buff, "git --global user.email"))
        {
            simple_c_string c_string;
            dismantling_string(input_buff, " ", &c_string);

            char *sentence = get_string(3, &c_string);
            remove_char_end(sentence, '\n');

            strcpy(user.email, sentence);

            char cat[256] = {0};
            strcat(cat, "email为：");
            strcat(cat, sentence);

            log_wirte(cat);

            destroy_string(&c_string);
        }
        else if (strstr(input_buff, "git --global user.name"))
        {
            simple_c_string c_string;
            dismantling_string(input_buff, " ", &c_string);

            char *sentence = get_string(3, &c_string);
            remove_char_end(sentence, '\n');

            strcpy(user.name, sentence);

            char cat[256] = {0};
            strcat(cat, "name为：");
            strcat(cat, sentence);

            log_wirte(cat);

            destroy_string(&c_string);
        }
        else if (strstr(input_buff, "ssh-keygen -t rsa -C"))
        {
            //openSSL RSA
        }
    }
}

void main()
{
    //初始化
    init_engine();

    //循环
    engine_loop();

    //退出
    exit_engine();
}