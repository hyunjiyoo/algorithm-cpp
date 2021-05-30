#include <iostream>

const int std_max_cnt = 10;

// 학생 수의 최대값이 10 이기 때문에 max값을 10으로 설정
bool friend_list[std_max_cnt][std_max_cnt];
// 해당 값이 할당이 되었는지 안되었는지 체크해주는 변수
bool visit[std_max_cnt];
// 짝을 지어줘서 순서대로 담아줄 변수
int selected[std_max_cnt];

int case_cnt; // 검사할 케이스 수
int pair_cnt; // 짝의 개수
int std_cnt; // 학생수
int tot_cnt; // 친구가 될 수 있는 경우의 수


// 초기화
void init() {
    // 처음에 학생수와 짝의 수를 받아준다.
    std::cin >> std_cnt >> pair_cnt;
    
    // 케이스가 바뀌었을 때 친구가 될 수 있는 경우의 수를 초기화해줘야 한다.
    tot_cnt = 0;
    
    // visit[]과 selected[]를 학생수만큼 배열을 초기화 해준다.
    // friend_list[][]는 처음 모두가 친구가 아니라고 가정해준다.
    for (int i = 0; i < std_cnt; ++i) {
        visit[i] = false;
        selected[i] = i;
        for (int j = 0; j < std_cnt; ++j) {
            friend_list[i][j] = false;
        }
    }
        
    // 짝의 수만큼 input을 받아서 친구리스트에 할당해준다.
    // 이 때, 인덱스를 반대로도 해준다. (**)
    for (int i = 0; i < pair_cnt; ++i) {
        int left;
        int right;
        std::cin >> left >> right;
        
        friend_list[left][right] = true;
        friend_list[right][left] = true;
    };
}


// 기준의 값을 중복제거를 위해 가장 작은 값을 뽑아야 하기때문에
// visit[i] 이 false가 되는 가장 첫번째 값을 리턴해준다.
int pickNum() {
    int basis = -1;
    for(int i = 0; i < std_cnt; ++i) {
        if(visit[i] == false) {
            basis = i;
            break;
        }
    }
    return basis;
}


//
void combination(int step = 0) {
    
    // step에 2를 곱해주는 이유는 combination() 호출은 짝을 짝을 이룰 수 있는 개수만큼 호출되어야 하기 때문이다.
    // 짝을 이룰 수 있는 최대 개수는 (std_cnt / 2) 이다. 그런데 step이 '0'부터 시작하기 때문에 >= 의 조건을 만들어준다.
    if(step * 2 >= std_cnt) {
        // step * 2 == std_cnt 가 되었다는 것은 학생끼리 모두 짝을 이룬 경우이기 때문에 tot_cnt를 1증가 시켜준다.
        ++tot_cnt;
        // 리턴을 해줘야 스택에 쌓여있는 combination()을 pop 시키고 다시 combination()을 호출한다.
        return;
    }
    
    // 학생을 뽑는다.
    int num = pickNum();
    // 학생이 뽑힌 것에 대한 flag를 설정해준다.
    visit[num] = true;
    // 뽑힌 학생을 selected[]에 차례대로 담는다.
    selected[step * 2] = num;
    
    // 학생의 짝은 그 학생 번호보다 무조건 크다. (중복제거)
    for(int i = num + 1; i < std_cnt; ++i) {
        // 이미 뽑은 학생이거나 서로 친구가 아니면 무시한다.
        if(visit[i] || !friend_list[num][i])
            continue;
        
        // 아니면 짝번호에 할당
        int num_pair = i;
        // 학생이 뽑힌 것에 대한 flag를 설정해준다.
        visit[num_pair] = true;
        // 학생 인덱스의 다음 인덱스에 짝 번호를 넣어준다.
        selected[step * 2 + 1] = num_pair;
        
        // 짝을 다시 찾는다. 이때 step 을 1 증가시켜준다.
        // 첫번째 짝을 찾았으니 다음짝을 찾기위해 1 증가.
        combination(step + 1);
        
        // 짝을 모두 찾고나서 새로운 짝을 찾기 위해 flag를 초기화해준다.
        visit[num_pair] = false;
    }
    
    // 학생을 다시 뽑기 위해 flag를 초기화해준다.
    visit[num] = false;
}

int main() {
    std::cin >> case_cnt;
    
    for (int i = 0; i < case_cnt; ++i) {
        init();
        combination();
        
        std::cout << tot_cnt << std::endl;
    }
        
    return 0;
}
