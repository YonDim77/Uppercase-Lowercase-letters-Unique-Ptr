#include <iostream>
#include <string>
#include <iomanip> 
#include <cmath>
#include <utility>
#include <sstream>
#include <ctype.h>
#include <list>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <memory>

using namespace std;

unique_ptr<char[]> convert(const char *pLine, const size_t &size, char (*pConvert) (const char&))
{
	unique_ptr<char[]> result = make_unique<char[]>(size);
	for (size_t i = 0; i < size; i++)
		result[i] = pConvert(pLine[i]);

	return result;
}

char toLower(const char &s)
{
	if (s >= 'A' && s <= 'Z')
		return s + 32;

	return s;
}

char toUpper(const char &s)
{
	if (s >= 'a' && s <= 'z')
		return s - 32;
		
	return s;
}

int main()
{
	string line;
	getline(cin, line);
	const char* pLine = line.c_str();
	size_t size = line.length() + 1;

	unique_ptr<char[]> outputToLower = convert(pLine, size, toLower);
	cout << outputToLower << endl;

	unique_ptr<char[]> outputToUpper = convert(pLine, size, toUpper);
	cout << outputToUpper << endl;

	return 0;
}
