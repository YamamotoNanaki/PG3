#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(unsigned int personID, std::string name, unsigned short attendanceNum, std::string className)
	:personID(personID), name(name), attendanceNum(attendanceNum), className(className) {}

void Person::SetName(std::string name)
{
	cout << "���O�� " << this->name << " ���� " << name << " �ɕύX���܂���" << endl << endl;
	this->name = name;
}

void Person::SetAttendanceNum(unsigned short attendanceNum)
{
	cout << "�o�Ȕԍ��� " << this->attendanceNum << " ���� " << attendanceNum << " �ɕύX���܂���" << endl << endl;
	this->attendanceNum = attendanceNum;
}

void Person::SetClassName(std::string className)
{
	cout << "�N���X�� " << this->className << " ���� " << className << " �ɕύX���܂���" << endl << endl;
	this->className = className;
}

unsigned int Person::GetID()
{
	return personID;
}

void Person::Draw()
{
	cout << className << "_" << attendanceNum << "_" << name << endl;
}

void Person::DrawID()
{
	cout << personID << " : ";
	Draw();
}

void Person::OutPut(ofstream& writing_file)
{
	writing_file << "id" << endl << personID << endl;
	writing_file << "class" << endl << className << endl;
	writing_file << "attendance" << endl << attendanceNum << endl;
	writing_file << "name" << endl << name << endl << endl;
}
