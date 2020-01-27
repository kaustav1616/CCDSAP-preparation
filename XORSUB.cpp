// problem link: https://www.codechef.com/problems/XORSUB

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_max_xor(vector<int> &, int);

int main() 
{
	int t, k, n, num, i;
	vector<int> input;
	
	cin >> t;
	
	while(t--)
	{
	    input.clear();
	    cin >> n >> k;
	    
	    for(i = 0; i < n; ++i)
	    {
	        cin >> num;
	        input.push_back(num);
	    }
	    
	    cout << find_max_xor(input, k) << endl;
	}
	
	return 0;
}

int find_max_xor(vector<int> &input, int k)
{
    int i, j, max_xor = INT_MIN;
    // DP[i][j] denotes if possible to have subset xor = j with input[1..i]
    vector<vector<int>> DP(input.size() + 1, vector<int> (1024, 0));
    
    DP[0][0] = 1;
    
    for(i = 1; i < DP.size(); ++i)
    {
        for(j = 0; j < 1024; ++j)
        {
            if(DP[i - 1][j] == 1)
            {
                DP[i][j] = 1; // if possible to have subarray xor = j with [1..i - 1], possible with [1..i]
                DP[i][j ^ input[i - 1]] = 1;
            }
        }
    }
    
    for(i = 0; i < 1024; ++i)
    {
        if(DP[DP.size() - 1][i] == 1)
            max_xor = max(max_xor, i ^ k);
    }
    
    return max_xor;
}
