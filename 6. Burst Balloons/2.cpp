#include <iostream> 
using namespace std; 
  
// recursive function to generate scores 
int getmaxscore(int arr[], int l, int r, int n) 
{ 
    int mscore = 0; 
    for (int i = l + 1; i < r; i++) { 
  
        // to permute through all cases 
        int cs = getmaxscore(arr, l, i, n) + getmaxscore(arr, i, r, n); 
        if (l == 0 && r == n) 
            cs = cs + arr[i]; 
        else
            cs = cs + (arr[l] * arr[r]); 
  
        if (cs > mscore) 
            mscore = cs; 
    } 
    return mscore; 
} 
  
int main() // driver function 
{ 
    int n;
    cin>>n;
    int arr[15];  
      arr[0]=1 && arr[n+1]=1 
      cin>>n; 
      for(int i=1;i<=n;i++) 
         cin>>arr[i]; 
  
    cout << getmaxscore(arr, 0, n + 1, n + 1) << "\n"; 
  
    return 0; 
} 
