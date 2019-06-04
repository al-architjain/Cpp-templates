vector<int> computePrefix(string pattern){
    int m = pattern.size();
    vector<int> longestPrefix(m);           // index where to jump back to.
    for(int i = 1, j = 0;  i < m;  i++){
        while(j > 0 && pattern[j] != pattern[i]){
            j = longestPrefix[j - 1];
        }
        if(pattern[i] == pattern[j]){
            j++;
            longestPrefix[i] = j;
        }
        else{
            longestPrefix[i] = j;
        }
    }
}



void KMP(string str,string pat){
    int n = str.size();
    int m = pat.size();
    vector<int> longestPrefix = computePrefix(pat);
    for(int i = 0, k = 0; i < n; i++){
        while(k > 0 && pat[k] != str[i]){
            k = longestPrefix[k - 1];
        }
        if(str[i] == pat[k]){
            k++;
        }
        if(k == m){
            cout << i - m + 1 << "\n";
            k = longestPrefix[k - 1];
        }
    }
}
