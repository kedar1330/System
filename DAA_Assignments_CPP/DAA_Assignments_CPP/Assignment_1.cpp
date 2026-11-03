
#include <bits/stdc++.h>
using namespace std;

// Recursive function
int fibRec(int n) {
    if (n < 0) {
        return -1;
    }

    if (n == 0 || n == 1) {
        return n;
    }

    return fibRec(n - 1) + fibRec(n - 2);
}

// Iterative function
int fibIter(int n) {
    if (n < 0) {
        return -1;
    }

    if (n == 0 || n == 1) {
        return n;
    }

    int a = 0;
    int b = 1;
    int c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

// Printing first n Fibonacci numbers
void printFibSeries(int n) {
    if (n < 0) {
        cout << "Enter positive number" << endl;
        return;
    }

    if (n == 0) {
        cout << endl;
        return;
    }

    int a = 0;
    int b = 1;

    cout << a << " ";

    if (n == 1) {
        cout << endl;
        return;
    }

    cout << b << " ";

    for (int i = 2; i < n; i++) {
        int c = a + b;
        cout << c << " ";

        a = b;
        b = c;
    }

    cout << endl;
}

// Main function
int main() {
    while (true) {
        cout << "\nEnter 1 to print nth Fibonacci number using recursion" << endl;
        cout << "Enter 2 to print nth Fibonacci number using iterative" << endl;
        cout << "Enter 3 to print Fibonacci series" << endl;
        cout << "Enter 4 to exit" << endl;

        int op;
        cout << "Enter option: ";
        cin >> op;

        if (op == 1) {
            int n1;
            cout << "Enter the value of n: ";
            cin >> n1;

            int res = fibRec(n1);
            cout << "Result is: " << res << endl;
        }

        else if (op == 2) {
            int n2;
            cout << "Enter the value of n: ";
            cin >> n2;

            int res = fibIter(n2);
            cout << "Result is: " << res << endl;
        }

        else if (op == 3) {
            int n3;
            cout << "Enter the value of n: ";
            cin >> n3;

            printFibSeries(n3);
        }

        else if (op == 4) {
            cout << "Program terminated." << endl;
            break;
        }

        else {
            cout << "Invalid option" << endl;
        }
    }

    return 0;
}
