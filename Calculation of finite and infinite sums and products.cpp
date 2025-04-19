// Topic 5. Calculation of finite and infinite sums and products.
#include <iostream>
#include <cmath>
#include <iomanip>

//Exercise 1. For a given natural n and real x, calculate the following sums
//5)
//      1     1     1          1
// 1 + --  + -- +  -- + ... + --
//     √1    √2    √3         √n


void task1()
{
    int n;
    std::cout << "Enter n: ";
    std::cin >> n;

    if (n <= 0)
    {
        std::cout << "\nThe number must be natural(greater 0)\n";
    }

    double sum = 1.0;
    for (int i = 1; i <= n; ++i) {
        sum += 1.0 / sqrt(i); //calculating the sum
    }

    std::cout << std::fixed << std::setprecision(4); //reducing the sum to ten-thousandths
    std::cout << "\nSum = " << sum << "\n";
}

//Exercise 2. For a given natural k and real x, calculate the following expressions
//5)S = ∑ от n = 1 до k ((-1)^(n+1) * x^(2n-1)) / (2n - 1)!.

long double factorial(int n)
{
    if (n == 0) {
        return 1;
    }
    long double result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

void task2()
{
    int k;
    double x;

    std::cout << "Enter k: ";
    std::cin >> k;
    std::cout << "Enter x: ";
    std::cin >> x;

    if (k <= 0) {
        std::cout << "\nThe number must be natural (greater 0)\n";
    }

    long double s = 0;
    for (int n = 1; n <= k; ++n) {
        
        //calculating the result of the S
        long double numerator = pow(-1, n + 1) * pow(x, 2 * n - 1);
        long double denominator = factorial(2 * n - 1);
        s += numerator / denominator;
    }

    std::cout << std::fixed << std::setprecision(3); //reducuing sum to thousandths
    std::cout << "\nResult S = " << s << "\n";
}

// Exercise 3. Calculate the infinite sum of a series with a given precision e (e > 0).
// 5)S = ∑ от n = 1 до ∞ (5/((i+1)(i-1)))

double calculateSum(double epsilon) 
{
    double sum = 0.0;
    double currentTerm = 5.0; //Initial value for n=1
    int n = 1;
    
    //Calculate the sum as long as the current term is greater than the specified accuracy
    while (std::fabs(currentTerm) > epsilon) {
        sum += currentTerm;
        n++;
        
        //Calculate the next term of the series
        currentTerm = 5.0 / ((n+1)*(n-1));
    }
    
    return sum;
}
void task3()
{
    //declaring and inputing an accuracy
    double epsilon;
    std::cout << "Enter an accuracy (e > 0): ";
    std::cin >> epsilon;
    
    double result = calculateSum(epsilon);
    
    std::cout << "Sum of a row with precision " << epsilon << " = " << result << std::endl;
}

// Exercise 4. 
// Calculate and display the value of the function F(x) on the segment [a, b] with 
// a h = 0.1 step and an E accuracy. 
// The results of the program are presented in the form of a table 
// (№|Value of x|Value of F(x)|The number of summed terms n). Use a helper function when writing code.
//
//5)
//              x        x ^ 2       x ^ 3      x ^ 4
//F(x) = 1 + ------- - --------- + --------- - -------  + ..., x ∈ [0.1; 0.9].
//            1 * 4      2 * 5       3 * 6      4 * 7
//
//F(x) = 1 + (x / (1*4)) - ((x^2) / (2*5)) + ((x^3) / (3*6)) - ((x^4) / (4*7)) + ..., x ∈ [0.1; 0.9].

//Auxiliary function for calculating the term of a series
double calculateTerm(double x, int n) {
    return pow(-1, n) * pow(x, n) / (n * (n + 3));
}

void task4() {
    double a = 0.1;  // begin of a segment
    double b = 0.9;  // end of a segment 
    double h = 0.1;  // step
    double e = 0.0001;  //accuracy

    std::cout << "\nN\t|Value x\t|Value of the F(x)\t|Number of summed terms n\n";

    for (double x = a; x <= b + h / 2; x += h) {
        double sum = 1.0; //initial value of the amount
        int n = 1; //row member number
        double term = calculateTerm(x, n); //current member of the series

        //Summing the terms of a series to achieve accuracy
        while (std::abs(term) > e) {
            sum += term;
            n++;
            term = calculateTerm(x, n);
        }

        std::cout << std::setw(2) << std::setprecision(0) << (x - a) / h + 1 << "\t" //reducing the value to an integer
            << std::setw(10) << std::setprecision(1) << x << "\t" //reducing the value to tenths
            << std::setw(15) << std::setprecision(3) << sum << "\t" //reducing the value to thousandths
            << std::setw(15) << n << "\n";
    }
}

int main()
{

    task1();
    task2();
    task3();
    task4();

    return 0;
}
