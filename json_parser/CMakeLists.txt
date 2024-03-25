cmake_minimum_required( VERSION 3.5 )

project( coding_challenge_2 )

set( CMAKE_CXX_STANDARD 17 )

add_executable( jsonParser 
  "main.cpp"
  "jsonParser/jsonParser.cpp"
)
