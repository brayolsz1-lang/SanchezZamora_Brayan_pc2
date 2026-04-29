## Actividad 3-CC232

### Estudiante

- Nombre: Sánchez Zamora Brayan Joel

#### Bloque 1

### 1. ¿Qué cambia cuando una estructura pasa de almacenamiento contiguo a almacenamiento dinámico?

Cuando es contiguo (como un arreglo), los datos están juntos en memoria, eso permite acceso rápido pero es poco flexible con el tamaño.  
En dinámico (como listas enlazadas), los elementos están separados y unidos por enlaces, entonces crece o cambia fácil, pero el acceso ya no es tan rápido



### 2. Diferencia entre acceso por rango y acceso por posición o enlace

El acceso por rango es cuando puedes ir directo a un elemento usando su índice, sin recorrer nada (como en arreglos).  
El acceso por enlace es diferente, tienes que ir elemento por elemento siguiendo referencias, no puedes saltar directo


### 3. ¿Por qué una lista enlazada mejora inserciones y eliminaciones locales, pero empeora el acceso por índice?

En listas enlazadas insertar o eliminar es fácil porque solo cambias enlaces, no necesitas mover todo  
pero acceder por índice es lento, porque tienes que recorrer desde el inicio hasta llegar a la posición, no hay acceso directo


### 4. ¿Por qué SLList implementa bien operaciones de Stack y Queue?

SLList funciona bien como stack porque puede hacer push y pop al inicio en O(1), solo cambia el head  
también sirve como queue porque agrega al final (tail) y elimina al inicio, todo en tiempo constante, no hay que recorrer



### 5. ¿Por qué SLList no implementa naturalmente todas las operaciones de un Deque con el mismo costo?

Porque solo tiene acceso rápido al inicio y al final en un sentido, pero no en ambos completamente  
por ejemplo, eliminar al final no es directo, hay que recorrer toda la lista, entonces no mantiene O(1) en todo como un deque ideal



### 6. ¿Qué aporta el nodo centinela dummy en DLList?

El nodo dummy ayuda a evitar casos especiales, como cuando la lista está vacía o tiene un solo elemento  
hace que las operaciones sean más uniformes, porque siempre hay un nodo ahí conectando todo, entonces no tienes que estar validando tanto



### 7. ¿Por qué DLList permite justificar get(i), set(i,x), add(i,x) y remove(i) con costo O(1 + min(i, n-i))?

Porque en una lista doble puedes recorrer desde el inicio o desde el final  
entonces si el índice está cerca del inicio vas por ahí, si está cerca del final vas por el otro lado  
eso hace que el recorrido sea más corto, como el mínimo entre i y n-i, más el costo constante de la operación


### 8. ¿Cuál es la idea espacial central de SEList?

La idea es agrupar varios elementos en bloques en vez de tener uno por nodo  
cada nodo guarda un pequeño arreglo (como un mini contenedor), así no hay tanto desperdicio de memoria como en listas simples  
y tampoco es tan rígido como un arreglo grande, es como un punto medio


### 9. ¿Por qué SEList reutiliza una BDeque basada en ArrayDeque?

Porque necesita una estructura interna que sea flexible dentro de cada bloque  
ArrayDeque ya permite insertar y eliminar en posiciones con buen costo, entonces reutilizarlo evita reinventar todo  
básicamente usa lo bueno de arreglos dinámicos pero dentro de cada nodo

### 10. ¿Qué papel cumple DengList dentro de esta semana y por qué no reemplaza a las estructuras de Morin?

DengList actúa más como una especie de “wrapper” o interfaz sobre otra estructura (CleanList), o sea no implementa todo desde cero  
sirve para usar operaciones de lista de forma más limpia y ordenada, como una capa encima

pero no reemplaza a las estructuras de Morin porque esas están pensadas para analizar costos, diseño y cómo funcionan internamente  
DengList en cambio ya reutiliza algo hecho, entonces no muestra tanto la lógica interna ni permite estudiar bien los trade-offs


#### Bloque 2

### 11. Tabla de observaciones de los archivos

