#pragma once
#include <string>

class Person
{
private:
	unsigned int personID;
	std::string name;
	unsigned short attendanceNum;
	std::string className;
public:
	Person(unsigned int personID, std::string name, unsigned short attendanceNum, std::string className);
	void SetName(std::string name);
	void SetAttendanceNum(unsigned short attendanceNum);
	void SetClassName(std::string className);
	unsigned int GetID();
	void Draw();
	void DrawID();
};

