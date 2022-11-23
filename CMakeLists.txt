cmake_minimum_required(VERSION 3.23)
project(oaip_lab C)

set(CMAKE_C_STANDARD 17)

add_subdirectory(src/lab-lib lab-lib)
link_libraries(lab-lib)

add_executable(test test.c)

add_executable(l1.1 src/lab1/task1.c)
add_executable(l1.2 src/lab1/task2.c)
add_executable(l1.3 src/lab1/task3.c)
add_executable(l1.4 src/lab1/task4.c)

add_executable(l2.1 src/lab2/task1.c)
add_executable(l2.2 src/lab2/task2.c)
add_executable(l2.3 src/lab2/task3.c)

add_executable(l3.1 src/lab3/task1.c)
add_executable(l3.2 src/lab3/task2.c)
add_executable(l3.3 src/lab3/task3.c)

add_executable(l4.1 src/lab4/task1.c)
add_executable(l4.2 src/lab4/task2.c)
add_executable(l4.3 src/lab4/task3.c)

add_executable(l5.1 src/lab5/task1.c)
add_executable(l5.2 src/lab5/task2.c)
add_executable(l5.3 src/lab5/task3.c)

add_executable(l6.1 src/lab6/task1.c)
add_executable(l6.2 src/lab6/task2.c)

add_executable(l7 src/lab7/main.c)

add_executable(l8 src/lab8/main.c)
