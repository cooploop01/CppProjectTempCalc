//
//  Temperature Converter
//
//  Created by Cooper Ring on 2/8/24.
//
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to convert Fahrenheit to Celsius
double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

int main() {
    // Open the input file
    ifstream inputFile("FahrenheitTemperature.txt");

    // Check if the file is successfully opened
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open the input file." << endl;
        return 1; // Return an error code
    }

    // Open the output file
    ofstream outputFile("CelsiusTemperature.txt");

    // Check if the file is successfully opened
    if (!outputFile.is_open()) {
        cerr << "Error: Unable to open the output file." << endl;
        inputFile.close(); // Close the input file before exiting
        return 1; // Return an error code
    }

    string cityName;
    double fahrenheitTemperature;

    // Read data from the input file and write to the output file
    while (inputFile >> cityName >> fahrenheitTemperature) {
        // Convert Fahrenheit to Celsius
        double celsiusTemperature = fahrenheitToCelsius(fahrenheitTemperature);

        // Write to the output file
        outputFile << cityName << " " << celsiusTemperature << endl;
    }

    // Close the input and output files
    inputFile.close();
    outputFile.close();

    cout << "Conversion completed successfully." << endl;

    return 0; // Return 0 to indicate successful execution
}
