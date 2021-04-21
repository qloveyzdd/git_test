#include "..\Public\simple_file.h"
#include "..\..\simple_c_helper_file\simple_c_helper_file.h"
#include "..\..\simple_c_string_algorithm\simple_c_string_algorithm.h"
#include "..\..\simple_c_path\simple_c_path.h"
#include "..\..\main_core\Public\log.h"
#include <string.h>
#include <stdio.h>
#define MAX_PATH 260

void copy_files(const char *src, const char *dest)
{
    if (!((strstr(src, "\\") || strstr(src, "/")) && (strstr(dest, "\\") || strstr(dest, "/"))))
    {
        printf("无效 非标准路径 %s", dest);
    }
    else
    {
        def_c_paths paths;
        init_def_c_paths(&paths);
        find_files(dest, &paths, true);
        for (int i = 0; i < paths.index; i++)
        {
            char buf_tmp[MAX_PATH] = {0};
            strcpy(buf_tmp, paths.paths[i]);
            remove_string_start(buf_tmp, dest);
            char buf_local_path[MAX_PATH] = {0};
            strcpy(buf_local_path, src);
            strcat(buf_local_path, buf_tmp);

            {
                char buf_local_path_tmp[MAX_PATH] = {0};
                strcpy(buf_local_path_tmp, buf_local_path);
                get_path_directory_inline(buf_local_path_tmp);

                if (create_file_directory(buf_local_path_tmp) == false)
                {
                    log_error("当前路径下内容无法拷贝：%s", buf_local_path_tmp);
                    break;
                }
            }

            if (!(copy_file(paths.paths[i], buf_local_path)))
            {
                //log_success("将 %s 拉取到 %s 成功", paths.paths[i], buf_local_path);
            }
            else
            {
                log_error("将 %s 拉取到 %s 失败", paths.paths[i], buf_local_path);
            }
            int b_value = ((double)i / (double)paths.index) * 100 + 1;
            printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b");
            printf("当前正在下载远端数据 %3d%%", b_value);
        }
        log_log("数据拉取结束!!!");
    }
}