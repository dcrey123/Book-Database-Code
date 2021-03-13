#include "rey00001_hw11EC.hpp"
#include <string>

Book::Book(){
	ident = author = title = isbn = "";
	edition = year = 0;
}
Book::Book(string a, string b, string c, int d, int e, string f){
	ident = a;
	author = b;
	title = c;
	edition = d;
	year = e;
	isbn = f;
	
}

void Book::setId(string id){							//id
	ident = id;
}
string Book::getId() const{
	return ident;
}

void Book::setAuth(string a){							//author
	author = a;
}	
string Book::getAuth() const{
	return author;
}

void Book::setTitle(string t){							//title
	title = t;
}
string Book::getTitle() const{			
	return title;
}

void Book::setEd(int e){								//edition
	edition = e;
}	
int Book::getEd() const{
	return edition;
}

void Book::setYr(int yr){								//year
	year = yr;
}	
int Book::getYr() const{
	return year;
}

void Book::setIsbn(string is){							//isbn
	isbn = is;
}	
string Book::getIsbn() const{
	return isbn;
}
int getInput(Book list[], int &i){ // read in input file
	
	ifstream in;										
	//in.open("bookinput.dat"); // open file (original)
	in.open("bookinput_text.txt");
	if(in.fail()) // check if file exists
	{
		cout << "File does not exist ";
		return 1;
	}
	else {
	}
	
	string id, a, t, is;						
	int ed, yr;
	string line = "";
	
	while(getline(in,line)) // keep doing till end of file
	{
		int id_pos = line.find(",",0); // read in id
		id = line.substr(0,id_pos);

		int auth_pos = line.find(",",id_pos+2); // read in author
		a = line.substr(id_pos+2, auth_pos-id_pos-2);
		
		int title_pos = line.find(",",auth_pos+2); // read in title
		t = line.substr(auth_pos+2, title_pos-auth_pos-2);
		
		int ed_pos = line.find(",", title_pos+1); // read in edition
		ed = atoi(line.substr(title_pos+1,ed_pos-title_pos).c_str());
		
		int yr_pos = line.find(",", ed_pos+1); // read in year
		yr = atoi(line.substr(ed_pos+1,yr_pos-ed_pos).c_str());
		
		is = line.substr(yr_pos+2,line.length()-yr_pos); // read in isbn
		
		//store this line i at index i of list data structure
		list[i].setId(id);
		list[i].setAuth(a);
		list[i].setTitle(t);
		list[i].setEd(ed);
		list[i].setYr(yr);
		list[i].setIsbn(is);
		i++; // increment i here
	}
	in.close(); // close file
	return 0;
}

