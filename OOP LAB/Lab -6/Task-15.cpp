#include<iostream>
using namespace std;
class Person {
	
public:
void show() {
cout << "Person" << endl;
}
};
class Student :  public Person {};
class Employee :   public Person {};
class TeachingAssistant : public Student, public Employee{
	
};
/* error: Both base classes of  TA have same show() method. 
So, Compiler gets Dconfused while calling*/
int main(){
TeachingAssistant obj;
obj.Student::show();

}
