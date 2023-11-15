#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
int Count(char* s) // s = вказівник на початок рядка
{
	int k = 0,
		pos = 0; // pos = позиція початку пошуку
	char* t;
	while (t = strchr(s + pos, ',')) // t = вказівник на ','
	{
		pos = t - s + 1; // pos = наступний символ після ','
		if (s[pos] == '-')
			k++;
	}
	return k;
}
char* Change(char* s) // s = вказівник на початок рядка
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0, // pos1 = позиція початку пошуку
		pos2 = 0;
	*t = 0;
	while (p = strchr(s + pos1, ',')) // p = вказівник на ','
	{
		if (s[p - s + 1] == '-')
		{
			pos2 = p - s + 2; // pos2 = позиція наступного символа після '-'
			strncat(t, s + pos1, pos2 - pos1 - 2);
			strcat(t, "*");
			pos1 = pos2;
		}
		else
		{
			pos2 = p - s + 1; // pos2 = позиція наступного символа після ','
			strncat(t, s + pos1, pos2 - pos1);
			pos1 = pos2;
		}
	}
	strcat(t, s + pos1);
	strcpy(s, t);
	return t;
}
int main()
{
	char str[101];


		cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << " groups of ', -'" << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}