#include "iostream"
#include "cstring"
#include "iomanip"
#include "time.h"
#include "stdio.h"
#include "conio.h"
#include "windows.h"
using namespace std;
 
 
 
long total_book = 0;        // Tong sach cua thu vien.
long total_bill = 0;
long total = 0;
char ma_tam[50];
int i, p;
int info[10];
 
 
////===============================================================================================
//                                                                                                
//  KHAI BAO CAC STRUCT.  
//
////===============================================================================================
 
struct n_DATE {
    int n_day;
    int n_month;
    int n_year;
};
 
struct BOOK {
    char b_ma[50];
    char b_tensach[50];
    char b_tacgia[50];
    char b_theloai[50];
    char b_nhaXB[50];  
    int b_soluong; 
};
 
struct BILL {  
    char bill_tenSV[50];
    char bill_maSV[50];
    n_DATE bill_ngaymuon;
};
 
struct BILL_DETAIL {
    char detail_maSV[50];
    char detail_maSach[50];
    char detail_tenSach[50];
    char b_trachua[50];             // Tinh trang tra hay chua.
    char b_moi_cu[50];              // Tinh trang moi hay cu.
};
 
 
 
typedef BOOK LIST_BOOK[100];                    // Kieu LIST_BOOK la mang 100 cuon sach.
typedef BILL LIST_BILL[100];                    // Kieu LIST_BILL la mang 100 phieu muon.
typedef BILL_DETAIL LIST_DETAIL[100];           // Kieu LIST_DETAIL la mang 100 chi tiet phieu muon.
 
 
LIST_BOOK lst_book;             // Bien lst_book la mang 50 cuon sach.
LIST_BILL lst_bill;             // Bien lst_bill la mang 50 phieu muon.
LIST_DETAIL lst_detail;         // Bien lst_detail la mang 50 chi tiet phieu muon.
 
 
////===============================================================================================
//
//  KHAI BAO MAU CHO HAM.
//
////===============================================================================================
 
    int days_in_month(int, int);
//-----------------------------------------------
    void phieu_load_file();
    void phieu_save_file();
    void phieu_nhap();
    void phieu_xuat();
    void phieu_them();
    void phieu_xoa();
    int  phieu_tim(char ma_tam[]);
    void phieu_hieu_chinh();
//-----------------------------------------------
    void ctphieu_nhap();
    void ctphieu_xuat();
    void ctphieu_load_file();
    void ctphieu_save_file();
//-----------------------------------------------
    void sach_load_file();
    void sach_save_file(); 
    void sach_nhap();
    void sach_xuat();
    void sach_hieu_chinh();
    void sach_them();
    void sach_xoa();
    int  sach_tim(char ma_tam[]);
//-----------------------------------------------
    void TK_theloai();
    void TK_SV_qua_han();           // Sinh vien muon qua han.
    void TK_tan_suat_muon();        // Tan suat muon cua moi cuon sach.
    void TK_soluong_sach();
//-----------------------------------------------
    void file_info();
    void interface_main();
    void interface_book_manager();
    void interface_bill_manager();
    void interface_bill_detail_manager();
 
 
 
//// CHUONG TRINH CHINH.
////===============================================================================================
////===============================================================================================
//                                                                                              //         
    int main()                                                                                //
    {                                                                                           //
        interface_main();                                                                       // 
    }                                                                                           //
