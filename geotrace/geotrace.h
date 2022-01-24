//
// Created by tkondrac on 22.01.22.
//

#ifndef GEOTRACE_H
# define GEOTRACE_H

//Structs

/// mathematical vector
/// \param x coord
/// \param y coord
/// \param z coord
typedef struct s_vec3d
{
	double	x;
	double	y;
	double	z;
}	t_vec3d;

/// line (or ray) along direction and passing through a point.
/// \param direction
/// \param point
typedef struct s_line
{
	t_vec3d	direction;
	t_vec3d point;
}	t_line;

/// plane defined by normal vector and a point.
/// \param direction
/// \param point
typedef struct s_plane
{
	t_vec3d	normal;
	t_vec3d point;
}	t_plane;

/// 3d Sphere
/// \param center
/// \param radius
typedef struct s_sphere
{
	t_vec3d	center;
	double	radius;
}	t_sphere;

//Vector funcs

t_vec3d	*scalar_mult(t_vec3d v, double a);

double	dot_prod(t_vec3d v, t_vec3d u);

t_vec3d	*vec_prod(t_vec3d v, t_vec3d u);

double	vec_norm(t_vec3d v);

t_vec3d	*unit_vector(t_vec3d v);

void	scalar_mult2(t_vec3d v, double a, t_vec3d *new);

void	vec_prod2(t_vec3d v, t_vec3d u, t_vec3d *new);

void	unit_vector2(t_vec3d v, t_vec3d *new);

t_vec3d	*init_vec(double x, double y, double z);

void	set_vec(t_vec3d *v, double x, double y, double z);

void	vec_sum(t_vec3d v, t_vec3d u, t_vec3d *new);

void	vec_subtract(t_vec3d v, t_vec3d u, t_vec3d *new);

//Sphere funcs

t_sphere	*init_sphere(double radius, double cx, double cy, double cz);

double	sphere_intersect(t_sphere *sphere, t_line ray);

//Line funcs

t_line	*init_line(t_vec3d dir, t_vec3d p);

//plane funcs

t_plane	*init_plane(t_vec3d normal, t_vec3d p);

double	plane_intersect(t_plane *plane, t_line ray);

#endif //GEOTRACE_H
