aux_source_directory(./Private main_core) #查找目录下的相关cpp文件

#链接其他库文件路径
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../simple_c_string_algorithm)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../simple_c_guid)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../simple_c_array)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/../simple_c_helper_file)

add_library(main_core SHARED ${main_core})


#set_target_properties(simple_file_helper_shared PROPERTIES VERSION 1.2 SOVERSION 1)
target_link_libraries(main_core PRIVATE simple_c_string_algorithm)
target_link_libraries(main_core PRIVATE simple_c_guid)
target_link_libraries(main_core PRIVATE simple_c_array)
target_link_libraries(main_core PRIVATE simple_c_helper_file)

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

install(TARGETS main_core LIBRARY DESTINATION lib)


