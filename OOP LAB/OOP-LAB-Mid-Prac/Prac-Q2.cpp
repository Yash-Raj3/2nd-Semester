#include<iostream>
using namespace std;
class MenuItem{
	public:
		string name;
		double price;
	MenuItem(){
		name ="";
		price =0.0;
	}
	MenuItem(string name,double price){
		this->name = name;
		this->price =price;
	}
};

class Order{
	int id;
	MenuItem items[3];
	int itemC;
	public:
		Order():id(0){
			
			itemC=0;
		}
		Order(int id):id(id){
			itemC = 0;
		}
		void addItem(MenuItem i){
			if(itemC < 3){
				items[itemC++] = i;
			}else{
				cout<<"Can't add more!!"<<endl;
			}
			
		}
		double CalculateOrderTotal(){
			double total=0;
			for(int i=0;i<itemC;i++){
				total += items[i].price;
			}
			return total;
		}
		
		void displayOrder() const{
			cout<<"Order ID: "<<id<<endl;
			for(int i=0;i<itemC;i++ ){
				cout<<"Name: "<<items[i].name<<", Price: "<<items[i].price<<"$"<<endl;
			}
		}
};
class Table{
	int Tnumber;
	Order orders[4];
	int orderC;
	public:
		Table(){
			Tnumber = 0;
			orderC =0;
		}
		 Table(int tnum):Tnumber(tnum){
		 	orderC = 0;
		 }
		 void addOrder(Order o){
		 	if(orderC < 4){
		 		orders[orderC++] = o;
			 }else{
			 	cout<<"You already have ordered 4 orders! Can't Add More"<<endl;
			 }
		 }
		 double calculatetotalcost() {
		 	double totalbill=0;
		 	for(int i=0;i<orderC;i++){
		 		totalbill += orders[i].CalculateOrderTotal();
			 }
			 return totalbill;
		 }
		 void displayTableinfo(){
		 	cout<<"\n====AL SAJJAD RESTAURANT====\n";
		 	cout<<"Table Number: "<<Tnumber<<endl;
		 	for(int i=0;i<orderC;i++){
		 		cout<<"====Order Number "<<i+1<<" ====\n";
		 		orders[i].displayOrder();
			 }
			 cout<<"=======================\n";
		 	cout<<"Total Bill: "<<calculatetotalcost()<<"$"<<endl;
		 	cout<<"---------Thank You---------\n";
		 	
		 }
		 
};
int main(){
	Table t1(101);
	Order o1(21);
	Order o2(22);
	MenuItem i1("Burger",2.5);
	MenuItem i2("Fries",3.2);
	o1.addItem(i1);
	o1.addItem(i2);
	o2.addItem(i1);
	o2.addItem(i2);
	t1.addOrder(o1);
	t1.addOrder(o2);
	t1.displayTableinfo();
	
}
