#include "..\Public\simple_file_helper.h"
#include <stdio.h>
#include <io.h>

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
    if ((f = fopen(filename, "r+") != NULL))
    {
        fclose(f);
        return true;
    }
    return false;
}