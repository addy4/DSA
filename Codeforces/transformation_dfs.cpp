//Problem = https://codeforces.com/problemset/problem/1490/D 

#include<iostream> 
#include<stdio.h> 
#include<string>
#include<string.h> 
#include<map>  
#include</Users/PremBhatia1/stdc.h> 
//#include<bits/stdc++.h> 

using namespace std ; 

void solve(int **ans, int *a, int start, int end, int t, int h) ;  
int searchMaxIndex(int *a, int start, int end) ;  
void printer(int j, int **answer, int *values) ; 

int main(int argc, char** argv)
{
    int T = 0 ; 
    int i = 0 ; 
    cin >> T ; 
    int cases = T ;
    int Values[T] ;
    int **answer = new int*[T] ;    
    while(T > 0)
    {
        int h = 0 ; 
        int N = 0 ; 
        cin >> N ;
        int arr[N] ;   
        answer[i] = new int[N] ;
        Values[i] = N ;   
        for(int t = 0 ; t < N ; t++)
        {
            int d = 0 ; 
            cin >> d ; 
            arr[t] = d ;  
        }
        solve(answer, arr, 0, N, i, h) ;  
        T-- ; 
        i++ ; 
    }
    for(int u = 0 ; u < cases ; u++)
    {
       printer(u,answer,Values) ; 
    }
}

void solve(int** answer ,int *arr, int start, int end, int i, int height)
{
    if(start < end) 
    {
        int max_index = searchMaxIndex(arr, start, end) ;
        answer[i][max_index] = height ;  
        solve(answer, arr, start, max_index, i, height+1) ; 
        solve(answer, arr, max_index+1, end, i, height+1) ;  
    }  
}

int searchMaxIndex(int *arr, int start, int end)
{
    int M = -1 ;
    int index = -1 ;  
    for(int i = start ; i < end ; i++) 
    {
        if(arr[i] >= M)
        {
            M = arr[i] ; 
            index = i ; 
        }
    }
    return index ; 
}

void printer(int L, int **answer, int *values)
{
    for(int i = 0 ; i < values[L] ; i++)
    {
        cout << answer[L][i] << " " ; 
    }
    cout << endl ; 
}
