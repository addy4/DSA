//Google Kick Start 2020 Round D -> Problem 1 : CountDown 
// Input : No. of testcases (T) 
//         Length of Sequence, K (for Determining the K-countdown i.e k,k-1,k-2 .. 0 

import java.util.* ; 
import java.io.* ; 

public class CountDown
{
    public static void main(String[] args)
    {
        LinkedList<Integer> answers = new LinkedList<>() ; 
        Scanner sc = new Scanner(System.in) ; 
        int T = sc.nextInt() ; 
        int N = 0 ; 
        int K = 0 ; 
        int[] A = new int[N] ;  
        for(int i = 0 ; i < T ; i++)
        {
             N = sc.nextInt() ; 
             K = sc.nextInt() ;
             A = new int[N] ;  
            for(int iter = 0 ; iter < N ; iter++)
            {
                A[iter] = sc.nextInt() ; 
            } 
        int result = counts(N,K,A) ;
        answers.add(result) ;  
        }
        for(int i = 0 ; i < answers.size() ; i++)
        {
            System.out.println("Case #" + (i+1) + ": " + answers.get(i)) ;
        }
        sc.close();
        }

    public static int counts(int N, int K, int[] A)
    {
        int counters = 0 ; 
        LinkedList<Integer> indices = new LinkedList<>() ; 
        for(int iter = 0 ; iter < N ; iter++)
        {
            if(A[iter] == K)
            {
                indices.add(iter) ; 
            }
        }
        int ind  = -1 ;  
        int len = indices.size() ;
        if(K == 1)
        {
            return len ; 
        }  
        int l ; 
        for(int getter = 0 ; getter < len ; getter++)
        {
        ind = indices.get(getter) ; 
        l = ind + K ;
        ind ++ ;   
        while(ind < l && ind < N ) 
        {
            if(A[ind] != A[ind-1] - 1)
            {
                break ; 
            }
            if(A[ind] == A[ind-1] -1 && A[ind] == 1)
            {
                counters ++ ; 
                break ; 
            }
            ind++ ; 
        }
        }
        return counters ; 
    }

}
