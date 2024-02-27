#include<bits/stdc++.h>
using namespace std;
struct Process{
    int process_id;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};
bool compareProcess(Process a,Process b);
int main(){
    freopen("input.txt","r",stdin);
    int process_num=5,i;
    vector<Process> process(process_num);
    int value;
    string curr_process;
    char ch;
    for(i=0;i<=process_num;i++){
        cin>>value;
        process[i].burst_time=value;
        cin>>value;
        process[i].priority=value;
        process[i].process_id=i+1;
    }
    sort(process.begin(),process.end(),compareProcess);
    // for(auto p:process){
    //     cout<<p.process_id<<" "<<p.burst_time<<" "<<p.priority<<endl;
    // }
    process[0].turnaround_time=process[0].burst_time;
    process[0].waiting_time=0;
    for(i=1;i<=process_num;i++){
        process[i].turnaround_time=process[i].burst_time+process[i-1].turnaround_time;
        process[i].waiting_time=process[i].turnaround_time-process[i].waiting_time;
    }
    cout<<"Gantt chart:"<<endl;
    cout<<"|";
    for(i=0;i<=process_num;i++){
        cout<<"---P"<<process[i].process_id<<"---|";
    }
    cout<<endl;
    for(auto t:turnaround_time){
        printf("%-9d",t);
    }
    cout<<endl<<endl;
    printf("%s\t%s\t\t%s\n","Process ID","Turnaround Time","Waiting Time");
    for(i=1;i<=process_num;i++){
        printf("P%d %20d %23d\n",i,turnaround_time[i],waiting_time[i]);
    }
}
bool compareProcess(Process a,Process b){
    return a.burst_time<b.burst_time;
}