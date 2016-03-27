#include <time.h>
#include <iostream>
#include "Time.h"
#include <windows.h>

using namespace std;

unsigned int main()
{

	//cout << 24 + (-1 % 24);


	Time t(0, 1, 0, 1);
	Time k(0, 1, 0, 1);
	if(k<=t)
	{
		cout << "T";
	}
	else
	{
		cout << "Ffff";
	}
	cin.get();
}