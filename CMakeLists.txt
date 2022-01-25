cmake_minimum_required(VERSION 3.17)
project(minirt_temp C)

set(CMAKE_C_STANDARD 99)

INCLUDE_DIRECTORIES (/System/Library/Frameworks mlx geotrace libft)
if (APPLE)
    FIND_LIBRARY(OPENGL_LIBRARY OpenGL)
    FIND_LIBRARY(APPKIT_LIBRARY AppKit )
    MARK_AS_ADVANCED (OPENGL_LIBRARY
            APPKIT_LIBRARY)
    add_subdirectory(mlx)
    SET(EXTRA_LIBS ${OPENGL_LIBRARY} ${APPKIT_LIBRARY})
elseif(UNIX)
    add_subdirectory(mlx_linux)
endif()
add_subdirectory(libft)
add_subdirectory(geotrace)
SET(EXTRA_LIBS ${EXTRA_LIBS} mlx geotrace libft)

add_executable(raytracer src/main.c src/camera.c src/camera.h src/object.c src/object.h)
target_link_libraries(raytracer ${EXTRA_LIBS})