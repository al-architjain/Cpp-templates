vector<int> calculateLPS(string pattern){
	int m = pattern.size();
	vector<int> lps(m,0);
	
	for(int i=1, j=0; i<m; i++ ){
		while(j>0 && pattern[j]!=pattern[i]){
			j = lps[j-1];		
		}
		if(pattern[i] == pattern[j] ){
			j++;
			lps[i] = j;
		}
		else{
			lps[i] = j;			//or lps[i]=0	as j=0;
		}
	}
	return lps;
}

void KMP(string str, string pattern){
	int n = str.size();
	int m = pattern.size();
	vector<int> lps = calculateLPS(pattern);

	for(int i=0; j=0; i<n; i++){
		while( j>0 && pattern[j]!=str[i]){
			j = lps[j-1];		
		}
		if(str[i] == pattern[j]){
			j++;
		}
		if( j == m ){
			cout<<i-m+1<<"\n";
			j = lps[j-1];
		}
	}
}
