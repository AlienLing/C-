#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include<stdlib.h>
#include<Windows.h>
#define PI 3.1415926
#define WIDTH 800              // 画面宽度
#define HEIGHT 600             // 画面高度
using namespace std;
float offsetAngle = PI / 6;    // 左右枝干和父枝干偏离的角度
float shortenRate = 0.65;      // 左右枝干长度与父枝干长度的比例
int isShowAnimation = 1;       // 是否显示树生成过程动画
// 定义点的坐标数组
int x[100];			// 点的 x 坐标
int y[100]; // 点的 y 坐标
int i;
void update_fall();



float mapValue(float input, float inputMin, float inputMax, float outputMin, float outputMax)
{
	float output;
	if (fabs(input - inputMin) < 0.000001)   // 防止除0
	{
		output = outputMin;
	}
	else
	{
		output = (input - inputMin) * (outputMax - outputMin) / (inputMax - inputMin) + outputMin;
	}
	return output;
}

float randBetween(float min, float max)
{
	float t = rand() / double(RAND_MAX);      // 生成[0, 1]的随机小数
	float r = mapValue(t, 0, 1, min, max);
	return r;
}

void xuehuastart()
{
	HRGN rgn1 = CreateRectRgn(0, 0, 150, 600);
	HRGN rgn2 = CreateRectRgn(650, 0, 800, 600);//设置裁剪区域
	HRGN rgn= CreateRectRgn(0, 0, 0, 0);
	int n1=CombineRgn(rgn,rgn1,rgn2,RGN_OR);//合并裁剪区域
	setcliprgn(rgn);//裁剪
	srand((unsigned)time(NULL));
	update_fall();
	while (!_kbhit())
	{
		for (i = 0; i < 20; i++)
		{
			// 擦掉前一个点
			setcolor(BLACK);
			setfillcolor(BLACK);
			fillcircle(x[i], y[i], 5);
			// 计算新坐标
			y[i] += 3;
			if (y[i] >= 600)
			{
				setcolor(WHITE);   //在落地位置画雪花
				setfillcolor(WHITE);
				fillcircle(x[i], y[i], 5);
				y[i] = 0;   //重新初始化雪花的位置
				x[i] = rand() % 800;
			}
			setcolor(WHITE);  //在新位置画雪花
			setfillcolor(WHITE);
			fillcircle(x[i], y[i], 5);
		}
		Sleep(10);
	}
}

void branch(float x_start, float y_start, float length, float angle, float thickness, int generation)
{
	float x_end, y_end;
	x_end = x_start + length * cos(angle);
	y_end = y_start + length * sin(angle);

	setlinestyle(PS_SOLID, thickness);      // 设定当前枝干线宽
	COLORREF color = HSVtoRGB(15, 0.75, 0.4 + generation * 0.05); // 枝干颜色，随代数变浅
	setlinecolor(color);//设置线色

	line(x_start, y_start, x_end, y_end);

	int childGeneration = generation + 1;   // 子枝干的代数
	float childLength = shortenRate * length; // 子枝干的长度逐渐变短
	float leftChildLength = childLength * randBetween(0.9, 1.1);  // 为子枝干长度引入随机性
	float rightChildLength = childLength * randBetween(0.9, 1.1);
	float centerChildLength = childLength * randBetween(0.8, 1.1);

	if (childLength >= 2 && childGeneration <= 9)               // 当子枝干长度大于2，且代数小于等于9，绘制子枝干
	{
		float childThickness = thickness * 0.8;                 // 枝干逐渐变细
		if (childThickness < 2)
		{
			childThickness = 2;
		}

		if (randBetween(0, 1) < 0.95)
		{
			branch(x_end, y_end, leftChildLength, angle + offsetAngle * randBetween(0.5, 1), childThickness, childGeneration);//左枝干迭代
		}
		if (randBetween(0, 1) < 0.95)
		{
			branch(x_end, y_end, childLength, angle - offsetAngle * randBetween(0.5, 1), childThickness, childGeneration);//右枝干迭代
		}
		if (randBetween(0, 1) < 0.85)
		{
			branch(x_end, y_end, centerChildLength, angle + offsetAngle / 5 * randBetween(-1, 1), childThickness, childGeneration);//主枝干迭代
		}
	}
	else//绘制樱花
	{
		setlinestyle(PS_SOLID, 1);//粗细为1的实线
		COLORREF color = HSVtoRGB(randBetween(300, 350), randBetween(0.2, 0.3), 1);//设置引入随机性的粉色
		setlinecolor(color);
		setfillcolor(color);
		if (childLength <= 4)
		{
			fillcircle(x_end, y_end, 2);
		}
		else
		{
			fillcircle(x_end, y_end, childLength / 2);
		}
	}
	
	if (isShowAnimation)//显示生成动画
	{
		FlushBatchDraw();
		Sleep(0.2);//每划线间隔0.002s
	}
}

void startup()
{
	srand(time(0));
	initgraph(WIDTH, HEIGHT);//绘图窗口初始化
	setbkcolor(RGB(0, 0, 0));//设置黑色背景色
	cleardevice();//用背景色清空屏幕
	BeginBatchDraw();//启动批量绘图模式
	branch(WIDTH / 2, HEIGHT, 0.45 * HEIGHT * shortenRate, -PI / 2, 15 * shortenRate, 1);
	EndBatchDraw();//执行未完成的绘制任务，不退出批量绘制状态
}

void update_fall()
{
	for (i = 0; i < 20; i++)
	{
		x[i] = rand() % 800;
		y[i] = rand() % 600;
	}
}

void update()
{
	ExMessage e;//消息结构体，用于鼠标控制
	if (peekmessage(&e))//获得windows发给这个程序的消息，处理并转发
	{
		if (e.message == WM_MOUSEMOVE)
		{
			offsetAngle = mapValue(e.x, 0, WIDTH, PI / 10, PI / 4);      // 鼠标从左到右移动，左右枝干偏离父枝干的角度逐渐变大
			shortenRate = mapValue(e.y, 0, HEIGHT, 0.7, 0.3);            // 鼠标从上到下移动，子枝干的长度比父枝干的长度缩短得更快
		}
		if (e.message == WM_LBUTTONDOWN)//左键按下重新绘制
		{
			cleardevice();
			branch(WIDTH / 2, HEIGHT, 0.45 * HEIGHT * shortenRate, -PI / 2, 15 * shortenRate, 1);
			FlushBatchDraw();
		}
		if (e.message == WM_RBUTTONDOWN)//右键按下切换是否显示树生成过程动画
		{
			if (isShowAnimation == 1)
			{
				isShowAnimation = 0;
			}
			else if (isShowAnimation == 1)
			{
				isShowAnimation = 1;
			}
		}
	}
}

int main()
{
	startup();//开始绘制
	while (1)
	{
		update();//一直接收信息
		xuehuastart();
	}
	return 0;
}



