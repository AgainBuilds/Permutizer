#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <unordered_set>
using namespace std;
int main(){
cout<<"Input your name:    "<<endl;
string name;
cin>>name;
int word_count = name.length();
int total = 1;
while(word_count!=0){
total = total * word_count;
word_count--;
}
sort(name.begin(), name.end());
cout<<"The number of arrangements is:    "<<total<<endl;
do{
cout<<name<<endl;
} while (next_permutation(name.begin(),  name.end()));
unordered_set <string> dictionary;
ifstream file ("word.txt" );
string word;
while (file>>word){
dictionary.insert(word);
} sort(name.begin(), name.end()); // reset to beginning
cout << "\nReal English words found:" << endl;
do {
    if (dictionary.count(name)) {
        cout << name << endl;
    }
} while (next_permutation(name.begin(), name.end()));

return 0;

}