| Archivo | Salida u observable importante | Idea estructural | Argumento de costo, espacio o diseño |
|--------|-------------------------------|------------------|--------------------------------------|
| SLList main | size, peek, pop, remove funcionan | Lista enlazada simple con head y tail | operaciones al inicio y final en O(1), pero acceso por índice es O(n) |
| DLList main | imprime elementos en orden correcto | Lista doblemente enlazada | permite recorrer en ambos sentidos, mejora búsquedas relativas |
| SEList main | imprime elementos agrupados | Lista de bloques (arreglos dentro de nodos) | balance entre acceso y uso de memoria, evita mucho overhead |
| DengList main | muestra front, back y lista ordenada | Wrapper sobre otra lista (CleanList) | reutiliza implementación, no muestra costos internos directamente |
| MorinDengBridge main | lista ordenada y sin duplicados | combinación de DLList + Deng | mezcla estructuras para aprovechar ventajas sin rehacer todo |
| Capitulo3 main | mensaje de carga + valores de varias estructuras | conjunto de estructuras (SLList, DLList, SEList, etc) | comparación general entre representaciones |
| MinStack / Queue / Deque main | muestra mínimo junto con operaciones | estructuras con soporte de mínimo | mantienen info extra, ligero costo adicional de espacio |
| XorList main | imprime lista con menos punteros | lista enlazada con XOR | reduce memoria en punteros, pero complica operaciones |
| LinkedStack/Queue/Deque main | operaciones básicas de cada ADT | adaptadores sobre listas enlazadas | implementan ADT clásicos en O(1) en extremos |
| Comparación contiguo vs enlazado | muestra diferencias en acceso y operaciones | ArrayDeque vs estructuras enlazadas | contiguo = mejor acceso, enlazado = mejor inserción local |

### 1. ¿Qué secuencia deja más clara la coexistencia de pila y cola en SLList?

Cuando primero haces add(10), add(20) (comportamiento cola) y luego push(5) (comportamiento pila)  
eso muestra que puedes usar la misma estructura como ambas cosas



### 2. ¿Qué operación muestra mejor la inserción en posición intermedia en DLList?

El d.add(1, 20), porque inserta en medio entre 10 y 30  
no es ni inicio ni final, ahí se ve claramente



### 3. ¿Qué observable permite defender que SEList mantiene orden lógico?

El for con get(i) imprime los elementos en orden correcto  
aunque internamente estén en bloques, hacia afuera se ve como lista normal



### 4. ¿Qué evidencia muestra que DengList ofrece un ADT más completo?

Que tiene operaciones como sort(), dedup(), reverse()  
no solo insertar o eliminar, sino funciones más avanzadas



### 5. ¿Qué parte permite justificar reutilización en MorinDengBridge?

Cuando la lista se ordena y elimina duplicados sin cambiar DLList directamente  
eso muestra que se usan algoritmos encima, no se reescribe la estructura



### 6. ¿Qué diferencia hay entre almacenar valores y info para min()?

Aquí no solo guardas los datos, también info extra para saber el mínimo rápido  
eso ocupa más espacio pero permite responder min() en O(1)


### 7. ¿Qué adaptador representa mejor la idea de reutilizar estructura?

LinkedQueue o LinkedStack, porque usan listas enlazadas pero dan interfaz distinta  
no cambian la base, solo cómo se usa


### 8. ¿Qué contraste se observa entre contiguo vs enlazado?

Contiguo (ArrayDeque) tiene acceso rápido por índice y buena localidad de memoria  
enlazado permite insertar o eliminar fácil en medio, pero acceso es más lento



#### Bloque 3

### 1. ¿Qué operaciones mínimas valida la prueba pública para SLList?

En las pruebas públicas generales se valida que funcione lo básico  
principalmente agregar elementos (add o push), eliminar (remove o pop), ver el primero (peek) y consultar tamaño (size)

no buscan cosas avanzadas, más que nada que cumpla como lista simple y soporte operaciones tipo stack/queue sin romperse


### 2. ¿Qué operaciones mínimas valida la prueba pública para DLList?

Se valida que pueda insertar en distintas posiciones (add), acceder por índice (get) y eliminar (remove)  
también que mantenga el orden correcto al recorrerla, o sea que no se rompan los enlaces



