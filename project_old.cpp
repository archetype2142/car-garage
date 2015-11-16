#include <fstream>
#include <stdio.h>
#include <string.h>
#include <iostream.h>
#include <conio.h>
#include <stdlib.h>

class car { 
	
public: 
	char name[20]; 
	char manufacturer[20];
	int car_index;
	unsigned long long int price; 
	void get() {
		cout << "Enter the details of the car below "<< endl;
		cout << "Enter name of the car: ";
		cin >> name;
		cout << "Enter name of manufacturer: ";
		cin >> manufacturer;
		cout << "Enter price: ";
		cin >> price;
	} 
	char *getn()
	{
		return name;
	}
	void show() { 
		cout << "* CAR NAME: " << name << endl;
		cout << "* MANUFACTURER: " << manufacturer << endl;
		cout << "* PRICE: " << price << endl;
		cout << "*                                                                *\n";
	}

	void bought(){
		
		cout << "*****************************INVOICE******************************\n";
		cout << "*            CONGRATULATIONS CAR SUCCESSFULLY PURCHASED          *\n";
		cout << "*                                                                *\n";
		cout << "*                                                                *\n";
		cout << "* CAR NAME: " << name << endl;
		cout << "*                                                                *\n";
		cout << "* MANUFACTURER: " << manufacturer << endl;
		cout << "*                                                                *\n";
		cout << "* PRICE: " << price << endl;
		cout << "*                                                                *\n";
		cout << "*                      "<< name << " is now yours.\n";
		cout << "*                                                                *\n";
		cout << "******************************************************************\n\n\n";
		exit(0);
	}
};
int main(){
	
	clrscr();
	int choice;
	int choice_1;  
	cout << "***************************WELCOME TO CAR GARAGE********************\n\n\n" << "                  Are you the manager(1) or customer(2): ";
	cin >> choice_1;
	cout << endl;
	do{
		if(choice_1 == 1){
			cout << "1. Add a new car" << endl;
			cout << "2. Display all cars" << endl;
			cout << "3. exit" << endl;
			cout << "Enter choice: ";
			cin >> choice;

			switch(choice){
				case 1: {
					char ch='y'; 
					car s; 
					fstream t; 
					t.open("cars.dat",ios::binary|ios::out|ios::app|ios::in); 
					while(ch=='y'||ch=='Y'){ 
						s.get(); 
						t.write((char*)&s,sizeof(car)); 
						cout << "do you want to add more(y/n)....:"<< endl;
						cin >> ch; 
					} 
					t.close();
					break;
				} 
				case 2: { 
					car s; 
					fstream t; 
					t.open("cars.dat",ios::binary|ios::out|ios::app|ios::in); 
					t.seekg(0); 
					cout << "****************************CAR*DETAILS***************************\n";
					cout << "*                                                                *\n";
					cout << "*                                                                *\n";
					while(t.read((char*)&s,sizeof(car))){ 
						s.show(); 
					}
					cout << "*                                                                *\n";
					cout << "*                                                                *\n";
					cout << "******************************************************************\n";
					t.close(); 
				} 
				break;

				case 3:
				exit(0);
			}
		}
		else{
			cout << "1. Display all cars" << endl;
			cout << "2. Buy car!" << endl;
			cout << "3. exit" << endl;
			cout << "Enter choice: ";
			cin >> choice;

			switch(choice){
				case 1: { 
					car s; 
					fstream t; 
					t.open("cars.dat",ios::binary|ios::out|ios::app|ios::in); 
					t.seekg(0); 
					cout << "****************************CAR*DETAILS***************************\n";
					cout << "*                                                                *\n";
					cout << "*                                                                *\n";
					while(t.read((char*)&s,sizeof(car))){ 
						s.show(); 
					}
					cout << "*                                                                *\n";
					cout << "*                                                                *\n";
					cout << "******************************************************************\n";
					t.close(); 
				} 
				break;

				case 2: { 
					char a[20]; 
					car s; 
					fstream t; 
					t.open("cars.dat",ios::binary|ios::out|ios::app|ios::in); 
					t.seekg(0); 
					cout <<"Enter the name of car you want to buy: ";
					cin >> a;
					while(t.read((char*)&s,sizeof(car))){
						if(strcmp(a, s.getn()) == 0){
							s.bought(); 
						}
					}
					t.close();
					break;
				}

				case 3:
				exit(0);
			}
		}
	}while(choice != 3);
	
	getch();
	return 0;
}