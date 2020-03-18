// problem link: https://www.codechef.com/problems/CHEFST
// problem reduces to considering maximum possible reduction in min(n1, n2) with nos. from [1..m]

#include <iostream>
using namespace std;

int main(void) 
{
	int i, num_tests;
	long int n1, n2, m, sum;
	
	cin >> num_tests;
	
	for(i = 0; i < num_tests; ++i)
	{
	    cin >> n1 >> n2 >> m;
	    sum = (m * (m + 1)) / 2;
	    
	    if(min(n1, n2) <= sum)
	        cout << max(n1, n2) - min(n1, n2) << endl;
	    else
	        cout << (n1 - sum) + (n2 - sum) << endl;
	}
	
	return 0;
}
