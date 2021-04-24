#include "..\Public\simple_file_helper.h"
#include "..\..\simple_c_array\simple_c_array.h"
#include <stdio.h>
#include <direct.h>
#include <io.h>

void init_def_c_paths(def_c_paths *str)
{
    str->index = 0;
    memset(str->paths, 0, sizeof(str->paths) - 1);
}

int copy_file(const char *src, const char *dest)
{
    //文件大小
    char buf[512] = {0};
    //拷贝大小
    int file_size = 0;
    FILE *f_src = NULL;
    FILE *f_dest = NULL;
    if ((f_src = fopen(src, "rb")) != NULL)
    {
        if ((f_dest = fopen(dest, "wb")) != NULL)
        {
            while (file_size = fread(buf, sizeof(char), sizeof(buf), f_src))
            {
                fwrite(buf, file_size, sizeof(char), f_dest);
                memset(buf, 0, sizeof(buf));
            }
            fclose(f_src);
            fclose(f_dest);

            return 0;
        }
    }
    return -1;
}

void find_files(const char *in_path, def_c_paths *str, bool b_brecursion)
{
    struct _finddata_t finddata;

    long hfile = 0;
    char tmp_path[260] = {0};
    strcpy(tmp_path, in_path);
    strcat(tmp_path, "\\*");
    if ((hfile = _findfirst(tmp_path, &finddata)) != -1)
    {
        do
        {
            if (finddata.attrib & _A_SUBDIR)
            {
                if (b_brecursion)
                {
                    if (strcmp(finddata.name, ".") == 0 || strcmp(finddata.name, "..") == 0)
                    {
                        continue;
                    }
                    char new_path[260] = {0};
                    strcpy(new_path, in_path);
                    strcat(new_path, "\\");
                    strcat(new_path, finddata.name);
                    find_files(new_path, str, b_brecursion);
                }
            }
            else
            {
                strcpy(str->paths[str->index], in_path);
                strcat(str->paths[str->index], "\\");
                strcat(str->paths[str->index], finddata.name);
                str->index++;
            }

        } while (_findnext(hfile, &finddata) == 0);
        _findclose(hfile);
    }
}

bool create_file(const char *filename)
{
    FILE *f = NULL;
    if ((f = fopen(filename, "w+")) != NULL)
    {
        fclose(f);
        return true;
    }
    return false;
}

bool create_file_directory(const char *in_path)
{
    simple_c_string c_file;
    init_string(&c_file);
    if (strstr(in_path, "\\"))
    {
        dismantling_string(in_path, "\\", &c_file);
    }
    else if (strstr(in_path, "/"))
    {
        dismantling_string(in_path, "/", &c_file);
    }
    else
    {
        printf("无效，非标准路径，请检查%s", in_path);
        return false;
    }

    char path[260] = {0};
    for (int i = 0; i < c_file.size; i++)
    {
        char *value = get_string(i, &c_file);
        strcat(path, value);
        if (_access(path, 0) == -1)
        {
            _mkdir(path);
        }
        path[strlen(path)] = '/';
    }

    destroy_string(&c_file);
    return _access(path, 0) == 0;
}

bool get_file_buf(char *buf, const char *path)
{
    //文件大小
    char buf_temp[512] = {0};
    //拷贝大小
    FILE *f_src = NULL;
    if ((f_src = fopen(path, "r")) != NULL)
    {
        int file_tmp = 0;
        while ((file_tmp = fread(buf_temp, sizeof(char), 512, path)) > 0)
        {
            strcat(buf, buf_temp);
            memset(buf_temp,0,sizeof(buf_temp));
        }
        fclose(f_src);
        return true;
    }
    return false;
}