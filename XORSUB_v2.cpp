// problem link: https://www.codechef.com/submit/XORSUB

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
    int i, j, max_xor = k;
    // DP[j] denotes if possible to have subset xor = j
    vector<int> DP(1024, 0);
    
    DP[0] = 1;
    
    for(i = 0; i < input.size(); ++i)
    {
        for(j = 0; j < 1024; ++j)
        {
            if(DP[j] == 1)
            {
                DP[j ^ input[i]] = 1; // if(subset xor = j possible, subset xor of input[i] ^ j also possible)
                max_xor = max(max_xor, j ^ input[i] ^ k);
            }
        }
    }
    
    return max_xor;
}
