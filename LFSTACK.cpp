// problem link: https://www.codechef.com/problems/LFSTACK

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check_possible(vector<vector<int>> &, vector<int> &, vector<int> &, int, map<vector<int>, bool> &);

int main() 
{
	bool flag;
	int i, j, t, num_threads, num, total_num, n;
	vector<int> seq, indexes;
	vector<vector<int>> input;
	map<vector<int>, bool> DP;
	
	cin >> t;
	
	while(t--)
	{
	    total_num = 0;
	    seq.clear();
	    input.clear();
	    indexes.clear();
	    DP.clear();
	    cin >> num_threads;
	    
	    for(i = 0; i < num_threads; ++i)
	    {
	        cin >> num;
	        indexes.push_back(num - 1);
	        total_num += num;
	        input.push_back({});
	        
	        for(j = 0; j < num; ++j)
	        {
	            cin >> n;
	            input[i].push_back(n);
	        }
	    }
	    
	    for(i = 0; i < total_num; ++i)
	    {
	        cin >> n;
	        seq.push_back(n);
	    }
	    
	    reverse(seq.begin(), seq.end());
	    
	    if(num_threads == 1)
	        flag = (input[0] == seq);
	    else
	        flag = check_possible(input, indexes, seq, total_num - 1, DP);
	    
	    if(flag)
	        cout << "Yes" << endl;
	    else
	        cout << "No" << endl;
	}
	
	return 0;
}

bool check_possible(vector<vector<int>> &input, vector<int> &indexes, vector<int> &seq, int seq_index, map<vector<int>, bool> &DP)
{
    if(DP.find(indexes) != DP.end()) // already calculated before
        return DP[indexes];
        
    if(seq_index == -1) // base case
        return true;
        
    bool flag;
    int i, index;
    
    for(i = 0; i < input.size(); ++i)
    {
        if(indexes[i] == -1) 
            continue;
            
        if(input[i][indexes[i]] == seq[seq_index])
        {
            --indexes[i];
            flag = check_possible(input, indexes, seq, seq_index - 1, DP);
            ++indexes[i];
            
            if(flag)
            {
                DP.insert({indexes, flag});
                
                return DP[indexes];
            }
        }
    }
    
    DP.insert({indexes, flag});
    
    return DP[indexes];
}
