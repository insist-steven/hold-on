#define _CRT_SECURE_NO_WARNINGS #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#include <time.h>

void menu()
{
	printf("***************\n");
	printf("***************\n");
	printf("*one.play*zero.exit*\n");
	printf("***************\n");
	printf("***************\n");


}
void initarray(char array[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<col; j++)
		{
			array[i][j] = ' ';
		}

	}


}
void displayarray(char array[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i<row; i++)
	{
		for (j = 0; j<col; j++)
		{
			printf(" %c ", array[i][j]);
			if (j<col - 1)
				printf("|");
		}
		printf("\n");
		if (i<row - 1)
		{
			for (j = 0; j<col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");

			}
			printf("\n");
		}
	}

}
void ComputerMove(char array[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("compter \n");
	while (1)
	{

		x = rand() % row;
		y = rand() % col;
		if (array[x][y] == ' ')
		{
			array[x][y] = '#';
			break;
		}
	}

}
int isfull(char array[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (array[i][j] == ' ')
			{
				return 0;
			}
		}
		
	}
	 return 1;
	     

}
char whowin(char array[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		
		if (array[i][0] == array[i][1] && array[i][1] == array[i][2] && array[i][1] != ' ')
		{
			return array[i][1];

		}
		
	}
	for (i = 0; i < col; i++)
	{
		if (array[0][i] == array[1][i] && array[1][i] == array[2][i] && array[1][i] != ' ')
		{
			return array[1][i];
		}
	
	}
	if (array[0][0] == array[1][1] && array[2][2]== array[1][1] && array[1][1] != ' ')
	{
		return array[1][1];
	}
	if (array[2][0] == array[1][1] && array[1][1] == array[0][2] && array[1][1] != ' ')
	{
		return array[1][1];

	}

	if (1 == isfull(array, ROW, COL))
	{
		return 'q';
	}
	else
	{
		return 'c';
	}

	
}

void PlayMove(char array[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("please put your coordinates\n");
		scanf("%d%d", &x,&y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{

			if (array[x - 1][y - 1] == ' ')
			{
				array[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("please put again\n");
			}
		}
		else
		{
			printf("the put is illwgal\n");
		}
	}
}
void game()
{  
	char ret = 0;
	char array[ROW][COL] = { 0 };

	initarray(array, ROW, COL);

	displayarray(array, ROW, COL);
	while (1)
	{
		PlayMove(array, ROW, COL);
		displayarray(array, ROW, COL);
		ret = whowin(array, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
		

		ComputerMove(array, ROW, COL);
		displayarray(array, ROW, COL);
		ret = whowin(array, ROW, COL);
		if (ret != 'c')
		{
			break;
		}
	}

		if (ret == '*')
		{
			printf("player win\n");
		}
		else if (ret == '#')
		{
			printf("computer win\n");
		}
		else
		{
			printf("dogfall\n");
		}

		

}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//²¥ÖÖ
	do
	{
		menu();
		printf("Please put zero or one");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("quit game\n");
			break;
		default:
			printf("error and again!\n");
			break;
		}
	} while (input);
}
int main()
{

	test();

	return 0;
}
