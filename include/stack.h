#ifndef TSTACK_H
#define TSTACK_H
#define ransize 30
#include <iostream>
using namespace std;

template <class type>
class stack
{   protected :
    type *ast;
	int Max;
	int Size;
			
public:
	stack();
	stack(int size);
	~stack();
	stack(const stack &st);
	stack& operator=(const stack &st);
	bool operator==(const stack &st);
	bool operator!=(const stack &st);
	int size() { return Max+1; }
	type begin() ;
	bool empty();
	bool full();		
	void push(const type& n);  
	type get();
	  
};

template <class type>
type stack<type>::begin()
{
 return ast[0];
}

template <class type>
stack<type>::stack(int size)
{  if(size<0) throw invalid_argument("--");
     else
	 {
		 ast = new type[size];
		 for (int i=0;i<size;i++)
				 ast[i]=0;
		 Max=-1; 
		 Size=size;
     
	}
}

template <class type>
stack<type>::stack(const stack &st)
{  
  Size= st.size();
  Max=st.Max;
  ast=new type [Size];
  for(i=0;i<Size;i++)
	  ast[i]=st.ast[i];
}

template <class type>
stack<type>& stack<type>::operator =(const stack &st)
{
  if (ast==st.ast) return *this; 
  else 
  { 
	 delete []ast;
	 Size=st.size();
	 Max=st.Max;
	 ast=new type[Size];
	 for (int i=0;i<Size;i++)
		 ast[i]=st.ast[i];
	 return *this;
  }
}
template <class type>
stack<type>::stack()
{  Max=-1;
   Size=ransize;
   ast = new type[Size];
   for (int i=0;i<ransize;i++)
	   ast[i]=0;
}

template<class type>
stack<type>::~stack()
{
 delete []ast;
}

template <class type>
bool stack<type>::empty()
{
	return (Max<0)?true:false;
}

template <class type>
bool stack<type>::full()
{
	return (Max==Size-1)?true:false;
}

template <class type>
void stack<type>::push(const type& n) 
{  
	if (Max==Size -1)
		throw invalid_argument("--");
	else {
		Max++;
		ast[Max]=n;
		}
}

template <class type>
type stack<type>::get()
{
  if (Max== -1)
		throw invalid_argument("--");
	else  
	{   
		return ast[Max--];
	     
	}

}

template <class type>
bool stack<type>::operator==(const stack &st)
{
	if((Size!=st.Size)||(Max!=st.Max)) return false; 
	else 
	{
       bool t=true;
      for (int i=0;i<Size;i++)
		  if(ast[i]!=st.ast[i])
		  {t=false; break;}
        return t;
	}
}

template <class type>
bool stack<type>::operator!=(const stack &st)
{ 
	return((*this)==st)?false:true;
}
#endif