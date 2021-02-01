set(THREADS_PREFER_PTHREAD_FLAG ON)
set(SOURIS_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB_RECURSE SOURIS_SRC_FILES "${SOURIS_SRC_DIR}/*.cpp")

add_executable(Souris WIN32 ${SOURIS_SRC_FILES})

find_package(Threads REQUIRED)
target_link_libraries(Souris PRIVATE Threads::Threads)

target_include_directories(Souris PRIVATE ${SOURIS_SRC_DIR})
