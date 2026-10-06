//  basic Reccursion Tamplate 

#include<iostream>
using namespace std;

// Helper function 

// Here We definne the Reccursive Function 

void solve(int n)
{
    // Base Case Condition 
    
    if(n==0)
    {
        return ;
    }
    
    cout<< n " ";
    solve(n-1); // reccursive Calling of Function  
}

int main ()
{
    int a;
    cout<< " Enter the value of s:";
    cin>> a;
    solve(a);
    
    return 0;
    
}