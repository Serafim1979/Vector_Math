//////////////////////////////////////////////////////////////////////////////////////////////////
/* The program simulates a known random walk problem. Idea 
is that you visit someone at the starting point. He starts moving., 
but the direction of each step is randomly changed in relation to  
the direction in the previous step. Here is how one of the formulations of this task looks like: 
how many steps does this character need to take to get away, say, 50 feet 
from the starting point? In terms of vectors, this means adding a set randomly 
oriented vectors as long as the amount does not exceed 50 feet.*/
//////////////////////////////////////////////////////////////////////////////////////////////////
#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Vect.h"
//////////////////////////////////////////////////////////////////////////////////////////////////
using std::cout;
using std::cin;
using std::endl;
using VECTOR::Vector;
//////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;

	cout << "Enter target distance (q to quit): ";

	while (cin >> target)
	{
		cout << "Enter step length: ";
		if (!(cin >> dstep))
			break;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(dstep, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "After " << steps << " steps, the subject "
			<< "has the following location:\n";
		cout << result << endl;
		result.polar_mode();
		cout << "or\n" << result << endl;
		cout << "Average outward distance per step = "
			<< result.magval() / steps << endl;
		steps = 0;
		result.reset(0.0, 0.0);
		cout << "Enter target distance (q to quit): ";
	}
	cout << "Bye!\n";
	cin.clear();
	while (cin.get() != '\n')
		continue;

	system("pause");
	return 0;
}