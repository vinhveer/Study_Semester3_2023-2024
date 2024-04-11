#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int pid;        // Process ID
    int burst_time; // CPU Burst time required
    int priority;   // Priority of this process
    int arrival_time; // Arrival time of this process
};

// Sort processes by priority (highest priority first)
bool compare(Process a, Process b)
{
    return (a.priority > b.priority);
}

void waiting_time(Process pro[], int n, int wt[])
{
    // Initial waiting time for a process is 0
    wt[0] = 0;
    
    // Calculating waiting time for each process
    for (int i = 1; i < n; i++)
        wt[i] = pro[i - 1].burst_time + wt[i - 1];
}

void turnaround_time(Process pro[], int n, int wt[], int tat[])
{
    // Calculating turnaround time for each process
    for (int i = 0; i < n; i++)
        tat[i] = pro[i].burst_time + wt[i];
}

void avgtime(Process pro[], int n)
{
    int wt[n], tat[n], total_wt = 0, total_tat = 0;
    
    // Calculating waiting time for each process
    waiting_time(pro, n, wt);
    
    // Calculating turnaround time for each process
    turnaround_time(pro, n, wt, tat);
    
    // Display processes along with their details
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
    {
        total_wt += wt[i];
        total_tat += tat[i];
        cout << "P" << pro[i].pid << "\t\t" << pro[i].burst_time << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    
    // Display average waiting and turnaround time
    cout << "\nAverage waiting time: " << (float)total_wt / n << endl;
    cout << "Average turnaround time: " << (float)total_tat / n << endl;
}

void scheduling(Process pro[], int n)
{
    // Sort processes by priority (highest priority first)
    sort(pro, pro + n, compare);
    
    // Display order in which processes get executed
    cout << "Order in which processes get executed: ";
    for (int i = 0; i < n; i++)
        cout << "P" << pro[i].pid << " ";
    cout << endl;
    
    // Calculate average waiting and turnaround time for all processes
    avgtime(pro, n);
}

int main()
{
    // Get number of processes and their details
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    
    Process pro[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter process " << i+1 << " info: " << endl;
        cout << "PID: ";
        cin >> pro[i].pid;
        cout << "Burst time: ";
        cin >> pro[i].burst_time;
        cout << "Priority: ";
        cin >> pro[i].priority;
        cout << "Arrival time: ";
        cin >> pro[i].arrival_time;
    }
    
    // Perform priority scheduling
    scheduling(pro, n);
    
    return 0;
}