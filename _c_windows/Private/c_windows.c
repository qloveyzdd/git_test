#include"../Public/c_windows.h"
#include<stdio.h>
#include<stdbool.h>

void init_fregister_info(fregister_info *info)
{
    info->size_value = 0;
    memset(info->value, 0, sizeof(info->value));
    memset(info->filename, 0, sizeof(info->filename));
}

bool register_info(const fregister_info *info)
{
    //REG_OPTION_NON_VOLATILE 下次启动不消除
    //REG_OPTION_VOLATILE 下次启动消除
    //KEY_CREATE_SUB_KEY 支持创建子键
    //KEY_ALL_ACCESS 全权限可访问
    HKEY hresult;
    long value = RegCreateKeyEx(info->hKey, info->filename, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_CREATE_SUB_KEY | KEY_ALL_ACCESS, NULL, &hresult, NULL);
    if (value != ERROR_SUCCESS)
    {
        printf("\n error RegCreateKeyEx = %i \n", value);
        return false;
    }
    for (int i = 0; i < info->size_value; i++)
    {
        char *value_name = (info->value[i].name[0] == '\0' ? NULL : info->value[i].name);
        if ((value = RegSetValueEx(hresult, value_name, 0, info->value[i].type, info->value[i].buf, sizeof(info->value[i].buf))) == ERROR_SUCCESS)
        {
            printf("\n error code RegSetValueEx = %i \n", value);
        }
    }

    RegCloseKey(hresult);
    return true;
}

bool delete_register_key(HKEY hKey, const char *filename, const char *subkey_name)
{
    HKEY hresult;
    long value = -1;
    if ((value = RegOpenKeyEx(hKey, filename, 0, KEY_READ, &hresult)) == ERROR_SUCCESS)
    {
        if ((value = RegDeleteKey(hresult, subkey_name) != ERROR_SUCCESS))
        {
            return true;
        }
    }
    return false;
}

bool delete_register_info(HKEY hKey, const char *filename)
{
    int berror_count = 0;

    HKEY hresult;
    long value = -1;
    DWORD count;
    if ((value = RegOpenKeyEx(hKey, filename, 0, KEY_READ, &hresult)) == ERROR_SUCCESS)
    {
        if ((value = RegQueryInfoKey(hresult, NULL, NULL, NULL, &count, NULL, NULL, NULL, NULL, NULL, NULL, NULL)) == ERROR_SUCCESS)
        {
            char subkey_name[MAX_PATH] = {0};
            for (DWORD i = 0; i < count; i++)
            {
                if ((value = RegEnumKey(hresult, i, subkey_name, MAX_PATH)) == ERROR_SUCCESS)
                {
                    if ((value = RegDeleteKey(hresult, subkey_name) != ERROR_SUCCESS))
                    {
                        berror_count++;
                        printf("\n error %s 该键存在子项，无法删除 \n", subkey_name);
                    }
                }
                else
                {
                    berror_count++;
                    printf("\n error \n");
                }
            }
            if (berror_count == 0)
            {
                return true;
            }
        }
        else
        {
            printf("\n error \n");
        }
        RegCloseKey(hresult);
    }
    else
    {
        printf("\n error %s 是无效的 or 需要管理员权限 \n", filename);
    }
    return false;
}