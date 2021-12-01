cmake_minimum_required(VERSION 3.0.0)
project(ndiReceiverDmx VERSION 0.1.0)

include(CTest)
enable_testing() 

add_executable(ndiReceiverDmx main.cpp 
        src/ndiReceiverWrapper.cpp
        src/ArtnetManager.cpp
        src/ChannelManager.cpp
        src/Dimmer.cpp
        src/PixelInMatrix.cpp
        src/PixelMatrix.cpp
        src/TimingCalculator.cpp)


set (ProjectPath "/home/pokm/Projects/Lights/ndiReceiver")
include_directories(${ProjectPath}/include)
link_directories(${ProjectPath}/src)

# NDI Related linking 
set (NdiFrameworkPath "/home/pokm/Projects/Lights/Frameworks/NDI_Framework")
set (NdiLibFile "libndi.so.5")
message(STATUS "NDI Framework: ${NdiFrameworkPath}")
message(STATUS "NDI Framework includes : ${NdiFrameworkPath}/include")
message(STATUS "NDI Framework lib : ${NdiFrameworkPath}/lib")

include_directories(${NdiFrameworkPath}/include)
link_directories(${NdiFrameworkPath}/lib)
target_link_libraries(${PROJECT_NAME} ${NdiFrameworkPath}/lib/x86_64-linux-gnu/${NdiLibFile})


# OpenCV - taken from package, need to be compiled from sources in future
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
target_link_libraries( ${PROJECT_NAME} ${OpenCV_LIBS} )

target_link_libraries( ${PROJECT_NAME} -lpthread)
target_link_libraries( ${PROJECT_NAME} -lartnet)
target_link_libraries( ${PROJECT_NAME} -lboost_system)
target_link_libraries( ${PROJECT_NAME} -lboost_thread)

#add_library(ndiReceiverWrapperLib src/ndiReceiverWrapper.cpp include/ndiReceiverWrapper.h)

#target_link_libraries(ndiReceiverDmx  ndiReceiverWrapperLib)


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
