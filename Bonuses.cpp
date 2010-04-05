//SOLVE LATER 

#include <vector>                                                     
#include <list>                                                       
#include <map>                                                        
#include <set>                                                        
#include <deque>                                                      
#include <stack>                                                      
#include <bitset>                                                     
#include <algorithm>                                                  
#include <functional>                                                 
#include <numeric>                                                    
#include <utility>                                                    
#include <sstream>                                                    
#include <iostream>                                                   
#include <iomanip>                                                    
#include <cstdio>                                                     
#include <cstdlib>                                                    
#include <ctime>                                                      


using namespace std ;

class Bonuses
{
	public:
	vector <int> getDivision ( vector <int> points )
	{
		int total = 0 ;
		int  left = 0 ; 
		vector<int> ret ;
		float per;
		multimap <int  , int > pos ;	
		for (int i = points.size() - 1 ; i>= 0 ;   i--)
		{
			total += points[i];
		}
			
		for ( int i = 0   ; i <points.size() ; i++ )
		{
			per = (float(points[i])/total)*100;
			ret.push_back(int(per));
		}


		for ( int i = points.size() -1   ; i >= 0  ; i-- )
		{
			per = (float(points[i])/total)*100;
			pos.insert(pair<int , int >(int(per) , i )) ;
			left +=per;
	
		}
		left = 100 -left;
		cout<<"Left :"<<left;
		for( multimap<int , int >::reverse_iterator ii = pos.rbegin() ; ii != pos.rend() && left; ii++ , left-- )
		{
			cout<<"Key " <<(*ii).first <<"Val " <<(*ii).second<<endl;
			int val = (*ii).second ;
			ret[val]++;
//(*ii).second++;
			
		}	
		return ret;	
	}





	
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arr0[] = {1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 6,  13,  20,  27,  34 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, getDivision(Arg0)); }
	void test_case_1() { int Arr0[] = {5,5,5,5,5,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 17,  17,  17,  17,  16,  16 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, getDivision(Arg0)); }
	void test_case_2() { int Arr0[] = {485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296,
 255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 8,  6,  4,  2,  8,  5,  5,  3,  1,  4,  5,  4,  6,  3,  5,  4,  1,  8,  1,  6,  3,  8 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, getDivision(Arg0)); }

// END CUT HERE


};


// BEGIN CUT HERE 
int main()
{
	Bonuses __test;
	__test.run_test(-1);
}
// END CUT HERE