### 3. ¿Qué operaciones mínimas valida la prueba pública para SEList?

Principalmente insertar (add), acceder (get) y eliminar (remove)  
además que la lista funcione como una secuencia normal, aunque internamente use bloques, o sea que el orden se mantenga

### 4. ¿Qué operaciones nuevas quedan cubiertas por test_public_extras.cpp?

aparecen operaciones más “extra”  

en SLList: secondLast(), reverse() y checkSize() en DLList: rotate() y isPalindrome() en Min estructuras: min() junto con push/pop/add/remove en XorList: reverse() y recorrido correcto

o sea, ya están validando comportamiento más avanzado, no solo insertar o eliminar, sino que la estructura haga cosas adicionales sin romperse

### 5. ¿Qué valida específicamente test_public_linked_adapters.cpp sobre LinkedStack, LinkedQueue y LinkedDeque?

Valida que cada adaptador respete su comportamiento esperado y funcione correctamente en operaciones básicas  

en LinkedStack: que siga LIFO (último en entrar, primero en salir), usando push, pop y top, además de size y empty  

en LinkedQueue: que siga FIFO (primero en entrar, primero en salir), usando add, remove y front, también size y empty  

en LinkedDeque: que permita operar por ambos extremos, con addFirst, addLast, removeFirst, removeLast, y consultar front/back  

en general, comprueba que las operaciones mantengan el orden correcto y no rompan la estructura

### 6. ¿Qué demuestra test_public_deng_bridge.cpp sobre integración y reutilización?

Demuestra que los algoritmos de Deng se pueden aplicar sobre distintas estructuras sin modificarlas directamente  
por ejemplo, funciona tanto con DLList como con SEList usando las mismas funciones como stable_sort o reverse

también se ve que no reescriben la estructura, sino que la convierten (to_vector) o la usan como base para aplicar los algoritmos  
eso deja claro que hay reutilización de código y buena integración entre componentes

### 7. ¿Qué comportamiento intenta estresar stress_selist_week3.cpp?

Intenta probar que la SEList soporte muchos cambios sin romperse  

primero crece bastante (500 elementos), luego elimina muchos desde el inicio, y después vuelve a insertar  
eso estresa cómo maneja el crecimiento y el reacomodo interno de bloques

también verifica que el tamaño lógico (size) se mantenga correcto después de muchas operaciones, o sea que no se desincronice

### 8. ¿Qué sí demuestra una prueba pública sobre una estructura enlazada?

Demuestra que las operaciones funcionan en casos normales, o sea que insertar, eliminar o acceder da los resultados esperados  
también que no se rompe fácilmente con uso básico



### 9. ¿Qué no demuestra una prueba pública por sí sola?

No demuestra que la implementación sea eficiente o óptima  
tampoco asegura que todos los casos extremos estén cubiertos, pueden haber errores escondidos



### 10. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes, punteros y complejidad?

Porque las pruebas solo muestran que “funciona”, pero no explican por qué funciona  
sin entender invariantes o punteros, podrías tener código correcto por casualidad pero mal diseñado  

y tampoco te dicen nada claro sobre el costo (tiempo o espacio), que es clave en estructuras de datos


#### Bloque 4

### 1. En SLList, ¿qué papel cumplen head, tail y n?

head apunta al primer nodo, tail al último  
n guarda cuántos elementos hay, así no tienes que recorrer para contar

### 2. En SLList::push, pop, add y remove, ¿qué punteros cambian exactamente?

push cambia head (el nuevo nodo apunta al anterior head)  
pop y remove mueven head al siguiente nodo  
add cambia tail->next y luego actualiza tail  
en removeAt se cambia el next del nodo anterior

### 3. Explica cómo funciona secondLast() y por qué no puede resolverse directamente con solo mirar tail.

recorre desde head hasta el nodo antes de tail  
no se puede con solo tail porque no hay puntero hacia atrás en lista simple

### 4. Explica paso a paso cómo funciona reverse() y por qué no necesita estructura auxiliar.

va nodo por nodo cambiando el next para que apunte al anterior  
usa tres punteros (prev, curr, next), no necesita otra estructura porque solo invierte enlaces

