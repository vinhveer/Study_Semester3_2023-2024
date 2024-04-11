#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Process
{
    int pid;
    int burst_time;
    int priority;
    int start_time;
    int end_time;
    int waiting_time;
    int turnaround_time;
};

bool compare_processes(Process p1, Process p2)
{
    return p1.priority > p2.priority;
}

void run_processes(vector<Process> processes)
{
    cout << "Process ID\t" << "Burst time\t" << "Priority\t" << "Start time\t" << "End time\t" << "Waiting time\t" << "Turnaround time" << endl;  
    int current_time = 0;
    while (!processes.empty())
    {
        sort(processes.begin(), processes.end(), compare_processes);
        Process current_process = processes.back();
        processes.pop_back();
        current_process.start_time = current_time;
        current_time += current_process.burst_time;
        current_process.end_time = current_time;
        current_process.turnaround_time = current_process.end_time - current_process.start_time;
        current_process.waiting_time = current_process.turnaround_time - current_process.burst_time;
        cout << current_process.pid << "\t\t" << current_process.burst_time << "\t\t" << current_process.priority << "\t\t" << current_process.start_time << "\t\t" << current_process.end_time << "\t\t" << current_process.waiting_time << "\t\t" << current_process.turnaround_time << endl;
    }
}

vector<Process> get_processes()
{
    vector<Process> processes;
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int pid, burst_time, priority;
        cout << "Enter process " << i + 1 << " info: " << endl;
        cout << "PID: ";
        cin >> pid;
        cout << "Burst time: ";
        cin >> burst_time;
        cout << "Priority: ";
        cin >> priority;
        processes.push_back({pid, burst_time, priority});
    }
    return processes;
}

int main()
{
    vector<Process> processes = get_processes();
    run_processes(processes);
    return 0;
}
