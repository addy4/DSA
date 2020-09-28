import java.util.* ;
import java.io.* ; 

//Code Jam 2020 Round 2
//Passes for test set 1

class pairs
{
    int source ; 
    int dest ; 
    pairs(int src, int dst)
    {
        this.source = src ; 
        this.dest = dst ; 
    }
}

public class SecurityUpdate
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in) ; 
        int Testcases = sc.nextInt() ;
        for(int iter = 0 ; iter < Testcases ; iter++)
        {
            int nodes = sc.nextInt() ; 
            int edges = sc.nextInt() ; 
            pairs[] links = new pairs[edges] ; 
            int[] time = new int[nodes] ; 
            int[][] array = new int[nodes][nodes] ; 
            for(int i = 1 ; i < nodes ; i++)
            {
                time[i] = (-1*sc.nextInt()*(edges+1)) ;  
            }
            for(int i = 0 ; i < edges ; i++)
            {
                int src = sc.nextInt() - 1; 
                int dst = sc.nextInt() - 1; 
                array[src][dst] = 1 ; 
                array[dst][src] = 1 ; 
                pairs edge = new pairs(src, dst) ; 
                links[i] = edge ; 
            }
            get_result(array,time,links,iter) ; 
        } 
        sc.close();
    }

    public static void get_result(int[][] array, int[] time, pairs[] links, int T)
    {
        for(int src = 0 ; src < time.length ; src++)
        {
            for(int dst = 0 ; dst < time.length ; dst++)
            {
                if(array[src][dst] == 1)
                {
                    int assign = time[dst] - time[src] ; 
                    if(assign == 0)
                    {
                        assign = 5 ; 
                    }
                    array[src][dst] = assign ; 
                    if(assign > 0)
                    {
                        array[dst][src] = assign ; 
                        // covered 
                    }
                }
            }
        }
        printAns(links, array,T) ; 
    }

    public static void printer(int[][] array, int length)
    {
        for(int i = 0 ; i < length ; i++)
        {
            for(int j = 0 ; j < length ; j++)
            {
                System.out.print(array[i][j] + "    ") ;
            }
            System.out.println() ;
        }
    }

    public static void printAns(pairs[] links, int[][] array, int T)
    {
        int X = 0 ; 
        System.out.print("Case #" + (T+1) + ": ") ;
        for(int iter = 0 ; iter < links.length ; iter++)
        {
            System.out.print(array[links[iter].source][links[iter].dest] + " ");
        }
        System.out.println() ; 
    }

}
