#include <stdio.h>
#include <iostream>
#include <bitset>
using namespace std;

string ToInt(unsigned char* b)
{
	string num;
	for (int i = 0; i < 8; i++)
	{
		if (*b & (128 >> i)) num += "1";
		else num += "0";
	}
	return num;
}

void ShowInt(int x)
{
	string A[4];
	cout << "int:\n";
	for (int i = 0; i < 4; i++)
	{
		string num = ToInt((unsigned char*)&x + i);
		A[i] = num;
	}

	cout << "Big-Endian:";
	for (int i = 3; i >= 0; i--)
	{
		cout << A[i];
		cout << ' ';
	}

	cout << "\nLittle-Endian:";
	for (int i = 0; i < 4; i++)
	{
		cout << A[i];
		cout << ' ';
	}
}

void ShowFloat(float x) 
{
	cout << "\nfloat:";
	cout << "\nBig-Endian:";
	for (int i = sizeof(x) - 1; i >= 0; i--)
		std::cout << ' ' << std::bitset<8>(reinterpret_cast<char*>(&x)[i]);
	cout << "\nLittle-Endian:";
	for (int i = 0; i <= sizeof(x) - 1; i++)
		std::cout << ' ' << std::bitset<8>(reinterpret_cast<char*>(&x)[i]);
}

void ShowDouble(double x) {
	cout << "\ndouble:";
	cout << "\nBig-Endian:";
	for (int i = sizeof(x)-1; i >= 0; i--)
		std::cout << ' ' << std::bitset<8>(reinterpret_cast<char*>(&x)[i]);
	cout << "\nLittle-Endian:";
	for (int i = 0; i <= sizeof(x) - 1; i++)
		std::cout << ' ' << std::bitset<8>(reinterpret_cast<char*>(&x)[i]);
}

void ShowByte(int x)
{
	ShowInt(x);
	ShowFloat((float)x);
	ShowDouble((double)x);
}

int main()
{
	int x;
	cout << "Input your number: ";
	cin >> x; 
	ShowByte(x);
	std::cin.get();
	std::cin.get();
	return 0;
}
