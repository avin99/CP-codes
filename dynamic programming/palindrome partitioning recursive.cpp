bool ispalindrome(string s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j])return false;
        i++; j--;
    }
    return true;
}
int solve(string s, int i, int j) {
    if (i >= j)return 0;
    if (ispalindrome(s, i, j))return 0;
    int mn = INT_MAX;
    for (int k = i; k < j; k++) {
        int temp = 1 + solve(s, i, k) + solve(s, k + 1, j);
        if (temp < mn) {
            mn = temp;
        }
    }
    return mn;

}