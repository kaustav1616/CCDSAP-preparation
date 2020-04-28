// problem link: https://www.codechef.com/submit/SNTEMPLE

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long int calc_min_ops(vector<int> &);

int main() 
{
	int i, j, num_tests, num_elements, height;
	vector<int> heights;
	
	cin >> num_tests;
	
	for(i = 0; i < num_tests; ++i)
	{
	    cin >> num_elements;
	    heights.clear();
	    
	    for(j = 0; j < num_elements; ++j)
	    {
	        cin >> height;
	        heights.push_back(height);
	    }
	    
	    cout << calc_min_ops(heights) << endl;
	}
	
	return 0;
}

long int calc_min_ops(vector<int> &height)
{
    int i, n = height.size(), curr_size, max_size = 0, req = 1;
    long sum_height = (long int)height[0];
    // ascending_till_here[i] stores 'm' if elements in [height[i - m + 1] .. height[i]] are >= [1, 2, .., m]
    vector<int> ascending_till_here(n, 1), descending_from_here(n, 1);
    
    // calculate number of continuous ascending blocks till here
    for(i = 1; i < n; ++i)
    {
        sum_height += (long int)height[i];
        
        if(height[i] >= req)
        {
            ascending_till_here[i] = ascending_till_here[i - 1] + 1;
            ++req;
        }
        else 
        {
            /* if height[i] < 'req', and a sequence [1 .. req] has already been 
             * created till i - 1, sequence [1 .. height[i] can also be created till i.
             */
            ascending_till_here[i] = height[i]; 
            req = height[i] + 1;
        }
    }
    
    // calculate number of continuous descending blocks from here
    req = 1;
    
    for(i = n - 2; i >= 0; --i)
    {
        if(height[i] >= req)
        {
            descending_from_here[i] = descending_from_here[i + 1] + 1;
            ++req;
        }
        else
        {
            descending_from_here[i] = height[i];
            req = height[i] + 1;
        }
    }
    
    /* find maximum size of temple that can be constructed, since
     * greater the size, lesser the reduction in stones required;
     * if n = number of blocks of ascending height in temple, sum
     * of heights of blocs = n^2 and reduction = sum - n^2; therefore,
     * greater is n, lesser is the reduction
     */
    for(i = 0; i < n; ++i)
    {
        curr_size = min(ascending_till_here[i], descending_from_here[i]);
        max_size = max(max_size, curr_size);
    }
    
    return (sum_height - (long int)max_size * (long int)max_size);
}
