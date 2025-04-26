// Topic 5. Calculation of finite and infinite sums and products.
#include <iostream>
#include <cmath>
#include <iomanip>

// Exercise 1. 
// For a given natural n and real x, calculate 
// the following sums
// 5)
//      1     1     1          1
// 1 + --  + -- +  -- + ... + --
//     √1    √2    √3         √n

//Code with Recurrent relations
double sumSeries(int n) {
    if (n == 1) {
        return 2.0;  // Base case
    }
    return sumSeries(n - 1) + 1.0 / sqrt(n);  // Recurrent relation
}

void task1() {
    int n;
    std::cout << "Enter n: \n";
    std::cin >> n;
    
    double s = sumSeries(n);
    
    std::cout << "S = " << s << std::endl;  // Recurrent relation
}

// Exercise 2. 
// For a given natural k and real x, calculate the next expressions
// 5)S = ∑ от n = 1 до k ((-1)^(n+1) * x^(2n-1)) / (2n - 1)!.

//Code with Recurrent relations
double calculate_series(int k, double x) {
    //Checking the correctness of the input data
    if (k <= 0) {
        std::cout << "Mistake: k must be a positive number" << std::endl;
        return 0;
    }
    
    //Initial values for n=1
    double numerator = x;    // (-1)^2 * x^1
    double denominator = 1;  // (2*1-1)! = 1!
    double result = numerator / denominator;
    
    //Calculate the remaining members of the series
    for (int i = 2; i <= k; i++) {
        //Updating the numerator and denominator
        numerator = -numerator * x * x;    // (-1)^(n+1) * x^(2n-1)
        denominator *= (2 * i - 1) * (2 * i - 2); // (2n-1)!
        
        //Adding the current member to the result
        result += numerator / denominator;
    }
    
    return result;
}

void task2() {
    int k;
    double x;
    
    std::cout << "Enter k and x: \n";
    std::cin >> k >> x;
    
    double result = calculate_series(k, x);
    
    std::cout << "S = " << result << std::endl;
    
}

// Exercise 3. Calculate the infinite sum of a series with a given precision e (e > 0).
// 5)S = ∑ от n = 1 до ∞ (5/((i+1)(i-1)))

//Code with Recurrent relations
double calculateSum(double e) 
{
    double sum = 0.0;
    double currentTerm = 5.0; //Initial value for n=1
    int n = 1;
    
    do {
        currentTerm = 5.0 / ((n + 1) * (n - 1));
        sum += currentTerm;
        n++;
        
    } while (fabs(currentTerm) > e);
    
    return sum;
}

void task3() 
{
    double e;
    std::cout << "Enter a accuracy (e > 0): \n";
    std::cin >> e;
    
    double result = calculateSum(e);
    
    std::cout << "S = " << result << std::endl; //result - inf(infinite)
}

// Exercise 4. 
// Calculate and display the value of the function F(x) on the segment [a, b] with a h = 0.1 step and an E accuracy. The results of the program are presented in the form of a table (№|Value of x|Value of F(x)|The number of summed terms n). Use a helper function when writing code.
// 5)
//              x        x ^ 2       x ^ 3      x ^ 4
// F(x) = 1 + ------- - --------- + --------- - -------  + ..., x ∈ [0.1; 0.9].
//            1 * 4      2 * 5       3 * 6      4 * 7
// F(x) = 1 + (x / (1*4)) - ((x^2) / (2*5)) + ((x^3) / (3*6)) - ((x^4) / (4*7)) + ..., x ∈ [0.1; 0.9].

//Code with Recurrent relations
//Auxiliary function for calculating the term of a series
double calculateTerm(double x, double eps, int* n) 
{
    double currentTerm = 1.0;  // current member of the series
    double sum = 1.0;          // row sum
    int i = 1;                 // row member number
    
    // Calculating the terms of the series until the specified accuracy is reached
    while (std::fabs(currentTerm) >= eps) {
        currentTerm *= -x * (2*i-1) / ((i+2)*(2*i+1));
        sum += currentTerm;
        i++;
    }
    
    *n = i;  // saving the number of members of the series
    return sum;
}

void task4() 
{
    
    const double a = 0.1;    // begin of the interval
    const double b = 0.9;    // end of the interval
    const double h = 0.1;    // step
    const double eps = 0.00001;  // accuracy
    
    std::cout << "№\tValue of x\tValue of F(x)\tThe number of summed terms n\n";
    
    int number = 1;  // row number in the table
    for (double x = a; x <= b; x += h) {
        int n;
        double result = calculateTerm(x, eps, &n);
        
        std::cout << number << "\t" 
             << std::fixed << std::setprecision(1) << x << "\t" << std::setw(16)
             << std::fixed << std::setprecision(5) << result << "\t" << std::setw(3)
             << n << "\n";
        
        number++;
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
