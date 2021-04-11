#pragma once
#include<stdbool.h>

typedef struct
{
    int index;
    char paths[1024][260];
} def_c_paths;

int copy_file(const char *src, const char *dest);

void find_files(const char *in_path, def_c_paths *str,bool b_brecursion);

bool create_file(const char *filename);

