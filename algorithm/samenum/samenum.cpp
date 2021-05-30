#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
int A[1'000];
int UNIQUEA[1'000];
int UP[1'000];
int DIFF[1'000];
int len;
int64_t R;

void init() {
    len = R = 0;
    for (int i = 0; i < 1000; ++i) {
        A[i] = 0;
        UP[i] = -1;
    }
}

void input() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", A + i);
}

void removeDup() {
    int j = 0;
    for (int i = 1; i < n; ++i) {
        UNIQUEA[j] = A[i - 1];
        
        if (UNIQUEA[j] == A[i])
            continue;
        
        if (i == n - 1 && UNIQUEA[j] != A[n - 1]) {
            UNIQUEA[j + 1] = A[n - 1];
            break;
        }
        
        ++j;
    }
    len = j + 1;
}

void graph() {
    for (int i = 1; i <= len; ++i) {
        if (UNIQUEA[i] - UNIQUEA[i - 1] > 0)
            UP[i - 1] = 1;
        else
            UP[i - 1] = 0;
    }
}


void solve() {
    for (int i = 1; i <= len; ++i) {
        DIFF[i - 1] = abs(UNIQUEA[i] - UNIQUEA[i - 1]);
    }
    
    for (int i = 0; i < len; ++i) {
        if (UP[i])
            R += DIFF[i];
    }
    
    int endnum = (UNIQUEA[len] != 0) ? UNIQUEA[len] : UNIQUEA[len - 1];
    sort(UNIQUEA, UNIQUEA + len + 1);
    R += (UNIQUEA[len] - endnum);
    
    printf("%lld", R);
}


int main (int argc, const char * argv []) {
    init();
    input();
    removeDup();
    graph();
    solve();
    
    return 0;
}
