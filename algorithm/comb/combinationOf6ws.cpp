#include <iostream>

const int num = 6;
int visit[num];
int selected[num];

void init() {
    for (int i = 0; i < num; ++i) {
        visit[i] = false;
    }
}

int selectBasis() {
    int result = -1;
    
    for (int i = 0; i < num; ++i) {
        if (visit[i] == false) {
            result = i;
            break;
        }
    }
    
    return result;
}

void print_result() {
    for (int i = 0; i < num; ++i) {
        std::cout << selected[i] << " ";
    }
    std::cout << std::endl;
}

void combination(int step = 0) {
    
//  종료조건
    if (step == 3) {
        print_result();
        return;
    }
    
//  재귀호출, 로직
    int basis = selectBasis();
    visit[basis] = true;
    selected[step * 2] = basis;
    
    for (int i = basis + 1; i < num; ++i) {
        if (visit[i])
            continue;
        
        int basis_pair = i;
        visit[basis_pair] = true;
        selected[step * 2 + 1] = basis_pair;
        
        combination(step + 1);
        
        visit[basis_pair] = false;
    }
    
    visit[basis] = false;
}

int main(int argc, const char* argv[]) {
    init();
    
    combination();
    
    return 0;
}

//    {
//        int first = selectBasis();
//        visit[first] = true;
//
//        for (int i = first + 1; i < num; ++i) {
//            if (visit[i])
//                continue;
//
//            int first_pair = i;
//            visit[first_pair] = true;
//
//            int second = selectBasis();
//            visit[second] = true;
//
//            for (int j = second + 1; j < num; ++j) {
//                if (visit[j])
//                    continue;
//
//                int second_pair = j;
//                visit[second_pair] = true;
//
//                int third = selectBasis();
//                visit[third] = true;
//
//                for(int k = third + 1; k < num; ++k) {
//                    if(visit[k])
//                        continue;
//
//                    int third_pair = k;
//                    visit[third_pair] = true;
//
//                    std::printf("(%d, %d), (%d, %d), (%d, %d)\n",
//                                first, first_pair,
//                                second, second_pair,
//                                third, third_pair);
//
//                    visit[third_pair] = false;
//                }
//                visit[third] = false;
//
//                visit[second_pair] = false;
//            }
//
//            visit[second] = false;
//
//            visit[first_pair] = false;
//        }
//
//        visit[first] = false;
//    }
//
//
