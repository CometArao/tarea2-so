# Sistemas Operativos Tarea 2 - Procesamiento de imágenes

El presente repositorio contiene la implementación de código secuencial para convertir imágenes de alta calidad a escala de grises.
La tarea fue realizada por:
- Fernanda Morales
- Abel Rosales

## 1.- Secuencial
```bash
cd Secuencial
make -f Makefile_S
./secuencial imagen_a_elegir.jpg imagen_a_elegir_gris.jpg
# Ejemplo con la imagen entregada: ./secuencial arbol.jpg arbolgris.jpg
IMPORTANTE: Se imprimirá cómo se va asignando las posiciones en la matriz, para luego compartir el tiempo de ejecución
```

## 2.- Paralelo (Thread)
```bash
cd Paralelo
cd Thread
make -f Makefile_T
./paralelo_threads imagen_a_elegir.jpg imagen_a_elegir_gris.jpg (cantidad_de_hebras)
# Ejemplo con la imagen entregada: ./paralelo_threads arbol.jpg arbolgris.jpg 4
```

## 3.- Paralelo (OpenMP)
```bash
cd Paralelo
cd OpenMP
./paralelo_openmp imagen_a_elegir.jpg imagen_a_elegir_gris.jpg (cantidad_de_hebras)
# Ejemplo con la imagen entregada: ./paralelo_openmp arbol.jpg arbolgris.jpg 4
```

## Presentación de resultados
Para el procesamiento de la imagen, se utilizó un procesador amd ryzen 5 3550H, de 4 núcleos y de 8 hebras máximas.

### Tiempos de ejecución con la imagen proporcionada y 4 hebras (En versiones paralelas)

### Secuencial
7.71233 segundos

### Paralelo (Thread)
0.166496 segundos

### Paralelo (OpenMP) 
0.141218 segundos
