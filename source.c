#include <stdio.h>

#define INDEX_NONE -1

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

    FILE *fp = fopen("abc.txt","r+");
    fseek(fp,3,0);
    fprintf(fp,"ABCDE");
    char buff[128];
    fgets(buff,127,fp);
    printf("%s",buff);
    fclose(fp);
}