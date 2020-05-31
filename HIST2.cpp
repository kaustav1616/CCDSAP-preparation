// problem link: https://www.spoj.com/problems/HIST2/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int calc_new_per(int, int, int);
pair<int, int> calc_max_perimeter(vector<int> &, int, int, vector<vector<pair<int, int>>> &);

int main() 
{
	int i, j, num_elements, ht, val, max_val, count;
	pair<int, int> soln;
	vector<int> input;
	vector<vector<pair<int, int>>> memo;
	unordered_map<int, int> m;
	
	while(1)
	{
		input.clear();
		memo.clear();
		max_val = INT_MIN;
		count = 0;
		m.clear();
		cin >> num_elements;
		
		if(!num_elements)
			break;
			
		// init
		for(i = 0; i < (1 << num_elements); ++i)
		{
			memo.push_back({});
			
			for(j = 0; j < num_elements; ++j)
				memo[i].push_back({-1, -1});
		}
			
		for(i = 0; i < num_elements; ++i)
		{
			cin >> ht;
			input.push_back(ht);
		}
		
		for(i = 0; i < num_elements; ++i)
		{
			soln = calc_max_perimeter(input, 0, i, memo);
			val = soln.first;
			max_val = max(max_val, val);
			
			if(m.find(val) == m.end())
			    m.insert({val, soln.second});
			else
			    m[val] += soln.second;
		}
		
		cout << max_val << " " << m[max_val] << endl;
	}
	
	return 0;
}

/* calc_max_perimeter[used_mask, last_index] = 
 * {max perimeter with 'last index' being index of histogram to be placed last and used_mask denoting indices of used histograms,
 * count of number of times this particular perimeter has occurred}
 */
pair<int, int> calc_max_perimeter(vector<int> &input, int used_mask, int last_index, vector<vector<pair<int, int>>> &memo)
{
	if(memo[used_mask][last_index] != make_pair(-1, -1)) // already calculated
		return memo[used_mask][last_index];
		
	int i, n = input.size(), new_per, val, max_val = INT_MIN, num_used = __builtin_popcount(used_mask);
	pair<int, int> soln;
	unordered_map<int, int> m;
	
	if(num_used == n - 1) // base case (first histogram to be placed)
	    return (memo[used_mask][last_index] = {2 * (1 + input[last_index]), 1});
	
	for(i = 0; i < n; ++i) // next rectangle to place
	{
		if(((used_mask >> i) & 1) || i == last_index) // already placed
			continue;
			
		soln = calc_max_perimeter(input, used_mask | (1 << last_index), i, memo); // vall with hist[i] = second last rectangle placed
		val = soln.first;
		val += (2 * (1 + input[last_index])); // add perimeter due to current histogram
		val -= 2 * min(input[i], input[last_index]); // subtract overlapping boundary with second last histogram
		max_val = max(val, max_val);
		
		if(m.find(val) == m.end())
		    m.insert({val, soln.second});
	    else
	        m[val] += soln.second;
	}
	
	return (memo[used_mask][last_index] = {max_val, m[max_val]});
}
