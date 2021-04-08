#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include<stdbool.h>
#define INDEX_NONE -1

bool copy_file(const char *src, const char *dest)
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

void main()
{
    // char v;
    // printf("输入：");
    // v = getchar();
    // printf("\r\n输出：");
    // putchar(v);

    // char v[128];
    // printf("输入：");
    // fgets(v,128,stdin);
    // printf("\r\n输出：");
    // fputs(v,stdout);

    // FILE *fp = fopen("abc.txt","w+");
    // fprintf(fp,"hello world......\n");
    // fclose(fp);

    // FILE *fp = fopen("abc.txt","r");
    // char buff[256];
    // fgets(buff,255,fp);
    // printf("%s",buff);
    // fclose(fp);

    // FILE *fp = fopen("abc.txt","r+");
    // fseek(fp,3,0);
    // fprintf(fp,"ABCDE");
    // char buff[128];
    // fgets(buff,127,fp);
    // printf("%s",buff);
    // fclose(fp);

    // FILE *fp = fopen("abc.txt", "rb");
    // if (!fp)
    // {
    //     int ErrorCode = errno;
    //     fprintf(stderr, "错误代码：%d\n", ErrorCode);
    //     fprintf(stderr, "错误代码：%s\n", strerror(ErrorCode));
    //     exit(EXIT_FAILURE);
    // }

}