#include <iostream>
#include <string>
#include <vector>
#include <set>

int n, k;
int card[10];
bool chk[10];
std::vector<int> v;
std::set<std::string> result;

void init() {
    for (int i = 0; i < 10; ++i) {
        card[i] = 0;
        chk[i] = false;
    }
}

void input() {
    std::cin >> n >> k;
    
    v.resize(k);
    for (int i = 0; i < n; ++i) {
        std::cin >> card[i];
    }
}


void solve(int step = 0) {
   
    if (step == k) {
        
        std::string str = "";
        for (int i : v) {
            str += std::to_string(i);
        }
        
        result.insert(str);
        
        return;
    }
    
    for (int i = 0; i < n; ++i) {
        if (chk[i]) continue;
        
        chk[i] = true;
        v[step] = card[i];
        solve(step + 1);
        chk[i] = false;
    }
}


int main (int argc, const char * argv []) {
    
    init();
    input();
    solve();
    std::cout << result.size();
    
    return 0;
}
