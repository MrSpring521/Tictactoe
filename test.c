#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("copyright Mr_Spring\n");
	printf("************************************\n");
	printf("***********1.play  0.exit***********\n");
	printf("************************************\n");
}
void game()
{
	char ret;
	char board[ROW][COL] = { 0 };
	Initboard(board, ROW, COL );
	Displayboard(board,ROW,COL);
	while (1)
	{
		Playermove(board,ROW,COL);
		Displayboard(board, ROW, COL);
		ret = Iswin(board,ROW,COL);
		if (ret != 'C' && ret != ' ')
		{
			break;
		}
		Computermove(board, ROW, COL);
		Displayboard(board, ROW, COL);
		ret = Iswin(board,ROW,COL);
		if (ret != 'C'&&ret!=' ')
		{
			break;
		}
	}
	if (ret == '*')
		printf("玩家赢\n\n");
	else if (ret == '#')
		printf("电脑赢\n\n");
	else
		printf("平局\n\n");
}
void test()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}