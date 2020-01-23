// Link to problem: https://www.codechef.com/problems/NOKIA

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

int find_min(int);
int find_max(int);

int main() 
{
	int t, n, m, min_rope_len, max_rope_len;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> n >> m;
	    min_rope_len = find_min(n);
	    max_rope_len = find_max(n);
	    
	    if(m < min_rope_len)
	        cout << -1 << endl;
	    else
	        cout << max(0, m - max_rope_len) << endl;
	}
	
	return 0;
}

int find_min(int n)
{
    int i, l, r;
    vector<int> DP(n + 1, 0);
    
    for(i = 1; i <= n; ++i)
    {
        l = (int)floor(((double)i - 1) / 2);
        r = (int)ceil(((double)i - 1) / 2);
        DP[i] = DP[l] + DP[r] + i + 1;
    }
    
    return DP[n];
}

int find_max(int n)
{
    int i;
    vector<int> DP(n + 1, 0);
    
    for(i = 1; i <= n; ++i)
        DP[i] = DP[0] + DP[i - 1] + i + 1;
        
    return DP[n];
}
