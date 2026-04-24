## Actividad 2-CC232

### Integrante
- Sánchez Zamora Brayan Joel

#### Bloque 1
1. Expliquen con sus palabras qué significa que un arreglo use memoria contigua.

Que un arreglo use memoria contigua significa que todos sus elementos están guardados uno seguido del otro en memoria, sin espacios entre ellos.

Es decir, si tienes un arreglo, cada elemento está en la siguiente posición de memoria inmediata respecto al anterior.

Esto permite acceder rápidamente a cualquier elemento usando su índice, porque la dirección se puede calcular directamente.

2. Expliquen por qué acceder a A[i] es una operación de costo O(1).

Acceder a A[i] es O(1) porque no depende del tamaño del arreglo.

Como los elementos están en memoria contigua, la posición de A[i] se calcula directamente con una fórmula: dirección base + (i * tamaño del elemento).

No es necesario recorrer el arreglo ni hacer búsquedas, por eso el acceso es constante.


3. Expliquen la diferencia entre size y capacity.

La diferencia entre size y capacity es:

- size: cantidad de elementos que realmente tiene el vector.
- capacity: cantidad de elementos que puede almacenar sin tener que aumentar memoria.

Es decir, size es lo que ya está ocupado, y capacity es el espacio total reservado.

La capacity puede ser mayor que size porque el vector reserva memoria extra para evitar realocaciones frecuentes.

4. Expliquen por qué un arreglo dinámico no puede crecer "en el mismo sitio" y necesita reservar un bloque nuevo al hacer resize().

Un arreglo dinámico no puede crecer en el mismo sitio porque la memoria contigua que necesita puede no estar disponible después del bloque actual.

Es posible que la siguiente posición en memoria ya esté ocupada por otra estructura, por lo que no se puede simplemente extender el arreglo.

Por eso, al hacer resize(), se reserva un nuevo bloque de memoria más grande, se copian los elementos al nuevo espacio y luego se libera el bloque anterior.

5. Expliquen por qué duplicar capacidad permite defender costo amortizado O(1) para inserciones al final.

Duplicar la capacidad permite que las inserciones al final sean O(1) amortizado porque las realocaciones ocurren pocas veces.

La mayoría de inserciones solo agregan el elemento al final en tiempo constante. Solo cuando se llena el arreglo se hace una realocación, que cuesta O(n) porque copia todos los elementos.

Pero como la capacidad se duplica, esas operaciones costosas se vuelven cada vez menos frecuentes. Al distribuir ese costo entre muchas inserciones, el costo promedio por inserción es constante O(1). 

6. Comparen ArrayStack y DengVector: ¿qué comparten y qué cambia en interfaz o intención didáctica?

Ambas estructuras (ArrayStack y DengVector) comparten la idea de usar un arreglo dinámico con memoria contigua que puede crecer y reducirse. En ambos casos se maneja un tamaño actual y una capacidad, y se realizan realocaciones copiando elementos cuando es necesario.

La diferencia está en la interfaz y la intención didáctica:

- ArrayStack tiene una interfaz más abstracta tipo lista (add, remove, get, set) y está pensado para enseñar estructuras de datos desde un enfoque más teórico. No expone directamente la capacidad.

- DengVector expone métodos como size(), capacity(), operator[], insert y remove, y muestra explícitamente cómo funcionan expand() y shrink(), por lo que es más didáctico .

En resumen, ArrayStack enfatiza el concepto de estructura de datos, mientras que DengVector enfatiza cómo se implementa y gestiona la memoria internamente.

7. Expliquen qué mejora FastArrayStack respecto a ArrayStack.

FastArrayStack mejora a ArrayStack principalmente en la implementación interna de las operaciones.

Ambos tienen la misma idea y complejidad teórica, pero FastArrayStack usa funciones de la STL como std::copy y std::copy_backward en lugar de bucles manuales.

Permite:
- código más limpio y compacto
- mejor rendimiento práctico en algunos casos

En resumen, no cambia la complejidad (sigue siendo O(n) en inserciones y eliminaciones en medio), pero mejora la eficiencia constante y la claridad del código.

8. Expliquen cuál es la idea espacial central de RootishArrayStack.

