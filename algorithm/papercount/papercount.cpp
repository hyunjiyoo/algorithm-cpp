#include <iostream>
using namespace std;

int N;
int paper[2'200][2'200];
int minusOne, plusOne, zero;


void init() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            scanf("%d", &paper[i][j]);
        
    minusOne = plusOne = zero = 0;
}


void solve(int s1, int s2, int n) {
    
    int tmp = paper[s1][s2];
    for (int i = s1; i < s1 + n; ++i) {
        for (int j = s2; j < s2 + n; ++j) {
            if (tmp != paper[i][j])  {
                
                solve(s1, s2, n/3);
                solve(s1, s2 + n/3, n/3);
                solve(s1, s2 + n*2/3, n/3);
                
                solve(s1 + n/3, s2, n/3);
                solve(s1 + n/3, s2 + n/3, n/3);
                solve(s1 + n/3, s2 + n*2/3, n/3);
                
                solve(s1 + n*2/3, s2, n/3);
                solve(s1 + n*2/3, s2 + n/3, n/3);
                solve(s1 + n*2/3, s2 + n*2/3, n/3);
                
                return;
            }
        }
    }

    
    if (tmp == 0) zero += 1;
    if (tmp == 1) plusOne += 1;
    if (tmp == -1) minusOne += 1;
}


int main (int argc, const char * argv []) {
   
    init();
    solve(0, 0, N);
    printf("%d\n%d\n%d", minusOne, zero, plusOne);
    
    return 0;
}
