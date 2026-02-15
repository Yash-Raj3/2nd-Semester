#include<stdio.h>
#include<string.h>
void Longest(char str[5][100]){
char *longest = str[0];
 	int  Max = strlen(str[0]);
	for(int i=0;i<5;i++){
		int Count = 0;
		for(int j=0;str[i][j]!='\0';j++){
		Count++;
		}
		if(Count > Max){
			Max =  Count;
			longest = str[i];
		}
	}
		printf("%s Word is Longest\n",longest);
	
	
}
int main(){
	char Str1[5][100];
		int n = 5;
	printf("Enter Five Words-\n");
	for(int i=0;i<n;i++){
		printf("Enter %d Word: ",i+1);
		scanf(" %[^\n]",Str1[i]);
	}
	Longest(Str1);
	
}
