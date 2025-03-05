#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for(int i=0; i<schedules.size(); i++){
        int today = startday;
        int count = 0;
        schedules[i] +=10;
        if(schedules[i]%100 >= 60) schedules[i]+=40;
        for(int log : timelogs[i]){
            if(today == 6 || today == 7) {
                today++;
                count++;
            }
            else if(schedules[i] >= log)  {
                today++;
                count++;
            }
            else break;
            if(today == 8) today = 1;
        }
        if(count == 7) answer++;
    }
    return answer;
}