#include "data.h"


void add_part(Part next_part){

        snake.parts = realloc(snake.parts, (1 + tail_len) *sizeof(Part));
        Part part = {next_part.row - next_part.curr_row_vector, next_part.col - next_part.curr_col_vector, &next_part, next_part.last_row_vector, next_part.last_col_vector, next_part.last_row_vector, next_part.last_col_vector};

        snake.parts[tail_len++] = part;
}

void spawn_random_fruit(){
	int row_offset = (rand() % 19) + 1;
	int col_offset = (rand() % 19) + 1;		
	f.row = t.window_row/2 + row_offset;
	f.col = t.window_col/2 + col_offset;
}


void add_coords_to_array(int row, int col){

	static int curr = 0;

	if(!grid_coordinates[curr]){
		grid_coordinates[curr] = malloc(2);
		grid_coordinates[curr][0] = row;
		grid_coordinates[curr][1] = col;
		curr++;
	}	
}

bool snake_biting_tail(){
	for(int i = 1; i<tail_len; i++){
		if(snake.parts[0].row == snake.parts[i].row && snake.parts[0].col == snake.parts[i].col){
			return true;
		}

	}
	return false;

}

void increment_score(){
	score += 50;
}

bool snake_is_in_grid(){
	for(int i = 0; i<80; i++){
		if(snake.parts[0].row == grid_coordinates[i][0] && snake.parts[0].col == grid_coordinates[i][1])
			return true;
	}
	return false;
}


bool snake_eats_fruit(){
	return snake.parts[0].row == f.row && snake.parts[0].col == f.col;
}
