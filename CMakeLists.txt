cmake_minimum_required(VERSION 3.10.0)
project(RISC-V-Simulator VERSION 0.1.0 LANGUAGES C)

include(CTest)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.c)

add_library(riscv ${SRC_FILES})

# Create the executable
add_executable(riscvsim src/main.c)
target_link_libraries(riscvsim PRIVATE riscv)

# Testing
add_executable(tester src/tester.c)
target_link_libraries(tester PRIVATE riscv)

file(GLOB TASK_DIRS tests/task*)
foreach(TASK_DIR IN LISTS TASK_DIRS)
	file(GLOB TEST_FILES ${TASK_DIR}/*.bin)
	foreach(TEST_FILE IN LISTS TEST_FILES)
		string(REGEX REPLACE "^.*(task[0-9]+)/(.+)\\.bin$" "\\1_\\2" TEST_NAME ${TEST_FILE})
		cmake_path(REMOVE_EXTENSION TEST_FILE)
		add_test(${TEST_NAME} tester ${TEST_FILE})
	endforeach()
endforeach()
