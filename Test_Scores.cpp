//Input-Output File Handling
// Test Scores Program
//Author is Moses Arocha

#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

using namespace std;

//Variables
string stars(string text);

//Declare Functions that will be used
void display_inventory();
void add_item();
void add_function();

//Display Input File Data
void display_inventory()
{
	char input[800];			//creates a character array for input file
	
	fstream inFile;				//creates an input file object
	inFile.open("Test_Scores.txt");		//Open the input file
	if(inFile.fail())
	{
		cout << " File not found - exiting program" << endl;
		system("PAUSE");
		exit(1);
	}

	cout << "\t\t\t Northside Grade Book 2015 \n\n";
	cout << "\t\First	Last	ID	Test 1	Test 2	Test 3	Test 4	Test 5 \n";
	cout << "\t\---------------------------------------------------------------\n";

	while (!inFile.fail())		//reads data from file until file input fails (the end)
	{
		inFile.getline(input,800);	//read one line at a time
		cout << "\t" << input << "\n" << endl;
	}
	
	inFile.close();				//close the input file

	cout << "\n\n Press [M or m] to return to Main Menu: ";
	cin.ignore();
	cin.get();

}

void display_total()
{
	char input[800];			//creates a character array for input file
	
	fstream inFile;				//creates an input file object

	inFile.open("TestScores.txt");		//Open the input file, the name of the file is within quotations 

// each name variable coincides with the variable in the text files 	
int Test1;
int Test2;
int Test3;
int Test4;
int Test5;
int userID;
int fakeID = 1;
int TestAverage;
string firstName;
string lastName;


	cout << "\t\ Holmes High School Grade Book \n\n";
	cout << " First	 Last	Test 1	Test 2	Test 3	Test 4	Test 5	Test Average\n";
	cout << "---------------------------------------------------------------------------\n";
	while (!inFile.fail())		//reads data from file until file input fails (the end)
	{
		inFile.getline(input,800);	//read one line at a time
		inFile >> firstName >> lastName >> userID >> Test1 >> Test2 >> Test3 >> Test4 >> Test5;
		TestAverage =  (Test1 + Test2 + Test3 + Test4 + Test5) /5;

		if (userID == fakeID)
		{
			break;
		}
		cout << "\n " << firstName << "\t" << lastName << "\t" << Test1 << "\t" << Test2 << "\t" << Test3 << "\t" << Test4 << "\t" << Test5 << "\t" << TestAverage;
		fakeID = userID;


		if (TestAverage >= 94)
		{
			cout << "\n\t\t\t\t\t" << lastName << " has a GPA of 4.0 \n";
		}

		else if (TestAverage >= 84 && TestAverage < 94)
		{
			cout << "\n\t\t\t\t\t" <<lastName << " has a GPA of 3.0 \n";
		}
		else if (TestAverage >= 74 && TestAverage < 84)
		{
			cout << "\n\t\t\t\t\t" << lastName << " has a GPA of 2.0\n";
		}
		else
		{
			cout << "\n\t\t\t\t\t" << lastName << " has a GPA of 1.0\n";
		}

	}
	

	
	inFile.close();			//close the input file

	cout << "\n\n Press [M or m] to return to Main Menu: ";
	cin.ignore();
	cin.get();
}

//Add new items to Inventory
void add_Item()
{

// all of the names of the variables conincide with the text file variables
int Test1;
int Test2;
int Test3;
int Test4;
int Test5;
int userID;
string firstName;
string lastName;


cout << "\t\t Adding New Students Into The Grade Book: ";
cout << "\n\n\t Please Enter A New Student First Name:  ";
cin >> firstName;
cin.ignore(800,'\n');

cout << "\n\t Enter Enter The Student's Last Name:  ";
cin >> lastName;
cin.ignore(800,'\n');

cout << "\n\t Enter The identification Number :  ";
cin >> userID;
cin.ignore(800,'\n');

cout << "\n\t Enter The First Test Grade :  ";
cin >> Test1;
cin.ignore(800,'\n');

cout << "\n\t Enter The Second Test Grade :  ";
cin >> Test2;
cin.ignore(800,'\n');

cout << "\n\t Enter The Third Test Grade :  ";
cin >> Test3;
cin.ignore(800,'\n');

cout << "\n\t Enter The Fourth Test Grade :  ";
cin >> Test4;
cin.ignore(800,'\n');

cout << "\n\t Enter The Fifth Test Grade :  ";
cin >> Test5;
cin.ignore(800,'\n');
	
ofstream outFile;				//Creates an output file object
outFile.open("TestScores.txt", ios::app);  	//Opens output file, 
//include ios::app for adding to file

outFile << firstName << "\t" << lastName << "\t" << userID << "\t" << Test1 << "\t" << Test2 << "\t" << Test3 << "\t" << Test4 << "\t" << Test5 << "\n";  //committs data to file
outFile.close();				//closes

cout << "\n\n New Student '" << firstName << " " << lastName << "' Has Been Added To Grade Book. " << endl;
cout << "\n\n Please Press [M or m] To Return To Main Menu: ";
cin.ignore();
cin.get();

}

int main()
{
	int choice;				//User Menu Choice
	int exit = 0;				//Program Exit flag

	while (exit == 0)
	{
		//Display the Inventory Item Menu
		cout << "\n\t\t Northside Independent School District Grade Book ";
		cout << "\n _____________________________________________________________________________ ";
		cout << "\n\n\t\t [1] Display Students In The Database ";
		cout << "\n\t\t [2] Add New Students To The Database ";
		cout << "\n\t\t [3] Display Students Averages ";
		cout << "\n\t\t [4] Exit ";
		cout << "\n\n Please Enter Your choice:  ";
		cin >> choice;

		//Check User Menu Choice
		switch(choice)
		{
			case 1:						//Display Inventory
				system("cls");				//clear screen
				display_inventory();
				system("cls");
				break;

			case 2:						//Add Item to Inventory
				system("cls");				//clear screen
				add_Item();
				system("cls");
				break;

			case 3:
				system("cls");
				display_total();
				system("cls");
				break;

				
			case 4:						//Exit the Program
				exit = 1;
				cout << "\n";
				break;

			default:
				cout << "\n\n\n Invalid Selection. Press A Key To Return To Main Menu. ";
				cin.ignore();
				cin.get();
				system("cls");
		}

		if (exit == 1)					//Exit flag is set-break the loop)
		{	break;    }

	}
	return 0;

}
