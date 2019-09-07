/*
 * 	Longest Common Subsequence Problem
 *	Implementation using C++ class
 * 	bottomUp approach
 * 	Complexity:
 * 		Time = O(n*m)
 * 		Space = O(n*m)
 */


#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

class longestCommonSubsequence{
	int l1,l2;
	string s1;
	string s2;
	vector< vector<int>> dp;
	public:
		/*longestCommonSubsequence(int a, int b){
			l1 = a;
			l2 = b;
			dp.resize(a+1, vector<int>(b+1,0));
		}*/
		void input(){
			cin>>s1;
			cin>>s2;
			l1 = s1.size();
			l2 = s2.size();
			dp.resize(l1+1, vector<int>(l2+1, 0));
		}
		int bottomUp(){
			for(int i=1; i<=l1; i++){
				for(int j=1; j<=l2; j++){
					if(s1[i-1] == s2[j-1]){
						dp[i][j] = dp[i-1][j-1] + 1;
					}
					else{
						dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
					}
				}
			}
			return dp[l1][l2];
		}
		void printSub(){
			printSubUtil(l1,l2);
		}
		void printSubUtil(int indexx, int indexy){
			if(indexx == 0 || indexy == 0)	return;
			if(dp[indexx][indexy] == dp[indexx-1][indexy]){
				printSubUtil(indexx-1, indexy);
			}
			else if(dp[indexx][indexy] == dp[indexx][indexy-1]){
				printSubUtil(indexx, indexy-1);
			}
			else{
				printSubUtil(indexx-1, indexy-1);
				cout<<s1[indexx-1]<<" ";
			}
		}
};

int main(){
	longestCommonSubsequence obj;
	obj.input();
	int ans = obj.bottomUp();
	cout<<ans<<endl;
	obj.printSub();
	return 0;
}
