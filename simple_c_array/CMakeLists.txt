aux_source_directory(./Private simple_c_array_file) #查找目录下的相关cpp文件

#生成静态库
add_library(simple_c_array STATIC ${simple_c_array_file})  #将他们编译为一个静态链接库