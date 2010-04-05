#include <string.h>
#include <iostream>
#include <map>
#include <utility>
 
using namespace std;
 
int main()
{
   map<int, string> Employees;
 
   // 1) Assignment using array index notation
   Employees[5234] = "1";
   Employees[3374] = "Charlie M.";
   Employees[1923] = "David D.";
   Employees[7582] = "John A.";
   Employees[5328] = "Peter Q.";
 
   cout << "Employees[3374]=" << Employees[3374] << endl << endl;
 
   cout << "Map size: " << Employees.size() << endl;
 
   for( map<int,string>::iterator ii=Employees.begin(); ii!=Employees.end(); ++ii)
   {
       cout << (*ii).first << ": " << (*ii).second << endl;
   }
   multimap < int , int > pos ;

   pos.insert(pair<int ,int >( 32 , 0 ));
   pos.insert(pair<int ,int >( 11  , 1 ));
   pos.insert(pair<int ,int >( 22 , 2 ));
   pos.insert(pair<int ,int >( 32 , 3 ));

   for( multimap<int,int >::iterator ii=pos.begin(); ii!=pos.end(); ++ii)
   {
       cout << (*ii).first << ": " << (*ii).second << endl;
   }

}
