cmake_minimum_required(VERSION 2.6) # Pour éviter un warning au lancement de CMake, on doit préciser la version minimale

# Nom du projet
project(particle_filter)

include_directories(
    /usr/local/include/opencv2
    /usr/local/include
    /usr/include/opencv2
    /usr/include/
    ./include/
    ./src/filter/ #for .tpp
    ./src/viewer/
)

link_directories(
    /usr/local/lib
	/usr/lib    
)

file(
    GLOB_RECURSE
    source_files
    src/*
    include/*
)

set(CMAKE_BUILD_TYPE Release)
set(EXECUTABLE_OUTPUT_PATH ../bin/)
set(CMAKE_CXX_FLAGS "-std=c++0x -g -ggdb")#active C++ 2011 standard

#find_package (Threads)
find_package( OpenCV REQUIRED )

add_library(
    particleFilter
    SHARED
    ${source_files}
)

# Déclaration de l'exécutable
add_executable(
    demo
    bin/src/demo.cpp
    ${source_files}
)

target_link_libraries(
    demo
		particleFilter
		
		${OpenCV_LIBS}
	#libs de boost
                boost_random
		boost_filesystem
		boost_system
                boost_thread
)
