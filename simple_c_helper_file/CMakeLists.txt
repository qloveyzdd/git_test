aux_source_directory(./Private simple_file_helper) #查找目录下的相关cpp文件

add_library(simple_file_helper_lib ${simple_file_helper})  #将他们编译为一个静态链接库