#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <windows.h>
#include <stdbool.h>
#include "simple_c_string_algorithm\simple_c_string_algorithm.h"
#include "simple_c_windows\simple_c_windows.h"
#include "simple_c_array\simple_c_array.h"
#include "simple_c_helper_file\simple_c_helper_file.h"

const char git_local_cofg_file[MAX_PATH] = "C:\\local_git\\"; //配置文件路径

char git_path[MAX_PATH] = {0};          //git路径
char git_log_path[MAX_PATH] = {0};      //log路径
char git_remote_origin[MAX_PATH] = {0}; //获取远端路径

char gir_local_cofg_filename[MAX_PATH] = {0}; //配置文件名称

typedef enum e_error
{
    GIT_SUCCESS = 0,
    GIT_LOG,
    GIT_WARNING,
    GIT_ERROR,
};

typedef struct fgit_user //  用户信息
{
    char name[MAX_PATH];
    char password[MAX_PATH];
    char email[MAX_PATH];
};

void log_wirte(enum e_error error, char *format, ...);
#define log_log(...) log_wirte(GIT_LOG, __VA_ARGS__)
#define log_success(...) log_wirte(GIT_SUCCESS, __VA_ARGS__)
#define log_warning(...) log_wirte(GIT_WARNING, __VA_ARGS__)
#define log_error(...) log_wirte(GIT_ERROR, __VA_ARGS__)

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
            log_error("创建日志失败！！");
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
    log_success("退出成功！！");
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
            log_success("当前git[%s]初始化成功", p);
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

            log_success(cat);

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

            log_success(cat);

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

            log_success(cat);

            destroy_string(&c_string);
        }
        else if (strstr(input_buff, "ssh-keygen -t rsa -C"))
        {
            //openSSL RSA
            log_error("ssh-keygen -t rsa -C 该指令尚未完成");
        }
        // else if (strstr(input_buff, "git clone"))
        // {
        //     simple_c_string c_string;
        //     dismantling_string(input_buff, " ", &c_string);

        //     char *sentence = get_string(2, &c_string);
        //     remove_char_end(sentence, '\n');

        //     simple_c_string c_file;
        //     if (strstr(sentence, "\\"))
        //     {
        //         dismantling_string(sentence, "\\", &c_file);
        //     }
        //     else if (strstr(sentence, "/"))
        //     {
        //         dismantling_string(sentence, "/", &c_file);
        //     }
        //     else
        //     {
        //         log_error("无效 非标准路径 %s", sentence);
        //         break;
        //     }
        //     char *file_value = get_string(c_file.size, &c_file);

        //     char buf_path[MAX_PATH];
        //     _gitcwd(buf_path, MAX_PATH - 1);

        //     char buf_local_path[MAX_PATH] = {0};
        //     get_printf(buf_local_path, "%s\\%s\\", buf_path, file_value);

        //     def_c_paths paths;
        //     find_files(sentence, &paths, true);
        //     for (int i = 0; i < paths.index; i++)
        //     {
        //         char buf_tmp[MAX_PATH];
        //         strcpy(buf_tmp,paths.paths[i]);
        //         remove_string_start(buf_tmp,sentence);
        //         strcat(buf_local_path,buf_tmp);

        //         if (!(copy_file(paths.paths[i],buf_local_path)))
        //         {
        //             log_success("将 %s 拉取到 %s 成功",paths.paths[i],buf_local_path);
        //         }
        //         else
        //         {
        //            log_error("将 %s 拉取到 %s 失败",paths.paths[i],buf_local_path);
        //         }

        //     }
        // }
        else if (strstr(input_buff, "git clone"))
        {
            simple_c_string c_string;
            dismantling_string(input_buff, " ", &c_string);

            char *sentence = get_string(2, &c_string);
            remove_char_end(sentence, '\n');

            if (!(strstr(sentence, "\\") || strstr(sentence, "/")))
            {
                log_error("无效 非标准路径 %s", sentence);
            }
            else
            {
                char buf_path[MAX_PATH];
                _getcwd(buf_path, MAX_PATH - 1);

                def_c_paths paths;
                find_files(sentence, &paths, true);
                for (int i = 0; i < paths.index; i++)
                {
                    char buf_tmp[MAX_PATH] = {0};
                    strcpy(buf_tmp, paths.paths[i]);
                    remove_string_start(buf_tmp, sentence);
                    char buf_local_path[MAX_PATH] = {0};
                    strcpy(buf_local_path, buf_path);
                    strcat(buf_local_path, buf_tmp);

                    if (!(copy_file(paths.paths[i], buf_local_path)))
                    {
                        log_success("将 %s 拉取到 %s 成功", paths.paths[i], buf_local_path);
                    }
                    else
                    {
                        log_error("将 %s 拉取到 %s 失败", paths.paths[i], buf_local_path);
                    }
                }
            }
        }
        else if (strstr(input_buff, "git --help"))
        {
            log_log("git init 创建仓库");
            log_log("git remote add origin 添加远程仓库");
            log_log("git --global user.email 添加email");
            log_log("git --global user.name 添加name");
            log_log("git clone 复制文件到此仓库");
            log_log("ssh-keygen -t rsa -C 创建密钥(尚未完成)");
            log_log("exit 退出");
        }
        else
        {
            log_warning("找不到命令:%s", input_buff);
            log_log("获取可以通过[git --help]的方式查看命令帮助");
        }
    }
}

