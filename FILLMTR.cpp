// problem link: https://www.codechef.com/problems/FILLMTR

/* concept is to partition all vertices into an odd value set and an
 * even value set; |v1 - v2| == 1 means v1 and v2 are in different sets;
 * (i.e. both have opposite labels) and |v1 - v2| == 0 means both have
 * same label. Now problem reduces to finding out if graph is bipartite.
 */
 
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<pair<int, int>>> &);
bool check_bipartite(int, vector<vector<pair<int, int>>> &, vector<int> &);

int main() 
{
	bool flag;
	int i, j, num_tests, num_elements, num_queries, v1, v2, val;
	
	cin >> num_tests;
	
	for(i = 0; i < num_tests; ++i)
	{
	    cin >> num_elements >> num_queries;
	    vector<vector<pair<int, int>>> graph(num_elements);
	    
	    for(j = 0; j < num_queries; ++j)
	    {
	        cin >> v1 >> v2 >> val;
	        graph[v1 - 1].push_back({v2 - 1, val});
	    }
	    
	    flag = isBipartite(graph);
	    
	    if(flag)
	        cout << "yes" << endl;
	    else
	        cout << "no" << endl;
	}
	
	return 0;
}

bool isBipartite(vector<vector<pair<int, int>>> &graph)
{
    bool flag;
    int i, n = graph.size();
    vector<int> colour(n, -1);
    
    // checking all disconnected components
    for(i = 0; i < n; ++i)
    {
        if(colour[i] == -1) // not yet visited
        {
            colour[i] = 0;
            flag = check_bipartite(i, graph, colour);
            
            if(!flag)
                return false;
        }
    }
    
    return true;
}

bool check_bipartite(int vertex, vector<vector<pair<int, int>>> &graph, vector<int> &colour)
{
    bool flag;
    int i, n = graph[vertex].size(), vertex_colour = colour[vertex], next_vert, edge_val;
    
    for(i = 0; i < n; ++i)
    {
        next_vert = graph[vertex][i].first;
        edge_val = graph[vertex][i].second;
        
        if(colour[next_vert] != -1) // next vertex has already been coloured
        {
            if((edge_val == 1 && colour[next_vert] == vertex_colour) || (!edge_val && colour[next_vert] != vertex_colour))
                return false;
            
            continue; // no need to visit next vertex as it has already been visited
        }
        
        if(edge_val)
            colour[next_vert] = 1 - vertex_colour;
        else
            colour[next_vert] = vertex_colour;
            
        flag = check_bipartite(next_vert, graph, colour);
        
        if(!flag)
            return false;
    }
    
    return true;
}
