#include <iostream> 
#include <vector>
#include <iterator>
#include <string>
#define pb push_back
using namespace std;
 vector <string> str;
 vector <string>::iterator qq;
 void raz(string s)
 { 
 string smin;  int k=-1;
 string::iterator e;
 vector<string>::iterator w;

 for (e=s.begin();e<s.end();e++)
 {
      if (*e=='-')
         { if (k<0)  {
                 string t;
                 t.pb('0');
                 str.pb(t); 
                 t.clear();
                 t.pb(*e); 
                 str.pb(t);
                 k=-1; }
                 else 
                  { if (!smin.empty()) str.pb(smin); 
                 k=-1;  
                 string t; 
                 t.pb(*e); 
                 str.pb(t); 
                 smin.clear();}
                 } else {
      if ((*e=='(')||(*e==')')||(*e=='*')||(*e=='+')||(*e=='/'))
         {if(k>0)
      {   if (!smin.empty()) str.pb(smin); 
                 k=-1;  
                 string t; 
                 t.pb(*e); 
                 str.pb(t); 
                 smin.clear();}
            else 
            {   string t;
                t.pb(*e);
                str.pb(t); }}
      else 
      {  if ((*e-'0')>-1 && (*e-'0')<10)
                      { if(k==1)
                          smin.pb(*e); else 
                          { k=1; 
                          if (!smin.empty())  str.pb(smin); 
                          smin.clear();
                          smin.pb(*e);}}
           else  
                 { if(k==2)
                          smin.pb(*e); else 
      { k=2;
        if (!smin.empty())  str.pb(smin); 
        smin.clear();  
        smin.pb(*e);}}
      }   

 }}
 if (!smin.empty())  str.pb(smin);
 smin.clear();
 }
 
 
 
 void main()
 { string s;
 cin>>s;
 raz(s);
 for (qq=str.begin();qq<str.end();qq++)
     cout<<*qq<<endl;
     }