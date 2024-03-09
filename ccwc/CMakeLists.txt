cmake_minimum_required( VERSION 3.5 )

project( coding_challenge_1 )

set( CMAKE_CXX_STANDARD 17 )

add_subdirectory( wc )

add_executable( ccwc
  main.cpp 
)

target_link_libraries( ccwc
  wc 
)
