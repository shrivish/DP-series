#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
    int countGoodNumbers(long long n) {
        if(n==0) return 1;

        if(n%2==0){
            return (4*countGoodNumbers(n-1))%mod;
        }
        else{
            return (5*countGoodNumbers(n-1))%mod;
        }
    }

int main(){
    int n;
    cout<< "number n: ";
    cin>>n;

    cout<<countGoodNumbers(n);
}