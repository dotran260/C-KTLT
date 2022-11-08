#include"Header.h"

int docMaTran(MaTran &mt, const char *filename)
{
	FILE *fp;
	fp = fopen(filename, "r");
	if (fp != NULL) {
		fscanf(fp, "%d", &mt.n);//đọc số dòng
		fscanf(fp, "%d", &mt.m); //đọc số cột
		for (int i = 0; i < mt.n; i++)
			for (int j = 0; j < mt.m; j++)
				fscanf(fp, "%d", &mt.a[i][j]);
		fclose(fp); //đóng tập tin
		return 1;
	}
	return 0;
}

void xuatMaTran(MaTran mt) {
	for (int i = 0; i < mt.n; i++) {
		for (int j = 0; j < mt.m; j++)
			cout << mt.a[i][j] << "\t";
		cout << endl;
	}
}

void xuatDuongCheoChinh(MaTran mt) {
	cout << "\n Xuat cac phan tu tren cheo Chinh:";
	for (int i = 0; i < mt.n; i++)
		cout << mt.a[i][i] << " ";
}

void xuatDuongCheoPhu(MaTran mt) {
	cout << "\n Xuat cac phan tu tren cheo phu:";
	for (int i = 0; i < mt.n; i++)
		cout << mt.a[i][mt.n - i - 1] << " ";
}

void xuatDongMot(MaTran mt) {
	cout << "\n Xuat cac phan tu tren cheo phu:";
	for (int i = 0; i < mt.m; i++)
		cout << mt.a[0][i] << " ";
}

void xuatMinCot(MaTran mt) {
	int min;
	min = mt.a[0][0];
	int j = 0;
	while (j < mt.m)
	{
		min = mt.a[0][j];
		for (int i = 0; i < mt.n; i++)
		{

			if (mt.a[i][j] < min)
			{
				min = mt.a[i][j];
			}
		}
		cout << min << " ";
		j++;
	}
}
void xuatTamGiacTrenDuongCheoPhu(MaTran mt) {
	for (int i = 0; i < mt.n; i++) {
		for (int j = 0; j < mt.m; j++)
			if (i + j <= mt.n - 1)
				cout << mt.a[i][j] << "\t";
		cout << endl;
	}
}
void xuatTamGiacDuoiDuongCheoPhu(MaTran mt) {
	for (int i = 0; i < mt.n; i++) {
		for (int j = 0; j < mt.m; j++)
			if (i + j >= mt.n - 1)
				cout << mt.a[i][j] << "\t";
		cout << endl;
	}
}

void xuatTamGiacTrenDuongCheoChinh(MaTran mt) {
	for (int i = 0; i < mt.n; i++) {
		for (int j = 0; j < mt.m; j++)
			if (i <= j)
				cout << mt.a[i][j] << "\t";
		cout << endl;
	}
}

void xuatTamGiacDuoiDuongCheoChinh(MaTran mt) {
	for (int i = 0; i < mt.n; i++) {
		for (int j = 0; j < mt.m; j++)
			if (i >= j)
				cout << mt.a[i][j] << "\t";
		cout << endl;
	}
}

//Kiểm tra đường chéo phụ có số âm hay không.
bool kiemTraMaTran(MaTran mt) {
	bool flag = true;
	for (int i = 0; i < mt.n; i++)
		if (mt.a[i][mt.n - i - 1] < 0)
			flag = false;
	return flag; //true:+ false:-
}

//Viết hàm bool kiemTra_Boi3 dùng để kiểm tra có tổn tại phần tử là bội của 3 trên  đường chéo phụ hay không, nếu tồn tại thì trả về true, ngược lại trả về false.
bool kiemTraBoi3(MaTran mt) {
	bool flag = false;
	for (int i = 0; i < mt.n; i++)
		if (mt.a[i][mt.n - i - 1] % 3 == 0)
			flag = true;
	return flag;
}

int kiemtradoixung(MaTran& mt)
{
	int k, j;
	for (k = 0; k < mt.n; k++)
		for (j = 0; j < mt.n && mt.a[k][j] == mt.a[j][k]; j++);
	return k == j;
}

int timMax(MaTran mt) {
	int MAX = mt.a[0][0];
	for (int i = 0; i < mt.n; i++)
		for (int j = 0; j < mt.n; j++)
			if (mt.a[i][j] > MAX)
				MAX = mt.a[i][j];
	return MAX;
}

int timMin(MaTran mt) {
	int MIN = mt.a[0][0];
	for (int i = 0; i < mt.n; i++)
		for (int j = 0; j < mt.n; j++)
			if (mt.a[i][j] < MIN)
				MIN = mt.a[i][j];
	return MIN;
}

//Viết hàm tính tổng các phần tử lớn nhất trên mỗi dòng.
int tinhTongPhanTuMaxMoiDong(MaTran mt) {
	int s = 0;
	for (int i = 0; i < mt.n; i++)
	{
		int max = mt.a[i][0];
		for (int j = 1; j < mt.m; j++)
			if (mt.a[i][j] > max)
				max = mt.a[i][j];
		s += max;
	}
	return s;
}

