## Actividad 1- CC232

### Integrante
- Sánchez Zamora Brayan Joel

#### Bloque 1

1. Expliquen con sus palabras la diferencia entre problema, algoritmo, ADT e implementación.

**Diferencia entre problema, algoritmo, ADT e implementación**

Un **problema** es lo que se quiere resolver. Describe el objetivo sin decir cómo hacerlo.  
Por ejemplo, ordenar una lista de números.

Un **algoritmo** es el conjunto de pasos que permiten resolver ese problema. Aquí ya se define el procedimiento, pero aún no depende de un lenguaje de programación.  
Por ejemplo, comparar elementos e intercambiarlos hasta que la lista quede ordenada.

Un **ADT (Tipo Abstracto de Datos)** define qué operaciones se pueden realizar sobre los datos y qué comportamiento tienen, sin especificar cómo están implementadas internamente. Es decir, describe la interfaz y no la representación.  
Por ejemplo, una secuencia con operaciones como insertar, eliminar y acceder.

La **implementación** es la forma concreta en la que se programa todo lo anterior. Aquí se decide cómo se representan los datos y cómo se ejecutan las operaciones en un lenguaje específico.  
Por ejemplo, implementar una secuencia usando un arreglo o una lista enlazada en C++.

En resumen: el problema define el objetivo, el algoritmo define los pasos, el ADT define las operaciones disponibles y la implementación define cómo se realiza todo en código.

2. En bubble_sort.cpp, expliquen qué observable conecta correctitud y costo.

**Bubble_sort.cpp: observable que conecta correctitud y costo**

El observable principal que conecta la correctitud con el costo es el conteo de comparisons y swaps almacenado en la estructura `BubbleStats`.

Por un lado, la correctitud se puede verificar con la función `isSortedNonDecreasing`, que revisa si el arreglo quedó ordenado. Además, durante la ejecución, el hecho de que ya no haya intercambios (`changed = false`) indica que el arreglo ya está ordenado.

Por otro lado, el costo del algoritmo no se mide directamente con tiempo, sino con la cantidad de operaciones realizadas, específicamente el número de comparaciones (`comparisons`) y de intercambios (`swaps`). Estas variables se incrementan dentro de `bubblePass`, lo que permite cuantificar el trabajo realizado por el algoritmo.

La conexión entre ambos es que, a medida que el algoritmo avanza hacia la correctitud (es decir, hacia un arreglo ordenado), el número de comparaciones e intercambios refleja cuánto esfuerzo fue necesario para lograrlo. Por ejemplo, si el arreglo ya está ordenado, no habrá intercambios y el algoritmo puede detenerse antes (en la versión optimizada), reduciendo el costo.

En resumen, el estado "arreglo ordenado" (correctitud) se alcanza a través de un proceso cuyo esfuerzo es medido por comparaciones e intercambios (costo).

3.En power.cpp, expliquen por qué power mejora la idea de una versión ingenua.

**Power.cpp: por qué power mejora la versión ingenua**

La version ingenua (`powerBF`) multiplica a por si mismo n veces, osea hace n operaciones, entonces su costo es lineal.

En cambio la funcion `power` usa una idea mejor que es ir dividiendo n entre 2 (usando bits) y elevando al cuadrado. Entonces en vez de hacer n multiplicaciones, hace muchas menos, como log(n).

Osea basicamente evita trabajo innecesario.

Por eso `power` es mejor, porque hace menos operaciones para llegar al mismo resultado (sigue siendo correcto pero mas eficiente).



4.En fibonacci.cpp, expliquen por qué una función puede ser correcta y aun así ser una mala elección práctica.


**Fibonacci.cpp: correctitud vs mala elección práctica**

Una función puede ser correcta porque devuelve el resultado matemáticamente correcto, pero aun así ser una mala elección práctica debido a su costo.

En este archivo, la función `fib(int n)` (recursiva simple) es correcta porque calcula bien el número de Fibonacci según la definición. Sin embargo, es una mala elección práctica porque tiene un costo exponencial: vuelve a calcular muchas veces los mismos valores (por ejemplo, `fib(n-1)` y `fib(n-2)` repiten subproblemas). Esto hace que su tiempo de ejecución crezca muy rápido y sea ineficiente para valores grandes de `n`.

En cambio, la función `fibI(int n)` usa un enfoque iterativo que también es correcto, pero mucho más eficiente, ya que calcula cada valor una sola vez, teniendo un costo lineal.

La versión `fib(int n, long long& prev)` también evita recomputaciones al pasar información entre llamadas, mejorando el costo respecto a la versión recursiva simple.

En resumen, la correctitud garantiza que el resultado es correcto, pero no garantiza que el algoritmo sea eficiente. Por eso, una función puede ser correcta pero impráctica si su costo es demasiado alto.

