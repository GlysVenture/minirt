#include <unistd.h>
#include "../incs/minirt.h"

float ft_atof(char *arr){
    int i,j,flag;
    float val;
    i=0;
    j=0;
    val=0;
    flag=0;
    while (arr[i] !='\0')
    {
        if (arr[i] !='.')
	{
            val =(val*10)+ (arr[i] - '0');
            if (flag == 1)
                --j;
        }
        if (arr[i] == '.')
	{ 
		if (flag == 1) 
			return 0; 
		flag=1;
	}
        ++i;
    }
    val = val*pow(10,j);
    return (val);
}

int check_light_color(char *color, t_alight *a)
{
	char **nbrs;
	int i;

	i = 0;
	nbrs = ft_split(color, ',');
	while (nbrs[i])
	{
		if (i == 3)
			return (1);
		a->colors[i] = ft_atoi(nbrs[i]);
		if (a->colors[i] > 255 || a->colors[i] < 0)
			return (1);
		i++;
	}
	if (i != 3)
		return (1);
	return (0);
}

int check_light(char *arg)
{
	char **args;
	t_alight a;
 
	args = ft_split(arg, ' ');
	a.ratio = ft_atof(args[1]);
	if (a.ratio >= 1.0 || a.ratio <= 0.0)
	{
		printf("Error not in the correct range\n");
			exit (1);
	}
	if (check_light_color(args[2], &a))
	{
		printf("ERROR COLOR\n");
		exit (1);
	}
	return (0);
}

int check_arg(char *arg)
{
	if (arg[0] == '\n')
		return (1);
	else if (arg[0] == 'A')
		return (check_light(arg));
//	else if (arg[0] == 'C')
//		return (check_cam(arg));
	return (0);
}
char *get_arg(char *filename)
{
	int fd;
	char *ret;
	fd = open(filename,O_RDONLY);
	if (fd <= 0)
	{
		printf("ERROR can't open file\n");
		exit(1);
	}
	else
	{
		ret = get_next_line(fd);
		check_arg(ret);
	}
	return (ret);
}
int main(int ac, char *av[])
{
	char *info;
	if (ac == 1)
	{
		printf("ERROR\n Needs a .rt file as argument\n");
		return (1);
	}
	else
		info = get_arg(av[1]);
	return (0);
}
