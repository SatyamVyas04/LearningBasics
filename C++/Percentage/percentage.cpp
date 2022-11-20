#include <iostream>

using namespace std;

int main ()
{
	cout<<"Enter your name: ";
	string Name;
	cin>>Name;

	cout<<"Enter your Mathematics marks: "<<endl;
	int a;
	cin>> a;

	cout<<"Enter your Physics marks: "<<endl;
	int b;
	cin>> b;

	cout<<"Enter your Chemistry marks: "<<endl;
	int c;
	cin>> c;

	double Percentage;
	Percentage=(a+b+c)/3;

	cout<<Name<<" Your Percentage is "<<Percentage<<"%";
}