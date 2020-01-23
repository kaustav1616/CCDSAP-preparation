// Link to problem: https://www.codechef.com/problems/NOKIA

#include <iostream>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> find_min_max(int);

int main() 
{
	int t, n, m, min_rope_len, max_rope_len;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> n >> m;
	    min_rope_len = find_min_max(n).first;
	    max_rope_len = find_min_max(n).second;
	    
	    if(m < min_rope_len)
	        cout << -1 << endl;
	    else
	        cout << max(0, m - max_rope_len) << endl;
	}
	
	return 0;
}

// approach: DP_min[i] = i + 1 + min(DP_min[j] + DP_min[i - j - 1]), for all j
pair<int, int> find_min_max(int n)
{
    int i, j, min_val, max_val;
    vector<int> DP_min(n + 1, 0), DP_max(n + 1, 0);
    
    DP_min[1] = 2;
    DP_max[1] = 2;
    
    for(i = 2; i <= n; ++i)
    {
        min_val = INT_MAX;
        max_val = INT_MIN;
        
        for(j = 1; j < i; ++j)
        {
            min_val = min(min_val, i + 1 + DP_min[j] + DP_min[i - j - 1]);
            max_val = max(max_val, i + 1 + DP_max[j] + DP_max[i - j - 1]);
        }
        
        DP_min[i] = min_val;
        DP_max[i] = max_val;
    }
    
    return make_pair(DP_min[n], DP_max[n]);
}
