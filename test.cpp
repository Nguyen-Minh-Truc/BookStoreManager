#include <iostream>
#include <string>
using namespace std;

struct danhsachmathang {
  int stt, masach, sltonkho, dongia, thanhtien, dongiaban;
  string tenmathang;
};

void nhapmathang(danhsachmathang ds[], int &n) {
  int i = 0;
  while (i < n) {
    ds[i].stt = i + 1;
    cout << "stt:   " << ds[i].stt << endl;

    cout << "nhap ma sach " << endl;
    cin >> ds[i].masach;

    cout << "nhap ten sach " << endl;
    cin.ignore();
    getline(cin, ds[i].tenmathang);

    cout << "so luong ton kho" << endl;
    cin >> ds[i].sltonkho;

    cout << " don gia     " << endl;
    cin >> ds[i].dongia;

    ds[i].thanhtien = ds[i].sltonkho * ds[i].dongia;
    cout << "thanh tien: " << ds[i].thanhtien << endl;

    cout << "don gia ban: " << endl;
    cin >> ds[i].dongiaban;

    i++;
  }
}

void xuatmathang(danhsachmathang ds[], int &n) {
  cout << "danh sach mat hang: " << endl;
  for (int i = 0; i < n; i++) {
    cout << "stt:                " << ds[i].stt << endl;

    cout << "-  ma sach:                      " << ds[i].masach
         << "       ten sach:       " << ds[i].tenmathang << endl;
    cout << "-  so luong ton kho:             " << ds[i].sltonkho
         << "      don gia:        " << ds[i].dongia << endl;
    cout << "-  thanh tien:                   " << ds[i].thanhtien << endl;
    cout << "-  don gia ban:                  " << ds[i].dongiaban << endl;
  }
}
void tonkho(danhsachmathang ds[], int &n) {
  int sum = 0, tem = 0;
  for (int i = 0; i < n; i++) {
    tem += ds[i].sltonkho;
    sum += ds[i].dongia * ds[i].sltonkho;
  }
  cout << "so luong: " << tem << endl;
  cout << "so tien: " << sum << endl;
}

void sapxepmathang(danhsachmathang ds[], int &n) {
  for (int i = 1; i < n; i++) {
    danhsachmathang mathang = ds[i];
    int j = i - 1;
    while (j >= 0 && ds[j].dongiaban < mathang.dongiaban) {
      ds[j + 1] = ds[j];
      j--;
    }
    ds[j + 1] = mathang;
  }
  cout << "danh sach da duoc sap xep: " << endl;

  for (int i = 0; i < n; i++) {
    cout << "stt:                " << ds[i].stt << endl;

    cout << "-  ma sach:                      " << ds[i].masach
         << "       ten sach:       " << ds[i].tenmathang << endl;
    cout << "-  so luong ton kho:             " << ds[i].sltonkho
         << "      don gia:        " << ds[i].dongia << endl;
    cout << "-  thanh tien:                   " << ds[i].thanhtien << endl;
    cout << "-  don gia ban:                  " << ds[i].dongiaban << endl;
  }
}

void xoasach(danhsachmathang ds[], int &n) {
  int index;
  cout << "nhap ma can  xoa: " << endl;
  cin >> index;

  if (index < 0 || index > n) {
    cout << "khong co ma sach nay." << endl;
    return;
  }
 for (int i = index; i < n - 1; i++) {
    index = ds[i + 1].masach;
  }
  n--;
  cout << "ma sach " << index << " da duoc xoa"<<endl;

}
int menu() {
  cout << "--------------------------------------------------------------"
       << endl;
  cout << "| 1. nhập mặt hàng                                           |"
       << endl;
  cout << "| 2. thêm mặt hàng                                           |"
       << endl;
  cout << "| 3. xoá mặt hàng                                            |"
       << endl;
  cout << "| 4. sắp xếp mặt hàng theo chiều giảm dần của giá bán        |"
       << endl;
  cout << "| 5. tổng giá trị tồn tho                                    |"
       << endl;
  cout << "| 6. xuất mặt hàng                                           |"
       << endl;
  cout << "| 0. Exit                                                    |"
       << endl;
  cout << "--------------------------------------------------------------"
       << endl;

  int choice;
  cin >> choice;
  return choice;
}
void themmathang(danhsachmathang ds[], int &n) {
  int i;
  cout << "nhập vị trí cần thêm: ";
  cin >> i;

  if (i < 1 || i > n + 1) {
    cout << "Không tồn tại vị trí này." << endl;
    return;
  }

  if (n >= 1000) {
    cout << "Danh sách đã đầy. Không thể thêm mặt hàng mới." << endl;
    return;
  }

  danhsachmathang newmathang;
  newmathang.stt = i;
  cout << "stt:   " << newmathang.stt << endl;

  cout << "nhap ma sach: " << endl;
  cin >> newmathang.masach;

  cout << "nhap ten sach: " << endl;
  cin.ignore();
  getline(cin, newmathang.tenmathang);

  cout << "so luong ton kho: " << endl;
  cin >> newmathang.sltonkho;

  cout << "don gia: " << endl;
  cin >> newmathang.dongia;

  newmathang.thanhtien = newmathang.sltonkho * newmathang.dongia;
  cout << "thanh tien: " << newmathang.thanhtien << endl;

  cout << "don gia ban: " << endl;
  cin >> newmathang.dongiaban;

  for (int j = n; j >= i; j--) {
    ds[j] = ds[j - 1];
  }

  ds[i - 1] = newmathang;
  n++;
}
int main() {
  danhsachmathang ds[1000];
  int n = 0;
  cout << "Nhap so luong sach :";
  cin >> n;

  while (true) {
    int choice = menu();

    switch (choice) {
    case 1:
      nhapmathang(ds, n);
      break;
    case 2:
     themmathang(ds,n);
      break;
    case 3:

      xoasach(ds, n);
      break;
    case 4:

      sapxepmathang(ds, n);
      break;
    case 5:

      tonkho(ds, n);
      break;
    case 6:

      xuatmathang(ds, n);
      break;
    case 0:

      return 0;
    default:

      break;
    }
  }
  return 0;
}


