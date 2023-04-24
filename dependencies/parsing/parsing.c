# include "parsing.h"

// t_cmd *parsing(char *input)
// {
// 	t_cmd	*result;
// 	char	**temp;
// 	int		index;

// 	temp = input_split(input);
// 	index = 0;
// 	result = NULL;
// 	while (temp[index])
// 	{
// 		result = append_cmd_to_tree(result, allocate_cmd_node(ft_strtrim(temp[index], " ")));
// 		free(temp[index++]);
// 	}
// 	free(temp);
// 	free(input);
// 	return result;
// }