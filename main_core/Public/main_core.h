#pragma once
#include "windows.h"
#include "..\..\simple_c_guid\simple_c_guid.h"

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

typedef struct //  提交信息
{
    bool b_init;
    char name[MAX_PATH];
    char commit[MAX_PATH];
    char data[MAX_PATH];
    simple_c_guid guid;
} fgit_commit;

fgit_commit commit;

void init_commit(fgit_commit *out_commit);

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

void init_git_path_2ds(fgit_path_2ds *path_2d);