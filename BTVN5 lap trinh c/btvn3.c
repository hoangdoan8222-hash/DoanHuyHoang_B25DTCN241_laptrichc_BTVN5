#include <stdio.h>

#define MAX 100

int main() {
    int ma_so[MAX];
    int tuoi[MAX];
    int bhyt[MAX];

    int n;
    int i;
    int K;

    int phi;
    int tong_doanh_thu = 0;
    int tong_uu_tien = 0;

    printf("Nhap so luong benh nhan (0-%d): ", MAX);
    scanf("%d", &n);

    if (n < 0 || n > MAX) {
        printf("So luong benh nhan khong hop le!\n");
        return 0;
    }

    for (i = 0; i < n; i++) {
        printf("\nBenh nhan %d\n", i + 1);

        printf("Nhap ma so thu tu: ");
        scanf("%d", &ma_so[i]);

        do {
            printf("Nhap tuoi (1-120): ");
            scanf("%d", &tuoi[i]);

            if (tuoi[i] < 1 || tuoi[i] > 120) {
                printf("Tuoi khong hop le! Vui long nhap lai.\n");
            }
        } while (tuoi[i] < 1 || tuoi[i] > 120);

        do {
            printf("Nhap BHYT (0-Khong, 1-Co): ");
            scanf("%d", &bhyt[i]);

            if (bhyt[i] != 0 && bhyt[i] != 1) {
                printf("Trang thai BHYT khong hop le! Vui long nhap lai.\n");
            }
        } while (bhyt[i] != 0 && bhyt[i] != 1);
    }

    for (i = 0; i < n; i++) {
        if (bhyt[i] == 1) {
            phi = 30000;
        } else {
            phi = 150000;
        }

        tong_doanh_thu += phi;

        if (tuoi[i] >= 70) {
            tong_uu_tien++;
        }
    }

    printf("\n========== HANG CHO BAN DAU ==========\n");
    printf("%-5s %-10s %-10s %-10s %-15s %-15s\n",
           "STT", "Ma so", "Tuoi", "BHYT", "Phi kham", "Uu tien");

    for (i = 0; i < n; i++) {
        if (bhyt[i] == 1) {
            phi = 30000;
        } else {
            phi = 150000;
        }

        printf("%-5d %-10d %-10d %-10d %-15d ",
               i, ma_so[i], tuoi[i], bhyt[i], phi);

        if (tuoi[i] >= 70) {
            printf("UU TIEN\n");
        } else {
            printf("THUONG\n");
        }
    }

    printf("\nTong doanh thu du kien: %d VND\n", tong_doanh_thu);
    printf("Tong so benh nhan uu tien: %d\n", tong_uu_tien);

    if (n == 0) {
        printf("\nHang cho dang rong, khong the huy!\n");
        return 0;
    }

    printf("\nNhap vi tri chi so K can huy (0-%d): ", n - 1);
    scanf("%d", &K);

    if (K < 0 || K >= n) {
        printf("Vi tri K khong hop le!\n");
        return 0;
    }

    if (bhyt[K] == 1) {
        phi = 30000;
    } else {
        phi = 150000;
    }

    tong_doanh_thu -= phi;

    if (tuoi[K] >= 70) {
        tong_uu_tien--;
    }

    for (i = K; i < n - 1; i++) {
        ma_so[i] = ma_so[i + 1];
        tuoi[i] = tuoi[i + 1];
        bhyt[i] = bhyt[i + 1];
    }

    n--;

    printf("\n========== HANG CHO SAU KHI HUY ==========\n");

    if (n == 0) {
        printf("Hang cho dang rong!\n");
    } else {
        printf("%-5s %-10s %-10s %-10s %-15s %-15s\n",
               "STT", "Ma so", "Tuoi", "BHYT", "Phi kham", "Uu tien");

        for (i = 0; i < n; i++) {
            if (bhyt[i] == 1) {
                phi = 30000;
            } else {
                phi = 150000;
            }

            printf("%-5d %-10d %-10d %-10d %-15d ",
                   i, ma_so[i], tuoi[i], bhyt[i], phi);

            if (tuoi[i] >= 70) {
                printf("UU TIEN\n");
            } else {
                printf("THUONG\n");
            }
        }
    }

    printf("\nTong doanh thu sau khi huy: %d VND\n", tong_doanh_thu);
    printf("Tong so benh nhan uu tien sau khi huy: %d\n", tong_uu_tien);

    return 0;
}
