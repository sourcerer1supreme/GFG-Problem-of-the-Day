//Lemonade Challenge
//https://practice.geeksforgeeks.org/problems/lemonade-change/1

#include<bits/stdc++.h>
using namespace std;

bool lemonadeChange(int N, vector<int> &bills);

int main()
{
    int N;
    cin >> N;
    
    vector<int> bills(N);
    for(int i = 0;i < N;i++)
        cin >> bills[i];

    int ans = lemonadeChange(N, bills);
    if(ans)
        cout << "True" <<endl;
    else
        cout << "False" <<endl;

    return 0;
}

bool lemonadeChange(int N, vector<int> &bills)
{
    int fives, tens, twenties;
    fives = tens = twenties = 0;

    for(int i = 0; i < N;i++)
    {
        if(bills[i]==5)
        {
            fives++;
        }   
        else if(bills[i]==10)
        {
            if(fives>0)
            {
                tens++;
                fives--;
            }
            else
                return false;
        }
        else
        {   
            if(fives>=1 && tens>=1)
            {
                fives--;
                tens--;
            }
            else if(fives>=3)
                fives-=3;
            else    
                return false;
        }
    }
    return true;
}