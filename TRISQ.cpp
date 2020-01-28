// problem link: https://www.codechef.com/problems/TRISQ

#include <iostream>
using namespace std;

int find_num_squares(int);

int main() 
{
	int t, h;
	
	cin >> t;
	
	while(t--)
	{
	    cin >> h;
	    cout << find_num_squares(h) << endl;
	}
	
	return 0;
}

int find_num_squares(int height)
{
    if(height < 4)
        return 0;
        
    return ((height - 2) / 2 + find_num_squares(height - 2));
}
