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

##############
Math Functions 
##############

Floor and Ceiling functions::
    
    #include<cmath>
    
    ceil(x);
    floor(x);
    // x can be int , float , double return value will 
    // be same as the supplied arg

   
######################
Custom sorting Sorting 
######################


Sorting of vectors can be done by using `sort` we can have custom sort function::

    typedef struct team_order
    {
        int score;
        int sixth;
        char team;
    }team_order_t;
    
    bool sort_score(team_order_t a, team_order_t b)
    {
        //here we are checking if a should come before b
        // so if a.score is less it will come first

        if ( a.score != b.score )
            return a.score < b.score;
    
        //equala
        if ( a.sixth != b.sixth )
            return a.sixth < b.sixth;
    
        //both can be num or INF
        return a.team < b.team;
    }

    //define it 
    vector< team_order_t > scores; 

    //add elements
    scores.push_back(t1);
    scores.push_back(t2);
    scores.push_back(t3);

    //call sort with custom function

    sort(scores.begin(),scores.end(),&sort_score);

