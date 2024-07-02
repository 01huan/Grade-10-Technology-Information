#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

struct element {
    int row;
    int col;
    int value;
};

vector<vector<int>> SparseMatrix(int rows, int  cols, int x) {
    vector<vector<int>> matrix(rows, vector<int>(cols));
    srand(time(0));
    for (int i=0; i<rows; i++) {
        for (int j=0; j<cols; j++) {
            if (rand()%100 < x) {
                matrix[i][j] = rand()%9 + 1;    // 1 <= non_0_element <= 9
            } else {
                matrix[i][j] = 0;
            }
        }
    } return matrix;
}

vector<element> compress(vector<vector<int>> matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    int non0 = 0;
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[0].size(); j++) {
            if (matrix[i][j]) {
                non0++;
            }
        } 
    } vector<element> compressed;
    compressed.push_back({rows, cols, non0});
    int k=1;
    for (int i=0; i<matrix.size(); i++) {
        for (int j=0; j<matrix[0].size(); j++) {
            if (matrix[i][j]) {
                compressed.push_back({i, j, matrix[i][j]});
                k++;
            }
        }
    } return compressed;
}

int main() {
    srand(time(0));
    const int _Rows = rand()%5 + 5;     // 5 <= rows,cols <= 9
    const int _Cols = rand()%5 + 5;
    const int x = rand()%31 + 20;       // 20 <= x <= 50
    vector<vector<int>> matrix = SparseMatrix(_Rows, _Cols, x);
    cout << "The origonal matrix: " << endl;
    
    for (int i=0; i<_Rows; i++) {
        for (int j=0; j<_Cols; j++) {
            cout << matrix[i][j] << " ";
        } cout << endl;
    } cout << "The compressed matrix: " << endl;

    vector<element> compressed = compress(matrix);
    matrix.clear();
    for (int i=0; i<compressed.size(); i++) {
        cout << compressed[i].row << " " << compressed[i].col << " " << compressed[i].value << endl;
    }
}