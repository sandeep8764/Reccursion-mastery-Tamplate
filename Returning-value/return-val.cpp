// Very important for problems like factorial, sum, Fibonacci, tree problems.

#include<iostream>
using namespace std;

// Reccursive Function Declaration 

int solve(int n)
{
    // Base Case Conditon 
    if(n==0)
    {
        return 0;
        
    }
    // reccursive calling 
    int result=solve(n-1);
    
    
    // Combine the final result
    return n+result;
    
    
    
    
}

int main ()
{
    int n;
    cout<< " Enter the Value of n:";
    cin>> n;
  cout<<   solve(n);
    
    return 0;
    
}