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
void nhapmatran(float M[max][max], int row, int col);
void xuatmatran(float M[max][max], int row, int col);
void congmatran(float A[max][max], float B[max][max], int row, int col);
void kiemtramatranvuong(int row,int col);
void kiemtra2matrancungcap(int row1, int col1, int row2, int col2);
void trumatran(float A[max][max], float B[max][max], int row, int col);
void nhanmatran(float A[max][max],float B[max][max],int row1, int col1,int row2,int col2);
void chuyenthanhmatrantamgiac(float M[max][max],int row);
void dinhthucmatran(int A[max][max],int row,int col);
int main(int argc, char const *argv[])
{
    int row1, col1, row2, col2,n;
    float A[max][max], B[max][max];
    cout<<"Nhập số ma trận muốn tạo : ";cin>>n;
    if (n==1) {
        int biendoi;
        cout << "Nhập số dòng i của ma trận = "; cin >> row1;
        cout << "Nhập số cột j ma trận = "; cin >> col1;
        nhapmatran(A, row1, col1);
        cout << "----Mời bạn chọn biểu thức biến đổi----"<<'\n';
        cout<< "Biến thành ma trận tam giác (1)\nTính định thức ma trận (2)";cin>>biendoi;
        switch (biendoi) {
            case 1:
                kiemtramatranvuong(row1, col1);
                chuyenthanhmatrantamgiac(A, row1);
                xuatmatran(A, row1, row1);
                break;
            case 2:
                
                break;
            default:
                cout<<"Bạn đã nhập sai phép biến đổi, mời bạn chạy lại chương trình";
                break;
        }
    }
    else if(n==2){
    cout << "Nhập số dòng i của ma trận 1 = "; cin >> row1;
    cout << "Nhập số cột j ma trận 1 = "; cin >> col1;
    nhapmatran(A, row1, col1);
    cout << "Nhập số dòng i ma trận 2 = "; cin >> row2;
    cout << "Nhập số cột j ma trận 2 = "; cin >> col2;
    nhapmatran(B, row2, col2);
    cout << "-----Mời bạn chọn phép tính bằng số tương ứng-----" << '\n';
    int pheptinh;
    cout << "Phép cộng (1)\nPhép trừ (2)\nPhép nhân(3)\nPhép chia (4)\n Chọn số : "; cin >> pheptinh;
        switch (pheptinh) {
            case 1:
                kiemtra2matrancungcap(row1, col1, row2, col2);
                congmatran(A, B, row1, col1);
                break;
            case 2:
                kiemtra2matrancungcap(row1, col1, row2, col2);
                trumatran(A, B, row1, col1);
                break;
            case 3:
                nhanmatran(A,B,row1,col1,row2,col2);
                break;
            case 4:
                break;
            default:
                cout<<"Bạn đã nhập sai phép tính, mời chạy lại chương trình nhập lại";
                break;
        }
    return 0;
  }
}
void nhapmatran(float M[max][max], int row, int col){
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cout << "M[" << i << "][" << j << "]= ";
            cin >> M[i][j];
        }
        cout << '\n';
    }
}

void xuatmatran(float M[max][max], int row, int col)
{
    cout << "----Xuất Ma trận---" << '\n';
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            cout << M[i][j] << '\t';
        }
        cout << '\n';
    }
}
void kiemtramatranvuong(int row,int col){
    if (row!=col) {
        cout<<"Lỗi kích thước, ma trận phải cùng cấp";
        exit(0);
    }
}
void kiemtra2matrancungcap(int row1, int col1, int row2, int col2){
    if (row1 != row2 || col1 != col2) {
        cout << "Lỗi kích thước không thực hiện phép tính được" << '\n';
        exit(0);
    }
}
void congmatran(float A[max][max], float B[max][max], int row, int col)
{
    float C[max][max];
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    xuatmatran(C, row, col);
}

void trumatran(float A[max][max], float B[max][max], int row, int col)
{
    float C[max][max];
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    xuatmatran(C, row, col);
}
void nhanmatran(float A[max][max],float B[max][max],int row1, int col1,int row2,int col2){
    float C[max][max];
    if (col1!=row2) {
        cout<<"Muốn nhân 2 ma trận bắt buộc cột của ma trận 1 phải bằng dòng của ma trận 2";
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
void chuyenthanhmatrantamgiac(float M[max][max],int row){
    float temp;
    for(int i=1; i<row; i++){
        for(int j=i+1; j<row+1; j++){
            temp=M[j][i]/M[i][i];
            for(int k=i; k<row+1; k++){
                M[j][k]-=temp*M[i][k];
            }
        }
    }
}
void dinhthucmatran(float M[max][max],int row,int col){
    chuyenthanhmatrantamgiac(M, row);
    double temp = 1;
    for(int i = 0; i<row; i++)
      temp*=M[i][i];
    cout<<"Định thức ma trận = "<<temp;
}
