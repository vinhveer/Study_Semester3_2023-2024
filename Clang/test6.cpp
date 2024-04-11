#include <iostream>
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

void insertion_sort(vector<Process> &processes)
{
    int n = processes.size();
    for (int i = 1; i < n; ++i)
    {
        Process key = processes[i];
        int j = i - 1;

        while (j >= 0 && processes[j].priority < key.priority)
        {
            processes[j + 1] = processes[j];
            j--;
        }
        processes[j + 1] = key;
    }
}

void run_processes(vector<Process> processes)
{
    cout << "Process ID\t"
         << "Burst time\t"
         << "Priority\t"
         << "Start time\t"
         << "End time\t"
         << "Waiting time\t"
         << "Turnaround time" << endl;
    cout << "----------\t"
         << "----------\t"
         << "--------\t"
         << "----------"
         << "--------\t"
         << "------------\t"
         << "--------------\t" << endl;

    int current_time = 0;
    while (!processes.empty())
    {
        insertion_sort(processes);
        Process current_process = processes.back();
        processes.pop_back();
        current_process.start_time = current_time;
        current_time += current_process.burst_time;
        current_process.end_time = current_time;
        current_process.turnaround_time = current_process.end_time - current_process.start_time;
        current_process.waiting_time = current_process.turnaround_time - current_process.burst_time;
        cout << current_process.pid 
        << "\t\t" << current_process.burst_time 
        << "\t\t" << current_process.priority 
        << "\t\t" << current_process.start_time 
        << "\t\t" << current_process.end_time 
        << "\t\t" << current_process.waiting_time 
        << "\t\t" << current_process.turnaround_time << endl;
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
