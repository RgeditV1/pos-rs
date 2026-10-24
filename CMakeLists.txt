cmake_minimum_required(VERSION 3.22)
project(pos-rs VERSION 0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/lib")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON) # resource file e.g .qrc

find_program(CLANG_TIDY_EXE NAMES "clang-tidy")

if(CLANG_TIDY_EXE)
  set(CLANG_TIDY_WRAPPER "${CMAKE_SOURCE_DIR}/utils/clang-tidy-wrapper.py")

  set(CMAKE_CXX_CLANG_TIDY
    "python3;${CLANG_TIDY_WRAPPER};${CLANG_TIDY_EXE};-extra-arg=-std=c++20;-extra-arg=-Wno-unknown-warning-option;-extra-arg=-Wno-ignored-optimization-argument"
  )
endif()

option(BUILD_SHARED_LIBS "Build using shared libraries" OFF)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

set(CARGO_TARGET_DIR "${CMAKE_CURRENT_SOURCE_DIR}/target")
set(RUST_LIB_NAME "libbackend")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file(GLOB_RECURSE HEADERS CONFIGURE_DEPENDS "include/*.hpp")

add_executable(pos-rs ${SOURCES} ${HEADERS} res.qrc)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
  set(CARGO_PROFILE "release")
  set(RUST_LIB_FILE "libbackend.a")
  set(RUST_LIB_PATH "${CARGO_TARGET_DIR}/release/${RUST_LIB_FILE}")
else()
  set(CARGO_PROFILE "debug")
  set(RUST_LIB_FILE "libbackend.a")
  set(RUST_LIB_PATH "${CARGO_TARGET_DIR}/debug/${RUST_LIB_FILE}")
endif()

add_custom_command(
    OUTPUT ${RUST_LIB_PATH}
    COMMAND cargo build --profile=${CARGO_PROFILE}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    DEPENDS Cargo.toml build.rs src/backend/lib.rs
    COMMENT "Building Rust BackendLib"
)

add_library(rust_backend STATIC IMPORTED)
set_target_properties(rust_backend PROPERTIES
    IMPORTED_LOCATION ${RUST_LIB_PATH}
)

add_custom_target(run_cargo_build DEPENDS ${RUST_LIB_PATH})
add_dependencies(rust_backend ${RUST_LIB_PATH})

target_include_directories(pos-rs PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(pos-rs PRIVATE
                      #rust_backend
                      Qt6::Core
                      Qt6::Gui
                      Qt6::Widgets)
