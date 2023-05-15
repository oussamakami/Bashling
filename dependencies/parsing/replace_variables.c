#include "parsing.h"

int	variable_count(char *str)
{
	int count;
	int	dquotes;
	int	squotes;

	count = 0;
	dquotes = 0;
	squotes = 0;
	while (str[0])
	{
		while (str[0] && (!(str[0] == '$') || (squotes & 1)))
		{
			dquotes += (!(squotes & 1) && str[0] == '"');
			squotes += (!(dquotes & 1) && str[0] == '\'');
			str++;
		}
		if (str[0])
		{
			count++;
			str++;
		}
	}
	return (count);
}
