#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdexcept>
#include <string>

// Helper function f(x)
double f(double x) 
{
    double denominator = x * x - 2;
    double radical = x * x * x - 1;

    if (std::abs(denominator) < 1e-9)
        throw std::runtime_error("Division by zero when x = " + std::to_string(x));

    if (radical < 0)
        throw std::domain_error("The root of a negative number when x = " + std::to_string(x));

    return (x + 4) / denominator + std::sqrt(radical);
}

int main() 
{
    double a, b, h;

    std::cout << "Please, enter the initial value a: ";
    std::cin >> a;
    std::cout << "Please, enter the final value b: ";
    std::cin >> b;
    std::cout << "Input step h: ";
    std::cin >> h;

    if (h <= 0 || a > b) 
    {
        std::cerr << "Incorrect values of a, b or h.\n";
        return 1;
    }

    std::cout << "\nFunction values table:\n";
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "-----------------------------\n";
    std::cout << "|    x    |       y         |\n";
    std::cout << "-----------------------------\n";

    for (double x = a; x <= b + 1e-9; x += h) 
    {
        std::cout << "| " << std::setw(7) << x << " | ";
        try 
        {
            double y = f(x);
            std::cout << std::setw(13) << y << " |\n";
        }
        catch (const std::exception& e) 
        {
            std::cout << e.what() << " |\n";
        }
    }

    std::cout << "-----------------------------\n";

    return 0;
}
