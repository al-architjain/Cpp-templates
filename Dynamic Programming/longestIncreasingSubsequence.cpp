#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class longestIncreasingSubsequence{
	int len;
	vector<int> arr;
	vector<int> dp;
	public:
		longestIncreasingSubsequence(){
			len=0;
		}
		void input(){
			cin>>len;
			arr.resize(len);
			dp.resize(len,1);
			for(int i=0; i<len; i++){
				cin>>arr[i];
			}
		}
		int bottomUp(){
			for(int i=1; i<len; i++){
				for(int j=i-1; j>=0; j--){
					if(arr[j]<arr[i]){
						dp[i] = max(dp[i], dp[j]+1);
					}
				}
			}
			return dp[len-1];
		}
		void output(){
			cout<<bottomUp()<<endl;
		}
};

int main(){
	longestIncreasingSubsequence obj;
	obj.input();
	obj.output();
	return 0;
}
