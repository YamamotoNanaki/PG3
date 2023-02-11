#pragma once
#include <list>
#include <vector>
#include <memory>
#include "Person.h"

class PersonManager
{
private:
	std::list<std::unique_ptr<Person>> people;
	std::vector<bool>nextID;
	PersonManager() {};
	~PersonManager();
public:
	PersonManager(const PersonManager& obj) = delete;
	PersonManager operator=(const PersonManager& obj) = delete;
	static PersonManager* GetInstance();
	void AddPerson();
	void SetName();
	void SetAttendance();
	void SetClassName();
	void SetAllChange();
	void Draw();
	void Draw(unsigned int PICID);
	void DrawID();
	bool IDCheck(unsigned int PIC);
	void DeletePerson();
	size_t GetPeopleSize();
};

