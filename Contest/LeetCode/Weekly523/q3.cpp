class BusBooking {
public:

    int cnt = 0;
    vector<vector<int>> seats;
    int time = 0;

    BusBooking(int n) {
        seats.resize(n,vector<int>(4,-1));
    }
    
    void toggle(string seat) {
        char ch = seat[0];
        int row = 0;
        for(int i=1;i<seat.size();i++){
            int dig = seat[i]-'0';
            row*=10;
            row += dig;
        }
        row--;
        if (seats[row][ch-'A'] != -1){
            time -= seats[row][ch-'A'];
            seats[row][ch-'A'] = -1;
            cnt--;
        }
        else{
            cnt++;
            if (ch == 'A'){
                if (seats[row][1] != -1){
                    time += 3;
                    seats[row][ch-'A'] = 3;
                }
                else{
                    time += 1;
                    seats[row][ch-'A'] = 1;
                }
            }
            else if (ch == 'D'){
                if (seats[row][2] != -1){
                    time += 3;
                    seats[row][ch-'A'] = 3;
                }
                else{
                    time += 1;
                    seats[row][ch-'A'] = 1;
                }
            }
            else{
                time++;
                seats[row][ch-'A'] = 1;
            }
        }
    }
    
    int getTotalTime() {
        return time;
    }
    
    int getMinTime() {
        return cnt;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */
