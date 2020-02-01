// problem link: https://www.codechef.com/submit/MATRIX2

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long int num_submatrices(vector<vector<long int>> &);

int main() 
{
    int n, m, i, j;
    char num;
    vector<vector<long int>> input;
    
    cin >> n >> m;
    
    for(i = 0; i < n; ++i)
    {
        input.push_back({});
        
        for(j = 0; j < m; ++j)
        {
            cin >> num;
            input[i].push_back(num - '0');
        }
    }
    
    cout << num_submatrices(input) << endl;
    
	return 0;
}

long int num_submatrices(vector<vector<long int>> &input)
{
    int i, j;
    long int count = 0;
    
    for(j = 0; j < input[0].size(); ++j)
    {
        for(i = input.size() - 1; i >= 0; --i)
        {
            if(!input[i][j])
                continue;
                
            if(i == input.size() - 1)
                input[i][j] = 1;
            else
                input[i][j] = input[i + 1][j] + 1;
        }
    }
    
    for(i = 0; i < input.size(); ++i)
    {
        for(j = 0; j < input[i].size(); ++j)
        {
            if(!input[i][j])
                continue;
                
            if(!j)
                input[i][j] = 1;
            else
                input[i][j] = min(input[i][j - 1] + 1, input[i][j]);
                
            count += input[i][j];
        }
    }
    
    return count;
}
