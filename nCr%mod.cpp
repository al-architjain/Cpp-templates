#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

vector<vector<ll>> nCr;
void calcnCr(ll n){
    nCr.resize(n);
    nCr[0].push_back(1);
    for(int i=1; i<n; i++){
        nCr[i].push_back(1);
        for(int j = 1; j<i; j++){
            nCr[i].push_back( (nCr[i-1][j]%mod + nCr[i-1][j-1]%mod) % mod );
        }
        nCr[i].push_back(1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    calcnCr(_);
    
    return 0;
}
