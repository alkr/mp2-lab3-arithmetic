#include <arithmetic.h>

void raz(string s,vector<string> &str)
 {
 vector<string>::iterator qq;
 string smin;  int k=-1;
 string::iterator e; int z=0;
 vector<string>::iterator w;

 for (e=s.begin();e<s.end();e++)
 {
      if (*e=='-')
	  { if ((k<0)&&(z==0))  {
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
         {   if(*e=='(') z=0; else z=1;
			 if(k>0)
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
      {   z=1;
		  if ((*e-'0')>-1 && (*e-'0')<10)
                      { if(k==1)
                          smin.pb(*e); else 
                          { k=1; 
                          if (!smin.empty())  str.pb(smin); 
                          smin.clear();
                          smin.pb(*e);}}
           else  
		   {   z=1;
			   if(k==2)
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

