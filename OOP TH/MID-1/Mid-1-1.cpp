#include<iostream>
using namespace std;
class PicnicManagement {
	private:
		
	const int tTicket;
	const float tBudget;
	
	static int  ticketSold;
	static float remBudget;
	static string Students[30];
	static string Faculty[30];
	static int Scount;
	static int Fcount;
	
	public:
		PicnicManagement():Tticket(2000),tBudget(2000000){
		remBudget = tBudget;
		ticketSold = 0;
		}
		PicnicManagement(int Ticket,float budget):tTicket(Ticket>0? Ticket:2000),tBudget(budget>0?budget:2000000){
			remBudget = tBudget;
			ticketSold = 0;
		}
	static	int tickets(){
	return ticketSold;
	}
	static float Budget(){
		return remBudget;
	}
	int Ttickets()const{
	return tTicket;
	}
	float Tbudget()const{
	return tBudget;
	}
	static void addStudent(string name){
		if(Scount<30){
		Students[Scount++] = name;
		}
	}
	static void addFaculty(string name){
		if(Fcount<30){
		Faculty[Fcount++] = name;
		}
	}
	bool UtilizeFunds(string reason,float amount){
		if(amount <=  0 ){
			cout<<"Invalid Amount"<<endl;
			return false;
		}
		if(amount > remBudget){
			cout<<"Insufficient Amount"<<endl;
			return false;
		}else{
			remBudget -= amount;
		}
		cout<<"Amount Used: "<<amount<<"  for Reason: "<<reason<<" Remaining Amount: "<<Budget()<<endl;
	}
	int sellTicket(int amount){
		if(amount > 2){
			amount = 2;
		}
		if(amount<1){
			amount =1;	
		}
		int ticketrem = tTicket - ticketSold;
		if(ticketrem <=0){
			cout<<"All SOLD"<<endl;
			return amount;
		}
		
		if(amount > ticketrem){
			ticketSold += ticketrem;
			remBudget += ticketrem*1500;
			return amount - ticketrem;
		}
		
		ticketSold += amount;
		remBudget += amount*1500;
		return 0;
	}
};

int main(){
	
}
