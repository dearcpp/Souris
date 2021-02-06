set(THREADS_PREFER_PTHREAD_FLAG ON)

set(SOURIS_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")
set(SOURIS_VENDOR_DIR "${CMAKE_CURRENT_SOURCE_DIR}/vendor")

file(GLOB_RECURSE SOURIS_SRC_FILES "${SOURIS_SRC_DIR}/*.cpp")

add_subdirectory("${SOURIS_VENDOR_DIR}/json")
add_executable(Souris WIN32 ${SOURIS_SRC_FILES})

target_compile_features(Souris PRIVATE cxx_std_17)

find_package(Threads REQUIRED)

target_link_libraries(Souris PRIVATE Threads::Threads)
target_link_libraries(Souris PRIVATE nlohmann_json::nlohmann_json)

target_include_directories(Souris PRIVATE ${SOURIS_SRC_DIR})
