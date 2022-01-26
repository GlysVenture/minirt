#include <math.h>
#include <stdio.h>

double below_zero(double val,const char *str, char sign)
{
	int j;

	j = 0;
	while (str[j])
	{
		val *= 10;
		val += str[j] - 48;
		j++;
	}
	val = val*pow(10,j * -1);
	if (sign == '-')
		val *= -1;
	printf("%f\n", val);
	return val;
}
double ft_atod(const char *arr){
    int i;
    double val;

    i=0;
    val=0;
    if (arr[0] == '+' || arr[0] == '-')
	    i++;
    while (arr[i] != '\0')
    {
        if (arr[i] != '.')
            val = (val*10) + (arr[i] - 48);
	else
		return (val = below_zero(val, arr + (i + 1), arr[0]));
        i++;
    }
    return (2);
 //   val = val*pow(10,j);
}

int main (void)
{
	ft_atod("-12.3");
	return 1;
}
