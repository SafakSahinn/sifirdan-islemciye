#include <iostream>
#include <cmath>
#include <limits>

int main() {
    double x = std::numeric_limits<double>::quiet_NaN();
    std::cout << "x = " << x << "\n";
    std::cout << "x == x: " << (x == x) << "\n";        // false
    std::cout << "isnan(x): " << std::isnan(x) << "\n"; // true
    return 0;
}
