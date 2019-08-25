#include "student.hpp"
#include <iostream>

void Student::PrintName(){
    cout << "Hello what up my name is: " << _name << ", and my age is: " << _age << endl;
}

Student::Student(int age, string name){
    this->_age = age;
    this->_name = name;
}

