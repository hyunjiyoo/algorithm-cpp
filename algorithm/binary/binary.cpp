#include <iostream>

int bin[10];
int lastBinaryStep;

void setArr() {
    for(int i = 0; i < 10; ++i) {
        bin[i] = 0;
    }
}

void setBinary(int num, int step = 0) {
    if(num == 0) {
        lastBinaryStep = 9 - (step - 1);
        return;
    }
    
    bin[9 - step] = num % 2;
    num /= 2;
    step += 1;
    
    setBinary(num, step);
}

int main(int argc, const char * argv[]) {
    int num = 0;
    std::cin >> num;
    
    setArr();
    setBinary(num);
    
    for (int i = lastBinaryStep; i < 10; ++i) {
        std::cout << bin[i];
    }
//    int j = 0;
//    for(int i = 10; i > 0; --i) {
//        if(bin[i] == 1) {
//            j = i;
//            break;
//        }
//    }
//
//    for(int i = j; i >= 0; --i) {
//        std::cout << bin[i];
//    }
    std::cout << std::endl;
    
    return 0;
}

// 거꾸로 출력하지 않고, 거꾸로 저장하면 된다.
// 마지막 인덱스의 값을 변수에 넣어 마지막 지점을 기억할 수 있다.
// 0 도 숫자이다. 테스트시 주의! 예외처리 필수.

