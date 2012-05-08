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

int num_array[] = { 10,11,12,13,14,15,16,17,18,19 };
#define NUM(c) ( c<='9'?c-'0': num_array[c-'A'])

int convert_to_num(string s, int base)
{
	int num=0;
	int exp=1;
	for(int i=s.size()-1;i>=0;i--)
	{
		if ( NUM(s[i])>= base )
			return -1;
		num+=(NUM(s[i])*exp);
		exp *=base;
	}

	return num;
}

class BaseMystery {

	public: vector<int> getBase(string equation) {

		vector<int> ret;

		FOR(i,2,21)
		{
			int pos1,pos2;
			string::iterator sit;

			pos1 = equation.find('+',0);
			pos2 = equation.find('=',0);

			string num1_str(equation.begin(),equation.begin() + pos1);
			string num2_str(equation.begin()+pos1+1,equation.begin() + pos2);
			string sum_str(equation.begin()+pos2+1,equation.end());


			int num1 = convert_to_num(num1_str,i);
			int num2 = convert_to_num(num2_str,i);
			int sum = convert_to_num(sum_str,i);


			if ( num1>=0 && num2>=0 && sum>=0 && (num1 + num2 == sum) )
				ret.push_back(i);
		}
		return ret;
	}

};
