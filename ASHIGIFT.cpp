// problem link: https://www.codechef.com/problems/ASHIGIFT

// concept: 1-D version of Dungeon princess (with slight modification)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long int find_min_people(vector<vector<long int>> &);
bool cmp(const vector<long int> &, const vector<long int> &);

int main() 
{
	int i, j, num_tests, dest, num_dishes, num_chiefs, dist;
	long int num1, num2;
	vector<vector<long int>> checkpts;
	
	cin >> num_tests;
	
	for(i = 0; i < num_tests; ++i)
	{
	    checkpts.clear();
	    cin >> dest >> num_dishes;
	    
	    for(j = 0; j < num_dishes; ++j)
	    {
	        cin >> dist >> num1;
	        checkpts.push_back({dist, num1, -1});
	    }
	    
	    cin >> num_chiefs;
	    
	    for(j = 0; j < num_chiefs; ++j)
	    {
	        cin >> dist >> num1 >> num2;
	        checkpts.push_back({dist, num1, num2});
	    }
	    
	    cout << find_min_people(checkpts) << endl;
	}
	
	return 0;
}

long int find_min_people(vector<vector<long int>> &checkpts)
{
    int i, n = checkpts.size();
    long int num_req, temp;
    vector<long int> DP(n + 1);
    
    DP[n] = 1;
    sort(checkpts.begin(), checkpts.end(), cmp);
    
    for(i = n - 1; i >= 0; --i)
    {
        if(checkpts[i][2] == -1) // food present
            DP[i] = DP[i + 1] + checkpts[i][1];
        else // tribal clan present
        {
            if(checkpts[i][1] > DP[i + 1]) // better to pass through without taking help
                DP[i] = DP[i + 1];
            else
                DP[i] = max(max(DP[i + 1] - checkpts[i][2], (long int)1), checkpts[i][1]);
        }
    }
        
    return DP[0];
}

bool cmp(const vector<long int> &v1, const vector<long int> &v2)
{
    return (v1[0] < v2[0]);
}
