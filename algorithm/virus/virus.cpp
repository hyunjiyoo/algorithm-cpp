#include <iostream>

int CNT;
int NET;
bool COM[100][100];
bool DP[100];
int R;

void solve(int idx = 0) {
    
    for (int j = 0; j < CNT; ++j) {
        if (!DP[j] && COM[idx][j]) {
            DP[j] = true;
            solve(j);
        }
    }
}

int main (int argc, const char * argv []) {

    std::scanf("%d\n%d", &CNT, &NET);

    int L, R;
    for (int i = 0; i < NET; ++i) {
        std::scanf("%d %d", &L, &R);
        COM[L-1][R-1] = true;
        COM[R-1][L-1] = true;
    }
    
    R = 0;
    solve();
    
    for (int i = 1; i < CNT; ++i)
        if(DP[i]) R += 1;

    std::printf("%d", R);
    
    return 0;
}
