//Task Scheduler
//https://practice.geeksforgeeks.org/problems/task-scheduler/1
/* Given a character array tasks of size N, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.
CPU has a cooldown period for each task. CPU can repeat a task only after atleast K units of time has passed after it did same task last time. It can perform other tasks in that time, can stay idle to wait for repeating that task.

Return the least number of units of times that the CPU will take to finish all the given tasks. */

#include<bits/stdc++.h>
using namespace std;

int leastInterval(int N, int K, vector<char> &tasks);

int main()
{
    int N, K;
    cin >> N >> K;

    vector<char> tasks(N);
    for(int i=0;i<N;i++)
        cin>>tasks[i];

    cout << leastInterval(N,K,tasks);

    return 0;
}

int leastInterval(int N, int K, vector<char> &tasks)
{
    unordered_map<char,int> taskFrequency;
    int maxCount = 0;

    for(auto i: tasks)
    {
        taskFrequency[i]++;
        maxCount = max(maxCount,taskFrequency[i]);
    }

    int ans = (maxCount - 1) * (K + 1);

    for(auto i: taskFrequency)
        if(i.second == maxCount)
            ans++;

    return max(ans,(int)tasks.size());
}
