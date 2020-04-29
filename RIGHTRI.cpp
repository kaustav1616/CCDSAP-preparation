// problem link: https://www.codechef.com/submit/RIGHTTRI

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long double calc_func(long double, long double);
vector<long double> find_sides(long double, long double);

int main() 
{
	int i, j, num_tests;
	long double hyp, area;
	vector<long double> soln;
	
	cin >> num_tests;
	
	for(i = 0; i < num_tests; ++i)
	{
	    cin >> hyp >> area;
	    soln = find_sides(hyp, area);
	    
	    for(j = 0; j < soln.size(); ++j)
	        printf("%.6Lf ", soln[j]);
	        
	    cout << endl;
	}
	
	return 0;
}

vector<long double> find_sides(long double hyp, long double area)
{
    long double low, high, mid, change = 0.0000000000001, func_val, det, val1, val2;
    vector<long double> soln(3);
    
    val1 = hyp * hyp * hyp * hyp;
    val2 = (long double)16 * area * area;
    det = val1 - val2;
    
    if(det < (long double)0)
        return {-1};
    
    low = hyp / (long double)sqrt(2);
    high = hyp - change;
    
    while(low <= high)
    {
        mid = low + (high - low) / (long double)2;
        func_val = calc_func(mid, hyp);
            
        if(func_val > area)
            low = mid + change;
        else
            high = mid - change;
    }
    
    if(mid < 0)
        return {-1};
    
    soln[0] = low;
    soln[1] = hyp;
    soln[2] = (long double)sqrt(hyp * hyp - low * low); 
    sort(soln.begin(), soln.end());
    return soln;
}

long double calc_func(long double base, long double hyp)
{
    return ((long double)0.5 * base * (long double)sqrt(hyp * hyp - base * base));
}
