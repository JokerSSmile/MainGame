#include "view.h"

void GetPlayerCoordinateForView(float x, float y)
{
	float tempX = x; float tempY = y;//��������� ����� ������ � ��������� ��, ����� ������ ����

	if (x < 480) tempX = 480;//������� �� ���� ����� �������
	if (y < 320) tempY = 320;//������� �������
	if (y > 320) tempY = 320;//������ �������	
	if (x > 480) tempX = 480;

	view.setCenter(tempX, tempY); //������ �� �������, ��������� ��� ����������
}