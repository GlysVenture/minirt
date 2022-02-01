//
// Created by tkondrac on 27.01.22.
//

#include <stdlib.h>
#include <stdio.h>

int	free_tab(char **tab)
{
	char **s;

	s = tab;
	while (*s)
		free(*(s++));
	free(tab);
	return (0);
}
