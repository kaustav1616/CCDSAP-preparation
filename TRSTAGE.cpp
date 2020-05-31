// problem link: https://www.spoj.com/problems/TRSTAGE/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double find_min_cost(vector<int> &, vector<vector<pair<int, int>>> &, int, int, int, int, vector<vector<double>> &);

int main()
{
    int i, j, num_tckts, num_cities, num_roads, src, dest, horses, s, d, w;
    double min_val;
    vector<int> tckts;
    vector<vector<double>> memo;
    vector<vector<pair<int, int>>> graph;
    
    cin >> num_tckts >> num_cities >> num_roads >> src >> dest;

    while(num_tckts || num_cities || num_roads || src || dest)
    {
        tckts.clear();
        memo.clear();
        graph.clear();

        // init
        for(i = 0; i < num_cities; ++i)
        {
            memo.push_back({});
            graph.push_back({});

            for(j = 0; j < 256; ++j)
                memo[i].push_back(-1);
        }

        for(i = 0; i < num_tckts; ++i)
        {
            cin >> horses;
            tckts.push_back(horses);
        }

        for(i = 0; i < num_roads; ++i)
        {
            cin >> s >> d >> w;
            // bidirectional graph
            graph[s - 1].push_back({d - 1, w});
            graph[d - 1].push_back({s - 1, w});
        }

        min_val = find_min_cost(tckts, graph, src - 1, dest - 1, 0, num_tckts, memo);
        
        if(min_val == INT_MAX)
            cout << "Impossible" << endl;
        else
            cout << min_val << endl;
            
        cin >> num_tckts >> num_cities >> num_roads >> src >> dest;
    }

    return 0;
}

/* min_cost[root, used_mask] = min time taken to go from 'root' to dest 
 * with unused tickets represented by 'used_mask' (kind of similar to Floyd-Warshall)
 */
double find_min_cost(vector<int> &tckts, vector<vector<pair<int, int>>> &graph, int root, int dest, int used_mask, int num_tckts, vector<vector<double>> &memo)
{
    if(memo[root][used_mask] != -1) // already calculated
        return memo[root][used_mask];

    if(root == dest) // base case (reached destination)
        return (memo[root][used_mask] = 0);

    if(used_mask == (1 << num_tckts) - 1) // base case (all tickets used) (but not reached destination)
        return (memo[root][used_mask] = INT_MAX);

    int i, j, n = graph[root].size();
    double cost, min_cost = INT_MAX;

    for(i = 0; i < n; ++i) // iterating over all possible next cities
    {
        for(j = 0; j < num_tckts; ++j) // iterating over all tickets
        {
            if((used_mask >> j) & 1) // check if ticket is used
                continue;

            cost = find_min_cost(tckts, graph, graph[root][i].first, dest, used_mask | (1 << j), num_tckts, memo);

            if(cost == INT_MAX)
                continue;

            cost += ((double)graph[root][i].second / (double)tckts[j]);
            min_cost = min(min_cost, cost);
        }
    }

    return (memo[root][used_mask] = min_cost);
}
