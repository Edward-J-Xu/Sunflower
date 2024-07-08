cmake_minimum_required(VERSION 3.10)
project(Sunflower)

set(CMAKE_CXX_STANDARD 17)

# Proto files
file(GLOB PROTO_FILES proto/**/*.proto)

# Generate C++ source files from proto files
foreach(PROTO_FILE ${PROTO_FILES})
    get_filename_component(PROTO_PATH ${PROTO_FILE} PATH)
    get_filename_component(PROTO_NAME ${PROTO_FILE} NAME_WE)
    set(PROTO_SRC "${PROTO_PATH}/${PROTO_NAME}.pb.cc")
    set(PROTO_HDR "${PROTO_PATH}/${PROTO_NAME}.pb.h")

    add_custom_command(
        OUTPUT ${PROTO_SRC} ${PROTO_HDR}
        COMMAND protoc
        ARGS --cpp_out=${PROTO_PATH} --proto_path=${PROTO_PATH} ${PROTO_FILE}
        DEPENDS ${PROTO_FILE}
    )

    list(APPEND PROTO_SRCS ${PROTO_SRC})
    list(APPEND PROTO_HDRS ${PROTO_HDR})
endforeach()

# Include directories
include_directories(proto)

# Source files
file(GLOB SOURCES
    "wallet/*.cpp"
    "filewriter/*.cpp"
    ${PROTO_SRCS}
)

# Add executable
add_executable(sunflower ${SOURCES})

# Link libraries
target_link_libraries(sunflower
    protobuf
)
