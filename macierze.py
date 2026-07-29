import numpy as np
import time

# Tworzenie dwóch dużych macierzy o wymiarach 2000x2000 losowych liczb
print("Generowanie macierzy dla procesora...")
A = np.random.rand(2000, 2000)
B = np.random.rand(2000, 2000)

# Pomiar czasu operacji algebry liniowej (mnożenie macierzy)
start = time.time()
wynik = np.dot(A, B)
koniec = time.time()

print(f"Mnożenie macierzy zakończone sukcesem!")
print(f"Czas wykonania na procesorze: {koniec - start:.4f} sekundy")
