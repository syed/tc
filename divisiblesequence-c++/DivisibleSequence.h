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
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define ISEQ(c) (c).begin(), (c).end()

#define MOD 1000000009

/* We get this using the fermat's little theorem
 * which says that if p is a prime number and x is 
 * some number which is not divisible by p then
 *          
 *          x^(p-1) == 1 mod p
 * we can write this as
 *          x*x(p-2) == 1 mod p 
 * now here we can say x(p-2) is the multiplicative
 * inverse of x. So lets say now we want to find out
 * (a/b)mod p , we have to first find multiplicative
 * inverse of b and then multiply it by a. 
 * we also know that
 *          (x1*x2) mod p = (x1 mod p)*(x2 mod p)
 */
long long modPow(long long n, long long k)
{
    long long res=1,a=n;
    while( k )
    {
        if ( k %2 != 0 )
        {
            res = (res * a) % MOD ;
        }

        a = ((a * a )% MOD) ;
        k /= 2;
    }
    return (res) % MOD;
}

long long modDiv(long long a, long long b)
{
    return a*modPow(b,MOD-2) % MOD;
}

long long nCr(long long n, long long r)
{
	long res=1;
        long k=1;
	if ( r > n)
		return 0;
	if ( r > n-r)
		r = n-r;

	for(long long i=0;i<r;i++)
        {
		res = (((n-i) % MOD) * (res % MOD)) % MOD;
                k = (((i+1) % MOD) * ( k % MOD )) % MOD;
        }

	return modDiv(res,k) % MOD;
}

class DivisibleSequence {

    public: int count(int N, int H) {
                vector<long long> factors;
                long long ret=1;
                for ( int i = 2 ; i <= N ; i++)
                {
                    int count = 0;
                    while( N % i == 0 )
                    {
                        count++;
                        N = N/i;
                    }
                    if ( count )
                    {
                        //printf("fator %d count %d\n",i,count);
                        factors.push_back(count);
                    }
                }

                FOR(i, 0, factors.size())
                {
                    //printf("n %lld r  = %d \n",H+factors[i]-1,factors[i] );
                    ret  = (ret*nCr(H+factors[i]-1, factors[i])) % MOD;
                }

                return int(ret%MOD);
            }
};
