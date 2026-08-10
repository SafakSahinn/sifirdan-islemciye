def asal_kapsayanlari_bul(n, mintermler):
    tum_bitler = (1 << n) - 1
    terimler = {(m, 0): {m} for m in mintermler}
    asal = {}
    while terimler:
        yeni, kullanilan = {}, set()
        liste = list(terimler)
        for i, (v1, maske1) in enumerate(liste):
            for v2, maske2 in liste[i + 1:]:
                if maske1 != maske2:
                    continue
                fark = (v1 ^ v2) & (tum_bitler & ~maske1)
                tek_bit_acik = fark and (fark & (fark - 1)) == 0
                if tek_bit_acik:
                    yeni_terim = (v1 & ~fark, maske1 | fark)
                    yeni[yeni_terim] = terimler[(v1, maske1)] | terimler[(v2, maske2)]
                    kullanilan.update({(v1, maske1), (v2, maske2)})
        asal.update({t: s for t, s in terimler.items() if t not in kullanilan})
        terimler = yeni
    return asal

def sadelestir(n, mintermler):
    asal = asal_kapsayanlari_bul(n, mintermler)
    kalan, secim = set(mintermler), []
    for terim, kapsanan in asal.items():
        digerleri = set().union(*(s for t, s in asal.items() if t != terim))
        if (kapsanan & kalan) - digerleri:
            secim.append(terim)
            kalan -= kapsanan
    for terim, kapsanan in asal.items():
        if kalan and (kapsanan & kalan):
            secim.append(terim)
            kalan -= kapsanan
    return secim
