#include "data.h"

struct termios orig_termios;

void write_to_file(){
	FILE *fptr;
	fptr = fopen("hiscores.txt", "a");
	char curr_score[32];

	snprintf(curr_score, sizeof(curr_score), "%d\n", score);

	fprintf(fptr, "%s", curr_score);

	fclose(fptr);


}


void leave_rawmode(){
        tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
        printf("\x1b[H");
        printf("\x1b[2J");
        fflush(stdout);
	write_to_file();
}


void enter_rawmode(){
         tcgetattr(STDIN_FILENO, &orig_termios);
         atexit(leave_rawmode);
         struct termios raw = orig_termios;
         raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
         raw.c_oflag &= ~(OPOST);
         raw.c_cflag |= (CS8);
         raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
         raw.c_cc[VMIN] = 0;
         raw.c_cc[VTIME] = 0;
         tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}
void get_terminal_size(int *row, int *col){
        struct winsize w;
        ioctl(0, TIOCGWINSZ, &w);
 
        *row = w.ws_row;
        *col = w.ws_col;
 }

