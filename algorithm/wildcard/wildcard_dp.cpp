#include <iostream>
#include <cstring>
#include <string>


int C, N;
std::string W;
std::string S;

// -1 은 아직 답이 계산되지 않았음
//  1 은 해당 입력들이 서로 대응
//  0 은 해당 입력들이 서로 대응되지 않음
int cache[101][101];

std::string R[50][100];

void init() {
    std::memset(cache, -1, sizeof cache);
}

bool solve(int w = 0, int s = 0) {
    // memoization
    int& ret = cache[w][s];
    if (ret != -1) return ret;
    
    while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        ++w;
        ++s;
    }
    
    if (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])) {
        solve(w + 1, s + 1);
    }
    
    
    if (w == W.size()) return ret = (s == S.size());
    
    // *을 만나서 끝난 경우: *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인
    if (W[w] == '*')
        for (int skip = 0; skip + s <= S.size(); ++skip)
            if (solve(w + 1, s + skip))
                return ret = 1;
    
    if (W[w] == '*')
        if (solve(w + 1, s) || (s < S.size() && solve(w, s + 1)))
            return ret = 1;
    
    // 이 외의 경우는 모두 대응되지 않음
    return ret = 0;
}


void sortprint(int idx, int len) {
    
    int cmp = 0;
    std::string tmp = "";
    
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            
            cmp = strcmp(R[idx][i].c_str(), R[idx][j].c_str());
            
            if (cmp > 0) {
                tmp = R[idx][j];
                R[idx][j] = R[idx][i];
                R[idx][i] = tmp;
            }
            
        }
    }
    
    for (int i = 0; i < len; ++i) {
        std::cout << R[idx][i] << std::endl;
    }
    
}


int main (int argc, const char * argv []) {
    
    std::scanf("%d", &C);
    
    for (int i = 0; i < C; ++i) {
        std::cin >> W;
        std::scanf("%d", &N);
        
        int idx = 0;
        for (int j = 0; j < N; ++j) {
            init();
            std::cin >> S;
            
            if (solve()) {
                R[i][idx] = S;
                idx += 1;
            }
        }
        
        sortprint(i, idx);
    }
    
    return 0;
}
