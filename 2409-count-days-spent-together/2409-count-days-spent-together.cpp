class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = { 0 ,31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30,};
        for(int i = 1 ; i < 12 ; i++){
            days[i] += days[i-1];
        }
        auto toDays = [&](const string &date){
            int month = stoi(date.substr(0,2));
            int day = stoi(date.substr(3,2));
            return days[month - 1] + day;
        };
        int aliceStart = toDays(arriveAlice);
        int aliceEnd = toDays(leaveAlice);
        int bobStart = toDays(arriveBob);
        int bobEnd = toDays(leaveBob);

        int start = max(aliceStart, bobStart);
        int end = min(aliceEnd, bobEnd);

        return max(0, end - start + 1);
    }
};