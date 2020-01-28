// problem link: https://www.codechef.com/submit/DELISH

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void find_min_subarray(vector<int> &, vector<long int> &);
void find_max_subarray(vector<int> &, vector<long int> &);
long int find_max_abs_diff(vector<int> &);

int main()
{
	int t, i, n, num;
	vector<int> input;
	
	cin >> t;
	
	while(t--)
	{
	    input.clear();
	    cin >> n;
	    
	    for(i = 0; i < n; ++i)
	    {
	        cin >> num;
	        input.push_back(num);
	    }
	    
	    cout << find_max_abs_diff(input) << endl;
	}
	
	return 0;
}

// T(n) = O(n), S(n) = O(n)
long int find_max_abs_diff(vector<int> &input)
{
    int i, n = input.size();
    long int max_abs_diff = LONG_MIN;
    vector<long int> min_starting(n), max_starting(n), min_ending(n), max_ending(n);
    
    find_min_subarray(input, min_ending);
    find_max_subarray(input, max_ending);
    reverse(input.begin(), input.end());
    find_min_subarray(input, min_starting);
    reverse(min_starting.begin(), min_starting.end());
    find_max_subarray(input, max_starting);
    reverse(max_starting.begin(), max_starting.end());
    
    for(i = 0; i < input.size() - 1; ++i) // explores all possible partitions
    {
        max_abs_diff = max(max_abs_diff, max_ending[i] - min_starting[i + 1]);
        max_abs_diff = max(max_abs_diff, max_starting[i + 1] - min_ending[i]);
    }
    
    return max_abs_diff;
}

// soln[i] = max sum of subarray in input[0..i]
void find_max_subarray(vector<int> &input, vector<long int> &soln)
{
    int i;
    soln[0] = (long int)input[0];
    
    /* find max sum of subarray ending at i */
    for(i = 1; i < input.size(); ++i)
        soln[i] = soln[i - 1] > 0 ? soln[i - 1] + (long int)input[i] : (long int)input[i];
        
    /* find max sum of subarray in input[0..i] */
    for(i = 1; i < input.size(); ++i)
        soln[i] = max(soln[i - 1], soln[i]);
}

void find_min_subarray(vector<int> &input, vector<long int> &soln)
{
    int i;
    soln[0] = (long int)input[0];
    
    for(i = 1; i < input.size(); ++i)
        soln[i] = soln[i - 1] < 0 ? soln[i - 1] + (long int)input[i] : (long int)input[i];
        
    for(i = 1; i < input.size(); ++i)
        soln[i] = min(soln[i - 1], soln[i]);
}
