#pragma once
#include <windows.h>
#include <stdbool.h>
#include "..\..\simple_c_guid\simple_c_guid.h"


char git_project_path[MAX_PATH];          //git路径

const char git_local_cofg_file[MAX_PATH]; //配置文件路径

char git_remote_origin[MAX_PATH]; //远端路径

char gir_local_cofg_filename[MAX_PATH]; //配置文件名称

char git_project_remote_url[MAX_PATH]; //远端路径的仓库

char git_log_path[MAX_PATH];      //log路径

typedef struct fgit_user //  用户信息
{
    char name[MAX_PATH];
    char password[MAX_PATH];
    char email[MAX_PATH];
};
struct fgit_user user;

typedef struct //  提交信息
{
    bool b_init;
    char name[MAX_PATH];
    char commit[MAX_PATH];
    char data[MAX_PATH];
    simple_c_guid guid;
} fgit_commit;
fgit_commit commit;

typedef struct //  git路径
{
    char path_src[MAX_PATH];
    char path_dis[MAX_PATH];
} fgit_path_2d;
typedef struct //  所有git提交路径
{
    int size;
    fgit_path_2d paths[MAX_PATH * 2];
} fgit_path_2ds;

fgit_path_2ds git_path_2ds;

typedef struct //  版本控制
{
    unsigned int file_size;
    char name[MAX_PATH];
    simple_c_guid crc;
} fgit_version;
typedef struct //  版本列表
{
    unsigned int size;
    fgit_version paths[MAX_PATH * 2];
} fgit_versions_list;

fgit_versions_list versions_list;



