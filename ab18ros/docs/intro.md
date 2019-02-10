# ROS ve Gazebo ile Robotik Atölyesi

## Robotik Nedir

- Bir çok mühendisliğinin ortak çalışma alanı
  - Makine
  - Elektronik
  - Bilgisayar
  - Kontrol
  - Mekatronik
  - Uçak
  - Uzay
- Robot kelimesi Çek Yazar Karel Capek'in 1920 yılında yayınlanan Rossum's Universal Robots  isimli oyunundan alınmıştır. "Robota" kelimesinden gelmekte. Oxford sözlüğüne göre "Robotik" kelimesi ilk olarak Isaac Asimov'n "Yalancı" adındaki  bilim kurgu romanında geçmekte.

> ## Robotiğin 3 Kuralı
>
> Isaac Asimov, 'I, Robot'
>
> 1. Bir robot bir insana zarar veremez ya da bir insanın zarar görmesine seyirci kalamaz
> 2. Bir robot 1. kuralla çelişmediği sürece bir insanın emirlerine uymak zorundadır
> 3. Bir robot 1. ve 2. kuralla çelişmediği sürece kendinin zarar görmesine izin veremez

- 1948'de Norbert Wiener Sibernetiğin prensiplerini tanımlamış, bu prensipler pratik robotiğin temelleri olmuştur

