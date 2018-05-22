// idcheck.cpp: 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define __DEBUG
int len(char* s)
{
	int i = 0;
	while (s[i] != 0)
		i++;
#ifdef __DEBUG
	cout << "debug: strlen=" << i << endl;
#endif
	return i;
}
bool isalpha(char c)
{
	if (c >= 'a' && c <= 'z') return true;
	if (c >= 'A' && c <= 'Z') return true;
	return false;
}
bool isuppercase(char c)
{
	if (c >= 'A' && c <= 'Z') return true;
	return false;
}
bool islowercase(char c)
{
	if (c >= 'a' && c <= 'z') return true;
	return false;
}
bool toupper(char& c)
{
	if (islower(c))
	{
		c = c - 'a' + 'A';
		return true;
	}
	return false;

}
int main()
{
	char s[256] = { 0 };
	int A[11] = { 0 };
	cin >> s;
#ifdef __DEBUG
	cout << "debug:" << s << endl;
#endif
	if (len(s) != 10) { cout << "length error" << endl;return -1; }
	if (!isalpha(s[0])) { cout << "first letter error" << endl;return -2; }
	toupper(s[0]);
#ifdef __DEBUG
	cout << "debug:" << s << endl;
#endif
	int T[26] = { 10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,30,31,32,33 };
	A[0] = T[s[0] - 'A'] / 10;
	A[1] = T[s[0] - 'A'] % 10;
	int i;
	for (i = 2;i <= 10;i++)
		A[i] = s[i - 1] - '0';
	int c = A[0];
	for (i = 1;i <= 9;i++)
		c += A[i] * (10 - i);
	if ((c + A[10]) % 10 == 0)
		cout << "correct" << endl;
	else
		cout << "incorrect" << endl;

	return 0;
}

