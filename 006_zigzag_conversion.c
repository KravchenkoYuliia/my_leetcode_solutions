#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct s_data {

	char*	src;
	int	len;
	int	nb_of_rows;
	int	pattern_first_line;
	int	nb_of_middle_rows;
	int	start_of_middle_line;
	char*	result;
	int	i_result;

}	t_data;

void	ft_copy_last_line_of_zigzag(t_data* data)
{
	int	i = data->nb_of_rows - 1;
	int	pattern = data->nb_of_rows* 2 - 2;

	if (data->i_result >= data->len)
		return ;
	while (data->src[i])
	{
		data->result[data->i_result] = data->src[i];
		if (i + pattern  < data->len && data->src[i + pattern])
			i = i + pattern;
		else
		{
			data->i_result++;
			data->result[data->i_result] = '\0';
			return ;
		}
		data->i_result++;
	}

}

void	ft_copy_middle_lines_of_zigzag(t_data* data, int pattern_a, int pattern_b)
{
	int	i;
	int	line = 0;
	int	count_char_in_middle_line = 0;
	int	pattern = 0;

	if (data->i_result >= data->len)
		return ;
	while (line < data->nb_of_middle_rows)
	{
		i = 0;
		i = data->start_of_middle_line;
		count_char_in_middle_line = 0;
		while (i < data->len && data->src[i])
		{
			if (data->i_result >= data->len)
				return ;
			data->result[data->i_result] = data->src[i];
			if (count_char_in_middle_line % 2 == 0)
				pattern = pattern_a;
			else
				pattern = pattern_b;
			if (i + pattern < data->len && data->src[i + pattern])
				i = i + pattern;
			else
			{
				data->i_result++;
				data->result[data->i_result] = '\0';
				break ;
			}
			count_char_in_middle_line++;
			data->i_result++;
		}
		pattern_a -= 2;
		pattern_b += 2;
		data->start_of_middle_line++;
		line++;
	}
}

void	ft_copy_first_line_of_zigzag(t_data* data)
{
	int	i = 0;
	int	pattern = data->nb_of_rows* 2 - 2;

	data->pattern_first_line = pattern;
	while (data->src[i])
	{
		data->result[data->i_result] = data->src[i];
		if (pattern == 0)
			i++;
		else if (i + pattern  < data->len && data->src[i + pattern])
			i = i + pattern;
		else
		{
			data->i_result++;
			data->result[data->i_result] = '\0';
			return ;
		}
		if (data->i_result >= data->len - 1 && data->nb_of_rows <= i + 1)
		{
			data->result[data->i_result + 1] = '\0';
			return ;
		}
		data->i_result++;
	}
}

void	ft_convert_even_rows(t_data* data)
{
	ft_copy_first_line_of_zigzag(data);
	ft_copy_middle_lines_of_zigzag(data, data->nb_of_rows * 2 - 4, 2);
	ft_copy_last_line_of_zigzag(data);
}

void	ft_convert_odd_rows(t_data* data)
{
	ft_copy_first_line_of_zigzag(data);
	ft_copy_middle_lines_of_zigzag(data, data->pattern_first_line - 2, 2);
	ft_copy_last_line_of_zigzag(data);
}

char*	convert(char* s, int numRows)
{
	t_data	data;

	data.src = s;
	data.len = strlen(s);
	data.nb_of_rows = numRows;
	data.nb_of_middle_rows = data.nb_of_rows - 2;
	data.start_of_middle_line = 1;
	data.i_result = 0;
	data.result = calloc(data.len + 1, sizeof(char));
	if (!data.result)
		return NULL;
	
	if (data.nb_of_rows == 1)
	{
		strcpy(data.result, s);
		return data.result;
	}
	if (numRows % 2 == 0)
		ft_convert_even_rows(&data);
	else
		ft_convert_odd_rows(&data);
	
	return data.result;
}


/*
  give 2 parameters to the program
	1: string to convert
	2: number of rows in zigzag
 */

int	main(int ac, char** av)
{
	if (ac != 3)
		return 1;
	char* result = convert(av[1], atoi(av[2]));
	printf("%s\n", result);
	free(result);
}
