#include "..\Public\git.h"
#include <stdio.h>
#include <direct.h>
#include "..\..\simple_c_helper_file\simple_c_helper_file.h"
#include "..\..\simple_c_array\simple_c_array.h"
//#include "..\..\simple_c_path\simple_c_path.h"

char *get_git_project_path()
{
    if (git_project_path[0] == '\0')
    {
        char buf_project_path[MAX_PATH] = {0};
        _getcwd(buf_project_path, MAX_PATH - 1);

        simple_c_string c_string;

        dismantling_string(buf_project_path, "\\", &c_string);

        char buf_path[MAX_PATH] = {0};
        for (int i = 0; i < c_string.size; i++)
        {
            char *p = get_string(i, &c_string);
            strcat(buf_path, p);
            strcat(buf_path, "\\");
            char buf_tmp[MAX_PATH] = {0};
            strcpy(buf_tmp, buf_path);

            strcat(buf_tmp, "git\\git.txt");
            if (_access(buf_tmp, 0) == 0)
            {
                strcpy(git_project_path, buf_path);
                break;
            }
        }
        destroy_string(&c_string);
        if (git_project_path[0] == '\0')
        {
            printf("请先使用git init创建仓库！！");
        }
    }
    return git_project_path;
}