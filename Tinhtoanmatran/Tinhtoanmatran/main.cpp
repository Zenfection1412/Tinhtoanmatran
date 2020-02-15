//
//  main.cpp
//  Tinhtoanmatran
//
//  Created by Lê Tuấn Kiệt on 2/15/20.
//  Copyright © 2020 Lê Tuấn Kiệt. All rights reserved.
//
#include "iostream"
#define max 100
using namespace std;
void nhapmatran(int M[max][max], int row, int col);
void xuatmatran(int M[max][max], int row, int col);
void congmatran(int A[max][max], int B[max][max], int row, int col);
void kiemtra2matrancungcap(int row1, int col1, int row2, int col2);
void trumatran(int A[max][max], int B[max][max], int row, int col);
void nhanmatran(int A[max][max],int B[max][max],int row1, int col1,int row2,int col2);
int main(int argc, char const *argv[])
{
    int row1, col1, row2, col2;
    int A[max][max], B[max][max];
    std::cout << "Nhập số dòng i của ma trận 1 = "; std::cin >> row1;
    std::cout << "Nhập số cột j ma trận 1 = "; std::cin >> col1;
    nhapmatran(A, row1, col1);
    std::cout << "Nhập số dòng i ma trận 2 = "; std::cin >> row2;
    std::cout << "Nhập số cột j ma trận 2 = "; std::cin >> col2;
    nhapmatran(B, row2, col2);
    std::cout << "-----Mời bạn chọn phép tính bằng số tương ứng-----" << '\n';
    int pheptinh;
    std::cout << "Phép cộng (1)\nPhép trừ (2)\nPhép nhân(3)\nPhép chia (4)\n Chọn số : "; std::cin >> pheptinh;
    if (pheptinh == 1){
        kiemtra2matrancungcap(row1, col1, row2, col2);
        congmatran(A, B, row1, col1);
    }
    else if(pheptinh == 2){
        kiemtra2matrancungcap(row1, col1, row2, col2);
        trumatran(A, B, row1, col1);
    }
    else if (pheptinh==3)
        nhanmatran(A,B,row1,col1,row2,col2);
    return 0;
}

void nhapmatran(int M[max][max], int row, int col)
{
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            std::cout << "M[" << i << "][" << j << "]= ";
            std::cin >> M[i][j];
        }
        std::cout << '\n';
    }
}

void xuatmatran(int M[max][max], int row, int col)
{
    std::cout << "----Xuất Ma trận---" << '\n';
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            std::cout << M[i][j] << '\t';
        }
        std::cout << '\n';
    }
}

void kiemtra2matrancungcap(int row1, int col1, int row2, int col2){
    if (row1 != row2 || col1 != col2) {
        std::cout << "Lỗi kích thước không thực hiện phép tính được" << '\n';
        exit(0);
    }
}
void congmatran(int A[max][max], int B[max][max], int row, int col)
{
    int C[max][max];
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    xuatmatran(C, row, col);
}

void trumatran(int A[max][max], int B[max][max], int row, int col)
{
    int C[max][max];
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    xuatmatran(C, row, col);
}
void nhanmatran(int A[max][max],int B[max][max],int row1, int col1,int row2,int col2){
    int C[max][max];
    if (col1!=row2) {
        std::cout<<"Muốn nhân 2 ma trận bắt buộc cột của ma trận 1 phải bằng dòng của ma trận 2";
        exit(0);
    }
    else{
    for (int i=1; i<= row1; i++) {
        for (int j=1; j<= col2; j++) {
             C[i][j]=0;
            for (int k=1; k<= col2; k++) {
                C[i][j]+=A[i][k]*B[k][j];
                }
            }
        }
    }
    xuatmatran(C, row1, col2);
}
