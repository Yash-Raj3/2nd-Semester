#include<iostream>
using namespace std;
class Matrix{
	int m,n;
	int matrix[20][20];
	public:
		Matrix(int m,int n):m(m),n(n){}
		void input(){
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					cout<<"Enter Element "<<i<<" "<<j<<": ";
					cin>>matrix[i][j];
				}
			}
		}
		Matrix operator + (Matrix other){
			Matrix m3(m,n);
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					m3.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
				}
			}
			return m3;
		}
		void display(){
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					cout<<matrix[i][j]<<"\t";
				}
				cout<<endl;
			}
			
		}
};
int main(){
	Matrix m1(2,2);
	Matrix m2(2,2);
	m1.input();
	m2.input();
	Matrix	m3 = m1+m2;
	cout<<"----Results----"<<endl;
	m3.display();
}
