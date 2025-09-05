#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//typedef struct ListNode t_list;

typedef struct ListNode {

	int		val;
	struct ListNode *next;

} t_list;

//solution
t_list* mergeTwoLists(t_list* list1, t_list* list2)
{
	if (!list1)
		return list2;
	if (!list2)
		return list1;
	while (list2)
	{
		if (list1->val < list2->val)
		{
			list1->next = mergeTwoLists(list1->next, list2);
			return list1;
		}
		else
		{
			list2->next = mergeTwoLists(list1, list2->next);
			return list2;
		}
	}
	return NULL;
}

//test
void	ft_print_lst(t_list* list)
{
	t_list*	temp = list;

	while (temp)
	{
		printf("%d ", temp->val);
		temp = temp->next;
	}
	printf("\n");
}

t_list*	ft_lstnew(int content)
{
	t_list*	new;

	new = calloc(sizeof(t_list), 1);
	if (!new)
		return NULL;
	new->val = content;
	new->next = NULL;
	return new;
}

t_list*	ft_lstlast(t_list* list)
{
	t_list	*temp;
       
	temp = list;

	while (temp && temp->next != NULL)
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



//format ./exec 123 456 only numbers less than 10 
//first list  1-2-3
//second list 4-5-6

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

	printf("before merge: \n");
	ft_print_lst(l1);
	ft_print_lst(l2);
	t_list* result = mergeTwoLists(l1, l2);

	printf("\nafter merge: \n");
	ft_print_lst(result);
}
