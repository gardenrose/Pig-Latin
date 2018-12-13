#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "pch.h"

using namespace std;

int provjeraJeLiSlovoVokal(char slovo)
{
	if (slovo != 'a' && slovo != 'y' && slovo != 'Y' && slovo != 'e' && slovo != 'i' && slovo != 'o' && slovo != 'u' && slovo != 'A' && slovo != 'E' && slovo != 'I' && slovo != 'O' && slovo != 'U')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int pocimanjeSamoglasnikom(string word)
{
	if (word[0] == 'a' || word[0] == 'y' || word[0] == 'Y' || word[0] == 'e' || word[0] == 'i' || word[0] == 'o' || word[0] == 'u' || word[0] == 'A' || word[0] == 'E' || word[0] == 'I' || word[0] == 'O' || word[0] == 'U')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void pigLatin(string& s)
{
	vector <char> spremnik;
	if (pocimanjeSamoglasnikom(s) == 1)
	{
		s.push_back('h');
		s.push_back('a');
		s.push_back('y');
	}
	else
	{
		for (int i = 0; i < s.size(); i = i + 1)
		{
			if (provjeraJeLiSlovoVokal(s[i]) == 1)
			{
				s.push_back(s[i]);
				s.erase(i, 1);
				i--;
			}
			else
			{
				break;
			}
		}
		s.push_back('a');
		s.push_back('y');
	}
}

vector <string> pigLatin2(string& s)
{
	string buffer;
	vector <string> v1;
	for (int i = 0; i < s.size(); i = i + 1)
	{
		if (s[i] == ' ' || s[i] == '.' || s[i] == '?' || s[i] == ',')
		{
			pigLatin(buffer);
			v1.push_back(buffer);
			buffer.clear();
		}
		else
		{
			buffer.push_back(s[i]);
		}
	}
	return v1;
}
int main()
{
	string s = "Elephant can fly only in the sky.";
	vector <string> v = pigLatin2(s);
	for (int i = 0; i < v.size(); i = i + 1)
	{
		cout << v[i] << " ";
	}
	return 0;
}