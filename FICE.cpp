// problem link: https://www.codechef.com/problems/FICE

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int calc_ways(int, int, vector<int> &);

int main() 
{
	int t, num_req_soldiers, mod;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> num_req_soldiers >> mod;
	    vector<int> DP(num_req_soldiers + 1, -1);
	    cout << (2 * calc_ways(num_req_soldiers, mod, DP)) % mod << endl;
	}
	
	return 0;
}

int calc_ways(int num_req_soldiers, int mod, vector<int> &DP)
{
    if(DP[num_req_soldiers] != -1)
        return DP[num_req_soldiers];
        
    if(!num_req_soldiers)
        return (DP[0] = 0);
        
    if(num_req_soldiers == 1)
        return (DP[1] = 1);
        
    int k;
    long int val1, val2, soln;
    
    if(num_req_soldiers % 2)
    {
        k = (num_req_soldiers + 1) / 2;
        val1 = (long int)calc_ways(k, mod, DP);
        val2 = (long int)calc_ways(k - 1, mod, DP);
        soln = (val1 * val1 + val2 * val2) % (long int)mod;
    }
    else
    {
        k = num_req_soldiers / 2;
        val1 = (long int)calc_ways(k, mod, DP);
        val2 = (long int)calc_ways(k - 1, mod, DP);
        soln = ((2 * val2 + val1) * val1) % (long int)mod;
    }
    
    return (DP[num_req_soldiers] = (int)soln);
}
