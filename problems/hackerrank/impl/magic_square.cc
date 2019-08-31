#include <bits/stdc++.h>

using namespace std;

vector<vector<vector<int>>> magic_squares;

// Complete the formingMagicSquare function below.

int formingMagicSquare(vector<vector<int>> s) {
    vector<bool> used{10, false};
    vector<int[3][3]>  boards;

    for (int i = 0; i<3; i++) {
        for (int k = 0; k<3; k++) {

        }
    }








}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);
    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        for (int j = 0; j < 3; j++) {
            cin >> s[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
