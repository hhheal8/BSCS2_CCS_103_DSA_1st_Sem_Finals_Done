cmake_minimum_required(VERSION 3.0.0)

project(
  FoodCourtSeatReservationSystem 
  VERSION 0.1.0 
  LANGUAGES CXX
)

add_executable(
  FoodCourtSeatReservationSystem 
  main.cpp

  sources/AlgorithmTools.cpp
  sources/ConsoleInterface.cpp
  sources/FileCSS.cpp
  sources/FileHTML.cpp
  sources/FoodCourtSeatReservationSystem.cpp
)

target_include_directories(
  FoodCourtSeatReservationSystem PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/includes
)
