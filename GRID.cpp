// problem link: https://www.codechef.com/submit/GRID

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_num_squares(vector<vector<char>> &);

int main()
{
	int t, n, i, j;
	char ch;
	vector<vector<char>> input;
	
	cin >> t;
	
	while(t--)
	{
	    input.clear();
	    cin >> n;
	    
	    for(i = 0; i < n; ++i)
	    {
	        input.push_back({});
	        
	        for(j = 0; j < n; ++j)
	        {
	            cin >> ch;
	            input[i].push_back(ch);
	        }
	    }
	    
	    cout << find_num_squares(input) << endl;
	}
	
	return 0;
}

int find_num_squares(vector<vector<char>> &input)
{
    int i, j, n = input.size(), count = 0;
    vector<vector<int>> DP(n, vector<int> (n, 0));
    
    /* check if square is reachable from respective easternmost square */
    for(i = 0; i < n; ++i)
    {
        for(j = n - 1; j >= 0; --j)
        {
            if(input[i][j] == '#')
                break;
                
            ++DP[i][j];
        }
    }
    
    /* check if square is reachable from respective southernmost square */
    for(i = 0; i < n; ++i)
    {
        for(j = n - 1; j >= 0; --j)
        {
            if(input[j][i] == '#')
                break;
                
            ++DP[j][i];
                
            if(DP[j][i] == 2)
                ++count;
        }
    }
    
    return count;
}
