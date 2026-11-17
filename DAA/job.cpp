#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Job{
    char id;
    int deadline;
    int profit;
};

int main(){
    vector<Job> jobs={
         {'A', 2, 100},
        {'B', 1, 19},
        {'C', 2, 27},
        {'D', 1, 25},
        {'E', 3, 15}
    };

    sort(jobs.begin(),jobs.end(),
        [](const Job a,const Job b) {
            return a.profit>b.profit;
        }
    );

    int maxDeadline=0;
    for(Job job:jobs) {
        maxDeadline=max(maxDeadline,job.deadline);
    }
    maxDeadline = min(maxDeadline, (int)jobs.size());

    vector<char> slots(maxDeadline+1,'\0');
    vector<bool> occcupied(maxDeadline+1,false);

    int profit=0;

    for(Job job:jobs) {
        for(int j=min(job.deadline,maxDeadline);j>=1;j--) {
            if(!occcupied[j]) {
                occcupied[j]=true;
                slots[j]=job.id;
                profit += job.profit;
                break;
            }
        }
    }

    cout<<"Scheduled jobs:"<<endl;
    for (int i = 1; i <= maxDeadline; ++i) {
        if (occcupied[i]) {
            cout << slots[i] << " ";
        }
    }
    cout<<endl;
    cout<<"Total Profit:"<<profit;


}