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
    
    unsigned int n, m;
    fin >> n >> m;
    vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        fin >> vec[i];
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n - 1; ++i) {
        if (vec[i] == vec[i + 1]) {
        }
        else if ((vec[i + 1] - vec[i]) * (i + 1) > m)
        {
            fout << vec[0] + m / (i + 1);
            return 0;
        }
        else
        {
            m -= (vec[i + 1] - vec[i]) * (i + 1);
            for (int j = 0; j <= i; ++j) {
                vec[j] = vec[i + 1];
            }
        }
    }

    fout << vec[0] + m / n;

    fin.close();
    fout.close();
    system("pause");
    return 0;
}
