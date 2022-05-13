#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

using namespace std;


bool prime(int num) {
    if (num == 1) return false;
    for (int i = 2; i <= num / i; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}


int main() {
    ifstream fin("D:/Desktop/INPUT.txt");
    ofstream fout("D:/Desktop/OUTPUT.txt");
    
    int k, cnt1 = 0, cnt2 = 0, num = 2;
    fin >> k;

    while (cnt2 != k) {
        if (prime(num)) {
            cnt1++;
            if (prime(cnt1)) {
                cnt2++;
            }
        }
        num++;
    }
    fout << --num;

    fin.close();
    fout.close();
    system("pause");
    return 0;
}