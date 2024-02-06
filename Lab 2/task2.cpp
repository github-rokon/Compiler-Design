#include <iostream>
using namespace std;

int main()
{

	char c;

	cout<<"Input : ";
	cin>>c;

	if (c =='+' || c =='-' || c =='*' || c =='/' || c =='=')
        cout<<"operator is: "<<c;
    else
        cout<<"no operator found";

	return 0;
}
