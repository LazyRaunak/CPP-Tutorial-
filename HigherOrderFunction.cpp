// C++ program to illustrate the higher
// order function in C++
#include <bits/stdc++.h>
using namespace std;

// Function that will be passed as an
// arguments to calling fuction
bool Parser(string x)
{
	// Check if string start
	// with alphabt 'R'
	return x[0] == 'R';
}

// Fuction that takes function as
// an arguments
vector<string> Parse(vector<string> a,
					function<bool(string)> Parser)
{
	vector<string> ans;

	// Traverse the vector a
	for (auto str : a) {
		if (Parser(str)) {
			ans.push_back(str);
		}
	}

	// Return the resultant vector
	return ans;
}

// Driver Code
int main()
{
	vector<string> dict = { "geeks", "Rxop",
							"Rka", "for" };

	// Function Call for Higher
	// Order Functions
	vector<string> ans = Parse(dict, Parser);

	// Print the results
	for (auto str : ans) {
		cout << str << " ";
	}

	return 0;
}
