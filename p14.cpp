//Next Happy Number
//https://practice.geeksforgeeks.org/problems/next-happy-number4538/1

#include<bits/stdc++.h>
using namespace std;

bool isHappy(int n);
int nextHappy(int n);

int main()
{
    int n;
    cin>>n;
    cout<<nextHappy(n);

    return 0;
}

bool isHappy(int n)
{
    unordered_set<int> visited_numbers;
    int current_num = n;

    while (current_num!=1 && visited_numbers.find(current_num)==visited_numbers.end())
    {
        visited_numbers.insert(current_num);
        int sum_of_squared_digits = 0;
        int digit;
        while(current_num)
        {
            digit = current_num%10;
            sum_of_squared_digits+=digit*digit;
            current_num/=10;
        }

        current_num = sum_of_squared_digits;
    }
    return current_num == 1;
}

int nextHappy(int n)
{
    while(!isHappy(++n));

    return n;
}