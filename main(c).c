#include <stdio.h>
#include <stdlib.h>

const char matrix_bigram_strings[10][3] ={"th", "he", "in", "er", "an", "en", "ch", "de", "ei", "te"};
const char matrix_trigram_strings[10][4]={"the", "and", "ing", "ent", "ion", "der", "sch", "ich", "nde", "die"};
int distances [2]={0,0};
//ingilizce dilinin frekans degerleri
const float frequency_eng[20]={ 2.71, 2.33, 2.03, 1.78, 1.61, 1.13, 0.01, 0.01, 0.01, 0.01, 1.81, 0.73, 0.72, 0.42, 0.42, 0.01, 0.01, 0.01, 0.01, 0.01 };
//almanca dilinin frekans degerleri
const float frequency_germ[20]={ 0.01, 0.89, 1.71, 3.90, 1.07, 3.61, 2.36, 2.31, 1.98, 1.98, 0.01, 0.01, 0.01, 0.01, 0.01, 1.04, 0.76, 0.75, 0.72, 0.62 };
//void detect_lang(); vb.. gibi prototipi tanimlanan fonksiyonlarý mainin üstünde tanimladigimiz için prototipleri sildik.
int calculated_frequencies[20]; // verilerimizin (tekrar sayilarimiz =  frekans)tutuldugu yer

void filter_str(char str[])//Kullanicidan alinan metinde yer alan A-Z,a-z ,bosluk ve '\0' disindaki karakterlerin yerine bosluk atayarak metni yabanci karakterlerden temizleyen fonksiyon
{
    for(int i=0;i<strlen(str);i++)
    {
        if(str[i]<=90 && str[i]>=65) // A-Z arasında girilen harfleri kucuk harfe donusturuyoruz
            str[i]=tolower(str[i]); //tolower ile buyuk harfleri kuculttuk

        else if(str[i]<=122 && str[i]>=97) // kucuk harfse devam ediyoruz
            continue;

        else if(str[i]== ' ' || str[i]=='\0' ) // eger karakter bosluk  veya terminating karakter ise devam ediyoruz
            continue;

        else
            str[i]=' '; //yabanci karakterle karsılastıgımızda yerlerine bosluk atiyoruz
    }
    puts(str);
}

void calculate_frequencies_bi(char str1[]) // bigramlarin frekansini hesaplayan fonksiyondur.
{

    int i,j=0;
    for(i=0;i<10;i++) // bu for bi gramlari sirasiyla taramamizi saglar
    {

            for(int sayac=0;sayac<strlen(str1);sayac++) // sayac metni taramamizi saglar her bi gram icin sifirlanir
            {
                if(str1[sayac]==matrix_bigram_strings[i][j])
                {
                    j++; // bi gramin bir sonraki harfine gecer.
                    sayac++; // metnin bir sonraki harfine gecer.

                    if(str1[sayac]==matrix_bigram_strings[i][j])
                        calculated_frequencies[i]+=1;
                }
                j=0;// bi gram bulunduktan sonra ayni bi gramin diger tekrarlarini yakalamak icin sifirlanir.
            }
    }
    for(int k=0;k<10;k++)
        printf("%d\n",calculated_frequencies[k]);
}
void calculate_frequencies_tri(char str1[]) // trigramlarin frekansini hesaplayan fonksiyondur.
{
    int i,j=0;
    for(i=0;i<10;i++) // bu for tri gramlari sirasiyla taramamizi saglar
    {
		for(int sayac=0;sayac<strlen(str1);sayac++) // sayac metni taramamizi saglar her tri gram icin sifirlanir
		{
			if(str1[sayac]==matrix_trigram_strings[i][j])
			{
				j++; // tri gramin bir sonraki harfine gecer.
				sayac++; // metnin bir sonraki harfine gecer.
				if(str1[sayac]==matrix_trigram_strings[i][j])
				{
					j++; // tri gramin son harfine gecer.
					sayac++; // metnin bir sonraki harfine gecer.
					if(str1[sayac]==matrix_trigram_strings[i][j])
						calculated_frequencies[i+10]+=1; // son 10 eleman icin.
				}
			}
			j=0; // trigram bulunduktan sonra ayni tri gramin diger tekrarlarini yakalamak icin sifirlanir.
		}
    }
    for(int k=10;k<20;k++)
        printf("%d\n",calculated_frequencies[k]);
}

void calculate_distances() // bigram ve trigramlarin frekanslari (tekrar sayilari) ile  hesaplamalar yapilir.
{
    for(int i=0;i<20;i++)
    {
        if(frequency_eng[i]>frequency_germ[i])
            distances[0]+=calculated_frequencies[i];  // distance[0]= ing point
        else
            distances[1]+=calculated_frequencies[i];  // distance[1]= ger point
    }
    printf("ing point:%d\n\n",distances[0]);
    printf("germ point:%d\n\n",distances[1]);
}
void detect_lang() // calculate_distances() ile yaptigimiz hesaplamar sonucunda metnin yazildigi dilini tahmin eder.
{
   if(distances[0]>distances[1])
        printf("Girilen metin Ingilizcedir\n");
   else
        printf("Girilen Metin Almancadir\n");
}
int main()
{
    char alinan_metin[999+1];// '\0'   // 20 harflik metin   20 byte
    //alinan_metin[1000]='\0'; gets fonksiyonu zaten '\0' bu karakteri otomatik olarak atiyor.
    printf("Metni giriniz:");  // metin = char dizisi // gets() kullan.
    gets(alinan_metin);
    printf("\n^^^^ Alinan metin temizleniyor...^^^^\n\n");
    filter_str(alinan_metin);
    printf("\n^^^^ Metin temizlendi!!!^^^^\n\n");
    printf("\n^^^^ Metindeki bigramlar hesaplaniyor...^^^^\n\n");
    calculate_frequencies_bi(alinan_metin);
    printf("\n^^^^ Metindeki bigramlar hesaplandi!!!^^^^\n\n");
    printf("\n^^^^ Metindeki trigramlar hesaplaniyor...^^^^\n\n");
    calculate_frequencies_tri(alinan_metin);
    printf("\n^^^^ Metindeki trigramlar hesaplandi...^^^^\n\n");
    printf("\n^^^^Girilen metnin tahmini dili^^^^\n");
    calculate_distances();
    detect_lang();
    return 0;
}
