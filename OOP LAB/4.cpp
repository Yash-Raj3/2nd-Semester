#include <iostream>
using namespace std;
class Student{
	private:
		float cgpa;
	public:
		void setCgpa(float c){
		if(c > 4.0){
			cout<<"Invalid! Must be Under 4.0"<<endl;
		}else if(c < 0){
			cout<<"Must be Positive"<<endl;
		}else{
			cgpa = c;
		}
	}
		void  getCgpa(){
			cout<<"Cgpa: "<<cgpa;
		}
};
int main(){
	Student s1;
	s1.setCgpa(3.8);
	s1.getCgpa();
}
    

