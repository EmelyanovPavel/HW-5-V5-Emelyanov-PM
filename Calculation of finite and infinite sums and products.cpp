////Topic 5. Calculation of finite and infinite sums and products.
// 
////Exercise 1.
////5)
////      1     1     1          1
//// 1 + --  + -- +  -- + ... + --
////     √1    √2    √3         √n
// 
//#include <iostream>
//#include <cmath>
//#include <iomanip>
//
//void task1_5()
//{
//    int n;
//    std::cout << "Enter n: ";
//    std::cin >> n;
//
//    if (n <= 0) 
//    {
//        std::cout << "The number must be natural(greater 0)\n";
//    }
//
//    double sum = 1.0;
//    for (int i = 1; i <= n; ++i) {
//        sum += 1.0 / sqrt(i);
//    }
//
//    std::cout << std::fixed << std::setprecision(4);
//    std::cout << "Sum = " << sum << "\n";
//}
//
//int main() 
// {
//
//    task1_5();
//    return 0;
//}
 
////Exercise 2.
////5)S = ∑ от n = 1 до k ((-1)^(n+1) * x^(2n-1)) / (2n - 1)!.
//
//#include <iostream>
//#include <cmath>
//#include <iomanip>
//
//long double factorial(int n) 
//{
//    if (n == 0) return 1;
//    long double result = 1;
//    for (int i = 1; i <= n; ++i) {
//        result *= i;
//    }
//    return result;
//}
//
//void task2_5()
//{
//    int k;
//    double x;
//    std::cout << "Enter k: ";
//    std::cin >> k;
//    std::cout << "Enter x: ";
//    std::cin >> x;
//
//    if (k <= 0) {
//        std::cout << "The number must be natural (greater 0)\n";
//    }
//
//    long double sum = 0;
//    for (int n = 1; n <= k; ++n) {
//        long double numerator = pow(-1, n + 1) * pow(x, 2 * n - 1);
//        long double denominator = factorial(2 * n - 1);
//        sum += numerator / denominator;
//    }
//
//    std::cout << std::fixed << std::setprecision(10);
//    std::cout << "Result S = " << sum << "\n";
//}
//
//int main() 
//{
//
//    task2_5();
//    return 0;
//}
 
////Exercise 3
////5)S = ∑ от n = 1 до ∞ (5/((i+1)(i-1)))
// 
//#include <iostream>
//#include <iomanip>
//#include <cmath>
//
//void task3_5()
//{
//    //entering an accuracy
//    double e;
//    std::cout << "Enter an accuracy e (e > 0): ";
//    std::cin >> e;
//
//    //checking the correctness of the input
//    if (e <= 0) {
//        std::cout << "An accuracy must be greater 0\n";
//    }
//
//    //calculating the sum
//    double sum = 0;
//    int i = 2; //start with i = 2, since at i = 1 the denominator turns to 0
//    double currentTerm = 5.0 / ((i + 1) * (i - 1));
//
//    while (std::abs(currentTerm) >= e) {
//        sum += currentTerm;
//        i++;
//        currentTerm = 5.0 / ((i + 1) * (i - 1));
//    }
//
//    //output of the result
//    std::cout << std::fixed << std::setprecision(10);
//    std::cout << "Series sum = " << sum << "\n";
//    std::cout << "Summed terms number: " << i - 2 << "\n";
//
//}
//
//int main() 
//{
//    task3_5();
//    return 0;
//}
 
//Exercise 4. 
//                x      x ^ 2   x ^ 3   x ^ 4
//5) F(x) = 1 + ------ - ----- + ----- - ----- + ..., x ∈ [0.1; 0.9].
//              1 * 4    2 * 5   3 * 6   4 * 7
//
//#include <iostream>
//#include <iomanip>
//#include <cmath>
//
//using namespace std;
//
//double calculateF(double x, double epsilon) 
//{
//    double sum = 1.0;
//    double term = 1.0;
//    int n = 0;
//
//    while (fabs(term) > epsilon) {
//        n++;
//        term = pow(-1, n) * pow(x, n) / (n * (n + 3));
//        sum += term;
//    }
//
//    return sum;
//}
//
//void task4_5()
//{
//
//    const double a = 0.1;
//    const double b = 0.9;
//    const double step = 0.1;
//    const double epsilon = 0.0001;
//
//    cout << "Number\tValue of x\tValue of F(x)\tNumber of summed members\n";
//
//    for (double x = a; x <= b; x += step) {
//        double result = calculateF(x, epsilon);
//        int n = 0;
//
//        double term = 1.0;
//        while (fabs(term) > epsilon) {
//            n++;
//            term = pow(-1, n) * pow(x, n) / (n * (n + 3));
//        }
//
//        cout << fixed << setprecision(4);
//        cout << (x - a) / step + 1 << "\t" << x << "\t\t" << result << "\t\t" << n << "\n";
//    }
//
//}
//
//int main() 
//{
//
//    task4_5();
//
//    return 0;
//}