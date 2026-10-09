#include <stdio.h>
#include <string.h>

int main(void) {
    struct VeMayBay {
        char maPNR[10];
        char tenHanhKhach[50];
        char hangVe[15];
        float trongLuongHanhLy;
        long phiPhuThu;
    };

    struct VeMayBay ve[50];
    int n, i, timThay = -1;
    char maCanTim[10];

    printf("=== HE THONG CHECK-IN VE MAY BAY ===\n");

    do {
        printf("Nhap so luong ve (1 - 50): ");
        if (scanf("%d", &n) != 1) {
            while (getchar() != '\n');
            n = 0;
        } else {
            while (getchar() != '\n');
        }

        if (n < 1 || n > 50) {
            printf("So luong ve khong hop le! Vui long nhap lai.\n");
        }
    } while (n < 1 || n > 50);

    for (i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);

        printf("Nhap ma PNR: ");
        fgets(ve[i].maPNR, sizeof(ve[i].maPNR), stdin);
        ve[i].maPNR[strcspn(ve[i].maPNR, "\n")] = '\0';

        printf("Nhap ho ten hanh khach: ");
        fgets(ve[i].tenHanhKhach, sizeof(ve[i].tenHanhKhach), stdin);
        ve[i].tenHanhKhach[strcspn(ve[i].tenHanhKhach, "\n")] = '\0';

        printf("Nhap hang ve (Eco/Deluxe/Business): ");
        fgets(ve[i].hangVe, sizeof(ve[i].hangVe), stdin);
        ve[i].hangVe[strcspn(ve[i].hangVe, "\n")] = '\0';

        printf("Nhap trong luong hanh ly (kg): ");
        while (scanf("%f", &ve[i].trongLuongHanhLy) != 1 ||
               ve[i].trongLuongHanhLy < 0) {
            printf("Trong luong khong hop le! Nhap lai: ");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');

        if (ve[i].trongLuongHanhLy > 7.0f) {
            ve[i].phiPhuThu =
                (long)((ve[i].trongLuongHanhLy - 7.0f) * 50000);
        } else {
            ve[i].phiPhuThu = 0;
        }
    }

    printf("\n=== DANH SACH VE MAY BAY CHUYEN BAY ===\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("%-5s %-10s %-25s %-12s %-12s %-15s\n",
           "STT", "MA PNR", "HO TEN HANH KHACH",
           "HANG VE", "HANH LY(KG)", "PHI PHU THU");
    printf("-----------------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-5d %-10s %-25s %-12s %-12.1f %-15ld\n",
               i + 1,
               ve[i].maPNR,
               ve[i].tenHanhKhach,
               ve[i].hangVe,
               ve[i].trongLuongHanhLy,
               ve[i].phiPhuThu);
    }

    printf("-----------------------------------------------------------------------------------------\n");

    printf("\n=== CAP NHAT THONG TIN HANH LY ===\n");
    printf("Nhap ma PNR can cap nhat: ");
    fgets(maCanTim, sizeof(maCanTim), stdin);
    maCanTim[strcspn(maCanTim, "\n")] = '\0';

    for (i = 0; i < n; i++) {
        if (strcmp(ve[i].maPNR, maCanTim) == 0) {
            timThay = i;
            break;
        }
    }

    if (timThay != -1) {
        printf("Tim thay ve cua hanh khach: %s\n",
               ve[timThay].tenHanhKhach);

        printf("Nhap trong luong hanh ly moi (kg): ");
        while (scanf("%f", &ve[timThay].trongLuongHanhLy) != 1 ||
               ve[timThay].trongLuongHanhLy < 0) {
            printf("Trong luong khong hop le! Nhap lai: ");
            while (getchar() != '\n');
        }
        while (getchar() != '\n');

        if (ve[timThay].trongLuongHanhLy > 7.0f) {
            ve[timThay].phiPhuThu =
                (long)((ve[timThay].trongLuongHanhLy - 7.0f) * 50000);
        } else {
            ve[timThay].phiPhuThu = 0;
        }

        printf("Cap nhat thanh cong! Phi phu thu moi: %ld VND\n",
               ve[timThay].phiPhuThu);

        printf("\n=== DANH SACH VE MAY BAY SAU CAP NHAT ===\n");
        printf("-----------------------------------------------------------------------------------------\n");
        printf("%-5s %-10s %-25s %-12s %-12s %-15s\n",
               "STT", "MA PNR", "HO TEN HANH KHACH",
               "HANG VE", "HANH LY(KG)", "PHI PHU THU");
        printf("-----------------------------------------------------------------------------------------\n");

        for (i = 0; i < n; i++) {
            printf("%-5d %-10s %-25s %-12s %-12.1f %-15ld\n",
                   i + 1,
                   ve[i].maPNR,
                   ve[i].tenHanhKhach,
                   ve[i].hangVe,
                   ve[i].trongLuongHanhLy,
                   ve[i].phiPhuThu);
        }

        printf("-----------------------------------------------------------------------------------------\n");
    } else {
        printf("Khong tim thay ma PNR hop le!\n");
    }

    return 0;
}
