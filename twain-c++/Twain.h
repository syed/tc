#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i < (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()
#define INT_TO_STR(i,s) do{\
	ostringstream out;\
	out << i;\
	s = out.str();\
	}while(0)

#define WORD_STARTS_WITH_X(i,s)  ( (i>0 && s[i-1]==' ' && s[i]=='x') || (i==0 && s[i] == 'x') )
#define WORD_STARTS_WITH_KN(i,s)  ( (s.size()>1) && ( (i>0 && s[i-1]==' ' && s[i]=='k' && s[i+1] == 'n') || (i==0 && s[i] == 'k' && s[i+1] == 'n') ))

#define NOT_VOWEL(c) ( c!='a' && c!='e' && c!='i' && c!='o' && c!='u' && c!=' ')

class Twain {

	public: string getNewSpelling(int year, string phrase) {

		unsigned int pos = 0;
		FOR(z,0,year+1)
		{
			switch (z)
			{
			case 0:
				//cout<<"year "<<z<<" val "<<phrase<<endl;
				break;
			case 1:
				FOR(i,0,phrase.size())
				{
					if ( WORD_STARTS_WITH_X(i,phrase))
						phrase[i] = 'z';

					if ( phrase[i] == 'x')
					{
						phrase[i] = 'k';
						phrase.insert(i+1,1,'s');
					}
				}
				//cout<<"year "<<z<<" val "<<phrase<<endl;
				break;
			case 2:
				FOR(i,0,phrase.size())
					if( phrase[i] == 'y')
						phrase[i] = 'i';
				//cout<<"year "<<z<<" val "<<phrase<<endl;
				break;
			case 3:
				FOR(i,0,phrase.size()-1)
					if ( phrase[i] == 'c' && (phrase[i+1] == 'e' || phrase[i+1] == 'i'))
						phrase[i] = 's';
				//cout<<"year "<<z<<" val "<<phrase<<endl;
				break;
			case 4:
				for(int i=phrase.size();i>=0;i--)
				{
					if (phrase[i] == 'k' )
					{
						while( phrase[i-1] == 'c' )
							phrase.erase(i-1,1);
					}
				}
				//cout<<"year "<<z<<" val "<<phrase<<endl;
				break;

			case 5:
				while(1)
				{
					pos = phrase.find("sch",pos==0 ? pos : pos+1);
					if ( pos == string::npos)
						break;
					if ( pos == 0 || phrase[pos-1] == ' ')
					{
						phrase[pos+1] = 'k';
						phrase.erase(pos+2,1);
					}
				}
				// ch followed by k
				pos = 0;
				while(1)
				{
					pos = phrase.find("ch",pos==0 ? pos : pos+1);
					if ( pos == string::npos)
						break;
					if ( pos+2 < phrase.size() && phrase[pos+2] == 'r' )
					{
						phrase[pos] = 'k';
						phrase.erase(pos+1,1);
					}

				}
				FOR(i,0,phrase.size()-1)
					if ( phrase[i] == 'c' && phrase[i+1] != 'h')
						phrase[i] = 'k';

				if (phrase[phrase.size()-1] == 'c')
					phrase[phrase.size()-1] = 'k';

				//cout<<"year "<<z<<" val "<<phrase<<endl;
				break;
			case 6:

				FOR(i,0,phrase.size())
					if ( WORD_STARTS_WITH_KN(i,phrase))
					{
						//cout<<"KN starting at "<<i<<endl;
						phrase.erase(i,1);
					}
				//cout<<"year "<<z<<" val "<<phrase<<endl;
				break;
			case 7:
				FOR(i,0,phrase.size()-1)
				{
					if ( NOT_VOWEL(phrase[i]) && (phrase[i] == phrase[i+1]))
					{
						while(phrase[i+1] == phrase[i])
							phrase.erase(i+1,1);
					}
				}
				//cout<<"year "<<z<<" val "<<phrase<<endl;
				break;
			}
		}


		return phrase;
	}

};
