#include <iostream>
using namespace std; // This is the practice of deep copy;
class student
{
public:
	string Name;
	int *rollnoptr;
	float *Marks;
	student(string Name, int rollno, float Mark)
	{
		this->Name = Name;
		Marks = new float;
		*Marks = Mark;
		rollnoptr = new int;
		*rollnoptr = rollno;
	}
	// student(student &s)
	// {
	// 	this->Name = s.Name;
	// 	rollnoptr = new int;
	// 	*rollnoptr = *s.rollnoptr;
	// 	Marks = new float;
	// 	*Marks = *s.Marks;
	// }
	void print()
	{
		cout << Name << endl
			 << *Marks << endl
			 << *rollnoptr << endl;
	}
};
int main()
{
	student s1("Yash", 1234, 84);
	s1.print();
	student s2(s1);
	(*s2.rollnoptr) = 3234;
	(*s2.Marks) = 23.23;
	s1.print();
	s2.print();
}
