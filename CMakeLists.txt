cmake_minimum_required(VERSION 3.17)
project(minirt C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_VERBOSE_MAKEFILE on)

INCLUDE_DIRECTORIES (/System/Library/Frameworks mlx geotrace libft src)
if (APPLE)
    FIND_LIBRARY(OPENGL_LIBRARY OpenGL)
    FIND_LIBRARY(APPKIT_LIBRARY AppKit )
    MARK_AS_ADVANCED (OPENGL_LIBRARY
            APPKIT_LIBRARY)
    #add_subdirectory(mlx)
    SET(EXTRA_LIBS ${OPENGL_LIBRARY} ${APPKIT_LIBRARY})
else()
    add_subdirectory(mlx_linux)
endif()
add_subdirectory(libft)
add_subdirectory(geotrace)
SET(EXTRA_LIBS ${EXTRA_LIBS} mlx geotrace libft)

link_directories(mlx)

add_executable(raytracer src/colors/colors.c src/parser/isvalid.c src/parser/aggr.c src/parser/parse_obj.c src/parser/rotate.c src/parser/sheer.c src/parser/sheer2.c src/parser/utils.c src/parser/gnl/get_next_line.c src/parser/matrix_opr.c src/parser/gnl/get_next_line_utils.c src/parser/args.c src/parser/check.c src/main.c src/camera.c src/camera.h src/object.c src/object.h src/key_handler.h src/light/light.c src/light/light.h src/debug/debug.c src/debug/debug.h src/colors/color_shift.c src/minirt.h src/rays/ray.c src/rays/ray.h src/rays/vec_utils.c src/rays/vec_utils.h src/parser/parse.c src/parser/parse.h src/rays/shadow.c src/parser/free_parsing.c src/key_handler.c src/mlx_utils.c src/mlx_utils.h src/colors/color_shift2.c)
target_link_libraries(raytracer ${EXTRA_LIBS})