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
    
    int now = 0, maxi = 0;
    string str;
    getline(fin, str);
    vector<int> vec;
    vec.push_back(0);
    for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '<') {
            if (vec[now] > 0) vec[now]--;
            else if (now > 0) vec.erase(vec.begin() + now--);
        }
        else if (str[i] == '^') {
            if (now > 0) now--;
        }
        else if (str[i] == '|') {
            if (now + 1 < vec.size()) now++;
        }
        else if (str[i] == 92) {
            vec.push_back(0);
            now++;
        }
        else {
            if (str[i] >= 32) vec[now]++;
        }
        maxi = max(maxi, vec[now]);
    }
    fout << maxi;

    fin.close();
    fout.close();
    system("pause");
    return 0;
}