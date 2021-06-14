#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    
    for (int i = 0; i < moves.size(); ++i) {
        for (int j = 0; j < board.size(); ++j) {
            if (board[j][moves[i] - 1] != 0) {
                basket.push(board[j][moves[i] - 1]);
                board[j][moves[i] - 1] = 0;
                break;
            }
        }
    }
    
    stack<int> s;
    while(!basket.empty()) {
        if (!s.empty() && s.top() == basket.top()) {
            basket.pop();
            s.pop();
            answer += 2;
            continue;
        }
        s.push(basket.top());
        basket.pop();
    }
    
    return answer;
}
