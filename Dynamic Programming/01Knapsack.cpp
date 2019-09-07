/*
	0/1 Knapsack Problem
	C++ Implementation using class
	BottomUp Approach used
	Complexity:
		Time = O(n*W);
		Space= O(n*W);
	Thank You
*/

#include <iostream>
#include <vector>
#include <math.h>
#define ll long long
using namespace std;

class Knapsack01{
	vector<int> wt;
	vector<int> val;
	vector< vector<int>> dp;
	int n;
	int W;
	public:
		Knapsack01(){
			W = 0;
			n = 0;
		}
		void input(){
			cin>>n;
			wt.resize(n);
			val.resize(n);
			cin>>W;
			// weights
			for(int i=0; i<n; i++){
				cin>>wt[i];
			}
			// values
			for(int i=0; i<n; i++){
				cin>>val[i];
			}
		}

		int bottomUp(){
			dp.resize(n+1, vector<int>(W+1,0));
			for(int i=1; i<=n; i++){
				for(int j=1; j<=W; j++){
					if(j >= wt[i-1]){
						dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
					}
					else{
						dp[i][j] = dp[i-1][j];
					}
				}
			}
			return dp[n][W];
		}
		
		void printPath(){
			printPathUtil(n,W);
		}

		void printPathUtil(int index, int w){
			if(index == 0)	return;
			if(dp[index][w] == dp[index-1][w]){
				printPathUtil(index-1, w);
			}
			else{
				printPathUtil(index-1, w-wt[index-1]);
				cout<<wt[index-1]<<"  ";
			}
		}

};

int main(){
	Knapsack01 obj;
	obj.input();
	int ans = obj.bottomUp();
	cout<<ans<<endl;
	obj.printPath();
	return 0;
}

