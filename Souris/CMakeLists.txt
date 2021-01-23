set(SOURIS_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

file(GLOB_RECURSE SOURIS_SRC_FILES "${SOURIS_SRC_DIR}/*.cpp")

add_executable(Souris WIN32 ${SOURIS_SRC_FILES})
target_include_directories(Souris PRIVATE ${SOURIS_SRC_DIR})
