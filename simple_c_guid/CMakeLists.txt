aux_source_directory(./Private simple_c_guid) #查找目录下的相关cpp文件

#链接其他库文件路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../simple_c_string_algorithm)

add_library(simple_c_guid SHARED ${simple_c_guid})


#set_target_properties(simple_file_helper_shared PROPERTIES VERSION 1.2 SOVERSION 1)
target_link_libraries(simple_c_guid PRIVATE simple_c_string_algorithm)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

install(TARGETS simple_c_guid LIBRARY DESTINATION lib)


