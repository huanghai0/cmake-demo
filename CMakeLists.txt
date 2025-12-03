# CMake最低版本要求
cmake_minimum_required(VERSION 3.10)

# 项目名称和版本
project(CMakeDemo VERSION 1.0.0 LANGUAGES CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 设置输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# 添加可执行文件
add_executable(${PROJECT_NAME} src/main.cpp)

# 安装目标
install(TARGETS ${PROJECT_NAME} DESTINATION bin)

# 可选：添加子目录
# add_subdirectory(lib)

# 可选：查找包
# find_package(Boost 1.70 REQUIRED COMPONENTS filesystem system)

# 可选：包含目录
include_directories(include)

# 可选：链接库
target_link_libraries(${PROJECT_NAME} PRIVATE fmt spdlog)
