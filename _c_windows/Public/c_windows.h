#pragma once
#include<windows.h>

#define REG_SHELL_DIRECTORY "*\\Shell\\"                   //在对象上鼠标右键
#define REG_DIRECTORY "Directory\\Background\\shell\\"     //在空白上鼠标右键
#define REG_DESKTOPBACKGROUND "DesktopBackground\\shell\\" //在空白上鼠标右键

//注册表操作
typedef struct
{
    char name[260];
    DWORD type;
    char buf[1024];
} freg_value;
typedef struct source
{
    HKEY hKey;
    char filename[260];
    int size_value;
    freg_value value[1024];
} fregister_info;

void init_fregister_info(fregister_info *info);

bool register_info(const fregister_info *info);

bool delete_register_key(HKEY hKey, const char *filename, const char *subkey_name);

bool delete_register_info(HKEY hKey, const char *filename);