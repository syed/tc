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

class FormatAmt {

	public: string amount(int dollars, int cents) {
		ostringstream out;
		string dollars_str;

		out << dollars;
		dollars_str = out.str();
		//cout <<dollars_str;
		/* Better solution
		 * String s = "."+(cents<10?"0":"")+cents;
   do{
      s = (dollars%1000)+s;
      if(dollars/1000 > 0){
         if(dollars%1000<100)s = "0"+s;
         if(dollars%1000<10)s = "0"+s;
      }
      dollars/=1000;
      if(dollars>0)s=","+s;
   }while(dollars>0);
   return "$"+s;
		 */
		int count =0;
		for(int i = dollars_str.length()-1 ; i>=0 ;i--)
		{
			count++;
			if ( i && count % 3 == 0 )
				dollars_str.insert(i , 1 , ',');
		}
		dollars_str.insert(0,1,'$');
		dollars_str.insert(dollars_str.length(),1,'.');
		//http://stackoverflow.com/questions/624260/how-to-reuse-an-ostringstream
		out.str("");
		if ( cents < 10)
			out << "0";

		out << cents;

		dollars_str.append(out.str());
		return dollars_str;
	}

};
