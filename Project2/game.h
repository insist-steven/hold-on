#define ROW 3
#define COL 3
void initarray(char array[ROW][COL], int row,  int col);
void displayarray(char array[ROW][COL], int row, int col);
void PlayMove(char array[ROW][COL], int row, int col);
void ComputerMove(char array[ROW][COL], int row, int col);
char whowin(char array[ROW][COL], int row, int col);
