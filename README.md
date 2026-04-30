# PC2 - Mike and Feet (Codeforces 547B)

## Estudiante
Brayan Sanchez Zamora 20235010K

## Problema
https://codeforces.com/problemset/problem/547/B

## Estructura de datos
- vector para alturas y resultados
- stack (pila) para nearest smaller elements

## Algoritmo
1. Calcular nearest smaller to left y right con stack
2. Para cada i: tamaño = right[i] - left[i] - 1
3. Actualizar mejor respuesta para ese tamaño
4. Propagar máximos hacia atrás

## Complejidad
- Tiempo: O(n)
- Espacio: O(n)

## Invariante
La pila mantiene índices con alturas crecientes (de abajo hacia arriba)

## Compilación y ejecución
g++ -std=c++17 -I include -o programa src/main.cpp src/mike_feet.cpp
./programa

## Resultado del ejemplo
Entrada:
10
1 2 3 4 5 4 3 2 1 6

Salida:
6 4 4 3 3 2 2 1 1 1

## Experimentos

### Sin optimización
g++ -std=c++17 -I include -o programa0 src/main.cpp src/mike_feet.cpp
Measure-Command { ./programa0 }

Tiempo real: 0.0235771 segundos

### Con optimización -O2
g++ -std=c++17 -O2 -I include -o programa2 src/main.cpp src/mike_feet.cpp
Measure-Command { ./programa2 }

Tiempo real: 0.0369834 segundos

## Declaración de autoría
Declaro que entiendo el código, puedo explicarlo, compilarlo, ejecutarlo y modificarlo.