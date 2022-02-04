#include <iostream>
#include <algorithm>

int n, s, m, r;
int v[50];
int dp[51][1'001];
bool able;


void init() {
    std::fill_n((int*)dp, 51 * 1'001, -1);
    able = false;
    r = 0;
}

void input() {
    
    std::cin >> n >> s >> m;
    for (int i = 0; i < n; ++i)
        std::cin >> v[i];
}


int solve(int idx = 0, int vol = s) {
    
    if (vol < 0 || vol > m)
        return 0;
    
    if (idx == n) {
        r = std::max(r, vol);
        able = true;
        return 0;
    }
    
    if (dp[idx + 1][vol] == -1) {
        dp[idx + 1][vol] = solve(idx + 1, vol + v[idx]);
        dp[idx + 1][vol] += solve(idx + 1, vol - v[idx]);
    }
    
    return dp[idx + 1][vol];
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
