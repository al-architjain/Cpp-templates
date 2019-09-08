#include<iostream>
#include<vector>
#include<math.h>
#include<limits.h>
using namespace std;

class longestIncreasingSubsequence{
	int len;
	vector<int> arr;
	vector<int> dp;
	vector<int> prev;
	public:
		longestIncreasingSubsequence(){
			len=0;
		}
		void input(){
			cin>>len;
			arr.resize(len);
			dp.resize(len,1);
			prev.resize(len);
			for(int i=0; i<len; i++){
				cin>>arr[i];
				prev[i] = i;
			}
		}
		int bottomUp(){
			for(int i=1; i<len; i++){
				for(int j=i-1; j>=0; j--){
					if(arr[j]<arr[i]){
						if(dp[j]+1 > dp[i]){
							dp[i] = dp[j]+1;
							prev[i] = j;
						}
					}
				}
			}
			return dp[len-1];
		}
		void output(){
			cout<<bottomUp()<<endl;
			int maxindex=-1;
			int maxnum = INT_MIN;
			for(int i=0; i<len; i++){
				if(dp[i]>=maxnum){
					maxnum = dp[i];
					maxindex = i;
				}
			}
			int i = maxindex;
			while(maxnum--){
				cout<<arr[i]<<" ";
				i = prev[i];
			}
		}
};

int main(){
	longestIncreasingSubsequence obj;
	obj.input();
	obj.output();
	return 0;
}
