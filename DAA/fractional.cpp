#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item{
    double weight;
    double profit;
};

int main() {
    vector<Item> items = {
    {10, 60, },
    {20, 100,},
    {30, 120,}
    };
     double capacity = 50.0;

    sort(items.begin(),items.end(), 
        [](Item a,Item b) {
            return a.profit/a.weight > b.profit/b.weight;
        }
    );


    double profit=0;
    for(Item item:items) {
        if(capacity<0) {
            break;
        }
        if(capacity>item.weight) {
            profit += item.profit;
            capacity -= item.weight;
        }else {
            profit =profit + (item.profit/item.weight)*capacity;
            capacity=0;
        }
    }
     cout << "Maximum Profit: " << profit<<endl;
     return 0;
     
}
