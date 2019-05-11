#include <stdio.h>
#include <stdlib.h>
#define MAXROW 6
typedef struct _Row
{
	int index;
	int numara;
	struct _Row *sonraki;
}Row;

typedef struct _Table
{
	Row satirlar[MAXROW]; 
}Table;

Table tablo;

void baslangic_deger_atama()
{
	int i;
	for(i=0;i<MAXROW;i++)
	{
		tablo.satirlar[i].index=-1;
		tablo.satirlar[i].sonraki=NULL;
	}
}
void collision(Row *bilgi,Row *ilk_adres);
void Ekle(int sayi)
{
	Row *bilgi,*gecici;
	int adres;
	adres=sayi%MAXROW;
	if(tablo.satirlar[adres].index==-1)//BO�
	{
		tablo.satirlar[adres].index=adres;
		tablo.satirlar[adres].numara=sayi;
	}
	else//COLLISION
	{
		bilgi=(Row *)malloc(sizeof(Row));
		if(bilgi==NULL)
		{
			printf("Bellek Dolu..");
			exit(0);	
		}
		bilgi->index=adres;
		bilgi->numara=sayi;
		bilgi->sonraki=NULL;
		gecici=tablo.satirlar[adres].sonraki;
		while(gecici->sonraki!=NULL)
		{
			gecici=gecici->sonraki;
		}
		gecici->sonraki=bilgi;	
		//collision(bilgi,&tablo.satirlar[adres]);
	}
}
void collision(Row *bilgi,Row *ilk_adres)
{
	Row *gecici;
	gecici=ilk_adres;//�lgili ba�l� listenin ba�lang�� adresi
	while(gecici->sonraki!=NULL)
	{
		gecici=gecici->sonraki;
	}
	gecici->sonraki=bilgi;
}
int Hash(int sayi)
{
	return sayi%MAXROW;
}
int arama(int sayi)
{
	int adres;
	Row * gecici;
	adres=Hash(sayi);
	if(tablo.satirlar[adres].numara==sayi)return 1;
	else
	{
		gecici=tablo.satirlar[adres].sonraki;
		while(gecici!=NULL)
		{
			if(gecici->numara==sayi)return 1;
			gecici=gecici->sonraki;
		}
		return 0;//Ba�ar�s�z arama
	}
}
void Tablo_Listele()
{
	Row *gecici;
	int i;
	for(i=0;i<MAXROW;i++)
	{
		if(tablo.satirlar[i].index!=-1)
		{
			printf("%d.satirda : %d ",i,tablo.satirlar[i].numara);
			gecici=tablo.satirlar[i].sonraki;//i.ba�l� listenin 2. eleman�na konumlan�r
			while(gecici!=NULL)
			{
				printf(" %d ",gecici->numara);
				gecici=gecici->sonraki;
			}
			printf("\n");
		}
	}
	
}
main()
{
	baslangic_deger_atama();
	Ekle(5);
	Ekle(25);
	Ekle(32);
	Ekle(76);
	Ekle(1);
	Ekle(9);
	Ekle(28);
	Ekle(49);
	Tablo_Listele();
	if(arama(1))printf("bulundu");
	else printf("bulunmadi");
	
}









