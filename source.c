#include <stdio.h>
#include<stdlib.h>

void main()
{
    char data[] = "ABC";
    char data1[] = "ABC";
    // char datatmp[] = {0};

    // //strcat(data,data1);

    // char *p = data;


    // printf("%d \r\n",sizeof(p));
    // printf("%d \r\n",strlen(p));

    // int b = strcmp(data,data1);
    // char* index = strchr(data,'B');
    // int aa = 12345678;
    char a[100] = "asa\nascddsa\nvsdfvfbgd\ncdvfdv\nvsbvdfb";
    //itoa(aa,a,2);
    char *p = strtok(a,"\n");
    while (p)
    {
        printf("%s \r\n",p);
        p=strtok(NULL,"\n");
    }
    int num =0;
    char temp_char;
    char array_char[128];
    while ((temp_char = getchar())!='\n')
    {
        array_char[num++] = temp_char;
        array_char[num] = '\0';
    }
    num =0;
    char temp_char1;
    char array_char1[128];
    while ((temp_char1 = getchar())!='\n')
    {
        array_char1[num++] = temp_char1;
        array_char1[num] = '\0';
    }
    // printf("%s",array_char);
    // printf("%s",array_char1);

    int char_len = strlen(array_char);
    int char_len1 = strlen(array_char1);
    char *qaz = array_char;
    char *wsx = array_char1;

    int flag =0;
    for (; *(wsx+char_len-1); wsx++)
    {
        flag++;
        for (qaz = array_char;*qaz == *wsx;wsx++,qaz++);
        if (!*qaz)
        {
            printf("%d \r\n",flag);
            break;
        }
        
    }
    


    // for (int i = 0; (char_len-i)<=char_len1; i++)
    // {
    //     if (array_char1[i]==array_char[0])
    //     {
    //         int j = 0;
    //        for (; j < char_len; j++)
    //        {
    //            if (array_char1[i+j] != array_char[j])
    //            {
    //                break;
    //            }
    //        }
    //        if (j == char_len)
    //        {
    //            printf("%d \r\n",i);
    //            break;
    //        }
    //     }
    // }
    

    // printf("%s \r\n",a);
}