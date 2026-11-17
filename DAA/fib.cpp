#include<iostream>
using namespace std;

void fibonacciSeries(int n) {
    if(n<0) {
        cout<<"Number of terms cannot be  negative";
        return;
    }
    int a=0, b=1;
    int steps=0;
    cout<<"series: ";
    for(int i=0;i<n;i++) {
        cout<<a<<" ";
        int c=a+b;
        a=b;
        b=c;
        steps ++;
    }
    cout<<endl;
    cout<<"Total computational steps:"<<steps;

    
}
int fib(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    cout<<"Enter number for terms for series: ";
    cin>>n;
    fibonacciSeries(n);
    return 0;
}