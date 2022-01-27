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

int shift_black(int c, double shift)
{
	if (islessequal(shift, 0))
		return (0);
	if (shift > 1)
		shift = shift - floor(shift);
	return (create_color(0, (int)(get_red(c) * shift),
						 (int)(get_green(c) * shift),
						 (int)(get_blue(c) * shift)));
}

void	unpack_color(double color[], int color2,  double ratio)
{
	color[0] = ratio * (double)get_red(color2) / 255;
	color[1] = ratio * (double)get_green(color2) / 255;
	color[2] = ratio * (double)get_blue(color2) / 255;
}

void	color_mult(double color[], int color2)
{
	color[0] *= (double)get_red(color2) / 255;
	color[1] *= (double)get_green(color2) / 255;
	color[2] *= (double)get_blue(color2) / 255;
}

void	color_mult2(double color[], int color2, double scalar)
{
	color[0] *= scalar * (double)get_red(color2) / 255;
	color[1] *= scalar * (double)get_green(color2) / 255;
	color[2] *= scalar * (double)get_blue(color2) / 255;
}

void	color_scalar(double color[], double scalar)
{
	color[0] *= scalar;
	color[1] *= scalar;
	color[2] *= scalar;
}

void	color_sum(double color[], const double color2[])
{
	color[0] += color2[0];
	color[1] += color2[1];
	color[2] += color2[2];
}

void	color_sum2(double color[], const double color2[], double scalar)
{
	color[0] += scalar * color2[0];
	color[1] += scalar * color2[1];
	color[2] += scalar * color2[2];
}

void	clamp(double color[], double min, double max)
{
	if (isless(color[0], min))
		color[0] = min;
	else if (isgreater(color[0], max))
		color[0] = max;
	if (isless(color[1], min))
		color[1] = min;
	else if (isgreater(color[1], max))
		color[1] = max;
	if (isless(color[2], min))
		color[2] = min;
	else if (isgreater(color[2], max))
		color[2] = max;
}
