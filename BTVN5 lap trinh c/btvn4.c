#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    int maSoThuTu[MAX];
    char tenBenhNhan[MAX][30];
    int tuoi[MAX];
    int uuTien[MAX];
    int bhyt[MAX];
    int chiPhi[MAX];

    char tenBacSi[MAX][30];
    char khungGio[MAX][20];

    int soLuong = 0;
    int soThuTuTiepTheo = 1001;

    int luaChon;
    int i, j;
    int viTri;
    int maNhap;
    int timThay;
    int tuoiMoi;
    int bhytMoi;
    int chiPhiMoi;
    int dangMangThai;
    int soBenhNhanBacSi;

    char tenNhap[30];
    char tenMoi[30];
    char bacSiNhap[30];
    char khungGioNhap[20];

    do {
        printf("\n========== MEDCARE CLINIC ==========\n");
        printf("1. Tiep nhan benh nhan moi\n");
        printf("2. Hien thi danh sach hang doi\n");
        printf("3. Cap nhat thong tin dang ky\n");
        printf("4. Huy so thu tu\n");
        printf("5. Tim kiem benh nhan\n");
        printf("0. Thoat\n");
        printf("====================================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &luaChon);
        while (getchar() != '\n');

        switch (luaChon) {
            case 1:
                if (soLuong >= MAX) {
                    printf("Hang doi da day, khong the tiep nhan them!\n");
                    break;
                }

                printf("Nhap ten benh nhan: ");
                fgets(tenNhap, sizeof(tenNhap), stdin);
                tenNhap[strcspn(tenNhap, "\n")] = '\0';

                printf("Nhap tuoi: ");
                scanf("%d", &tuoi[soLuong]);
                while (getchar() != '\n');

                if (tuoi[soLuong] < 1 || tuoi[soLuong] > 120) {
                    printf("Tuoi khong hop le!\n");
                    break;
                }

                printf("Benh nhan co mang thai khong? (1-Co, 0-Khong): ");
                scanf("%d", &dangMangThai);
                while (getchar() != '\n');

                if (dangMangThai != 0 && dangMangThai != 1) {
                    printf("Trang thai mang thai khong hop le!\n");
                    break;
                }

                printf("Nhap trang thai BHYT (1-Co, 0-Khong): ");
                scanf("%d", &bhyt[soLuong]);
                while (getchar() != '\n');

                if (bhyt[soLuong] != 0 && bhyt[soLuong] != 1) {
                    printf("Trang thai BHYT khong hop le!\n");
                    break;
                }

                printf("Nhap bac si: ");
                fgets(bacSiNhap, sizeof(bacSiNhap), stdin);
                bacSiNhap[strcspn(bacSiNhap, "\n")] = '\0';

                printf("Nhap khung gio: ");
                fgets(khungGioNhap, sizeof(khungGioNhap), stdin);
                khungGioNhap[strcspn(khungGioNhap, "\n")] = '\0';

                soBenhNhanBacSi = 0;

                for (i = 0; i < soLuong; i++) {
                    if (strcmp(tenBacSi[i], bacSiNhap) == 0 &&
                        strcmp(khungGio[i], khungGioNhap) == 0) {
                        soBenhNhanBacSi++;
                    }
                }

                if (soBenhNhanBacSi >= 5) {
                    printf("Bac si nay da du 5 benh nhan trong khung gio!\n");
                    break;
                }

                strcpy(tenBenhNhan[soLuong], tenNhap);
                strcpy(tenBacSi[soLuong], bacSiNhap);
                strcpy(khungGio[soLuong], khungGioNhap);

                maSoThuTu[soLuong] = soThuTuTiepTheo;
                soThuTuTiepTheo++;

                if (tuoi[soLuong] > 70 || dangMangThai == 1) {
                    uuTien[soLuong] = 1;
                } else {
                    uuTien[soLuong] = 0;
                }

                if (bhyt[soLuong] == 1) {
                    chiPhi[soLuong] = 40000;
                } else {
                    chiPhi[soLuong] = 200000;
                }

                if (uuTien[soLuong] == 1) {
                    viTri = 0;

                    while (viTri < soLuong && uuTien[viTri] == 1) {
                        viTri++;
                    }

                    for (j = soLuong; j > viTri; j--) {
                        maSoThuTu[j] = maSoThuTu[j - 1];
                        strcpy(tenBenhNhan[j], tenBenhNhan[j - 1]);
                        tuoi[j] = tuoi[j - 1];
                        uuTien[j] = uuTien[j - 1];
                        bhyt[j] = bhyt[j - 1];
                        chiPhi[j] = chiPhi[j - 1];
                        strcpy(tenBacSi[j], tenBacSi[j - 1]);
                        strcpy(khungGio[j], khungGio[j - 1]);
                    }

                    maSoThuTu[viTri] = maSoThuTu[soLuong];
                    strcpy(tenBenhNhan[viTri], tenNhap);
                    tuoi[viTri] = tuoi[soLuong];
                    uuTien[viTri] = 1;
                    bhyt[viTri] = bhyt[soLuong];
                    chiPhi[viTri] = chiPhi[soLuong];
                    strcpy(tenBacSi[viTri], bacSiNhap);
                    strcpy(khungGio[viTri], khungGioNhap);
                }

                soLuong++;

                printf("Tiep nhan benh nhan thanh cong!\n");
                printf("So thu tu: %d\n", maSoThuTu[soLuong - 1]);

                break;

            case 2:
                if (soLuong == 0) {
                    printf("Danh sach hang doi dang rong!\n");
                    break;
                }

                printf("\n================ DANH SACH HANG DOI ================\n");
                printf("%-5s %-10s %-25s %-6s %-10s %-10s %-12s %-15s\n",
                       "STT", "Ma STT", "Ten benh nhan", "Tuoi",
                       "Uu tien", "BHYT", "Chi phi", "Bac si");

                for (i = 0; i < soLuong; i++) {
                    printf("%-5d %-10d %-25s %-6d %-10s %-10s %-12d %-15s\n",
                           i + 1,
                           maSoThuTu[i],
                           tenBenhNhan[i],
                           tuoi[i],
                           uuTien[i] ? "CO" : "KHONG",
                           bhyt[i] ? "CO" : "KHONG",
                           chiPhi[i],
                           tenBacSi[i]);

                    printf("      Khung gio: %s\n", khungGio[i]);
                }

                break;

            case 3:
                if (soLuong == 0) {
                    printf("Danh sach hang doi dang rong!\n");
                    break;
                }

                printf("Nhap ma so thu tu can cap nhat: ");
                scanf("%d", &maNhap);
                while (getchar() != '\n');

                timThay = 0;
                viTri = -1;

                for (i = 0; i < soLuong; i++) {
                    if (maSoThuTu[i] == maNhap) {
                        timThay = 1;
                        viTri = i;
                        break;
                    }
                }

                if (!timThay) {
                    printf("Khong tim thay benh nhan co ma so nay!\n");
                    break;
                }

                printf("Ten hien tai: %s\n", tenBenhNhan[viTri]);
                printf("Nhap ten moi: ");
                fgets(tenMoi, sizeof(tenMoi), stdin);
                tenMoi[strcspn(tenMoi, "\n")] = '\0';

                printf("Nhap tuoi moi: ");
                scanf("%d", &tuoiMoi);
                while (getchar() != '\n');

                if (tuoiMoi < 1 || tuoiMoi > 120) {
                    printf("Tuoi khong hop le!\n");
                    break;
                }

                printf("Nhap BHYT moi (1-Co, 0-Khong): ");
                scanf("%d", &bhytMoi);
                while (getchar() != '\n');

                if (bhytMoi != 0 && bhytMoi != 1) {
                    printf("Trang thai BHYT khong hop le!\n");
                    break;
                }

                strcpy(tenBenhNhan[viTri], tenMoi);
                tuoi[viTri] = tuoiMoi;
                bhyt[viTri] = bhytMoi;

                if (tuoi[viTri] > 70) {
                    uuTien[viTri] = 1;
                }

                if (bhyt[viTri] == 1) {
                    chiPhiMoi = 40000;
                } else {
                    chiPhiMoi = 200000;
                }

                chiPhi[viTri] = chiPhiMoi;

                printf("Cap nhat thong tin thanh cong!\n");

                break;

            case 4:
                if (soLuong == 0) {
                    printf("Danh sach hang doi dang rong!\n");
                    break;
                }

                printf("Nhap ma so thu tu can huy: ");
                scanf("%d", &maNhap);
                while (getchar() != '\n');

                timThay = 0;
                viTri = -1;

                for (i = 0; i < soLuong; i++) {
                    if (maSoThuTu[i] == maNhap) {
                        timThay = 1;
                        viTri = i;
                        break;
                    }
                }

                if (!timThay) {
                    printf("Khong tim thay ma so thu tu can huy!\n");
                    break;
                }

                for (i = viTri; i < soLuong - 1; i++) {
                    maSoThuTu[i] = maSoThuTu[i + 1];
                    strcpy(tenBenhNhan[i], tenBenhNhan[i + 1]);
                    tuoi[i] = tuoi[i + 1];
                    uuTien[i] = uuTien[i + 1];
                    bhyt[i] = bhyt[i + 1];
                    chiPhi[i] = chiPhi[i + 1];
                    strcpy(tenBacSi[i], tenBacSi[i + 1]);
                    strcpy(khungGio[i], khungGio[i + 1]);
                }

                soLuong--;

                printf("Huy so thu tu thanh cong!\n");

                break;

            case 5:
                if (soLuong == 0) {
                    printf("Danh sach hang doi dang rong!\n");
                    break;
                }

                printf("\n1. Tim theo ten\n");
                printf("2. Tim theo ma so thu tu\n");
                printf("Nhap lua chon: ");
                scanf("%d", &j);
                while (getchar() != '\n');

                if (j == 1) {
                    printf("Nhap ten benh nhan can tim: ");
                    fgets(tenNhap, sizeof(tenNhap), stdin);
                    tenNhap[strcspn(tenNhap, "\n")] = '\0';

                    timThay = 0;

                    for (i = 0; i < soLuong; i++) {
                        if (strcmp(tenBenhNhan[i], tenNhap) == 0) {
                            printf("\nTim thay benh nhan:\n");
                            printf("Ma so thu tu: %d\n", maSoThuTu[i]);
                            printf("Ten: %s\n", tenBenhNhan[i]);
                            printf("Tuoi: %d\n", tuoi[i]);
                            printf("Uu tien: %s\n",
                                   uuTien[i] ? "CO" : "KHONG");
                            printf("BHYT: %s\n",
                                   bhyt[i] ? "CO" : "KHONG");
                            printf("Chi phi: %d VND\n", chiPhi[i]);
                            printf("Bac si: %s\n", tenBacSi[i]);
                            printf("Khung gio: %s\n", khungGio[i]);

                            timThay = 1;
                        }
                    }

                    if (!timThay) {
                        printf("Khong tim thay benh nhan!\n");
                    }

                } else if (j == 2) {
                    printf("Nhap ma so thu tu can tim: ");
                    scanf("%d", &maNhap);
                    while (getchar() != '\n');

                    timThay = 0;

                    for (i = 0; i < soLuong; i++) {
                        if (maSoThuTu[i] == maNhap) {
                            printf("\nTim thay benh nhan:\n");
                            printf("Ma so thu tu: %d\n", maSoThuTu[i]);
                            printf("Ten: %s\n", tenBenhNhan[i]);
                            printf("Tuoi: %d\n", tuoi[i]);
                            printf("Uu tien: %s\n",
                                   uuTien[i] ? "CO" : "KHONG");
                            printf("BHYT: %s\n",
                                   bhyt[i] ? "CO" : "KHONG");
                            printf("Chi phi: %d VND\n", chiPhi[i]);
                            printf("Bac si: %s\n", tenBacSi[i]);
                            printf("Khung gio: %s\n", khungGio[i]);

                            timThay = 1;
                            break;
                        }
                    }

                    if (!timThay) {
                        printf("Khong tim thay benh nhan!\n");
                    }

                } else {
                    printf("Lua chon tim kiem khong hop le!\n");
                }

                break;

            case 0:
                printf("Ket thuc chuong trinh!\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (luaChon != 0);

    return 0;
}
