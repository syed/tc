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

// 1 3 5 7 4 6 4 2  - yes
using namespace std;


class FoxSequence
{ 
public: 
string isValid(vector <int> seq) 
{ 
	if( seq.size() < 5 ) 
		return  "NO";
	int i = 0 , j=1;
	int diff = seq[j]-seq[i];
first :	
	if( diff < 1  ) 
		return "NO";
	while( seq[j] - seq[i] == diff )
	{
		i++;j++;
	}
	//cout<<"First : i "<< seq[i] <<" j "<<seq[j]<<endl;
	if((seq[i] > seq[j]) && j<seq.size()-1)
		goto second;
	else 	
		return "NO";
second:
	diff = seq[j] - seq[i];
	if ( diff >=0 ) 
		return "NO";
	while( seq[j] - seq[i] == diff )
	{
		i++;j++;
	}
	//cout<<"Second : i "<< seq[i] <<" j "<<seq[j]<<endl;
	if(seq[i] == seq[j] && j<seq.size()-1)
		goto third;
	if(seq[i] < seq[j] && j<seq.size()-1 )
		goto fourth;
	else
		return "NO";
third:
	while(seq[i] == seq[j])
	{
		i++;j++;
	}
	//	cout<<"third : i "<< seq[i] <<" j "<<seq[j]<<endl;
	if(seq[i]<seq[j] && j<seq.size()-1 )
		goto fourth;
	else 
		return "NO";

fourth:
	diff = seq[j] - seq[i];
	if ( diff <1 ) 
		return "NO";
	while( seq[j] - seq[i] == diff )
	{
		i++;j++;
	}
	//	cout<<"forth : i "<< seq[i] <<" j "<<seq[j]<<endl;
	if( seq[i] >  seq[j] && j<seq.size())
		goto fifth;
	else
		return "NO";
fifth:

	diff = seq[j] - seq[i];
	if ( diff >0 ) 
		return "NO";
	while ((seq[j] - seq[i] == diff)&&j<seq.size()) 
	{
		i++;j++;
	}
	//	cout<<"fifth : i "<< seq[i] <<" j "<<seq[j]<<endl;
	//	cout<<"size "<<seq.size();
	if ( j == seq.size() )
		return "YES";
	else
		return "NO";



} 


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,3,5,7,5,3,1,1,1,3,5,7,5,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, isValid(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,3,4,5,4,3,2,2,2,3,4,5,6,4}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, isValid(Arg0)); }
	void test_case_2() { int Arr0[] = {3,6,9,1,9,5,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(2, Arg1, isValid(Arg0)); }
	void test_case_3() { int Arr0[] = {1,2,3,2,1,2,3,2,1,2,3,2,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, isValid(Arg0)); }
	void test_case_4() { int Arr0[] = {1,3,4,3,1,1,1,1,3,4,3,1}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(4, Arg1, isValid(Arg0)); }
	void test_case_5() { int Arr0[] = {6,1,6}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(5, Arg1, isValid(Arg0)); }

// END CUT HERE
 
	   }; 

    // BEGIN CUT HERE 
    int main()
        {
        FoxSequence ___test; 
	vector<int> seq;
	seq.push_back(1);
	seq.push_back(3);
	seq.push_back(5);
	seq.push_back(7);
	seq.push_back(4);
	seq.push_back(6);
	seq.push_back(4);
	seq.push_back(2);
	int vals[] = {264, 295, 326, 357, 388, 419, 450, 481, 512, 543, 574, 605, 636, 667, 698, 729, 760, 791, 822, 795, 768, 741, 714, 687, 660, 633, 606, 579, 552, 525, 525, 525, 525, 525, 525, 525, 525, 525, 525, 525, 525, 525, 568, 611, 654, 697, 740, 783, 826, 869};
	vector<int> seq2(vals,vals+sizeof(vals)/sizeof(int));

	cout << ___test.isValid(seq2);

        ___test.run_test(-1); 
        }
    // END CUT HERE 
