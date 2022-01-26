//
// Created by Tadeusz Kondracki on 1/25/22.
//

#include "colors.h"
#include <math.h>

int shift_color2(int c, int c2, double shift)
{
	if (islessequal(shift, 0))
		return (0);
	if (shift > 1)
		shift = shift - floor(shift);
	return (create_color(0, (int)(get_red(c) * shift * get_red(c2) / 255),
		(int)(get_green(c) * shift * get_green(c2) / 255),
		(int)(get_blue(c) * shift * get_blue(c2) / 255)));
}
