cmake_minimum_required(VERSION 3.17)
project(minirt_temp C)

set(CMAKE_C_STANDARD 99)

INCLUDE_DIRECTORIES (/System/Library/Frameworks mlx geotrace libft src)
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

add_executable(raytracer src/parser/gnl/get_next_line.c src/parser/gnl/get_next_line_utils.c src/parser/args.c src/parser/check.c src/main.c src/camera.c src/camera.h src/object.c src/object.h src/key_handler.h src/light/light.c src/light/light.h src/debug/debug.c src/debug/debug.h src/colors/color_shift.c src/minirt.h src/rays/ray.c src/rays/ray.h src/rays/vec_utils.c src/rays/vec_utils.h)
target_link_libraries(raytracer ${EXTRA_LIBS})