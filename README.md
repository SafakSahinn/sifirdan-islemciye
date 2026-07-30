# Sıfırdan İşlemciye — Sayısal Donanım Tasarımı

**Yazarlar:** Şafak Şahin - Batuhan Hangün

Bool cebri ve temel mantık kapılarından başlayıp kombinasyonel ve ardışık mantık
devreleri üzerinden ilerleyen, sonlu durum makinelerine (FSM) ve basit bir CPU
mimarisine kadar uzanan, Türkçe yazılmış kapsamlı bir dijital donanım tasarımı kitabı.

Kitap; lisans/yüksek lisans öncesi teorik temeli sağlamlaştırmayı, gate-level tasarım
ile fiziksel gerçekleme (silikon/layout) arasındaki köprüyü tam olarak kavratmayı
hedefler. Her kavram yalnızca tanım düzeyinde bırakılmaz — sezgisi, "neden"i ve elle
doğrulanmış örnekleriyle birlikte, başka bir kaynağa ihtiyaç duyurmayacak derinlikte
işlenir.

## Metodoloji

Öğrenilen her konsept dört ayrı sütundan geçirilir:

1. **Teori ve Dokümantasyon** — Bu depodaki LaTeX kitabı (Türkçe, profesyonel donanım
   kitabı formatında).
2. **Temel Simülasyon** — Logisim ile kapı seviyesinde görselleştirme.
3. **Sektörel Pratik** — Vivado/HDL ile üç modelleme türü (yapısal, veri akışı,
   davranışsal).
4. **Açık Kaynak ASIC Akışı** — Icarus/Verilator, GTKWave, Yosys, OpenLane/KLayout
   (SKY130 PDK) üzerinden testbench'ten layout'a tam bir akış.

## Kitabın Bölüm Planı

| Faz | Kapsam | Kitap Bölümleri |
|-----|--------|-----------------|
| 1 | Temeller | Sayı Sistemleri ve Kodlama · Bool Cebri ve Mantık Kapıları |
| 2 | Kombinasyonel mantık | Kapı Seviyesinde Sadeleştirme (K-map) · Kombinasyonel Mantık Devreleri |
| 3 | Ardışık mantık | Senkron Ardışık Mantık · Yazmaçlar ve Sayaçlar |
| 4 | Bellek ve programlanabilir mantık | Bellek ve Programlanabilir Mantık |
| 5 | RTL ve kontrol mantığı | RTL, ASMD ve Kontrol Mantığı |
| 6 | CPU mimarisi | Basit Bir CPU Mimarisi (uçtan uca RTL-to-GDSII) |

## Mevcut Durum

- **Bölüm 1 — Sayı Sistemleri ve Kodlama:** tamamlandı (sayı tabanları, ikili
  aritmetik, tümleyenler, işaretli sayılar, IEEE 754, BCD/Gray/ASCII/parity).
- **Bölüm 2 — Bool Cebri ve Mantık Kapıları:** devam ediyor. Tamamlanan kısımlar:
  Giriş (tarihçe, ikili değişkenler, gerilim eşikleri), Cebirsel Yapı Kavramı
  (postülat kavramı, küme/ikili işlem, cisim örneği), Bool Cebirinin Aksiyomları
  (Huntington postülatları, sıradan cebirle karşılaştırma, iki-değerli doğrulama),
  Düalite İlkesi ve Temel Teoremler, De Morgan Teoremi (ispat, doğruluk tablosu,
  $n$-değişkenli genelleme, tümleyen alma kısayolu). Sırada: Sayısal Mantık Kapıları.
- Sonraki bölümler henüz başlamadı.

## Derleme

Kitap `latex/ana-kitap.tex` dosyasından, **XeLaTeX** ile derlenir (fontspec ve
unicode-math kullanıldığı için pdflatex ile derlenemez):

```
cd latex
xelatex ana-kitap.tex
```

Derlenmiş güncel PDF (`latex/ana-kitap.pdf`) da depoda takip edilmektedir.
