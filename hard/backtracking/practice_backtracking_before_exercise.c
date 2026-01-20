/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_possibilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 13:46:47 by yukravch          #+#    #+#             */
/*   Updated: 2026/01/20 13:46:47 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#define OUI 1
#define NON 0

void print_tab(int tab[], int tab_size)
{
	for (int i = 0; i < tab_size; i++)
                printf("%d ", tab[i]);

	printf("\n");
}


void	print_solution(int tab[], int solution[], int size)
{
	int	i = 0;


	printf("[");
	while (i < size)
	{
		if (solution[i] == OUI)
                	printf("%d", tab[i]);
		i++;
	}
	printf("]\n");
}

void go_deeper(int index, int size, int set[], int solution[])
{
	if (index >= size)
	{
		print_solution(set, solution, size);
		return;
	}

	solution[index] = NON;
	go_deeper(index + 1, size, set, solution);

	solution[index] = OUI;
	go_deeper(index + 1, size, set, solution);
}

int main(int argc, char** argv)
{
	int  set_size = argc - 1;
	int* set = malloc(sizeof(int) * set_size);
	int* solution = malloc(sizeof(int) * set_size);

	for (int i = 1; i < argc; i++)
		set[i - 1] = atoi(argv[i]);


	print_tab(set, set_size);

	go_deeper(0, set_size, set, solution);
}
