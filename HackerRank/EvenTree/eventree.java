import java.util.* ; 
import java.io.* ; 

//Even Tree Problem 

public class eventree
{
    public static int NR = 0 ; 
    public static void main(String[] args)
    {    
        Scanner sc = new Scanner(System.in) ; 
        int N = sc.nextInt() ; 
        int K = sc.nextInt() ;
        int src ; int des ; 
        int[][] A = new int[N][N] ;   
        for(int iter = 0 ; iter < K ; iter++)
        {
            src = sc.nextInt() ; 
            des = sc.nextInt() ;
            src-- ; des -- ;  
            A[src][des] = 1 ; 
            A[des][src] = 1 ; 
        }  
        sc.close(); 
        for(int i  = 0 ; i < N ; i++)
        {
            for(int j = 0 ; j < N ; j++)
            {  
                if(i == j)
                {
                    A[i][j] = 0 ; 
                } 
            }
        }
        int[] ans = new int[N] ; 
        int[] v = new int[N] ; 
        int func = summ(0,A,ans,v,N) ; 
        System.out.println(NR-1) ; 
    }

    public static int summ(int iter, int[][] A, int[] ans, int[] v, int len)
    {
        ans[iter] = 1 ; 
        int i = iter ; 
        int j = 0 ; 
        v[i] = 1 ; 
        while(j < len)
        {
            if(A[i][j] == 1 && v[j] != 1)
            {
                v[j] = 1 ; 
                ans[i] = ans[i] + summ(j,A,ans,v,len) ;  
            }  
            j++ ; 
        }
        if(ans[i] % 2 == 0)
                {
                    NR++ ; 
                }
        return ans[iter] ; 
        
    }

}
