// Snake.cpp : �������̨Ӧ�ó������ڵ㡣
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


//���ʳ��
int g_nFoodRow = 0;
int g_nFoodCol = 0;
//��ʼ���ƶ�����
int nDir = E_DIR_NONE;
//�÷�
int nScore = 0;
//�������������,������С��ʾ�ߵĳ���
vector<SBody> g_snake;


void updateFood()
{
	//����һ�����ʳ��
	g_nFoodRow = rand() % (19 - 1) + 1;
	g_nFoodCol = rand() % (19 - 1) + 1;
	for (int i = 0; i < g_snake.size(); i++)
	{
		//���ʳ�ﴴ���������ϣ������ٴ���ʳ��
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

	//��ͷ��Ҫ��һ���ƶ��ķ����������Ĭ��Ϊ��
	nDir = E_DIR_NONE;
	//����һ�����飬�������������ߣ�����ĵ�һ��������Ϊ0��������ͷ
	g_snake.push_back(head);
	//�����������
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
	//����һ����ͷ
	//SBody head;
	//head.nRow = rand() % (19 - 1) + 1;
	//head.nCol = rand() % (19 - 1) + 1;
	//
	////��ͷ��Ҫ��һ���ƶ��ķ����������Ĭ��Ϊ��
	//int nDir = E_DIR_NONE;

	////����һ�����飬�������������ߣ�����ĵ�һ��������Ϊ0��������ͷ
	//g_snake.push_back(head);
	////�����������
	//srand(time(nullptr));
	//updateFood();

	while (true)
	{
		gotoxy(0, 0);
		if (E_GAME_MENU == nGameScene)
		{
			//��������
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

			//����¼�
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
				cout << "����������������������������" << endl;
				cout << "��     ��  Ϸ  ��  ��     ��" << endl;
				cout << "��      ->��ʼ��Ϸ        ��" << endl;
				cout << "��        ��Ϸ����        ��" << endl;
				cout << "��        �˳���Ϸ        ��" << endl;
				cout << "����������������������������" << endl;
			}
			else if (E_MENU_SET == nMenuState)
			{
				cout << "����������������������������" << endl;
				cout << "��     ��  Ϸ  ��  ��     ��" << endl;
				cout << "��        ��ʼ��Ϸ        ��" << endl;
				cout << "��      ->��Ϸ����        ��" << endl;
				cout << "��        �˳���Ϸ        ��" << endl;
				cout << "����������������������������" << endl;
			}
			else if (E_MENU_EXIT == nMenuState)
			{
				cout << "����������������������������" << endl;
				cout << "��     ��  Ϸ  ��  ��     ��" << endl;
				cout << "��        ��ʼ��Ϸ        ��" << endl;
				cout << "��        ��Ϸ����        ��" << endl;
				cout << "��      ->�˳���Ϸ        ��" << endl;
				cout << "����������������������������" << endl;
			}
		}
		else if (E_GAME_OVER == nGameScene)
		{
			
			cout << "����������������������������" << endl;
			cout << "��     ��  Ϸ  ��  ��     ��" << endl;
			cout << "��      ��  �֣�" << nScore << "        ��" << endl;
			cout << "��      ->  �� ҳ         ��" << endl;
			cout << "����������������������������" << endl;
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

		//��ʼ��Ϸ
		else if (E_GAME_MAP == nGameScene)
		{
			//����ÿһ�����������
			for (int i = 0; i < g_snake.size(); i++)
			{
				g_snake[i].nRowBk = g_snake[i].nRow;
				g_snake[i].nColBk = g_snake[i].nCol;
			}
			//�����ı���ͷ�ķ���
			if (KEY_DOWN(VK_UP))
			{
				//�ж�ԭ���ķ����ǲ������µ�
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

			//��ͷ����ָ���ķ����ƶ�
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
			//���������ͷ�ƶ�����һ��������Զ������һ���ƶ���
			for (int i = 1; i < g_snake.size(); i++)
			{
				g_snake[i].nRow = g_snake[i - 1].nRowBk;
				g_snake[i].nCol = g_snake[i - 1].nColBk;
			}
			//��ͷ����ʳ����������
			if (g_snake[0].nRow == g_nFoodRow && g_snake[0].nCol == g_nFoodCol)
			{
				//����һ������
				//�Ѵ�����������һ������ӵ���������
				SBody body;
				g_snake.push_back(body);
				nScore += 1;
				updateFood();

			}
			//��ͷײ��ǽ
			//�����ͷ��λ�õ���ǽ��λ�ã���ͷײǽ����Ϸ����
			if (1 == arrMap[g_snake[0].nRow][g_snake[0].nCol])
			{
				bClear = true;
				nGameScene = E_GAME_OVER;
			}

			//��ͷײ������
			for (int i = 1; i < g_snake.size(); i++)
			{
				if (g_snake[0].nRow == g_snake[i].nRow && g_snake[0].nCol == g_snake[i].nCol)
				{
					bClear = true;
					nGameScene = E_GAME_OVER;
				}
			}

			//��Ⱦ
			for (int i = 0; i < 20; i++)
			{
				for (int j = 0; j < 20; j++)
				{
					//���ߵ����廭����
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
						cout << "��";//ǽ
					}
					else if (i == g_snake[0].nRow && j == g_snake[0].nCol)
					{
						cout << "��";//��ͷ
					}
					else if (i == g_nFoodRow && j == g_nFoodCol)
					{
						cout << "��";//ʳ��
					}
					else if (bDrawBody)
					{
						cout << "��";//����
					}
					else if (0 == arrMap[i][j])
					{
						cout << "  ";//�յ�
					}
				}
				cout << endl;
			}
			if (bClear)
			{
				//�л�������ʱ����Ҫ��ԭ�е����������
				system("cls");
				bClear = false;
			}
		}
		
		Sleep(100);
	}
	return 0;
}

