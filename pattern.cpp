#include "bits/stdc++.h"
using namespace std;
// Right Half Pyramid:
void pattern_1(int Size){
    // for(int i = 0 ; i < Size; i++){
    //     for(int j = 0; j <= i; j++){
    //         cout << "* ";
    //     }
    //     cout<<endl;
    // } 
//  use while loop:
    int i=0;
    while(i<Size){
        int j=0;
        while(j<=i){
            cout << "* ";
            j++;
        }
        i++;
        cout<<endl;
    }
}

void pattern_2(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            cout << "_"; 
        }
        for(int j=0; j<=i; j++){
            cout << "* ";
        }
        cout << endl;
    }
}
// Inverted Right Half Pyramid:
void pattern_3(int n){
    for(int i=0;i<n;i++){
        for(int j=n-i;j>0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
}

// Inverted Left Half Pyramid
void pattern_4(int n){
    for(int i=0;i<n;i++){
        for(int j=i;j>0;j--){
            cout<<"_";
        }
        for(int j=n-i;j>0;j--){
            cout<<"*";
        }
        cout<<endl;
    }
}

// Left Half Pyramid
void pattern_5(int n){
    cout<<"pattern_5:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            cout<<"_";
        }
        for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

// Full Pyramid:
void pattern_6(int n){
    cout<<"Full Pyramid Pattern:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1-i;j++){
            cout<<"_";
        }
        for(int j=0;j<(2*i+1);j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
// Inverted Full Pyramid Pattern:
void pattern_7(int n){
    cout<<"Inverted Full Pyramid Pattern:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<"_";
        }
        for(int j=0;j<(2*(n-i)-1);j++){
            cout<<"*";
        }
        cout<<endl;
    }
}

// Half Diamond Star:
void pattern_8(int n){
    cout<<"Half Diamond Star Pattern:"<<endl;
    for(int i=0;i<2*n-1;i++){
        if (i<n){
            for(int j=0;j<=i;j++){
                cout<<"*";
            }
        } else{
            for(int j=0;j<(2*n-i-1);j++){
                cout<<"*";
            }
        }
        cout<<endl;
    }
}
// Diamond Shape Pattern:
void pattern_9(int n){
    cout<<"Diamond Shape:"<<endl;
    for(int i=0;i<2*n;i++){
        int spaces = (i<n) ? (n-1-i) : (i-n);
        for(int j=0;j<spaces;j++){
            cout<<"_";
        }

        int stars = (i<n) ? (i+1) : (2*n-i);
        for(int j=0;j<stars;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
//Alphabet “A” using Stars pattern:
void pattern_10(int n){
    cout<<"Alphabet A using Stars pattern: "<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n / 2; j++) {
            if (i==0 || j==0 || j==n/2 || i==n/2){
                if(i==0  && (j==0 || j==n/2))
                cout<<" ";
                else
                cout<<"*";
            } else
                cout << " ";
        }

        cout << '\n';
    }
}

// Solid and Hollow Square:
void pattern_11(int n){
    for (int i=1; i<=n; i++)
    {
        // Print stars for each solid rows
        if (i==1 || i==n)
            for (int j=1; j<=n; j++)
                cout << "*";

        // stars for hollow rows
        else
            for (int j=1; j<=n; j++)
                if (j==1 || j==n)
                    cout << "*";
                else
                    cout << " ";

        // Move to the next line/row
        cout << "\n";
    }
}

// Hollow Rectangle or Square Star:
void pattern_12(int n){
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = 1; j <= n; j++) 
        { 
            if (i == 1 || i == n || 
                j == 1 || j == n)         
                cout << "*";             
            else
                cout << " ";
        } 
        cout << endl;
    } 
}

//Stair Case Patterns:
void pattern_13(int n){
    for(int i = 0; i <= n; i++){

        int k = (i % 2 != 0) ? i + 1 : i;

        for (int j = 0; j < k; j++)
            cout << " * ";
        cout << endl;
    }
}
int main(){
    int Size;
    cout << "Enter size: ";
    cin >> Size;
    
    // pattern_1(Size);
    // pattern_2(Size);
    // pattern_3(Size);
    // pattern_4(Size);
    // pattern_5(Size);
    // pattern_6(Size);
    // pattern_7(Size);
    // pattern_8(Size);
    // pattern_9(Size);
    // pattern_10(Size);
    // pattern_11(Size);
    // pattern_12(Size);
    pattern_13(Size);
    return 0;
}