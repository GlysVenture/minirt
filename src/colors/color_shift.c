//
// Created by Tadeusz Kondracki on 1/25/22.
//

#include "colors.h"
#include <math.h>

int shift_color2(int c, double shift)
{
	if (islessequal(shift, 0))
		return (0);
	if (shift > 1)
		shift = shift - floor(shift);
	return (create_color(0, (int)(get_red(c) * shift), (int)(get_green(c) * shift), (int)(get_blue(c) * shift)));
}
