#include "arithmetic.h"
vector <string> str;
vector <string> polz;
vector <string>::iterator qq;
int main()
{
	string::iterator pp;
string s;
cin>>s;
raz(s,str);
for (qq=str.begin(); qq<str.end(); qq++)
cout<<*qq<<" ";
pol(str,polz);
cout<<opol(polz);

int i;
cin>>i;
  return 0;
}