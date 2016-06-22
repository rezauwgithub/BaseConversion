// BaseConversion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


bool BaseConversion(int num, int base, string &ans);

int main()
{
	while (true)
	{
		int num, base;

		string answer;
		cout << "Input number: ";
		cin >> num;
		
		cout << "Input Base to convert to: ";
		cin >> base;

		if (BaseConversion(num, base, answer))
			cout << num << " is " << answer << " in base" << base << endl;
		else
			cout << "Invalid input!" << endl;

	}

	system("pause");
    return 0;
}

bool BaseConversion(int num, const int base, string &ans)
{
	const string static DIGIT_ARRAY = "0123456789ABCDEF";

	if (num < 0 || base < 1 || base > 16)
		return false;

	if (num < base)
	{
		ans = DIGIT_ARRAY[num] + ans;
		return true;
	}

	// ans += DIGIT_ARRAY[num % base];
	// ans = ans + DIGIT_ARRAY[num % base];
	ans = DIGIT_ARRAY[num % base] + ans;

	return BaseConversion(num / base, base, ans);


}

