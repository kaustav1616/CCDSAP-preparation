// problem link: https://www.spoj.com/problems/GCJ101BB/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_min_swaps(int, int, int, int, vector<int> &, vector<int> &);

int main() 
{
	int i, j, num, num_tests, num_chicks, min_req, barn_posn, req_time, soln;
	vector<int> posn, speed;
	
	cin >> num_tests;
	
	for(i = 0; i <= num_tests - 1; ++i)
	{
	    posn.clear();
	    speed.clear();
		cin >> num_chicks >> min_req >> barn_posn >> req_time;

		for(j = 0; j <= num_chicks - 1; ++j)
		{
			cin >> num;
			posn.push_back(num);
		}
		
		for(j = 0; j <= num_chicks - 1; ++j)
		{
			cin >> num;
			speed.push_back(num);
		}
		
		soln = find_min_swaps(num_chicks, min_req, barn_posn, req_time, posn, speed);
		cout << "Case #" << i + 1 << ": ";
		
		if(soln == -1)
		    cout << "IMPOSSIBLE" << endl;
		else
		    cout << soln << endl;
	}
	
	return 0;
}

int find_min_swaps(int num_chicks, int min_req, int barn_posn, int req_time, vector<int> &posn, vector<int> &speed)
{
    int i, count_can_reach = 0, curr_swaps = 0, total_swaps = 0;
    long int dist_to_cover, dist_can_cover;
    
    for(i = num_chicks - 1; i >= 0; --i)
    {
        dist_to_cover = barn_posn - posn[i];
        dist_can_cover = (long int)speed[i] * (long int)req_time;
        
        if(dist_can_cover >= dist_to_cover)
        {
            ++count_can_reach;
            total_swaps += curr_swaps;
        }
        else
            ++curr_swaps;
            
        if(count_can_reach == min_req)
            break;
    }
    
    if(count_can_reach < min_req)
        return -1;
        
    return total_swaps;
}
