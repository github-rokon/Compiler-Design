#include<iostream>
using namespace std;
int main(){
    int a,i;

    cout<<"Array size: ";
    cin>>a;

    float arr[a], sum=0.0,avg;

      for(i = 0; i < a; ++i)
    {
        cout <<"Enter number: ";
        cin >> arr[i];
    }

     for(i = 0; i < a; ++i)
    {
        if (arr[0]< arr[i])
        {
            arr[0]=arr[i];
        }
    }

    cout<<"Maximum :" <<arr[0]<<endl;

     for(i = 0; i < a; ++i)
    {
        if (arr[0]> arr[i])
        {
            arr[0]=arr[i];
        }
    }

    cout<<"Minimum :" <<arr[0];


    return 0;



}
