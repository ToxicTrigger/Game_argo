#pragma once

struct node
{
	int x;
	int y;
	//����
	int dir;
};


struct offset
{
	//���� ������
	int vert;
	//���� ������
	int horiz;
};

//Ÿ�� �Ӽ�
enum MAPINFO { BLANK, OBJECT, WALL };