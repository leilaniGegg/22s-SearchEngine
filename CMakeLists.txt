cmake_minimum_required(VERSION 3.16)
project(22s_final_proj)

set(CMAKE_CXX_STANDARD 17)

add_executable(22s_final_proj main.cpp catch_setup.cpp AVLTree.h Word.cpp Word.h Article.cpp Article.h DocumentParser.cpp DocumentParser.h IndexHandler.cpp IndexHandler.h SearchEngine.cpp SearchEngine.h QueryProcessor.cpp QueryProcessor.h)
