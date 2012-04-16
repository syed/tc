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
 


