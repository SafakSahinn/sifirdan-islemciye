# Sıfırdan İşlemciye — Sayısal Donanım Tasarımı

**Yazarlar:** Şafak Şahin · Batuhan Hangün

![status](https://img.shields.io/badge/durum-aktif%20geli%C5%9Ftirme-yellow)
![language](https://img.shields.io/badge/dil-T%C3%BCrk%C3%A7e-red)
![engine](https://img.shields.io/badge/-XeLaTeX-008080?logo=latex&logoColor=white)
![chapters](https://img.shields.io/badge/b%C3%B6l%C3%BCm-2%2F9%20tamam-blue)

Bool cebri ve temel mantık kapılarından başlayıp kombinasyonel ve ardışık mantık
devreleri üzerinden ilerleyen, sonlu durum makinelerine (FSM) ve basit bir CPU
mimarisine kadar uzanan, Türkçe yazılmış kapsamlı bir dijital donanım tasarımı kitabı.

Kitap; lisans/yüksek lisans öncesi teorik temeli sağlamlaştırmayı, gate-level tasarım
ile fiziksel gerçekleme (silikon/layout) arasındaki köprüyü tam olarak kavratmayı
hedefler. Her kavram yalnızca tanım düzeyinde bırakılmaz: sezgisi, "neden"i ve elle
doğrulanmış örnekleriyle birlikte, başka bir kaynağa ihtiyaç duyurmayacak derinlikte
işlenir.

## İlerleme Yolu

<img src="assets/ilerleme-yolu.svg" alt="İlerleme Yolu" width="100%">

🟩 Tamamlandı &nbsp;&nbsp; 🟨 Devam Ediyor &nbsp;&nbsp; ⬜ Planlandı

## Mevcut Durum

| # | Bölüm | Durum |
|---|-------|:---:|
| 1 | Sayı Sistemleri ve Kodlama | ✅ Tamamlandı |
| 2 | Bool Cebri ve Mantık Kapıları | ✅ Tamamlandı |
| 3 | Kapı Seviyesinde Sadeleştirme (K-map) | ⬜ Planlandı |
| 4 | Kombinasyonel Mantık Devreleri | ⬜ Planlandı |
| 5 | Senkron Ardışık Mantık | ⬜ Planlandı |
| 6 | Yazmaçlar ve Sayaçlar | ⬜ Planlandı |
| 7 | Bellek ve Programlanabilir Mantık | ⬜ Planlandı |
| 8 | RTL, ASMD ve Kontrol Mantığı | ⬜ Planlandı |
| 9 | Basit Bir CPU Mimarisi | ⬜ Planlandı |

<details>
<summary><b>Bölüm 1 — detaylı ilerleme</b></summary>
<br>

- [x] Giriş
- [x] Sayı Tabanları ve Dönüşümler
- [x] İkili Aritmetik (Toplama, Çıkarma, Çarpma, Bölme)
- [x] Tümleyenler (Complements)
- [x] İşaretli İkili Sayılar
- [x] IEEE 754 ile Kayan Noktalı Sayı Gösterimi
- [x] BCD ve Diğer İkili Kodlar (Gray, ASCII, Parity)

</details>

<details>
<summary><b>Bölüm 2 — detaylı ilerleme</b></summary>
<br>

- [x] Giriş (tarihçe, ikili değişkenler, gerilim eşikleri)
- [x] Cebirsel Yapı Kavramı
- [x] Bool Cebirinin Aksiyomları
- [x] Düalite İlkesi ve Temel Teoremler
- [x] De Morgan Teoremi (Diğer Mantık İşlemleri dahil)
- [x] Sayısal Mantık Kapıları (çok girişli genişletme, pozitif/negatif mantık dahil)
- [x] Kanonik ve Standart Formlar (minterm/maxterm, Σ/Π simgeleri)
- [x] Entegre Devreler (entegrasyon seviyeleri, dijital lojik aileleri)

</details>

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

| Sütun | Araç | Logo |
|---|---|:---:|
| Dokümantasyon | XeLaTeX | <img src="assets/logos/latex.webp" height="40" alt="LaTeX"> |
| Simülasyon | Logisim | <img src="assets/logos/logism.svg" height="40" alt="Logisim"> |
| HDL | Xilinx Vivado | <img src="assets/logos/vivado.webp" height="40" alt="Vivado"> |
| Testbench | Icarus Verilog | <img src="assets/logos/icarus.png" height="40" alt="Icarus Verilog"> |
| Testbench | Verilator | <img src="assets/logos/verilator.png" height="40" alt="Verilator"> |
| Dalga Analizi | GTKWave | <img src="assets/logos/gtkwave.png" height="40" alt="GTKWave"> |
| Sentez | Yosys | <img src="assets/logos/yosys.png" height="40" alt="Yosys"> |
| Layout / ASIC | OpenLane | <img src="assets/logos/openlane.png" height="40" alt="OpenLane"> |
| Layout / ASIC | KLayout (SKY130) | <img src="assets/logos/klayout.png" height="40" alt="KLayout"> |

## Derleme

Kitap `latex/ana-kitap.tex` dosyasından, **XeLaTeX** ile derlenir (fontspec ve
unicode-math kullanıldığı için pdflatex ile derlenemez):

```
cd latex
xelatex ana-kitap.tex
```

Derlenmiş güncel PDF (`latex/ana-kitap.pdf`) da depoda takip edilmektedir.
