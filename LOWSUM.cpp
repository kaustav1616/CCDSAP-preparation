//  https://www.codechef.com/submit/LOWSUM

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<long int> find_qth_smallest_sum(vector<long int> &, vector<long int> &, vector<pair<int, int>> &);

int main() 
{
	int i, j, num_tests, num_chefs, num_queries, q;
	long int num;
	vector<pair<int, int>> queries;
	vector<long int> motivation, satisfaction, soln;
	
	cin >> num_tests;
	
	for(i = 0; i < num_tests; ++i)
	{
	    cin >> num_chefs >> num_queries;
	    motivation.clear();
	    satisfaction.clear();
	    queries.clear();
	    
	    for(j = 0; j < num_chefs; ++j)
	    {
	        cin >> num;
	        motivation.push_back(num);
	    }
	    
	    for(j = 0; j < num_chefs; ++j)
	    {
	        cin >> num;
	        satisfaction.push_back(num);
	    }
	    
	    for(j = 0; j < num_queries; ++j)
	    {
	        cin >> q;
	        queries.push_back({q, j});
	    }
	    
	    soln = find_qth_smallest_sum(motivation, satisfaction, queries);
	    
	    for(j = 0; j < soln.size(); ++j)
	        cout << soln[j] << endl;
	}
	
	return 0;
}

vector<long int> find_qth_smallest_sum(vector<long int> &motivation, vector<long int> &satisfaction, vector<pair<int, int>> &queries)
{
    int i, j = 0, n1 = motivation.size(), n2 = queries.size(), max_q;
    vector<long int> soln(n2), temp;
    
    struct cmp
    {
        bool operator()(vector<long int> &a, vector<long int> &b)
        {
            return (a[0] > b[0]);
        }
    };
    
    priority_queue<vector<long int>, vector<vector<long int>>, cmp> q;
    sort(motivation.begin(), motivation.end());
    sort(satisfaction.begin(), satisfaction.end());
    sort(queries.begin(), queries.end());
    max_q = queries[n2 - 1].first;
    
    // inserting intital candidates for n1 smallest elements
    for(i = 0; i < n1; ++i)
        q.push({motivation[i] + satisfaction[0], (long int)i, (long int)0});
        
    for(i = 1; i <= max_q + 1; ++i)
    {
        temp = q.top();
        q.pop();
        
        if(temp[2] + 1 < n1)
            q.push({motivation[temp[1]] + satisfaction[temp[2] + 1], temp[1], temp[2] + 1});
            
        while(queries[j].first == i)
        {
            soln[queries[j].second] = temp[0];
            ++j;
        }
    }
    
    return soln;
}
