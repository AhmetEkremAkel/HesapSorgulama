#include <stdio.h>
#include <stdlib.h>


int main() {
	char isim[256], sifre[30];
	int basari = 0;
	int* p = &basari;
	printf("### Hosgeldiniz ! ###\n");
	while (basari != 1) {
		char buf[256];
		char deneme[256] = "C:\\Users\\USER\\VisualStudioCprojects\\HesapSorguKayitProjesi\\Proje\\KullaniciVerileri\\";
		FILE* pointer;

		printf("Giris yapmak icin 1 i tuslayiniz\nKayit olmak icin 2 yi tuslayiniz\nCikmak icin -1 i tuslayin\n");
		char islem[256];
		scanf("%s", &islem);

		if (!strcmp(islem, "1")) {
			char girisIsim[256];
			char GercekSifre[256];
			char kullainiciSifre[256];

			printf("Kullanici adinizi giriniz :");
			scanf("%s", girisIsim);

			snprintf(buf, sizeof(buf), "%s%s.txt", deneme, girisIsim);

			if (pointer = fopen(buf, "r") == NULL) {
				printf("Kullanici Bulunamadi !\n");
				continue;
			}
			else {
				pointer = fopen(buf, "r");
				fgets(GercekSifre, 256, pointer);
				char kullainiciSifre[256] = "a";
				while (strcmp(kullainiciSifre, "-1")) {
					printf("Cikmak icin -1 tuslayin\n");
					printf("Sifre giriniz : ");
					scanf("%s", &kullainiciSifre);

					if (!strcmp(kullainiciSifre, "-1")) {
						exit(1);
					}

					if (!strcmp(GercekSifre, kullainiciSifre)) {
						*p = 1;
						printf("Giris basarili\n");
						break;
					}
					else {
						printf("Sifre yanlis\n\n");
					}
				}
			}
		}

		else if (!strcmp(islem, "2")) {
			char deneme2[256];

			printf("Kullanici adi giriniz :");
			scanf("%s", &deneme2);

			snprintf(buf, sizeof(buf), "%s%s.txt", deneme, deneme2);

			if (pointer = fopen(buf, "r") != NULL) {
				while (pointer = fopen(buf, "r") != NULL) {
					printf("Bu kullanici adi alinmis baska bir kullanici adi giriniz :");
					scanf("%s", &deneme2);
					snprintf(buf, sizeof(buf), "%s%s.txt", deneme, deneme2);
				}
			}
			pointer = fopen(buf, "a");

			printf("Sifre giriniz :");
			scanf("%s", &sifre);

			while (!strcmp(sifre, "-1")) {
				printf("Sifre -1 olamaz\n");
				printf("Sifre giriniz :");
				scanf("%s", &sifre);
			}

			fputs(sifre, pointer);
			printf("\nKayit basarili !\n");
			fclose(pointer);

			continue;
		}

		else if (!strcmp(islem, "-1")) {
			exit(1);
		}

		else {
			printf("Hatali bir sayi tusladiniz !\n");
			continue;
		}
	}

	printf("Sisteme Giris Yaptiniz");
	int  cikis;
	scanf("%d", &cikis);

	return 0;
}