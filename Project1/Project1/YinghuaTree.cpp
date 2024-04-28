#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include<stdlib.h>
#include<Windows.h>
#define PI 3.1415926
#define WIDTH 800              // ������
#define HEIGHT 600             // ����߶�
using namespace std;
float offsetAngle = PI / 6;    // ����֦�ɺ͸�֦��ƫ��ĽǶ�
float shortenRate = 0.65;      // ����֦�ɳ����븸֦�ɳ��ȵı���
int isShowAnimation = 1;       // �Ƿ���ʾ�����ɹ��̶���
// ��������������
int x[100];			// ��� x ����
int y[100]; // ��� y ����
int i;
void update_fall();



float mapValue(float input, float inputMin, float inputMax, float outputMin, float outputMax)
{
	float output;
	if (fabs(input - inputMin) < 0.000001)   // ��ֹ��0
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
	float t = rand() / double(RAND_MAX);      // ����[0, 1]�����С��
	float r = mapValue(t, 0, 1, min, max);
	return r;
}

void xuehuastart()
{
	HRGN rgn1 = CreateRectRgn(0, 0, 150, 600);
	HRGN rgn2 = CreateRectRgn(650, 0, 800, 600);//���òü�����
	HRGN rgn= CreateRectRgn(0, 0, 0, 0);
	int n1=CombineRgn(rgn,rgn1,rgn2,RGN_OR);//�ϲ��ü�����
	setcliprgn(rgn);//�ü�
	srand((unsigned)time(NULL));
	update_fall();
	while (!_kbhit())
	{
		for (i = 0; i < 20; i++)
		{
			// ����ǰһ����
			setcolor(BLACK);
			setfillcolor(BLACK);
			fillcircle(x[i], y[i], 5);
			// ����������
			y[i] += 3;
			if (y[i] >= 600)
			{
				setcolor(WHITE);   //�����λ�û�ѩ��
				setfillcolor(WHITE);
				fillcircle(x[i], y[i], 5);
				y[i] = 0;   //���³�ʼ��ѩ����λ��
				x[i] = rand() % 800;
			}
			setcolor(WHITE);  //����λ�û�ѩ��
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

	setlinestyle(PS_SOLID, thickness);      // �趨��ǰ֦���߿�
	COLORREF color = HSVtoRGB(15, 0.75, 0.4 + generation * 0.05); // ֦����ɫ���������ǳ
	setlinecolor(color);//������ɫ

	line(x_start, y_start, x_end, y_end);

	int childGeneration = generation + 1;   // ��֦�ɵĴ���
	float childLength = shortenRate * length; // ��֦�ɵĳ����𽥱��
	float leftChildLength = childLength * randBetween(0.9, 1.1);  // Ϊ��֦�ɳ������������
	float rightChildLength = childLength * randBetween(0.9, 1.1);
	float centerChildLength = childLength * randBetween(0.8, 1.1);

	if (childLength >= 2 && childGeneration <= 9)               // ����֦�ɳ��ȴ���2���Ҵ���С�ڵ���9��������֦��
	{
		float childThickness = thickness * 0.8;                 // ֦���𽥱�ϸ
		if (childThickness < 2)
		{
			childThickness = 2;
		}

		if (randBetween(0, 1) < 0.95)
		{
			branch(x_end, y_end, leftChildLength, angle + offsetAngle * randBetween(0.5, 1), childThickness, childGeneration);//��֦�ɵ���
		}
		if (randBetween(0, 1) < 0.95)
		{
			branch(x_end, y_end, childLength, angle - offsetAngle * randBetween(0.5, 1), childThickness, childGeneration);//��֦�ɵ���
		}
		if (randBetween(0, 1) < 0.85)
		{
			branch(x_end, y_end, centerChildLength, angle + offsetAngle / 5 * randBetween(-1, 1), childThickness, childGeneration);//��֦�ɵ���
		}
	}
	else//����ӣ��
	{
		setlinestyle(PS_SOLID, 1);//��ϸΪ1��ʵ��
		COLORREF color = HSVtoRGB(randBetween(300, 350), randBetween(0.2, 0.3), 1);//������������Եķ�ɫ
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
	
	if (isShowAnimation)//��ʾ���ɶ���
	{
		FlushBatchDraw();
		Sleep(0.2);//ÿ���߼��0.002s
	}
}

void startup()
{
	srand(time(0));
	initgraph(WIDTH, HEIGHT);//��ͼ���ڳ�ʼ��
	setbkcolor(RGB(0, 0, 0));//���ú�ɫ����ɫ
	cleardevice();//�ñ���ɫ�����Ļ
	BeginBatchDraw();//����������ͼģʽ
	branch(WIDTH / 2, HEIGHT, 0.45 * HEIGHT * shortenRate, -PI / 2, 15 * shortenRate, 1);
	EndBatchDraw();//ִ��δ��ɵĻ������񣬲��˳���������״̬
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
	ExMessage e;//��Ϣ�ṹ�壬����������
	if (peekmessage(&e))//���windows��������������Ϣ������ת��
	{
		if (e.message == WM_MOUSEMOVE)
		{
			offsetAngle = mapValue(e.x, 0, WIDTH, PI / 10, PI / 4);      // ���������ƶ�������֦��ƫ�븸֦�ɵĽǶ��𽥱��
			shortenRate = mapValue(e.y, 0, HEIGHT, 0.7, 0.3);            // �����ϵ����ƶ�����֦�ɵĳ��ȱȸ�֦�ɵĳ������̵ø���
		}
		if (e.message == WM_LBUTTONDOWN)//����������»���
		{
			cleardevice();
			branch(WIDTH / 2, HEIGHT, 0.45 * HEIGHT * shortenRate, -PI / 2, 15 * shortenRate, 1);
			FlushBatchDraw();
		}
		if (e.message == WM_RBUTTONDOWN)//�Ҽ������л��Ƿ���ʾ�����ɹ��̶���
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
	startup();//��ʼ����
	while (1)
	{
		update();//һֱ������Ϣ
		xuehuastart();
	}
	return 0;
}



