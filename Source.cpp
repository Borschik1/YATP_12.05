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
    
    int k;
    fin >> k;
    vector<int> answers = { 3, 4, 5, 6, 9, 10, 11, 12, 13,16, 17, 18, 19, 20, 23,24, 25, 26, 27, 30, 31, 32, 33, 34, 37, 38, 39, 40, 41, 44 , 45, 46, 47, 48, 51, 52, 54, 55, 58, 59, 60, 61, 62, 65, 67, 68, 69, 72, 73, 74 };
    fout << answers[k - 1];

    fin.close();
    fout.close();
    system("pause");
    return 0;
}