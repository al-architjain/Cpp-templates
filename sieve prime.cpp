    #include<bits/stdc++.h>
    #define ull unsigned long long
    #define ll long long
    #define mod 1000000007
    using namespace std;
     
    vector<ll> prime;
    void calcprime(ll n){
        prime.resize(n+1,true);
        prime[0]=false;
        prime[1]=false;
        
        for(ll i=2; i<=sqrt(n); i++){
            if(prime[i]==false)
                continue;
            for(ll j=2; i*j<=n; j++){
                prime[i*j]=false;
            }
        }
    }
         
    int main(){
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        calcprime(1000000);
        
        return 0;
    }
