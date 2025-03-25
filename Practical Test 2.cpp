/*
Practical Test 2							Date : 11/02/2025
Name : Nurul Farhana binti Azani			Matric No : 247418
Name : Nur Aliesya Nasrina binti Ahmad		Matric No : 244815
*/

#include <iostream>
#include <fstream>
using namespace std;

int main ()
{
	ofstream outFile;
	outFile.open("Registration.txt");
	
	int code [3] = {1,2,3};
	float charge [3] = {400.0, 350.0, 300.0};
	int input, i=0;
	float total = 0, ntotal = 0;
	
	cout << "Welcome to Little CFS Kindergarden\n\n";
	cout << "How many children would like to enroll? ";
	cin >> input;
	
	string *name = new string[input];
	int *cat = new int[input];
	float *cost = new float[input];
	cost = charge;
	
	outFile << "Children Infromation\n";
	outFile << "Child name\t\tCategory\t\tCost:\n";
	
	for (i=0; i<input; i++)
	{
		cin.ignore();
		cout << "Enter name child #" << i+1 << ": ";
		getline (cin,name[i]);
		cout << "Enter category (1/2/3) ";
		cin >> cat[i];
		cout << endl;
		outFile << name[i] << "\t\t\t" << cat[i];
		switch (cat[i])
		{
			case 1 : total += *cost; outFile<< "\t\t\tRM" << *cost << endl; break;
			case 2 : total += *(cost + 1); outFile<< "\t\t\tRM" << *(cost + 1) << endl; break;
			case 3 : total += *(cost + 2); outFile<< "\t\t\tRM" << *(cost + 2) << endl; break;
		}
		
	}
	
	if (input >= 3)
	{
		ntotal = total - (0.1 * total);
		outFile << "\nTotal fees for all children : RM" << ntotal << endl;
	}
	else
	{
		outFile << "\nTotal fees for all children : RM" << total << endl;
	}
	
	delete[] name;
	delete[] cat;
	delete[] cost;
	outFile.close();
	
	return 0;
}
