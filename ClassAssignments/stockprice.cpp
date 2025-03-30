/*
Author: Nicholas DeRobertis
I Pledge my Honor that I have Abided by the Stevens Honor System
Class Assignment 2: Enhanced Stock Price Analysis Tool
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int MAX_DAYS = 100;

struct StockRecord {
    string date;
    double price;
};

// Function prototypes
void inputStockPrices(StockRecord records[], int numDays);
void bubbleSortByDate(StockRecord records[], int numDays);
double calculateAveragePrice(StockRecord records[], int numDays);
void findHighestAndLowestPrices(StockRecord records[], int numDays);
void searchStockPricesInRange(StockRecord records[], int numDays);
int countPricesAboveThreshold(StockRecord records[], int numDays);

int main() {
    int numDays;
    cout << "Welcome to the Enhanced Stock Price Analysis Tool!\n";
    cout << "Enter the number of days with historical stock prices (up to 100): ";
    cin >> numDays;

    // Create arrays to store stock records
    StockRecord records[MAX_DAYS];

    // Input stock prices
    inputStockPrices(records, numDays);

    // Sort the stock prices by date
    bubbleSortByDate(records, numDays);

    cout << "\nStock prices sorted successfully!\n";

    while (true) {
        cout << "\nAdditional Features:\n";
        cout << "1. Calculate average stock price.\n";
        cout << "2. Find highest and lowest stock prices.\n";
        cout << "3. Search for stock prices within a date range.\n";
        cout << "4. Count days with stock price above a threshold.\n";
        cout << "5. Exit.\n";
        cout << "Select an option (1-5): ";
        
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: // Calculate average stock price
            {
                double average = calculateAveragePrice(records, numDays);
                cout << "Average stock price: $" << fixed << setprecision(2) << average << endl;
                break;
            }
            case 2: // Find highest and lowest stock prices
                findHighestAndLowestPrices(records, numDays);
                break;
            case 3: // Search for stock prices within a date range
                searchStockPricesInRange(records, numDays);
                break;
            case 4: // Count days with stock price above a threshold
            {
                int count = countPricesAboveThreshold(records, numDays);
                cout << "Number of days with stock price above the threshold: " << count << endl;
                break;
            }
            case 5: // Exit
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please select a valid option (1-5).\n";
        }
    }
}

// Function to input stock prices
void inputStockPrices(StockRecord records[], int numDays) {
     // write code here
     for(int i = 0; i < numDays; i++){
        cout << "Day " << i + 1 << ": " << endl;
        cout << "Date (YYYY-MM-DD): ";
        cin >> records[i].date;
        cout << "Stock Price: ";
        cin >> records[i].price;
        cout << endl;
     }
}

// Function to sort stock prices by date using bubble sort
void bubbleSortByDate(StockRecord records[], int numDays) {
    // write code here
    int flag = 0;
    for(int i = 0; i < numDays - 1; i++){
        for(int j = 0; j < numDays - 1 - i; j++){
            if(records[j].date > records[j + 1].date ){
                swap(records[j].date, records[j+1].date);
                flag = 1;
            }
        }
        if(flag == 0){
            return;
        }
    }

}

// Function to calculate the average stock price
double calculateAveragePrice(StockRecord records[], int numDays) {
   // write code here
   double sum = 0;
   for(int i = 0; i < numDays; i++){
        sum += records[i].price;
   }
   double avg = sum / numDays;
   return avg;
}

// Function to find and display the highest and lowest stock prices
void findHighestAndLowestPrices(StockRecord records[], int numDays) {
    // write code here
    double high = records[0].price;
    double low = records[0].price;
    for(int i = 0; i < numDays; i++){
        if(records[i].price > high){
            high = records[i].price;
        }else if(records[i].price < low){
            low = records[i].price;
        }
    }
    cout << "Highest Stock Price: " << high << endl;
    cout << "Lowest Stock Price: " << low << endl;
}

// Function to search for stock prices within a date range
void searchStockPricesInRange(StockRecord records[], int numDays) {
    string startDate, endDate;
    cout << "Enter Start Date for Range (YYYY-MM-DD): ";
    cin >> startDate;
    cout << "Enter End Date for Range (YYYY-MM-DD): ";
    cin >> endDate;

    if (startDate > endDate) {
        cout << "Invalid Date Range. Start date must be earlier than end date.\n";
        return;
    }

    bool found = false;
    cout << "\nStock Prices in Range (" << startDate << " to " << endDate << "):\n";

    for (int i = 0; i < numDays; i++) {
        if (records[i].date >= startDate && records[i].date <= endDate) {
            cout << "Date: " << records[i].date << " | Price: $" << fixed << setprecision(2) << records[i].price << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No stock prices found within the given date range.\n";
    }
}

// Function to count days with stock price above a threshold
int countPricesAboveThreshold(StockRecord records[], int numDays) {
    double threshold;
    int count = 0;
    cout << "Enter Price Threshold: ";
    cin >> threshold;

    for(int i = 0; i < numDays; i++){
        if(records[i].price > threshold){
            count++;
        }
    }
    return count;
}
