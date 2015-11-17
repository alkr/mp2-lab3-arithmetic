#include "stack.h"

template <class type>
stack<type>::stack(int size)
{  if(size<0) throw invalid_argument("--");
     else
	 {
		 ast = new type[size];
		 for (int i=0;i<size;i++)
				 ast[i]=0;
		 Max=-1; 
		 Size=n;
     
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
		throw invalid argument("--");
	else {
		Max++;
		ast[Max]=n;
		}
}
template <class type>
type stack<type>::get(int &n) 
{  
	if ((n<Max -1)&&(n>=0))
		throw invalid argument("--");
	else 
		return ast[n];
}
template <class type>
void stack<type>::pop()
{   if (Max==-1) throw invalid_argument("--");
else 
	Max--;
}

template <class type>
type stack<type>::getlast()
{
  if (Max== -1)
		throw invalid argument("--");
	else  
	{ return ast[Max];
        if (Max==-1) throw invalid_argument("--");
          else 
	     Max--;
	}

}