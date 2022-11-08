#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct MaTran {
	int a[10][10];
	int n; //dong
	int m; //cot
};
struct MaTranVuong {
	int a[10][10];
	int n; //dong
};

int docMaTran(MaTran &mt, const char *filename);
void xuatMaTran(MaTran mt);
void xuatDuongCheoChinh(MaTran mt);
void xuatDuongCheoPhu(MaTran mt);
void xuatMinCot(MaTran mt);
void xuatTamGiacTrenDuongCheoChinh(MaTran mt);
void xuatTamGiacDuoiDuongCheoChinh(MaTran mt);
void xuatDongMot(MaTran mt);
bool kiemTraMaTran(MaTran mt);
int kiemtradoixung(MaTran& mt);
bool kiemTraBoi3(MaTran mt);

int tinhTongAll(MaTran mt);
int tinhTongPhanTuMaxMoiDong(MaTran mt);
int tinhTongPhanTuMinMoiDong(MaTran mt);
int tinhTongPhanTuMinMoiCot(MaTran mt);
int tinhTichCotMot(MaTran mt);
int tinhTongCheoPhu(MaTran mt);
int tinhTongBien(MaTran& mt);

int timMax(MaTran mt);
int timMin(MaTran mt);
int timMaxDong(MaTran mt);
int timMinDong(MaTran mt);

void thayThe(MaTran& mt);
void hoanvicot(MaTran& mt, int c1, int c2);
void hoanvidong(MaTran& mt, int d1, int d2);

void xoacot(MaTran& mt);