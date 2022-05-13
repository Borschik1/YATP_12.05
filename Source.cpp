#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;


int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    
    int n, m;
    string word, str;
    vector<string> words;
    map<string, bool> mp;
    fin >> n >> m;
    for (int i = 0; i < n; ++i) {
        fin >> word;
        mp.emplace(word, false);
        words.push_back(word);
    }
    getline(fin, str);
    for (int i = 0; i < m; ++i) {
        getline(fin, str);
        word = "";
        //cout << str << endl;
        for (int j = 0; j < str.size(); ++j) {
            if (str[j] == ' ' || str[j] == '.' || str[j] == ',' || str[j] == ':' || str[j] == ';' || str[j] == '-' || str[j] == 39 || str[j] == '"' || str[j] == '!' || str[j] == '?') {
                if (word == "") {
                    continue;
                }
                if (!mp.contains(word)) {
                    fout << "Some words from the text are unknown.";
                    return 0;
                }
                mp[word] = true;
                word = "";
            }
            else {
                string s(1, tolower(str[j]));
                word += s;
            }
            //cout << word << endl;
        }
        if (word != "") {
            if (!mp.contains(word)) {
                fout << "Some words from the text are unknown.";
                return 0;
            }
            mp[word] = true;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!mp[words[i]]) {
            fout << "The usage of the vocabulary is not perfect.";
            //cout << words[i] << endl;
            return 0;
        }
    }
    fout << "Everything is going to be OK.";

    fin.close();
    fout.close();
    system("pause");
    return 0;
}