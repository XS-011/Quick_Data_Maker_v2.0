#include <bits/stdc++.h>
#include <Windows.h>
#include<time.h>
#include<conio.h>
using namespace std;
int variable_n;
int h=0;//指针指向的方块
int Read;//读入的数据
struct node
{
	char Names[25];
	int Kinds;//变量种类1整数型 2.字符型 3.浮点型
	char Min,Max;
	int Group;//1表明他是数组，2表明不是
	char Times[35];
	int After;//0为之后不输出任何东西，1为空格，2为换行
};
node variable[105];
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
void Make_New()
{
	
	variable_n++;
	while(1)
	{
		system("cls");
		bool Flag=true;
		printf("输入你想使用的变量名\n");
		cin>>variable[variable_n].Names;
		for(int i=1;i<variable_n;i++)
		{
			if(strcmp(variable[i].Names,variable[variable_n].Names)==0)
			{
				Flag=false;
				break;
			}
		}
		if(strcmp("Model1",variable[variable_n].Names)==0)
		Flag=false;
		if(strcmp("Model2",variable[variable_n].Names)==0)
		Flag=false;
		if(strcmp("Model3",variable[variable_n].Names)==0)
		Flag=false;
		if(strcmp("Model4",variable[variable_n].Names)==0)
		Flag=false;
		if(strcmp("Model5",variable[variable_n].Names)==0)
		Flag=false;

		if(Flag==true)
		break;
		else
		printf("变量名不可用！\n");
	}
	system("cls");
	printf("输入变量的种类：1整数型 2.字符型 3.浮点型\n");
	cin>>variable[variable_n].Kinds;
	printf("这是一个数组（字符串）吗？1.是 2.不是\n");
	cin>>variable[variable_n].Group;
	if(variable[variable_n].Kinds==1)
	{
		printf("这个变量的最大值是多少？\n");
		cin>>variable[variable_n].Min;
		printf("这个变量的最小值是多少？\n");
		cin>>variable[variable_n].Max;
		if(variable[variable_n].Group==1)
		{
			printf("这个变量输出多少次？\n");
			cin>>variable[variable_n].Times;
		}
		printf("之后输出什么？0.什么都没有 1.空格 2.换行\n");
		cin>>variable[variable_n].After;
	}
	printf("完成！");
	system("cls");
}
void Working()
{
	int Start,End;
	system("cls");
	printf("输出文件的开始编号是多少？\n");
	cin>>Start;
	printf("输出文件的结束编号是多少？\n");
	cin>>End;
	FILE *k;
	k=fopen(".//data//Runthis.cpp","w+");
	fprintf(k,"#include <bits/stdc++.h>\n");
	fprintf("#define ll long long");
	fprintf(k,"using namespace std;\n");
	fprintf(k,"char Modle1=%cabcdefghijklmnopqrstuvwxyz%c",'"','"');
	for(int i=1;i<=variable_n;i++)
	{
		if(variable[variable_n].Kinds==1)
		fprintf(k,"ll %s;\n"variable[i].Names);
	}
	fprintf(k,"ll RP()\n{return (ll)(rand()*(ll)(rand()*(ll)(rand()*(ll)(rand());}\n");
	fprintf(k,"signed main()\n");
	printf("{\n");
	printf("srand(0)");
	for(int i=Start;i<=End;i++)
	{
		fprintf(k,"FILE *Act%d;\n",i);
		fprintf(k,"Act%d=fopen(%c%d.in%c);\n",i,'"',i,'"');
		for(int j=1;j<=variable_n;j++)
		{
			if(variable[j].Group==1)
			fprintf(k,"for(int i=1;i<=%s;i++)\n{\n",variable[j].Times);

			fprintf(k,"%s=(ll)(%s)+(ll)( RP()%((ll)(%s-%s+1)) );\n",variable[j].Names,variable[j].Min,variable[j].Max,variable[j].Min);
			fprintf("fprintf(Act%d,%c",i,'"');

			if(variable[j].Kinds)
		}
	}
}
void Check_All()
{
	Working();
}
void main_page()
{
	system("cls");
	for(int i=1;i<=8;i++)
	putchar(' ');

	if(h==0)
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
	if(h==0)
	{
		putchar('<');
		putchar('-'); 
	}
	putchar('\n');

	for(int i=1;i<=variable_n;i++)
	{
		for(int j=1;j<=8;j++)
		putchar(' ');
		if(h==i)
		{
			putchar('-');
			putchar('>');
		}
		else
		{
			putchar(' ');
			putchar(' ');
		}
		printf("变量：【%s】",variable[i].Names);
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
	if(h==variable_n+1)
	{
		putchar('<');
		putchar('-');
	}
	putchar('\n');
	
	for(int i=1;i<=8;i++)
	putchar(' ');
	if(h==variable_n+2)
	{
		putchar('-');
		putchar('>');
	}
	else
	{
		putchar(' ');
		putchar(' ');
	}
	printf("【返回至主程序】");
	if(h==variable_n+2)
	{
		putchar('<');
		putchar('-');
	}
	putchar('\n');

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
		if(h==0)
		Make_New();
		if(h>=1 && h<=variable_n)
		Check(h);
		if(h==variable_n+1)
		Check_All();
	}
	if(h==-1)
	h=variable_n+2;
	if(h==variable_n+3)
	h=0;
	
}
int main()
{
	Initialize();
	while(1)
    main_page();
}
