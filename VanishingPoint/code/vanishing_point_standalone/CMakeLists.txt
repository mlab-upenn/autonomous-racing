cmake_minimum_required(VERSION 2.8)
project( Vanishing_Point )

# find openCV
find_package( OpenCV REQUIRED )

# find flycapture libraries
# include_directories("/usr/include/flycapture")
# find_library(FLYCAPTURE2 flycapture)

# add_executable( vp vanishing_point.cpp )
# add_executable( vp vanishing_point_flexible.cpp )
add_executable( vp vanishing_point_video.cpp )
# add_executable( vp vanishing_point_cam.cpp )
# link program to opencv and flycapture
target_link_libraries( vp ${OpenCV_LIBS})
# target_link_libraries( vp ${OpenCV_LIBS} ${FLYCAPTURE2})
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
SET(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -nopie -pg")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")
