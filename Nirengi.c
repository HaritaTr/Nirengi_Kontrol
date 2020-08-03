#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Turkish");

	double DxK, DyK, DzK, DxG, DyG, DzG;
	double dxF, dyF, dzF, Baz_Uzn, Kriter;

		/// Bilinenleri isteyelim.
	// Nirengi noktalarının; DX (KONTROL), DY (KONTROL), DZ (KONTROL),
	printf("DX (KONTROL) değerini giriniz: ");
	scanf("%lf", &DxK);
	printf("DY (KONTROL) değerini giriniz: ");
	scanf("%lf", &DyK);
	printf("DZ (KONTROL) değerini giriniz: ");
	scanf("%lf", &DzK);
	// Nirengi noktalarının; DX (GERÇEK), DY (GERÇEK), DZ (GERÇEK),
	printf("DX (GERÇEK) değerini giriniz: ");
	scanf("%lf", &DxG);
	printf("DY (GERÇEK) değerini giriniz: ");
	scanf("%lf", &DyG);
	printf("DZ (GERÇEK) değerini giriniz: ");
	scanf("%lf", &DzG);

		/// Bilinmeyenlerin hesaplanması;
	printf("\n\t=== Hesap sonuçları! === \n");
	/* Nirengi noktalarının ”DX” kontrolü; dx(Fark)
	dx(Fark)= DX(KONTROL) - DX(GERÇEK); */
	dxF= DxK - DxG;
	printf("dx fark değeri: %f\n", dxF);
	/* Nirengi noktalarının ”DY” kontrolü; dy(Fark)
	dy(Fark)= DY(KONTROL) - DY(GERÇEK); */
	dyF= DyK - DyG;
	printf("dy fark değeri: %f\n", dyF);
	/* Nirengi noktalarının ”DZ” kontrolü; dz(Fark)
	dz(Fark)= DZ(KONTROL) - DZ(GERÇEK); */
	dzF= DzK - DzG;
	printf("dz fark değeri: %f\n", dzF);
	/* Baz uzunluğu hesaplanması; Baz_Uzn
	Baz_Uzn = sqrt(dx(Fark)^2 + dy(Fark)^2 + dz(Fark)^2) / 1000; */
	Baz_Uzn = pow((pow(dxF, 2) + pow(dyF, 2) + pow(dzF, 2)), 0.5) / 1000;
	printf("Baz uzunluğu (km) değeri: %f\n", Baz_Uzn);
	/* Teknik şartname madde 54 kriter değerinin hesaplanması; Kriter
	Kriter = 0.03 + (0.003 * Baz_Uzn); */
	Kriter = 0.03 + (0.003 * Baz_Uzn);
	printf("Teknik şartname madde 54 kriter değeri: %f\n", Kriter);
	// dx(fark) < Kriter, dy(fark) < Kriter, dz(fark) < Kriter sonuçları doğrultusunda ise “TAMAM” veya “HATA” olarak yazdırılması.
	if (dxF < Kriter)
	{
		printf("DX < Kriter sağlandı işlem DOĞRU. \n");
	}
	else
	{
		printf("DX < Kriter sağlanmadı işlem YANLIŞ!!! \n");
	}
	if (dyF < Kriter)
	{
		printf("DY < Kriter sağlandı işlem DOĞRU. \n");
	}
	else
	{
		printf("DY < Kriter sağlanmadı işlem YANLIŞ!!! \n");
	}
	if (dzF < Kriter)
	{
		printf("DZ < Kriter sağlandı işlem DOĞRU. \n");
	}
	else
	{
		printf("DZ < Kriter sağlanmadı işlem YANLIŞ!!! \n");
	}

	return 0;
}
