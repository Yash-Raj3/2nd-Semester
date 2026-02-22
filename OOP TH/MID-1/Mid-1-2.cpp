#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class game{
	static int  highscores[3];
	static string highscorers[3];
	
	string name;
	int score;
	public:
		game():score(0),name("Player1"){}
		game(string n){
			score =0;
			if(n == ""){
				name="Player1";
			}else{
				 name = n;
			}
		}
	static void displayScore(){
		for(int i=0;i<3;i++){
			cout<<i+1<<". "<<"Name: "<<highscorers[i]<<"|| Score: "<<highscores[i]<<endl;
		}
	}
	void playgame(){
		score = rand() % 9000+1000;
		cout<<name<<" Scored "<<score<<endl;
		
		for(int i=0;i<3;i++){
			if(score > highscores[i]){
				for(int j=2 ;j>i;j--){
					highscores[j] = highscores[j-1];
					highscorers[j] = highscorers[j-1];
				}
			highscores[i] = score;
			highscorers[i] = name;
			break;
			}
		}
	}
};
string game::highscorers[3] = {"Abeeha","Bakhtawar","Nizam"};
int game::highscores[3] ={ 9999, 8888, 7777 };
int main(){
	srand(time(0));
	
	game p1("XYZ");
	p1.displayScore();
	p1.playgame();
	p1.displayScore();
	
	
	
	
}
