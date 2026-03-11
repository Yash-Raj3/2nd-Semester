#include<iostream>
using namespace std;
class Media
{
protected:
    string title;
    

public:
    Media(string t)
    {
        title = t;
      
    }

    void displayMedia()
    {
        cout << "Title: " << title << endl;
       
    }
};
class Book : public Media
{
private:
    string author;

public:
    Book(string t,string a) : Media(t)
    {
        author = a;
    }

    void displayBook()
    {
        displayMedia();   
        cout << "Author: " << author << endl;
    }
};
class Video : public Media
{
private:
    string resolution;
    float duration;

public:
    Video(string t, float d,string r) : Media(t)
    {
        resolution = r;
        duration =d;
    }

    void displayVideo()
    {
        displayMedia();  
        cout<<"Duration: "<<duration<<endl;
        cout << "Resolution: " << resolution << endl;
    }
};
class Audio : public Media
{
private:
    string format;
    float duration;

public:
    Audio(string t, float d, string f) : Media(t)
    {
        format = f;
        duration = d;
    }

    void displayAudio()
    {
        displayMedia();  
         cout<<"Duration: "<<duration<<endl;
        cout << "Format: " << format << endl;
    }
};

int main()
{
    Book b("Killer Hive", "Monet");
    Video v("OOP Lecture", 60, "1080p");
    Audio a("Podcast", 45, "MP3");

    cout << "\n--- Book ---" << endl;
    b.displayBook();

    cout << "\n--- Video ---" << endl;
    v.displayVideo();

    cout << "\n--- Audio ---" << endl;
    a.displayAudio();

}
