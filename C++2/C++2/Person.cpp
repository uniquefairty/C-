#if 0
#include "Person.h"
#include<iostream>
using namespace std;
void Person::SetPersonInfo(char *name, char *gender, int age)
{
	strcpy(_name, name);
	strcpy(_gender, gender);
	_age = age;
}
void Person::PrintfPerson()
{
	cout << _name << ": " << _gender << " :" << _age << endl;
}

//���г�Ա���������涨��������������
#endif