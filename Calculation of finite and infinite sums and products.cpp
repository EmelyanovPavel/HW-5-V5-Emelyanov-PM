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

void task1()
{
    
    int n; 
    double s = 0.0;
    
    std::cout << "Enter n: \n";
    std::cin >> n;
    
    if (n == 1) 
    {
        s += 2.0;  // Base case
        
    } else {
        
        s = (n - 1) + 1.0 / sqrt(n);
        
    } 
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "S = " << s << std::endl;
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
//
//Auxiliary function for calculating the term of a series
 double calculateF(double x, double eps, int* n) 
 {
     double result = 1.0; // The initial value (the first term of the series = 1)
     double term = 1.0;   // Сurrent member of the series
     int i = 1;           // Row member number

     //Calculating a row sum with given accuracy
     do {
         term = pow(-1, i - 1) * pow(x, i) / (i * (i + 3)); //formation of the next term
         result += term; //adding a summand to sum
         i++;
     } while (fabs(term) >= eps); //The specified degree of accuracy has not been reached yet
     
     *n = i - 1; // Writing a terms number
     return result; //return the result with the value of the function 
 }

void task4()
{
    double a = 0.1;  // begin of a segment
    double b = 0.9;  // end of a segment 
    double h = 0.1;  // step
    double eps = 0.0001;  //accuracy

    // displaying the table header
    std::cout << "N" << "\tx value" << "\tF(x) value" << "\tNumber summed terms" << std::endl;

    int count = 1; //Rows counter
    for (double x = a; x <= b; x += h) 
    {
        int n;
        double result = calculateF(x, eps, &n); //calling an auxiliary function

        //displaying the received data on the screen
        std::cout << count << "\t" << std::fixed << std::setprecision(1) << x << "\t" << std::fixed << std::setprecision(6) << result << "\t" << n << std::endl;

        count++;
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
