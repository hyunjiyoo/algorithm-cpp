#include <string>
#include <vector>
#include <map>

using namespace std;

multimap<string, int> p;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for (int i = 0; i < participant.size(); ++i)
        p.insert(pair<string, int>(participant[i], i));
    
    for (auto i = completion.begin(); i != completion.end(); ++i)
        p.erase(p.find(*i));
    
    for (auto i = p.begin(); i != p.end(); ++i)
        answer = (*i).first;
    
    return answer;
}
