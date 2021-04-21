aux_source_directory(./Private simple_path_file) #查找目录下的相关cpp文件

#编写动态库
#add_definitions("-DLIBA_API_EXPORTS")
#编写静态库
#add_definitions("-DLIBA_STATIC")
#头文件目录
#include_directories(${CMAKE_CURRENT_SOURCE_DIR})

#链接其他库文件路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../simple_c_array)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../simple_c_string_algorithm)

#生成动态库
add_library(simple_path_file SHARED ${simple_path_file})  #将他们编译为一个动态链接库
#设置文件名
#set_target_properties(simple_file_helper_shared PROPERTIES OUTPUT_NAME "simple_file_helper")
#链接其他库依赖
target_link_libraries(simple_path_file PRIVATE simple_c_array)
target_link_libraries(simple_path_file PRIVATE simple_c_string_algorithm)

#生成静态库
#add_library(simple_file_helper_static STATIC ${simple_file_helper_file})  #将他们编译为一个静态链接库
#设置文件名
#set_target_properties(simple_file_helper_static PROPERTIES OUTPUT_NAME "simple_file_helper")
#链接其他库依赖
#target_link_libraries(simple_file_helper_static simple_c_array_static)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

install(TARGETS simple_path_file LIBRARY DESTINATION lib)