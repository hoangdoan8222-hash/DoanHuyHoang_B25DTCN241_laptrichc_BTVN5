#include <stdio.h>

int main() {
    int phi_kham[10] = {150000, 300000, 200000, 500000};
    int so_luong = 4;

    int vi_tri_sua;
    int gia_tri_moi;
    int phi_kham_moi;
    int vi_tri_xoa;

    int tong_chi_phi;

    tong_chi_phi = phi_kham[0] + phi_kham[1];

    printf("Tong chi phi 2 ca dau: %d VND\n", tong_chi_phi);

    printf("Nhap vi tri sua: ");
    scanf("%d", &vi_tri_sua);

    printf("Nhap gia tri moi: ");
    scanf("%d", &gia_tri_moi);

    if (vi_tri_sua >= 0 && vi_tri_sua < so_luong) {
        phi_kham[vi_tri_sua] = gia_tri_moi;
        printf("Sau khi sua vi tri %d: Chi phi moi = %d VND\n",
               vi_tri_sua, phi_kham[vi_tri_sua]);
    } else {
        printf("Loi: Vi tri sua %d khong hop le!\n", vi_tri_sua);
    }

    printf("Nhap phi kham moi: ");
    scanf("%d", &phi_kham_moi);

    if (so_luong < 10) {
        phi_kham[so_luong] = phi_kham_moi;
        so_luong++;

        printf("Sau khi them ca moi: So luong = %d, Chi phi ca cuoi = %d VND\n",
               so_luong, phi_kham[so_luong - 1]);
    } else {
        printf("Loi: Mang da day, khong the them!\n");
    }

    printf("Nhap vi tri xoa: ");
    scanf("%d", &vi_tri_xoa);

    if (vi_tri_xoa >= 0 && vi_tri_xoa < so_luong) {
        if (vi_tri_xoa == 0) {
            phi_kham[0] = phi_kham[1];
            phi_kham[1] = phi_kham[2];
            phi_kham[2] = phi_kham[3];
            phi_kham[3] = phi_kham[4];
        } else if (vi_tri_xoa == 1) {
            phi_kham[1] = phi_kham[2];
            phi_kham[2] = phi_kham[3];
            phi_kham[3] = phi_kham[4];
        } else if (vi_tri_xoa == 2) {
            phi_kham[2] = phi_kham[3];
            phi_kham[3] = phi_kham[4];
        } else if (vi_tri_xoa == 3) {
            phi_kham[3] = phi_kham[4];
        } else if (vi_tri_xoa == 4) {
        }

        so_luong--;

        printf("Sau khi xoa vi tri %d: So luong = %d, Chi phi vi tri 0 moi = %d VND\n",
               vi_tri_xoa, so_luong, phi_kham[0]);
    } else {
        printf("Loi: Vi tri xoa %d khong hop le!\n", vi_tri_xoa);
        printf("So luong ca kham giu nguyen: %d\n", so_luong);
    }

    return 0;
}
