import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Lottery {

    private long nPr(int n, int r){
        long ret = 1;
        while(r != 0){
            ret = ret*n;
            n--;
            r--;
        }
        return ret;
    }

    private long nCr(int n, int r){
        if( n-r < r) {
            r = n-r;
        }
        return nPr(n,r)/fact(r);
    }

    private long fact(int n){
       long ret = 1;
       while(n != 0) {
           ret = ret*n;
           n--;
       }
       return ret;
    }


	public String[] sortByOdds(String[] rules) {


        List<Score> vals = new ArrayList<Score>();

        Pattern p = Pattern.compile("(.*?):\\s(\\d+)\\s(\\d+)\\s(\\w)\\s(\\w)");
        for( String r : rules) {

            Matcher m  = p.matcher(r);
            m.find();
            String name = (m.group(1));
            int digits = Integer.parseInt((m.group(2)));
            int blanks = Integer.parseInt((m.group(3)));
            String sorted = (m.group(4));
            String unique = (m.group(5));

            if( sorted.equals("F") && unique.equals("F"))
                vals.add(new Score(name, (long) Math.pow(digits, blanks)));
            else if (sorted.equals("T") && unique.equals("T"))
                vals.add(new Score(name, nCr(digits, blanks)));
            else if (sorted.equals("F") && unique.equals("T"))
                vals.add(new Score(name, nPr(digits, blanks)));
            else if (sorted.equals("T") && unique.equals("F"))
                vals.add(new Score(name, nCr( digits+blanks-1, blanks)));
            else
                System.out.println("ERROR");
        }

        Collections.sort(vals, new Comparator<Score>() {
            @Override
            public int compare(Score score1, Score score2) {
                if ( score1.ways == score2.ways ) {
                    return (score1.name.compareTo(score2.name));
                }
                return (score1.ways > score2.ways)? 1 : -1;
            }
        });

        /*for( Score s : vals)
            System.out.println(s.name + " : " + s.ways);
        System.out.println("-----");*/

        String[] ret =  new String[vals.size()];
        int i = 0;
        for( Score s : vals){
            ret[i] = s.name;
            i++;
        }

		return ret;
	}

    public class Score {
        public String name;
        public long ways;

        public Score(String name, long ways){
            this.name = name;
            this.ways = ways;
        }
    }
}
