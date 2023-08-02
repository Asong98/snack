// Snake.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
#define KEY_DOWN(vk_code) (GetAsyncKeyState(vk_code)&0x8000)?1:0

void gotoxy(int x, int y)
{
	COORD position;
	position.X = x;
	position.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

enum
{
	E_GAME_MENU,
	E_GAME_MAP,
	E_GAME_OVER
};

enum
{
	E_MENU_START,
	E_MENU_SET,
	E_MENU_EXIT
};

enum
{
	E_DIR_NONE,
	E_DIR_UP,
	E_DIR_DOWN,
	E_DIR_LEFT,
	E_DIR_RIGHT
};

struct SBody
{
	int nRow;
	int nCol;
	int nRowBk;
	int nColBk;
};




//SBody g_snake[100];


//随机食物
int g_nFoodRow = 0;
int g_nFoodCol = 0;
//初始化移动方向
int nDir = E_DIR_NONE;
//得分
int nScore = 0;
//创建蛇身的容器,容器大小表示蛇的长度
vector<SBody> g_snake;


void updateFood()
{
	//创建一个随机食物
	g_nFoodRow = rand() % (19 - 1) + 1;
	g_nFoodCol = rand() % (19 - 1) + 1;
	for (int i = 0; i < g_snake.size(); i++)
	{
		//如果食物创建在蛇身上，重新再创建食物
		if (g_nFoodRow == g_snake[i].nRow && g_nFoodCol == g_snake[i].nCol)
		{
			updateFood();
		}
	}
}

void newGame()
{
	g_snake.clear();
	nScore = 0;
	SBody head;
	head.nRow = rand() % (19 - 1) + 1;
	head.nCol = rand() % (19 - 1) + 1;

	//蛇头需要有一个移动的方向，这个方向默认为空
	nDir = E_DIR_NONE;
	//定义一个数组，用来代表整条蛇，数组的第一个（索引为0）代表蛇头
	g_snake.push_back(head);
	//更新随机种子
	srand(time(nullptr));
	updateFood();
}


int _tmain(int argc, _TCHAR* argv[])
{
	int arrMap[20][20] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};
	int nMenuState = E_MENU_START;
	int nGameScene = E_GAME_MENU;
	bool bClear = false;

	//newGame();
	//int nGameScene = 0;
	//创建一个蛇头
	//SBody head;
	//head.nRow = rand() % (19 - 1) + 1;
	//head.nCol = rand() % (19 - 1) + 1;
	//
	////蛇头需要有一个移动的方向，这个方向默认为空
	//int nDir = E_DIR_NONE;

	////定义一个数组，用来代表整条蛇，数组的第一个（索引为0）代表蛇头
	//g_snake.push_back(head);
	////更新随机种子
	//srand(time(nullptr));
	//updateFood();

	while (true)
	{
		gotoxy(0, 0);
		if (E_GAME_MENU == nGameScene)
		{
			//按键处理
			if (KEY_DOWN(VK_UP))
			{
				nMenuState--;
				if (nMenuState <E_MENU_START)
				{
					nMenuState = E_MENU_EXIT;
				}
			}
			else if (KEY_DOWN(VK_DOWN))
			{
				nMenuState++;
				if (nMenuState > E_MENU_EXIT)
				{
					nMenuState = E_MENU_START;
				}
			}

			//光标事件
			else if (KEY_DOWN(VK_RETURN))
			{
				if (E_MENU_START == nMenuState)
				{
					bClear = true;
					nGameScene = E_GAME_MAP;
					newGame();
					

				}
				else if (E_MENU_SET == nMenuState)
				{
				}
				else if (E_MENU_EXIT == nMenuState)
				{
					exit(0);
				}
			}
			if (E_MENU_START == nMenuState)
			{
				cout << "□□□□□□□□□□□□□□" << endl;
				cout << "□     游  戏  菜  单     □" << endl;
				cout << "□      ->开始游戏        □" << endl;
				cout << "□        游戏设置        □" << endl;
				cout << "□        退出游戏        □" << endl;
				cout << "□□□□□□□□□□□□□□" << endl;
			}
			else if (E_MENU_SET == nMenuState)
			{
				cout << "□□□□□□□□□□□□□□" << endl;
				cout << "□     游  戏  菜  单     □" << endl;
				cout << "□        开始游戏        □" << endl;
				cout << "□      ->游戏设置        □" << endl;
				cout << "□        退出游戏        □" << endl;
				cout << "□□□□□□□□□□□□□□" << endl;
			}
			else if (E_MENU_EXIT == nMenuState)
			{
				cout << "□□□□□□□□□□□□□□" << endl;
				cout << "□     游  戏  菜  单     □" << endl;
				cout << "□        开始游戏        □" << endl;
				cout << "□        游戏设置        □" << endl;
				cout << "□      ->退出游戏        □" << endl;
				cout << "□□□□□□□□□□□□□□" << endl;
			}
		}
		else if (E_GAME_OVER == nGameScene)
		{
			
			cout << "□□□□□□□□□□□□□□" << endl;
			cout << "□     游  戏  结  束     □" << endl;
			cout << "□      得  分：" << nScore << "        □" << endl;
			cout << "□      ->  主 页         □" << endl;
			cout << "□□□□□□□□□□□□□□" << endl;
			if (KEY_DOWN(VK_RETURN))
			{
				bClear = true;
			/*	g_snake.clear();
				SBody head;
				head.nRow = 5;
				head.nCol = 8;*/
				nGameScene = E_GAME_MENU;
			}
		}

		//开始游戏
		else if (E_GAME_MAP == nGameScene)
		{
			//备份每一节身体的坐标
			for (int i = 0; i < g_snake.size(); i++)
			{
				g_snake[i].nRowBk = g_snake[i].nRow;
				g_snake[i].nColBk = g_snake[i].nCol;
			}
			//按键改变蛇头的方向
			if (KEY_DOWN(VK_UP))
			{
				//判断原来的方向是不是往下的
				if (nDir != E_DIR_DOWN)
				{
					nDir = E_DIR_UP;
				}
			}
			else if (KEY_DOWN(VK_DOWN))
			{
				if (nDir != E_DIR_UP)
				{
					nDir = E_DIR_DOWN;
				}
			}
			else if (KEY_DOWN(VK_LEFT))
			{
				if (nDir != E_DIR_RIGHT)
				{
					nDir = E_DIR_LEFT;
				}
			}
			else if (KEY_DOWN(VK_RIGHT))
			{
				if (nDir != E_DIR_LEFT)
				{
					nDir = E_DIR_RIGHT;
				}
			}

			//蛇头朝着指定的方向移动
			if (E_DIR_UP == nDir)
			{
				g_snake[0].nRow--;
			}
			else if (E_DIR_DOWN == nDir)
			{
				g_snake[0].nRow++;
			}
			else if (E_DIR_LEFT == nDir)
			{
				g_snake[0].nCol--;
			}
			else if (E_DIR_RIGHT == nDir)
			{
				g_snake[0].nCol++;
			}
			//身体跟着蛇头移动（下一节身体永远跟着上一节移动）
			for (int i = 1; i < g_snake.size(); i++)
			{
				g_snake[i].nRow = g_snake[i - 1].nRowBk;
				g_snake[i].nCol = g_snake[i - 1].nColBk;
			}
			//蛇头吃上食物蛇身增长
			if (g_snake[0].nRow == g_nFoodRow && g_snake[0].nCol == g_nFoodCol)
			{
				//创建一节身体
				//把创建出来的这一节身体加到容器里面
				SBody body;
				g_snake.push_back(body);
				nScore += 1;
				updateFood();

			}
			//蛇头撞上墙
			//如果蛇头的位置等于墙的位置（蛇头撞墙）游戏结束
			if (1 == arrMap[g_snake[0].nRow][g_snake[0].nCol])
			{
				bClear = true;
				nGameScene = E_GAME_OVER;
			}

			//蛇头撞上蛇身
			for (int i = 1; i < g_snake.size(); i++)
			{
				if (g_snake[0].nRow == g_snake[i].nRow && g_snake[0].nCol == g_snake[i].nCol)
				{
					bClear = true;
					nGameScene = E_GAME_OVER;
				}
			}

			//渲染
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					//把蛇的身体画出来
					bool bDrawBody = false;
					for (int n = 1; n < g_snake.size(); n++)
					{
						if (i == g_snake[n].nRow && j == g_snake[n].nCol)
						{
							bDrawBody = true;
						}
					}
					if (1 == arrMap[i][j])
					{
						cout << "□";//墙
					}
					else if (i == g_snake[0].nRow && j == g_snake[0].nCol)
					{
						cout << "◇";//蛇头
					}
					else if (i == g_nFoodRow && j == g_nFoodCol)
					{
						cout << "△";//食物
					}
					else if (bDrawBody)
					{
						cout << "●";//蛇身
					}
					else if (0 == arrMap[i][j])
					{
						cout << "  ";//空地
					}
				}
				cout << endl;
			}
			if (bClear)
			{
				//切换场景的时候需要把原有的内容清除掉
				system("cls");
				bClear = false;
			}
		}
		
		Sleep(100);
	}
	return 0;
}

