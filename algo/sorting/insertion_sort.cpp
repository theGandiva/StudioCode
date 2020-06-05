#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter number of elements : ";
    cin>>n;

    int A[n];
    // Read input
    for(int i = 0; i<n; ++i)
    {
        cin>>A[i];
    }

    // Sort input
    for(int i = 1; i<n; ++i)
    {
        int key = A[i];

        for(int j = i-1; j>=0; --j)
        {
            if(A[j]>key)
            {
                // do the swap
                A[j+1] = A[j];
                A[j] = key;
            } else 
                break;
        }
    }

    // Process output
    for(int i = 0; i<n; ++i)
        cout<<A[i]<<" ";
    
    return 0;
}