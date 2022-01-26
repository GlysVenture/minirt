#include "mrt.h"
#include "geotrace.h"
#include "gnl/get_next_line.h"
#include "minirt.h"
#include "parse.h"

#include "debug/debug.h"
int  hexcolor(char *line);

double ft_atod(char *arr){
    int i,j,flag;
    double val;
    i=0;
    j=0;
    val=0;
    flag=0;
    while (arr[i] !='\0')
    {
        if (arr[i] !='.')
	{
            val =(val*10) + (arr[i] - '0');
            if (flag == 1)
                --j;
        }
        if (arr[i] == '.')
	{ 
		if (flag == 1) 
			return 0; 
		flag=1;
	}
        i++;
    }
    val = val*pow(10,j);
    return (atof(arr)); //todo ??????????????????
}

t_amb_light check_alight(char *arg)
{
	char **args;
	t_amb_light a;

	args = ft_split(arg, ' ');
	a.ratio = ft_atod(args[1]);
	if (a.ratio >= 1.0 || a.ratio <= 0.0)
	{
		printf("Error not in the correct range\n");
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
