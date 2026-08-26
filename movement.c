#include "data.h"


void update_part_vector(){
        int index = tail_len - 1;


        while(index >= 0){
                Part *curr = &snake.parts[index];
		curr->row += curr->curr_row_vector;
		curr->col += curr->curr_col_vector;		
		curr->last_row_vector = curr->curr_row_vector;	
		curr->last_col_vector = curr->curr_col_vector;
		index--;
		
        }
}

void set_curr_to_prev(){

	for(int i = 0; i<tail_len; i++){
		if(i >= 1){
			snake.parts[i].curr_row_vector = snake.parts[i-1].last_row_vector;
			snake.parts[i].curr_col_vector = snake.parts[i-1].last_col_vector;
		}
	}
}
