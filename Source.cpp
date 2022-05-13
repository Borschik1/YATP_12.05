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
    
    int m, copy;
    vector<int> vec = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    fin >> m;
    copy = m;

    for (int i = 9; i > 1; --i) {
        vec[i] = 0;
        while (m % i == 0) {
            m /= i;
            vec[i]++;
        }
    }

    if (m != 1) {
        fout << -1 << " " << -1;
        return 0;
    }

    for (int i = 2; i <= 9; ++i) {
        while (vec[i]) {
            vec[i]--;
            fout << i;
        }
    }
    fout << " ";

    for (int i = 2; i <= 7; ++i) {
        while (copy % i == 0) {
            copy /= i;
            vec[i]++;
        }
    }
    for (int i = 7; i > 1; --i) {
        while (vec[i]) {
            fout << i;
            vec[i]--;
        }
    }

    fin.close();
    fout.close();
    system("pause");
    return 0;
}