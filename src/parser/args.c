#include "mrt.h"
#include "geotrace.h"
#include "gnl/get_next_line.h"
#include "minirt.h"

#include "debug/debug.h"

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
	return (1);
}

int	check_arg(char *arg, t_list **objects)
{
	void	*mem;
	long unsigned int color;

	if (arg[0] == '\n')
		return (1);
	else if (arg[0] == 's')
		mem = (check_sphere(arg, &color));
	else if (arg[0] == 'p')
		mem = (check_plane(arg, &color));
	else
		return (1);
	printf("%lX\n",color);
	ft_lstadd_front(objects,ft_lstnew(init_obj(arg[0],mem,color)));
	return (1);
}
char *get_arg(char *filename)
{
	int fd;
	char *ret;
	t_list	*objects = NULL;

	fd = open(filename,O_RDONLY);
	if (fd <= 0)
	{
		printf("ERROR can't open file\n");
		exit(1);
	}
	ret = get_next_line(fd);
	while (ret != NULL)
	{
		check_arg(ret, &objects);
		ret = get_next_line(fd);
	}
	print_objlst(objects);
	launch_window(&objects);
	ft_lstclear(&objects, (void (*)(void *))destroy_obj);
	return (NULL);
}