//                                                                                              // 
////===============================================================================================
////===============================================================================================
 
 
////===============================================================================================
//
//  DAY DUNG CAC HAM TO CHUC MENU.
//
////===============================================================================================
 
 
void interface_book_manager() {
begin:
    //system("cls");
    cout << endl << endl;
    cout << "               +-------------------------------------------------+ \n";
    cout << "               |      GIAO DIEN QUAN LY SACH TRONG THU VIEN      | \n";
    cout << "               |-------------------------------------------------| \n";
    cout << "               |                                                 | \n";
    cout << "               |  1. Nhap sach vao thu vien.                     | \n";
    cout << "               |  2. Xoa sach khoa thu vien.                     | \n";
    cout << "               |  3. Xuat Danh sach sach.                        | \n";
    cout << "               |                                                 | \n";
    cout << "               |  4. Them sach vao thu vien.                     | \n";
    cout << "               |  5. Tim sach trong Thu vien.                    | \n";
    cout << "               |  6. Hieu chinh sach.                            | \n";
    cout << "               |                                                 | \n";
    cout << "               |  7. Back.                                       | \n";
    cout << "               |                                                 | \n";
    cout << "               +-------------------------------------------------+ \n";
 
    char chon;
    bool k = true;
   
    do
    {   if (k == false)
            cout << "Hay chon cong viec theo so tu 1 den 3 :";
        else
            cout << "Chon cong viec theo so: "; cin >> chon;
        k = false;
    } while ((chon < '1') || (chon > '7'));
 
 
    switch (chon) {
        case '1':   sach_nhap();
                    break;
        case '2':
                    sach_xoa();
                    break;
        case '3':                  
                    sach_xuat();
                    break;
        case '4':
                    sach_them();
                    break;
        case '5':              
                    cin.ignore();
                    cout << "Nhap ma sach can tim : "; cin.getline(ma_tam, 50);
   
                    i = sach_tim(ma_tam);
 
                    if (i == 0)
                        cout << "- Khong tim thay sach co ma so tren. ";
                    else {
                        cout << "\nDa tim thay sach: \n";
                        cout << setw(13) << ".Ma Sach" << setw(13) << "Ten Sach" << setw(13) << "The Loai" << setw(13) << "So Luong" << endl << endl;
                        cout << setw(13) << lst_book[i].b_ma << setw(13) << lst_book[i].b_tensach << setw(13) << lst_book[i].b_theloai << setw(13) << lst_book[i].b_soluong;
                        cout << endl;
                    }
                    break;
        case '6':
                    sach_hieu_chinh();
                    break;
        case '7':
                    goto end;
                    break;
    }
    goto begin;
end:;
}
 
void interface_bill_manager() {
begin:
    //system("cls");
    cout << endl << endl;
    cout << "               +-------------------------------------------------+ \n";
    cout << "               |      GIAO DIEN QUAN LY PHIEU MUON SACH          | \n";
    cout << "               |-------------------------------------------------| \n";
    cout << "               |                                                 | \n";
    cout << "               |  1. Nhap Phieu.                                 | \n";
    cout << "               |  2. Them Phieu.                                 | \n";
    cout << "               |  3. Xoa Phieu.                                  | \n";
    cout << "               |                                                 | \n";
    cout << "               |  4. Xuat Phieu.                                 | \n";
    cout << "               |  5. Hieu chinh Phieu.                           | \n";
    cout << "               |  6. Tim Phieu.                                  | \n";
    cout << "               |                                                 | \n";
    cout << "               |  7. Back.                                       | \n";
    cout << "               |                                                 | \n";
    cout << "               +-------------------------------------------------+ \n";
 
    char chon;
    bool k = true;
   
    do
    {   if (k == false)
            cout << "Hay chon cong viec theo so tu 1 den 3 :";
        else
            cout << "Chon cong viec theo so: "; cin >> chon;
        k = false;
    } while ((chon < '1') || (chon > '7'));
 
 
    switch (chon) {
        case '1':   system("cls");
                    phieu_nhap();
                    break;
        case '2':
                    system("cls");
                    phieu_them();
                    break;
        case '3':                  
                    phieu_xoa();
                    break;
        case '4':
                    system("cls");
                    phieu_xuat();
                    break;
        case '5':
                    system("cls");
                    phieu_hieu_chinh();
                    break;
        case '6':      
                    cin.ignore();
                    cout << "Nhap ma phieu (Ma SV) can tim : "; cin.getline(ma_tam, 50);
   
                    i = phieu_tim(ma_tam);
 
                    if (i == 0)
                        cout << "- Khong tim thay phieu co ma so tren. ";
                    else {
                        cout << "\nDa tim thay phieu: \n";
                        cout << setw(15) << ".Ma Phieu/ Ma SV" << setw(15) << "Ten SV" << endl << endl;
                        cout << setw(15) << lst_bill[i].bill_maSV << setw(15) << lst_bill[i].bill_tenSV;
                        cout << endl;
                    }
                    break;
        case '7':
                    goto end;
                    break;
    }
    goto begin;
end:;
}
 
