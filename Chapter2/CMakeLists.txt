cmake_minimum_required(VERSION 3.13)
project(Chapter2_0 C)

set(CMAKE_C_STANDARD 99)

add_executable(Chapter2_0 main.c DataElement.h SequenceList.h SequenceList.c LinkList.h LinkList.c CircularLinkList.h CircularLinkList.c)