#ifndef TSTACK_H
#define TSTACK_H
#define ransize 10;
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
	int size() { return Size; }
	void pop();
	bool empty();
	bool full();		
	void push(const type& n);  
	type get();
	  
};
#endif;