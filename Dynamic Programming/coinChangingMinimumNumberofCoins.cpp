/*
 * 	Coin Changing Problem to find minimum coins required
 * 	bottom-up approach used
 * 	Complexity:
 * 		Time: O(n*m);		// n = # of numbers, m = coin value
 * 		Space: O(n*m);
 */

#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;

class coinChangingMin{
	int n;
	int cval;
	vector<int> arr;
	vector<vector<int>> dp;
	public:
		coinChangingMin(){
			n=0;
			cval=0;
		}
		void input(){
			cin>>n;
			arr.resize(n+1,0);
			for(int i=1; i<=n; i++){
				cin>>arr[i];
			}
		}
		void problemInput(){
			cin>>cval;
			dp.resize(n+1, vector<int>(cval+1, INT_MAX));
		}
		int bottomUp(){
			for(int i=0; i<=n; i++){
				dp[i][0]=0;
			}
			for(int i=1; i<=n; i++){
				for(int j=1; j<=cval; j++){
					if(arr[i]>j){
						dp[i][j] = dp[i-1][j];
					}
					else{
						dp[i][j] = min(dp[i-1][j] , 1 + dp[i][j-arr[i]]);
					}
				}
			}
			if(dp[n][cval] == INT_MAX)	return -1;
			else return dp[n][cval];
		}
		void printPath(){
			printPathUtil(n,cval);
			// INCOMLETE TRAVERSAL
		}
};

int main(){
	coinChangingMin obj;
	obj.input();
	obj.problemInput();
	int ans = obj.bottomUp();
	cout<<ans<<endl;

	return 0;
}
