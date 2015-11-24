#include <gtest.h>
#include "arithmetic.h"

TEST(arithmetic, NUM_1) {
	vector<string> str,polz;
	string s;
	s="1+1";
    raz(s,str);
	pol(str,polz);
	double t=opol(polz);

EXPECT_EQ(2,t);
}

TEST(arithmetic, NUM_2) {
	vector<string> str,polz;
	string s;
	s="2*1";
    raz(s,str);
	pol(str,polz);
	double t=opol(polz);

EXPECT_EQ(2,t);
}

TEST(arithmetic, NUM_3) {
	vector<string> str,polz;
	string s;
	s="1+2*3-3*1+12";
    raz(s,str);
	pol(str,polz);
	double t=opol(polz);

EXPECT_EQ(16,t);
}

TEST(arithmetic, NUM_4) {
	vector<string> str,polz;
	string s;
	s="(4+1)*5";
    raz(s,str);
	pol(str,polz);
	double t=opol(polz);

EXPECT_EQ(25,t);
}

TEST(arithmetic, NUM_5) {
	vector<string> str,polz;
	string s;
	s="2+(12-30/6)*2";
    raz(s,str);
	pol(str,polz);
	double t=opol(polz);

EXPECT_EQ(16,t);
}

TEST(arithmetic, NUM_6) {
	vector<string> str,polz;
	string s;
	s="9/2+5-3*(1+2)";
    raz(s,str);
	pol(str,polz);
	double t=opol(polz);

EXPECT_EQ(0.5,t);
}

TEST(arithmetic, NUM_7) {
	vector<string> str,polz;
	string s;
	s="99-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-1+2*2*(3*1+2*2*1)+10/2/5";
    raz(s,str);
	pol(str,polz);
	double t=opol(polz);

EXPECT_EQ(100,t);
}