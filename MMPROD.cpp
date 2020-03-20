// problem link: https://www.codechef.com/problems/MMPROD

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_max_prod(vector<int> &, int);
long int find_mod(long int);

int main() 
{
	int i, j, num_tests, num_elements, num_prod, num;
	vector<int> input;
	
	cin >> num_tests;
	
	for(i = 0; i < num_tests; ++i)
	{
	    input.clear();
	    cin >> num_elements >> num_prod;
	    
	    for(j = 0; j < num_elements; ++j)
	    {
	        cin >> num;
	        input.push_back(num);
	    }
	    
	    cout << find_max_prod(input, num_prod) << endl;
	}
	
	return 0;
}

int find_max_prod(vector<int> &input, int num_prod)
{
    int i, n = input.size(), start = 0, end = input.size() - 1, count = num_prod;
    long int prod = 1, poss1, poss2;
    
    sort(input.begin(), input.end());
    
    if(num_prod % 2 == 1 && input[n - 1] < 0) // odd number of inputs + all inputs (-)ve
    {
        for(i = n - 1; i >= n - num_prod; --i)
        {
            prod = prod * (long int)input[i];
            prod = find_mod(prod);
        }
        
        return (int)prod;
    }
    
    while(start <= end)
    {
        if(!count)
            return (int)prod;
            
        if(count == 1)
        {
            prod = max(prod * (long int)input[start], prod * (long int)input[end]);
            prod = find_mod(prod);
            return (int)prod;
        }
        
        /* if product of smallest 2 (-ve) numbers is greater than the product of 
         * largest 2 (+ve) numbers, add smallest 2 (-ve)nos. ((-ve) nos. to be 
         * always added in pairs) or add the largest (+ve) no. (logic) is
         * extension of 'greatest product with 3 numbers' problem
         */
        poss1 = (long int)input[start] * (long int)input[start + 1];
        poss2 = (long int)input[end] * (long int)input[end - 1];
        
        if(poss1 > poss2)
        {
            poss1 = find_mod(poss1);
            prod *= poss1;
            prod = find_mod(prod);
            start += 2;
            count -= 2;
        }
        else
        {
            prod *= (long int)input[end];
            prod = find_mod(prod);
            --end;
            --count;
        }
    }
    
    return -1;
}

long int find_mod(long int num)
{
    long int mod = 1000000007;
    
    if(num >= 0)
        return (num % mod);
        
    num *= -1;
    return ((long int)ceil((double)num / (double)mod) * mod - num);
}
