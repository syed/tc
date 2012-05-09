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
#define STR_TO_INT(s,i) do{\
	istringstream in(s);\
	in >> i;\
	in.clear();\
	}while(0)

int calculate_expensive(vector< vector<int> >mc)
{
	int max = -1;
	int maxi = -1;
	FOR(i,0,mc[0].size())
	{
		int sum = 0 ;
		FOR(j,0,mc.size())
			sum += mc[j][i];

		if ( sum > max )
		{
			max=sum;
			maxi=i;
		}
	}
	return maxi;
}

#define MIN(a,b) (a<b?a:b)
#define ROTATION_TIME(cur,dest,sz) MIN( abs(cur-dest) , (sz - abs(cur-dest)))

typedef struct purchases_struct {
	int row,col,time;
}purchase_t;

class VendingMachine {

	public: int motorUse(vector<string> prices, vector<string> purchases) {
		vector< vector<int> > mc;
		FOR(i,0,prices.size())
		{
			vector<int> v;
			string rprice(prices[i].rbegin(),prices[i].rend());
			int start=0;
			while( start < rprice.size())
			{
				int p = 0 ;
				int base = 1;
				while( start < rprice.size() && rprice[start] != ' ')
				{
					p += base*( rprice[start]- '0');
					base*=10;
					start++;
				}
				v.push_back(p);
				start++;
			}
			mc.push_back(vector<int>(v.rbegin(),v.rend()));
		}
		vector< purchase_t > transactions;
		FOR(i,0,purchases.size())
		{
			int row,col,time;
			int pos = purchases[i].find(',',0);
			string substr = purchases[i].substr(0,pos);
			STR_TO_INT(substr,row);
			int pos2 = purchases[i].find(':',pos);
			substr = purchases[i].substr(pos+1, pos2 - pos -1 );
			STR_TO_INT(substr,col);
			substr = purchases[i].substr(pos2+1,purchases[i].size());
			STR_TO_INT(substr,time);
			//cout<<"row "<<row<<" col "<<col<<" time "<<time<<endl;

			purchase_t p;
			p.row = row;
			p.col = col;
			p.time = time;
			transactions.push_back(p);
		}
		int expensive = calculate_expensive(mc);
		//cout<<"Expensive first"<<expensive<<endl;
		int total_time = ROTATION_TIME(0,expensive,mc[0].size());
		//cout<<"total_time "<<total_time<<endl;

		//first transaction
		purchase_t p = transactions[0];

		mc[p.row][p.col] = 0;
		total_time += ROTATION_TIME(expensive,p.col,mc[0].size());
		expensive = calculate_expensive(mc);
		//cout<<"total_time "<<total_time<<endl;
		int prev_col=p.col;
		FOR(i,1,transactions.size())
		{
			purchase_t prev,curr;
			prev = transactions[i-1];
			curr = transactions[i];
			if( mc[curr.row][curr.col] <= 0 )
				return -1;
			cout<<"Cur row "<<curr.row<<" Cur Col "<<curr.col<<" val "<<mc[curr.row][curr.col]<<endl;
			mc[curr.row][curr.col]  = 0;

			if ( curr.time - prev.time >= 5 )
			{
				//cout<<"goig to expensive slot"<<endl;
				total_time+= ROTATION_TIME(prev.col,expensive,mc[0].size());
				//cout<<"total_time , prev col"<<total_time<<"  "<<prev.col<<endl;
				total_time+= ROTATION_TIME(expensive,curr.col,mc[0].size());
				//cout<<"total_time , cur col"<<total_time<<"  "<<curr.col<<endl;
			}
			else
			{
				total_time+= ROTATION_TIME(prev.col,curr.col,mc[0].size());
				//cout<<"total_time "<<total_time<<endl;
			}

			expensive = calculate_expensive(mc);
			//cout<<"Expensive "<<expensive<<endl;
			prev_col  = curr.col;

		}
		total_time+= ROTATION_TIME(prev_col,expensive,mc[0].size());

		return total_time;
	}

};
