#include <iostream>  //include library
using namespace std;


void matrix43(); 
void get_matr43(); 
void show_matr43();

void matrix60();
void get_matr60();
void show_matr60();
void mirror_matr60();
void show_mirror_matr60();

int main() {
    int choice = 0;

    while (choice != 3) {

        cout << endl;
        cout << "Choose task: "
            "\n1 - Matrix43"
            "\n2 - Matrix60"
            "\n3 - Exit"
            "\n" << endl;

        cin >> choice;

        switch (choice) {
        case 1: {
            matrix43();
            break;
        }
        case 2: {
            matrix60();
            break;
        }
        case 3: {
            cout << "Exit";
            break;
        }
        default: {
            cout << "Wrong number,try again";
        }
        }
    }
}
//task selector

const int ROW = 10, COL = 10; //matrix size limit

void get_matr43(int in_matr[ROW][COL], int& in_row, int& in_col) {
    do
    {
        cout << "Enter rows count (2-10): "; //request matrix size
        cin >> in_row;
        cout << "Enter columns count (= Rows !!!) (2-10): ";//request matrix size
        cin >> in_col;
    }

    while (in_col < 2 || in_col>COL || in_row <2 || in_row>ROW || in_row != in_col); // validation 
    cout << "Enter elements: " << endl; // request elements of matrix 
    for (int i = 0; i < in_row; i++)
        for (int j = 0; j < in_col; j++)
            cin >> in_matr[i][j];
} 
//request matrix

bool check_col(int matrix[ROW][COL], int rows, int column) { 
    for (int i = 1; i < rows; ++i) {
        if (matrix[i][column] > matrix[i - 1][column]) { 
            return false;
        }
    }
    return true;
}
//column descending check

int count_col(int matrix[ROW][COL], int rows, int columns) { 
    int count = 0;
    for (int j = 0; j < columns; ++j) {
        if (check_col(matrix, rows, j)) { 
            ++count;
        }
    }
    return count;
}
// count columns 

void show_matr43(const int out_matr[ROW][COL], const int row, const int col) {
    cout << endl << "Matrix: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << out_matr[i][j] << "\t";
        cout << endl;
    }
}
//show matrix 

void matrix43() {
    int matr1[ROW][COL]; 
    int row, col; 
    get_matr43(matr1, row, col);
    show_matr43(matr1, row, col);
    int count = count_col(matr1, row, col);
    cout << "Number of columns with descending elements: " << count << endl;
    cout << endl;
}
//task function 

void get_matr60(int in_matr[ROW][COL], int& in_row, int& in_col) {
    do
    {
        cout << "Enter rows count (2-10): ";//request matrix size
        cin >> in_row;
        cout << "Enter columns count (= Rows !!!) (2-10): ";//request matrix size
        cin >> in_col;
    }

    while (in_col < 2 || in_col>COL || in_row <2 || in_row>ROW || in_row != in_col); // validation
    cout << "Enter elements: " << endl;// request elements of matrix 
    for (int i = 0; i < in_row; i++)
        for (int j = 0; j < in_col; j++)
            cin >> in_matr[i][j];
}
//request matrix

void show_matr60(const int out_matr[ROW][COL], const int row, const int col) {
    cout << endl << "Matrix: " << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            cout << out_matr[i][j] << "\t";
        cout << endl;
    }
}
//show matrix

void mirror_matr60(int matrix[ROW][COL], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col / 2; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][col - 1 - j];
            matrix[i][col - 1 - j] = temp;
        }
    }
}
// mirror matrix 

void show_mirror_matr60(int matrix[ROW][COL], int row, int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}
//show mirrored matrix 

void matrix60() {
    int matr1[ROW][COL];
    int row, col;
    get_matr60(matr1, row, col);
    show_matr60(matr1, row, col);
    mirror_matr60(matr1, row, col);
    cout << "Mirrored matrix:" << endl;
    show_mirror_matr60(matr1, row, col);
}
//task function 