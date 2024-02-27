#include<bits/stdc++.h>
using namespace std;
struct Process{
    int process_id;
    int burst_time;
    int priority;
    int arrival;
    int start_time;
    int turn_around_time;
    int waiting_time;
};
bool comparator(Process a,Process b);
int main(){
    freopen("input.txt","r",stdin);
    int i,j;
    int value,process_num=6;
    vector<Process> process;
    Process temp;
    for(i=0;i<process_num;i++){
        temp.process_id=i+1;
        cin>>value;
        temp.burst_time=value;
        cin>>value;
        temp.priority=value;
        cin>>value;
        temp.arrival=value;
        process.push_back(temp);
    }
    sort(process.begin(),process.end(),comparator);
    printf("PID\tBT\tPR\tAT\n");
    for(auto p:process){
        printf("P%d\t%d\t%d\t%d\n",p.process_id,p.burst_time,p.priority,p.arrival);
    }
    int curr_time,next_arrival;
    curr_time=process[i].arrival;
    next_arrival=process[i+1].arrival;
    queue<Process*> arrived_process;
    arrived_process.push(&process[i]);
    Process curr_process=*arrived_process.front();
    while(!arrived_process.empty()){
        if(curr_process.burst_time<next_arrival){
            curr_time+=curr_process.burst_time;
            curr_process.turn_around_time=curr_time;

        }
    }
    return 0;
}
bool comparator(Process a,Process b){
    return a.arrival<b.arrival;
}