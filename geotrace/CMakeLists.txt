include_directories(.)
add_library(geotrace src/objects/sphere.c src/objects/line.c src/objects/plane.c src/objects/cylinder.c
        src/vectors/vec3d.c src/vectors/vec3d2.c src/math/solve.c src/matrix/matrix.c src/matrix/matrix2.c  src/objects/objects.c)