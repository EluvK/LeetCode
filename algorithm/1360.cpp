class Solution {
public:
    bool isLeapYear(int year){
        return ((year%4==0 && year%100!=0) || year%400==0);
    }

    int getDays(int year, int month, int day){
        int m[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(isLeapYear(year))
            m[2]++;
        int result = 0;
        for(int i = 1;i < year;i++){
            result += 365;
            if(isLeapYear(i))
                result ++;
        }
        for(int i = 1;i < month;i++){
            result += m[i];
        }
        result += day;
        return result;
    }

    int daysBetweenDates(string date1, string date2) {
        int y1,y2,m1,m2,d1,d2;
        y1=stoi(date1.substr(0,4));
        y2=stoi(date2.substr(0,4));
        m1=stoi(date1.substr(5,2));
        m2=stoi(date2.substr(5,2));
        d1=stoi(date1.substr(8,2));
        d2=stoi(date2.substr(8,2));
        return abs(getDays(y1, m1, d1) - getDays(y2, m2, d2));
    }
};
