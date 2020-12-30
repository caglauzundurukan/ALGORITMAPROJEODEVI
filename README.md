# ALGORITMAPROJEODEVI
Algoritmalar ve Programlama proje ödevi
Kullanıcıdan alınan metinde yer alan A-Z,a-z ,bosluk ve '\0' dışındaki karakterlerin yerine boşluk atayarak metni yabancı karakterlerden temizleyen bir fonksiyon oluşturduk.
void calculate_frequencies_bi() fonksiyonu ile bi gramlarin frekansini hesapladık.
Bi gramları hesaplarken iki for döngüsü kullandık. 
İlk for döngümüz, bi gramları sırasıyla taramamızı sağladı.
İkinci for döngümüzde tanımladığımız sayaç sayesinde metni taradık ve bu sayaç her bi gram için sıfırlandı.
Oluşturduğumuz ikinci for döngüsünde 2 adet if koşulu kullandık.
İlk if de, metnin ilk harfi ile bigramın ilk harfinin aynı olup olmama durumuna baktık.
Eğer aynı ise yine bir if döngüsü yardımıyla ikinci harflere baktık.
Bu harflerin de aynı olması durumunda o bi grama +1 ekledik. Ve bi gram bulunduktan sonra aynı bi gramın diğer tekrarlarını yakalamak için j'yi sıfırladık.
void calculate_frequencies_tri() fonksiyonunu da aynı düzen ve mantık içerisinde yazarak tri gramların frekanslarını hesapladık.
Sonrasında oluşturduğumuz void calculate_distances() fonksiyonu ile bigram ve trigramlarin frekanslari (tekrar sayilari) ile  hesaplamalar yaptık.
Eğer bi gram ve tri gramlarımızın ingilizce frekansları yüksek ise distances[0]'e 1 ekledik ve ing point kısmını artırmış olduk.
Tam tersi durumda ise aynı işlemi germ point'te uyguladık.
Son olarak da void detect_lang() fonksionunda puanların son durumuna baktık ve buna göre metnin dilni tahmin etmeye çalıştık.
Oluşturduğumuz tüm bu fonksiyonları en altta bulunan main fonksiyonunda çağırdık ve kodumuzu tamamlamış olduk.
Esasında, en altta main fonksiyonunu oluşturup oluşturduğumuz tüm fonksiyonları buraya çağırarak kodumuz için iki temel fayda sağlamış olduk. Birincisi, kodda oluşabilecek tüm karışıklıkları ve sorunları önlemektir. İkincisi ise, bu şekilde yaparak fonksiyonlarımızın kütüphaneden hemen sonra prototip olarak tanımlanmasına gerek kalmamasıdır.
