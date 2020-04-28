// problem link: https://www.codechef.com/submit/SCHEDULE

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_min_max_consec(vector<int> &, int);
bool is_possible(vector<int> &, int, int);
bool is_possible_consec_1(vector<int> &, int);

int main() 
{
	int i, j, num_tests, num_days, max_allowed, num;
	string str;
	vector<int> input;
	
	cin >> num_tests;
	
	for(i = 0; i < num_tests; ++i)
	{
	    scanf("%d%d", &num_days, &max_allowed);
	    input.clear();
	    cin >> str;
	    
	    for(j = 0; j < num_days; ++j)
	        input.push_back((int)(str[j] - '0'));
	    
	    printf("%d\n", find_min_max_consec(input, max_allowed));
	}
	
	return 0;
}

int find_min_max_consec(vector<int> &input, int num_breaks)
{
    bool flag;
    int i, n = input.size(), count = 1, low, high, mid, max_consec = 0;
    vector<int> consec;
    
    // fill 'consec' array (stores lengths of all consecutive runs of any element)
    for(i = 1; i < n; ++i)
    {
        if(input[i] == input[i - 1]) // extend already active run of consecutive elements
            ++count;
        else // start new run
        {
            consec.push_back(count);
            max_consec = max(max_consec, count);
            count = 1;
        }
        
        if(i == n - 1)
        {
            consec.push_back(count);
            max_consec = max(max_consec, count);
        }
    }
    
    // calculate min value of max consecutive gap
    flag = is_possible_consec_1(input, num_breaks);
    
    if(flag)
        return 1;
    
    low = 2; // min val of max consecutive run
    high = max_consec; // max val of max consecutive run
    
    while(low <= high)
    {
        /* check if all consec runs can be limited to 'mid' (i.e. after reduction 
         * of consec runs, max of reduced values can be limited to this)
         */
        mid = low + (high - low) / 2; 
        flag = is_possible(consec, mid, num_breaks);
        
        if(flag)
            high = mid - 1;
        else
            low = mid + 1;
    }
    
    return low;
}

// check if possible to get max consec run of length 1
bool is_possible_consec_1(vector<int> &input, int num_breaks)
{
    int i, n = input.size(), count1 = 0, count2 = 0, min_count;
    vector<int> choice_1(n), choice_2(n);
    
    choice_1[0] = 0; // alternating numbers starting at 0
    choice_2[0] = 1; // alternating numbers starting at 0
    
    for(i = 1; i < n; ++i)
    {
        choice_1[i] = 1 - choice_1[i - 1];
        choice_2[i] = 1 - choice_2[i - 1];
    }
    
    for(i = 0; i < n; ++i)
    {
        if(input[i] != choice_1[i])
            ++count1; // cost to make input equal to choice_1
        
        if(input[i] != choice_2[i])
            ++count2; // cost to make input equal to choice_1
    }
    
    min_count = min(count1, count2);
    return (min_count <= num_breaks);
}

bool is_possible(vector<int> &consec, int max_allowed, int num_breaks)
{
    int i, n = consec.size(), breaks_req;
    
    for(i = 0; i < n; ++i)
    {
        breaks_req = consec[i] / (max_allowed + 1);
        
        if(breaks_req > num_breaks)
            return false;
            
        num_breaks -= breaks_req;
    }
    
    return true;
}
