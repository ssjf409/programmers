#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    vector<string> temp;

    for(int i = 0; i < record.size(); i++) {
        if(record[i].find("RECEIVE ") != -1) {
            temp.push_back(record[i].substr(8));
        } else if(record[i].find("DELETE") != -1) {
            if(temp.size() != 0) {
                temp.pop_back();
            }
        } else if(record[i].find("SAVE") != -1) {
            if(temp.size() != 0) {
                for(int j = 0; j < temp.size(); j++) {
                    answer.push_back(temp[j]);
                }
                temp.clear();
            }
        }
    }
    return answer;
}

int main() {
    vector<string> str = {"RECEIVE abcd@naver.com", "RECEIVE zzkn@naver.com", "DELETE", "RECEIVE qwerty@naver.com", "SAVE", "SAVE", "DELETE", "RECEIVE QwerTY@naver.com", "SAVE"};
    vector<string> temp = solution(str);
    for(int k = 0; k < temp.size(); k++) {
        cout << temp[k] << '\n';
    }
    return 0;
}