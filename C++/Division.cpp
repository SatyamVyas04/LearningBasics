#include <bits/stdc++.h>
using namespace std;
 
string add1(string A, string M){
    int carry = 0;
    string Sum = ""; 
    for (int i = A.length() - 1; i >= 0; i--) {
        int temp = (A[i] - '0') + (M[i] - '0') + carry;
         if (temp > 1) {
            Sum += to_string(temp % 2);
            carry = 1;
        }
        else {
            Sum += to_string(temp);
            carry = 0;
        }
    }
    return string(Sum.rbegin(), Sum.rend());
}
 
string compliment1(string m){
    string M = "";
    for (int i = 0; i < m.length(); i++) {
        M += to_string((m[i] - '0' + 1) % 2);
    }
    M = add1(M, "0001");
    return M;
}
 
void nonRestoringDivision(string Q, string M, string A){
    int count = M.length();
    string comp_M = compliment1(M);
    string flag = "successful";
    cout << "\nInitial Values: A: " << A << " Q: " << Q
         << "M: " << M << endl;
    while (count) {
        cout << "\nstep: " << M.length() - count + 1;
        cout << " Left Shift and ";
        A = A.substr(1) + Q[0];
        if (flag == "successful") {
            A = add1(A, comp_M);
            cout << " Subtract: \n";
        }
        else {
            A = add1(A, M);
            cout << " Addition: \n";
        }
        cout << "A: " << A << " Q: " << Q.substr(1) << "_";
        if (A[0] == '1') {
            Q = Q.substr(1) + "0";
            cout << " -Unsuccessful";
            flag = "unsuccessful";
            cout << "\nA: " << A << " Q: " << Q
                 << " -Addition in next Step" << endl;
        }
        else {
            Q = Q.substr(1) + "1";
            cout << " Successful";
            flag = "successful";
            cout << "\nA: " << A << " Q: " << Q
                 << " -Subtraction in next step" << endl;
        }
        count--;
    }
    cout << "\nQuotient(Q): " << Q << " Remainder(A): " << A
         << endl;
}

string add(string A, string M) {
    int carry = 0;
    string Sum;
    for (int i = A.length() - 1; i >= 0; i--) {
        int temp = A[i] - '0' + M[i] - '0' + carry;
        if (temp > 1) {
            Sum.push_back('0' + (temp % 2));
            carry = 1;
        }
        else {
            Sum.push_back('0' + temp);
            carry = 0;
        }
    }
    reverse(Sum.begin(), Sum.end());
    return Sum;
}
 
string complement(string m) {
    string M;
    for (int i = 0; i < m.length(); i++) {
        M.push_back('0' + ((m[i] - '0' + 1) % 2));
    }
    M = add(M, "0001");
    return M;
}
 
void restoringDivision(string Q, string M, string A) {
    int count = M.length();
    cout << "Initial Values: A:" << A << " Q:" << Q << " M:" << M << endl;
    while (count > 0) {
        cout << "\nStep:" << (M.length() - count + 1) << endl;
        A = A.substr(1) + Q[0];
        string comp_M = complement(M);
        A = add(A, comp_M);
        cout << "Left Shift and Subtract: ";
        cout << " A:" << A << endl;
        cout << "A:" << A << " Q:" << Q.substr(1) << "_";
        if (A[0] == '1') {
            Q = Q.substr(1) + '0';
            cout << "  -Unsuccessful" << endl;
            A = add(A, M);
            cout << "A:" << A << " Q:" << Q << " -Restoration" << endl;
        }
        else {
            Q = Q.substr(1) + '1';
            cout << " Successful" << endl;
            cout << "A:" << A << " Q:" << Q << " -No Restoration" << endl;
        }
        count--;
    }
    cout << "\nQuotient(Q):" << Q << " Remainder(A):" << A << endl;
}

int main(){
    int choice;
    do {
        cout<<"\n1.Non-Restoring Division\n";
        cout<<"2.Restoring Division\n";
        cout<< "3.Exit\n";
        cout<<"\nEnter choice \n";
        cin >> choice;
        switch (choice) {
        case 1:{
            cout<<"Non-Restoring Division\n";
            string dividend;
            string divisor;
            cout<<"Enter dividend: ";
            cin>>dividend;
            cout<<"Enter divisor : ";
            cin>>divisor;
            string accumulator = string(dividend.size(), '0');
            nonRestoringDivision(dividend, divisor, accumulator);
            break;
        }
        case 2:{
            cout<<"Restoring Division\n";
            string dividend;
            string divisor;
            cout<<"Enter dividend: ";
            cin>>dividend;
            cout<<"Enter divisor : ";
            cin>>divisor;
            string accumulator= string(dividend.length(), '0');
            restoringDivision(dividend, divisor, accumulator);
            break;}
        case 3:{
            cout<< "\n Exiting...."<< endl;
            break;
            }
        default:
            cout << "\nInvalid choice!\n";}
    }while (choice != 3);}
