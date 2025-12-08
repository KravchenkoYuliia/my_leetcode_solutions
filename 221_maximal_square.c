/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   221_maximal_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 13:46:52 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/08 16:48:14 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
int	ft_min(int a, int b, int c) {

	int min = a;

	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return min;
}


int	maximalSquare(char** matrix, int matrixSize, int* matrixColSize) {

	int**	dp = calloc(matrixSize, sizeof(int*));

	for (int i = 0; i < matrixSize; i++) {
	
		dp[i] = calloc(matrixColSize[i], sizeof(int));
	}

	if (!matrix)
		return 0;
	int	rows = 0;
	int	cols = 0;
	int	biggest_square = 0;
	while (rows < matrixSize) {

		cols = 0;
		while (cols < matrixColSize[rows]){
	
			if (matrix[rows][cols] == '0')
				dp[rows][cols] = 0;
			else if (rows == 0 || cols == 0) {
				dp[rows][cols] = 1;
				if (dp[rows][cols] > biggest_square)
					biggest_square = dp[rows][cols];
			}
			else {
				dp[rows][cols] = ft_min(dp[rows-1][cols], dp[rows][cols-1], dp[rows-1][cols-1]) + 1;
				if (dp[rows][cols] > biggest_square)
					biggest_square = dp[rows][cols];
			}
			cols++;
		}
		rows++;
	}
	
	for (int i = 0; i < matrixSize; i++) {  free(dp[i]);  }
	free(dp);
	return biggest_square * biggest_square;
}


//
// TO TEST
//
/*
typedef	struct square_data{

	char**	matrix;
	int	nb_of_lines;
	int	nb_of_columns[100];

} t_square;


char*	strdup_till_newline(char* buffer) {

	int	size = strlen(buffer);
	
	if (buffer[size-1] != '\n')
		size += 1;
	char*	result = calloc(sizeof(char), size);
	if (!result)
		return NULL;

	int	i = 0;
	while (i < size && buffer[i] != '\n') {
		result[i] = buffer[i];
		i++;
	}
	result[i] = '\0';

	return result;
}

void	get_matrix(FILE* stream, t_square* square) {

	ssize_t	return_value = 0;
	char*	buffer = NULL;
	size_t	size = 0;
	int	i = 0;
	int	nb_of_line = 0;
	
	while (return_value != -1) {

		return_value = getline(&buffer, &size, stream);
		if (return_value == -1)
			break ;

		nb_of_line += 1;
		square->matrix = realloc(square->matrix, sizeof(char*) * (nb_of_line + 1));
		if (!square->matrix)
			return ;
		square->matrix[i] = strdup_till_newline(buffer);
		if (!square->matrix[i])
			return ;
		square->nb_of_columns[i] = strlen(square->matrix[i]);
		i++;
	}
	square->matrix[i] = NULL;
	square->nb_of_lines = i;
}


void	readFromStdin(t_square* square) {  get_matrix(stdin, square);  }

void	readFromFile(char* filename, t_square* square) {

	FILE*	stream = fopen(filename, "r");
	if (!stream)
		return ;

	get_matrix(stream, square);
	fclose(stream);
}

int	main(int ac, char** av) {

	if (ac > 2) {
		printf("./a.out <optional>map\n");
		return 1;
	}

	t_square	square;

	square.matrix = NULL;
	square.nb_of_lines = 0;

	for (int i = 0; i < 100; i++) {  square.nb_of_columns[i] = 0;  }


	if (ac == 1)
		readFromStdin(&square);
	else
		readFromFile(av[1], &square);
	if (!square.matrix)
		return 1;

	int	maximal_area = maximalSquare(square.matrix, square.nb_of_lines, square.nb_of_columns);
	for (int i = 0; square.matrix[i]; i++) {  free(square.matrix[i]);  }
	free(square.matrix);

	printf("Maximal area is %d\n", maximal_area);
	return 0;
}
*/

//
// TO VISUALIZE THE ARRAY / DEBUG
//
/*
void	print_dp(int** dp, int max_row, int max_col) {

	printf("dp: \n");
	for (int i = 0; i < max_row; i++) {

		printf("line[%d]: ", i);
		for (int j = 0; j < max_col; j++) {
			printf("[%d]", dp[i][j]);
		}
		printf("\n");
	}
}

void	print_matrix(t_square square) {


	for (int i = 0; square.matrix[i]; i++) {

		printf("line%d = [%s] has %d columns\n", i+1, square.matrix[i], square.nb_of_columns[i]);
	}
	printf("\nnb of lines[%d]\n", square.nb_of_lines);
}
*/
