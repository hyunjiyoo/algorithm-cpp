#include <iostream>
#include <string>

int N;
std::string R;
std::string BD[64];

const int dy[] = { 0, 0, 1, 1 };
const int dx[] = { 0, 1, 0, 1 };

std::string solve(int y, int x, int step, int dim) {
    if (step == 1) // 더이상 쪼갤 수 없으면 해당 블럭을 리턴
        return std::string{BD[y][x]};
    
    int next_step = step / 2;
    
    std::string ret[4];
    
    for (int i = 0; i < 4; ++i) { // 4개로 쪼개서 각각의 경우를 구함
        const int ny = y + (dy[i] * next_step);
        const int nx = x + (dx[i] * next_step);
        ret[i] = solve(ny, nx, next_step, i);
    }
    
    bool allsame = false; // 합치기가 가능한지 여부를 나타내는 플래그

    if (ret[0].length() == 1) { // 첫번째가 1자리수 (0 또는 1) 이 나왔을때 모두 다 같으면 합칠 수 있다.
        allsame = true;

        for (int i = 1; i < 4; ++i) {
            if (ret[0] != ret[i]) {
                allsame = false;
                break;
            }
        }
    }

    if (allsame) // 합칠 수 있다면 모두 같다는 뜻이니 하나만 리턴
        return ret[0];
    else // 합칠 수 없으면 각각 나눠서 리턴
        return "(" + ret[0] + ret[1] + ret[2] + ret[3] + ")";
}

void init() {
    for (int i = 0; i < 64; ++i)
        BD[i].resize(64);
}

void input() {
    std::cin >> N;
    for (int i = 0; i < N; ++i)
        std::cin >> BD[i];
}

void output() {
    std::cout << R;
}

int main(int argc, const char* argv[]) {
    init();
    input();
    R = solve(0, 0, N, 0);
    output();
    return 0;
}
