#include<iostream>
#include<vector>
#include<math.h>
#include<string>
using namespace std;

class minEditDistance{
	int ans;
	string X;
	int xlen;
	string Y;
	int ylen;
	vector<vector<int>> dp;
	public:
		minEditDistance(){
			ans=0;	xlen=0;	ylen=0;
		}
		void input(){
			cin>>X;
			cin>>Y;
			xlen = X.size();
			ylen = Y.size();
			dp.resize(xlen+1, vector<int>(ylen+1,0));
			for(int i=0; i<=xlen; i++)	dp[i][0] = i;
			for(int i=0; i<=ylen; i++)	dp[0][i] = i;
		}
		int bottomUp(){
			for(int i=1; i<=xlen; i++){
				for(int j=1; j<=ylen; j++){
					if(X[i] == Y[j])	dp[i][j] = dp[i-1][j-1];
					else dp[i][j] = 1 + min( dp[i-1][j-1], min( dp[i-1][j], dp[i][j-1] ));
				}
			}
			return dp[xlen][ylen];
		}

		int levenshteinDistance(){
			for(int i=1; i<=xlen; i++){
				for(int j=1; j<=ylen; j++){
					if(X[i] == Y[j])	dp[i][j] = dp[i-1][j-1];
					else dp[i][j] = min( 2 + dp[i-1][j-1], 1 + min( dp[i-1][j], dp[i][j-1] ));
				}
			}
			return dp[xlen][ylen];
		}

		int getAns(){
			ans = bottomUp();
			return ans;
		}

};

int main(){
	minEditDistance obj;
	obj.input();
	cout<<obj.bottomUp()<<endl;
	cout<<obj.levenshteinDistance()<<endl;
	return 0;
}
