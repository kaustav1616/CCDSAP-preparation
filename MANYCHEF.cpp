// problem link: https://www.codechef.com/problems/MANYCHEF

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void find_max_chef_lex_smallest(string &);
char find_exp_char(int);

int main()
{
	int num_tests, i;
	string str;
	
	cin >> num_tests;
	
	for(i = 0; i < num_tests; ++i)
	{
	    cin >> str;
	    find_max_chef_lex_smallest(str);
	    cout << str << endl;
	}
	
	return 0;
}

void find_max_chef_lex_smallest(string &str)
{
    int i, j, len = str.length();
    char exp_char;
    
    for(i = len - 1; i >= 3; --i)
    {
        if(str[i] == 'F')
        {
            for(j = 1; j <= 3; ++j)
            {
                exp_char = find_exp_char(j);
                
                if(str[i - j] != exp_char && str[i - j] != '?')
                    break;
            }
            
            if(j == 4) // "CHEF" can be placed
            {
                for(j = 1; j <= 3; ++j)
                {
                    exp_char = find_exp_char(j);
                    str[i - j] = exp_char;
                }
            }
        }
        else if(str[i] == '?')
        {
            for(j = 0; j <= 3; ++j)
            {
                exp_char = find_exp_char(j);
                
                if(str[i - j] != exp_char && str[i - j] != '?')
                    break;
            }
            
            if(j == 4) // "CHEF" can be placed
            {
                for(j = 0; j <= 3; ++j)
                {
                    exp_char = find_exp_char(j);
                    str[i - j] = exp_char;
                }
            }
            else
                str[i] = 'A';
        }
    }
    
    for(i = 2; i >= 0; --i)
    {
        if(str[i] == '?')
            str[i] = 'A';
    }
}

char find_exp_char(int i)
{
    if(!i)
        return 'F';
        
    if(i == 1)
        return 'E';
        
    if(i == 2)
        return 'H';
        
    return 'C';
}
