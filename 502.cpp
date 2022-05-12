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
    
    int n;
    fin >> n;
    vector < vector<int>> vec(1 + n, vector<int>(1 + n));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            fin >> vec[i][j];
        }
    }
    const int ultra_small = -1000000000;
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, ultra_small));
    ans[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            ans[i][j] = ans[i - 1][j];
            for (int k = 1; k <= j; ++k) {
                ans[i][j] = max(ans[i][j], vec[k][i] + ans[i - 1][j - k]);
            }
        }
    }
    fout << ans[n][n];

    fin.close();
    fout.close();
    system("pause");
    return 0;
}
