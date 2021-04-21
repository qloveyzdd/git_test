#include "..\Public\git.h"
#include <stdio.h>
#include <direct.h>

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