set(CMAKE_PREFIX_PATH $ENV{LIB})

find_path(FUNCTIONS_INCLUDE_DIR strings.h file.h
        HINTS ${CMAKE_PREFIX_PATH}/include)

find_library(FUNCTIONS_LIBRARY
        NAMES functions
        HINTS ${CMAKE_PREFIX_PATH}/lib)