#ifndef ARITHMETIC_H
#define ARITHMETIC_H
#include "stack.h"
#include <iostream> 
#include <vector>
#include <iterator>
#include <string>
#define pb push_back
#define MAX 30
using namespace std;

void raz(string s,vector<string> &str);
bool prior(char a, char b);
double dob(string tt); 
double opol(vector<string> polz);
void pol(vector<string> str, vector<string> &polz);
#endif