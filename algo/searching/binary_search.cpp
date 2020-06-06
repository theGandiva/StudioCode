#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Number of elements : ";
    cin>>n;

    int sA[n];
    for(int i = 0; i<n; ++i)
        cin>>sA[i]; // read sorted array

    int key;
    cout<<"Enter key to search : ";
    cin>>key;

    int r = n, l = 0;
    int i = (r-l)/2;
    while (i>0 && i<n)
    {
        if(sA[i] == key)
        {
            cout<<"Its at "<<i<<endl;
            break;
        } else if(sA[i]>key)
        {
            i = 3*i/4;
        } else
        {
            i = i/4;
        }
        
    }
}