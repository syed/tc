=====
Notes
=====

#####################################
Clear `istringstream` & ostringstream
#####################################

To clear istringseream::

    istringstream in;
    in.str(row);
    in.clear()
    in.str(row2);

To clear ostringstream::

    ostringstream out;
    out<<v1<<v2<<v3;
    out.str()
    //clear
    out.str('');
    out<<v1<<v2<<v3;
 

##############################
Find min and max in vector etc 
##############################

use `min_element` and `max_element` ::
    
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(0);

    int min = min_element( v.begin(),v.end())
    int max = max_element( v.begin(),v.end())

