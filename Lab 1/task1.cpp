#include<iostream>
using namespace std;
main(){
    int a,i;

    cout<<"Array size: ";
    cin>>a;

    float arr[a], sum=0.0,avg;

      for(i = 0; i < a; ++i)
    {
        cout <<"Enter number: ";
        cin >> arr[i];
        sum += arr[i];
    }

    avg = sum / a;
    cout << "Average = " << avg;

    return 0;



}
