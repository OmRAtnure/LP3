#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,r;
    cout<<"Enter n:";
    cin>>n;
    cout<<"Enter r:";
    cin>>r;

    if (n < 0 || r < 0 || r > n) {
        cout << "Invalid input\n";
        return 1;
    }

    vector<vector<long long>> dp(n+1,vector<long long> (r+1,0));

    for(int i=0;i<=n;i++) {
        for(int j=0;j<=min(i,r);j++) {
            if(j==0 ||j==i) {
                dp[i][j]=1;
            } else {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
    }

     cout << "Binomial Coefficient: " << dp[n][r] << '\n';
    return 0;


}