#include <iostream>
#include <sstream>

int main() {
    // Declare a number
    int number = 42;

    // Create an output string stream
    std::ostringstream oss;

    // Use the output stream to convert the number to text
    oss << number;

    // Get the text representation as a string
    std::string text = oss.str();

    // Print the text representation
    std::cout << "Text representation: " << text << std::endl;

    return 0;
}