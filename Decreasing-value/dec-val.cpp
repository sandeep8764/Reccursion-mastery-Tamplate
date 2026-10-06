
#include<iostream>
using namespace std;

// Reccursive Function Declaration 

void solve(int n)
{
    // Base Case Conditon 
    if(n==0)
    {
        return ;
        
    }
    cout<< n << " "; // Work is performed 
    
    // Reccirsive Function 
    solve(n-1);
    
    
    
}

int main ()
{
    int n;
    cout<< " Enter the Value of n:";
    cin>> n;
    solve(n);
    
    return 0;
    
}