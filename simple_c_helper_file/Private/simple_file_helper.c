#include "..\Public\simple_file_helper.h"
#include<stdio.h>

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
            while (file_size = fread(buf,sizeof(char),sizeof(buf),f_src))
            {
                fwrite(buf,file_size,sizeof(char),f_dest);
                memset(buf,0,sizeof(buf));
            }
            fclose(f_src);
            fclose(f_dest);

            return 0;
        }
    }
    return -1;
}