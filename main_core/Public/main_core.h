#pragma once
#include "windows.h"

const char git_local_cofg_file[MAX_PATH] = "C:\\local_git\\"; //配置文件路径

char git_remote_origin[MAX_PATH] = {0}; //获取远端路径

char gir_local_cofg_filename[MAX_PATH] = {0}; //配置文件名称


typedef struct fgit_user //  用户信息
{
    char name[MAX_PATH];
    char password[MAX_PATH];
    char email[MAX_PATH];
};

struct fgit_user user;