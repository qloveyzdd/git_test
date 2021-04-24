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
    commit.b_init = false;
    //读取用户配置表
    read_user();
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
            char tmp_path[MAX_PATH] = {0};
            strcat(tmp_path,".\\git\\");

            _mkdir(tmp_path);
            strcat(tmp_path,"git.txt");

            if (create_file(tmp_path))
            {
                char*p = get_git_project_path();
                log_success("初始化[%s]路径",p);
            }
            else
            {
                log_error("初始化git路径");
            }
            
            
            
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
            dismantling_string_by_index(user.email,input_buff," ",3);
            save_user();
            log_success("设置email为：%s",user.email);
        }
        else if (strstr(input_buff, "git --global user.name"))
        {
            dismantling_string_by_index(user.name,input_buff," ",3);
            save_user();
            log_success("设置name为：%s",user.name);
        }
        else if (strstr(input_buff, "git --global user.password"))
        {
            dismantling_string_by_index(user.password,input_buff," ",3);
            save_user();
            log_success("设置password为：%s",user.password);
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
                if (strstr(input_buff, "git add ."))
                {
                    char sentence[MAX_PATH] = {0};
                    _getcwd(sentence, MAX_PATH - 1); //  获取本地路径

                    char *buf_path = git_remote_origin; //  获取远端路径

                    copy_files(buf_path, sentence, true);
                }
                else if (strstr(input_buff, "git add"))
                {
                    simple_c_string c_string;
                    dismantling_string(input_buff, " ", &c_string);
                    char *sentence = get_string(2, &c_string);
                    remove_char_end(sentence, '\n');

                    char buf_path[MAX_PATH] = {0};
                    strcpy(buf_path, git_remote_origin);

                    copy_files(buf_path, sentence, true);

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

            copy_files(buf_path, sentence, false);
            destroy_string(&c_string);
        }
        else if (strstr(input_buff, "git commit -m"))
        {
            simple_c_string c_string;
            dismantling_string(input_buff, " ", &c_string);
            char *sentence = get_string(3, &c_string);
            remove_char_end(sentence, '\n');

            init_commit(&commit);
            get_current_time(commit.data, false);
            strcpy(commit.name, user.name);
            strcpy(commit.commit, sentence);
            create_guid(&commit.guid);
            log_log("版本提交信息为：%s", sentence);

            destroy_string(&c_string);
        }
        else if (strstr(input_buff, "git push -u origin master"))
        {
            for (int i = 0; i < git_path_2ds.size; i++)
            {
                if (!(copy_file(git_path_2ds.paths[i].path_src, git_path_2ds.paths[i].path_dis)))
                {
                    //log_success("将 %s 拉取到 %s 成功", paths.paths[i], buf_local_path);
                }
                else
                {
                    log_error("将 %s 拉取到 %s 失败", git_path_2ds.paths[i].path_src, git_path_2ds.paths[i].path_dis);
                }
            }
            log_log("数据拉取结束!!!");
        }
        else if (strstr(input_buff, "git push"))
        {
            
        }
        else if (strstr(input_buff, "git --help"))
        {
            log_log("git init 创建仓库");
            log_log("git remote add origin 添加远程仓库");
            log_log("git --global user.email 添加email");
            log_log("git --global user.name 添加name");
            log_log("git add 将仓库复制到某个文件夹");
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