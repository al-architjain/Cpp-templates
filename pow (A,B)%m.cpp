int Mod(int A, int B, int m) {
    if (B == 0) return 1 % p;
    long long ans = 0;        
    if (B % 2 == 0) {
        ans = Mod(A, B/2, m);
        ans = (ans * ans) % m;
    } else {
        ans = A % m;
        ans = (ans * Mod(A, B - 1, m)) % m;
    }
    // Incase y is negative. 
    return (int)((ans + m) % m);
}
