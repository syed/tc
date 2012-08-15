#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i < (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()


/* area is given by
 *
 * (x1y2 - x2y1) + (x2y3-x3y2) ..... (xny1-ynx1)/2
 *
 */

double cross_product(pair<int,int> p1 , pair<int,int> p2)
{
	return (p1.first*p2.second - p2.first*p1.second);
}


class ConvexPolygon {

	public: double findArea(vector<int> x, vector<int> y) {
		// sum of area of triangles
		double area = 0;
		pair<int,int> p1,p2;
		FOR(i,0,x.size()-1)
		{
			p1 = make_pair(x[i],y[i]);
			p2 = make_pair(x[i+1],y[i+1]);

			area+= cross_product(p1,p2);
		}

		int sz = x.size();
		p1 = make_pair(x[sz-1],y[sz-1]);
		p2 = make_pair(x[0],y[0]);

		area += cross_product(p1,p2);

		return fabs(area/2);
	}

};
