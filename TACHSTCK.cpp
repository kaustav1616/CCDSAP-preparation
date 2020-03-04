// problem link: https://www.codechef.com/problems/TACHSTCK

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_num_pairs(vector<int> &, int);

int main() 
{
	int i, num_inputs, diff, num;
	vector<int> input;
	
	cin >> num_inputs >> diff;
	
	for(i = 0; i < num_inputs; ++i)
	{
	    cin >> num;
	    input.push_back(num);
	}
	
	cout << find_num_pairs(input, diff) << endl;
	
	return 0;
}

int find_num_pairs(vector<int> &input, int diff)
{
    int i = 0, n = input.size(), count = 0;
    
    sort(input.begin(), input.end());
    
    while(i < n - 1)
    {
        if(input[i + 1] - input[i] <= diff)
        {
            ++count;
            i += 2;
        }
        else
            ++i;
    }
    
    return count;
}
