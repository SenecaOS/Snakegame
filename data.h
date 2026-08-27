 #ifndef DATA_H
 #define DATA_H
#include <stdlib.h>


#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "data.h"
#include <unistd.h>
#include <sys/ioctl.h>
#include <termios.h>
 
typedef struct Part{
         int row;
         int col;
         struct Part *next;
         int curr_row_vector;
         int curr_col_vector;
 
         int last_row_vector;
         int last_col_vector;
 } Part;
 
 typedef struct {
         Part *parts;
 }Snake;
 
 
 typedef struct{
         int window_row;
         int window_col;
 
 
 }Terminal;
 
 typedef struct{
         int row;
         int col;
 }Fruit;
void increment_score();
bool snake_eats_fruit();
void add_snake_coords(int row, int col);
bool is_in_tail(int row, int col);
void add_coords_to_array(int row, int col);
void set_curr_to_prev();
extern Terminal t;
extern Snake snake;
extern Part head;
extern Fruit f;
extern int tail_len;
extern int score;
extern int **grid_coordinates;
void draw();
void get_terminal_size(int*, int*);
void init_part();
void enter_rawmode();
void leave_rawmode();
void add_part(Part next_part);
void update_part_vector();
void update_last(); 
bool snake_is_in_grid();
void spawn_random_fruit();
void draw_grid();
 #endif

