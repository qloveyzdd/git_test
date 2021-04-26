#pragma once
#include "windows.h"
#include "..\..\simple_c_guid\simple_c_guid.h"
#include "git.h"

void init_commit(fgit_commit *out_commit);

void init_git_path_2ds(fgit_path_2ds *path_2d);

void read_user(); //读取用户信息

void save_user(); //存储用户信息

char *get_git_local_user_filename();

char*get_git_project_remote_url();

char *get_git_project_path();