### 5. Explica qué verifica checkSize() y por qué esta función ayuda a defender correctitud.

cuenta los nodos reales y los compara con n  
también verifica que tail sea el último nodo  
sirve para detectar si algo se rompió en los enlaces

### 6. En DLList, explica por qué getNode(i) puede empezar desde el inicio o desde el final.

porque tiene punteros next y prev  
entonces puede ir desde el inicio o desde el final según convenga

### 7. En DLList::addBefore, ¿qué enlaces se actualizan y por qué el nodo centinela elimina casos borde?

se actualizan los prev y next del nuevo nodo y de sus vecinos  
el nodo dummy evita casos especiales como lista vacía o insertar al inicio

### 8. Explica cómo funciona rotate(r) sin mover los datos elemento por elemento.

no mueve valores, solo cambia enlaces entre nodos  
redefine quién queda como inicio y final lógico

### 9. Explica cómo isPalindrome() aprovecha la naturaleza doblemente enlazada de la estructura.

compara elementos desde ambos extremos al mismo tiempo  
usa next y prev para avanzar desde inicio y final

### 10. En SEList, explica qué representa Location.

representa en qué nodo (bloque) está el dato y su posición interna  
sirve para ubicar rápido dentro de la estructura

### 11. Explica qué hacen spread() y gather() y en qué situaciones aparecen.

spread reparte elementos cuando un bloque está lleno  
gather junta elementos cuando hay bloques muy vacíos  
aparecen para mantener equilibrio

### 12. Explica cómo el tamaño de bloque b afecta el trade-off entre acceso, actualización y uso de espacio.

si b es grande, menos nodos pero operaciones dentro del bloque más pesadas  
si b es pequeño, más nodos pero operaciones internas más ligeras  
es un balance entre eficiencia y memoria



#### Bloque 5

### 1. ¿Cómo reutiliza LinkedStack a SLList?

usa SLList como base y solo expone operaciones de pila  
push y pop trabajan sobre el inicio, no crea estructura nueva

### 2. ¿Cómo reutiliza LinkedQueue a SLList?

usa SLList aprovechando head y tail  
agrega al final (add) y elimina al inicio (remove), así cumple FIFO

### 3. ¿Por qué LinkedDeque se construye naturalmente sobre DLList y no sobre SLList?

porque necesita operar eficiente en ambos extremos  
SLList no permite eliminar rápido al final, DLList sí

### 4. En MinStack, ¿por qué cada entrada guarda el valor y el mínimo acumulado?

para responder min() en O(1)  
cada nodo ya tiene el mínimo hasta ese punto

### 5. En MinQueue, ¿por qué usar dos pilas permite mantener semántica FIFO y consulta de mínimo?

una pila es para entrada y otra para salida  
al pasar elementos se mantiene FIFO, y ambas guardan mínimos

### 6. En MinDeque, ¿qué problema resuelve el rebalanceo entre front_ y back_?

evita que todo quede en un solo lado  
mantiene equilibrio para que las operaciones sigan siendo eficientes

### 7. Compara "implementar una estructura" y "adaptar una estructura existente" usando ejemplos de este bloque.

implementar: SLList, DLList (defines todo desde cero)  
adaptar: LinkedStack, DengList (reutilizas otra estructura)

### 8. ¿Qué operaciones puedes defender como constantes y cuáles debes defender como amortizadas?

constantes: push, pop, add/remove en extremos, min()  
amortizadas: cuando hay rebalanceo o redistribución, como en SEList o MinQueue

#### Bloque 6

### 1. ¿Qué operaciones del ADT de lista aparecen reforzadas en DengList?

operaciones como sort, dedup, reverse, búsqueda (contains, find_index)  
no solo lo básico, sino funciones más completas de lista

### 2. ¿Qué ventaja tiene encapsular una lista más rica sin cambiar el resto de estructuras de Semana 3?

puedes agregar funcionalidad sin tocar lo que ya funciona  
evitas romper otras partes del código y mantienes compatibilidad

### 3. Explica qué hacen to_deng y assign_from_deng.

