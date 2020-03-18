// problem link: https://www.codechef.com/submit/MAXDIFF
// Given 'k' and no. of elements 'n', divide into 2 groups such that difference between 2 groups is maximized
// analysis: If I have to give 'k' elements to 'k', what is max possible diff; using this result, add on:
// If I have 2 choices: to give 'k' elements or (n - k) elements, what is max possiblle diff?

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_max_diff(vector<int> &, int);

int main() 
{
	int num_tests, num_inputs, k, i, num;
	vector<int> inputs;
	
	cin >> num_tests;
	
	while(num_tests--)
	{
	    inputs.clear();
	    cin >> num_inputs >> k;
	    
	    for(i = 0; i < num_inputs; ++i)
	    {
	        cin >> num;
	        inputs.push_back(num);
	    }
	    
	    cout << find_max_diff(inputs, k) << endl;
	}
	
	return 0;
}

int find_max_diff(vector<int> &inputs, int k)
{
    int l = inputs.size() - k, n = inputs.size(), i, sum1 = 0, sum2 = 0;
    
    if(l > k)
        k = l;
        
    sort(inputs.begin(), inputs.end());
        
    for(i = n - 1; i >= 0; --i)
    {
        if(i >= n - k)
            sum2 += inputs[i];
        else 
            sum1 += inputs[i];
    }
        
    return (sum2 - sum1);
}
