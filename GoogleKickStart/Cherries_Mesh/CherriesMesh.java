import java.util.* ;
import java.io.* ; 

//Round E Google Kickstart 2019 

public class CherriesMesh
{
    public static int NR = 0 ; 
    public static int nodes = 0 ; 
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in) ; 
        int tc = sc.nextInt() ;
        int init = 0 ; 
        int[] results = new int[tc] ; 
        while(init < tc)
        {
            LinkedList <Integer> comp_count = new LinkedList<>() ; 
            int total = 0 ; 
            int cherries = sc.nextInt() ;  
            int[] covered = new int[cherries] ; 
            // declare an array for mapping 
            int[][] arr = new int[cherries][cherries] ; 
            int strands = sc.nextInt() ;
            for(int k = 0 ; k < strands ; k++)
            {
                int src = sc.nextInt() - 1 ;
                int dest = sc.nextInt() - 1 ; 
                arr[src][dest] = arr[dest][src] = 1 ;
            }
            comp_count = components(arr,covered) ; 
            for(int c = 0 ; c < NR ; c++)
            {
                total = total + comp_count.get(c) ; 
            }
            total = total + (NR-1)*2 ; 
            results[init] = total ; 
            NR = 0 ; 
            init++ ; 
        }
        for(int w = 0 ; w < tc ; w++)
        {
            System.out.println("Case #" + (w+1) + ": " + results[w]); 
        }
        sc.close();
    }

    public static LinkedList <Integer> components(int[][] arr, int[] covered)
    {
        LinkedList <Integer> comp_count = new LinkedList<>() ; 
        int[] visited = new int[covered.length] ; 
        for(int ini = 0 ; ini < covered.length ; ini ++)
        {
            if(covered[ini] == 0)
            {
                nodes ++ ; 
                NR++ ; 
               int x = dfs(ini,arr,covered,visited) ; 
               comp_count.add(x-1) ; 
               nodes = 0 ; 
            }

        }
        return comp_count ; 
    }

    public static int dfs(int src , int[][] arr, int[] covered, int[] visited)
    { 
        int origin = src ; 
        visited[src] = 1 ; 
        covered[src] = 1 ;
        for(int i = 0 ; i < covered.length ; i++)
        {
            if(arr[origin][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1 ;
                covered[i] = 1 ;
                nodes ++  ; 
                dfs(i, arr, covered, visited);
            }
        }
      return nodes ; 
    } 

}