to_deng convierte una estructura a DengList para usar sus algoritmos  
assign_from_deng devuelve los datos a la estructura original ya modificados

### 4. Explica por qué stable_sort_with_deng no obliga a reimplementar ordenamiento dentro de DLList o SEList.

porque usa DengList como intermediario  
no necesitas programar sort en cada estructura, solo reutilizas uno

### 5. Explica qué hace dedup_with_deng y qué relación guarda con deduplicate() o uniquify() de la teoría.

elimina duplicados de la lista  
es parecido a deduplicate o uniquify, depende si la lista está ordenada o no

### 6. Explica por qué reverse_with_deng es un ejemplo de reutilización de algoritmos sobre una interfaz común.

porque aplica reverse sin importar la estructura original  
mientras cumpla la interfaz, se puede usar el mismo algoritmo

### 7. ¿Qué costo adicional introduce la conversión entre estructuras y cuándo vale la pena aceptarlo?

hay costo de copiar datos (tiempo y algo de memoria)  
vale la pena cuando quieres reutilizar algoritmos complejos sin reimplementarlos

#### Bloque 7

### 1. Compara ArrayDeque y LinkedDeque: ¿qué cambia en representación y qué cambia en costo observable?

ArrayDeque usa un arreglo contiguo, LinkedDeque usa nodos enlazados  
en costo, ArrayDeque tiene mejor acceso por índice, pero LinkedDeque es más flexible en inserciones sin mover datos

### 2. ¿Qué significa que una representación contigua tenga mejor localidad de memoria?

que los datos están juntos en memoria  
eso hace que la CPU los acceda más rápido por caché, no tiene que saltar tanto

### 3. ¿Qué tipo de operaciones favorecen más a la representación enlazada?

inserciones y eliminaciones locales  
no necesitas mover elementos, solo cambias enlaces

### 4. En el benchmark, ¿qué comparación sirve mejor para discutir acceso aleatorio y cuál sirve mejor para discutir operaciones en extremos?

acceso aleatorio: cuando usan get(i) en ArrayDeque vs DLList  
extremos: cuando comparan colas o deques (add/remove en inicio o final)

### 5. ¿Por qué el benchmark no debe leerse como prueba absoluta de superioridad de una estructura sobre otra?

porque depende del caso de uso  
una puede ser mejor en unas operaciones y peor en otras

### 6. ¿Qué idea intenta mostrar XorList respecto al ahorro de punteros?

que puedes usar un solo campo XOR en vez de dos punteros (prev y next)  
así reduces memoria

### 7. ¿Qué desventaja práctica introduce una estructura como XorList aunque sea interesante desde el punto de vista del espacio?

es más difícil de implementar y depurar  
también complica recorrer la lista, no es tan directa como una doblemente enlazada

#### Bloque 8

### ¿Qué cambia cuando pasamos de "usar arreglos dinámicos" a "diseñar estructuras enlazadas y adaptadores sobre nodos"?

en representación, pasas de datos contiguos en memoria a nodos conectados por punteros, o sea más flexible pero menos compacto  

en acceso, el arreglo permite acceso por rango directo (índice en O(1)), mientras que en enlazadas es acceso por posición, tienes que recorrer  

en inserciones y eliminaciones locales, las enlazadas son mejores porque solo cambian enlaces, en arreglos hay que mover elementos  

en complejidad, SLList tiene acceso O(n) pero operaciones en extremos O(1), DLList mejora recorridos usando ambos lados, y SEList busca un balance usando bloques  

en reutilización, aparecen adaptadores y puentes (como LinkedStack o Deng) que permiten usar estructuras existentes sin reescribir todo  

en comparación general, contiguo es mejor para acceso rápido y localidad de memoria, enlazado es mejor para flexibilidad y cambios dinámicos

#### Autoevaluación breve
### Autoevaluación breve

Qué puedo defender con seguridad:
- contiguo vs enlazado  
- acceso O(1) vs O(n)  
- inserciones más fáciles en enlazadas  

Qué todavía confundo:
- detalles de punteros  
- amortizado vs constante  
- SEList interno  

Qué evidencia usaría en una sustentación:
- ejemplos de código  
- asserts de tests  
- outputs comparando estructuras