void interface_bill_detail_manager() {
    begin:
    //system("cls");
    cout << endl << endl;
    cout << "               +-------------------------------------------------+ \n";
    cout << "               |     GIAO DIEN QUAN LY CHI TIET PHIEU MUON       | \n";
    cout << "               |-------------------------------------------------| \n";
    cout << "               |                                                 | \n";
    cout << "               |  1. Nhap Chi Tiet Phieu.                        | \n";
    cout << "               |                                                 | \n";
    cout << "               |  2. Xuat Chi Tiet Phieu.                        | \n";   
    cout << "               |                                                 | \n";
    cout << "               |  3. Back.                                       | \n";
    cout << "               |                                                 | \n";
    cout << "               +-------------------------------------------------+ \n";
 
    char chon;
    bool k = true;
   
    do
    {   if (k == false)
            cout << "Hay chon cong viec theo so tu 1 den 3 :";
        else
            cout << "Chon cong viec theo so: "; cin >> chon;
        k = false;
    } while ((chon < '1') || (chon > '3'));
 
 
    switch (chon) {
        case '1':   system("cls");
                    ctphieu_nhap();
                    break;
        case '2':
                    system("cls");
                    ctphieu_xuat();
                    break;
        case '3':
                    goto end;
                    break;
    }
    goto begin;
end:;
}
   
void interface_main() {
begin:
    system("cls");
    cout << endl << endl;
    cout << "                SV : VUONG NGOC NAM _________________ LOP: CN08-B  \n";
    cout << "               +=================================================+ \n";
    cout << "               |         CHUONG TRINH QUAN LY THU VIEN           | \n";
    cout << "               |-------------------------------------------------| \n";
    cout << "               |                                                 | \n";
    cout << "               |  1. Quan ly sach trong Thu vien.                | \n";
    cout << "               |  2. Quan ly phieu ban doc  .                    | \n";
    cout << "               |  3. Quan ly Chi tiet phieu muon sach.           | \n";
    cout << "               |                                                 | \n";
    cout << "               |  4. Thong ke sach theo the loai.                | \n";
    cout << "               |  5. Thong ke doc gia muon qua han               | \n";
    cout << "               |                                                 | \n";
    cout << "               |  6. Exit.                                       | \n";
    cout << "               |                                                 | \n";
    cout << "               +-------------------------------------------------+ \n";
 
    char chon;
    bool k = true;
 
    do
    {   if (k == false)
            cout << "Hay chon cong viec theo so tu 1 den 3 :";
        else
            cout << "Chon cong viec theo so: "; cin >> chon;
        k = false;
    } while ((chon < '1') || (chon > '7'));
 
 
 
    switch (chon) {
        case '1':
                    system("cls");
                    interface_book_manager();
                    break;
        case '2':
                    system("cls");
                    interface_bill_manager();
                    break;
        case '3':
                    system("cls");
                    interface_bill_detail_manager();
                    break;
        case '4':
                    system("cls");
                    TK_theloai();
                    break;
        case '5':
                    system("cls");
                    TK_SV_qua_han();
                    break;
        case '6':
                    goto end;
                    break;
    }
    goto begin;
end:;
 
}
 
 
////===============================================================================================
//
//  DINH NGHIA CAC HAM.
//
////===============================================================================================
 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DINH NGHIA HAM CHO DOI TUONG SACH.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
void file_info() {
    FILE * f_b;
    info[0] = total_book;
    info[1] = total_bill;
    info[2] = total;
    f_b = fopen("file_info", "wb");
    fwrite(info, sizeof(info), 1, f_b);
    fclose(f_b);
}
void sach_load_file() {
    FILE * f_b;
    f_b = fopen("book_file", "rb");
    fread(lst_book, sizeof(lst_book), 1, f_b);
    fclose(f_b);
}
 
