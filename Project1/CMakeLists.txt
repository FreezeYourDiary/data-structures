cmake_minimum_required(VERSION 3.27)
project(Project1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project1 main.cpp
        List.h
        ArrayList.h
        ArrayList.cpp
        LinkedList.h
        LinkedList.cpp
        Node.h
        SinglyLinkedListHT.h
        SinglyLinkedListHT.cpp
        DLinkedList.h
        DNode.h
        DLinkedList.cpp
)
