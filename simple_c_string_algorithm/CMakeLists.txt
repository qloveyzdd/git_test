aux_source_directory(./Private simple_c_string_algorithm) #查找目录下的相关cpp文件

add_library(simple_c_string_algorithm_lib ${simple_c_string_algorithm})  #将他们编译为一个静态链接库