RootishArrayStack busca usar mejor la memoria.

La idea es que así no se desperdicie tanto espacio como en un arreglo dinámico normal.

El acceso no es tan directo porque primero hay que calcular en qué bloque está el elemento.

En resumen: ahorra memoria comparado con ArrayStack, pero a costa de ser un poco más complejo.

9. Expliquen por qué RootishArrayStack usa bloques de tamaños 1, 2, 3, ....

RootishArrayStack usa bloques de tamaño 1, 2, 3, ... para crecer de forma gradual.

La idea es que la suma 1 + 2 + 3 + ... permita cubrir n elementos sin tener que duplicar un arreglo grande.

Así el crecimiento es más fino y se desperdicia menos memoria.

Además, esa forma permite ubicar cualquier elemento usando una fórmula matemática.

En resumen: se usan tamaños crecientes para equilibrar espacio y acceso.

10. Expliquen qué relación hay entre representación, costo temporal y desperdicio espacial en estas estructuras.

La representación influye directamente en el costo y en la memoria.

Si usas un arreglo contiguo (ArrayStack):
- acceso es rápido O(1)
- pero puede haber bastante espacio sin usar

Si usas bloques (RootishArrayStack):
- ahorras memoria
- pero el acceso es un poco más complejo

Entonces hay un intercambio:
mejor tiempo , más desperdicio de memoria  
mejor uso de memoria, operaciones un poco más costosas


#### Bloque 2

Construyan una tabla con cuatro columnas:

Archivo
Salida u observable importante
Idea estructural
Argumento de costo o espacio

| Archivo | Salida u observable importante | Idea estructural | Argumento de costo o espacio |
|--------|------------------------------|------------------|------------------------------|
| demo_array_basico.cpp | length y contenido, y que b = a transfiere ownership | arreglo contiguo simple | acceso O(1), pero tamaño fijo |
| demo_arraystack.cpp | inserciones, remove y size | arreglo dinámico con desplazamientos | add/remove cuestan O(n-i) |
| demo_arraystack_explicado.cpp | muestra paso a paso los shifts | mismo ArrayStack pero explicado | costo viene de mover elementos |
| demo_fastarraystack.cpp | mismos resultados que ArrayStack | usa std::copy para mover datos | mejora práctica, mismo O(n-i) |
| demo_rootisharraystack.cpp | funciona como lista pero con bloques | usa bloques 1,2,3,... | menos desperdicio de memoria |
| demo_rootisharraystack_explicado.cpp | muestra bloque y posición de cada elemento | acceso con cálculo matemático | trade-off: menos espacio, más complejidad |
| demo_deng_vector.cpp | muestra size y capacity cambiando | vector dinámico con expand/shrink | inserción amortizada O(1) |
| demo_stl_vector_contraste.cpp | capacity crece al hacer push_back | vector STL estándar | crecimiento dinámico, posible desperdicio |


1. En demo_array_basico.cpp, ¿qué deja claro sobre arreglo, longitud y asignación?

Deja claro que un arreglo tiene un tamaño fijo llamado length. Se puede acceder directamente a los elementos con a[i].

También muestra que la asignación (b = a) no copia elemento por elemento, sino que transfiere el arreglo completo (ownership).

En resumen: arreglo contiguo, tamaño fijo y asignación especial (no copia tradicional).

2. En demo_arraystack_explicado.cpp, ¿qué operación muestra mejor el costo por desplazamientos?

La operación que mejor muestra el costo por desplazamientos es add(i, x).

Porque al insertar en una posición intermedia, todos los elementos desde i hasta n-1 se mueven una posición a la derecha.

Eso hace que el costo sea O(n - i).

También remove(i) tiene desplazamientos, pero add(i, x) se ve más claro en el ejemplo.

3. En demo_fastarraystack.cpp, ¿qué cambia en la implementación aunque no cambie la complejidad asintótica?

Cambia la forma de mover los elementos.

En lugar de usar un for, usa funciones como std::copy y std::copy_backward.

Esto hace que el código sea más eficiente en la práctica y más limpio.

Pero la complejidad no cambia: sigue siendo O(n - i) porque igual hay que mover elementos.

