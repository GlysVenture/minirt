//
// Created by tkondrac on 27.01.22.
//

#include <stdlib.h>
#include <stdio.h>

int	free_tab(char **tab)
{
	char **s;
	if (tab == NULL)
		return (0);
	s = tab;
	while (*s)
		free(*(s++));
	free(tab);
	tab = NULL;
	return (0);
}
