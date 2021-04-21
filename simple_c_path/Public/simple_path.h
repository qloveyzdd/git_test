#pragma once

void get_path_directory_inline(char *path_buf); //获取路径

void get_path_directory(char *buf, const char *path_buf); //获取当前路径

void get_path_clean_filename(char *buf, const char *path_buf); //获取文件名称及后缀

void normslization_path(char *path_buf); //单位化