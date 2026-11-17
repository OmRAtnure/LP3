#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> weight ={10,20,30}; 
    vector<int> profit ={60,100,120};
    
    int n=weight.size();
    int capacity=50;
    
    vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));

    for(int i=1;i<=n;i++) {
        for(int w=0;w<=capacity;w++) {
            if(weight[i-1]<=w) {
                dp[i][w]=max(
                    dp[i-1][w],
                    profit[i-1] + dp[i-1][w-weight[i-1]]
                );
            }else{
                dp[i][w]=dp[i-1][w];
            }
        }
    }

    cout<<"Maximum profit: "<<dp[n][capacity];

    cout << "Selected Items:\n";

    int w= capacity;
    for (int i=n;i>0;i--) {
        if(dp[i][w]!=dp[i-1][w]) {
             cout << "Item " << i << '\n';
            w -= weight[i - 1];
        }
    }
}