5. En count_ones.cpp, expliquen por qué el tamaño de entrada no siempre coincide con el valor numérico.

**Count_ones.cpp: tamaño de entrada vs valor numerico**

El tamaño de entrada no es el valor del numero, sino cuantos bits se usan para representarlo.

Por ejemplo, un numero puede ser grande en valor pero no necesariamente tener muchos bits, o al reves. Lo que importa para el costo es cuantos bits tiene (su representacion), no el numero en si.

En estas funciones, el algoritmo trabaja sobre bits. Por ejemplo `countOnes1` va eliminando bits en 1, y `countOnes2` hace operaciones por bloques de bits.

Entonces el costo depende de la cantidad de bits (tipo 32 bits), no del valor numerico directo.

Osea, el input real aqui no es "n grande", sino "n con muchos bits".

6. En demo_adt_secuencia.cpp, expliquen por qué la misma interfaz puede convivir con representaciones distintas.

**demo_adt_secuencia.cpp: misma interfaz con distintas representaciones**

La interfaz es la clase `IntSequence`, donde estan las operaciones como size, get, set, add y remove. Eso es lo que el usuario usa.

Pero hay dos implementaciones distintas: `FixedArraySequence` y `VectorSequence`. Una usa un arreglo fijo y la otra usa un vector.

Aunque por dentro funcionan diferente (una tiene limite fijo y la otra crece dinamicamente), desde afuera se usan igual, porque tienen la misma interfaz.

Osea el usuario no necesita saber como esta hecho por dentro, solo usa las funciones.

Por eso se dice que la misma interfaz puede convivir con distintas representaciones, porque el comportamiento es el mismo aunque la implementacion cambie.

#### Bloque 2


#### Bloque 2

| archivo | salida u observable importante | idea algorítmica | argumento de costo |
|--------|-------------------------------|------------------|--------------------|
| demo_bubblesort.cpp | arreglo final ordenado, comparaciones, intercambios, ultimo swap, indices con desorden | comparar e intercambiar adyacentes hasta ordenar, optimizacion con ultimo swap | O(n^2) peor caso, mejora si ya esta casi ordenado (corta antes) |
| demo_power.cpp | mismos resultados entre powerBF y power | exponenciacion por cuadrados usando bits | O(n) vs O(log n), power es mucho mas rapido |
| demo_fibonacci.cpp | mismo resultado entre fibI, fib y fib con prev | recursion vs iteracion, evitar recomputacion | exponencial vs lineal |
| demo_countones.cpp | representacion en bits y cantidad de unos | eliminar bits en 1 o agrupar bits | depende de cantidad de bits, no del valor |

1. En demo_bubblesort.cpp, ¿qué salida sirve para defender costo y no solo resultado?


La salida que sirve para defender costo son las comparaciones y los intercambios (`stats.comparisons` y `stats.swaps`).

Porque el arreglo ordenado solo demuestra correctitud, pero no dice cuanto trabajo hizo el algoritmo.

En cambio, esos contadores muestran cuantas operaciones se hicieron, osea el esfuerzo real.

Tambien el `ultimo swap` ayuda porque muestra hasta donde tuvo que trabajar el algoritmo.

2. En demo_power.cpp, ¿qué comparación concreta muestra una mejora algorítmica?


La comparacion entre `powerBF` y `power`.

Ambos dan el mismo resultado, pero `powerBF` hace n multiplicaciones mientras que `power` hace muchas menos usando la idea de dividir el exponente.

Tambien pasa lo mismo con `power2BF` y `power2`.

Entonces la mejora se ve en que con la misma salida, uno hace menos operaciones (mejor costo).


3. En demo_fibonacci.cpp, ¿qué crecimiento se vuelve defendible?

El crecimiento lineal.

Porque las versiones como `fibI` o la que usa `prev` calculan cada valor una sola vez, entonces el costo crece proporcional a n.

En cambio la recursiva simple crece exponencial, pero eso no es practico.

Entonces el crecimiento que se puede defender es el lineal.

4. En demo_countones.cpp, ¿qué ejemplo ayuda más a distinguir valor numérico de tamaño en bits?

El ejemplo donde se imprime `x` junto con `std::bitset<16>(x)`.

Porque ahi se ve el mismo numero en decimal y en bits. Eso ayuda a notar que el valor numerico es una cosa, pero el tamaño real que usa el algoritmo son los bits.

Osea el algoritmo trabaja sobre la representacion en bits, no sobre que tan grande es el numero en decimal.

#### Bloque 3

1. ¿Qué funciones o ideas están verificando las pruebas públicas?

Las pruebas estan verificando que las funciones den el resultado correcto (correctitud).

Por ejemplo:

