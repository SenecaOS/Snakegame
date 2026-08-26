#include "data.h"
#define INITIAL_SNAKE_SIZE 5
Fruit f;
Snake snake;
Terminal t;
int tail_len = 0;

int score = 0;
int **grid_coordinates;
void init_part(){
        snake.parts = malloc(INITIAL_SNAKE_SIZE *sizeof(Part));
	Part *next = malloc(sizeof(Part));
	for(int i = 0; i<INITIAL_SNAKE_SIZE; i++){
        	Part part = {t.window_row/2 - i + 6, t.window_col/2 + 10, next, 1, 0, 1, 0}; 
		snake.parts[tail_len] = part;	
		*next = snake.parts[tail_len++];
	}
}

void init(){
        t.window_row = 0;
        t.window_col = 0;
        get_terminal_size(&t.window_row, &t.window_col);
        grid_coordinates = malloc(256 * sizeof(int*));
	init_part();
}

void execute_game_tick(){
		static bool fruit_is_spawned;
		set_curr_to_prev();
		update_part_vector();
		if(!fruit_is_spawned){
			spawn_random_fruit();
			fruit_is_spawned = true;
		}
		if(snake_eats_fruit()){
			fruit_is_spawned = false;
			add_part(snake.parts[tail_len - 1]);
			increment_score();
		}	

		draw();	
		if(snake_is_in_grid() || snake_biting_tail()) exit(0);
                usleep(250 * 1000);
}


void enter_game_loop(){
        char c;
        while(read(STDIN_FILENO, &c, 1) != -1){
                switch(c){
                        case 'w':
                                if(snake.parts[0].curr_row_vector != 1){	
                                        snake.parts[0].curr_row_vector = -1;
                                        snake.parts[0].curr_col_vector = 0;
                                }
                                break;
                        case 's':
                                if(snake.parts[0].curr_row_vector != -1){
					snake.parts[0].curr_row_vector = 1;
                                        snake.parts[0].curr_col_vector = 0;
                                }
                                break;
                        case 'd':
                                if(snake.parts[0].curr_col_vector != -1){	
                                        snake.parts[0].curr_col_vector = 1;
                                        snake.parts[0].curr_row_vector = 0;
                                }
                                break;
                        case 'a':
                                if(snake.parts[0].curr_col_vector != 1){

                                        snake.parts[0].curr_col_vector = -1;
                                        snake.parts[0].curr_row_vector = 0;
                                }
                                break;
                        case 'q':
                                write(STDOUT_FILENO, "\x1b[?25h", 6);
				leave_rawmode();
                                exit(0);
                                break;
                        default:

                }
		execute_game_tick();
        }
}




int main(){
	enter_rawmode();
	init();
	enter_game_loop();

}
