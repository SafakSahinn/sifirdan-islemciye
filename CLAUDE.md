# PROJE BRİFİ — "Sıfırdan İşlemciye" Donanım Tasarımı Yaz Kampı

> **Bu dosya taşınabilir bağlamdır.** Bir Claude Code oturumunda proje köküne `CLAUDE.md`
> olarak koy → asistan otomatik okur, rolünü/planı/mevcut durumu anında kavrar.
> Yeni bir claude.ai sohbetine de yapıştırıp aynı şekilde devam edebilirsin.

---

## 0. Claude Code'da Nasıl Başlarım? (Devir-Teslim)
1. Proje kökü **Windows'ta** bu klasördür: `C:\Users\safak\Desktop\Logic-Design\`
   (bu `CLAUDE.md` zaten içinde). Alt yapı dosyaları `latex/` içinde. WSL'de kalıcı proje
   klasörü YOKTUR — WSL sadece araç çalıştırmak için kullanılır (bkz. §6).
2. Kaynaklar zaten bu klasörde:
   - Mano & Ciletti — *Digital Design, Global Edition* (PDF)
   - Şafak Şahin — *Açık Kaynak VLSI Araçları ve Geliştirme Ortamı Kurulum Rehberi* (PDF)
   - Oğuz Ergin — *Bilgisayar Mimarisi* (PDF) — LaTeX şablonunun kaynağı, bkz. §4/§9.
3. Claude'a şunu söyle: **"CLAUDE.md'yi oku ve Faz 1'e başla."**

---

## 1. Rol
Claude; kıdemli **Dijital Donanım Tasarım Başmühendisi** + **Akademik Danışman** + **Proje Yöneticisi**
gibi davranır. Ton: profesyonel, vizyoner, disiplinli, motive edici — sıkıcı bir öğretmen değil,
ekibini eğiten bir başmühendis.

## 2. Kullanıcı Profili
- EE yüksek lisansına başlayacak, tamamen **Donanım Tasarımı**na odaklı mühendis.
- Geçmiş: RTL-to-GDSII akışları, RISC-V mimarileri, davranışsal modelleme.
- Hedef: YL öncesi teorik temeli kusursuzlaştırmak; gate-level ↔ layout (silikon) köprüsünü
  tam kavramak; süreci profesyonelce dökümante etmek.
- **Tempo:** Yoğun (15+ saat/hafta). **Dökümantasyon dili:** Türkçe.

## 3. Ana Hedef
Bool cebri ve temel kapılardan → kombinasyonel → ardışık → **FSM** → **basit bir CPU mimarisi**.
Öğrenilen her konsept aşağıdaki 4 sütundan geçirilir.

## 4. Dört Sütunlu Metodoloji
1. **Teori & Dökümantasyon → LaTeX.** Profesyonel donanım kitabı formatı — altyapı olarak
   Oğuz Ergin'in *Bilgisayar Mimarisi* kitabının LaTeX şablonu (github.com/prof-oguzergin/
   bilgisayar-mimarisi) uyarlanıyor (Legrand Orange Book şablonu terk edildi), Türkçe.
2. **Temel Simülasyon → Logisim.** Kapı seviyesi görsellik; ekran görüntüleri kitaba eklenir.
3. **Sektörel Pratik → Vivado / HDL.** Her modül 3 modelleme türüyle: Structural, Dataflow, Behavioral.
4. **Açık Kaynak ASIC Akışı → WSL (Ubuntu) + Docker.** Icarus/Verilator (testbench) →
   GTKWave (dalga analizi) → Yosys (mantık sentezi) → OpenLane/KLayout (layout/GDSII, SKY130 PDK).

## 5. Kaynaklar ve Linkler
**Ana kitap:** Mano, M. Morris & Ciletti, Michael — *Digital Design, Global Edition* (Pearson, 712 s., 10 bölüm).

