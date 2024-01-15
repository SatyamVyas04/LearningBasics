#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Function 1
float fn_n(int input) {
    return input;
}

// Function 2
float fn_2_raised_to_n(int input) {
    return pow(2, input);
}

// Function 3
float fn_n_into_2_raised_to_n(int input) {
    return input * (pow(2, input));
}

// Function 4
float fn_n_raised_to_3(int input) {
    return pow(input, 3);
}

// Function 5
float fn_e_raised_to_n(int input) {
    return exp(input);
}

// Function 6
float fn_natural_log(int input) {
    return log(input);
}

// Function 7
float fn_ln_of_ln_of_n(int input) {
    return log(log(input));
}

// Function 8
float fn_logbase2_of_n(int input) {
    return log2f(input);
}

// Function 9
float fn_logbase2_twice_of_n(int input) {
    return log2f(log2f(input));
}

// Function 10
float fn_n_into_log2_n(int input) {
    return input * log2f(input);
}

int main() {
    // Argument (n) Input
    printf("\n> Enter a number: ");
    int input;
    scanf("%d", &input);

    // Function Selection Menu
    printf("\n> Choose the Function: \n\
    01. n\n\
    02. 2^n\n\
    03. n*2^n\n\
    04. n^3\n\
    05. e^n\n\
    06. ln(n)\n\
    07. ln(ln(n))\n\
    08. lg(n)\n\
    09. lg(lg(n))\n\
    10. n*lg(n)\n\
    where lg stands for log base 2\n\
    and ln denotes natural log\n\
    -> Enter your Choice: ");
    int choice;
    scanf("%d", &choice);

    // Function Calls
    float ans;
    switch (choice) {
    case 1:
        ans = fn_n(input);
        printf("\n> Answer for Function (n) : %lf", ans);
        break;
    case 2:
        ans = fn_2_raised_to_n(input);
        printf("\n> Answer for Function [2^n] : %lf", ans);
        break;
    case 3:
        ans = fn_n_into_2_raised_to_n(input);
        printf("\n> Answer for Function [n*2^n] : %lf", ans);
        break;
    case 4:
        ans = fn_n_raised_to_3(input);
        printf("\n> Answer for Function [n^3] : %lf", ans);
        break;
    case 5:
        ans = fn_e_raised_to_n(input);
        printf("\n> Answer for Function [e^n] : %lf", ans);
        break;
    case 6:
        ans = fn_natural_log(input);
        printf("\n> Answer for Function [ln(n)] : %lf", ans);
        break;
    case 7:
        ans = fn_ln_of_ln_of_n(input);
        printf("\n> Answer for Function [ln(ln(n))] : %lf", ans);
        break;
    case 8:
        ans = fn_logbase2_of_n(input);
        printf("\n> Answer for Function [lg(n)] : %lf", ans);
        break;
    case 9:
        ans = fn_logbase2_twice_of_n(input);
        printf("\n> Answer for Function [lg(lg(n))] : %lf", ans);
        break;
    case 10:
        ans = fn_n_into_log2_n(input);
        printf("\n> Answer for Function [n*lg(n)] : %lf", ans);
        break;
    default:
        printf("\n> Error!");
        break;
    }
}