#include <bits/stdc++.h>
using namespace std;
int recursive(int n)
{

    if (n == 0 or n == 1)
        return n;
    return recursive(n - 1) + recursive(n - 2);
}

int intrative(int n)
{

    if (n == 0 or n == 1)
        return n;

    int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++)
    {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}

int main()
{

    int n, choice;
    while (true)
    {

        cout << "\n \n main menu \n \t 1. recursive \n \t 2. itrative \n \t 3. exit\n \t ";
        cout << "\n \t enter your choice : ";
        cin >> choice;
        if (choice == 1)
        {

            cout<<"\n \t enter value of n : ";
            cin >> n;
            int res = recursive(n);
            cout<<"value of fibonacii of " <<n<< " is : "<<res<<endl;


        }

        else if(choice==2){
            cout<<"\n \t enter value of n : ";
            cin >> n;
            int res = intrative(n);
            cout<<res<<endl;
        }
        else if(choice==3){
            cout<<"\n \t thank you";
            exit(0);
        }
        else{
            cout<<"\n \t invalid choice";
        }
    }
}