**YouTube oynatma listeleri:**
| # | Başlık | Sahibi | Hacim | Rolü | Link |
|---|--------|--------|-------|------|------|
| 1 | Mantık Devresi Tasarımı | Oğuz Ergin (TOBB ETÜ) | 56 video | Akademik omurga | https://www.youtube.com/playlist?list=PLvNq8wrSYGAVB2spsV_hoOZW-ogot4Gd2 |
| 2 | Mantıksal Devre Tasarımı – Logic Design | Mehmet Burak Aykenar | 24 video | Pekiştirici | https://www.youtube.com/playlist?list=PLZyLAHn50933YtB32ECJujIskuFJiz8AJ |
| 3 | FPGA from Zero to Hero (Podcast) | Expaths Türkiye | Podcast | Sektörel/kariyer | https://www.youtube.com/playlist?list=PLbv31UO1rAEEA1OEMvcxurI_phmIPfhsK |
| 4 | Verilog Eğitimi | Kerim Turak | 19 video | HDL pratiği (Verilog→SystemVerilog) | https://www.youtube.com/playlist?list=PLjDoPE3CoNjmveQnXhlkgjrFsS7ivKoLG |

> Not: Video başlıkları şu an liste düzeyinde biliniyor. Her modüle gelindiğinde, o modülle
> eşleşen videolar tek tek çıkarılıp ilgili bölüme referanslanacak.

## 6. Ortam Durumu ve Araç Yerleşimi
| Araç | Durum | Nerede |
|------|-------|--------|
| WSL/Ubuntu | ✓ Kurulu | WSL |
| Docker | ✓ Kurulu | WSL |
| Icarus/Verilator, Yosys, GTKWave, KLayout, OpenLane + SKY130 | ✓ Kurulu (kullanıcının rehberiyle) | WSL |
| Vivado | ✓ Kurulu | **Windows** (GUI) |
| Logisim | ✓ Kurulu | **Windows** (GUI) |
| TeX (LaTeX) — TeXstudio + MiKTeX | ✓ Kurulu (2026-07-27) | **Windows** |

