/*
Author: Nicholas DeRobertis
I Pledge my Honor that I have Abided by the Stevens Honor System
Weekly Assignment 9: Rabin-Karp String Algorithm
*/

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

vector<string> duplicates(string s) {
    if (s.length() < 10) return {};

    unordered_set<int> visited;
    unordered_set<string> repeated;
    
    int hash = 0;
    int size = 10;

    auto nucleos = [](char c) {
        switch (c) {
            case 'A': return 0;
            case 'C': return 1;
            case 'G': return 2;
            case 'T': return 3;
        }
        return -1;
    };

    for (int i = 0; i < size; ++i) {
        hash = (hash << 2) | nucleos(s[i]);
    }
    visited.insert(hash);

    for (int i = 1; i <= s.length() - size; ++i) {
        hash = ((hash << 2) & ((1 << 20) - 1)) | nucleos(s[i + size - 1]);
        if (visited.count(hash)) {
            repeated.insert(s.substr(i, size));
        } else {
            visited.insert(hash);
        }
    }

    return vector<string>(repeated.begin(), repeated.end());
}

int main(){
    string s;
    cout << "Enter Biologicial String: ";
    cin >> s;

    vector<string> output = duplicates(s);

    cout << "\nRepeated Nucleotide Portions: [";

    for (int i = 0; i < output.size(); i++){
        cout << output[i];
        if(i < output.size() - 1){
            cout << ", ";
        }
    }
    cout << "]";

    return 0;
}