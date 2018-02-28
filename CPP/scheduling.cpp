//https://www.geeksforgeeks.org/program-shortest-job-first-sjf-scheduling-set-1-non-preemptive/

#include <bits/stdc++.h>
#include <iterator>

using namespace std;


struct Process{
    //assuming all process arrived at 0
    int pid;
    int bt;
};

bool comparision(Process a, Process b)
{
    return (a.bt < b.bt);
}

void findWaitingTime(Process proc[], int n, int wt[])
{
    wt[0] = 0;
    for(int i=1;i<n;i++)
    {
        wt[i] = proc[i-1].bt + wt[i-1];
    }
}

void findTatTime(Process proc[], int n, int tat[], int wt[])
{

    for(int i=0;i<n;i++)
    {
        tat[i] = proc[i].bt + wt[i];
    }
}

void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, n, wt);
    findTatTime(proc,n, tat, wt);

    for(int i=0;i<n;i++)
    {
        cout << i <<" th Process waiting time: "<< wt[i] << " Turnaround time:" << tat[i] << endl; 
    }

   // float avg = accumulate(begin(wt), end(wt), 0)/n; Fails but wt[3] will pass (variable-sized array type ‘int [n]’ is not a valid template argument)
}

int main()
{
    Process proc[] = {{1,6}, {2,8}, {3,7}, {4,3}};
    int n = sizeof proc/sizeof proc[0];

    sort(proc, proc+n, comparision);
    cout << "Order of execution" << endl;
    for(int i=0; i<n; i++)
        cout << proc[i].pid << "--->";
    cout << endl;

    findavgTime(proc, n);

    return 0;
}
-------------------------------------------------------------------

