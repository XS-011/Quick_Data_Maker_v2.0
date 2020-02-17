#include <bits/stdc++.h>
#include <Windows.h>
#include<time.h>
#include<conio.h>
using namespace std;
FILE *mainpage_dat;
const int main_page_print_n=4;
char main_page_print[20][100];
int h=1;//指向的方块
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
	mainpage_dat=fopen("mainpage.dat","r");
	for(int i=1;i<=main_page_print_n;i++)
	fscanf(mainpage_dat,"%s",main_page_print[i]);
}
void main_page()
{
	system("cls");//清屏指令
	for(int i=1;i<=main_page_print_n;i++)
	{
		if(i==h)
		{
			for(int j=1;j<=8;j++)
			putchar(' ');

			putchar('-');putchar('>');
			printf("%s",main_page_print[i]);
			putchar('<');
			putchar('-');
			putchar('\n');
		}
		else
		{
			for(int j=1;j<=10;j++)
			putchar(' ');

			printf("%s",main_page_print[i]);
			putchar('\n');
		}
	}
	printf("确认请按X");
	int Read;
	while(1)
	{
		Read=getCommand(); 
		if(Read==2 || Read==0 || Read==-2)
		break;
	}
	if(Read==2)
	h++;
	if(Read==0)
	h--;
	if(Read==-2)
	{
		/*执行相应程序*/
		if(h==1)
		system("numbermaker.exe");
		if(h==2);
		if(h==3);
		if(h==main_page_print_n)
		exit(0);
		/*以后添加的时候要注意一定要把退出程序置为最后一个*/
	}
	if(h==0)
	h=main_page_print_n;
	if(h==main_page_print_n+1)
	h=1;/*出界处理*/
}
int main()
{
	Initialize();
	while(1)
	main_page();
}