void sach_save_file() {
    FILE * f_b;
    f_b = fopen("book_file", "wb");
    fwrite(lst_book, sizeof(lst_book), 1, f_b);
    fclose(f_b);
}
 
int sach_tim(char ma_tam[]) {
    int jump = 1;
    while ((jump <= total_book) && (strcmp(lst_book[jump].b_ma, ma_tam) != 0))
        jump++;
   
    if (jump > total_book)
        return 0;
    else
        return jump;
}
 
void sach_nhap() {
    char ma_tam[50];
 
    cout << endl;
    cout << "NHAP SACH. \n";
    cout << "Hay nhap tong so luong sach se nhap : "; cin >> total_book;
    cout << endl;
 
    for (int i = 1; i <= total_book; i++) {
    nhap_ma:;
        cin.ignore(1);
        cout << ". Ma Sach: "; cin.getline(ma_tam, 50);
 
        if (sach_tim(ma_tam) != 0) {
            cout << "   Ma sach da ton tai.";
            cout << "   Nhan Enter de nhap lai !";
            goto nhap_ma;
        }
 
        //cin.ignore(1);
        strcpy(lst_book[i].b_ma, ma_tam);
        cout << ". Ten Sach : "; cin.getline(lst_book[i].b_tensach, 50);
        cout << ". Tac Gia  : "; cin.getline(lst_book[i].b_tacgia, 50);
        cout << ". The Loai : "; cin.getline(lst_book[i].b_theloai, 50);
        cout << ". Nha XB   : "; cin.getline(lst_book[i].b_nhaXB, 50);
        cout << ". So Luong : "; cin >> lst_book[i].b_soluong;
        cin.ignore();
        cout << endl;
    }
    sach_save_file();
    file_info();
}
 
void sach_xoa() {
    char ma_tam[50];
 
    cin.ignore();
    cout << "Nhap ma sach can xoa : "; cin.getline(ma_tam, 50);
   
    i = sach_tim(ma_tam);
 
    if (i == 0)
        cout << "- Khong tim thay sach co ma so tren. ";
    else {
        for (int j = i; j <= total_book; j++)
            lst_book[j] = lst_book[j+1];
 
        total_book = total_book - 1;
        cout << "- Da xoa.";
    }
    sach_save_file();
    file_info();
}
 
void sach_xuat() {
    sach_load_file();
 
    cout << "\n                      DANH SACH SACH TRONG THU VIEN           \n \n";
    cout << setw(13) << ".Ma Sach" << setw(13) << "Ten Sach" << setw(13) << "The Loai" << setw(13) << "So Luong" << endl << endl;
    for(int i = 1; i <= total_book; i++) {
        cout << setw(13) << lst_book[i].b_ma << setw(13) << lst_book[i].b_tensach << setw(13) << lst_book[i].b_theloai << setw(13) << lst_book[i].b_soluong;
        cout << endl;
    }
}
 
void sach_them() {
    char ma_tam[50];
 
    total_book = total_book + 1;
    cout << "THEM SACH. \n";
    nhap_ma:;
        cin.ignore(1);
        cout << ". Ma Sach: "; cin.getline(ma_tam, 50);
 
        if (sach_tim(ma_tam) != 0) {
            cout << "   Ma sach da ton tai. Hay nhap lai!";
            goto nhap_ma;
        }
 
        //cin.ignore(1);
        cout << ". Ten Sach : "; cin.getline(lst_book[i].b_tensach, 50);
        cout << ". Tac Gia  : "; cin.getline(lst_book[i].b_tacgia, 50);
        cout << ". The Loai : "; cin.getline(lst_book[i].b_theloai, 50);
        cout << ". Nha XB   : "; cin.getline(lst_book[i].b_nhaXB, 50);
        cout << ". So Luong : "; cin >> lst_book[i].b_soluong;
        cout << endl;
 
 
    sach_save_file();
    file_info();
}
 
