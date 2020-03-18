// problem link: https://www.codechef.com/submit/CIELRCPT
// proof: 1) Formula approach; 2) Greedy approach (reduces to fomrula approach)
// specific case of coin change problem where every multiple of every denomination <= req change is present in set of denominations

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_num_menus(int, vector<int> &);

int main() 
{
	int num_tests, amt;
	vector<int> menu = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};
	
	cin >> num_tests;
	
	while(num_tests--)
	{
	    cin >> amt;
	    cout << find_num_menus(amt, menu) << endl;
	}
	
	return 0;
}

int find_num_menus(int amt, vector<int> &menu)
{
    int count = 0, index;
    
    while(amt > 0)
    {
        ++count;
        auto itr = upper_bound(menu.begin(), menu.end(), amt);
        --itr;
        index = itr - menu.begin();
        amt -= menu[index];
    }
    
    return count;
}
