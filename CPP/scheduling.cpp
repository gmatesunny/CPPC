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
//https://www.geeksforgeeks.org/program-shortest-job-first-scheduling-set-2srtf-make-changesdoneplease-review/
#include <bits/stdc++.h>

struct Process{
    int pid;
    int bt;
    int art;
};

void findWaitingTime(Process proc[], int wt[], int n)
{
    int rt[n]; //remaining time
    for(int i=0;i<n;i++)
    {
        rt[i] = proc[i].bt;
    }
    int complete = 0, t=0, minm = INT_MAX;
    int shortest = 0, finish_time;
    bool check = false;

    while(complete != n)
    {
        for(int j=0;j<n;j++)
        {
            if((proc[j].art <=t) && (rt[j] < minm) && (rt[j]> 0)) //checking at t, if any prcocess is there with lower rt an
            {
                minm = rt[j];
                shortest = j;
                check = true;
            }
        }
        if(check == false) //if any process has not yet arrived 
        {
            t++;
            continue;
        }

        rt[shortest]--;
        minm = rt[shortest];
        if(minm == 0 )
        {
            minm = INT_MAX;
            complete++;
            finish_time = t+1;
            wt[shortest] = finish_time - proc[shortest].bt - proc[shortest].art;   
        }
        t++;
    }
}



void findavgTime(Process proc[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    findWaitingTime(proc, wt, n);
}

int main()
{
    Process proc[] = {{1,6,1},
    {2,8,1},
    {3,7,2},
    {4,3,3}};

    int n = sizeof proc/sizeof proc[0];
    findavgTime(proc, n);
}
--------------------------------------------------------------------------------------------------------------
    
    
