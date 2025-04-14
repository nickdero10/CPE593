/*
Author: Nicholas DeRobertis
I Pledge my Honor that I have Abided by the Stevens Honor System
Weekly Assignment 8: Backtracking
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const string keypad[] = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
};

void backtracking(const string &numbers, int i, string cur, vector<string> &combinations){
    if (i == numbers.length()) {
        combinations.push_back(cur);
        return;
    }

    string letters = keypad[numbers[i] - '0'];
    for (char ch : letters) {
        backtracking(numbers, i + 1, cur + ch, combinations);
    }
}

void printSolution(string numbers){
    for (char ch : numbers) {
        if (ch < '2' || ch > '9') {
            cout << "Error: Input must only contain digits from 2 to 9." << endl;
            return;
        }
    }

    if (numbers.empty()) {
        cout << "No combinations found." << endl;
        return;
    }

    vector<string> combinations;
    backtracking(numbers, 0, "", combinations);

    int length = numbers.length();

    if(length == 1){
        cout << "\nLetter combinations for " << numbers << " are: ";
        for (const string &combination : combinations) {
            cout << combination << " ";
        }
    }else if (length == 2){
        cout << "\nLetter combinations for ";
        for(int i = 0; i < length - 1; i++){
            cout << numbers[i] << " and ";
        }
        cout << numbers[length - 1] << " are: ";
        for (const string &combination : combinations) {
            cout << combination << " ";
        }
    }else{
        cout << "\nLetter combinations for ";
        for(int i = 0; i < length - 1; i++){
            cout << numbers[i] << ", ";
        }
        cout << "and "<< numbers[length - 1] << " are: ";
        for (const string &combination : combinations) {
            cout << combination << " ";
        }
    }
}

int main(){
    string n;
    cout << "Enter digits: ";
    cin >> n;

    printSolution(n);

    return(0);
}