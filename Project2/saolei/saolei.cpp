#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
void menu()
{
	printf("******************\n");
	printf("********1.play******\n");
	printf("********0.exit****\n");
	printf("******************\n");
	printf("******************\n");

}
void initarray(char array[ROWS][COLS], int rows, int cols, char set)
{
	int x = 0;
	int y = 0;
	for (x = 0; x < rows; x++)
	{
		for (y = 0; y < cols; y++)
		{
			array[x][y] = set;
		}
	
	}

}
void displayarray(char array[ROWS][COLS], int row, int col)
{
	int i = 1;
	int j = 1;
	//打印列好
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ",i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", array[i][j]);
		}

		printf("\n");
	}
}
void wriarray(char array[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = Easy;
	while (count)
	{
		i = rand () % row + 1;
		j = rand() % col + 1;
		if (array[i][j] == '0')
		{
			array[i][j] = '1';
			count--;
		}
	
	}

}
int getmaincount(char main[ROWS][COLS], int x, int y)
{
	return main[x - 1][y] +
		main[x + 1][y] +
		main[x - 1][y - 1] +
		main[x - 1][y + 1] +
		main[x + 1][y - 1] +
		main[x + 1][y + 1] +
		main[x][y - 1] +
		main[x][y + 1] - 8 * '0';

}
void findarray(char main[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row*col-Easy)
	{
		printf("please input coord\n");
		scanf("%d%d",&x,&y);
		if (x >= 1 && x <= row && y>=1 && y <= col)
		{
			if (main[x][y] == '1')
			{ 
				printf("You have been blown up\n");
				displayarray(main,row,col);
				break;
			}
			else
			{
				int count = getmaincount(main,x,y);
				show[x][y] = count + '0';
				displayarray(show,row,col);
				win++;
			}
		}
		else
		{
			printf("illegal coord\n");
		}
	}
	if (win == row*col - Easy)
	{
		printf("You have won\n");
	}
}
void game()
{
	char main[ROWS][COLS] = { 0 };

	char show[ROWS][COLS] = { 0 };

	initarray(main, ROWS, COLS, '0');

	initarray(show, ROWS, COLS, '*');

	//displayarray(main,ROW,COL);
	displayarray(show,ROW,COL);
	wriarray(main, ROW, COL);//布置雷
	//displayarray(main,ROW,COL);
	findarray(main,show,ROW,COL);
	



}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{

		menu();
		printf("plase choose 1 or 0\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("exit\n");
			break;
		default:
			printf("please choose again\n");
			break;

		}
	} while (input);
}
int main()
{
	test();
	return 0;
}