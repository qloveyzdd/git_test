aux_source_directory(./Private simple_c_array_file) #查找目录下的相关cpp文件

#头文件目录
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#生成动态库
#add_library(simple_c_array_shared SHARED ${simple_c_array_file})  #将他们编译为一个动态链接库
#设置文件名
#set_target_properties(simple_c_array_shared PROPERTIES OUTPUT_NAME "simple_c_array_shared")

#生成静态库
add_library(simple_c_array_static STATIC ${simple_c_array_file})  #将他们编译为一个静态链接库
#设置文件名
#set_target_properties(simple_c_array_static PROPERTIES OUTPUT_NAME "simple_c_array_lib")