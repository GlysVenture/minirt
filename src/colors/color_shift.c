//
// Created by Tadeusz Kondracki on 1/25/22.
//

#include "colors.h"
#include <math.h>

int shift_color2(int color, double shift)
{
	if (islessequal(shift, 0))
		return (0);
	return (shift_color(0, color, shift));
}