void main(int argc, char *argv[])
{

    // const char *commit_type = argv[1]; //命令
    // const char *path_exe = argv[2];    //exe路径
    // const char *path_icon = argv[3];   //图标
    // const char *name = argv[4];        //名字

    // char buf_reg_key[MAX_PATH] = {0};    //主路径
    // char buf_reg_subkey[MAX_PATH] = {0}; //子路径

    // strcpy(buf_reg_key, REG_DIRECTORY);
    // strcat(buf_reg_key, name);

    // strcpy(buf_reg_subkey, REG_DIRECTORY);
    // strcat(buf_reg_subkey, name);
    // strcat(buf_reg_subkey, "\\command");

    // if (strcmp(commit_type, "1") == 0) //安装
    // {
    //     fregister_info info;
    //     //key
    //     init_fregister_info(&info);
    //     strcpy(info.filename, buf_reg_key);
    //     info.hKey = HKEY_CLASSES_ROOT;
    //     {
    //         info.value[info.size_value].type = REG_SZ;
    //         strcpy(info.value[info.size_value++].buf, name);
    //         info.value[info.size_value].type = REG_SZ;
    //         strcpy(info.value[info.size_value].name, "icon");
    //         strcpy(info.value[info.size_value++].buf, path_icon);
    //     }
    //     if (!register_info(&info))
    //     {
    //         printf("\n 1 需要管理员权限 \n");
    //         return -1;
    //     }
    //     //subkey
    //     init_fregister_info(&info);
    //     strcpy(info.filename, buf_reg_subkey);
    //     info.hKey = HKEY_CLASSES_ROOT;
    //     {
    //         info.value[info.size_value].type = REG_SZ;
    //         strcpy(info.value[info.size_value++].buf, path_exe);
    //     }
    //     if (!register_info(&info))
    //     {
    //         printf("\n 2 需要管理员权限 \n");
    //         return -1;
    //     }
    // }
    // else if (strcmp(commit_type, "2") == 0) //卸载
    // {
    //     if (delete_register_info(HKEY_CLASSES_ROOT, buf_reg_key))
    //     {
    //         delete_register_key(HKEY_CLASSES_ROOT, REG_DIRECTORY, name);
    //     }
    // }

    //初始化
    init_engine();

    //循环
    engine_loop();

    //退出
    exit_engine();
}