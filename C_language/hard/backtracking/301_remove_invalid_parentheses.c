
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAKE 1
#define NO 0


typedef struct s_par{

	int	rm_open;
	int	rm_close;
	
} t_par;

typedef struct s_array {

	char**	result;
	char*	s;
	int	i_of_solution;
	int	size_of_malloc;
	int	len_of_s;
	int	len_of_result;

} t_array;

void	print_solution(char *s, int solution[])
{
	int	i = 0;
	printf("[ ");
	while (i < strlen(s))
	{
		if (solution[i] == TAKE)
			printf("%c", s[i]);
		i++;
	}
	printf(" ]\n");

}

int	ft_nb_of_useless_par(char *s, t_par *par)
{
	int	i = 0;

	par->rm_open = 0;
	par->rm_close = 0;
	while (s[i])
	{
		if (s[i] == '(')
			par->rm_open++;
		else if (s[i] == ')')
		{
			if (par->rm_open > 0)
				par->rm_open--;
			else
				par->rm_close++;
		}
		i++;
	}
	return (0);
}

int	malloc_place(t_array *array)
{
	if (array->i_of_solution == 0)
	{
		array->result = calloc(2, sizeof(char *));
		if (!array->result)
			return -1;
		array->size_of_malloc = 2 * sizeof(char *);
		array->result[array->i_of_solution] = calloc(array->len_of_result, sizeof(char));
		if (!array->result[array->i_of_solution])
			return -1;
		array->result[array->i_of_solution + 1] = NULL;
	}
	else
	{
		array->result = realloc(array->result, array->size_of_malloc + sizeof(char *));
		if (!array->result)
			return -1;
		array->size_of_malloc += sizeof(char *);
		array->result[array->i_of_solution] = calloc(array->len_of_result, sizeof(char));
		if (!array->result[array->i_of_solution])
			return -1;
		array->result[array->i_of_solution + 1] = NULL;
	}
	return 0;
}

void	check_duplicates(t_array *array)
{
	int	i = 0;

	while (i < array->i_of_solution && array->result[i])
	{
		if (strcmp(array->result[i], array->result[array->i_of_solution]) == 0)
		{
			free(array->result[array->i_of_solution]);
			array->result[array->i_of_solution] = NULL;
			if (array->i_of_solution > 0)
				array->i_of_solution--;
			array->result = realloc(array->result, array->size_of_malloc - sizeof(char *));
			return ;
		}
		i++;
	}
}

void	save_solution(t_array *array, int solution[])
{
	int	i = 0;
	int	j = 0;


	if (malloc_place(array) == -1)
		return ;
	while (j < array->len_of_s)
	{
		if (solution[j] == TAKE)
		{
			array->result[array->i_of_solution][i] = array->s[j]; 
			i++;
		}
		j++;
	}
	array->result[array->i_of_solution][i] = '\0';
	check_duplicates(array);
}

void	get_solution(t_array *array, int index, int solution[], int open, int rm_o, int rm_cl)
{
	if (index == array->len_of_s) //end, printing the result
	{
		if (open == 0 && rm_o == 0 && rm_cl== 0)
		{
			array->i_of_solution++;
			save_solution(array, solution);
		}
		return ;
	}


	if (array->s[index] != '(' && array->s[index] != ')') //for other symbols always print
	{
		solution[index] = TAKE;
		get_solution(array, index+1, solution, open, rm_o, rm_cl);
		return ;
	}


	else if (array->s[index] == '(') //open parenthese
	{
		if (rm_o > 0) //need to remove any open 
		{
			solution[index] = NO;
			get_solution(array, index+1, solution, open, rm_o-1, rm_cl);
		}
		solution[index] = TAKE;
		get_solution(array, index+1, solution, open+1, rm_o, rm_cl);
	}
	else if (array->s[index] == ')') //close parenthese
	{
		if (open > 0)
		{
			solution[index] = TAKE;
			get_solution(array, index+1, solution, open-1, rm_o, rm_cl);
		}
		if (rm_cl > 0)
		{
			solution[index] = NO;
			get_solution(array, index+1, solution, open, rm_o, rm_cl-1);
		}
	}
}

char**	removeInvalidParentheses(char* s, int* returnSize)
{
	t_par		par;
	t_array		array;
	int		*solution;
	int		index = 0;
	int		open = 0;

	array.result = NULL;
	array.s = s;
	array.size_of_malloc = 0;
	array.len_of_s = strlen(s);
	array.i_of_solution = -1;

	solution = calloc(array.len_of_s, sizeof(int));
	if (!solution)
		return (NULL);
	ft_nb_of_useless_par(s, &par);
	array.len_of_result = array.len_of_s - (par.rm_close + par.rm_open) + 1;
	get_solution(&array, index, solution, open, par.rm_open, par.rm_close);
	
	*returnSize = array.i_of_solution+1;	
	free(solution);
	return(array.result);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	int	size = 0;
	char**	res = removeInvalidParentheses(av[1], &size);
	int i = 0;
	while (res[i])
	{
		printf("%s\n", res[i]);
		free(res[i]);
		i++;
	}
	free(res);
}


/*
 Using backtracking with recursion
 ---------------------------------

	1. Count the number of invalid open and close paretheses
	2. Parsing the string character by character and deciding to keep it or no or both
	 
	'(' →→→→→ always TAKE (then recursion with open+1)
	↓ 
	↓
	↓
	NO only if need_to_rm_open > 0 
	(then recursion with 
		need_to_rm_open-1)
	 
					')'→→→→→ TAKE only if open > 0 (then recursion with open-1)
					↓
					↓
					↓
					NO only if need_to_rm_close > 0 (then recursion with 
						need_to_rm_close-1)

	3. Put every solution to array char** checking the doublicates
*/