int tinhTongPhanTuMinMoiDong(MaTran mt) {
	int s = 0;
	for (int i = 0; i < mt.n; i++)
	{
		int min = mt.a[i][0];
		for (int j = 1; j < mt.m; j++)
			if (mt.a[i][j] < min){
				min = mt.a[i][j];
			}
		cout << min;
		s += min;
	}
	return s;
}

int tinhTongPhanTuMinMoiCot(MaTran mt) {
	int s = 0;
	int min;
	min = mt.a[0][0];
	int j = 0;
	while (j < mt.m)
	{
		min = mt.a[0][j];
		for (int i = 0; i < mt.n; i++)
		{

			if (mt.a[i][j] < min)
			{
				min = mt.a[i][j];
			}
		}
		s += min;
		j++;
	}
	return s;
}

int tinhTichCotMot(MaTran mt) {
	int result = 1;
	for (int i = 0; i < mt.n; i++) {
		result *= mt.a[i][0];
		cout << endl;
	}
	return result;
}

int tinhTongCheoPhu(MaTran mt) {
	int tong = 0;
	for (int i = 0; i < mt.n; i++)
		tong += mt.a[i][mt.n - i - 1];
	return tong;
}



//Viết hàm tìm phần tử lớn nhất tại dòng k của mảng 2 chiều.
int timMaxDong(MaTran mt) {
	int k;
	cout << "\nNhap so dong k: ";
	cin >> k;
	int MAX = mt.a[0][0];
	for (int i = 0; i < mt.n; i++)
		for (int j = 0; j < mt.n; j++)
			if (mt.a[k][j] > MAX)
				MAX = mt.a[k][j];
	return MAX;
}

int timMinDong(MaTran mt) {
	int k;
	cout << "\nNhap so dong k: ";
	cin >> k;
	int MIN = mt.a[k][0];
	for (int j = 0; j < mt.n; j++)
		if (mt.a[k][j] < MIN)
			MIN = mt.a[k][j];
	return MIN;
}

int tinhTongAll(MaTran mt) {
	int tongDong = 0;
	for (int i = 0; i < mt.n; i++) {
		for (int j = 0; j < mt.n; j++)
			tongDong += mt.a[i][j];
	}
	return tongDong;
}

int tinhTongBien(MaTran& mt)
{
	int s = 0;
	for (int i = 0; i < mt.m; i++)
	{
		s += mt.a[i][0] + mt.a[i][mt.n - 1];
	}
	for (int j = 1; j < mt.n - 1; j++)
	{
		s += mt.a[0][j] + mt.a[mt.m - 1][j];
	}
	return s;
}


// thay thế các số Âm có trong ma trận bằng phần tử bất kỳ được truyền vào trong hàm.
void thayThe(MaTran& mt) {
	int k;
	cout << "\nNhap phan tu can thay the";
	cin >> k;
	for (int i = 0; i < mt.n; i++)
		for (int j = 0; j < mt.m; j++)
			if (mt.a[i][j] < 0)
				mt.a[i][j] = k;
}
void hoanvi(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void hoanvicot(MaTran& mt, int c1, int c2)
{
	if ((c1 >= 0 && c1 < mt.m) && (c2 >= 0 && c2 < mt.m))
	{
		for (int i = 0; i < mt.n; i++)
			hoanvi(mt.a[i][c1], mt.a[i][c2]);
	}
	xuatMaTran(mt);
}

void hoanvidong(MaTran& mt, int d1, int d2)
{
	if ((d1 >= 0 && d1 < mt.n) && (d2 >= 0 && d2 < mt.n))
	{
		for (int j = 0; j < mt.m; j++)
			hoanvi(mt.a[d1][j], mt.a[d2][j]);
	}
	xuatMaTran(mt);
}

void xoacot(MaTran& mt)
{
	int c;
	cout << "\nNhap cot can xoa";
	cin >> c;
	if (c >= 0 && c < mt.m)
	{
		for (int i = 0; i < mt.n; i++)
			for (int j = c; j < mt.m - 1; j++)
				mt.a[i][j] = mt.a[i][j + 1];
		mt.m--;
	}
	xuatMaTran(mt);
}
void xoadong(MaTran& mt)
{
	int d;
	cout << "\nNhap cot can xoa";
	cin >> d;
	if (d >= 0 && d < mt.n)
	{
		for (int i = d; i < mt.n - 1; i++)
			for (int j = 0; j < mt.m; j++)
				mt.a[i][j] = mt.a[i + 1][j];
		mt.n--;
	}
	xuatMaTran(mt);
}
//////////////
void searchX(DAYSO ds) {
	cout << "\n===========TIM PHAN TU===========" << endl;
	int x;
	cout << "\nNhap gia tri muon tim:";
	cin >> x;
	for (int i = 0; i < ds.n; i++) {
		//cout << ds.a[i] << " ";
		if (ds.a[i] == x){
			cout << "\nCo Trong Danh Sach!";
			return;
		}		
	}
	cout << "\nKhong tim thay trong danh sach!";
}

int ktSNT(int n) {
	int dem = 0;
	for (int i=1; i <= n; i++) {
		if (n%i == 0) {
			dem++;
		}
	}
	return dem;
}

bool ktSHT(int n) {
	int dem = 0;
	for (int i = 1; i <= n/2; i++) {
		if (n%i == 0) {
			dem+=i;
		}
	}
	if (dem == n) 
		return true;
	return false;
}

