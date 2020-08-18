// problem link: https://www.spoj.com/problems/BAISED/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long int calc_min_badness(vector<int> &);

int main() 
{
	int i, j, num, num_tests, num_elements;
	string str;
	vector<int> input;
	
	cin >> num_tests;
	
	for(i = 0; i <= num_tests - 1; ++i)
	{
	    input.clear();
		cin >> num_elements;

		for(j = 0; j <= num_elements - 1; ++j)
		{
			cin >> str >> num;
			input.push_back(num);
		}
		
		cout << calc_min_badness(input) << endl;
	}
	
	return 0;
}

long int calc_min_badness(vector<int> &input)
{
	int i, n = input.size();
	long int badness = 0;
	
	sort(input.begin(), input.end());
	
	for(i = 0; i <= n - 1; ++i)
		badness += (long int)abs(i + 1 - input[i]);
		
	return badness;
}
