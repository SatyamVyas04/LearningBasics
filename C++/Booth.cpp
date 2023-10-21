#include <bitset>
#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int n1, n2;
    cout << "---Booth's Algorithm for Multiplying 2 numbers---" << endl;
    cout << "Enter 2 numbers: ";
    cin >> n1 >> n2;
    int count = max(log2(abs(n1)) + 1, log2(abs(n2)) + 1) + 1;
    int Qe = 0;
    bitset<5> A = 0, M = n1, Q = n2, Mc = -1 * n1;
    int i = count;
    cout << left << setw(10) << "A" << setw(10) << "Q" << setw(10) << "Q-1" << setw(10) << "Count"
         << "Remark" << endl;
    cout << left << setw(10) << A << setw(10) << Q << setw(10) << Qe << setw(10) << i << "Initial" << endl;
    while (i--) {
        cout << left << setw(10) << A << setw(10) << Q << setw(10) << Qe << setw(10) << i + 1 << "Current" << endl;
        if (Q[0] == 0 && Qe == 1) {
            int carry = 0;
            for (int j = 0; j < count; j++) {
                int sum = A[j] + M[j] + carry;
                if (sum < 2) {
                    if (sum == 0)
                        A[j] = 0;
                    else
                        A[j] = 1;
                    carry = 0;
                } else {
                    if (sum == 2)
                        A[j] = 0;
                    else
                        A[j] = 1;
                    carry = 1;
                }
            }
            cout << left << setw(10) << A << setw(10) << Q << setw(10) << Qe << setw(10) << i + 1 << "A = A+M" << endl;
        } else if (Q[0] == 1 && Qe == 0) {
            int carry = 0;
            for (int j = 0; j < count; j++) {
                int sum = A[j] + Mc[j] + carry;
                if (sum < 2) {
                    if (sum == 0)
                        A[j] = 0;
                    else
                        A[j] = 1;
                    carry = 0;
                } else {
                    if (sum == 2)
                        A[j] = 0;
                    else
                        A[j] = 1;
                    carry = 1;
                }
            }
            cout << left << setw(10) << A << setw(10) << Q << setw(10) << Qe << setw(10) << i + 1 << "A = A-M" << endl;
        }
        Qe = Q[0];
        Q = Q >> 1;
        Q[count - 1] = A[0];
        int temp = A[count - 1];
        A = A >> 1;
        A[count - 1] = temp;
        cout << left << setw(10) << A << setw(10) << Q << setw(10) << Qe << setw(10) << i << "ASR" << endl;
    }

    cout << left << setw(10) << A << setw(10) << Q << setw(10) << Qe << setw(10) << '0' << "Final" << endl;
    cout << "\nAnswer: ";
    for (int i = count - 1; i >= 0; i--) {
        cout << A[i];
    }
    for (int i = count - 1; i >= 0; i--) {
        cout << Q[i];
    }
    cout << endl;
    return 0;
}
