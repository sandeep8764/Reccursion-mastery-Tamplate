
#include<iostream>
using namespace std;

// Reccursive Function Declaration 

void solve(int i ,int n)
{
    // Base Case Conditon 
    if(i>n)
    {
        return ;
        
    }
    cout<< i << " "; // Work is performed 
    
    // Reccirsive Function 
    solve(i+1,n);
    
    
    
}

int main ()
{
    int n;
    cout<< " Enter the Value of n:";
    cin>> n;
    solve(0,5);
    
    return 0;
    
}