**Önemli yerleşim kuralı (2026-07-27'de kullanıcı tarafından netleştirildi/düzeltildi):**
- **Tek doğru kaynak (single source of truth): proje dosyalarının TAMAMI Windows'ta**,
  bu klasörün içinde (`C:\Users\safak\Desktop\Logic-Design\`) tutulur — `latex/`, ileride
  `hdl/`, `logisim/` alt klasörleriyle. **WSL'de kalıcı proje dosyası TUTULMAZ.**
  (Önceki bir oturumda dosyalar WSL'de `~/donanim-yaz-kampi` altında tutulmaya başlanmıştı;
  kullanıcı bunun yanlış olduğunu belirtti ve her şey Windows'a taşındı — bkz. `latex/`
  altındaki `_eski_legrand_denemesi/` ve `_sablon_kaynaklari/` klasörleri, o taşımadan
  kalan arşiv/referans dosyalarıdır.)
- **WSL yalnızca oradaki araçları (iverilog, yosys, gtkwave, klayout, openlane) çalıştırmak
  için kullanılır** — bir çalışma alanı/depo değildir. Bu araçlar gerektiğinde Windows'taki
  dosyalara `/mnt/c/Users/safak/Desktop/Logic-Design/...` yolundan erişerek (WSL tarafından)
  çalıştırılır; proje dosyaları asla WSL home dizinine kopyalanmaz.
- **Logisim, Vivado, LaTeX editörü (TeXstudio)** zaten Windows'ta GUI uygulaması olarak çalışır,
  doğrudan bu klasördeki dosyaları açar.
- **Not (Claude Code):** Claude Code WSL terminalinde çalıştığı için ağ erişimi zaten vardır;
  claude.ai web sohbetindeki "network egress" ayarına burada gerek yoktur.

## 7. Açık İşler
- [x] Windows'a TeXstudio + MiKTeX kur (kullanıcı tarafından 2026-07-27'de tamamlandı).
- [x] TeXstudio'da varsayılan derleyiciyi **XeLaTeX**'e ayarla ve `latex/ana-kitap.tex`'i
      derle — kullanıcı 2026-07-27'de doğruladı, sorunsuz çalışıyor.
- [x] Künye sayfasındaki şablon artığı kullanıcının adı ve lisans notuyla değiştirildi
      (artık `latex/ana-kitap.tex` içinde; eski Legrand denemesi `_eski_legrand_denemesi/`'de).
- [ ] **`bolum01-sayi-sistemleri/bolum01.tex`, §1.3 Tümleyenler'in başındaki "Neden Çıkarmayı
      Toplamaya Çeviriyoruz?" bilgi notunda düz metin bir ileri referans var** ("ilerideki
      Toplayıcı Devreler bölümünde göreceğiz") — Bölüm 4 (Kombinasyonel Mantık Devreleri,
      adder konusu) yazıldığında buraya dönüp gerçek bir `\label`/`\ref` ile değiştirilmeli.
- [ ] İleride OpenLane 2 (Python/Nix) geçişini değerlendir (klasik OpenLane şimdilik yeterli).

## 8. Faz Haritası ve Kitap Bölüm Planı

**Faz**, kampın/çalışmanın genel ilerleme aşamasıdır (birden fazla kitap bölümünü kapsayabilir,
dört sütunu — LaTeX/Logisim/Vivado/WSL — birlikte kapsar). **Bölüm**, `latex/` altındaki somut
kitap bölümüdür (`bolumNN-.../bolumNN.tex`). İkisi karıştırılmamalı — bir faz genelde 1-2 bölüm
içerir.

| Faz | İçerik | Mano Bölüm | Kitabın Bölümleri |
|-----|--------|-----------|--------------------|
| **1 (AKTİF)** | Temeller + Ortam | 1–2 | **Bölüm 1:** Sayı Sistemleri ve Kodlama · **Bölüm 2:** Bool Cebri ve Mantık Kapıları |
| 2 | Kombinasyonel mantık + HDL + testbench | 3–4 | Bölüm 3: Kapı Seviyesinde Sadeleştirme (K-map) · Bölüm 4: Kombinasyonel Mantık Devreleri (adder/mux/decoder) |
| 3 | Ardışık mantık | 5–6 | Bölüm 5: Senkron Ardışık Mantık (latch/flip-flop) · Bölüm 6: Yazmaçlar ve Sayaçlar |
| 4 | Bellek + programlanabilir mantık | 7 | Bölüm 7: Bellek ve Programlanabilir Mantık |
| 5 | RTL/ASMD, kontrol mantığı — **CPU köprüsü** | 8 | Bölüm 8: RTL, ASMD ve Kontrol Mantığı |
| 6 | Basit CPU mimarisi (uçtan uca RTL-to-GDSII) | — | Bölüm 9: Basit Bir CPU Mimarisi |

**Not (2026-07-27 düzeltmesi):** Kitaba ilk yazılan bölüm yanlışlıkla doğrudan Bool Cebri
(Mano Bölüm 2'nin konusu) olmuştu; Mano Bölüm 1'in konusu olan **Sayı Sistemleri ve Kodlama**
atlanmıştı. Bu düzeltildi: eski `bolum01-bool-cebri/` → `bolum02-bool-cebri/` olarak yeniden
numaralandırıldı, yeni `bolum01-sayi-sistemleri/` bölümü Bölüm 1 olarak plana eklendi (içerik
henüz yazılmadı, bkz. §9).

## 9. Mevcut Adım — NEREDE KALDIK?
**Faz 0 (Ortam Kurulumu): TAMAM.** WSL, Docker, açık kaynak zincir (iverilog/yosys/gtkwave/
klayout/docker) doğrulanmış kurulu. Windows'a TeX editörü (TeXstudio+MiKTeX) da kullanıcı
tarafından kuruldu (2026-07-27).

**Proje kökü:** Windows'ta bu klasör: `C:\Users\safak\Desktop\Logic-Design\` (tek doğru kaynak
— bkz. §6). Alt klasör: `latex/` (kitap). WSL'de kalıcı proje dosyası YOK, sadece gerektiğinde
araç çalıştırmak için `/mnt/c/...` üzerinden bu klasöre erişilir.

**LaTeX şablonu değişti (2026-07-27):** Legrand Orange Book şablonu terk edildi. Yeni altyapı,
Oğuz Ergin'in `prof-oguzergin/bilgisayar-mimarisi` reposundan (Türkçe, RISC-V bilgisayar mimarisi
ders kitabı) uyarlanıyor. Repo'dan yalnızca kaynak dosyalar (pdf/görsel/`.git` hariç) referans
olarak `latex/_sablon_kaynaklari/bilgisayar-mimarisi-orjinal/` altına alındı. Oradan
`preamble.tex`, `renk-modu.tex`, `tikz-sekiller-makrolar.tex` (K-map çizim makroları `\karnoiki/
\karnouc/\karnodort` dahil) kopyalanıp `latex/` köküne yerleştirildi. Bu şablon `tanim`/`ornek`/
`alistirma`/`bilginot`/`terimnotu`/`karsilastirma` kutu ortamlarını ve modüler `\bolumekle`
bölüm sistemini sağlıyor.
**ÖNEMLİ — derleme motoru:** Bu şablon `fontspec`+`unicode-math` kullanıyor, yani **XeLaTeX**
(pdflatex DEĞİL) ile derlenmeli; TeXstudio'da varsayılan derleyici XeLaTeX'e ayarlanmalı.
Eski Legrand denemesi `latex/_eski_legrand_denemesi/` altına arşivlendi, artık **kullanılmıyor**.
Yeni ana dosya: `latex/ana-kitap.tex`.
Kapak sayfası kullanıcı isteğiyle şimdilik atlandı (düz başlık sayfası var), sonraki bir adımda
eklenecek.

**Faz 1 (AKTİF) — ilk somut görev, dört sütun. Kullanıcı adım adım, küçük parçalar halinde
ilerlemek istiyor: önce konu gerçekten anlatılıyor/tartışılıyor (canlı, karşılıklı), sonra o
parça kitaba yazılıyor — sadece metin üretip onaya sunmak yetmiyor. Alıştırmaların cevapları da
artık alıştırmanın hemen altına yazılıyor (ayrı bir cevap anahtarı yok).**

**Bölüm 1 — Sayı Sistemleri ve Kodlama (`bolum01-sayi-sistemleri/bolum01.tex`):
devam ediyor.** Kullanıcı erkenden §1.2'nin ilk halini "yüzeysel" bulup
**derinlik/kendine-yeterlilik** standardını netleştirdi (bkz. `feedback_book_depth_self_contained`
hafıza dosyası) — bu standart tüm bölüm boyunca korunuyor: her "neden" açıklanıyor, gerekli
kısayol/trikler veriliyor, örnekler elle doğrulanıyor, ve her yeni konuya başlamadan önce
Mano&Ciletti'nin PDF'i (`venv+pypdf` ile, bkz. §"Mano karşılaştırma yöntemi" notu) taranıp
kapsam netleştiriliyor. Güncel bölüm sırası (2026-07-27 itibarıyla):
- Bölüm açılışı + Öğrenme Hedefleri kutusu.
- §1.1 Giriş.
- **§1.2 Sayı Tabanları ve Dönüşümler — TAMAMLANDI** (9 alt bölüm): Pozisyonel Sayı Sistemi →
  İkiliden Ondalığa → Ondalıktan İkiliye ("neden kalan, bölüm değil" ispatı) →
  Sekizlik/Onaltılık: Sembol Sorunu (A-F'in neden var olduğu) → Sekizlik/Onaltılıktan
  Ondalığa → Ondalıktan Sekizliğe/Onaltılığa → İkili-Sekizlik-Onaltılık Arası Gruplama →
  Tabanı Bilinmeyen İşlemlerde Taban Bulma → Kesirli Sayı Dönüşümleri.
- **§1.3 İkili Aritmetik: Toplama, Çıkarma, Çarpma ve Bölme — TAMAMLANDI.** Her işlem için
  önce genel $r$-tabanlı formül (`tanım` kutusu), sonra ikili örnek: Toplama (elde formülü,
  full adder'a bağlantı) → Çıkarma (borç formülü) → Çarpma (kaydır-ve-topla, $\sum b_i A r^i$)
  → Bölme (kaydır-ve-çıkar algoritması). Mano §1.2'nin (sayfa 22) karşılığı + Mano'da olmayan
  bölme kısmı kullanıcı isteğiyle eklendi.
- **§1.4 Tümleyenler (Complements) — TAMAMLANDI.** Mano §1.5 ile tam karşılaştırıldı, Mano'da
  olan her şey (sekizlik/onaltılıkta $(r{-}1)$'in tümleyeni, noktalı sayılarda tümleyen alma,
  tümleyenin tümleyeni özelliği, basamak eşitleme kuralı) dahil, hatta ayrı `\subsection`lara
  bölünüp örneklendirildi.
- **§1.5 İşaretli İkili Sayılar — TAMAMLANDI.** Mano §1.6 ile karşılaştırıldı: İşaret Biti ve
  Yorumlama → İşaret-Büyüklük Gösterimi → İşaretli Tümleyen Sistemi (1'in/2'nin tümleyeni) →
  Neden 2'nin Tümleyeni Tercih Edilir (tek sıfır + aritmetik kolaylığı, tam 4-bit karşılaştırma
  tablosu) → İşaretli Toplama (4 durum + taşma/overflow kavramı) → İşaretli Çıkarma (aynı
  toplayıcı donanımın yeniden kullanılması ile kapanış).

- **§1.6 IEEE 754 ile Kayan Noktalı Sayı Gösterimi — TAMAMLANDI.** Mano'da YOK (712 sayfalık
  kitapta sadece 4 sayfada geçiyor, hiçbiri Bölüm 1'de) — Oğuz Ergin'in "Mantık Devresi
  Tasarımı" oynatma listesinden bir video kaynaklı (`index=3`, "IEEE 754 ile Ondalıklı
  Sayıların Gösterilmesi"). Neden Sabit Nokta Yetmez → Normalizasyon (örtük baştaki $1$
  trick'i) → Format ve Bias (neden 2'nin tümleyeni değil biaslı üs — karşılaştırma kolaylığı)
  → Ondalıktan IEEE 754'e ($0.6875$ örneği, §1.2'deki kesirli dönüşüm sonucumuzu yeniden
  kullanarak) → IEEE 754'ten Ondalığa (ters yön, $-5$ örneği) → Özel Değerler (±0/±∞/NaN/
  denormal) → kapanış: $0.1+0.2\neq0.3$'ün nedeni artık tam açıklanabiliyor (§1.2'deki "her
  kesir sonlanmaz" notuna geri bağlanıyor).

Sırada: BCD ve diğer ikili kodlar (Mano §1.7 "Binary Codes" — Gray code, ASCII, parity/hata
sezme), muhtemelen §1.7. Mano §1.1 (genel dijital sistemler tarihi/girişi) ve §1.8 (yazmaçlara
giriş) kullanıcı kararıyla bilinçli atlandı — §1.1 tarzı genel tarihsel içerik (bilgisayar
tarihi, hesap makineleri) kitap daha ilerleyince ayrıca ele alınacak; §1.8 ise zaten planlı
olan Bölüm 6 (Yazmaçlar ve Sayaçlar)'da tam işlenecek. **Bu, aynı derinlik standardıyla devam
edecek — konu önce anlatılıp tartışılıyor, sonra yazılıyor.**

**Bölüm 2 — Bool Cebri ve Mantık Kapıları (`bolum02-bool-cebri/bolum02.tex`, eski adıyla
`bolum01-bool-cebri`): devam ediyor.** Şu ana kadar yazılanlar:
- Bölüm açılışı + Öğrenme Hedefleri kutusu.
- §2.1 Giriş (bir önceki bölüme — sayı sistemlerine — bağlayan bir geçiş cümlesiyle
  güncellendi, artık "pat diye" başlamıyor), §2.2 İkili Değişkenler ve Mantık Fonksiyonları.
- §2.3 Bool Cebrinin Aksiyomları (Huntington postülatları, anahtarlama devresi yorumu,
  Postülat 2 örneği, Postülat 1 alıştırması + **Çözümü**).
- §2.4 Düalite İlkesi ve Temel Teoremler (Teorem 1'in tam türetimi, temel teoremler tablosu,
  Teorem 4 alıştırması + **Çözümü**).
Sırada: De Morgan Teoremi → 7 temel kapı. **Henüz XeLaTeX ile derlenip görsel doğrulama
kullanıcı tarafından yapıldı ve sorunsuz çalıştı (2026-07-27).**
2. **Logisim:** 7 temel kapıyı (AND, OR, NOT, NAND, NOR, XOR, XNOR) kur, doğruluk tablolarını
   simüle et, ekran görüntülerini al → kitaba ekle. **Henüz başlanmadı.**
3. **Vivado / HDL:** Temel kapıları / basit bir Bool fonksiyonunu 3 modelleme türüyle yaz
   (Structural, Dataflow, Behavioral). **Henüz başlanmadı.**
4. **WSL akışı:** Icarus ile testbench yaz → GTKWave'de dalga formunu doğrula → Yosys ile sentezle
   (kapı seviyesi netlist'i incele). Kullanıcı notu: bu adım "vakti geldiğinde" çalıştırılacak,
   yani doğal pillar sırasına göre — hemen değil. **Henüz başlanmadı.**

**Kullanıcı "Faz 1" dediğinde bu görev paketi başlatılır.**
