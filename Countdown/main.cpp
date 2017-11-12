#include <iostream>
#include <thread>
#include <windows.h>
using namespace std;

#define COUNT_DOWN_NUMBER 12
#define COUNT_DOWN_DELAY 1s
#define TAKEOFF_DELAY 5s

HANDLE hCon;

enum Color {
	GREEN = 10,
	RED = 12
};

void SetTextColor(Color c) {
	if (hCon == NULL)
		hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, c);
}


int main()
{
	SetTextColor(Color::GREEN);
	for (int i = COUNT_DOWN_NUMBER; i > 0; i--)
	{
		cout << "\rTime until takeoff: " << i << "\t";
		this_thread::sleep_for(COUNT_DOWN_DELAY);
	}
	
	SetTextColor(Color::RED);
	cout  << "\rTakeoff\t\t\t" << endl;
	this_thread::sleep_for(TAKEOFF_DELAY);


	return 0;
}