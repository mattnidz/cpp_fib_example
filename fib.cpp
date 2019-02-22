#include <iostream>
#include <cstring>

using namespace std;


int main(int argc,char* argv[]) {

    int n; // nth terms
    int t1 = 0; // first term
    int t2 = 1; //second term
    int the_count = 0; // not dracula

    n = atoi(argv[1]);

    if(n <= 0){
        cout<<"Please enter a positive integer"<<endl;
    }

    else if(n == 1){
        cout<<"Fibonacci sequence: "<<n<<endl;
        cout<<t1<<endl;
    }

    else{
         cout<<"Fibonacci sequence: "<<n<<endl;
         while(the_count<n){
            int nth = t1 + t2;
            cout<<t1<<',';
            t1 = t2;
            t2 = nth;
            the_count++;

         }

    }


    return 0;
}
