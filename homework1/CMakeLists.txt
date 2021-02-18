cmake_minimum_required(VERSION 3.17)
project(homework1)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(homework1 main.cpp geometry.h Point.cpp Point.h PolygonalChain.cpp PolygonalChain.h ClosedPolygonalChain.h Polygon.cpp Polygon.h Triangle.h RegularPolygon.cpp RegularPolygon.h Trapezoid.cpp Trapezoid.h)