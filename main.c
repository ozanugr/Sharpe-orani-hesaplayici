#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {


    // Degisken tanimlamalari
    // Tum oranlar ondalikli olacagi icin double tipini kullaniyoruz.
    double yatirim_getirisi;     // Belirli bir dönemde yatýrýmýn veya portföyün elde ettiði getiri oranýdýr.
    double risksiz_faiz_orani;   // Piyasada hiç risk almadan elde edilebilecek teorik getiri oranýdýr.
    double standart_sapma;       // Yatýrýmýn getirisinin dalgalanmasýný yani riskini ölçer 
    double sharpe_orani;         // Bir yatýrýmýn risk baþýna ne kadar getiri saðladýðýný gösteren ölçüttür.

    printf("--- Sharpe Orani Hesaplayici ---\n\n");
    printf("Not: Tum oranlari ondalik olarak giriniz. (Orn: %%15 icin 0.15)\n\n");

    // 1. Yatirim Getirisi (Portfoy Getirisi) Alimi
    printf("1. Yatirim Getirisini (Orn: 0.15) girin: ");
    // Kullanicidan alinan ondalikli degeri 'yatirim_getirisi' degiskenine kaydet
    if (scanf("%lf", &yatirim_getirisi) != 1) {
        printf("Hatali giris! Lutfen gecerli bir sayi girin.\n");
        return 1; // Hata kodu ile programdan cikis
    }

    // 2. Risksiz Faiz Orani Alimi
    printf("2. Risksiz Faiz Oranini (Orn: 0.05) girin: ");
    if (scanf("%lf", &risksiz_faiz_orani) != 1) {
        printf("Hatali giris! Lutfen gecerli bir sayi girin.\n");
        return 1;
    }

    // 3. Standart Sapma (Risk) Alimi
    printf("3. Portfoyun Standart Sapmasini (Risk, Orn: 0.12) girin: ");
    if (scanf("%lf", &standart_sapma) != 1) {
        printf("Hatali giris! Lutfen gecerli bir sayi girin.\n");
        return 1;
    }
    
    // Standart sapmanin 0 olma durumunu kontrol etmeliyiz (Bolen sifir olamaz)
    if (standart_sapma == 0.0) {
        printf("\nUYARI: Standart Sapma sifir olamaz (sifira bolme hatasi).\n");
        printf("Risksiz bir yatirim icin Sharpe Orani tanimsizdir veya sonsuz kabul edilir.\n");
        return 1;
    }

    // Sharpe Orani Formulu Uygulanmasi: (Yatirim Getirisi - Risksiz Faiz Orani) / Standart Sapma
    sharpe_orani = (yatirim_getirisi - risksiz_faiz_orani) / standart_sapma;

    // Sonuclarin Gosterilmesi
    printf("\n--- Hesaplama Sonuclari ---\n");
    printf("Risk Primi (Getiri - Risksiz Faiz): %.4lf\n", (yatirim_getirisi - risksiz_faiz_orani));
    printf("Portfoyun Standart Sapmasi (Risk): %.4lf\n", standart_sapma);
    printf("==================================\n");
    printf("Sharpe Orani Degeri: %.4lf\n", sharpe_orani);
    printf("==================================\n");
    
    // Elde edilen Sharpe Oranini yorumlama
    if (sharpe_orani > 3.0) {
        printf("Yorum: Mukemmel bir risk-getiri dengesi!\n");
    } 
	else if (sharpe_orani >= 2.0) {
        printf("Yorum: Cok iyi bir risk-getiri dengesi!\n");
    }
	 else if (sharpe_orani >= 1.0) {
        printf("Yorum: Iyi bir risk-getiri dengesi. Piyasa ortalamasinin uzerinde.\n");
    }
	 else if (sharpe_orani >= 0.0) {
        printf("Yorum: Kabul edilebilir bir Sharpe Orani. Getiri risksiz getirinin uzerinde.\n");
    }
	 else {
        printf("Yorum: Negatif Sharpe Orani. Yatirim risksiz getiriden daha az kazanc saglamis. (Kotu)\n");
    }
    
    printf("\nProgram sonlandi.\n");
    
	return 0;
}