void sach_hieu_chinh() {
    char ma_tam[50];
 
    cin.ignore();
    cout << "Nhap ma sach can hieu chinh : "; cin.getline(ma_tam, 50);
       
    i = sach_tim(ma_tam);
 
    if (i == 0)
        cout << "- Khong tim thay sach co ma so tren. ";
    else {
        //cin.ignore();
        cout << ". Ma Sach  : "; cin.getline(lst_book[i].b_ma, 50);
        cout << ". Ten Sach : "; cin.getline(lst_book[i].b_tensach, 50);
        cout << ". Tac Gia  : "; cin.getline(lst_book[i].b_tacgia, 50);
        cout << ". The Loai : "; cin.getline(lst_book[i].b_theloai, 50);
        cout << ". Nha XB   : "; cin.getline(lst_book[i].b_nhaXB, 50);
        cout << ". So Luong : "; cin >> lst_book[i].b_soluong;
        cout << endl;
    }
    sach_save_file();
}
 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DINH NGHIA HAM CHO DOI TUONG PHIEU.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
void phieu_load_file() {
    FILE *f_b;
    f_b = fopen("bill_file","rb");
    fread(lst_bill, sizeof(lst_bill), 1, f_b);
    fclose(f_b);
}
 
void phieu_save_file() {
    FILE * f_b;
    f_b = fopen("bill_file", "wb");
    fwrite(lst_bill, sizeof(lst_bill), 1, f_b);
    fclose(f_b);
}
 
int phieu_tim(char ma_tam[]) {
    int jump = 1;
 
    while ((jump <= total_bill) && (strcmp(lst_bill[jump].bill_maSV, ma_tam) != 0))
        jump++;
   
    if (jump > total_bill)
        return 0;
    else
        return jump;
 
}
 
void phieu_nhap() {
    char ma_tam[50];
 
    cout << "Day la lan dang ki phieu muon dau tien. \n";
    cout << "Hay nhap tong so luong phieu muon se duoc dang ki : "; cin >> total_bill;
    cout << endl;
 
    for (int i = 1; i <= total_bill; i++) {
    nhap_ma:;
        cin.ignore();
        cout << ". Ma Phieu: "; cin.getline(ma_tam, 50);
 
        if (phieu_tim(ma_tam) != 0) {
            cout << "   Ma Phieu nay da ton tai. Hay nhap lai!";
            goto nhap_ma;
        }
 
        //cin.ignore();
        strcpy(lst_bill[i].bill_maSV, ma_tam);
        cout << ". Ten Sinh Vien : "; cin.getline(lst_bill[i].bill_tenSV, 50);
 
        cout << ". Ngay Muon     : \n";
        cout << " \tNgay "; cin >> lst_bill[i].bill_ngaymuon.n_day;
        cout << " \tThang: "; cin >> lst_bill[i].bill_ngaymuon.n_month;
        cout << " \tNam: "; cin >> lst_bill[i].bill_ngaymuon.n_year;
        cout << endl;
    }
    phieu_save_file();
    file_info();
}
 
void phieu_them() {
    char ma_tam[50];
 
    total_bill = total_bill + 1;
 
    nhap_ma:;
        cin.ignore();
        cout << ". Ma Phieu: "; cin.getline(ma_tam, 50);
 
        if (phieu_tim(ma_tam) != 0) {
            cout << "   Ma sach da ton tai. Hay nhap lai!";
            goto nhap_ma;
        }
 
        //cin.ignore();
        strcpy(lst_bill[i].bill_maSV, ma_tam);
        cout << ". Ten Sinh Vien : "; cin.getline(lst_bill[i].bill_tenSV, 50);
 
        cout << ". Ngay Muon     : \n";
        cout << " Ngay "; cin >> lst_bill[i].bill_ngaymuon.n_day;
        cout << " thang: "; cin >> lst_bill[i].bill_ngaymuon.n_month;
        cout << " nam: "; cin >> lst_bill[i].bill_ngaymuon.n_year;
        cout << endl;
 
    phieu_save_file();
    file_info();
}
 
