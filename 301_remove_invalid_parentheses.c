
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAKE 1
#define NO 0


typedef struct s_par{

	int	rm_open;
	int	rm_close;
	
} t_par;

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



void	get_solution(char *s, int index, int solution[], int open, int rm_o, int rm_cl, int len)
{
	if (index == len) //end, printing the result
	{
		if (open == 0 && rm_o == 0 && rm_cl== 0)
			print_solution(s, solution);
		return ;
	}


	if (s[index] != '(' && s[index] != ')') //for other symbols always print
	{
		solution[index] = TAKE;
		get_solution(s, index+1, solution, open, rm_o, rm_cl, len);
		return ;
	}


	else if (s[index] == '(') //open parenthese
	{
		if (rm_o > 0) //need to remove any open 
		{
			solution[index] = NO;
			get_solution(s, index+1, solution, open, rm_o-1, rm_cl, len);
		}
		solution[index] = TAKE;
		get_solution(s, index+1, solution, open+1, rm_o, rm_cl, len);

	}
	else if (s[index] == ')') //close parenthese
	{
		if (open > 0)
		{
			solution[index] = TAKE;
			get_solution(s, index+1, solution, open-1, rm_o, rm_cl, len);
		}
		if (rm_cl > 0)
		{
			solution[index] = NO;
			get_solution(s, index+1, solution, open, rm_o, rm_cl-1, len);
		}
	}
}

void	removeInvalidParentheses(char* s)
{
	t_par	par;
	int	*solution;
	int	index = 0;
	int	open = 0;
	int	len = strlen(s);

	solution = calloc(1000, sizeof(int));
	ft_nb_of_useless_par(s, &par);

	get_solution(s, index, solution, open, par.rm_open, par.rm_close, len);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	
	removeInvalidParentheses(av[1]);
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
