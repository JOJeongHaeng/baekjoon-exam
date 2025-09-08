#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    for(int move : moves)
    {
        for(int i = 0; i<board.size(); i++)
        {
            if(board[i][move-1] != 0)
            {
                if(!st.empty() && st.top() == board[i][move-1])
                {
                    cout << st.top() << endl;
                    st.pop();
                    answer+=2;
                }
                else
                {
                    st.push(board[i][move-1]);
                }
                board[i][move-1] = 0;
                break;
            }
        }
    }
    return answer;
}