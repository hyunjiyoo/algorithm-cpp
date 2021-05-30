#include <iostream>
#include <algorithm>

int N;
int OIL[10'000][2];
int* POIL[10'000];
bool VISIT[10'000];
int L, P;
int R;

void init() {
    R = -1;
    
    for (int i = 0; i < 10'000; ++i) {
        OIL[i][0] = 0;
        OIL[i][1] = 0;
        POIL[i] = OIL[i];
        VISIT[i] = false;
    }
}


void input() {
    std::scanf("%d", &N);
    
    for (int i = 0; i < N; ++i)
        std::scanf("%d %d", &OIL[i][0], &OIL[i][1]);
    
    std::scanf("%d %d", &L, &P);
}


void sort() {
    std::sort(POIL, POIL + N, [](auto a, auto b) {
        return a[0] < b[0];
    });
}


void solve(int start = 0, int cnt = 0, int idx = 0, int gas = P, int prevstart = 0) {
    
    if (start + gas >= L) {
        R = cnt;
        return;
    }
    
    if (cnt > N) {
        return;
    }
    
    
    int remain = -99999999;
    int j = -1;
    for (int i = 0; i < N; ++i) {
        
        if (VISIT[i])
            continue;
    
        if (i > idx || idx == 0) {
            if (POIL[i][0] - start > gas) break;
            
            if (remain <= POIL[i][1] - (POIL[i][0] - start)) {
                remain = POIL[i][1] - (POIL[i][0] - start);
                j = i;
            }
        }
        else {
            
            if (remain <= POIL[i][1] - (POIL[i][0] - prevstart)) {
                remain = POIL[i][1] - (POIL[i][0] - prevstart);
                j = i;
            }
        }
    }
    
    if (j != -1) {
        VISIT[j] = true;
     
        if (POIL[j][0] - start > 0) {
            prevstart = start;
            start = POIL[j][0];
        }
        else {
            prevstart = POIL[j][0];
            remain = POIL[j][1];
        }
    }
    
    solve(start, cnt + 1, j, gas + remain, prevstart);
}

int main (int argc, const char * argv []) {
    
    init();
    input();
    sort();
    solve();
    std::printf("%d", R);
    
    return 0;
}
