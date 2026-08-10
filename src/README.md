# Kod Örnekleri

<img src="../assets/logos/c.webp" height="50" alt="C">&nbsp;&nbsp;&nbsp;
<img src="../assets/logos/cpp.webp" height="50" alt="C++">&nbsp;&nbsp;&nbsp;
<img src="../assets/logos/java.webp" height="50" alt="Java">&nbsp;&nbsp;&nbsp;
<img src="../assets/logos/python.webp" height="50" alt="Python">

Bu klasör, kitaptaki (bkz. ana repo [`README.md`](../README.md)) kod
örneklerinin **çalıştırılabilir hâlini** içerir. Kitapta gördüğünüz her kod
bloğu, buradaki bir dosyanın birebir kopyasıdır. PDF'ten elle kopyalamanıza
gerek kalmadan doğrudan indirip kendi derleyicinizde/yorumlayıcınızda
çalıştırabilir, kitaptaki sonucun gerçekten doğru olduğunu kendiniz
doğrulayabilirsiniz. Dosyalar, kitaptaki gibi okunabilirlik için kısaltılmış
parçalar değil; gerekli `#include`/`import` ifadeleriyle birlikte eksiksiz,
gerçekten derlenip çalışan programlardır.

## Klasör yapısı

Her bölüm klasörü, kitaptaki alt bölüm numarasına göre ayrılır; her alt
bölümün içindeki kod dosyaları da `kod-dosyalari/` alt klasörüne düşer:

```
src/
├── bolum01/
│   └── 1.6/
│       └── kod-dosyalari/   → IEEE 754: NaN örnekleri (C, C++, Java)
└── bolum03/
    └── 3.10/
        └── kod-dosyalari/   → Quine-McCluskey algoritması (Python, C++)
```

## Mevcut dosyalar

### Bölüm 1.6: IEEE 754 ile Kayan Noktalı Sayı Gösterimi

NaN'ın kendisine bile eşit olmadığını (`x != x`) üç dilde gösteren, birbirinin
birebir karşılığı üç kısa program:

| Dosya | Dil | Çalıştırma |
|---|:---:|---|
| [`bolum01/1.6/kod-dosyalari/nan_ornegi.c`](bolum01/1.6/kod-dosyalari/nan_ornegi.c) | <img src="../assets/logos/c.webp" height="24" alt="C"> | `gcc nan_ornegi.c -o nan && ./nan` |
| [`bolum01/1.6/kod-dosyalari/nan_ornegi.cpp`](bolum01/1.6/kod-dosyalari/nan_ornegi.cpp) | <img src="../assets/logos/cpp.webp" height="24" alt="C++"> | `g++ nan_ornegi.cpp -o nan && ./nan` |
| [`bolum01/1.6/kod-dosyalari/NanOrnegi.java`](bolum01/1.6/kod-dosyalari/NanOrnegi.java) | <img src="../assets/logos/java.webp" height="24" alt="Java"> | `javac NanOrnegi.java && java NanOrnegi` |

### Bölüm 3.10: Quine-McCluskey Algoritması

Aşama 1 (asal kapsayan bulma) ve Aşama 2'yi (kapsama tablosuyla temel asal
kapsayan seçme) birebir izleyen, her terimi bir *(değer, maske)* tamsayı
çifti olarak tutan iki gerçekleme:

| Dosya | Dil | Kullanım |
|---|:---:|---|
| [`bolum03/3.10/kod-dosyalari/quine_mccluskey.py`](bolum03/3.10/kod-dosyalari/quine_mccluskey.py) | <img src="../assets/logos/python.webp" height="24" alt="Python"> | `from quine_mccluskey import sadelestir` |
| [`bolum03/3.10/kod-dosyalari/quine_mccluskey.cpp`](bolum03/3.10/kod-dosyalari/quine_mccluskey.cpp) | <img src="../assets/logos/cpp.webp" height="24" alt="C++"> | `asalKapsayanlariBul`/`sadelestir` fonksiyonlarını kendi projenize kopyalayın |

Örnek kullanım (Python) — kitaptaki Örnek 3.21'in ($F(A,B,C,D)=\Sigma(0,2,3,5,7,8,9,10,11,13,15)$) doğrulaması:

```python
>>> from quine_mccluskey import sadelestir
>>> sadelestir(4, {0, 2, 3, 5, 7, 8, 9, 10, 11, 13, 15})
[(0, 10), (5, 10), (2, 9), (8, 3)]
```

Her çift bir *(değer, maske)* asal kapsayanı temsil eder ($A$ bit 3, $B$ bit 2,
$C$ bit 1, $D$ bit 0; maskedeki her `1` biti o değişkenin elendiğini gösterir).
Burada çözülen `(0,10)`$\to B'D'$, `(5,10)`$\to BD$, `(2,9)`$\to B'C$,
`(8,3)`$\to AB'$'dir — yani $F=B'D'+BD+B'C+AB'$. Kitapta essential-olmayan
seçim için $CD+AD$ tercih edilmişti; ikisi de eşit derecede minimal, geçerli
alternatif çözümlerdir (fonksiyonun birden fazla eşit-minimal SOP ifadesi
olabileceğini gösteren iyi bir örnek).

Her dosyaya, kitabın ilgili kod bloğunun hemen üzerindeki/altındaki
paragraftan da (Bölüm 1.6 ve Bölüm 3.10) ulaşılabilir.
