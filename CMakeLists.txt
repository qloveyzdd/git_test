project(GIT_TEST)   #指定工程名称

aux_source_directory(. source_list) #搜索当前目录下的所有cpp文件

add_subdirectory(simple_c_array)    #添加查找文件夹，这样可以去文件夹中查找编译
add_subdirectory(simple_c_helper_file)    #添加查找文件夹，这样可以去文件夹中查找编译
add_subdirectory(simple_c_string_algorithm)    #添加查找文件夹，这样可以去文件夹中查找编译
add_subdirectory(simple_c_windows)    #添加查找文件夹，这样可以去文件夹中查找编译
add_subdirectory(simple_c_path)    #添加查找文件夹，这样可以去文件夹中查找编译
add_subdirectory(main_core)    #添加查找文件夹，这样可以去文件夹中查找编译
add_subdirectory(simple_c_file)    #添加查找文件夹，这样可以去文件夹中查找编译

add_executable(source ${source_list})   #生成目标文件

target_link_libraries(source simple_c_array)    #添加链接库
target_link_libraries(source simple_c_helper_file)    #添加链接库
target_link_libraries(source simple_c_string_algorithm)    #添加链接库
target_link_libraries(source simple_c_windows)    #添加链接库
target_link_libraries(source simple_c_path)    #添加链接库
target_link_libraries(source main_core)    #添加链接库
target_link_libraries(source simple_c_file)    #添加链接库

#如果B的头文件中包含了A的头文件(源文件间接包含)，那么这里应该用PUBLIC，依赖关系会传递下去。
#如果B仅源文件中包含了A的头文件，那么这里应该用PRIVATE，依赖关系不会传递。
#如果B的头文件包含A，但源文件未包含，那么这里应该用INTERFACE，依赖关系不会传递。


SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

set(CMAKE_BUILD_TYPE DEBUG)