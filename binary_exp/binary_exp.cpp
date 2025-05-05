#include <bits/stdc++.h>
using namespace std;

/*
    Problem Statement: Your task is to calculate ab mod 1337 where a is a positive integer and b
    is an extremely large positive integer given in the form of an array.

    Constraints:

    1 <= a <= 231 - 1
    1 <= b.length <= 2000
    0 <= b[i] <= 9
    b does not contain leading zeros.

*/

void solvehalf(vector<int>& b, vector<int>& bh, bool& parity){
    if(b.back()%2) parity=false;
    int carry = 0;
    for(int i=0;i<b.size();i++){
        int a = (b[i]+carry*10)/2;
        carry = (b[i]+carry*10)%2;
        if(a==0 && i==0) continue;
        bh.push_back(a);
    }
}

int superPow(int a, vector<int>& b) {
    if(b.size()==0) return 1;
    if(b.size()==1 && b[0]==1) return a;
    vector<int> bhalf;
    bool parity = true;
    solvehalf(b,bhalf,parity);
    int ans = 1;
    if(!parity) ans*=a;
    int x = superPow(a, bhalf);
    return ans*x*x;
}

int main(){
    int a = 2;
    vector<int> b(2);
    b[0]=1;b[1]=0;
    cout<<superPow(a, b)<<endl;
}
