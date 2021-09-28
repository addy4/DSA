import java.util.* ;  
import java.io.* ; 
import java.math.*; 

public class PerfectSubarray
{
    public static void main(String[] args)
    {
        LinkedList<Integer> results = new LinkedList<>() ; 
        Scanner sc = new Scanner(System.in) ; 
        int T = sc.nextInt() ; 
        int N = 0 ; 
        int[] A = new int[0] ; 
        for(int iter = 0 ; iter < T ; iter++)
        {
            N = sc.nextInt() ;
            A = new int[N] ;  
            for(int i = 0 ; i < N ; i++)
            {
               A[i] = sc.nextInt() ; 
            }
        int subarrays = 0 ; 
        for(int i = 0 ; i < N ; i++)
        {
          subarrays = subarrays + checker(i, N, A) ;  
        }
        results.add(subarrays) ; 
        }
        sc.close() ; 
        for(int i = 0 ; i < results.size() ; i++)
        {
            System.out.println("Case #" + (i+1) + ": " + results.get(i)) ; 
        }
    }

    public static int checker(int iter, int N, int[] A)
    {
        int answer = 0 ; 
        int sum_val = A[iter] ; 
        if(per_square(sum_val) == 1)
        {
            answer++ ; 
        }
        for(int val = iter+1 ; val < N ; val++)
        {
            sum_val = sum_val + A[val] ; 
            if(per_square(sum_val) == 1)
            {
                answer++ ; 
            }
        }
        return answer ; 
    }

    public static int per_square(int num)
    {
        double cast = (double)num ; 
        double ans = Math.sqrt(cast) ;
        if((ans - Math.floor(ans)) == 0)
        {
            return 1 ; 
        } 
        return 0 ; 
    }

}
