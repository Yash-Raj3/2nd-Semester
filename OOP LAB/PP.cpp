#include<iostream>
using namespace std;
void encode(string str){
	int i  =0;
	while (str[i] != '\0'){
		if(!(str[0] >= '0' && str[0] <= '9')){
			cout<<"Not According to Pattern"<<endl;
			exit(0);
		}
		if(str[1] >= '0' && str[1]<= '9'){
			cout <<"Not according to pattern";
			exit(0);
		}
		
	}
	
	
}

int main(){
	
	string str;
	
	cout<<"Enter The String: ";
	getline(cin,str);
	encode(str);
	
}