4. En demo_rootisharraystack_explicado.cpp, ¿qué ejemplo explica mejor el mapeo de índice lógico a bloque y offset?

El mejor ejemplo es cuando se imprimen varios índices con su ubicación.

Por ejemplo, al pedir índices como 0, 2 y 5, el programa muestra:

- qué bloque (b) contiene el elemento
- qué posición dentro del bloque (j) tiene

Eso deja claro cómo un índice lógico i se transforma en (bloque, offset) usando la función de mapeo.

En resumen: los ejemplos de “locate(i)” son los que mejor explican el mapeo.

5. En demo_deng_vector.cpp, ¿qué observable permite defender el crecimiento de capacity?

El observable principal es cómo cambia capacity cuando se hacen insert().

Se ve que al inicio la capacidad es pequeña, y cada vez que se llena el arreglo, capacity aumenta.

También se nota que no crece en cada inserción, sino en saltos (se expande).

En resumen: el crecimiento de capacity se observa en los prints después de cada insert.

6. En demo_stl_vector_contraste.cpp, ¿qué similitud conceptual observan con DengVector?

La similitud es que ambos usan un arreglo dinámico con crecimiento de capacity.

Cuando se llena el espacio, reservan un bloque más grande y copian los elementos.

También ambos tienen size y capacity separados.

En resumen: los dos implementan la misma idea de vector dinámico con expansión por bloques.

7. ¿Qué demo sirve mejor para defender amortización y cuál sirve mejor para defender uso de espacio?

Para amortización, el mejor demo es el de DengVector (demo_deng_vector.cpp).

Ahí se ve cómo insert puede costar a veces más (cuando crece capacity), pero en promedio se mantiene O(1) por inserción.

Para uso de espacio, el mejor es RootishArrayStack (demo_rootisharraystack.cpp / explicativo).

Ahí se observa que se reduce el desperdicio de memoria al usar bloques 1,2,3,... en vez de duplicar todo el arreglo.



#### Bloque 3

1. ¿Qué operaciones mínimas valida la prueba pública para ArrayStack?
- add(x) al final
- add(i, x) en posición intermedia
- get(i)
- remove(i)
- size()

---

2. ¿Qué operaciones mínimas valida la prueba pública para FastArrayStack?
- add al final
- add(i, x)
- get(i)
- remove(i)
- size()
(igual que ArrayStack, pero validando versión optimizada)

---

3. ¿Qué operaciones mínimas valida la prueba pública para RootishArrayStack?
- add(i, x)
- get(i)
- set(i, x)
- remove(i)
- size()


4. ¿Qué sí demuestra una prueba pública sobre una estructura?

Demuestra que el código funciona en casos concretos y que no rompe en escenarios básicos o medianos.



5. ¿Qué no demuestra una prueba pública?

No demuestra complejidad real (O(n), O(1)), ni eficiencia teórica, ni todos los casos posibles.



6. En resize_stress_week2.cpp, ¿qué comportamiento intenta estresar sobre crecimiento, reducción o estabilidad?

Intenta estresar el crecimiento y reducción de la estructura, verificando cómo se comporta al insertar y eliminar muchos elementos seguidos.



7. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes y complejidad?

Porque las pruebas solo muestran casos específicos, pero no explican por qué funciona ni garantizan el comportamiento en todos los casos posibles.




#### Bloque 4

1. ¿Qué papel cumplen _size, _capacity y _elem?
_size = cuántos elementos hay realmente  
_capacity = cuánto espacio hay reservado  
_elem = el arreglo dinámico donde se guardan los datos  



2. ¿Cuándo debe ejecutarse expand()?
Cuando _size llega a _capacity, o sea cuando ya no hay espacio para insertar más elementos.


3. ¿Por qué insert(r, e) necesita desplazar elementos?
Porque hay que abrir espacio en la posición r, moviendo los elementos a la derecha.



4. ¿Qué diferencia conceptual hay entre remove(r) y remove(lo, hi)?
remove(r) elimina un solo elemento  
remove(lo, hi) elimina un rango de elementos


5. ¿Qué evidencia de copia profunda aparece en la demo?
Cuando se crea copia o asignación y luego modificar una no afecta a la otra.



