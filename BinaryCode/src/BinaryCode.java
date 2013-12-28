
public class BinaryCode {
	public String[] decode(String message) {
        String[] ret = {"NONE", "NONE"};

        int prev;
        boolean bad=false ;

        int[] P = new int[51];
        int[] Q = new int[51];

        for( int i=0; i< message.length(); i++){
            Q[i] = message.charAt(i) - '0';
        }

        for( int i=0; i<message.length(); i++){
            if( i == 0 ){
                prev = 0;
            } else{
                prev = P[i-1];
            }

            P[i+1] = Q[i] - ( prev + P[i]);
            if ( !( P[i+1] == 1 || P[i+1] == 0 ) || ( i == message.length() - 1 && P[i+1] != 0)){
                bad = true;
                break;
            }
        }

        if (!bad){
            StringBuilder buf = new StringBuilder();
            for( int i=0; i< message.length(); i++){
                buf.append(P[i]) ;
            }
            ret[0] = buf.toString();

        }

        //System.out.println("P=0");
        //System.out.println(Arrays.toString(P));

        for( int i=0; i< message.length(); i++){
            P[i] = 0;
        }


        P[0] = 1;
        bad = false;

        for( int i=0; i< message.length(); i++){
            if( i == 0 ){
                prev = 0;
            } else{
                prev = P[i-1];
            }

            P[i+1] = Q[i] - ( prev + P[i]);
            if ( !( P[i+1] == 1 || P[i+1] == 0 ) || ( i == message.length() - 1 && P[i+1] != 0)){
                bad = true;
                break;
            }

        }

        if (!bad){
            StringBuilder buf = new StringBuilder();
            for( int i=0; i< message.length(); i++){
                buf.append(P[i]) ;
            }
            ret[1] = buf.toString();

        }

        return ret;

	}
}
