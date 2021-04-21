#include <stdio.h>
#include <io.h>
#include <direct.h>
#include <windows.h>
#include <stdbool.h>
#include "simple_c_string_algorithm\simple_c_string_algorithm.h"
#include "simple_c_windows\simple_c_windows.h"
#include "simple_c_array\simple_c_array.h"
#include "simple_c_helper_file\simple_c_helper_file.h"
#include "simple_c_path\simple_c_path.h"
#include "simple_c_file\simple_c_file.h"
#include "main_core\Public\log.h"
#include "main_core\Public\git.h"
#include "main_core\Public\main_core.h"
#include "simple_c_guid\simple_c_guid.h"

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
                dismantling_string(buf_cofg, "\n", &c_str_sentence);
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
    set_console_w_color(SIMPLE_BLUE, SIMPLE_BLACK);
    log_success("退出成功！！");
}

void engine_loop()
{
    char input_buff[1024] = {0}; //指令输入缓存
    int b_exit = 0;              //退出符
    while (!b_exit)
    {
        set_console_w_color(SIMPLE_BLUE, SIMPLE_BLACK);
        printf("输入指令：\r\n");
        printf("\r\n");
        set_console_w_color(SIMPLE_GREEN, SIMPLE_BLACK);
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
        else if (strstr(input_buff, "git push"))
        {
            if (git_remote_origin[0] == '\0')
            {
                log_error("远端路径未设置，请使用\"git remote add origin\"设置远端路径");
            }
            else
            {
                if (strstr(input_buff, "git push ."))
                {
                    char sentence[MAX_PATH] = {0};
                    _getcwd(sentence, MAX_PATH - 1); //  获取本地路径

                    char *buf_path = git_remote_origin; //  获取远端路径

                    copy_files(buf_path, sentence);
                }
                else if (strstr(input_buff, "git push"))
                {
                    simple_c_string c_string;
                    dismantling_string(input_buff, " ", &c_string);
                    char *sentence = get_string(2, &c_string);
                    remove_char_end(sentence, '\n');

                    char buf_path[MAX_PATH] = {0};
                    strcpy(buf_path, git_remote_origin);

                    copy_files(buf_path, sentence);

                    destroy_string(&c_string);
                }
            }
        }
        else if (strstr(input_buff, "git clone"))
        {
            simple_c_string c_string;
            dismantling_string(input_buff, " ", &c_string);
            char *sentence = get_string(2, &c_string);
            remove_char_end(sentence, '\n');

            char buf_path[MAX_PATH];
            _getcwd(buf_path, MAX_PATH - 1); //将当前的绝对路径放在字符串中

            copy_files(buf_path, sentence);
            destroy_string(&c_string);
        }
        else if (strstr(input_buff, "git --help"))
        {
            log_log("git init 创建仓库");
            log_log("git remote add origin 添加远程仓库");
            log_log("git --global user.email 添加email");
            log_log("git --global user.name 添加name");
            log_log("git push 将仓库复制到某个文件夹");
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

int main(int argc, char *argv[])
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

    return 0;
}