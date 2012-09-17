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

#define IS_EMPTY_LINE(s) (s.find_first_not_of(' ') == s.npos)

string find_last_word(string s)
{
	int i  = s.size();
	string word;
	while( i && s[i-1] ==  ' ' )
		i--;

	while( i && s[i-1] != ' ')
	{
		word.push_back(s[i-1]);
		i--;
	}

	return string(word.rbegin(),word.rend());
}

#define VOWEL(c,index,sz) (c=='a' || c=='e'|| c=='i'|| c=='o'|| c=='u'|| (c=='y' && index>0 && index < (sz-1)))

bool check_if_rhyme(string a, string b)
{
	int sz = (a.size()<b.size())?a.size():b.size();

	//cout<<"a: " <<a <<" b: "<<b<<endl;
	//if ( a == "scheme" && b == "kreme")
	//	cout<<"here"<<endl;
	a = string(a.rbegin(), a.rend());
	b = string(b.rbegin(), b.rend());
	string sub;
	int index = 0;
	for( index = 0; index<sz;index++)
	{
		if ( a[index] != b[index] )
			break;
		sub.push_back(a[index]);
	}
	sub =  string(sub.rbegin(),sub.rend());

	int n=0;
	bool got_vowel = false;
	FOR(i,0,sub.size())
	{
		if ( VOWEL(sub[i] , i, sub.size()))
		{
			got_vowel = true;
			break;
		}
		n++;
	}
	if ( ! got_vowel )//reached end and didn't get vowel
		return false;

	sub = string( sub.begin() + n , sub.end());



	index =  sub.size();
	if (((sub.size() != a.size()) && (VOWEL(a[index],index,a.size())) ))
		return false;

	if (((sub.size() != b.size()) &&  (VOWEL(b[index],index,b.size())) ) )
		return false;

	//cout<<" SUB: "<<sub<<endl;

	return true;
}

class Poetry {

	public: string rhymeScheme(vector<string> poem) {
		vector<string> lines;
		string ret;
		char cur_rhyme_char = 'a';
		char rhymes[poem.size()+1];

		FOR(i,0,poem.size())
		{
			rhymes[i] = '\0';
			transform(poem[i].begin(),poem[i].end(),poem[i].begin(),::tolower);
		}
		rhymes[poem.size()] = '\0';

		FOR(i,0,poem.size())
		{
			string s=poem[i];

			string last_word_a = find_last_word(s);

			if (!IS_EMPTY_LINE(s) && !rhymes[i])
			{
				//cout<<s<<endl;
				rhymes[i] = cur_rhyme_char;

				FOR(j,i+1,poem.size())
				{
					if (!IS_EMPTY_LINE(s) && !rhymes[j]) // already rhymed
					{
						string last_word_b = find_last_word(poem[j]);
						if (check_if_rhyme(last_word_a,last_word_b))
							rhymes[j] = cur_rhyme_char;
					}
				}
				{
					if ( cur_rhyme_char == 'z')
						cur_rhyme_char = 'A';
					else
						cur_rhyme_char++;
				}

			}
			else if ( IS_EMPTY_LINE(s) )
			{
				//cout<<"empty line i:"<<i<<endl;
				rhymes[i] = ' ';
			}
		}


		return string(rhymes);
	}

};
