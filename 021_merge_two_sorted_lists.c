#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListNode {

	int		val;
	struct ListNode *next;

} t_list;



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

t_list* mergeTwoLists(t_list* list1, t_list* list2)
{
	ft_print_lst(list1);
	ft_print_lst(list2);

	return NULL;
}

int	main(int ac, char** av)
{
	int	i = 0;
	t_list*	l1 = NULL;
	t_list*	l2 = NULL;

	t_list* new = ft_lstnew(4);
	ft_lst_addback(&l1, new);
	new = ft_lstnew(6);
	ft_lst_addback(&l1, new);
	new = ft_lstnew(10);
	ft_lst_addback(&l1, new);
	

	new = ft_lstnew(1);
	ft_lst_addback(&l2, new);
	new = ft_lstnew(2);
	ft_lst_addback(&l2, new);
	new = ft_lstnew(3);
	ft_lst_addback(&l2, new);


	mergeTwoLists(l1, l2);
}
