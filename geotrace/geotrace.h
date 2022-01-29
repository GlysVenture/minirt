//
// Created by tkondrac on 22.01.22.
//

#ifndef GEOTRACE_H
# define GEOTRACE_H

//Structs

/// mathematical vector
/// \param xyz coordinates
typedef double	t_vec3d[3];

/// 3x3 matrix
/// \param i line
/// \param j column
typedef double	t_matrix[3][3];

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

double	*scalar_mult(const t_vec3d v, double a, t_vec3d w);

double	dot_prod(const t_vec3d v, const t_vec3d u);

double	*vec_prod(const t_vec3d v, const t_vec3d u, t_vec3d w);

double	vec_norm(const t_vec3d v);

double	*unit_vector(t_vec3d v, t_vec3d unit);

double	*set_vec(t_vec3d v, double x, double y, double z);

double	*set_vec2(t_vec3d v, const t_vec3d u);

double	*vec_sum(const t_vec3d v, const t_vec3d u, t_vec3d new);

double	*vec_subtract(const t_vec3d v, const t_vec3d u, t_vec3d new);

double	get_angle(const t_vec3d v, const t_vec3d u);

//Matrix funcs

double	**set_matrix(t_matrix a, const t_vec3d x, const t_vec3d y, const t_vec3d z);

double	**matrix_transpose(const t_matrix a, t_matrix b);

double	*matrix_vect_prod(const t_matrix a, const t_vec3d v, t_vec3d u);

double	**matrix_prod(t_matrix a, t_matrix b, t_matrix c);

double	**matrix_scalar_mult(const t_matrix a, double scalar, t_matrix b);

double	matrix_determinant(const t_matrix a);

double	**inverse_matrix(t_matrix a, t_matrix b);

double	**cofactor_matrix(const t_matrix a, t_matrix c);

void	print_matrix(const t_matrix a);

//Sphere funcs

t_sphere	*init_sphere(double radius, double cx, double cy, double cz);

double	sphere_intersect(t_sphere *sphere, t_line ray);

//Line funcs

t_line	*init_line(const t_vec3d dir, const t_vec3d p);

//plane funcs

t_plane	*init_plane(t_vec3d normal, t_vec3d p);

double	plane_intersect(t_plane *plane, t_line ray);

#endif //GEOTRACE_H
