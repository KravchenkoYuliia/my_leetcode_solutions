#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode t_list;

typedef struct ListNode {

	int	val;
	t_list*	next;

} t_list;


t_list*	ft_addition(t_list* l1, t_list* l2, int remain, t_list* result)
{
	int	val1 = 0;
	int	val2 = 0;
	int	val_final = 0;

	if (!l1 && !l2 && !remain)
		return NULL;
	
	
	if (l1)
		val1 = l1->val;
	else
		val1 = 0;
	if (l2)
		val2 = l2->val;
	else
		val2 = 0;

	val_final = val1 + val2 + remain;
	remain = val_final / 10;

	if (l1)
	{
		l1->val = val_final % 10;
		result = l1;
	}
	else if (l2)
	{
		l2->val = val_final % 10;
		result = l2;
	}

	if (l1 && l2)
		result->next = ft_addition(l1->next, l2->next, remain, result->next);
	return result;
}

t_list* addTwoNumbers(t_list* l1, t_list* l2)
{
	int	remain = 0;
	t_list*	 result = NULL;

	result = ft_addition(l1, l2, remain, result);
	
	return result;
}

//testing

void	ft_print_list(t_list* list)
{
	t_list*	temp = list;

	printf("[");
	while (temp)
	{
		printf("%d", temp->val);
		if (temp->next)
			printf(" ");
		temp = temp->next;
	}
	printf("]\n");
}

t_list*	ft_lstnew(int content)
{
	t_list*	new = calloc(sizeof(t_list), 1);
	if (!new)
		return NULL;
	new->val = content;
	new->next = NULL;

	return new;
}

t_list*	ft_lstlast(t_list* list)
{
	t_list*	temp = list;

	if (!list)
		return NULL;
	while (temp && temp->next)
		temp = temp->next;
	return temp;
}

void	ft_lst_addback(t_list** list, t_list* new)
{
	t_list*	last = ft_lstlast(*list);
	if (!last)
		*list = new;
	else
		last->next = new;
}

int	main(int ac, char** av)
{
	int	i = 0;
	int	arg = 1;
	char	temp;

	t_list*	l1 = NULL;
	t_list*	l2 = NULL;
	t_list*	new = NULL;

	if (ac < 3)
		return 1;
	while (arg < 3)
	{
		i = 0;
		while (av[arg][i])
		{
			temp = av[arg][i+1];
			av[arg][i+1] = '\0';
			new = ft_lstnew(atoi(&av[arg][i]));
			if (arg == 1)
				ft_lst_addback(&l1, new);
			else if (arg == 2)
				ft_lst_addback(&l2, new);
			av[arg][i+1] = temp;
			i++;
		}
		arg++;
	}

	printf("input: \n");
	ft_print_list(l1);
	ft_print_list(l2);
	t_list* result = addTwoNumbers(l1, l2);

	printf("\nresult: \n");
	ft_print_list(result);
}
