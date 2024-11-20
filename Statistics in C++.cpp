#include <iostream>
#include <cmath>
using namespace std;
void calculateUngroupedData(int count) {
    double sum = 0, mean, varianceSum = 0, stdDev;
    double numbers[100]; // Fixed size for simplicity
    // Input ungrouped data
    cout << "Enter " << count << " numbers:\n";
    for (int i = 0; i < count; i++) {
        cin >> numbers[i];
        sum += numbers[i];
    }
    mean = sum / count;

    // Calculate Variance
    for (int i = 0; i < count; i++) {
        varianceSum += (numbers[i] - mean) * (numbers[i] - mean);
    }
    double variance = varianceSum / count;
    
    //  calculation of standard deviation
    double guess = variance / 2.0;
    for (int i = 0; i < 10; i++) {
        guess = (guess + variance / guess) / 2.0;
    }
    stdDev = guess;

    // Calculate Median
    // Bubble sort for median
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                double temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    double median;
    if (count % 2 == 0) {
        median = (numbers[count / 2 - 1] + numbers[count / 2]) / 2.0;
    } else {
        median = numbers[count / 2];
    }

    // Calculate Mode
    double mode = numbers[0];
    int maxCount = 1;
    for (int i = 0; i < count; i++) {
        int countMode = 1;
        for (int j = i + 1; j < count; j++) {
            if (numbers[i] == numbers[j]) {
                countMode++;
            }
        }
        if (countMode > maxCount) {
            maxCount = countMode;
            mode = numbers[i];
        }
    }

    // Output results
    cout << "\nUngrouped Data Results:\n";
    cout << "Mean: " << mean << endl;
    cout << "Median: " << median << endl;
    cout << "Mode: " << mode << endl;
    cout << "Standard Deviation: " << stdDev << endl;
}

void calculateGroupedData(int classes) {
    double frequency[100], midpoints[100];
    double sum = 0, totalFrequency = 0;
    
    // Input grouped data
    cout << "Enter the frequency for " << classes << " classes:\n";
    for (int i = 0; i < classes; i++) {
        cout << "Frequency of class " << (i + 1) << ": ";
        cin >> frequency[i];
        totalFrequency += frequency[i];

        cout << "Enter midpoint for class " << (i + 1) << ": ";
        cin >> midpoints[i];
        sum += midpoints[i] * frequency[i];
    }
    
    double mean = sum / totalFrequency;

    // Calculate Mode
    double mode = midpoints[0];
    double maxFrequency = frequency[0];
    for (int i = 1; i < classes; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
            mode = midpoints[i];
        }
    }

    // Calculate Median
    double cumulativeFrequency[100] = {0};
    cumulativeFrequency[0] = frequency[0];
    for (int i = 1; i < classes; i++) {
        cumulativeFrequency[i] = cumulativeFrequency[i - 1] + frequency[i];
    }
    double medianClass = 0;
    for (int i = 0; i < classes; i++) {
        if (cumulativeFrequency[i] >= totalFrequency / 2) {
            medianClass = midpoints[i];
            break;
        }
    }

    // Output results
    cout << "\nGrouped Data Results:\n";
    cout << "Mean: " << mean << endl;
    cout << "Mode: " << mode << endl;
    cout << "Median Class: " << medianClass << endl;
}

int main() {
    int choice, count, classes;

    cout << "Choose data type:\n1. Ungrouped Data\n2. Grouped Data\n";
    cin >> choice;

    if (choice == 1) {
        cout << "Enter number of data points: ";
        cin >> count;
        calculateUngroupedData(count);
    } else if (choice == 2) {
        cout << "Enter number of classes: ";
        cin >> classes;
        calculateGroupedData(classes);
    } else {
        cout << "Invalid choice." << endl;
    }
    return 0;
}
