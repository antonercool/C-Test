#pragma once
#include <string>
using namespace std;

class Student
{

private:
    int _age;
    string _name;

public:
    void PrintName();
    Student(int age = 0, string name = "hello");

};
