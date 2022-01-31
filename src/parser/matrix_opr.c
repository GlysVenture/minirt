#include "mrt.h"
#include "parse.h"
#include "minirt.h"
void	sheer_xy(t_matrix a, double l)
{
	t_matrix b;
	
	ft_memset(b,0,sizeof(t_matrix));
	b[0][0] = 1;
	b[0][1] = l;
	b[1][1] = 1;
	b[2][2] = 1;
	matrix_prod(a,b,a);
}

void	sheer_yx(t_matrix a, double l)
{
	t_matrix	b;

	ft_memset(b,0,sizeof(t_matrix));
	b[0][0] = 1;
	b[1][0] = l;
	b[1][1] = 1;
	b[2][2] = 1;
	matrix_prod(a,b,a);
}

void	sheer_xz(t_matrix a, double l)
{
	t_matrix	b;

	ft_memset(b,0,sizeof(t_matrix));
	b[0][0] = 1;
	b[1][1] = 1;
	b[0][2] = l;
	b[2][2] = 1;
	matrix_prod(a,b,a);
}
void	sheer_zx(t_matrix a, double l)
{
	t_matrix	b;

	ft_memset(b,0,sizeof(t_matrix));
	b[0][0] = 1;
	b[2][0] = l;
	b[1][1] = 1;
	b[2][2] = 1;
	matrix_prod(a,b,a);
}
void	sheer_zy(t_matrix a, double l)
{
	t_matrix	b;

	ft_memset(b,0,sizeof(t_matrix));
	b[0][0] = 1;
	b[1][1] = 1;
	b[2][2] = 1;
	b[2][1] = l;
	matrix_prod(a,b,a);
}
void	sheer_yz(t_matrix a, double l)
{
	t_matrix	b;

	ft_memset(b,0,sizeof(t_matrix));
	b[0][0] = 1;
	b[1][1] = 1;
	b[2][2] = 1;
	b[1][2] = l;
	matrix_prod(a,b,a);
}
void	rotate_x(t_matrix m, double a)
{
	t_matrix	b;
	
	ft_memset(b,0,sizeof(t_matrix));
	b[0][0] = 1;
	b[1][1] = cos(a);
	b[1][2] = (sin(a) * -1);
	b[2][1] = sin(a);
	b[2][2] = cos(a);
	matrix_prod(m,b,m);
}
void	rotate_y(t_matrix m, double a)
{
	t_matrix	b;
	
	ft_memset(b,0,sizeof(t_matrix));
	b[0][0] = cos(a);
	b[0][2] = sin(a);
	b[1][1] = 1;
	b[2][0] = (sin(a) * -1);
	b[2][2] = cos(a);
	matrix_prod(m,b,m);
}

void	rotate_z(t_matrix m, double a)
{
	t_matrix	b;

	ft_memset(b,0,sizeof(t_matrix));
	b[0][0] = cos(a);
	b[0][1] = (sin(a) * -1);
	b[1][0] = sin(a);
	b[1][1] = cos(a);
	b[2][2] = 1;
	matrix_prod(m,b,m);
}
void	aggr_x(t_matrix m, double a)
{
	t_matrix	b;

	ft_memset(b,0,sizeof(t_matrix));
	b[1][1] = 1;
	b[2][2] = 1;
	b[0][0] = a;
	b[0][1] = a;
	b[0][2] = a;
	matrix_prod(m,b,m);
}
void	aggr_y(t_matrix m, double a)
{
	t_matrix	b;

	ft_memset(b,0,sizeof(t_matrix));
	b[0][0] = 1;
	b[1][0] = a;
	b[1][1] = a;
	b[1][2] = a;
	b[2][2] = 1;
	matrix_prod(m,b,m);
}
void	aggr_z(t_matrix m, double a)
{
	t_matrix	b;

	ft_memset(b,0,sizeof(t_matrix));
	b[0][0] = 1;
	b[1][1] = 1;
	b[2][0] = a;
	b[2][1] = a;
	b[2][2] = a;
	matrix_prod(m,b,m);
}
void	ft_sheer(char *dir,t_matrix m, double l)
{
	if (!ft_strncmp(dir, "xy", 3))
		sheer_xy(m,l);
	else if (!ft_strncmp(dir,"xz",3))
		sheer_xz(m,l);
	else if (!ft_strncmp(dir,"yz",3))
		sheer_yz(m,l);
	else if (!ft_strncmp(dir,"yx",3))
		sheer_yx(m,l);
	else if (!ft_strncmp(dir,"zx",3))
		sheer_zx(m,l);
	else if (!ft_strncmp(dir,"zy",3))
		sheer_zy(m,l);
}
void	ft_rotate(char dir,t_matrix m, double l)
{
	if (dir == 'x')
		rotate_x(m,l);
	else if (dir == 'y')
		rotate_y(m,l);
	else if (dir == 'z')
		rotate_z(m,l);
}

void	ft_aggr(char dir, t_matrix m, double l)
{
	if (dir == 'x')
		aggr_x(m,l);
	else if (dir == 'y')
		aggr_y(m,l);
	else if (dir == 'z')
		aggr_z(m,l);
}
