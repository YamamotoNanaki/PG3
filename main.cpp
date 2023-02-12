#include <cstdlib>
#include <iostream>
#include "PersonManager.h"
#include "TaskManager.h"

using namespace std;

void main()
{
	Date::SetToday();
	PersonManager* pm = PersonManager::GetInstance();
	TaskManager* tm = TaskManager::GetInstance();
	pm->InPut();
	tm->InPut();
	int decision = 1;
	while (decision != 0)
	{
		std::system("cls");
		size_t psize = pm->GetPeopleSize();
		bool flag = true;
		int decisionMax = 2;
		if (psize == 0)
		{
			flag = false;
			decisionMax = 1;
		}
		cout << "�^�X�N�Ǘ��V�X�e��" << endl << endl;
		cout << "���삵�������e��I��ł�������" << endl;
		cout << "1 : �S���ґ���" << endl;
		if (flag)cout << "2 : �^�X�N����" << endl;
		cout << "0 : �I��" << endl;
		cin >> decision;
		cout << endl;
		while (!(decision >= 0 && decision <= decisionMax))
		{
			cout << "���삪���݂��܂���" << endl;
			cout << "�ē��͂��Ă�������" << endl;
			cout << "1 : �S���ґ���" << endl;
			cout << "2 : �^�X�N����" << endl;
			cout << "0 : �I��" << endl;
			cin >> decision;
			cout << endl;
		}
		std::system("cls");
		if (decision == 1)
		{
			cout << "�S���ҊǗ�" << endl << endl;
			cout << "���삵�������e��I��ł�������" << endl;
			cout << "1 : �S���҂̒ǉ�" << endl;
			cout << "2 : �S���҂̓��e�ύX" << endl;
			cout << "3 : �S���҂̍폜" << endl;
			cout << "4 : �S���҂�S�ĕ\��" << endl;
			cin >> decision;
			cout << endl;
			while (!(decision >= 1 && decision <= 4))
			{
				cout << "���삪���݂��܂���" << endl;
				cout << "�ē��͂��Ă�������" << endl;
				cout << "1 : �S���҂̒ǉ�" << endl;
				cout << "2 : �S���҂̓��e�ύX" << endl;
				cout << "3 : �S���҂̍폜" << endl;
				cout << "4 : �S���҂�S�ĕ\��" << endl;
				cin >> decision;
				cout << endl;
			}
			std::system("cls");
			if (decision == 1)
			{
				pm->AddPerson();
			}
			else if (decision == 2)
			{
				cout << "�S���҂̓��e�ύX" << endl << endl;
				cout << "���삵�������e��I��ł�������" << endl;
				cout << "1 : �S���҂̎����ύX" << endl;
				cout << "2 : �S���҂̏o�Ȕԍ��ύX" << endl;
				cout << "3 : �S���҂̃N���X�ύX" << endl;
				cout << "4 : �S���҂̑S�Ă̗v�f��ύX" << endl;
				cin >> decision;
				cout << endl;
				while (!(decision >= 1 && decision <= 4))
				{
					cout << "�S���҂̓��e�ύX" << endl << endl;
					cout << "���삵�������e��I��ł�������" << endl;
					cout << "1 : �S���҂̎����ύX" << endl;
					cout << "2 : �S���҂̏o�Ȕԍ��ύX" << endl;
					cout << "3 : �S���҂̃N���X�ύX" << endl;
					cout << "4 : �S���҂̑S�Ă̗v�f��ύX" << endl;
					cin >> decision;
					cout << endl;
				}
				std::system("cls");
				if (decision == 1)
				{
					pm->SetName();
				}
				else if (decision == 2)
				{
					pm->SetAttendance();
				}
				else if (decision == 3)
				{
					pm->SetClassName();
				}
				else if (decision == 4)
				{
					pm->SetAllChange();
				}
			}
			else if (decision == 3)
			{
				pm->DeletePerson();
			}
			else if (decision == 4)
			{
				pm->Draw();
			}
			pm->OutPut();
			cout << endl;
			cout << "�����̒S���ҏ�" << endl;
			pm->Draw();
			system("PAUSE");
		}
		else if (decision == 2)
		{
			cout << "�^�X�N�Ǘ�" << endl << endl;
			cout << "���삵�������e��I��ł�������" << endl;
			cout << "1 : �^�X�N�̒ǉ�" << endl;
			cout << "2 : �^�X�N�̓��e�ύX" << endl;
			cout << "3 : �^�X�N�̍폜" << endl;
			cout << "4 : �^�X�N��S�ĕ\��" << endl;
			cin >> decision;
			cout << endl;
			while (!(decision >= 1 && decision <= 4))
			{
				cout << "���삪���݂��܂���" << endl;
				cout << "�ē��͂��Ă�������" << endl;
				cout << "1 : �^�X�N�̒ǉ�" << endl;
				cout << "2 : �^�X�N�̓��e�ύX" << endl;
				cout << "3 : �^�X�N�̍폜" << endl;
				cout << "4 : �^�X�N��S�ĕ\��" << endl;
				cin >> decision;
				cout << endl;
			}
			std::system("cls");
			if (decision == 1)
			{
				tm->AddTask();
			}
			else if (decision == 2)
			{
				cout << "�^�X�N�̓��e�ύX" << endl << endl;
				cout << "���삵�������e��I��ł�������" << endl;
				cout << "1 : �^�X�N�̒S���҂̕ύX" << endl;
				cout << "2 : �^�X�N�̓��e�ύX" << endl;
				cout << "3 : �^�X�N�̏d�v�x�ύX" << endl;
				cout << "4 : �^�X�N�̊����ύX" << endl;
				cout << "5 : �^�X�N�̃X�e�[�^�X�ύX" << endl;
				cin >> decision;
				cout << endl;
				while (!(decision >= 1 && decision <= 5))
				{
					cout << "�^�X�N�̓��e�ύX" << endl << endl;
					cout << "���삵�������e��I��ł�������" << endl;
					cout << "1 : �^�X�N�̒S���҂̕ύX" << endl;
					cout << "2 : �^�X�N�̓��e�ύX" << endl;
					cout << "3 : �^�X�N�̏d�v�x�ύX" << endl;
					cout << "4 : �^�X�N�̊����ύX" << endl;
					cout << "5 : �^�X�N�̃X�e�[�^�X�ύX" << endl;
					cin >> decision;
					cout << endl;
				}
				std::system("cls");
				if (decision == 1)
				{
					tm->SetPIC();
				}
				else if (decision == 2)
				{
					tm->SetContent();
				}
				else if (decision == 3)
				{
					tm->SetPriority();
				}
				else if (decision == 4)
				{
					tm->SetDeadLine();
				}
				else if (decision == 5)
				{
					tm->SetStatus();
				}
			}
			else if (decision == 3)
			{
				tm->DeleteTask();
			}
			else if (decision == 4)
			{
				tm->Draw();
			}
			tm->OutPut();

			cout << endl;
			cout << "�����̃^�X�N��" << endl;
			tm->Draw();
			system("PAUSE");
		}
	}
	system("PAUSE");
}