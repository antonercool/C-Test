#include <iostream>
#include "student.hpp"
#include <array>
#include <map>
#include <string>
#include "data.hpp"
using namespace std;
using namespace MyData;

// Prototype s2 function
Student s2();
Student *s2Ptr();

int main()
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


    //C++11 INITIALISATION
    int i = 42.0;
    
    int i_default{}; /* = 0 */

    int i_value{42}; // 42

    //int i_undefined; // undefined // some high number

    //int i_narrowing_conversion_error{4.2}; /* Not ok */ casting double to int

    int i_narrowing_conversion(4.2); /* Ok */

    cout << "i = " << i << " + i_default =  " << i_default << "+ i_value = " << i_value <<" +  i_narrowing_conversion = " << i_narrowing_conversion << endl;


    // C++11 INITIALISATION
    //int v[] {1,2,3,4}; // auto size
     
    // initializer_list<> - a new feature
    array<int, 5> a { 1,2,3,4,5};
    string s {'t','h','r','e','e'};
    map<int, std::string> m {{1, "hello"}, {2, "world"}};

    cout << "Test array [0]: " <<  a[0] << endl;    


    Data dataTest {1,2,3,4,5};
    list<int>::iterator it;            

    int elementCounter = 0;
    for (it=dataTest._list.begin(); it !=dataTest._list.end(); it++)
    {
        cout << "Element : " << elementCounter << " : "<< *it << endl;
        elementCounter++;
    }
    
    
    cout << "\n ALLOCATED ON HEAP TESTS" << endl;

    //HEAPS (!!!!REMEMBER DELETE!!!!)
    //Default constructor // gets allocated on heap
    Student *s0Ptr = new Student;

    //strange quirk of the language // Calls a function named s2Ptr, which returns a Student*, pointing to the heap (Null ptr?)
    Student *s1Ptr = s2Ptr();

    // Implicit constructor to create Student on the heap
    Student *s2Ptr = new Student(53, "Ganton");

    (*s0Ptr).PrintName();
    (*s1Ptr).PrintName();
    (*s2Ptr).PrintName();

    delete s0Ptr;
    delete s1Ptr;
    delete s2Ptr;

    cout << "Good!, you remembered not to leak memory" << endl;

    return 0;
}

Student s2()
{
    Student someOne;
    return someOne;
}

Student *s2Ptr()
{
    Student *someOne = new Student(123123, "HelloThere");
    return someOne;
}