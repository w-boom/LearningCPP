cmake_minimum_required(VERSION 3.10)

# 设置项目名称
project(MyProject)

# 获取项目根目录下的所有 .cpp 文件
file(GLOB SOURCES "*.c" "*.cpp")

# 对每个源文件创建一个可执行文件
foreach(SOURCE ${SOURCES})
    # 提取文件名（不带扩展名）
    get_filename_component(EXECUTABLE_NAME ${SOURCE} NAME_WE)
    add_executable(${EXECUTABLE_NAME} ${SOURCE})
endforeach()
