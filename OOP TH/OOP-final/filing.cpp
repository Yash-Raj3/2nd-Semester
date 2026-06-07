#include <fstream>
#include <iostream>

using namespace std;

int main() {
  char ch[10] = "Helllo";

  fstream file("hello.txt", ios::binary | ios::out);
  file.write(ch, 10);
  file.close();

  fstream file1("hello.txt", ios::binary | ios::in);
  char readCh[10];

  file1.read(readCh, 10);
  file1.close();

  for (int i = 0; readCh[i] != '\0'; i++) {
    cout << readCh[i];
  }
  cout << endl;
file.open("hello.txt",ios::binary|ios::out);
string s;
cout<<"Enter String: ";
getline(cin,s);
file.write(s.c_str(),s.size());
file.close();
file.open("hello.txt",ios::binary|ios::in);
char r[100] ={};
file.read(r,sizeof(r));
file.close();
cout<<r<<endl;
file.open("hello.txt",ios::binary|ios::out|ios::in);
file.seekp(4,ios::beg);
cout<<file.tellp()<<endl;
file.seekg(6,ios::beg);

streampos pos;
pos  = file.tellg();
cout<<pos;  

file.close();
}