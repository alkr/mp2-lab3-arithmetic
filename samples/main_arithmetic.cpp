#include "arithmetic.h"
vector <string> str;
vector <string>::iterator qq;
int main()
{
	string::iterator pp;
string s,www;
cin>>s;
raz(s,str);
char tt='+';
for (qq=str.begin();qq<str.end();qq++)
 cout<<*qq<<endl; 
cin>>s;
cout<<dob(s)*2;
int i;
cin>>i;
  return 0;
}