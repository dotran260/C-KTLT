#include"Header.h"
void main() {
	MaTran a;

	if (docMaTran(a, "mt.txt") == 1) {
		xuatMaTran(a);
		cout<<"tinhTongPhanTuMinMoiDong: "<<tinhTongPhanTuMinMoiDong(a);
		cout << "tinhTichCotMot: " << tinhTichCotMot(a);
		xuatDuongCheoChinh(a);
		xuatDuongCheoPhu(a);
		cout << "\n tinhTongCheoPhu: " << tinhTongCheoPhu(a);
		if (kiemTraMaTran(a) == true) {
			cout << "\n Duong cheo phu khong co so am";
		}
		else {
			cout << "\n Duong cheo phu CO so am"; 
		}
		cout << "\nMax la:" << timMax(a) << endl;
		cout << "\ntinhTongPhanTuMinMoiCot"<<tinhTongPhanTuMinMoiCot(a) << endl;
		if (kiemtradoixung(a) == 1)
			cout << " ma tran co doi xung qua duong cheo chinh";
		else
			cout << " ma tran khong doi xung qua duong cheo chinh";
		//hoanvidong(a, 0, 1);
		//xuatMaTran(a);
	}
	else {
		cout << "Loi";
	}

	system("pause");
}