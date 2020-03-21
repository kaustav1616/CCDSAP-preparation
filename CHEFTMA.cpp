// problem link: https://www.codechef.com/problems/CHEFTMA

// concept: reduce the biggest differences with the biggest possible buttos in descending order

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_min_uncompleted_tasks(vector<int> &, vector<int> &, vector<int> &);
bool cmp(int, int);

int main() 
{
    int num_tests, num_days, num_white, num_black, i, j, input;
    vector<int> planned, completed, buttons;
    
    cin >> num_tests;
    
    for(i = 0; i < num_tests; ++i)
    {
        planned.clear();
        completed.clear();
        buttons.clear();
        cin >> num_days >> num_white >> num_black;
        
        for(j = 0; j < num_days; ++j)
        {
            cin >> input;
            planned.push_back(input);
        }
        
        for(j = 0; j < num_days; ++j)
        {
            cin >> input;
            completed.push_back(input);
        }
        
        for(j = 0; j < num_white + num_black; ++j)
        {
            cin >> input;
            buttons.push_back(input);
        }
        
        cout << find_min_uncompleted_tasks(planned, completed, buttons) << endl;
    }
    
	return 0;
}

int find_min_uncompleted_tasks(vector<int> &planned, vector<int> &completed, vector<int> &buttons)
{
    int i, j = 0, n = planned.size(), m = buttons.size(), num_uncompleted = 0;
    vector<int> diff;
    
    for(i = 0; i < n; ++i)
    {
        diff.push_back(planned[i] - completed[i]);
        num_uncompleted += (planned[i] - completed[i]);
    }
        
    sort(diff.begin(), diff.end(), cmp);
    sort(buttons.begin(), buttons.end(), cmp);
    
    for(i = 0; i < n; ++i)
    {
        while(j < m && buttons[j] > diff[i])
            ++j;
        
        if(j == m)
            break;
        else
        {
            num_uncompleted -= buttons[j];
            ++j;
        }
    }
    
    return num_uncompleted;
}

bool cmp(int i1, int i2)
{
    return (i1 > i2);
}
