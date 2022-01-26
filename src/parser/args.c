#include "mrt.h"
#include "geotrace.h"
#include "gnl/get_next_line.h"
#include "minirt.h"

#include "debug/debug.h"
long unsigned int  hexcolor(char *line);

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

t_alight check_light(char *arg)
{
	char **args;
	t_alight a;

	args = ft_split(arg, ' ');
	a.ratio = ft_atod(args[1]);
	if (a.ratio >= 1.0 || a.ratio <= 0.0)
	{
		printf("Error not in the correct range\n");
			exit (1);
	}
	a.color = hexcolor(args[2]);
	return (a);
}

int	check_arg(char *arg, t_list **objects)
{
	void	*mem;
	long unsigned int color;
	t_list *debug;
	t_alight al;

	if (arg[0] == '\n')
		return (1);
	else if (arg[0] == 'A')
	{
		al = check_light(arg);
		return (1);
	}
	else if (arg[0] == 's')
		mem = (check_sphere(arg, &color));
	else if (arg[0] == 'p')
		mem = (check_plane(arg, &color));
	else
		return (1);
	printf("color 0x%lX\n",color);
	debug = ft_lstnew(init_obj(arg[0],mem,color));
	ft_lstadd_front(objects,debug);
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
