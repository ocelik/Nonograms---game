#include <stdio.h>
#include <stdlib.h>
#define MAX_SATIR 10 //Oynanabilecek maximum satir sayisi..
#define MAX_SUTUN 10 //Oynanabilecek maximum sutun sayisi..

int sayi_al(int,int);
void matrisi_yazdir(char matris1[][MAX_SUTUN], int matris2[][MAX_SUTUN],int matris3[][MAX_SUTUN], int, int);

int main()
{
    FILE *dosya;
    int i,j,l,n,z;
    int resim[MAX_SATIR][MAX_SUTUN];
    int satir_say,sutun_say;
    int satir_no,sutun_no,kod_no;
    int sayac=0, esleme_sayaci=0, dolu_kutu=0, kazandi=0;
    int matris_satir[MAX_SATIR][MAX_SUTUN]= {{0}};
    int matris_sutun[MAX_SATIR][MAX_SUTUN]= {{0}};
    int matris_sutun1[MAX_SATIR][MAX_SUTUN]= {{0}};
    char kullanici_matrisi[MAX_SATIR][MAX_SUTUN];
    char esleme_matrisi[MAX_SATIR][MAX_SUTUN];
    int kazandi_matrisi[MAX_SATIR][MAX_SUTUN]= {{0}};

    dosya=fopen("resim.txt","r"); //Verileri okumak icin resim.txt dosyasini aciyoruz..

    while(!feof(dosya)) //Dosya sonuna kadar okuyotuyoruz..
    {
        fscanf(dosya, "%d" ,&satir_say); //Gelen ilk deger satir sayimizi belirliyor..
        fscanf(dosya, "%d" ,&sutun_say); //Gelen ikinci deger sutun sayimizi belirliyor..

        for (i=0; i<satir_say; i++)
        {
            for (j=0; j<sutun_say; j++)
            {
                fscanf(dosya,"%d",&resim[i][j]); //Kalan degerler ise resim matrisine ataniyor..
            }
        }
    }
    fclose(dosya); //Dosyayi kapatiyoruz..

    for (i=0; i<satir_say; i++)
    {
        l=0;
        for (j=0; j<sutun_say; j++)
        {
            if (resim[i][j]==0)
                l++; //Eger satirda 0 degeri varsa matris_satir'inin satir sayisi siradakine geciyor..
            else if (resim[i][j]==1) //Resim matrisinden gelen deger 1 iken; ..
            {
                matris_satir[i][l]++; //Her satirdaki 1 olan degerler toplanip matris_satir'ina ataniyor..
                sayac++; //Resim.txt'den gelen matristeki 1 olan degerler saydiriliyor..
                esleme_matrisi[i][j]=219; //Gelen degerler 1 ise yeni bir matriste 219 karakterine ataniyor..
            }

            kullanici_matrisi[i][j]='O'; //Kullanici girdisi matrisinin butun degerleri 'O' karakterine ataniyor..
        }
    }

    for(i=0; i<sutun_say; i++)
    {
        n=0;
        for (j=0; j<satir_say; j++)
        {
            if (resim[j][i]==0)
                n++; //Resimden gelen matrisin sutunlarindaki deger 0 ise sonraki satira geciliyor..
            else if (resim[j][i]==1)
                matris_sutun[n][i]++; //Resimden gelen matrisin sutunlarindaki degerler 1 ise saydiriliyor..
        }
    }

    for (i=0; i<sutun_say; i++)
    {
        z=0;
        for (j=0; j<satir_say; j++)
        {
            if (matris_sutun[j][i]!=0)
            {
                matris_sutun1[z][i]=matris_sutun[j][i]; //Sutundaki saydirilan matrisler sirali bi sekilde olmasi icin baska bir matrise esitleniyor..
                z++;
            }
        }
    }

    matrisi_yazdir(kullanici_matrisi,matris_satir,matris_sutun1,satir_say,sutun_say); //Ilk ekran goruntusu yazdiriliyor..

    do
    {
        esleme_sayaci=0; //Sayac her dongude sifirlaniyor..
        dolu_kutu=0; //Her dongunun basinda isaretlenen kutularin sayisi sifirlaniyor..
        printf("\n");

        printf("Satir Numarasini Giriniz(1-%d):",satir_say);
        satir_no=sayi_al(1,satir_say); //Kullanicidan belirlenen aralikta satir sayisi isteniyor..

        printf("Sutun Numarasini Giriniz(1-%d):",sutun_say);
        sutun_no=sayi_al(1,sutun_say); //Kullanicidan belirlenen aralikta sutun sayisi isteniyor..

        printf("Isaretleme Kodunu Giriniz(1:dolu, 0:bos, 2:belirsiz):");
        kod_no=sayi_al(0,2); //Kullanicidan belirlenen aralikda isaretleme kodu isteniyor..

        if (kod_no==0) //Isaretleme kodu 0 ise;
        {
            kullanici_matrisi[satir_no-1][sutun_no-1]='X'; //Kullanici matrisine 'X' karakteri ataniyor..
            kazandi_matrisi[satir_no-1][sutun_no-1]=0; //Kazandi matrisine 0 degeri ataniyor..
        }

        else if (kod_no==1) //Isaretleme kodu 1 ise;
        {
            kullanici_matrisi[satir_no-1][sutun_no-1]=219; //Kullanici matrisine 219 karakteri ataniyor..
            kazandi_matrisi[satir_no-1][sutun_no-1]=1; //Kazandi matrisine 1 degeri ataniyor..
        }
        else if (kod_no==2) //Isaretleme kodu 2 ise;
        {
            kullanici_matrisi[satir_no-1][sutun_no-1]='O'; //Kullanici matrisine 'O' karakteri ataniyor..
            kazandi_matrisi[satir_no-1][sutun_no-1]=2; //Kazandi matrisine 2 degeri ataniyor..
        }

        matrisi_yazdir(kullanici_matrisi,matris_satir,matris_sutun1,satir_say,sutun_say); //Girilen degerler sonucu yeni ekran goruntusu geliyor..

        for (i=0; i<satir_say; i++)
        {
            for (j=0; j<sutun_say; j++)
            {
                if (kazandi_matrisi[i][j]==1) //Kazandi matrisinin degeri 1 iken;
                    dolu_kutu++; //Dolu kutu sayaci artiriliyor..

                if (kullanici_matrisi[i][j]==esleme_matrisi[i][j]) //Kullanici matrisindeki deger ile esleme matrisinin degeri esit ise esleme sayaci artiriliyor..
                    esleme_sayaci++;
            }
        }
        if (sayac==esleme_sayaci && dolu_kutu==sayac) //Eger 3 deger de birbirinine esit ise;
            kazandi=1; //Kazandi degeri 1'e esitleniyor..
    }
    while(kazandi!=1); //Dongu kazandi degeri 1 olmadikca devam ediyor..

    printf("\n\nTebrikler, gizli resmi ortaya cikardiniz!\n"); //Donguden cikilince tebrikler yazisi yazdiriliyor ve oyun sonlaniyor..
    return 0;
}

