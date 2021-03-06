#pragma once
#include<stdbool.h>

typedef struct
{
    int index;
    char paths[4096][260];
} def_c_paths;

void init_def_c_paths(def_c_paths *str);

int copy_file(const char *src, const char *dest);

void find_files(const char *in_path, def_c_paths *str,bool b_brecursion);

bool create_file(const char *filename);

bool create_file_directory(const char *in_path);

bool get_file_buf(char *buf,const char *path);

