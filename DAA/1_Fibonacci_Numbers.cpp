#include<iostream>
#include<vector>

using namespace std;

//Iteratively using memoization
int iStepFibbonacci(int n){
    if(n==0) return 0;
    vector<int> f;
    f.push_back(0);
    f.push_back(1);
    
    int cnt = 2;
    for(int i = 2; i < n; i++){
        cnt++;
        f.push_back(f[i - 1] + f[i - 2]);
    }
    return f[n-1];
}

int rSteps = 0;

//Recursively
int rStepFibbonacci(int n){
    rSteps++;
    if(n <=1) return n;
    return rStepFibbonacci(n - 1) + rStepFibbonacci(n - 2);
}

int main(){
    int n;
    cin >> n;
    cout << "Fibbonacci Value : " << rStepFibbonacci(n) << '\n';
    cout << "Steps required using Iteration : " << iStepFibbonacci(n) << '\n';
    cout << "Steps required using recursion : " << rSteps << '\n';
    return 0;
}

