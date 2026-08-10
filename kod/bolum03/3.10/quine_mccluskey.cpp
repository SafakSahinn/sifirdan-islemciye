#include <algorithm>
#include <cstdint>
#include <iterator>
#include <map>
#include <set>
#include <utility>
#include <vector>

using Terim = std::pair<uint32_t, uint32_t>;  // (deger, maske)

std::map<Terim, std::set<int>>
asalKapsayanlariBul(int n, const std::vector<int>& mintermler) {
    uint32_t tumBitler = (1u << n) - 1;
    std::map<Terim, std::set<int>> terimler;
    for (int m : mintermler)
        terimler[{(uint32_t)m, 0u}] = {m};

    std::map<Terim, std::set<int>> asal;
    while (!terimler.empty()) {
        std::map<Terim, std::set<int>> yeni;
        std::set<Terim> kullanilan;
        for (auto it1 = terimler.begin(); it1 != terimler.end(); ++it1) {
            for (auto it2 = std::next(it1); it2 != terimler.end(); ++it2) {
                auto [v1, maske1] = it1->first;
                auto [v2, maske2] = it2->first;
                if (maske1 != maske2) continue;
                uint32_t fark = (v1 ^ v2) & (tumBitler & ~maske1);
                bool tekBitAcik = fark && (fark & (fark - 1)) == 0;
                if (tekBitAcik) {
                    Terim yeniTerim{v1 & ~fark, maske1 | fark};
                    auto birlesim = it1->second;
                    birlesim.insert(it2->second.begin(), it2->second.end());
                    yeni[yeniTerim] = birlesim;
                    kullanilan.insert(it1->first);
                    kullanilan.insert(it2->first);
                }
            }
        }
        for (auto& [terim, kapsanan] : terimler)
            if (!kullanilan.count(terim)) asal[terim] = kapsanan;
        terimler = std::move(yeni);
    }
    return asal;
}

std::vector<Terim> sadelestir(int n, const std::vector<int>& mintermler) {
    auto asal = asalKapsayanlariBul(n, mintermler);
    std::set<int> kalan(mintermler.begin(), mintermler.end());
    std::vector<Terim> secim;

    for (auto& [terim, kapsanan] : asal) {
        std::set<int> digerleri;
        for (auto& [t2, s2] : asal)
            if (t2 != terim) digerleri.insert(s2.begin(), s2.end());
        bool tekBasinaKapsiyor = std::any_of(kapsanan.begin(), kapsanan.end(),
            [&](int m) { return kalan.count(m) && !digerleri.count(m); });
        if (tekBasinaKapsiyor) {
            secim.push_back(terim);
            for (int m : kapsanan) kalan.erase(m);
        }
    }
    for (auto& [terim, kapsanan] : asal) {
        if (kalan.empty()) break;
        bool ortakVar = std::any_of(kapsanan.begin(), kapsanan.end(),
            [&](int m) { return kalan.count(m); });
        if (ortakVar) {
            secim.push_back(terim);
            for (int m : kapsanan) kalan.erase(m);
        }
    }
    return secim;
}
