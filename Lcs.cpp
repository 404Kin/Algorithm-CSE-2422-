
#include <bits/stdc++.h>
using namespace std;

string LCS(string X, string Y) {
    int m = X.size();
    int n = Y.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int i = m, j = n;
    string lcsStr = "";

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsStr += X[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(lcsStr.begin(), lcsStr.end());
    return lcsStr;
}

int main() {
    string X, Y;
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    string lcsStr = LCS(X, Y);

    cout << "Length of LCS is: " << lcsStr.size() << endl;
    cout << "LCS is: " << lcsStr << endl;

    return 0;
}
