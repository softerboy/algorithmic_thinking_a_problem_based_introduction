cmake_minimum_required(VERSION 3.15)
project(book_algorithmic_thinking_a_problem_based_introduction C)

set(CMAKE_C_STANDARD 11)

include_directories(common)

add_subdirectory(chapter_1/hash_tables)
add_subdirectory(chapter_4/graphs_and_breadth_first_search)

