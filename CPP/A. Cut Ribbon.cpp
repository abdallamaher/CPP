/*
Dynamic_Programing solution for Cut_Ribbon codeforces problem,
With OOP style.
https://codeforces.com/contest/189/problem/A
*/

#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 4e3 + 5;
int n, a, b, c;
int dp[4][N];
int mem[N];

class Cut_Ribbon {
public:
    static void brute_force();

    static int Memoization(int rem);

    static void Table();
};

void Cut_Ribbon::brute_force(){
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int ii = 0; ii <= n; ii++) {
            int t = n - (a * i + b * ii);
            if (t >= 0 && !(t % c)) {
                ans = max(ans, i + ii + t / c);
            }
        }
    }
    cout << ans;
}

int Cut_Ribbon::Memoization(int rem) {
    if (rem == 0)return 0;
    if (rem < 0)return -1e8;
    if (~mem[rem])return mem[rem];
    int ans = -1e9;
    ans = max(ans, 1 + Memoization(rem - a));
    ans = max(ans, 1 + Memoization(rem - b));
    ans = max(ans, 1 + Memoization(rem - c));
    return mem[rem] = ans;
}

void Cut_Ribbon::Table() {
    vector<int> v(n + 3);
    v[1] = a, v[2] = b, v[3] = c;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= n; j++) {
            int a, b = 0;
            a = dp[i - 1][j];
            if (j >= v[i] && (j == v[i] || dp[i][j - v[i]])) b = dp[i][j - v[i]] + 1;
            dp[i][j] = max(a, b);
        }
    }
    cout << dp[3][n];
}

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> a >> b >> c;
    memset(mem, -1, sizeof(mem));
    Cut_Ribbon::Table();
    //cout << Cut_Ribbon::Memoization(n);
    //Cut_Ribbon::brute_force();
    return 0;
}

