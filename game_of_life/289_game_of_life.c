/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   289_game_of_life.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yukravch <yukravch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:52:21 by yukravch          #+#    #+#             */
/*   Updated: 2025/12/10 18:11:43 by yukravch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdlib.h> 

void	free_board(int** board);

int**	calloc_next_generation(int boardSize, int* boardColSize) {

	int**	next_generation = calloc(boardSize, sizeof(int*));
	if (!next_generation) {  return NULL;  }
	
	for (int i = 0; i < boardSize; i++) {
		for(int j = 0; j < boardColSize[i]; j++) {
			next_generation[i] = calloc(boardColSize[i], sizeof(int));
			if (!next_generation[i]) {  free(next_generation); return NULL;  }
		}
	}
	return next_generation;
}

int	get_live_neighbors(int** board, int row, int col, int boardSize, int* boardColSize) {

	int count = 0;

	if (row != 0 && board[row-1][col] == 1) //above
		count++;
	if (row != 0 && col != 0 && board[row-1][col-1] == 1) //above-left
		count++;
	if (col != 0 && board[row][col-1] == 1) //left
		count++;
	if (col != 0 && row < boardSize-1 && board[row+1][col-1] == 1) //below-left
		count++;
	if (row < boardSize-1 && board[row+1][col] == 1) //below
		count++;
	if (row < boardSize-1 && col+1 < boardColSize[row+1] && board[row+1][col+1] == 1) //below-right
		count++;
	if (col+1 < boardColSize[row] && board[row][col+1] == 1) //right
		count++;
	if (row != 0 && col+1 < boardColSize[row-1] && board[row-1][col+1] == 1) //above-right
		count++;
	return count;
}

void	next_gen_for_dead_cell(int** next_generation, int i, int j, int count_live_neighbors) {

	if (count_live_neighbors == 3)
		next_generation[i][j] = 1;
	else
		next_generation[i][j] = 0;
}

void	next_gen_for_alive_cell(int ** next_generation, int i, int j, int count_live_neighbors) {

	if (count_live_neighbors < 2)
		next_generation[i][j] = 0;
	else if (count_live_neighbors == 2 || count_live_neighbors == 3)
		next_generation[i][j] = 1;
	else if (count_live_neighbors > 3)
		next_generation[i][j] = 0;
}

void	rewrite_generation(int** board, int** next_generation, int boardSize, int* boardColSize) {

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardColSize[i]; j++) {
			board[i][j] = next_generation[i][j];
		}
	}
}

void gameOfLife(int** board, int boardSize, int* boardColSize) {
 
	int**	next_generation = calloc_next_generation(boardSize, boardColSize);

	int	count_live_neighbors = 0;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardColSize[i]; j++) {

			count_live_neighbors = get_live_neighbors(board, i, j, boardSize, boardColSize);
			if (board[i][j] == 0)
				next_gen_for_dead_cell(next_generation, i, j, count_live_neighbors);
			else if (board[i][j] == 1)
				next_gen_for_alive_cell(next_generation, i, j, count_live_neighbors);
		}
	}
	rewrite_generation(board, next_generation, boardSize, boardColSize);
	free_board(next_generation);
}

void	free_board(int** board) {

	for (int i = 0; i < 4; i++) {  free(board[i]);  }
	free(board);
}

//
//TEST
//

void	printBoard(int** board) {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {  printf("%d", board[i][j]);  }
		printf("\n");
	}
}

int	main() {

	/*
	 board is:
	 
		010
		001
		111
		000
	 
	 */
	int**	board = calloc(4, sizeof(int*));
	if (!board) {  return 1;  }

	for (int i = 0; i < 4; i++) {
		board[i] = calloc(3, sizeof(int));
		if (!board[i]) {  free(board); return 1;  }
	}
	
	int	to_copy[12] = {0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0};

	int k = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = to_copy[k];
			k++;
		}
	}

	int*	boardColSize = calloc(4, sizeof(int));
	if (!boardColSize) {  free_board(board); return 1;  }

	for (int i = 0; i < 4; i++) {  boardColSize[i] = 3;  }


	gameOfLife(board, 4, boardColSize);
	
	printBoard(board);
	free(boardColSize);
	free_board(board);

	return 0;
}
