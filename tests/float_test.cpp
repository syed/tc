#include<iostream>

using namespace std;

int main()
{
	float a = 1.999999 ;
	int b =static_cast<int>(a);
	cout<<"a:" << a <<"b:"<<b ;
	if ( a <  2.0 ) 
	{
		cout<<"A is less than 2"<<endl;
	}
}
