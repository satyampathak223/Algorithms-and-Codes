#include <iostream>
#include<climits>

using namespace std;
 
void printParenthesis(int i, int j, int n, int* bracket, string &matrix) {
    if (i == j) {
        cout << matrix;
        matrix[1] = matrix[1] + 1;
        return;
    }
    cout << "(";
    printParenthesis(i, *((bracket + i * n) + j), n, bracket, matrix);
    printParenthesis(*((bracket + i * n) + j) + 1, j, n, bracket, matrix);
    cout << ")";
}

void matrixChainOrder(int dimensions[], int size) {
    int m[size][size];
    int bracket[size][size];
    for (int i = 1; i < size; i++)
        m[i][i] = 0;
    for (int L = 2; L < size; L++) {
        for (int i = 1; i < size - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + dimensions[i - 1] * dimensions[k] * dimensions[j];
                if (q < m[i][j]) 
                {
                    m[i][j] = q;
                    bracket[i][j] = k;
                }
            }
        }
    }
    string matrix = "A1";
    cout << "Optimal Parenthesization is : ";
    printParenthesis(1, size - 1, size, (int*)bracket, matrix);
    cout << "\n" << "Optimal Cost is : " << m[1][size - 1] << "\n";
}

int main() {
    int dimensions[] = {5, 10, 3, 12, 5, 50, 6};
    int size = 7;
    matrixChainOrder(dimensions, size);
    return 0;
}