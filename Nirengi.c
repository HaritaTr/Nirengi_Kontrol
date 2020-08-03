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
	printf("DX (KONTROL) değerini giriniz: \n");
	scanf("%lf", &DxK);
	printf("DY (KONTROL) değerini giriniz: \n");
	scanf("%lf", &DyK);
	printf("DZ (KONTROL) değerini giriniz: \n");
	scanf("%lf", &DzK);
	// Nirengi noktalarının; DX (GERÇEK), DY (GERÇEK), DZ (GERÇEK),
	printf("DX (GERÇEK) değerini giriniz: \n");
	scanf("%lf", &DxG);
	printf("DY (GERÇEK) değerini giriniz: \n");
	scanf("%lf", &DyG);
	printf("DZ (GERÇEK) değerini giriniz: \n");
	scanf("%lf", &DzG);

		/// Bilinmeyenlerin hesaplanması.
	/* Nirengi noktalarının ”DX” kontrolü; dx(Fark)
	dx(Fark)= DX(KONTROL) - DX(GERÇEK); */
	dxF= DxK - DxG;

	/* Nirengi noktalarının ”DY” kontrolü; dy(Fark)
	dy(Fark)= DY(KONTROL) - DY(GERÇEK); */
	dyF= DyK - DyG;

	/* Nirengi noktalarının ”DZ” kontrolü; dz(Fark)
	dz(Fark)= DZ(KONTROL) - DZ(GERÇEK); */
	dzF= DzK - DzG;

	/* Baz uzunluğu hesaplanması; Baz_Uzn
	Baz_Uzn = sqrt(dx(Fark)^2 + dy(Fark)^2 + dz(Fark)^2) / 1000; */
	Baz_Uzn = pow((pow(dxF, 2) + pow(dyF, 2) + pow(dzF, 2)), 0.5) / 1000;

	/* Teknik Şartname Madde 54 Kriter Değerinin Hesaplanması; Kriter
	Kriter = 0.03 + (0.003 * Baz_Uzn); */
	Kriter = 0.03 + (0.003 * Baz_Uzn);

	// dx(fark) < Kriter, dy(fark) < Kriter, dz(fark) < Kriter sonuçları doğrultusunda ise “TAMAM” veya “HATA” olarak yazdırılması.

	return 0;
}
