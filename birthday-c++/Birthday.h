#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

int days_in_mon[] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };

int DAYS(int mon)
{
	int days = 0 ;
	FOR(i,1,mon)
		days+= days_in_mon[i];
	return days;
}


class Birthday {

	public: string getNext(string date, vector<string> bdays) {

		vector<int> day;
		int cmonth = (date[0]-'0')*10 + (date[1] - '0');
		int cday = (date[3]-'0')*10 + (date[4] - '0');

		cday += DAYS(cmonth);

//		cout<<"c month :"<<cmonth<<"c day: "<<cday<<endl;
		FOR(i,0,bdays.size())
		{
			day.push_back(int(bdays[i][4] - '0') + 10*(int(bdays[i][3] - '0')));
			day[i] += DAYS((int(bdays[i][1] - '0') + 10*(int(bdays[i][0] - '0'))));
		}

again:
		int min_day = 10000;
		int mini = -1;
		FOR(i,0,bdays.size())
		{
//			cout<<"day :"<<day[i]<<"c day: "<<cday<<" i "<<i<<endl;
			if ( (day[i]-cday) >= 0 && (day[i]-cday)< min_day )
			{
				min_day = day[i] - cday;
				mini = i;
//				cout<<"Min i" << mini<<endl;
			}
		}
		if ( mini == -1 ) /* next year */
		{
			FOR(i,0,bdays.size())
					day[i]+=365;
			goto again;
		}
//		cout<<"Min ii " << mini<<endl;

		return bdays[mini].substr(0,5);
	}

};
