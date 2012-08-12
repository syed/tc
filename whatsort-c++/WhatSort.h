#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

#define FOR(i,s,e) for (int i = int(s); i != int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i < (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

#define EQ(p1,p2) ( (p1.name == p2.name) && (p1.age == p2.age) && (p1.weight == p2.weight) )

// 6 possibilites Name(Asc),Age(Asc),Wt(Des)

typedef struct person_t {
	string name;
	int age;
	int weight;
} person;

bool cmp_naw(person a,person b)
{
	if ( a.name < b.name )
		return true;
	else if ( a.name > b.name )
		return false;
	else
	{
		if ( a.age < b.age)
			return true;
		else if( a.age > b.age )
			return false;
		else
		{
			if( a.weight > b.weight)
				return true;
			else if( a.weight < b.weight )
					return false;
			else
				return true;
		}
	}
}

bool cmp_nwa(person a,person b)
{
	if ( a.name < b.name )
		return true;
	else if ( a.name > b.name )
		return false;
	else
	{
		if ( a.weight > b.weight)
			return true;
		else if( a.weight < b.weight )
			return false;
		else
		{
			if( a.age < b.age)
				return true;
			else if( a.age > b.age )
					return false;
			else
				return true;
		}
	}
}

bool cmp_anw(person a,person b)
{
	if ( a.age < b.age )
		return true;
	else if ( a.age > b.age )
		return false;
	else
	{
		if ( a.name < b.name)
			return true;
		else if( a.name > b.name )
			return false;
		else
		{
			if( a.weight > b.weight)
				return true;
			else if( a.weight < b.weight )
					return false;
			else
				return true;
		}
	}
}

bool cmp_awn(person a,person b)
{
	if ( a.age < b.age )
		return true;
	else if ( a.age > b.age )
		return false;
	else
	{
		if ( a.weight > b.weight )
			return true;
		else if( a.weight < b.weight )
			return false;
		else
		{
			if( a.name < b.name)
				return true;
			else if( a.name > b.name )
					return false;
			else
				return true;
		}
	}
}

bool cmp_wan(person a,person b)
{
	if ( a.weight > b.weight )
		return true;
	else if ( a.weight < b.weight )
		return false;
	else
	{
		if ( a.age < b.age)
			return true;
		else if( a.age > b.age )
			return false;
		else
		{
			if( a.name < b.name)
				return true;
			else if( a.name > b.name )
					return false;
			else
				return true;
		}
	}
}

bool cmp_wna(person a,person b)
{
	if ( a.weight > b.weight )
		return true;
	else if ( a.weight < b.weight )
		return false;
	else
	{
		if ( a.name < b.name)
			return true;
		else if( a.name > b.name )
			return false;
		else
		{
			if( a.age < b.age)
				return true;
			else if( a.age > b.age )
					return false;
			else
				return true;
		}
	}
}
class WhatSort {

	public: string sortType(vector<string> name, vector<int> age, vector<int> wt) {
		vector<person> p;
		FOR(i,0,name.size())
		{
			person per;
			per.name = name[i];
			per.age = age[i];
			per.weight = wt[i];
			p.push_back(per);
		}
		char *met[] = {"NAW" , "NWA" , "ANW" , "AWN" , "WAN" , "WNA" };
		bool (*cmp[6]) ( person a,person b)  = { cmp_naw , cmp_nwa , cmp_anw , cmp_awn , cmp_wan , cmp_wna };
		int sort_count  = 0 ;
		char *ret;
		int sz = name.size();
		FOR(i,0,6)
		{
			vector<person> temp ;
			temp  = p ;
			sort(temp.begin(),temp.end(), cmp[i]);
			bool sorted = true;
			FOR(j,0,sz)
			{
				if (! EQ(temp[j],p[j]))
				{
					sorted = false;
					break;
				}
			}
			if ( sorted)
			{
				sort_count++;
				ret = met[i];
			}
		}
		if ( sort_count > 1)
			return "IND";
		else if ( sort_count == 0  )
			return "NOT";

		return string(ret);
	}

};
