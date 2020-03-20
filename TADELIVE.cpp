// problem link: https://www.codechef.com/problems/TADELIVE

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int find_max(vector<int> &, vector<int> &, int, int);
bool cmp(const vector<int> &, const vector<int> &);

int main() 
{
	int i, num_orders, num_A, num_B, num;
	vector<int> A, B;
	
	cin >> num_orders >> num_A >> num_B;
	
	for(i = 0; i < num_orders; ++i)
	{
	    cin >> num;
	    A.push_back(num);
	}
	
	for(i = 0; i < num_orders; ++i)
	{
	    cin >> num;
	    B.push_back(num);
	}
	
	cout << find_max(A, B, num_A, num_B) << endl;
	
	return 0;
}

int find_max(vector<int> &A, vector<int> &B, int num_A, int num_B)
{
    int i, num_orders = A.size(), val = 0;
    vector<vector<int>> diff(num_orders, vector<int> (3));
    
    for(i = 0; i < num_orders; ++i)
    {
        diff[i][0] = A[i];
        diff[i][1] = B[i];
        diff[i][2] = abs(A[i] - B[i]);
    }
    
    sort(diff.begin(), diff.end(), cmp);
    
    for(i = 0; i < num_orders; ++i)
    {
        if(!num_A)
        {
            val += diff[i][1];
            continue;
        }
        
        if(!num_B)
        {
            val += diff[i][0];
            continue;
        }
        
        if(diff[i][0] >= diff[i][1])
        {
            val += diff[i][0];
            --num_A;
        }
        else
        {
            val += diff[i][1];
            --num_B;
        }
    }
    
    return val;
}

bool cmp(const vector<int> &v1, const vector<int> &v2)
{
    return (v1[2] > v2[2]);
}
