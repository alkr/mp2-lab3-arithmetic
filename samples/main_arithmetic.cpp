#include "arithmetic.h"
vector <string> str;
vector <string>::iterator qq;
int main()
{
string s;
cin>>s;
raz(s,str);
for (qq=str.begin();qq<str.end();qq++)
     cout<<*qq<<endl;
int i;
cin>>i;
  return 0;
}