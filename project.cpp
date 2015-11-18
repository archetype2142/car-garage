#include <fstream>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

class car { 
	
public: 
	char name[20]; 
	char manufacturer[20];
	int car_index;
	char color[20];
	int seats;
	int price; 
	void get() {
		cout << "Enter the details of the car below "<< endl;
		cout << "Enter name of the car: ";
		cin >> name;
		cout << "Enter name of manufacturer: ";
		cin >> manufacturer;
		cout << "Enter price: ";
		cin >> price;
		cout << "Enter color: ";
		cin >> color;
		cout << "How many seats? ";
		cin >> seats;
	} 
	char *getn()
	{
		return name;
	}
	void show() { 
		cout << "* CAR NAME: " << name << endl;
		cout << "* MANUFACTURER: " << manufacturer << endl;
		cout << "* PRICE: " << price << endl;
		cout << "* COLOR: " << color << endl;
		cout << "* SEATS: " << seats << endl;
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
		cout << "* COLOR: " << color << endl;                                     
		cout << "*                                                                *\n";
		cout << "* PRICE: " << price << endl;                                      
		cout << "*                                                                *\n";
		cout << "* SEATS: " << seats << endl;										
		cout << "*                                                                *\n";
		cout << "*                      "<< name << " is now yours.\n";
		cout << "*                                                                *\n";
		cout << "******************************************************************\n\n\n";
		exit(0);
	}
};
int main(){
	int choice;
	char exitr = 'y';
	int choice_1;
	do{  
		cout << "***************************WELCOME TO CAR GARAGE********************\n\n\n" << "                  Are you the manager(1) or customer(2): ";
		cin >> choice_1;
		cout << endl;
		if(choice_1 == 1){
			cout << "1. Add a new car" << endl;
			cout << "2. Display all cars" << endl;
			cout << "3. Remove old car" << endl;
			cout << "4. Update outdated car" << endl;
			cout << "5. exit" << endl;
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
					break;
				}

				case 3:{ 
					ofstream o;
					char a[20]; 
					car s; 
					ifstream t; 
					o.open("new.dat", ios::out|ios::binary);
					t.open("cars.dat",ios::binary|ios::app|ios::in); 
					t.seekg(0); 
					cout <<"Enter the name of car you want to remove: ";
					cin >> a;
					while(t.read((char*)&s,sizeof(car))){
						if(strcmp(a, s.getn()) != 0){
							o.write((char*)&s, sizeof(s));
						}
					}
					o.close();
					t.close();
					remove("cars.dat");
					rename("new.dat", "cars.dat");
					cout << "\n Car successfully deleted \n";
					break;
				}
				case 4: {
					char n[100];
					cout<<"Enter Name that should be modified: ";
					cin >> n;
					long pos;
					char found = 'f';
					fstream t;
					car s;
					t.open("cars.dat",ios::in| ios::out|ios::binary);
					while(!t.eof())
					{
						pos = t.tellg();
						t.read((char*)&s, sizeof(s));
						if(strcmp(n, s.getn()) == 0){
							cout << "Enter new details below\n";
							s.get();
							t.seekg(pos);
							t.write((char*)&s, sizeof(s));
							found = 't';
							t.seekg(0);
							cout << "\n        Garage successfully modified, new files are...\n";
							cout << "****************************CAR*DETAILS***************************\n";
							cout << "*                                                                *\n";
							cout << "*                                                                *\n";
							while(t.read((char*)&s,sizeof(car))){ 
								s.show(); 
							}
							cout << "*                                                                *\n";
							cout << "*                                                                *\n";
							cout << "******************************************************************\n";
							break;
						}
					}
					if(found == 'f'){
						cout << "\nRecord not found\n";
					}
					t.close();
				}
			}
			cout << "Do you want you continue?(y/n): ";
			cin >> exitr;
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
				}
				break;

				case 3:
				exit(0);
			}
			cout << "Do you want you continue?(y/n): ";
			cin >> exitr;
		}
	}while(exitr == 'y');
	return 0;
}
