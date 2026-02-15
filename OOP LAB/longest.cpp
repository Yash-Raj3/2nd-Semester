#include<iostream>
using namespace std;
int main(){
char str[300];
int count[50];
cout<<"Enter String: ";
cin.getline(str,300);
int i =0;
int k;
int le=0;
int maxl =0;
char word[50];
char longest [50];
while(1){
	if(str[i] != ' ' && str[i] != '\0'){
		word[le++] = str[i];
		
	}else{
		word[le] = '\0';
		if(le > maxl){
			maxl = le;
			k =0;
			while(word[k] != '\0'){
				longest[k]  = word[k];
				k++;
			}
			longest[k] = '\0';
			
		}
		le =0;
	}
	if(str[i]== '\0'){
		break;
	}
	i++;
}

cout<<"Longest Word: "<<longest<<endl;
cout<<"Length: "<<maxl;

	
}
