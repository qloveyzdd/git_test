#include "../Public/simple_path.h"
#include "../../simple_c_string_algorithm/simple_c_string_algorithm.h"
#include "../../simple_c_array/simple_c_array.h"
#include <string.h>

void get_path_directory_inline(char *path_buf)
{
    normslization_path(path_buf);
    char filename[260] = {0};
    get_path_clean_filename(filename, path_buf);

    remove_string_start(path_buf, filename);
    path_buf[strlen(path_buf)-1] = '\0';
}

void get_path_directory(char *buf, const char *path_buf)
{
    strcpy(buf, path_buf);
    get_path_directory_inline(buf);
}

void get_path_clean_filename(char *buf, const char *path_buf)
{
    simple_c_string c_string;
    dismantling_string(path_buf, "/", &c_string);
    char *temp = get_string(c_string.size-1,&c_string);
    strcpy(buf,temp);
    destroy_string(&c_string);
}

void normslization_path(char *path_buf)
{
    replace_char_inline(path_buf, '\\', '/');
}