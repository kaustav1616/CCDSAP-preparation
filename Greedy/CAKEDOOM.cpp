// problem link: https://www.codechef.com/problems/CAKEDOOM

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check_init_valid(string &);
bool check_valid(string &, int);
bool check_valid_len_2(string &);

int main() 
{
	bool flag;
	int i, num_tests, k, len;
	string str;
	
	cin >> num_tests;
	
	for(i = 0; i < num_tests; ++i)
	{
	    cin >> k >> str;
	    len = str.length();
	    
	    if(len == 1)
	    {
	        if(str == "?")
	            str = "0";
	            
	        cout << str << endl;
	        continue;
	    }
	    
	    flag = check_init_valid(str);
	    
	    if(!flag)
	    {
	        cout << "NO" << endl;
	        continue;
	    }
	    
	    if(k == 1)
	        flag = false;
	    else if(k == 2)
	        flag = check_valid_len_2(str);
	    else
	        flag = check_valid(str, k);
	        
	    if(flag)
	        cout << str << endl;
	    else
	        cout << "NO" << endl;
	}
	
	return 0;
}

bool check_valid_len_2(string &str)
{
    bool flag = true;
    int i, len = str.length();
    string str1 = "0", str2 = "1";
    
    if(len % 2)
        return false;
    
    for(i = 1; i <= len - 1; ++i)
    {
        if(str1[i - 1] == '0')
            str1 += '1';
        else
            str1 += '0';
            
        if(str2[i - 1] == '0')
            str2 += '1';
        else
            str2 += '0';
    }
    
    for(i = 0; i <= len - 1; ++i)
    {
        if(str[i] == '?')
            continue;
            
        if(str1[i] != str[i])
        {
            flag = false;
            break;
        }
    }
    
    if(flag)
    {
        str = str1;
        return true;
    }
    
    for(i = 0; i <= len - 1; ++i)
    {
        if(str[i] == '?')
            continue;
            
        if(str2[i] != str[i])
            return false;
    }
    
    str = str2;
    return true;
}

bool check_valid(string &str, int k)
{
    int i, j, len = str.length(), prev_digit, next_digit;
    
    for(i = 0; i <= len - 1; ++i)
    {
        if(str[i] != '?') // number
            continue;
            
        if(i)
            prev_digit = str[i - 1] - '0';
        else
        {
            if(str[len - 1] != '?')
                prev_digit = str[len - 1] - '0';
            else
                prev_digit = 10;
        }
            
        if(str[(i + 1) % len] != '?')
            next_digit = str[(i + 1) % len] - '0';
        else
            next_digit = 10;
            
        for(j = 0; j <= k - 1; ++j)
        {
            if(j != prev_digit && j != next_digit)
                break;
        }
        
        if(j == k)
            return false;
            
        str[i] = (char)(j + '0');
    }
    
    return true;
}

bool check_init_valid(string &str)
{
    int i, len = str.length();
    
    for(i = 0; i <= len - 1; ++i)
    {
        if(str[i] == '?')
            continue;
            
        if(str[i] == str[(i + 1) % len])
            return false;
    }
    
    return true;
}
