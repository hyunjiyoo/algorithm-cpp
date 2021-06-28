#include <iostream>
#include <vector>

int N;
std::vector<int> v, ans;

void input() {
    std::scanf("%d", &N);
    
    v.resize(N);
    ans.resize(N);
    
    for (int i = 0; i < N; ++i) {
        std::scanf("%d", &v[i]);
        ans[i] = 0;
    }
}

void solve() {

    for (int i = 0; i < N; ++i) {
        
        int count = 0;

        for (int j = 0; j < N; ++j) {
            if (v[i] == 0 && ans[j] == 0) {
                ans[j] = i + 1;
                break;
            }
            else {
                
                if (ans[j] == 0)
                    ++count;
                
                if (v[i] == count && ans[j + 1] == 0) {
                    ans[j + 1] = i + 1;
                    break;
                }
            }
        }
    }
}



int main (int argc, const char * argv []) {

    input();
    solve();

    for (int i = 0; i < N; ++i)
        std::printf("%d ", ans[i]);

    return 0;
}
