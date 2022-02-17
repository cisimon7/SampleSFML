cmake_minimum_required(VERSION 3.21)
project(SampleSFML)

set(CMAKE_CXX_STANDARD 23)

set(SFML_DIR ${PROJECT_SOURCE_DIR}/dependencies/SFML)
set(OPEN_MP_DIR ${PROJECT_SOURCE_DIR}/dependencies/openMP)
set(PYBIND_DIR ${PROJECT_SOURCE_DIR}/dependencies/pybind11)

add_subdirectory(${SFML_DIR})
add_subdirectory(${PYBIND_DIR})

add_executable(SampleSFML main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${SFML_DIR}/include ${OPEN_MP_DIR}/include)
target_link_directories(${PROJECT_NAME} PRIVATE ${SFML_DIR}/src)
target_link_libraries(${PROJECT_NAME} pybind11::embed sfml-graphics sfml-window sfml-system sfml-audio)

SET(OPENMP_COMPILE_FLAGS "-Xpreprocessor -fopenmp")
#SET(OPENMP_LINK_FLAGS    "-fopenmp=libomp")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${OPENMP_COMPILE_FLAGS}")
SET(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${OPENMP_LINK_FLAGS}")

set(OPEN_MP_LIB "${OPEN_MP_DIR}/lib/libomp.dylib")
target_link_libraries(${PROJECT_NAME} ${OPEN_MP_LIB})
