cmake_minimum_required(VERSION 2.8)

project(TransmitMessage)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g")

set( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib )

find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/proto
    ${PROJECT_SOURCE_DIR}/Config
    )

find_package( OpenCV 3.2 REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_library("rwmemory" SHARED
    src/rw_sharedmemory.c
    src/Mes_semaphore.c
    )

add_executable(tran_message
    proto/sensor_image.pb.cc
    proto/res_message.pb.cc
    Config/mem_config.pb.cc
    main.cpp)

target_link_libraries(tran_message  ${PROJECT_SOURCE_DIR}/lib/librwmemory.so
    ${PROTOBUF_LIBRARIES}
    ${OpenCV_LIBS})
#/home/hyz/self_driving/my_code/TransmitMessage/lib/librwmemory.so
