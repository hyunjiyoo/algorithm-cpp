#include <iostream>
#include <string>

int N, C;
std::string W, S;
std::string R[10][50];

// 와일드카드 패턴 w가 문자열 s에 대응되는지 여부를 반환한다.
bool solve(const std::string& w, const std::string& s) {
    // w[pos]와 s[pos]를 맞춰나간다.
    int pos = 0;
    
    while (pos < s.size() && pos < w.size() && (w[pos] == '?' || w[pos] == s[pos]))
        ++pos;
    
    // 더이상 대응할 수 없으면 왜 while문이 끝났는지 확인한다.
    // 2. 패턴 끝에 도달해서 끝난 경우: 문자열도 끝났어야 대응됨.
    if (pos == w.size())
        return pos == s.size();
    
    // 4. * 를 만나서 끝난 경우: *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인
    if (w[pos] == '*')
        for (int skip = 0; pos + skip <= s.size(); ++skip)
            if (solve(w.substr(pos + 1), s.substr(pos + skip)))
                return true;
    
    return false;
}


void sortprint(int idx, int len) {
    
    int cmp = 0;
    std::string tmp = "";
    
    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            cmp = std::strcmp(R[idx][i].c_str(), R[idx][j].c_str());
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



int main(int argc, const char * argv []) {
    
    std::scanf("%d", &C);
    for (int i = 0; i < C; ++i) {
        std::cin >> W;
        std::scanf("%d", &N);
        
        int idx = 0;
        for (int j = 0; j < N; ++j) {
            std::cin >> S;
            if (solve(W, S)) {
                R[i][idx] = S;
                idx += 1;
            }
        }
        
        sortprint(i, idx);
    }
    
    return 0;
}
