# Linear Algebra Performance on AMD Ryzen 5 7520U

Projekt demonstruje wysokowydajne obliczenia algebry liniowej (mnożenie macierzy wielkich rozmiarów) w języku **C++** z wykorzystaniem biblioteki **Eigen3**. Kod został zoptymalizowany pod kątem architektury procesora zainstalowanego w laptopie.

## 💻 Specyfikacja Sprzętowa (Target Architecture)
Program został przetestowany i zoptymalizowany pod konkretny model procesora wykryty przez system Linux:
* **Procesor:** AMD Ryzen 5 7520U with Radeon Graphics
* **Architektura:** x86_64 (Zen 2 / Mendocino)
* **Liczba rdzeni/wątków:** 4 rdzenie / 8 wątków
* **Pamięć Cache L3:** 4 MiB (rozmiar macierzy 1500x1500 został dobrany pod optymalne wykorzystanie cache)
* **Kluczowe instrukcje wektorowe (SIMD):** AVX2, FMA3, SSE4.2

## 🚀 Zastosowane Optymalizacje Kompilatora
Dzięki precyzyjnemu skonfigurowaniu flag w systemie CMake, kompilator `gcc` generuje kod maszynowy bezpośrednio wykorzystujący rejestry wektorowe procesora AMD:
* `-O3` – najwyższy poziom optymalizacji pętli i przetwarzania kodu.
* `-mavx2` – wymuszenie użycia instrukcji AVX2 do jednoczesnego operowania na wielu danych zmiennoprzecinkowych.
* `-mfma` – włączenie operacji Fused Multiply-Add ($A \times B + C$ wykonywane w jednym cyklu procesora).
* `-ffast-math` – przyspieszenie operacji matematycznych na liczbach zmiennoprzecinkowych.

## 📈 Wyniki Wydajności
Dzięki pełnemu wsparciu sprzętowemu dla AVX2 i optymalizacji biblioteki Eigen, procesor osiąga znakomity czas wykonania dla operacji na macierzy o rozmiarze **1500 x 1500**:
* **Czas obliczeń:** ~0.74 sekundy

## 🛠️ Jak uruchomić projekt lokalnie

### 1. Wymagania wstępne (Linux)
Zainstaluj kompilator, CMake oraz nagłówki biblioteki Eigen3:
```bash
sudo apt update
sudo apt install build-essential cmake libeigen3-dev
```

### 2. Budowanie projektu
```bash
mkdir build
cd build
cmake ..
make
```

### 3. Uruchomienie testu
```bash
./MatrixPerf
```
