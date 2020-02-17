#include <bits/stdc++.h>
#include <Windows.h>
#include<time.h>
#include<conio.h>
using namespace std;
int variable_n;
int h=1;//指针指向的方块
struct node
{
	char names[25];
}variable[105];
int getCommand()
{
	int temp = -1;
	if (_kbhit()) //如果有键盘输入
	{
		switch (_getch())
		{
		case 'A': case 'a': temp = 3; break; //表示向左
		case 'S': case 's': temp = 2; break; //表示向下
		case 'D': case 'd': temp = 1; break; //表示向右
		case 'W': case 'w': temp = 0; break; //表示向上
		case 'X': case 'x': temp = -2;break;//表示确认
		}
	}
	return temp;
	/*
	A是3
	S是2
	D是1
	W是0
	无读取数据是-1
	确认X是-2
	*/
}
void Initialize()
{
	SetConsoleOutputCP(65001);//转换编码，防止出现乱码
	variable_n=0;
}
void main_page()
{
	for(int i=1;i<=8;i++)
	putchar(' ');

	if(h==1)
	{
		putchar('-');
		putchar('>');
	}
	else
	{
		putchar(' ');
		putchar(' ');
	}
    printf("【新建变量】");
	if(h==1)
	{
		putchar('<');
		putchar('-')
	}
	putchar('\n');

	for(int i=1;i<=variable_n;i++)
	{
		for(int i=1;i<=8;i++)
		putchar(' ');
		if(h==i+1)
		{
			putchar('-');
			putchar('>');
		}
		else
		{
			putcahr(' ');
			putchar(' ');
		}
		printf("变量：【%s】",variable[i].names);
		if(h==i+1)
		{
			putchar('<');
			putchar('-');
		}
		putchar('\n');
	}/*输出所有的变量*/
	for(int i=1;i<=8;i++)
	putchar(' ');
	if(h==variable_n+1)
	{
		putchar('-');
		putchar('>');
	}
	else
	{
		putchar(' ');
		putchar(' ');
	}
	printf("【检查并开始】");
	
}
int main()
{
	while(1)
    main_page();
}
