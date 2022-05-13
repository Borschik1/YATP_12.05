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
    
    long long n, now = 1;
    fin >> n;
    for (int i = 1; i <= n; ++i) {
        now *= i;
        while (now % 10 == 0) {
            now /= 10;
        }
        now %= 1000000;
    }
    fout << now % 10;

    fin.close();
    fout.close();
    system("pause");
    return 0;
}