- sum verifica suma de arreglos
- power y power2 verifican potencias
- fib verifica numeros de fibonacci
- bubbleSort verifica que el arreglo quede ordenado
- countOnes verifica conteo de bits en 1
- max verifica encontrar el maximo
- reverse y shift verifican cambios en arreglos
- gcd verifica maximo comun divisor
- hanoi verifica cantidad de movimientos

Osea en general estan comprobando que los algoritmos funcionen bien segun lo esperado.

2. ¿Qué sí demuestra una prueba pública?

Una prueba publica demuestra que el programa funciona correctamente en ciertos casos.Osea, verifica que para algunos inputs el resultado es el esperado. 

Tambien ayuda a detectar errores basicos si algo falla. Pero solo prueba ejemplos especificos, no todos los posibles casos.


3. ¿Qué no demuestra una prueba pública?

No demuestra que el algoritmo sea correcto en todos los casos, solo en los que se probaron.

Tampoco demuestra que sea eficiente, osea no dice nada del costo o tiempo. Ni asegura que no haya errores en otros inputs mas raros o extremos.


4. Elijan una pregunta de preguntas_semana1.md y respóndanla bien.

**Ordena y comenta estos crecimientos de menor a mayor:**
O(1), O(log n), O(n), O(n^2), O(2^n)

Orden: O(1) < O(log n) < O(n) < O(n^2) < O(2^n)

O(1) es constante, no depende de n.  
O(log n) crece muy lento.  
O(n) crece proporcional.  
O(n^2) ya crece bastante mas rapido.  
O(2^n) explota muy rapido, es exponencial.

---

**¿Por qué una diferencia pequeña en la fórmula puede ser enorme cuando n crece?**

Porque cuando n es grande, esas diferencias se multiplican mucho.  
Por ejemplo n vs n^2 no parece tanto al inicio, pero con n grande se vuelve gigante.

---

**¿Qué papel juega el tamaño de entrada en el análisis?**

El tamaño de entrada (n) es lo principal, porque el costo depende de eso.  
Mientras mas grande sea n, mas se nota la diferencia entre algoritmos.

---

**¿Por qué los algoritmos exponenciales suelen volverse inviables rápidamente?**

Porque crecen demasiado rapido.  
Con valores pequeños aun funcionan, pero apenas n aumenta un poco ya se vuelven imposibles de ejecutar en tiempo razonable.

---

**¿Qué significa decir que existe una jerarquía de complejidades?**

Que hay niveles de eficiencia.  
Algunos algoritmos siempre son mejores que otros cuando n crece, por ejemplo O(n) siempre sera mejor que O(n^2) para n grande.



Usen la rúbrica para autoevaluarse en:

comprensión conceptual,
sustentación de correctitud,
análisis de eficiencia.


**Autoevaluación según la rúbrica**

Comprensión conceptual:  
En proceso. Entiendo la diferencia entre problema, algoritmo, ADT e implementacion, y tambien ideas como complejidad, pero a veces me falta explicarlo mas formal o preciso.

Sustentación de correctitud:  
En proceso. Puedo decir por qué funciona un algoritmo (ej: porque ordena o porque sigue la definicion), pero no siempre uso bien ideas como invariante o demostracion mas formal.

Análisis de eficiencia:  
En proceso. Identifico cuando algo es mas rapido (ej: log n vs n o exponencial), pero a veces no justifico completamente o no lo conecto con todas las operaciones del codigo.

#### Bloque 4

**¿Qué diferencia observable deja demo_const_refs.cpp entre lectura, modificación y copia?**

La lectura no cambia el vector original.  
La modificacion si cambia el vector (se agrega el 4).  
La copia crea otro vector nuevo y el original se queda igual.  

---

**¿Qué cambia con reserve en bench_vector_growth.cpp?**

Con reserve el vector ya tiene espacio desde el inicio, entonces no necesita redimensionarse varias veces.  
Eso hace que sea mas rapido.  

---

**¿Por qué push_back, insert(begin()) e insert(middle) no cuestan lo mismo?**

push_back es rapido porque agrega al final.  
insert(begin()) es caro porque mueve todos los elementos.  
insert(middle) mueve como la mitad.  

Por eso tienen distinto costo.  

---

**¿Qué intuición deja sobre localidad de memoria en bench_cache_effects.cpp?**

Que acceder de forma secuencial es mas rapido que acceso aleatorio.  
Y que estructuras como vector aprovechan mejor la memoria que list.  



#### Bloque 5

1. Según Ejercicios0.md, ¿cuál es el orden correcto antes de optimizar?

Primero elegir bien el algoritmo.  
Luego verificar que el programa sea correcto.  
Despues medir el rendimiento.  
Y al final recien aplicar optimizaciones del compilador.

Osea primero lo conceptual y correcto, luego ya optimizar.  

2. ¿Qué quiere mostrar stl_optimizacion_demostracion.cpp con reserve, nth_element, partial_sort y lower_bound?

