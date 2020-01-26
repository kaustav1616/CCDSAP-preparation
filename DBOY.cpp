// problem link: https://www.codechef.com/problems/DBOY

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void min_elements_to_realize_sum(vector<int> &, vector<int> &);
int find_min_trips(vector<int> &, vector<int> &, int);

int main() 
{
	int t, n, i, num, max_dist;
	vector<int> dist, capacity;
	
	cin >> t;
	
    while(t--)
	{
	    dist.clear();
	    capacity.clear();
	    max_dist = INT_MIN;
	    cin >> n;
	    
	    for(i = 0; i < n; ++i)
	    {
	        cin >> num;
	        dist.push_back(2 * num);
	        max_dist = max(max_dist, 2 * num);
	    }
	    
	    for(i = 0; i < n; ++i)
	    {
	        cin >> num;
	        capacity.push_back(num);
	    }
	    
	    cout << find_min_trips(dist, capacity, max_dist) << endl;
	}
	
	return 0;
}

int find_min_trips(vector<int> &dist, vector<int> &capacity, int max_dist)
{
    int i, sum = 0;
    vector<int> DP(max_dist + 1, INT_MAX); // DP[i] stores min number of fillings to fill i litres of petrol
    
    min_elements_to_realize_sum(capacity, DP);
    
    for(i = 0; i < dist.size(); ++i)
        sum += DP[dist[i]];
        
    return sum;
}

// similar to coin change problem (min number of coins to realize value)
void min_elements_to_realize_sum(vector<int> &capacity, vector<int> &DP)
{
    int i, j;
    
    DP[0] = 0;
    
    for(i = 0; i < DP.size(); ++i)
    {
        for(j = 0; j < capacity.size(); ++j)
        {
            if(capacity[j] <= i && DP[i - capacity[j]] != INT_MAX)
                DP[i] = min(DP[i], 1 + DP[i - capacity[j]]);
        }
    }
}
