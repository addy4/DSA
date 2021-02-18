#include<iostream> 
#include<stdio.h> 
#include<string>
#include<string.h> 
#include<map>  
#include</Users/PremBhatia1/stdc.h> 
//#include<bits/stdc++.h> 

class Slot
{
    public : 
        int t_1 ; 
        int t_2 ; 
        Slot(int Time_1, int Time_2) 
        {
            t_1 = Time_1 ; t_2 = Time_2 ; 
        }
} ; 

bool operator< (Slot one, Slot two) 
{
    return (one.t_1 < two.t_1) ;    
}
 

using namespace std ; 

class Result
{
    public : 
        int check ; 
        char arr[2000] ;  
        int len ; 
        Result(int c, char array[], int L)
        {
            check = c ; 
            strcpy(arr, array) ;   
            len = L ; 
        }
};

int assign(vector<Slot>, int, char[], map<Slot,int>) ;  
bool overlap(Slot, Slot) ; 

int main()
{  
    //cout << "Check this" << endl ; 
    std::vector<Result> R ;  
    int T = 0 ;  
    cin >> T ; 
    int TC = T ; 
    while(T > 0)
    {
    T -- ; 
    std::vector<Slot> time_slots ;
    map<Slot,int> mapper ;  
    int N = 0 ; // The number of slots   
    cin >> N ;  
    for(int i = 0 ; i < N ; i++)
    {
        int t_1 = 0 ; int t_2 = 0 ; 
        cin >> t_1 ; 
        cin >> t_2 ; 
        Slot New_Slot(t_1, t_2) ; 
        mapper.insert(pair<Slot,int>(New_Slot,i)) ;  
        time_slots.push_back(New_Slot) ; 
    }
    sort(time_slots.begin(), time_slots.end()) ;
    char answer[N] ; 
    int check = assign(time_slots, N, answer, mapper) ; 
    Result res(check, answer, N) ; 
    R.push_back(res) ;         
    }
    for(int r = 0 ; r < TC ; r++)
    {
        if(R.at(r).check == 0)
        {
            cout << "Case #" << r+1 << ": " << "IMPOSSIBLE" << endl ; 
        }
        else
        {
            cout << "Case #" << r+1 << ": " ; 
            for(int i = 0 ; i < R.at(r).len ; i++)
            {
                cout << (R.at(r)).arr[i] ; 
            }
            cout << endl ; 
        }
    }
    return 1 ; 
}

int assign(vector<Slot> time_slots_fn, int N, char ans[], map<Slot,int> mapper)
{

    for(int ti = 0 ; ti < N ; ti++)
    {
        ans[ti] = '0' ; 
    }

    ans[0] = 'C' ; 
    int iter = 1 ;  

    int it = 0 ; 
    char final_arr[N] ; 

    for(auto i = time_slots_fn.begin() ; (i+1) != time_slots_fn.end() ; i++)
    {
        if(overlap(*i,*(i+1))) 
        {
            if((i+2) != time_slots_fn.end() && overlap(*(i+1),*(i+2)) && overlap(*i, *(i+2))) 
            {
                return 0 ; 
            }
            if(ans[iter-1] == 'C')
            {
                ans[iter] = 'J' ; 
            }
            else if(ans[iter-1] == 'J')
            {
                ans[iter] = 'C' ; 
            }
        }
        else
        {
            ans[iter] = ans[iter-1] ; 
        }
        iter++ ;
        //cout << " For : " << i->t_1 << " and " << i->t_2 << " parent = " << ans[it++] << endl ;  
    }

    for(auto i = time_slots_fn.begin() ; i != time_slots_fn.end() ; i++)
    {
        int id = mapper.at(*i) ; 
        final_arr[id] = ans[it++] ;  
    }
    for(int ii = 0 ; ii < N ; ii++)
    {
        ans[ii] = final_arr[ii] ; 
    }
    return 1 ; 
}

bool overlap(Slot first, Slot second)
{
    //cout << "Slot -> " << first.t_1 << " N " << first.t_2 << " and " << second.t_1 << " N " << second.t_2 ;  
    if(second.t_1 < first.t_2)
    {
        //cout << " Overlaps" << endl ; 
        return true ; 
    }
    else {
        return false ; 
    }
}
