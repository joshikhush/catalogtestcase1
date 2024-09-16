#include <iostream>
#include <vector>
#include <cmath>
#include <string>


// Function to decode a value from a given base
int decodeValue(const std::string& value, int base) {
    return std::stoi(value, nullptr, base);
}

// Function to perform polynomial interpolation and find the constant term
double findPolynomialConstantTerm(const std::vector<int>& x_values, const std::vector<int>& y_values) {
    int n = x_values.size();
    std::vector<std::vector<double>> matrix(n, std::vector<double>(n + 1, 0.0));

    // Set up the matrix
    for (int i = 0; i < n; ++i) {
        matrix[i][0] = 1.0;
        for (int j = 1; j < n; ++j) {
            matrix[i][j] = matrix[i][j - 1] * x_values[i];
        }
        matrix[i][n] = y_values[i];
    }

    // Apply Gaussian Elimination
    for (int i = 0; i < n; ++i) {
        // Find the pivot row
        int max_row = i;
        for (int k = i + 1; k < n; ++k) {
            if (std::fabs(matrix[k][i]) > std::fabs(matrix[max_row][i])) {
                max_row = k;
            }
        }
        
        // Swap rows
        std::swap(matrix[i], matrix[max_row]);

        // Make the pivot element 1 and eliminate other rows
        for (int j = i + 1; j < n; ++j) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k <= n; ++k) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }

    // Back substitution
    std::vector<double> coefficients(n, 0.0);
    for (int i = n - 1; i >= 0; --i) {
        coefficients[i] = matrix[i][n] / matrix[i][i];
        for (int j = i - 1; j >= 0; --j) {
            matrix[j][n] -= matrix[j][i] * coefficients[i];
        }
    }

    return coefficients[0]; // constant term
}

int main() {
    // Decoded values from the provided JSON
    std::vector<int> x_values = {1, 2, 3}; // x-values (keys in JSON)
    std::vector<int> y_values = {4, 7, 12}; // Decoded y-values

    // Find the constant term of the polynomial
    double constant_term = findPolynomialConstantTerm(x_values, y_values);
    
    // Output the result
    std::cout << "Constant term: " << constant_term << std::endl;
    
    return 0;
}
