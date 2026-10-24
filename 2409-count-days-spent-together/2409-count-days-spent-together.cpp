class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        string a=max(arriveAlice,arriveBob);
        string b=min(leaveAlice,leaveBob);
        if(a>b) return 0;
        int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
        auto ans=[&](string date){
            int m=stoi(date.substr(0,2));
            int d=stoi(date.substr(3,2));
            int t=d;
            for(int i=0;i<m-1;i++)
            {
                t+=days[i];
            }
            return t;
        };
        return ans(b)-ans(a)+1;

    }
};