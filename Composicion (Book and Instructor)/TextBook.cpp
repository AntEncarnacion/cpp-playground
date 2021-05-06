#include <iostream>
using namespace std;
#include "MyString.h"
#include "TextBook.h"


TextBook::TextBook()
{
	setTitle("");
	setAuthor("");
	setPublisher("");
}

// Constructor 
TextBook::TextBook(MyString textTitle, MyString auth, MyString pub)
{
	setTitle(textTitle);
	setAuthor(auth);
	setPublisher(pub);
}

TextBook::TextBook(const TextBook& aTextbook)
{
	title = aTextbook.getTitle();
	author = aTextbook.getAuthor();
	publisher = aTextbook.getPublisher();
}

// set function 
void TextBook::set(MyString textTitle, MyString auth, MyString pub)
{
	title = textTitle;
	author = auth;
	publisher = pub;
}

void TextBook::setTitle(MyString aTitle)
{
	title = aTitle;
}

void TextBook::setAuthor(MyString aAuthor)
{
	author = aAuthor;
}

void TextBook::setPublisher(MyString aPublisher)
{
	publisher = aPublisher;
}

MyString TextBook::getTitle()const
{
	return this->title;
}

MyString TextBook::getAuthor()const
{
	return this->author;
}

MyString TextBook::getPublisher()const
{
	return this->publisher;
}


// print function 
void TextBook::print() const
{
	cout << "Title: " << title << endl;
	cout << "Author: " << author << endl;
	cout << "Publisher: " << publisher << endl;
}