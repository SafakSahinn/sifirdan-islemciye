# Sıfırdan İşlemciye — Sayısal Donanım Tasarımı

**Yazarlar:** Şafak Şahin · Batuhan Hangün

![status](https://img.shields.io/badge/durum-aktif%20geli%C5%9Ftirme-yellow)
![language](https://img.shields.io/badge/dil-T%C3%BCrk%C3%A7e-red)
![engine](https://img.shields.io/badge/-XeLaTeX-008080?logo=latex&logoColor=white)
![chapters](https://img.shields.io/badge/b%C3%B6l%C3%BCm-1%2F9%20tamam-blue)

Bool cebri ve temel mantık kapılarından başlayıp kombinasyonel ve ardışık mantık
devreleri üzerinden ilerleyen, sonlu durum makinelerine (FSM) ve basit bir CPU
mimarisine kadar uzanan, Türkçe yazılmış kapsamlı bir dijital donanım tasarımı kitabı.

Kitap; lisans/yüksek lisans öncesi teorik temeli sağlamlaştırmayı, gate-level tasarım
ile fiziksel gerçekleme (silikon/layout) arasındaki köprüyü tam olarak kavratmayı
hedefler. Her kavram yalnızca tanım düzeyinde bırakılmaz — sezgisi, "neden"i ve elle
doğrulanmış örnekleriyle birlikte, başka bir kaynağa ihtiyaç duyurmayacak derinlikte
işlenir.

## İlerleme Yolu

```mermaid
flowchart TD
    subgraph Row1[" "]
        direction LR
        B1["Bölüm 1<br/>Sayı Sistemleri"]
        B2["Bölüm 2<br/>Bool Cebri ve<br/>Mantık Kapıları"]
        B3["Bölüm 3<br/>K-map"]
        B4["Bölüm 4<br/>Komb. Mantık"]
        B5["Bölüm 5<br/>Ardışık Mantık"]
        B6["Bölüm 6<br/>Yazmaçlar"]
    end

    subgraph Row2[" "]
        direction RL
        B9["Bölüm 9<br/>CPU Mimarisi"]
        B8["Bölüm 8<br/>RTL/ASMD"]
        B7["Bölüm 7<br/>Bellek"]
    end

    B1 --> B2 --> B3 --> B4 --> B5 --> B6
    B6 --> B7
    B7 --> B8 --> B9

    class B1 done
    class B2 progress
    class B3,B4,B5,B6,B7,B8,B9 todo

    classDef done fill:#2ea44f,stroke:#1a7f37,color:#ffffff,stroke-width:2px
    classDef progress fill:#d4a72c,stroke:#9a6700,color:#ffffff,stroke-width:2px
    classDef todo fill:#e1e4e8,stroke:#8c959f,color:#24292f,stroke-width:1px
    style Row1 fill:transparent,stroke:transparent
    style Row2 fill:transparent,stroke:transparent
```

🟩 Tamamlandı &nbsp;&nbsp; 🟨 Devam Ediyor &nbsp;&nbsp; ⬜ Planlandı

<details>
<summary><b>Bölüm 2 — detaylı ilerleme</b></summary>
<br>

- [x] Giriş (tarihçe, ikili değişkenler, gerilim eşikleri)
- [x] Cebirsel Yapı Kavramı
- [x] Bool Cebirinin Aksiyomları
- [x] Düalite İlkesi ve Temel Teoremler
- [x] De Morgan Teoremi
- [ ] Sayısal Mantık Kapıları
- [ ] Bool Fonksiyonları
- [ ] Kanonik ve Standart Formlar
- [ ] Diğer Mantık İşlemleri
- [ ] Entegre Devreler

</details>

## Mevcut Durum

| # | Bölüm | Durum |
|---|-------|:---:|
| 1 | Sayı Sistemleri ve Kodlama | ✅ Tamamlandı |
| 2 | Bool Cebri ve Mantık Kapıları | 🟨 Devam ediyor |
| 3 | Kapı Seviyesinde Sadeleştirme (K-map) | ⬜ Planlandı |
| 4 | Kombinasyonel Mantık Devreleri | ⬜ Planlandı |
| 5 | Senkron Ardışık Mantık | ⬜ Planlandı |
| 6 | Yazmaçlar ve Sayaçlar | ⬜ Planlandı |
| 7 | Bellek ve Programlanabilir Mantık | ⬜ Planlandı |
| 8 | RTL, ASMD ve Kontrol Mantığı | ⬜ Planlandı |
| 9 | Basit Bir CPU Mimarisi | ⬜ Planlandı |

Bölüm 2'nin alt başlık bazında ilerlemesi için yukarıdaki açılır listeye bakabilirsin.

## Metodoloji

Öğrenilen her konsept dört ayrı sütundan geçirilir:

1. **Teori ve Dokümantasyon** — Bu depodaki LaTeX kitabı (Türkçe, profesyonel donanım
   kitabı formatında).
2. **Temel Simülasyon** — Logisim ile kapı seviyesinde görselleştirme.
3. **Sektörel Pratik** — Vivado/HDL ile üç modelleme türü (yapısal, veri akışı,
   davranışsal).
4. **Açık Kaynak ASIC Akışı** — Icarus/Verilator ile testbench, GTKWave ile dalga
   analizi, Yosys ile sentez, OpenLane/KLayout (SKY130 PDK) ile layout — testbench'ten
   GDSII'ye tam bir akış.

## Kullanılan Araçlar

| Sütun | Araç | |
|---|---|---|
| Dokümantasyon | XeLaTeX | ![LaTeX](https://img.shields.io/badge/-XeLaTeX-008080?logo=latex&logoColor=white) |
| Simülasyon | Logisim | ![Logisim](https://img.shields.io/badge/-Logisim-4A90D9) |
| HDL | Xilinx Vivado | ![Vivado](https://img.shields.io/badge/-Vivado-A31F34) |
| Testbench | Icarus Verilog / Verilator | ![Icarus](https://img.shields.io/badge/-Icarus%20%2F%20Verilator-E67E22) |
| Dalga Analizi | GTKWave | ![GTKWave](https://img.shields.io/badge/-GTKWave-16A085) |
| Sentez | Yosys | ![Yosys](https://img.shields.io/badge/-Yosys-6A5ACD) |
| Layout / ASIC | OpenLane · KLayout (SKY130) | ![OpenLane](https://img.shields.io/badge/-OpenLane%20%2F%20KLayout-2E8B57) |

> Not: Bu araçların çoğu niş, açık kaynak EDA projeleri olduğu için hazır bir logo
> servisinde (shields.io/simple-icons) resmî ikonları bulunmuyor; rozetler bu yüzden
> düz renkli. Gerçek logo dosyalarını paylaşırsan (portrelerde yaptığımız gibi) buraya
> gömebilirim.

## Derleme

Kitap `latex/ana-kitap.tex` dosyasından, **XeLaTeX** ile derlenir (fontspec ve
unicode-math kullanıldığı için pdflatex ile derlenemez):

```
cd latex
xelatex ana-kitap.tex
```

Derlenmiş güncel PDF (`latex/ana-kitap.pdf`) da depoda takip edilmektedir.
