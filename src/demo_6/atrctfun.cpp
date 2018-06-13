#include <iostream>
#include <cmath>

// ������ṹ 
struct rect
{
	double x;
	double y;
};

// ������ṹ
struct polar
{
	double distance;				// ����
	double angle;					// �Ƕ�
};

polar rect_to_polar(rect rcpos);	// ������ת��������
void show_Polar(polar dapos);	// ��ʾ������

// ����ת��������
int atrctfun_test()
{
	using namespace std;

	rect rplace;
	polar pplace;

	cout << "Enter the x and y value: ";

	// ���������ֵ������cin����false���˳�whileѭ��
	while (cin >> rplace.x >> rplace.y)
	{
		pplace = rect_to_polar(rplace);
		show_Polar(pplace);
		cout << "Next two numbers(q to quit):";
	}

	cout << "Done.\n";
	return 0;
}

polar rect_to_polar(rect rcpos)
{
	polar pret;
	pret.distance = sqrt(rcpos.x * rcpos.x + rcpos.y * rcpos.y);
	pret.angle = atan2(rcpos.y, rcpos.x);
	return pret;
}

void show_Polar(polar dapos)
{
	using std::cout;
	using std::endl;
	
	double rad_to_deg = 180/M_PI;                            // ����ת�Ƕ�(���� * 180 / ��)  �Ƕ�ת����(�Ƕ� * �� / 180)
	cout << "distance = " << dapos.distance << endl;
	cout << "angle = " << dapos.angle * rad_to_deg << endl;
}

