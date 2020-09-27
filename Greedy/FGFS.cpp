// https://www.codechef.com/submit/FGFS

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_max_cust_dine(unordered_map<int, vector<pair<int, int>>> &);
bool cmp(const pair<int, int> &, const pair<int, int> &);
int find_max_non_overlap_intervals(vector<pair<int, int>> &) ;

int main() 
{
	int i, j, num_tests, num_customers, num_booths, start, end, booth;
	unordered_map<int, vector<pair<int, int>>> booths;
	
	scanf("%d", &num_tests);
	
	for(i = 0; i <= num_tests - 1; ++i)
	{
		booths.clear();
		scanf("%d%d", &num_customers, &num_booths);

		for(j = 0; j <= num_customers - 1; ++j)
		{
			scanf("%d%d%d", &start, &end, &booth);
			
			if(booths.find(booth) == booths.end())
			    booths.insert({booth, {{start, end}}});
			else
			    booths[booth].push_back({start, end});
		}
		
		printf("%d\n", find_max_cust_dine(booths));
	}
	
	return 0;
}

int find_max_cust_dine(unordered_map<int, vector<pair<int, int>>> &booths)
{
    int count = 0;
    
    for(auto itr = booths.begin(); itr != booths.end(); ++itr)
        count += find_max_non_overlap_intervals(itr->second);
        
    return count;
}

int find_max_non_overlap_intervals(vector<pair<int, int>> &start_stop) 
{
    int i, count = 1, stop, n = start_stop.size();
        
    /* sort by ascending order of end times
     * within tasks with same end times, sort by descending order of start time
     */
    sort(start_stop.begin(), start_stop.end(), cmp);
    stop = start_stop[0].second;
    
    for(i = 1; i <= n - 1; ++i)
    {
        if(start_stop[i].first >= stop)
        {
            ++count;
            stop = start_stop[i].second;
        }
    }
    
    return count;
}
 
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if(p1.second < p2.second)
        return true;
    else if(p1.second == p2.second && p1.first > p2.first)
        return true;
        
    return false;
}
