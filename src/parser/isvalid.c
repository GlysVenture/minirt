#include "mrt.h"

int	nbrargs(char **args, int nbr)
{
	int	i;

	i = 0;
	if (args == NULL)
		return (0);
	while (args[i] != NULL)
		i++;
	if (i != nbr)
	{
		printf("Error,wrong number of arguments ");
		printf("have %i expected %i",i,nbr);
		return (0);
	}
	return (1);
}
void	*error(char *mess,char **tf[2])
{
	int i;

	i = 0;
	write(2,mess,ft_strlen(mess));
	write(2,"\n",1);
	while (i != 2)
	{	
		if (tf[i] != NULL)
			free_tab(tf[i]);
		i++;
	}
	return (NULL);
}
int	inrange(t_vec3d v,double min, double max)
{
	int	i;

	i = 0;
	while (i != 3)
	{
		if (isless(v[i],min) || isgreater(v[i],max))
			return (0);
		i++;
	}
	return (1);
}
