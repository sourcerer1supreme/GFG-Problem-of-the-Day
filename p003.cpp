/*
https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string3411/1
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string that reads the same backward. More formally, S is a palindrome if reverse(S) = S. In case of conflict, return the substring which occurs first ( with the least starting index).

*/

#include<bits/stdc++.h>
using namespace std;

string longestPalin (string s);

int main()
{
    string S;
    cin>>S;

    cout<< longestPalin(S) <<endl;
}

string longestPalin (string s)
{
    int len = s.size();

    int start = len;
    int anslen = 0;

    for(int i = 0;i < len;i++)
    {
        //Odd Case
        int l = i - 1;
        int r = i + 1;
        int canslen = 1;

        while((l>=0 && r<len) && (s[l]==s[r]))
        {
            canslen+=2;
            --l;
            ++r;
        }

        if(canslen > anslen)
        {
            anslen = canslen;
            start = l + 1;
        }
        else if(canslen == anslen && l+1 < start)
            start = l + 1;
            
        //Even Case
        l = i-1;
        r = i;
        canslen = 0;

        while((l>=0 && r<len) && (s[l]==s[r]))
        {
            canslen+=2;
            --l;
            ++r;
        }

        if(canslen > anslen)
        {
            anslen = canslen;
            start = l + 1;
        }
        else if(canslen == anslen && l+1 < start)
            start = l + 1;
    }

    return s.substr(start,anslen);
}
