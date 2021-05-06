#pragma once

#include <iostream>
  //#include <string>
#include "MyString.h"  
using namespace std;

  // TextBook class 
  class TextBook
  {
  private:
	  MyString title;    // Book title 
	  MyString author;    // Author name 
	  MyString publisher; // Publisher name 
  public:
	  // The default constructor stores empty MyStrings 
		  // in the MyString objects. 
	  TextBook();

	  // Constructor 
	  TextBook(MyString textTitle, MyString auth, MyString pub);
	  TextBook(const TextBook&);

	  // set function 
	  void set(MyString textTitle, MyString auth, MyString pub);
	  void setTitle(MyString);
	  void setAuthor(MyString);
	  void setPublisher(MyString);

	  MyString getTitle()const;
	  MyString getAuthor()const;
	  MyString getPublisher()const;

	  // print function 
	  void print() const;

  };
