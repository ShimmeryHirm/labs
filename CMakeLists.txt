cmake_minimum_required(VERSION 3.23)
project(oaip_lab C)

set(ClMAKE_C_STANDARD 11)

include_directories(include)

add_executable(l1.1
        lab1/task1.c)

add_executable(l1.2
        lab1/task2.c)

add_executable(l1.3
        lab1/task3.c)

add_executable(l1.4
        lab1/task4.c)

add_executable(l2.1
        lab2/task1.c)

add_executable(l2.2
        lab2/task2.c)

add_executable(l2.3
        lab2/task3.c)

add_executable(test
        test.c)

add_executable(l3.1
        lab3/task1.c)

add_executable(l3.2
        lab3/task2.c)

add_executable(l3.3
        lab3/task3.c)

add_executable(l4.1
        lab4/task1.c)

add_executable(l4.2
        lab4/task2.c)

add_executable(l4.3
        lab4/task3.c)

add_executable(l5.1
        lab5/task1.c)

add_executable(l5.2
        lab5/task2.c)

add_executable(l5.3
        lab5/task3.c)

add_executable(l6.1
        lab6/task1.c)

add_executable(l6.2
        lab6/task2.c)
