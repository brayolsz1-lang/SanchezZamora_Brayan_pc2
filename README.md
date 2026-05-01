## PC2 - CC232

### Estudiante
- Nombre: Brayan Sanchez Zamora
- Código: 20235010K
- Problema asignado: Codeforces 547B - Mike and Feet
- Enlace: https://codeforces.com/problemset/problem/547/B

### Referencia oficial
- Archivo de asignación:
  https://github.com/kapumota/CC-232/blob/main/Practicas/Practica2_CC232/Problemas-Evaluacion2.csv

### Tema principal
- Semana: 3
- Estructura o técnica principal: Stack (pila) y vector (arreglo dinámico)

### Resumen de la solución
Se calcula para cada elemento el rango máximo donde es el mínimo usando nearest smaller to left/right con una pila. Luego se propaga la respuesta hacia atrás para obtener la fuerza máxima para cada tamaño de grupo.

### Complejidad
- Tiempo: O(n)
- Espacio: O(n)

### Invariante o idea clave
La pila mantiene índices con alturas crecientes. Esto permite encontrar en O(1) el elemento menor más cercano.

### Archivos relevantes
- include/mike_feet.h
- src/mike_feet.cpp
- src/main.cpp
- tests/test.cpp
- demos/demo_creciente.cpp


### Compilación
```bash
g++ -std=c++17 -I include -o programa src/main.cpp src/mike_feet.cpp
```

### Ejecucion
./programa


### Casos de prueba
Describe al menos 3 casos:
1. n=1, entrada [42] , salida [42]
2. todos iguales [5,5,5,5] → salida [5,5,5,5]
3. ejemplo del problema → salida [6,4,4,3,3,2,2,1,1,1]


### Historial de commits
Indica que el historial debe verse en el video.


### Declaración de autoría
Declaro que entiendo el código entregado, que puedo explicarlo, compilarlo, ejecutarlo y modificarlo sin ayuda externa durante la grabación.
