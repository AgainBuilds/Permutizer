#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <unordered_set>
#include <cctype>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Error: No word provided!" << endl;
        return 1;
    }

    string name = argv[1];

    if (name.empty()) {
        cerr << "Error: Empty input!" << endl;
        return 1;
    }

    // Calculate factorial (number of permutations)
    long long total = 1;
    for (size_t i = 2; i <= name.length(); i++) {
        total *= i;
    }

    // Sort for permutations
    sort(name.begin(), name.end());

    cout << "The number of arrangements is: " << total << endl;

    cout << "\nAll possible arrangements:" << endl;
    do {
        cout << name << endl;
    } while (next_permutation(name.begin(), name.end()));

    unordered_set<string> dictionary;
    ifstream file("word.txt");
    if (!file.is_open()) {
        cerr << "Error: word.txt not found!" << endl;
        return 1;
    }

    string word;
    while (file >> word) {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        dictionary.insert(word);
    }

    sort(name.begin(), name.end());
    int real_word_count = 0;
    cout << "\nReal English words found:" << endl;
    do {
        string lower_name = name;
        transform(lower_name.begin(), lower_name.end(), lower_name.begin(), ::tolower);
        if (dictionary.count(lower_name)) {
            cout << name << endl;
            real_word_count++;
        }
    } while (next_permutation(name.begin(), name.end()));

    cout << "\nTotal real English words found: " << real_word_count << endl;

    return 0;
}