void phieu_xoa() {
    char ma_tam[50];
 
    cin.ignore();
    cout << "Nhap ma phieu can xoa : "; cin.getline(ma_tam, 50);
   
    i = phieu_tim(ma_tam);
 
    if (i == 0)
        cout << "- Khong tim thay phieu co ma so tren. ";
    else {
        for (int j = i; j <= total_bill; j++)
            lst_bill[j] = lst_bill[j+1];
 
        total_bill = total_bill - 1;
        cout << "- Da xoa.";
    }
    phieu_save_file();
    file_info();
}
 
void phieu_xuat() {
    phieu_load_file();
 
    cout << "\n                      DANH SACH PHIEU MUON           \n \n";
    cout << setw(15) << ".Ma Phieu/ Ma SV" << setw(15) << "Ten SV" << endl << endl;
    for(int i = 1; i <= total_bill; i++) {
        cout << setw(15) << lst_bill[i].bill_maSV << setw(15) << lst_bill[i].bill_tenSV;
        cout << endl;
    }
}
 
 
 
void phieu_hieu_chinh() {
    char ma_tam[50];
 
    cin.ignore();
    cout << "Nhap ma phieu can hieu chinh : "; cin.getline(ma_tam, 50);
       
    i = phieu_tim(ma_tam);
 
    if (i == 0)
        cout << "- Khong tim thay phieu co ma so tren. ";
    else {
        //cin.ignore();
        cout << ". Ma phieu/Ma SV: "; cin.getline(lst_bill[i].bill_maSV, 50);
        cout << ". Ten Sinh Vien : "; cin.getline(lst_bill[i].bill_tenSV, 50);
 
        cout << ". Ngay Muon     : \n";
        cout << " Ngay "; cin >> lst_bill[i].bill_ngaymuon.n_day;
        cout << " thang: "; cin >> lst_bill[i].bill_ngaymuon.n_month;
        cout << " nam: "; cin >> lst_bill[i].bill_ngaymuon.n_year;
        cout << endl;
    }
    phieu_save_file();
}
 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DINH NGHIA HAM CHO DOI TUONG CHI TIET PHIEU.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
void ctphieu_load_file() {
    FILE *f_b;
    f_b = fopen("bill_detail_file","rb");
    fread(lst_detail, sizeof(lst_detail), 1, f_b);
    fclose(f_b);
}
void ctphieu_save_file() {
    FILE * f_b;
    f_b = fopen("bill_detail_file", "wb");
    fwrite(lst_detail, sizeof(lst_detail), 1, f_b);
    fclose(f_b);
}
 
void ctphieu_nhap() {
    char sach_ma_tam[50];
    char phieu_ma_tam[50];
    char t;
    int total_tam;                  // So sach SV hien muon muon.
 
    muon:;
    cin.ignore(1);
    cout << ". So sach se muon : "; cin >> total_tam;
   
    if (total + total_tam > 5) {
        cout << "- Ban chi co the muon toi da 5 cuon. \n";
        cout << "  Ban duoc phep muon them  " << 5 - total << "  cuon nua.";
        goto muon;
    }
 
    for (int i = 1; i <= total_tam; i++) {
        cin.ignore(1);
        cout << endl;
        cout << ". Nhap ma phieu : "; cin.getline(phieu_ma_tam, 50);
 
        if (phieu_tim(phieu_ma_tam) == 0) {
            cout << "- Khong tim thay phieu muon cua ban.";
            break;
        }
       
        nhap_ma_sach:;
        cin.ignore(1);
        cout << ". Nhap ma sach : "; cin.getline(sach_ma_tam, 50);
 
        t = sach_tim(sach_ma_tam);
 
        if (t == 0) {
            cout << ". Khong tim thay sach ban can.";
            cout << "  Ban muon muon sach khac (y/n) : "; cin >> t;
            if (t == 'y' || t == 'Y')
                goto nhap_ma_sach;
            else
                break;
        }
 
        strcpy(lst_detail[i].detail_maSV, phieu_ma_tam);   
        strcpy(lst_detail[i].detail_maSach, sach_ma_tam);
        strcpy(lst_detail[i].detail_tenSach, lst_book[p].b_tensach);
 
        cin.ignore(1);
        cout << ". Tinh trang : "; cin.getline(lst_detail[i].b_moi_cu, 50);
        cout << ". Tra / Chua : "; cin.getline(lst_detail[i].b_trachua, 50);
 
        if (strcmp(lst_detail[i].b_trachua, "chua") == 0)
            lst_book[p].b_soluong = lst_book[p].b_soluong - 1;
        else
            lst_book[p].b_soluong = lst_book[p].b_soluong + 1;
    }
    ctphieu_save_file();
    file_info();
 
}
 