int sayi_al(int alt, int ust) //Alt ve ust sinira gore sayi sayi isteniyor..
{
    int sayi;
    scanf("%d", &sayi);

    while (sayi<alt || sayi>ust) //Sayi dogru girilinceye kadar bekleniyor..
    {
        printf("Lutfen %d ile %d arasinda sayi giriniz: ",alt,ust);
        scanf("%d",&sayi);
    }
    return sayi;
}

void matrisi_yazdir(char matris1[][MAX_SUTUN], int matris2[][MAX_SUTUN], int matris3[][MAX_SUTUN], int satir, int sutun)
{
    int i,j,k;
    printf("\n");
    printf("  ");
    for (i=0; i<sutun; i++)
    {
        printf("%d",i+1); //Sutun sayilari yan yana yazdiriliyor..
    }
    printf("\n");
    for (i=0; i<satir; i++)
    {
        if (i<9)
            printf("%d ",i+1); //Satir sayilari yazdiriliyor..
        else if (i==9)
            printf("X "); //Satir sayisi 10 ise X karakteri yazdiriliyor..

        for (j=0; j<sutun; j++)
        {
            printf("%c", matris1[i][j]); //Matris degerleri yazdiriliyor..
        }
        for (k=0; k<MAX_SUTUN; k++)
        {
            if (matris2[i][k]!=0)
                printf(" %d", matris2[i][k]); //Satirdaki dolu kutularin sayilari yazdiriliyor..
        }
        printf("\n");
    }
    printf("\n");
    printf("  ");
    for (i=0; i<5; i++)
    {
        for (j=0; j<sutun; j++)
        {
            if(matris3[i][j]!=0) //Sutunlardaki dolu kutular yazdiriliyor..
            {
                if (matris3[i][j]<10)
                    printf("%d",matris3[i][j]);
                else if (matris3[i][j]==10)
                    printf("X"); //Eger o sutunda 10 kutu doluysa X karakteri yazdiriliyor..
            }
            else printf(" ");
        }
        printf("\n");
        printf("  ");
    }
    return;
}
