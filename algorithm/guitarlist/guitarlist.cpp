#include <iostream>
#include <algorithm>

int n, s, m, r;
int v[50];
bool dp[51][1'001];
bool able;

void init() {
    std::fill_n((bool*)dp, 51 * 1'001, false);
    able = false;
    r = 0;
}

void input() {
    
    std::cin >> n >> s >> m;
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
}


void solve(int idx = 0, int vol = s) {
    
    if (vol < 0 || vol > m)
        return;
    
    if (idx == n) {
        r = std::max(r, vol);
        able = true;
        return;
    }
    
    if (!dp[idx + 1][vol]) {
        dp[idx + 1][vol] = true;
        solve(idx + 1, vol + v[idx]);
        solve(idx + 1, vol - v[idx]);
    }
}


void output() {
    
    if (able)
        std::cout << r;
    else
        std::cout << -1;
}

int main (int argc, const char * argv []) {
    
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    init();
    input();
    solve();
    output();
    
    return 0;
}