Quiere mostrar que elegir el algoritmo o herramienta correcta es mucho mas importante que solo optimizar un poco.

Por ejemplo:
- reserve evita muchas realocaciones en vector
- nth_element encuentra el k-esimo sin ordenar todo
- partial_sort sirve para top-K sin ordenar todo
- lower_bound hace busqueda en log n en vez de lineal

Osea todas esas funciones hacen lo mismo final (resolver el problema), pero con mucho menos costo.

La idea es que una buena eleccion algoritmica gana mas que pequeñas optimizaciones.

3. ¿Qué tipo de evidencia puede producir resolver_ejercicios0_v4.2.sh?

El script resolver_ejercicios0_v4.2.sh produce evidencia experimental y cuantitativa sobre el comportamiento de programas en C++. 

Genera tiempos de ejecución, tamaños de ejecutables, warnings del compilador y resultados de ejecución para verificar correctitud. Además, incluye evidencia de profiling (gprof) para identificar funciones críticas, uso de sanitizers para detectar errores como accesos inválidos u overflow, y cobertura de código (gcov) para ver qué partes del programa se ejecutan realmente.

También permite comparar distintas técnicas (como optimizaciones del compilador, uso de STL, LTO y PGO), mostrando su impacto real en el rendimiento.

Toda esta información se organiza en un reporte en Markdown, proporcionando una base empírica para analizar rendimiento, calidad del código y efectos de optimización.

4. ¿Qué limitaciones de entorno menciona INSTRUCCIONES_Ejercicios0_v4.2.md?

El archivo menciona principalmente limitaciones del entorno en Windows (Git Bash o MSYS2). En estos entornos pueden presentarse problemas como:

- Sanitizers (ASan, UBSan, TSan) que no enlazan o no funcionan correctamente.
- Cobertura con gcov que puede requerir configuraciones adicionales.
- Profiling con gprof que puede fallar o no generar resultados útiles.

Por ello, se recomienda usar UCRT64 en MSYS2 para compilación normal, y preferir WSL (Ubuntu) o Linux nativo para ejecutar correctamente sanitizers, cobertura y profiling.

5. ¿Por qué esta parte no reemplaza la discusión de correctitud de Semana1?

porque se enfoca en medir rendimiento y comportamiento empírico, no en demostrar formalmente que un algoritmo es correcto.

Los experimentos muestran tiempos de ejecución, uso de memoria, profiling y efectos de optimización, pero no prueban que un algoritmo siempre produzca resultados correctos para todos los casos posibles.

La correctitud requiere demostraciones formales, invariantes, pruebas matemáticas o razonamiento lógico, mientras que este laboratorio se basa en evidencia experimental. Por eso ambas partes son complementarias: primero se asegura correctitud (Semana 1) y luego se analiza rendimiento (esta parte).

#### Bloque 6


**Afirmación de especificación**  
Se define claramente qué problema se está resolviendo y cuál es el comportamiento esperado del programa (entradas, salidas y condiciones). En esta etapa, la especificación sigue siendo la base para poder comparar distintas implementaciones sobre el mismo problema.

**Afirmación de correctitud**  
Se mantiene que la implementación produce resultados correctos respecto a la especificación, pero ya no basta con argumentos teóricos: se verifica también mediante pruebas y ejecución real del programa.

**Afirmación de costo**  
Se pasa de un análisis teórico (Big-O) a medir costos reales como tiempo de ejecución, constantes ocultas y eficiencia práctica usando benchmarks.

**Afirmación de representación o memoria**  
Se analiza cómo la estructura de datos y la gestión de memoria (por ejemplo, uso de `vector`, `reserve`, realocaciones) afectan el rendimiento y el uso de recursos.

**Advertencia metodológica**  
Los resultados experimentales pueden variar según el entorno (CPU, compilador, sistema operativo), por lo que las mediciones deben interpretarse con cuidado y bajo condiciones controladas.


#### Autoevaluación breve- 

- Que podemos defender con seguridad:

Podemos defender que distintas implementaciones pueden compararse objetivamente usando evidencia experimental (tiempos, profiling, tamaño, etc.), y que elegir el algoritmo correcto tiene más impacto que micro-optimizaciones. También que herramientas como STL, PGO y LTO pueden mejorar el rendimiento real.

- Qué todavía confundimos:
Aún puede haber confusión entre costo teórico (Big-O) y rendimiento práctico, así como en la interpretación de resultados (por ejemplo, variaciones por entorno o benchmarks mal diseñados).

- Qué evidencia usaríamos en una sustentación:
Usaríamos el reporte generado (`reporte_ejercicios0.md`), tiempos de ejecución, comparaciones entre versiones, resultados de gprof, gcov y sanitizers, además de logs de compilación para respaldar conclusiones.
