#include<iostream>
#include<vector>
using namespace std;

class subsetSum{
	vector< vector<bool>> dp;
	vector< int> arr;
	int n;
	int sum;
	public:
		subsetSum(){
			n=0;
			sum=0;
		}
		void input(){
			cin>>n;
			arr.resize(n,0);
			cin>>sum;
			dp.resize(n+1, vector<bool>(sum+1, false));
			for(int i=0; i<n; i++){
				cin>>arr[i];
				dp[i][0] = true;
			}
		}
		bool bottomUp(){
			for(int i=1; i<=n; i++){
				for(int j=1; j<=sum; j++){
					if(j<arr[i-1])	dp[i][j] = dp[i-1][j];
					else{
						dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i-1]]);
					}
				}
			}
			return dp[n][sum];
		}
		void tracePath(){
			tracePathUtil(n,sum);
		}
		void tracePathUtil(int r, int c){
			if(r==0 || c==0)	return ;
			if(dp[r-1][c]==false){
				tracePathUtil(r-1, c-arr[r-1]);
				cout<<arr[r-1]<<" ";
			}
			else{
				tracePathUtil(r-1, c);
			}
		}
};

int main(){
	subsetSum obj;
	obj.input();
	cout<< obj.bottomUp()<<endl;
	obj.tracePath();
	return 0;
}
