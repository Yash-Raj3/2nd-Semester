#include<iostream>
using namespace std;
class Member{
	private:
	const int memberId;
	string name;
	int NumOfTSession;
	static int totalMember;
	static int tNumOfTSession;
	public:
		Member(int id,string name,int session):memberId(id),name(name),NumOfTSession(session){
			totalMember++;
			tNumOfTSession += session;
		}
		int SessionsAttended()const{
			return NumOfTSession;
		}
		void displayMember(){
			cout<<"ID: "<<memberId<<", Name: "<<name<<", Sessions Attended: "<<SessionsAttended()<<endl;
			
		}
		static void DisplayData(){
			cout<<"Total Members: "<<totalMember<<endl;
			cout<<"Total Sessions Attended: "<<tNumOfTSession<<endl;
		}
};
int Member::totalMember = 0;
int  Member::tNumOfTSession =0;
int main(){
	Member m1(201,"Yash",2);
	Member m2(202,"Harsh",5);
	Member m3(203,"Vinesh",3);
	
	m1.displayMember();m2.displayMember();m3.displayMember();
	Member::DisplayData();
	
	
	
	
}
