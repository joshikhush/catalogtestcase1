#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>

// Function to decode the value from any base to base 10
long long decodeValue(const std::string& value, int base) {
    long long result = 0;
    long long power = 1;  // base^0 is 1
    for (int i = value.length() - 1; i >= 0; --i) {
        char digit = value[i];
        int digitValue;
        if (digit >= '0' && digit <= '9') {
            digitValue = digit - '0';
        } else if (digit >= 'A' && digit <= 'Z') {
            digitValue = digit - 'A' + 10;
        } else {
            throw std::invalid_argument("Invalid character in base number.");
        }
        result += digitValue * power;
        power *= base;
    }
    return result;
}

// Function for Lagrange interpolation to find the constant term (c)
double lagrangeInterpolation(const std::vector<std::pair<int, long long>>& points) {
    double result = 0.0;
    
    for (int i = 0; i < points.size(); ++i) {
        double term = points[i].second;  // Start with y_i
        
        for (int j = 0; j < points.size(); ++j) {
            if (i != j) {
                term *= (0 - points[j].first) * 1.0 / (points[i].first - points[j].first);
            }
        }
        
        result += term;
    }
    
    return result;
}

int main() {
    // Hardcoded JSON-like input (with different bases and values)
    std::map<int, std::pair<int, std::string>> input = {
        {1, {10, "28735619723837"}},
        {2, {16, "1A228867F0CA"}},
        {3, {12, "32811A4AA0B7B"}},
        {4, {11, "917978721331A"}},
        {5, {16, "1A22886782E1"}},
        {6, {10, "28735619654702"}},
        {7, {14, "71AB5070CC4B"}},
        {8, {9, "122662581541670"}},
        {9, {8, "642121030037605"}}
    };

    // Convert input to (x, y) points
    std::vector<std::pair<int, long long>> points;
    for (const auto& item : input) {
        int x = item.first;
        int base = item.second.first;
        std::string value = item.second.second;
        long long y = decodeValue(value, base);
        points.push_back({x, y});
    }

    // Print decoded points for debugging
    std::cout << "Decoded points (x, y):\n";
    for (const auto& point : points) {
        std::cout << "(" << point.first << ", " << point.second << ")\n";
    }

    // Perform Lagrange interpolation to find the constant term 'c'
    double constantTerm = lagrangeInterpolation(points);

    // Print the result (constant term 'c')
    std::cout << "\nThe constant term (c) is: " << constantTerm << std::endl;

    return 0;
}