void add(Book list[], int &i){
	string id, a, t, is;						//local variables
	int ed, yr;
	string line = "";
	
	cout << "Enter the record, with items separated by a comma: " << endl;	
	cin.ignore();
	getline(cin,line);
	
	int id_pos = line.find(",",0);
	id = line.substr(0,id_pos);

	int auth_pos = line.find(",",id_pos+2);
	a = line.substr(id_pos+2, auth_pos-(id_pos+2));

	int title_pos = line.find(",",auth_pos+2);
	t = line.substr(auth_pos+2, title_pos-(auth_pos+2));
	
	int ed_pos = line.find(",", title_pos+2);
	ed = atoi(line.substr(title_pos+1,ed_pos-title_pos).c_str());
	
	int yr_pos = line.find(",", ed_pos+1);
	yr = atoi(line.substr(ed_pos+1,yr_pos-ed_pos).c_str());
	
	is = line.substr(yr_pos+2,line.length()-yr_pos);
	
	list[i].setId(id);
	list[i].setAuth(a);
	list[i].setTitle(t);
	list[i].setEd(ed);
	list[i].setYr(yr);
	list[i].setIsbn(is);
	i++;
	cout << "------------------------------------------------" << endl;
}
void find(Book list[], int i){
	string line = "";
	
	cout << "Enter author's first and last name: ";
	cin.ignore();
	getline(cin,line);
	
	bool found = 0;
	int j;
	
	for(j=0; j<i;j++){
		if(line == list[j].getAuth()){
			cout << list[j] << endl;
			found = 1;
		}
	}
	
	if(found == 0){
		cout << "No records found" << endl;
	}
	cout << "------------------------------------------------" << endl;
}
void display(Book list[], int i){						
	for(int z = 0; z < i; z++)
	{
		cout << list[z] << endl;
	}
	cout << "------------------------------------------------" << endl;
}
void sort(Book list[], int i, int res){
	for (int x = (i-1); x > 0; x--)
	{
		for(int y = 0; y<x; y++)
		{
			int b = 0;
			switch(res){
				case 1: 
					b = list[y].getId() > list[y+1].getId();
					break;
				case 2:
					b = list[y].getAuth() > list[y+1].getAuth();
					break;
				case 3:
					b = list[y].getTitle() > list[y+1].getTitle();
					break;
				case 4:
					b = list[y].getEd() > list[y+1].getEd();
					break;
				case 5:
					b = list[y].getYr() > list[y+1].getYr();
					break;
				case 6:
					b = list[y].getIsbn() > list[y+1].getIsbn();
					break;
			}
			if(b!=0)			//swap objects
			{
				Book temp = list[y+1];
				list[y+1] = list[y]; 
				list[y] = temp;
			}
		}
	}
}
int bsearch(Book list[], int i, int res, string key){
	int mid;
	string temp, elemAbove, elemBelow;
	int low = 0;
	int high = i;
	
	while(low <= high)
	{
		mid = (low+high)/2;				//get mid
		
		if(res == 1){
			temp = list[mid].getId();	//filter by options
			elemAbove = list[mid+1].getId();
			elemBelow = list[mid-1].getId();
		}
		else if(res == 2){
			temp = list[mid].getAuth();
			elemAbove = list[mid+1].getId();
			elemBelow = list[mid-1].getId();
		}
		else if(res == 3){
			temp = list[mid].getTitle();
			elemAbove = list[mid+1].getId();
			elemBelow = list[mid-1].getId();
		}
		else
			temp = list[mid].getIsbn();
			elemAbove = list[mid+1].getId();
			elemBelow = list[mid-1].getId();
		
		if(temp == key)					//change limits
			if(elemAbove == temp || elemBelow == temp)
				return -1;
			else
				return mid;
		else if(temp > key)
			high = mid-1;
		else
			low = mid+1;
		
	}
	return -1;
}
int bsearch(Book list[], int i, int res, int key){
	int mid;
	int temp, elemAbove, elemBelow;
	int low = 0;
	int high = i;	
	
	while(low <= high)
	{
		mid = (low+high)/2;				//get mid
		
		if(res == 4){					//filter by correct option
			temp = list[mid].getEd();
			elemAbove = list[mid+1].getEd();
			elemBelow = list[mid-1].getEd();
		}
		else{
			temp = list[mid].getYr();
			elemAbove = list[mid+1].getYr();
			elemBelow = list[mid-1].getYr();
		}
		
		if(temp == key)					//change limits
			if(elemAbove == temp || elemBelow == temp)
				return -2;	//will prompt message saying multiple entries
			else
				return mid;
		else if(temp > key)
			high = mid-1;
		else
			low = mid+1;
	}
	return -1;
}
void del(Book list[], int &i, int location){
	for(int x = location; x < (i-1); x++)
	{
		list[x] = list[x+1];
	}
	i--;
	cout << "Record deleted!!!" << endl;
}
void quit(Book list[], int i){
	ofstream out;
	out.open("bookoutput_text.txt");
	for(int x = 0; x < i; x++){
		out << list[x] << endl;
	}
	out.close();
	
	out.open("bookinput_text.txt");
	sort(list, i, 1);
	for(int y = 0; y < i; y++){
		out << list[y] << endl;
	}
	out.close();
}
ostream& operator<< (ostream& os, Book& d){				//write
		os << d.ident << ", " << d.author << ", " << d.title << ", " << d.edition << ", " << d.year << ", " << d.isbn;
		return os;
}
