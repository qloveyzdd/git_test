project(GIT_TEST)   #指定工程名称

aux_source_directory(. source_list) #搜索当前目录下的所有cpp文件

add_subdirectory(simple_c_array)    #添加查找文件夹，这样可以去文件夹中查找编译
add_subdirectory(simple_c_helper_file)    #添加查找文件夹，这样可以去文件夹中查找编译

add_executable(source ${source_list})   #生成目标文件

target_link_libraries(source simple_file_helper_lib)    #添加链接库
target_link_libraries(source simple_c_array_lib)    #添加链接库


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(CMAKE_BUILD_TYPE DEBUG)