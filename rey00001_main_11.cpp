//This is the main file for a program that reads of book database text file ("bookinput_text.txt") and allows the user to add a record, find records, display all records or delete a record. It then write an updated database to a new file ("bookoutput_text.txt").
//This program also requires a header file ("rey00001_hw11EC.hpp"), a cpp file with functions (rey00001_books_11.cpp) and the two text files ("bookinput_text.txt" & "bookoutput_text.txt") 
#include "rey00001_hw11EC.hpp"
#include <string>

int main()
{										
	int i = 0;									//book record number
	const int size = 20;						//book record array size
	Book list[size];							//book record array
	char ans; 									//user's response: A,F,P,S,D,or Q
	
	getInput(list, i);							//gets data from Bookinput_text.txt
	
	do{											//ask for user input
		cout << "Current database size: " << i << " records." << endl;
		cout << "(A) Add Record" << endl << "(F) Find Record By Author Name" << endl << "(P) Print All Records" << endl << "(S) Sort Records" << endl << "(D) Delete A Record" << endl << "(Q) Quit" << endl;
		cin >> ans;
		
		if(ans == 'a' || ans == 'A'){				
			add(list,i);						//add a record
		}
		else if(ans == 'f' || ans == 'F'){			
			find(list, i);						//find record by author name
		}
		else if(ans == 'p' || ans == 'P'){
			display(list, i);					//display records in current sorted order
		}
		else if(ans == 's' || ans == 'S'){		//sort records
			int res = 0;
			bool isWrong = true;
			
			do{									//asks user how they want to sort by
				cout << "Sort by: 1.ID 2.Author Name 3.Title 4.Edition 5.Year 6.ISBN" << endl;
				cin >> res;
		
				if(res>=1 && res<=6){
					sort(list, i, res);
					isWrong = false;
				}
				else{
					cout << "You did not enter a correct option. Please re-try." << endl;
				}
			}while(isWrong == true);
			cout << "------------------------------------------------" << endl;
		}
		else if(ans == 'd' || ans == 'D')		//find record by binary search then delete it
		{	
			int res = 0;
			bool isWrong = true;
			int location = -1;
			
			do{									//asks user what they want to delete
				cout << "Delete by: 1.ID 2.Author Name 3.Title 4.Edition 5.Year 6.ISBN" << endl;
				cin >> res;
		
				if(res>=1 && res<=6)
				{
					sort(list, i, res);
					
					if (res == 4|| res == 5)		//if int
					{
						int key;
						cout << "Enter in the value you want to delete: ";
						cin >> key;
						location = bsearch(list, i, res, key);
						//cout << "location at: " << location << endl; //debugger
					}
					else 						//if string
					{
						string key;
						cout << "Enter in the value " << "you want to delete: ";
						cin.ignore();
						getline(cin,key);
					
						location = bsearch(list, i, res, key);
						//cout << "location at: " << location << endl; //debugger
					}

					if(location == -1){
						cout << "Record not found" << endl;
						cout << "------------------------------------------------" << endl;
						break;
					}
					else if(location ==-2){
						cout << "Error!!! Multiple records found. Please try to delete using another category." << endl;
						cout << "------------------------------------------------" << endl;
						break;
					}
					else
						del(list, i, location);
						cout << "------------------------------------------------" << endl;
					isWrong = false;
				}		
				else
					cout << "You did not enter a correct option. Please re-try." << endl;
			}while(isWrong == true);
		}
		else if(ans == 'q' || ans == 'Q'){	
			quit(list, i);
			cout << "------------------------------------------------" << endl;
			return 0;
		}
		else{
			cout << "You have not entered a correct option, please re-try or press q to quit" << endl << endl;
		}
	}while (ans != 'q' || ans != 'Q');
	
	return 0;
}
