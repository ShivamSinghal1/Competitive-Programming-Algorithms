#include<bits/stdc++.h>
#define endl           "\n"
#define w(x)           int x; cin>>x; while(x--)
using namespace std;

void IO_FILE() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

string convert(string text) {
    string s;
    s += '#';
    for (auto x : text) {
        s += x;
        s += '#';
    }
    return s;
}
string LongestPalindromeSubString(string text)
{
    string s = convert(text);
    int n = s.length();
    int LPS[n];
    fill(LPS, LPS + n, 0);
    int l = 0, r = 0, c = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) {
            int i_mirror = l + (r - i);
            LPS[i] = min(r - i, LPS[i_mirror]);
        }
        while (i + LPS[i] + 1 < n and s[i + LPS[i] + 1] == s[i - LPS[i] - 1]) {
            LPS[i]++;
        }
        if (i + LPS[i] > r) {
            c = i;
            r = i + LPS[i];
            l = i - LPS[i];
        }
    }
    int ans_center = 0;
    for (int i = 1; i < n; i++) {
        if (LPS[ans_center] < LPS[i]) {
            ans_center = i;
        }
    }
    return  text.substr((ans_center - LPS[ans_center]) / 2, LPS[ans_center]);
}

int main() {
    IO_FILE();
    w(t)
    {
        string s;
        cin >> s;
        cout << LongestPalindromeSubString(s) << endl;
    }

    return 0;
}
