#include "mrt.h"
#include "geotrace.h"
#include "gnl/get_next_line.h"
#include "minirt.h"
#include "parse.h"

#include "debug/debug.h"
int  hexcolor(char *line);

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
	val = val*pow(10, j * -1);
	if (sign == '-')
		val *= -1;
	return (val);
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
    return (val);
}
t_amb_light check_alight(char *arg)
{
	char **args;
	t_amb_light a;

	args = ft_split(arg, ' ');
	a.ratio = ft_atod(args[1]);
	if (a.ratio >= 1.0 || a.ratio <= 0.0)
	{
		printf("Error not in the correct range %f\n", a.ratio);
			exit (1); //todo err return
	}
	a.color = hexcolor(args[2]);
	return (a);
}

int	check_arg(char *arg, t_vars *v)
{
	if (arg[0] == '\n')
		return (1);
	else if (arg[0] == 'A')
	{
		v->ambient = check_alight(arg);
		return (1);
	}
	else if (arg[0] == 'L')
		return (parse_light(arg, v));
	else if (arg[0] == 's')
		return (parse_sphere(arg, v));
	else if (arg[0] == 'p')
		return (parse_plane(arg, v));
	return (1);
}
char *get_arg(char *filename, t_vars *v)
{
	int fd;
	char *ret;

	fd = open(filename,O_RDONLY);
	if (fd <= 0)
	{
		printf("ERROR can't open file\n");
		exit(1);
	}
	ret = get_next_line(fd);
	while (ret != NULL)
	{
		check_arg(ret, v);
		ret = get_next_line(fd);
	}
	return (NULL);
}
