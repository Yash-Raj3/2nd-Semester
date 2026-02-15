#include<iostream>
using namespace std;
class student{
	public:
		float *cgpa;
		string name;
		string *rollno;
		
		student(string n,string rn,float gpa){
			name = n;
			cgpa  = new float;
			*cgpa = gpa;
			rollno = new string;
			*rollno = rn;
		}
		student(student & s){
			name = s.name;
			cgpa = new float;
			*cgpa = *s.cgpa;
			rollno = new string;
			*rollno = *s.rollno;
		}
		void print(){
			cout<<name<<endl<<*cgpa<<endl<<*rollno<<endl;
		}
		
};
int main(){
	student s1("yash","25k-0878",3.8);
	s1.print();
	student s2(s1);
    *s2.cgpa = 4.2;
    *s2.rollno = "25k-0989";
    s2.print();
	
}