> ## Sibernetik
>
> Canlı ve cansız tüm karmaşık sistemlerin denetlenmesi ve yönetilmesini inceleyen bilim dalıdır.
>
> Sibernetiğin muhteşem döngüsü:
>
> 1. Hissediş
> 2. Karar
> 3. Düzeltme![img](https://upload.wikimedia.org/wikipedia/commons/thumb/e/ed/Ideal_feedback_model.svg/1024px-Ideal_feedback_model.svg.png)
>
> 

- İlk otonom robot 20. yüzyılın yarısında ortaya çıkıyor. Resimdeki robotun adı "Unimate"![unimate_working.jpg](https://my.ilstu.edu/~kldevin/Introduction_to_robotics2/unimate_working.jpg)

## Robotik Alanının Zorlukları

```java

import Robot.*;

public class incredible {

    public static void main(String[] args) {
        
        Robot myFancyRobot = new Robot();
        boolean isShitDone = myFancyRobot.autonomus.getTheShitDone();

        if( isShitDone ){
			System.out.println("Its almost impossible");
        } else {
            System.out.println("This is probably the case mate :/");
        }
    }
}



```



> ## Tamam da neden?
>
> Otonom olmak, düşümek, davranmak hatta karar vermek nedir?
>
> Üzerine biraz düşününce tabi...
>
> | Genel Tanım                     | Alıntılar                                                    |
> | ------------------------------- | ------------------------------------------------------------ |
> | İnsan gibi düşünen sistemler    | _“[The automation of] activitiesthat we associate with human thinking, activitiessuch as decision-making, problem solving,learning. . .”_ (Bellman, 1978)<br /><br />_“The exciting new effortto make computers<br/>think . . . machines with minds, in the full
and literal sense”_(Haugeland, 1985) |
> | İnsan gibi davranan sistemler   | _“The art of creating machines that perform functionsthatrequire intelligencewhen performed by people” (Kurzweil, 1990)_<br /><br />_“The study of how to make computers do<br/>things at which, at the moment, people are
better”_  (Rich and Knight, 1991) |
> | Rasyonel düşünebilen sistemler  | _“The study of mental faculties through the use of computational models”_
(Charniak and McDermott, 1985)<br /><br />_“The study of the computations that make it possible to perceive, reason, and act”_ (Winston, 1992) |
> | Rasyonel davranabilen sistemler | _ “A field of study that seeks to explain and emulate intelligent behavior in terms of
computational processes”_ (Schalkoff, 1990)<br /><br />_“Thebranch of computersciencethatis concerned with the automation of intelligent behavior”_ (Luger and Stubblefield, 1993) |

![challenges in robotics](https://20kh6h3g46l33ivuea3rxuyu-wpengine.netdna-ssl.com/wp-content/uploads/2018/02/robotics-challenges-1024x453.jpg) 

_Görsel [bu bağlantıdan](https://www.therobotreport.com/10-biggest-challenges-in-robotics/) edilnilmiştir._

> - [Waymo'nun otonom aracı](https://www.youtube.com/watch?time_continue=112&v=aaOB-ErYq6Y)
> - [Boston Dynamics Spot Mini](https://www.youtube.com/watch?v=Ve9kWX_KXus)
> - [Kuka'nın müzik yapan robotları](https://www.youtube.com/watch?v=bAdqazixuRY)
> - [Darpa Urban Challange](https://www.youtube.com/watch?v=P0NTV2mbJhA)
> - [Darpa Challange](https://www.youtube.com/watch?v=8P9geWwi9e0)



**Tuhaf soru**: Bir işi kaç tane robotun yapacağı, robotlara yeni bi özellik katar mı? Tanımlarını değiştirir mi?



## Robotu meydana getiren bileşenler

### Hareket

- Robot nasıl hareket eder?
  - Çizgisel
  - Dairesel
  - _Gerçekleştirme şekilleri göre değişiklik gösterir_
- Robotun nereleri hareket eder?
  - Kolu, Bacağı. _Bacağı?_
  - Tekerlekleri. _Peki ya bacağı?_
  - Kendisi??!? _Tamam da bacağı?_



### Algı

- Envayi çeşit sensör tipi
  - Mesafe
    - Sonar
    - Lidar
    - Stereo Camera
  - Renk matrisi
    - Bildiğin kamera
  - Dokunma
  - Sıcaklık
  - Nem
  - Yükseklik
  - Pusula
    - IMU
  - İvme
    - IMU
  - Açısal Hız
    - _Yine_ IMU

> ### O kadar şeyi algıladık, şimdi ne yapıcaz?
>
> Hangi problemi çözeceğimize karar vereceğiz. _Ancak büyük parçalar halinde değil_ 
>
> - Şerit Takibi
> - Konum belirleme
> - Basit yol planlama
> - Engelden kaçma
>
> 
>
>  Başka bir problemi çözmek için nasıl bir tasarımla yaklaşım sergiliyorsak, hemen hemen aynı yaklaşımları sergileyeceğiz.
>
> 1. Sorgu
> 2. Araştırma
> 3. Çözüm geliştirme
> 4. En başarılı bulunan çözümün planlaması
> 5. Prototipleme
> 6. Test ve Doğrulama
> 7. İyileştirme

_**Premature optimization is our great enemy**_

### Etkileşim

_Kendisi harici herhangi birşeyle etkileşime geçtiği hemen hemen herşey_

- Tutmak
- İttirmek
- Düğmeye basmak
- Birşeyler yazmak

### Gezi

- Tek Tekerlekli
- Çok tekerlekli
  - Omni Drive
  - Differential Drive
  - Skid steer Drive
  - Ackermann Drive
- Kollu bacaklı
  - İki bacaklı
  - 4 bacaklı
- Paletli
- Kanatlı
- _Kolsuz, bacaksız_
  - Yılan
- Yüzebilen

## _Özerk_ Robotlar, şaka şaka, Otonom Robotlar

- Otonomluk nedir?

### Otonomluk seviyeleri

| Seviye                     | Açıklaması                                                   |
| -------------------------- | ------------------------------------------------------------ |
| Seviye 1: Bayağı otonom    | İnsanların robotların tüm hareketleri üzerinde tam kontrol sahibi olduğu sistemler. Genellikle _teleoperasyon_ ile yönetilirler<br />**İnsan Kişi**: "_Ketılda_ Çay demliyim, içilir" |
| Seviye 2: Ha gayret otonom | Operatörün orta ve yüksek seviye görevleri verdiği, robotların işleri nasıl tamamlayacaklarına kendilerinin karar verdiği sistemler.<br />**İnsan Kişi**: "Sevgili _robot_ bana çay demle": |
| Seviye 3: Epeycene otonom  | İnsan müdahalesi gerektirmeden uzun süreler boyunca, yapacağa işe de nasıl yapacağına da kendi karar verebilen sistemler.<br />**Robot birey**: "Çay demledim seversin, bergamot da attım, mis" |

## Genel Maksatlı ve Özel Maksatlı Robotlar

_Sadece sınıfta muhabbet edicez bunun üzerine_

## Hocam Hani ROS?

_Wait a little bit more my young padawan_