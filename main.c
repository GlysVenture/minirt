#include <stdio.h>
#include "geotrace.h"

int main() {
	t_line	ray = {{1, 0, 0}, {0, 0, 0}};
	t_plane	plane = {{-5, 1, 1}, {0, 1, 0}};
	t_sphere sphere = {{7, 1, 1}, 4};

	printf("plane distance: %f\n", plane_intersect(&plane, ray));
	printf("sphere distance: %f\n", sphere_intersect(&sphere, ray));
	return 0;
}