6. ¿Por qué traverse() es una buena interfaz didáctica?
Porque permite aplicar operaciones sin exponer la estructura interna del vector.


7. ¿Qué ventaja tiene implementar un vector propio antes de std::vector?
Ayuda a entender cómo funciona realmente el crecimiento dinámico, memoria y desplazamientos por dentro.


#### Bloque 5

1. ¿Cómo se distribuyen los elementos entre bloques?

Se van llenando en orden: bloque 0 tiene 1, bloque 1 tiene 2, bloque 2 tiene 3, etc. Siempre consecutivo.

2. ¿Por qué con r bloques la capacidad total es r(r+1)/2?

Porque es la suma 1 + 2 + 3 + ... + r, que da r(r+1)/2.

3. ¿Qué problema resuelve i2b(i)?

Convierte el índice lógico i en el bloque donde está el elemento.

4. ¿Qué información produce locate(i) en la versión explicada?

Devuelve (b, j): bloque b y posición dentro del bloque j.

5. ¿Qué se gana en espacio frente a ArrayStack?

Menos desperdicio de memoria, no hay un solo arreglo grande sobredimensionado.

6. ¿Qué se conserva igual respecto a la interfaz?

Las mismas operaciones: get, set, add, remove, size.

7. ¿Qué parte es más difícil de defender oralmente?

El mapeo i2b / locate(i), porque no es intuitivo al inicio.


#### Bloque 6


1. ¿Qué aporta operator[] a la idea de vector?
Permite acceso directo con sintaxis tipo arreglo (v[i]), haciendo más natural el uso del vector sin perder encapsulación.

2. ¿Qué supone find(e) sobre igualdad entre elementos?
Supone que existe una noción clara de igualdad (==) definida para el tipo de datos almacenado.

3. ¿Qué muestra traverse() sobre procesamiento uniforme de toda la estructura?
Que el vector puede recorrerse completo aplicando una misma operación a cada elemento, sin importar su tipo.

4. ¿Por qué esta lectura sirve como refuerzo natural de DengVector aunque no sea el centro exclusivo de la semana?
Porque DengVector implementa exactamente estas ideas (size, capacity, insert, remove, traverse), mostrando la teoría aplicada en código real.


#### Bloque 7

1. Representación:
Pasar a una estructura dinámica significa que ya no hay un arreglo fijo, sino un arreglo interno que puede cambiar de tamaño o incluso dividirse en bloques (como en RootishArrayStack).

2. Correctitud:
La estructura debe mantener invariantes claros (orden lógico, tamaño válido, mapeo correcto de índices) aunque el arreglo físico cambie por resize o por bloques.

3. Costo amortizado:
Aunque algunas operaciones como expand o shrink son O(n), al distribuirse en muchas inserciones el costo promedio por operación se mantiene O(1).

4. Uso de espacio:
Se introduce sobrecarga controlada de memoria (capacity > size), pero estructuras como RootishArrayStack reducen el desperdicio frente a un solo arreglo grande.

5. Comparación:
ArrayStack es simple pero puede mover muchos elementos y desperdiciar espacio tras resize.
FastArrayStack mejora los desplazamientos usando std::copy y operaciones más eficientes, pero sigue siendo un solo bloque.
RootishArrayStack divide el almacenamiento en bloques crecientes, reduciendo desperdicio espacial a cambio de mayor complejidad en el mapeo de índices.

### Autoevaluación breve

- Qué podemos defender con seguridad:
Sabemos explicar cómo funciona el vector dinámico (size, capacity, expand/shrink), y podemos describir ideas básicas de ArrayStack, FastArrayStack y RootishArrayStack a nivel general.

- Qué todavía confundimos:
Aún cuesta explicar con total claridad el mapeo de índices en RootishArrayStack (i2b, locate) y justificar formalmente algunos casos de costo amortizado sin apoyarnos en intuición.

- Qué evidencia usaríamos en una sustentación:
Código de las demos, salidas de ejecución (prints de size/capacity/bloques), pruebas de inserción/eliminación, y ejemplos donde se vea el efecto real de resize, desplazamientos y uso de bloques.