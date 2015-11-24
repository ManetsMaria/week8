#include <iostream>
#include <string.h>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

class Str
{
protected:
    char* string;
    int length_str;
public:
    Str():string(0), length_str(0) {}
    Str(char s) : length_str(1)
    {
	   string = new char[100];
	   string[0] = s;
    }
    Str(char *s)
    {
	string = new char[100];
	for (int i = 0; i < strlen(s); i++)
	{
		string[i] = s[i];
	}
	length_str = strlen(s);
    }
    Str (Str& s)
    {
        string = new char [s.length_str];
        length_str=s.length_str;
        for (int i=0; i<length_str; i++)
        string[i]=s.string[i];
    }
    void help()
    {
	 if (length_str == 0)
	 {
		cout << "no elements" << endl;
		return;
	 }
	 for (int i = 0; i < length_str; i++)
		cout << string[i];
	 cout << endl;
    }
    void clean()
    {
        length_str=0;
        string[0]='\0';
    }
    Str operator += (Str& s)
    {
     int k=length_str;
     length_str+=s.length_str;
     for (int i=k; i < length_str; i++)
		string[i] = s.string[i - k];
    }
    void operator=(Str& s)
    {
	 length_str = s.length_str;
	 for (int i = 0; i < length_str; i++)
		string[i] = s.string[i];
    }
     virtual void operator > (Str& s)
    {
	 int k=strcmp(string,s.string);
	 if (k==0)
     {
        cout<<"they are equal\n";
        return;
     }
     if (k>0)
        cout<<"1 is bigger\n";
     else
        cout<<"2 is bigger\n";
    }
    virtual ~Str()
    {
      if (string)
       delete [] string;
    }
};

 class StrDigits : public Str
 {
 public:
    StrDigits():Str() {}
    StrDigits(char s)
    {
      if (!isdigit(s))
        cout<<"mistake\n";
      Str();
    }
    StrDigits(int numb)
    {
	 string = new char[100];
	 char* time;
	 time = new char [100];
	 int i = 0;
	 while (numb != 0)
	 {
		time[i++] = numb % 10 + 48;
		numb /= 10;
	 }
	 length_str = i;
	 for (int i=0; i<length_str; i++)
        string[i]=time[length_str-i];
   }
   StrDigits(char *s): Str(s){}
   int convert()
   {
      int rez=atoi (string);
      return rez;
   }
   int addition (StrDigits& s)
   {
     return convert()+s.convert();
   }
   void operator > (StrDigits& s)
   {
     if (convert()==s.convert())
     {
        cout<<"they are equal\n";
        return;
     }
     if (convert()>s.convert())
        cout<<"1 is bigger\n";
     else
        cout<<"2 is bigger\n";
    }
    ~StrDigits() {}
 };

bool dig (char* s)
{
    for (int i = 0; i < strlen(s); i++)
		if (!isdigit(s[i])) return false;
	return true;
}

int main()
{
    Str *array[100];
    int summa=0;
    Str sum;
    int num;
    char time[100];
    cout<<"input number of string"<<endl;
    cin>>num;
    for (int i=0; i<num; i++)
      {
          cin>>time;
          if(dig(time))
          {
              array[i]= new StrDigits (time);
              StrDigits u (time);
              summa+=u.convert();
          }
          else
          {
              array[i]=new Str (time);
              Str u (time);
              sum+=u;
          }
      }
      sum.help();
      cout<<summa;
    return 0;
}
