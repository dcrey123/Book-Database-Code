#ifndef REY00001_HW11EC_HPP
#define REY00001_HW11EC_HPP
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

class Book{	
public:	
	Book();											
	Book(string,string,string,int,int,string);
	
	void setId(string id);
	string getId() const;
	
	void setAuth(string a);
	string getAuth() const;
	
	void setTitle(string t);
	string getTitle() const;
	
	void setEd(int e);
	int getEd() const;
	
	void setYr(int yr);
	int getYr() const;
	
	void setIsbn(string is);
	string getIsbn() const;
						
	friend ostream& operator<< (ostream& os, Book& d);
	
	friend int getInput(Book list[], int &i);			
	friend void add(Book list[], int &i);
	friend void find(Book list[], int i);
	friend void display(Book list[], int i);				 
	friend void sort(Book list[], int i, int res);
	friend int bsearch(Book list[], int i, int res, string key); //for string variables
	friend int bsearch(Book list[], int i, int res, int key);	//for int variables
	friend void del(Book list[], int &i, int location);
	friend void quit(Book list[], int i);
	
private:
	string ident;											
	string author;
	string title;
	int edition;
	int year;
	string isbn;
};

#endif
