// https://www.codechef.com/problems/CLETAB

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_min_clean(vector<int> &, int);
int find_seated(vector<pair<int, int>> &, int);
int find_cust_farthest_time(vector<pair<int, int>> &);

int main() 
{
	int i, j, num, num_tests, num_tables, num_orders;
	vector<int> orders;
	
	cin >> num_tests;
	
	for(i = 0; i <= num_tests - 1; ++i)
	{
	    orders.clear();
		cin >> num_tables >> num_orders;

		for(j = 0; j <= num_orders - 1; ++j)
		{
			cin >> num;
			orders.push_back(num);
		}
		
		cout << find_min_clean(orders, num_tables) << endl;
	}
	
	return 0;
}

int find_min_clean(vector<int> &orders, int num_tables)
{
    int i, n = orders.size(), count = 0, next_index, rem_cust, index, max_index;
    vector<pair<int, int>> seated_customers;
    unordered_map<int, queue<int>> order_times;
    
    // step 1: map of vectors containing order times of each customer
    for(i = 0; i <= n - 1; ++i)
    {
        if(order_times.find(orders[i]) == order_times.end())
        {
            queue<int> temp;
            temp.push(i);
            order_times.insert({orders[i], temp});
        }
        else
            order_times[orders[i]].push(i);
    }
    
    for(auto itr = order_times.begin(); itr != order_times.end(); ++itr)
        order_times[itr->first].push(n);
    
    // step 2: process orders
    for(i = 0; i <= n - 1; ++i)
    {
        order_times[orders[i]].pop();
        next_index = order_times[orders[i]].front();
        index = find_seated(seated_customers, orders[i]);
        
        if(index != -1) // customer already seated
        {
            seated_customers[index].second = next_index;
            continue;
        }
        
        if(seated_customers.size() == num_tables)
        {
            max_index = find_cust_farthest_time(seated_customers);
            seated_customers[max_index] = {orders[i], next_index};
        }
        else
            seated_customers.push_back({orders[i], next_index});
            
        ++count;
    }
    
    return count;
}

// find index of customer with maximum next order time
int find_cust_farthest_time(vector<pair<int, int>> &seated_customers)
{
    int max_val = -1, max_index = -1, i, n = seated_customers.size();
    
    for(i = 0; i <= n - 1; ++i)
    {
        if(seated_customers[i].second > max_val)
        {
            max_val = seated_customers[i].second;
            max_index = i;
        }
    }
    
    return max_index;
}

// check if person with 'pid' is seated
int find_seated(vector<pair<int, int>> &seated_customers, int pid)
{
    int i, n = seated_customers.size();
    
    for(i = 0; i <= n - 1; ++i)
    {
        if(seated_customers[i].first == pid)
            return i;
    }
    
    return -1;
}
