// https://www.spoj.com/problems/BALIFE/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long int count_num_jobs(vector<int> &);

int main() 
{
	int i, num_processors, num;
	vector<int> jobs;
	
	while((cin >> num_processors) != -1)
	{
		jobs.clear();
		
		for(i = 0; i <= num_processors - 1; ++i)
		{
			cin >> num;
			jobs.push_back(num);
		}
		
		cout << count_num_moves(jobs) << endl;
	}
	
	return 0;
}

long int count_num_jobs(vector<int> &jobs)
{
	int i, n = jobs.size();
	long int sum = 0, prefix_sum = 0, avg, max_count = 0;
	
	for(i = 0; i <= n - 1; ++i)
		sum += (long int)jobs;
	
	if(sum % n)
		return -1;
		
	avg = sum / n;
	
	for(i = 0; i <= n - 1; ++i)
	{
		prefix_sum += (avg - (long int)jobs[i]);
		max_count = max(max_count, (abs)prefix_sum);
	}
	
	return max_count;
}
