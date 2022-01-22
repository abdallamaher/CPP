/*
Dynamic_Programing solution for Cut_Ribbon codeforces problem,
With OOP style.
https://codeforces.com/contest/189/problem/A
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int mem[(int)4e4 + 4];

struct Cut_Ribbon {
    int n, a, b, c;
    vector<int>dp;

    Cut_Ribbon(int N, int A, int B, int C) {
        n = N; a = A; b = B; c = C;
        dp.resize(n * n);
        memset(mem, -1, sizeof(mem));
    }

    int brute_force() {
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                int x = n - i * a - j * b;
                if (x < 0 || x % c)continue;
                ans = max(ans, i + j + x / c);
            }
        }
        return ans;
    }

    int Memoization(int rem) {
        if (rem < 0)return -1e9;
        if (rem == 0)return 0;
        int& ret = mem[rem];
        if (~ret)return ret;
        int A = Memoization(rem - a) + 1;
        int B = Memoization(rem - b) + 1;
        int C = Memoization(rem - c) + 1;
        return ret = max({ A, B, C });
    }

    int Table() {
        for (int i = 1; i <= n;i++)dp[i] = -1;
        for (int i = 0; i <= n; i++) {
            if (dp[i] == -1)continue;
            dp[i + a] = max(dp[i + a], dp[i] + 1);
            dp[i + b] = max(dp[i + b], dp[i] + 1);
            dp[i + c] = max(dp[i + c], dp[i] + 1);
        }
        return dp[n];
    }
};

int main() {
    cin.sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    Cut_Ribbon* e;
    e = new Cut_Ribbon(n, a, b, c);
    cout << e->Table();
    // cout << e->Memoization(n);
    // cout << e->brute_force();
    return 0;
}


