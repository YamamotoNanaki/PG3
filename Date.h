#pragma once

struct Date
{
	static Date today;
	unsigned short year;
	unsigned short day;
	unsigned short month;
	//���������ŕ\��
	void Draw();
	void Set();
	//�����ƌ��ݕێ����Ă�������̃f�[�^��30���ȓ��̓��������v�Z
	int DaysDifference();
	static void SetToday();
};

