#include "arithmetic.h"




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
		  if (((*e-'0')>-1 && (*e-'0')<10)||(*e=='.'))
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



void pol(vector<string> str, vector<string> &polz)
{   
	stack<char> st(40);
	vector<string>::iterator qq;
	for (qq=str.begin(); qq<str.end(); qq++)
	{    
		string ww=*qq;
		if(*(ww.begin())=='(')
			st.push(*ww.begin()); else {
		if ((*(ww.begin())=='*')||(*(ww.begin())=='+')||(*(ww.begin())=='/')||(*(ww.begin())=='-'))
			{   
				if (st.empty())
		        st.push(*ww.begin());
				else 

				{	char t=st.get();
				   while((prior(t,*ww.begin()))&&(!st.empty()))
				   {
						string hh;
						hh.pb(t);
						polz.pb(hh);
						t=st.get();
				   }
				   if(st.empty())
				   {  
					   if(prior(t,*ww.begin()))
					   {string hh;
						hh.pb(t);
						polz.pb(hh);
						st.push(*ww.begin());}
					   else
					   {st.push(t); st.push(*ww.begin()); }
				   }
				   else 
				   {st.push(t); st.push(*ww.begin()); }}
		}
		else 
		{
			if (*(ww.begin())==')')
			{  
				char h='~';
			 while (h!='(')
			  {  h=st.get();
				  string hh;
			   hh.pb(h);
				  polz.pb(hh);
					}
			 polz.pop_back();}
			else 

				polz.pb(ww); }
		}}


	 while (st.empty()==false)
	{   
		char cc=st.get();
		string hhh;
		hhh.pb(cc);
		polz.pb(hhh);
	} 

}




double opol(vector<string> polz)
{
	vector<string>::iterator qq;
    stack<double> st(MAX);
	double l,r;
	for (qq=polz.begin(); qq<polz.end(); qq++)
	{
		string ww=*qq;
		if((*ww.begin()-'0'<10) && (*ww.begin()-'0'>=0))
			st.push(dob(ww));
		else 
		{ if ((*ww.begin()!='+')&&(*ww.begin()!='-')&&(*ww.begin()!='*')&&(*ww.begin()!='/')&&(*ww.begin()!='('))
		{cout<<"Vvedite znachenie peremennoy "<<ww<<endl;
		     double a;
			 cin>>a;
			 st.push(a);
		}}
		if (*ww.begin()=='+')
		{  
			l=st.get();
			r=st.get();
			l+=r;
			st.push(l);
		}

    if (*ww.begin()=='-')
		{  
			r=st.get();
			l=st.get();
			l-=r;
			st.push(l);
		}

	if (*ww.begin()=='*')
		{  
			l=st.get();
			r=st.get();
			l*=r;
			st.push(l);
		}

	if (*ww.begin()=='/')
		{  
			r=st.get();
			l=st.get();
			l/=r;
			st.push(l);
         }
	}
return st.get();
} 



double dob(string tt)
{  string::iterator qq;
   int k=0;
    double m=1.0;
    double ans=(double)(*tt.begin()-'0');
	for (qq=tt.begin()+1;qq<tt.end(); qq++)
	{if (*qq=='.')
	    k=1;
	else  
	{if (k==0)
		{ ans*=10.0;
	ans+=(double)(*qq-'0');}
	   else 
		{   m*=10.0;
			ans+=(double)(*qq-'0')/m;
	}}}
	return ans;
	}

bool prior(char a, char b)
{
	int k=0;
	if ((a=='*' || a=='/')&& (b=='+' || b=='-')) k++;
	if (a=='*' && b=='/') k++;
	if (a=='+' && b=='-') k++;
	if (a=='/' && b=='*') k++;
	if (a=='-' && b=='+') k++;
	if (a=='-' && b=='-') k++;
	if (a=='+' && b=='+') k++;
	if (a=='*' && b=='*') k++;
	if (a=='/' && b=='/') k++;
    if ((a=='*' || a=='/' || a=='+' || a=='-')&& (b=='(')) k++;
	return (k==0)?false:true;
} 