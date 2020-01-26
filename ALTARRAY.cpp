// problem link: https://www.codechef.com/problems/ALTARAY

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_max_len_seq(vector<int> &);

int main() 
{
	int t, n, i, num;
	vector<int> input;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> n;
	    input.clear();
	    
	    for(i = 0; i < n; ++i)
	    {
	        cin >> num;
	        input.push_back(num);
	    }
	    
	    find_max_len_seq(input);
	}
	
	return 0;
}

int find_max_len_seq(vector<int> &input)
{
    bool prev_flag, curr_flag;
    int i;
    
    prev_flag = input[input.size() - 1] < 0 ? 0 : 1;
    input[input.size() - 1] = 1;
    
    for(i = input.size() - 2; i >= 0; --i)
    {
        curr_flag = input[i] < 0 ? 0 : 1;
        
        if(curr_flag ^ prev_flag == 1) // previous element and current element are different
            input[i] = input[i + 1] + 1; // extending previous sequence
        else
            input[i] = 1; // start of a new sequence
            
        prev_flag = curr_flag;
    }
    
    for(i = 0; i < input.size(); ++i)
        cout << input[i] << " ";
        
    cout << endl;
}
