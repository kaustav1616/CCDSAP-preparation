// https://www.spoj.com/problems/PT07Z/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_max_num_edges(int, vector<vector<int>> &, int, int *);

int main() 
{
	int i, num_nodes, src, dest, max_num_edges = 0, temp;
	
	cin >> num_nodes;

    vector<vector<int>> adj_list(num_nodes);
	
	for(i = 0; i < num_nodes - 1; ++i)
	{
	    cin >> src >> dest;
        --src;
        --dest;
        adj_list[src].push_back(dest);
        adj_list[dest].push_back(src);
	}
	
	temp = find_max_num_edges(0, adj_list, -1, &max_num_edges);
    cout << max_num_edges << endl;
    return 0;
}

/* returns max depth of any subtree rooted at this vertex and updates max 
 * no. of edges between two vertices in its subtree in a path going through it
 */
int find_max_num_edges(int root, vector<vector<int>> &adj_list, int parent, int *max_num_edges)
{
    int i, child, n = adj_list[root].size(), depth, max_depth = 0, second_max_depth = 0;
    
    for(i = 0; i < n; ++i)
    {
        child = adj_list[root][i];
        
        if(child == parent)
            continue;
            
        depth = find_max_num_edges(child, adj_list, root, max_num_edges);
        
        if(depth > max_depth)
        {
            second_max_depth = max_depth;
            max_depth = depth;
        }
        else if(depth > second_max_depth && depth <= max_depth)
            second_max_depth = depth;
    }
    
    *max_num_edges = max(*max_num_edges, max_depth + second_max_depth);
    return (max_depth + 1);
}
