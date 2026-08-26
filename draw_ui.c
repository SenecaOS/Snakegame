#include "data.h"


void draw_char_at_coord(int row, int col, char c){

	char output[32];

	snprintf(output, sizeof(output), "\x1b[%d;%dH%c\x1b[?25l", row, col, c);
	write(STDOUT_FILENO, output, strlen(output));
}

void draw_fruit(){
                char fruit[32];
                draw_char_at_coord(f.row, f.col, '*');
}


void draw_snake(){

	int index = tail_len - 1;
	while(index >= 0){
		Part *curr = &snake.parts[index--];
		draw_char_at_coord(curr->row, curr->col, '*');
	}
}


#define GRID_LEN 20 //same height/width


void draw_grid_part(int start, bool vertical){
	char c = vertical ? '_' : '|';	
	int col_increment = vertical ? 1 : 0;
	int row_increment = vertical ? 0 : 1;
	int row = t.window_row/2 - 1 * col_increment + start * col_increment;
	int col = t.window_col/2 + 1 * col_increment + start * row_increment;


	for(int i = 0; i<GRID_LEN; i++){
		int col_offset = i * col_increment;
		int row_offset = i * row_increment;
		draw_char_at_coord(row + row_offset, col + col_offset, c);
		add_coords_to_array(row + row_offset, col + col_offset); //implemented in gamelogic
	}
}


void draw_scoreboard(){
	char output[64];	
	snprintf(output, sizeof(output), "\x1b[%d;%dHScore: %d\x1b[?25l", t.window_row/2 - 2, t.window_col/2, score);
	write(STDOUT_FILENO, output, strlen(output));

}



void draw_grid(){
	int top_row = 0;
	int bottom_row = 20;
	int leftmost_col = 0;
	int rightmost_col = 20;

	int grid_parts[] = {top_row, bottom_row, leftmost_col, rightmost_col};

	int array_len = sizeof(grid_parts) / sizeof(grid_parts[0]);

	for(int i = 0; i<array_len; i++){
		draw_grid_part(grid_parts[i], i < 2);
	}
}





void draw(){
        printf("\x1b[2J");
        fflush(stdout);
	draw_scoreboard();
        draw_grid();
       	draw_fruit();
        draw_snake();
}

