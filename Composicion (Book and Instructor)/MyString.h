#pragma once
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_LEN = 80;

class MyString
{
private:
	char s[MAX_LEN + 1];
public:
	MyString(const char* s = "");
	MyString(char ch);
	MyString(const MyString& aMyString);
	~MyString();

	MyString& operator=(const char* s);
	MyString& operator=(char ch);
	MyString& operator=(const MyString& aMyString);

	void setS(const char* s);
	const char* getS() const;

	MyString operator+(const char* s) const;
	MyString operator+(char ch)const;
	MyString operator+(const MyString& aMyString)const;
	friend MyString operator+(const char* s, const MyString& aMyString);
	friend MyString operator+(char ch, const MyString& aMyString);

	friend istream& operator >>(istream& in, MyString& aMyString);
	friend ostream& operator <<(ostream& out, const MyString& aMyString);
	int len()const;
};