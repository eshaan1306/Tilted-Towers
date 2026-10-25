class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};
        vector<string> dates = {arriveAlice, leaveAlice, arriveBob, leaveBob};
        vector<int> a(4);
        for (int i=0;i<4;i++){
            int month = stoi(dates[i].substr(0, 2));
            int day = stoi(dates[i].substr(3, 2));
            for (int j = 0; j < month - 1; j++)
                day += days[j];
            a[i] = day;
        }
        return max(0, min(a[1], a[3]) - max(a[0], a[2]) + 1);
    }
};
