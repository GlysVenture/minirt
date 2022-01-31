#include "mrt.h"
#include "geotrace.h"
#include "gnl/get_next_line.h"
#include "minirt.h"
#include "parse.h"

//#include "debug/debug.h"
int  hexcolor(char *line);

double below_zero(double val,const char *str, char sign)
{
	int j;

	j = 0;
	while (str[j] <= '9' && str[j] >= '0')
	{
		val *= 10;
		val += str[j] - 48;
		if (ft_isdigit(str[j]) == 0)
			break;
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
    if (arr[0] == '0' && arr[1] != '.')
	    return (0.0);
    if (arr[0] == '+' || arr[0] == '-')
	    i++;
    while (arr[i] != '\0')
    {
	if (ft_isdigit(arr[i]) == 0 && arr[i] != '.')
		break;
        else if (arr[i] != '.') // je gere cela comme un atoi en gros, je regarde que je suis sur un chiffre et pas sur un point, et si je suis sur un point j'appele une autre fonction qui s'occupe de faire la puissance sinon c'est trop long pour la norminette
            val = (val*10) + (arr[i] - 48);
	else
		return (val = below_zero(val, arr + (i + 1), arr[0]));
        i++;
    }
    if (arr[0] == '-')
	    val *= -1;
    return (val);
}
/*int check_alight(char *arg, t_amb_light *a)
{
	char **args;

	args = ft_split(arg, ' ');
	a->ratio = ft_atod(args[1]);
	if (a->ratio >= 1.0 || a->ratio <= 0.0)
	{
		printf("Error not in the correct range\n");
			return (0); //todo err return
	}
	a->color = hexcolor(args[2]);
	free_tab(args);
	return (1);
}

int	check_arg(char *arg, t_vars *v)
{
	if (arg[0] == '\n')
		return (1);
	else if (arg[0] == 'A')
	{
		if (check_alight(arg, &v->ambient) == 0)
			return (0);
		return (1);
	}
	else if (arg[0] == 'L')
		return (parse_light(arg, v));
	else if (arg[0] == 's')
		return (parse_sphere(arg, v));
	else if (arg[0] == 'p')
		return (parse_plane(arg, v));
	else if (arg[0] == 'c')
		return (parse_cylinder(arg, v));
	return (1);
}
int	get_arg(char *filename, t_vars *v)
{
	int fd;
	char *ret;

	fd = open(filename,O_RDONLY);
	if (fd <= 0)
	{
		printf("ERROR can't open file\n");
		return (0);
	}
	ret = get_next_line(fd);
	while (ret != NULL)
	{
		if (check_arg(ret, v) == 0)
			return (0);
		free(ret);
		ret = get_next_line(fd);
	}
	return (1);
} */
