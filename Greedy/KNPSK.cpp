// problem link: https://www.codechef.com/submit/KNPSK

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<long int> calc_max_value(vector<pair<int, int>> &);
bool cmp(const pair<int, int> &, const pair<int, int> &);

int main() 
{
	int i, num_items, wt, cost;
	vector<long int> soln;
	vector<pair<int, int>> input;
	
	cin >> num_items;
	
	for(i = 0; i <= num_items - 1; ++i)
	{
	    cin >> wt >> cost;
	    input.push_back({cost, wt});
	}
	
	soln = calc_max_value(input);
	
	for(i = 1; i <= soln.size() - 1; ++i)
	    cout << soln[i] << " ";
	    
	cout << endl;
	return 0;
}

vector<long int> calc_max_value(vector<pair<int, int>> &input)
{
    int i, n = input.size(), sum_wt = 0, ptr1 = 0, ptr2 = 0, n1, n2, c1, c2;
    vector<int> wt1, wt2;
    
    sort(input.begin(), input.end(), cmp);
    
    // separate into weight 1 and 2 items
    for(i = 0; i <= n - 1; ++i)
    {
        if(input[i].second == 1)
            wt1.push_back(input[i].first);
        else
            wt2.push_back(input[i].first);
            
        sum_wt += input[i].second;
    }
    
    n1 = wt1.size();
    n2 = wt2.size();
        
    vector<long int> max_val(sum_wt + 1, 0);
    
    // even
    for(i = 2; i <= sum_wt; i += 2)
    {
        c1 = -1;
        
        if(ptr1 < n1)
            c1 = wt1[ptr1];
            
        if(ptr1 + 1 < n1)
            c1 += wt1[ptr1 + 1];
            
        if(ptr2 == n2)
            c2 = -1;
        else
            c2 = wt2[ptr2];
            
        if(c1 > c2)
        {
            max_val[i] = max_val[i - 2] + c1;
            ptr1 += 2;
        }
        else
        {
            max_val[i] = max_val[i - 2] + c2;
            ++ptr2;
        }
    }
    
    // odd
    ptr1 = 0;
    ptr2 = 0;
    
    if(n1)
    {
        max_val[1] = wt1[0];
        ptr1 = 1;
    }
    
    for(i = 3; i <= sum_wt; i += 2)
    {
        c1 = -1;
        
        if(ptr1 < n1)
            c1 = wt1[ptr1];
            
        if(ptr1 + 1 < n1)
            c1 += wt1[ptr1 + 1];
            
        if(ptr2 == n2)
            c2 = -1;
        else
            c2 = wt2[ptr2];
            
        if(c1 > c2)
        {
            max_val[i] = max_val[i - 2] + c1;
            ptr1 += 2;
        }
        else
        {
            max_val[i] = max_val[i - 2] + c2;
            ++ptr2;
        }
    }
    
    return max_val;
}

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    return (p1.first > p2.first);
}
