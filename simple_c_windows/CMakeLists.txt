aux_source_directory(./Private simple_c_windows) #查找目录下的相关cpp文件

add_library(simple_c_windows ${simple_c_windows})  #将他们编译为一个静态链接库