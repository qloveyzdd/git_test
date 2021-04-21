aux_source_directory(./Private simple_c_helper_file) #查找目录下的相关cpp文件

#链接其他库文件路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../simple_c_array)

add_library(simple_c_helper_file SHARED ${simple_c_helper_file})


#set_target_properties(simple_file_helper_shared PROPERTIES VERSION 1.2 SOVERSION 1)
target_link_libraries(simple_c_helper_file PRIVATE simple_c_array)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

install(TARGETS simple_c_helper_file LIBRARY DESTINATION lib)


