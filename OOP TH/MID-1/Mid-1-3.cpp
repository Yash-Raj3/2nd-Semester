#include<iostream>
using namespace std;
class Furniture{
	string type;
	int quantity;
	public:
Furniture(){
	type ="";
	quantity = 0;
}
Furniture(string t,int q){
	type = t;
	quantity = q;
}
	void display(){
		cout<<"Furniture Type: "<<type<<endl<<"Quantity: "<<quantity<<endl;
	}
};
class student{
	int sid;
	string name;
	string department;
	public:
	student(int id,string name,string department){
		this ->name = name;
		sid =  id;
		this -> department = department;
	}
	int getId(){
		return sid;
	}
	void display(){
		cout<<"Name: "<<name<<" || ID: "<<sid<<" || Department: "<<department<<endl;
	}
};
class Room{
	int roomNo;
	int MaxCap;
	int currStudents;
	
	student *students[4];
	Furniture bed;
	Furniture table;
	Furniture chair;
	public:
	Room(int rno,int cap):roomNo(rno),MaxCap(cap),currStudents(0),bed("BED",cap),table("TABLE",cap),
	chair("CHAIR",cap){
		cout<<"ROOM CREATED!"<<endl;
	}
		
	
	void addStudent(student &s){
		if(currStudents >= MaxCap){
			cout<<"Room is FULL!"<<endl;
			return;
		}else{
			students[currStudents] = &s;
			currStudents++;
			cout<<"Student Added!!"<<endl;
		}
		
	}
	void removeStudent(int stid){
		for(int i=0;i<currStudents;i++){
			if(students[i]->getId() == stid){
				for(int j=i;j<currStudents-1;j++){
					students[j] = students[j+1];
				}
				currStudents--;
				cout<<"Student with ID "<<stid<<" Removed!"<<endl;
				return;
			}
		}
		cout<<"Student Not Found!"<<endl;
	}
	void displayInfo(){
		cout<<"====ROOM INFORMATION===="<<endl;
		cout<<"Room No: "<<roomNo<<endl;
		cout<<"Max Capacity: "<<MaxCap<<endl;
		cout<<endl;
		cout<<"====Furniture Information===="<<endl;
		bed.display();
		table.display();
		chair.display();
		cout<<endl;
		cout<<"====Student Information===="<<endl;
		if(currStudents == 0){
			cout<<"Room is Empty!"<<endl;
			return;
		}else{
		for(int i=0;i<currStudents;i++){
			students[i]->display();
		}
		}
		
	}
};
int main(){
	student s1(101, "Ali", "Computer Science");
    student s2(102, "Sara", "Software Engineering");
    student s3(103, "Ahmed", "Electrical Engineering");
    student s4(104, "Hina", "Business");
    student s5(105, "Usman", "AI");
    
    Room r1(12,4);
    r1.addStudent(s1);
    r1.addStudent(s2);
    r1.addStudent(s3);
    r1.addStudent(s4);
    r1.addStudent(s5);
    
    r1.removeStudent(102);
    r1.addStudent(s5);
    r1.displayInfo();
	
}
