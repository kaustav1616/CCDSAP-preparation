// problem link: https://www.spoj.com/problems/KFSTB/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long int find_num_ways(int, int, vector<vector<int>> &, vector<long int> &);

int main() 
{
	int i, j, num_tests, num_camps, num_bridges, start, end, src, dest;
	
	cin >> num_tests;
	
	for(i = 0; i < num_tests; ++i)
	{
	    cin >> num_camps >> num_bridges >> start >> end;

        vector<long int> memo(num_camps, -1);
        vector<vector<int>> adj_list(num_camps);

        for(j = 0; j < num_bridges; ++j)
        {
            cin >> src >> dest;
            --src;
            --dest;
            adj_list[src].push_back(dest);
        }

        cout << find_num_ways(start - 1, end - 1, adj_list, memo) << endl;
	}
	
	return 0;
}

long int find_num_ways(int root, int dest, vector<vector<int>> &adj_list, vector<long int> &memo)
{
    if(memo[root] != -1)
        return memo[root];

    if(root == dest)
        return (memo[root] = 1);
    
    int i, n = adj_list[root].size();
    long int num_ways = 0, m = 1000000007;

    for(i = 0; i < n; ++i)
    {
        num_ways += find_num_ways(adj_list[root][i], dest, adj_list, memo);
        num_ways %= m;
    }

    return (memo[root] = num_ways);
}
