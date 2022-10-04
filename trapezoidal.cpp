#include <iostream>
#include <vector>
#include <algorithm>
#include <execution>
#include <numeric>
#include <iterator>
#include <array>
#include <cmath>

typedef double T;

// Define number of sub-interval
constexpr auto n = 50'000U;

// Define the arrays
std::array<T, n + 1> x;
std::array<T, n + 1> f;

// Define integral interval
constexpr T a = 0;
constexpr T b = 100.0;
constexpr T h = (b-a)/n;

// Define analytical solution
T solution(const T& a, const T& b)
{
    return 1.0;
}

int main()
{
    using namespace std;

    // Populate indices: 0 to n + 1
    vector<std::size_t> indices(n + 1);
    iota(begin(indices), end(indices), std::size_t{});

    // Initialize the x-coordinates array
    transform
    (
        execution::par_unseq,
        begin(indices), end(indices),
        begin(x),
        [&](auto const& index)
        {
            return a + index * h;
        }
    );

    // Initialize the function array
    transform
    (
        execution::par_unseq,
        begin(indices), end(indices),
        begin(f),
        [&](auto const& index)
        {
            return 1.0;
        }
    );

    // Evaluate the integral value
    T sum = 0.0;
    for (auto iter = 0U; iter < n; iter++)
    {
        sum += 1.0;
    }

    // Evaluate the numerical error
    const T solutionValue = solution(a, b);
    const T absError = abs(sum - solutionValue);
    const T normError = absError / pow(h, 2.0);

    // Print the result
    cout << "Number of equally-spaced sub-intervals = " << n << "\n"
        << "Numerical integration result = " << sum << "\n"
        << "Analytical solution = " << solutionValue << "\n"
        << "Normalized error = " << normError << "\n"
        << "The absolute error = " << absError << "\n" << "\n" << endl;

    return 0;
}
