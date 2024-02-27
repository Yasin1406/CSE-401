#include<bits/stdc++.h>
using namespace std;
struct Process{
    int process_id;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
    int remaining_time;
};
struct Result{
    int process_id;
    int start;
    int end;
};
bool compareProcess(Process a,Process b);
int main(){
    freopen("input.txt","r",stdin);
    int process_num=5,i;
    vector<Process> process(process_num);
    int value,wait=0,turn=0,quantam;
    string curr_process;
    char ch;
    for(i=0;i<process_num;i++){
        cin>>value;
        process[i].burst_time=value;
        cin>>value;
        process[i].priority=value;
        process[i].process_id=i+1;
        process[i].remaining_time=process[i].burst_time;
    }
    cin>>quantam;
    // sort(process.begin(),process.end(),compareProcess);
    // for(auto p:process){
    //     cout<<p.process_id<<" "<<p.burst_time<<" "<<p.priority<<endl;
    
    cout<<"Average turnaround time: "<<(double)turn/process_num<<endl;
    cout<<"Average waiting time: "<<(double)wait/process_num<<endl;
}
bool compareProcess(Process a,Process b){
    return a.priority>b.priority;
}