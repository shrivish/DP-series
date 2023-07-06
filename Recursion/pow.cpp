#include<bits/stdc++.h>
using namespace std;

double power(double x, int n){
        if(n==0){
            return 1;
        }
        return x * power(x, n-1);
    }

double myPow(double x, int n) {
        if (n == INT_MAX) return (x == 1) ? 1 : (x == -1) ? -1 : 0;
        if (n == INT_MIN) return (x == 1 || x == -1) ? 1 : 0;
        double num = 1;
        if(n>=0){
            num = power(x, n);
        }
        else{
            n = -n;
            num = power(x, n);
            num = 1.0/num;
        }
        return num;
    }

int main(){
    double x = 2.400;
    int n = 10;
    cout<< myPow(x,n);
}


// double myPow(double x, int n) {
//         if(n==0){
//             return 1;
//         }

//         if(n==1){
//             return x;
//         }

//         if(n>0){
//             if(n%2==0){
//                 return myPow(x*x, n/2);
//             }
//             else{
//                 return x*myPow(x*x, n/2);
//             }
//         }

//         else{
//             n= abs(n);
//             if(n%2==0){
//                 return 1/myPow(x*x, n/2);
//             }
//             else{
//                 return 1/(x*myPow(x*x, n/2));
//             }
//         }
//     }