void ctphieu_xuat() {
    ctphieu_load_file();
 
    char phieu_ma_tam[50];
    //char t;
    p = 0;
 
    cin.ignore(1);
    cout << ". Nhap ma phieu : "; cin.getline(phieu_ma_tam, 50);
 
    cout << setw(13) << ".Ma Sach" << setw(13) << "Ten Sach" << setw(13) << "Cu / Moi" << setw(13) << "Tra / Chua" << endl << endl;
    for(int i = 1; i <= total; i++)
        if (strcmp(lst_detail[i].detail_maSV, phieu_ma_tam) == 0) {
            cout << setw(13) << lst_detail[i].detail_maSach << setw(13) << lst_detail[i].detail_tenSach << setw(13) << lst_detail[i].b_moi_cu << setw(13) << lst_detail[i].b_trachua;
            p = 1;
        }
    if (p == 0) printf("\n- Khong tim thay. ");
}
 
 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// DINH NGHIA HAM THONG KE.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 
void TK_theloai() {
    char sach_theloai_tam[50];
    p = 0;
 
    cin.ignore(1);
    cout << ". Nhap the loai muon thong ke: "; cin.getline(sach_theloai_tam, 50);
    cout << endl;
   
    cout << setw(13) << ".Ma Sach" << setw(13) << "Ten Sach" << setw(13) << "The Loai" << setw(13) << "So Luong.";
    for (int i = 1; i <= total_book ;i++)
        if (strcmp(lst_book[i].b_theloai, sach_theloai_tam) == 0)
        {   cout << setw(13) << lst_book[i].b_ma << setw(13) << lst_book[i].b_tensach << setw(13) << lst_book[i].b_theloai << setw(13) << lst_book[i].b_soluong;
            p = p + 1;
        }
    cout << endl << "- Co " << p << " cuon sach co the loai : " << sach_theloai_tam;
    if( p == 0)
        cout << endl << "- Khong co sach nao thuoc the loai : " << sach_theloai_tam;
}
 
void TK_SV_qua_han() {
    SYSTEMTIME d;
    int n_d, n_m, n_y;
    int d_quahan;
 
    n_d = d.wDay;
    n_m = d.wMonth;
    n_y = d.wYear;
   
    cout << endl;
    cout << setw(15) << "So Phieu" << setw(15) << "Ten SV" << endl << endl;
 
    for (int i = 1; i <= total_bill; i++) {
        if ((lst_bill[i].bill_ngaymuon.n_year == n_y) && (lst_bill[i].bill_ngaymuon.n_month == n_m))
            d_quahan = n_d - lst_bill[i].bill_ngaymuon.n_day;
        if ((lst_bill[i].bill_ngaymuon.n_year == n_y) && (lst_bill[i].bill_ngaymuon.n_month != n_m))
            d_quahan = n_d + days_in_month(n_m,n_d);
        if (d_quahan >= 30)
            cout << endl;
            cout << setw(15) << lst_bill[i].bill_maSV << setw(15) << lst_bill[i].bill_tenSV << endl;
    }
}
// Tinh ngay trong thang.
int days_in_month(int md, int dd ) {
    switch (md)
    {
    case '1':
                return (31 - dd);
    case '2':
                return (28 - dd);
    case '3':
                return (31 - dd);
    case '4':
                return (30 - dd);
    case '5':
                return (31 - dd);
    case '6':
                return (30 - dd);
    case '7':
                return (31 - dd);
    case '8':
                return (31 - dd);
    case '9':
                return (30 - dd);
    case '10':
                return (31 - dd);
    case '11':
                return (30 - dd);
    case '12':
                return (31 - dd);
    }
}