cmake_minimum_required(VERSION 3.12)

project(Souris
	VERSION 0.0.1
	DESCRIPTION "Lightweight cross-platform monitoring software for your devices"
)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY SOURIS_PROJECT Souris)
add_subdirectory(Souris)
