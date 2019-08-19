#include <iostream>
#include "student.hpp"
using namespace std;

// Prototype s2 function
Student s2();
Student *s2Ptr();

main()
{

    cout << "ALLOCATED ON STACK TESTS" << endl;
    //Stack
    //Default constructor // gets allocated on stack
    Student s0;

    //strange quirk of the language // Calls a function named s2, which returns a Student on the stack
    Student s1 = s2();

    // Implicit constructor // stack
    Student s2(42, "Tom");

    s0.PrintName();
    s1.PrintName();
    s2.PrintName();


    cout << "\n ALLOCATED ON HEAP TESTS" << endl;
   

    //HEAPS (!!!!REMEMBER DELETE!!!!)
    //Default constructor // gets allocated on heap   
    Student* s0Ptr = new Student;
    
    //strange quirk of the language // Calls a function named s2Ptr, which returns a Student*, pointing to the heap (Null ptr?)
    Student* s1Ptr = s2Ptr();

    // Implicit constructor to create Student on the heap
    Student* s2Ptr = new Student(53, "Ganton");

    (*s0Ptr).PrintName();
    (*s1Ptr).PrintName();
    (*s2Ptr).PrintName();


    delete s0Ptr;
    delete s1Ptr;
    delete s2Ptr;

    cout << "Good!, you remembered not to leak memory" << endl;
}

Student s2()
{
    Student someOne;
    return someOne;
}

Student *s2Ptr()
{
    Student* someOne = new Student(123123, "HelloThere");
    return someOne;
}