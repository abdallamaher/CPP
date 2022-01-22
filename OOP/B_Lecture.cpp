/*
Implementation solution for a codeforces problem,
With OOP style.
https://codeforces.com/problemset/problem/499/B
*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

struct DICT {
    vector<pair<string, string>> v;

    void add(string& a, string& b) {
        v.push_back({ a, b });
    }

    string find(string& x) {
        for (auto it : v) {
            if (it.first == x || it.second == x) {
                if (it.first.size() <= it.second.size())return it.first;
                else return it.second;
            }
        }
    }

};


int main() {
    int n, m; cin >> n >> m;
    DICT dict;
    for (int i = 0; i < m; i++) {
        string s, ss; cin >> s >> ss;
        dict.add(s, ss);
    }
    for (int i = 0;i < n;i++) {
        string s; cin >> s;
        cout << dict.find(s) << ' ';
    }
    return 0;
}