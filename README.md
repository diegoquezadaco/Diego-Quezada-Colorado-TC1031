# Diego-Quezada-Colorado-TC1031

## Proyecto Closet-Lavadora
## Diego Quezada Colorado A01710024

El objetivo de este proyecto es modelar el funcionamiento de una idea que podría ser útil para nuestras generaciones futuras. Con el uso de la IA y su incorporación cada vez más cercana con nuestra vida diaria, se propone este proyecto que nos ayudaría en el ámbito personal. Lo que hace este Closet-Lavadora inteligente es tener un sistema lleva un control de las prendas de ropa que usas (playeras, pantalones, zapatos, accesorios, etc.) y de su uso y en base al mismo uso las lava y las vuleve a poner. Asímismo es posible adquirir más prendas y desechar las que ya no quieras. Y también te permite filtrat tu closet por tipo de prenda, color, material, veces de uso y talla.

El programa empieza con un closet predeterminado con 99 prendas diferentes, cada una con atributos propios de una prend de ropa, como lo son tipo (playera, pantalón, etc), color, talla, material, adicionalmente, para la funcionalidad del Closet-Lavadora, le fueron añadidos parámetros como estado, que puede ser Limpia o Lavando, un número de puestas o veces que la prenda ha sido usada desde su última lavada, y un ID que sirve para identificar todas las prendas entre sí. Así mismo existe una Tienda con prendas predeterminadas con 27 prendas, que te permiten aumentar tu arsenal de prendas.

La dinámica del programa es simple, para poder interactuar con las prendas del closet y de la tienda, se tiene un menú, que es el siguiente:
1. Consultar closet
2. Filtrar closet
3. Ordenar Closet por puestas
4. Usar prenda (requiere ID)
5. Comprar prenda
6. Desechar prenda (requiere ID)

Para interactuar con el menú simplemente se debe insertar alguno de los números brindados como opción, o en alguna de sus subopciones, como por ejemplo la 4 y la 6, ingresar números de ids de prendas que sí existen, de lo contrario, el programa termina después de arrojarte un error como por ejemplo NoSuchElement(), basados en el archivo de exceptions.h

## SICT0301: Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

- Quicksort:  Hice uso la función de sort, de la biblioteca de algorithm, que varía segun el caso, pero por lo general opta por usar el algoritmo de ordenamiento de Quicksort, que usa pivotes para ordenar parcialmente los arreglos, de tal manera que al final ordena arreglos mucho más ordenados que implica menos ciclos.
Sin embargo, aunque en su caso promedio tiene una complejidad de Θ(n log (n)), en el peor de los casos tiene un tiempo asinótico de O(n^2). Y una complejidad de espacio de O(log(n)). Es utilizado en todas las subopciones desplegadas al utilizar la opcion 3 del menú principal, que ordena el closet por puestas de menor a mayor, cuya lógica está especificada en la función ordenarPuestas, declarada en la línea 488 del archivo DLL.h

- Search: Con la implementación de la nueva estructura de datos, había que implementar también el algoritmo principal de búsqueda, que en este caso es la función search.  En el peor caso, el bucle while recorrerá toda la lista antes de encontrar el elemento o lanzar la excepción NoSuchElement. El tiempo de ejecución en el peor caso sería O(n). Esto significa que el tiempo de ejecución crece linealmente con el tamaño de la lista. Y tiene una complejidad espacial de O(n).

### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa.

Respecto a la estructura de datos, hago uso de una lista doblemente ligada, que según su análisis de tiempos asintóticos en promedio tiene Θ(n) para acceso y búsqueda, y Θ(1), para inserción y eliminación y para sus peores casos es de igual manera O(n) para acceso y búsqueda y O(1) para inserción y eliminación, teniendo una complejidad espacial de O(n). Esta estructura está declarada en el archivo "DLL.h", donde cada uno de los nodos son elementos de tipo DLink, cuya declaración está en el mismo archivo a partir de la línea 30 y hasta la 141, y la estructura que administra dichos "nodos" es precisamente la Doubly Linked List, cuya declaración va desde la línea 144 hasta la 539.

#### Análisis de los usos de dicha estructura:

- Constructor default DLL():

  - Complejidad de tiempo: O(1)
  - Complejidad de espacio: O(1)
  - Justificación: La inicialización de head, tail y size se realiza en tiempo constante, independientemente del tamaño de la lista. No hay bucles ni operaciones que dependan del tamaño de la lista.

- Constructor copia DLL(const DLL& dll):
  - Complejidad de tiempo: O(n)
  - Complejidad de espacio: O(1)
  - Justificación: El constructor copia recorre todos los elementos de la lista enlazada dll para copiarlos en la nueva lista. La complejidad de tiempo es lineal respecto al número de elementos en la lista original. La complejidad de espacio es constante ya que no se utiliza memoria adicional en función del tamaño de la lista.
   
- Destructor ~DLL():
  - Complejidad de tiempo: O(n)
  - Complejidad de espacio: O(1)
  - Justificación: El destructor invoca el método removeAll(), que elimina todos los nodos de la lista. La complejidad de tiempo es lineal, ya que cada nodo debe ser eliminado. La complejidad de espacio es constante ya que no se utiliza memoria adicional en función del tamaño de la lista.

- Métodos getHead(), getTail(), getSize(), empty():
  - Complejidad de tiempo: O(1)
  - Complejidad de espacio: O(1)
  - Justificación: Estos métodos realizan operaciones simples que no dependen del tamaño de la lista. Acceder al primer elemento, al último elemento, obtener el tamaño o verificar si la lista está vacía son operaciones de tiempo constante.

- Método add(PrendaRopa val):
  - Complejidad de tiempo: O(1)
  - Complejidad de espacio: O(1)
  - Justificación: La adición de un elemento al final de la lista enlazada doble se realiza en tiempo constante. No es necesario recorrer la lista, ya que se agrega al final.

- Método find(PrendaRopa val) const:
  - Complejidad de tiempo: O(n)
  - Complejidad de espacio: O(1)
  - Justificación: Este método realiza una búsqueda lineal en la lista para encontrar el elemento. En el peor caso, debe recorrer toda la lista. La complejidad de espacio es constante ya que no se utiliza memoria adicional en función del tamaño de la lista.

- Método remove(PrendaRopa val):
  - Complejidad de tiempo: O(n)
  - Complejidad de espacio: O(1)
  - Justificación: La eliminación de un elemento implica buscar el elemento en la lista, lo cual puede requerir recorrerla por completo en el peor caso. La complejidad de espacio es constante ya que no se utiliza memoria adicional en función del tamaño de la lista.

- Método removeAll():
  - Complejidad de tiempo: O(n)
  - Complejidad de espacio: O(1)
  - Justificación: Eliminar todos los nodos de la lista implica recorrerla por completo y eliminar cada nodo individualmente. La complejidad de espacio es constante ya que no se utiliza memoria adicional en función del tamaño de la lista.

- Método mostrarDatos():
  - Complejidad de tiempo: O(n)
  - Complejidad de espacio: O(1)
  - Justificación: Este método imprime los datos de todas las prendas en la lista, recorriéndola por completo. La complejidad de espacio es constante ya que no se utiliza memoria adicional en función del tamaño de la lista.

- Métodos filtrarTipo, filtrarColor, filtrarTalla, filtrarMaterial, filtrarEstado:
- Estos métodos realizan un recorrido completo de la lista enlazada doble (DLL) e imprimen los datos de las prendas que coinciden con el criterio de filtrado. La complejidad de tiempo y espacio de estos métodos es lineal, O(n), ya que deben examinar cada elemento de la lista para aplicar el filtro.
  - Complejidad de tiempo: O(n): En el peor caso, cada nodo de la lista debe ser revisado para verificar si cumple con el criterio de filtrado.
  - Complejidad de espacio: O(1): No se utiliza memoria adicional en función del tamaño de la lista, la impresión se realiza directamente en la consola y no implica almacenamiento adicional.
 
- Método ordenarPuestas: Este método utiliza un enfoque más eficiente utilizando std::sort de la biblioteca de algorithm de C++. La complejidad de tiempo de std::sort es O(n log(n)), que es mejor que O(n^2) de un algoritmo de ordenación cuadrático.
  - Complejidad de tiempo: O(n log(n)): La operación principal es la ordenación de las prendas basada en el número de puestas.
  - Complejidad de espacio: O(n): Se utiliza un vector auxiliar para almacenar las prendas antes de ordenarlas, lo que requiere espacio adicional proporcional al número de elementos en la lista.
 
- Método search: Este método realiza un recorrido lineal en la lista para buscar un nodo con el ID proporcionado. La complejidad de tiempo es O(n) en el peor caso.
  - Complejidad de tiempo: O(n): En el peor caso, se debe recorrer toda la lista para encontrar el nodo con el ID proporcionado.
  - Complejidad de espacio: O(1): No se utiliza memoria adicional en función del tamaño de la lista.
  
- Método reasignarID: Este método realiza un recorrido lineal en la lista para reasignar los IDs en orden ascendente. La complejidad de tiempo es O(n) en el peor caso.
  - Complejidad de tiempo: O(n): En el peor caso, se debe recorrer toda la lista para reasignar los IDs en orden ascendente.
  - Complejidad de espacio: O(1): No se utiliza memoria adicional en función del tamaño de la lista.

### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

##### Hay métodos que no fueron mencionados en los anteriores, porque van más en cuanto a la administración de archivos, en cuanto a lectura y escritura de los mismos, así como también métodos que recorren la DLL de tienda y del closet para determinar el número de prendas limpias y las que se están lavando y están declarados en el archivo ClosetLavadora.h entre las líneas 222 y 257 y a partir de la línea 643

- Función limpias:
  - Complejidad de tiempo: O(n^2): La función realiza un bucle que recorre la lista de prendas (num_prendas) y en cada iteración realiza una búsqueda en la lista doblemente enlazada (Closet->search(j)). La búsqueda en la lista implica recorrer la lista enlazada, que tiene una complejidad de tiempo lineal O(n) en el peor caso. Dado que se realiza n veces en el bucle, la complejidad total es O(n^2).
  - Complejidad de espacio: O(1): Se utilizan variables locales (i, num, j, nodo) que no dependen del tamaño de la entrada, por lo que la complejidad de espacio es constante.

- Función lavando:
  - Complejidad de tiempo: O(n^2): Similar a la función limpias, realiza un bucle que recorre la lista de prendas (num_prendas) y en cada iteración realiza una búsqueda en la lista doblemente enlazada (Closet->search(j)). La búsqueda en la lista implica recorrer la lista enlazada, que tiene una complejidad de tiempo lineal O(n) en el peor caso. Dado que se realiza n veces en el bucle, la complejidad total es O(n^2).
  - Complejidad de espacio: O(1): Se utilizan variables locales (i, num, j, nodo) que no dependen del tamaño de la entrada, por lo que la complejidad de espacio es constante.

- Métodos creaCloset y creaTienda:
  - Complejidad de tiempo: O(n* m): Ambas funciones realizan primero un while con el que ingresan todas las líneas del archivo CSV correspondiente (n) al arreglo "prendas" creada previamente, y en ese while se modifica un parámetro "num" que en pocas palabras es como el lenght real del areglo prendas, es decir, el número de elementos del arreglo que realmente estan ocupados por líneas del archivo CSV. Posteriormente con ayuda de un for recorre cada uno de los elementos de este arreglo, que son líneas del archivo CSV (n), después, dentro de ese for, recorre cada elemento (m) de la línea del archivo en turno para obtener los elementos en orden y asignarlos a variables de apoyo para eventualmente crear un elemento de tipo Prenda ropa y agregarlo al DLL de Closet o Tienda según corresponda. Por lo tanto, la complejidad del tiempo es de O(n*m), donde n representa el número de líneas y m la longitud de cada línea. O bien podría ser representada como O(n^2).
  - Complejidad de espacio: Como se mencionó anteriormente se crea un arreglo de prendas cuya longitud depende de si es Closet o es Tienda y del número de líneas en los archivos CSV (n), n que será el número de prendas, así que la complejidad espacial es de O(n).
 
- Método actualizaArchivo:
  - Complejidad de tiempo: O(n): La función comienza con una serie de operaciones de tiempo constante que no dependen del tamaño de la entrada (apertura de archivos, verificación de errores, etc.). Luego, hay un bucle for que itera sobre cada elemento en la lista enlazada (for (int i = 0; i < DLL->size; i++)). Cada iteración de este bucle realiza operaciones de tiempo constante para acceder a la prenda correspondiente, obtener sus atributos y escribirlos en el archivo de salida. Por lo tanto, la complejidad de tiempo es O(n), donde n es el tamaño de la Doubly Linked List DLL.
  - Complejidad de espacio: O(1): Se utilizan variables locales y no se asigna memoria adicional en función del tamaño de la entrada. La complejidad de espacio es constante.


#### Complejidad final del programa:
Analizando el que podría ser el pero caso del programa, y analizando los algoritmos 



## SICT0302: Toma decisiones

### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
QuickSort es una elección sólida para ordenar un closet de prendas de vestir, especialmente si valoras la eficiencia promedio y la adaptabilidad a datos parcialmente ordenados. Aunque ahora con la incorporación de la estructura de árbol BST, el algoritmo de búsqueda prácticamente viene incluido con la estructura y es aún más eficiente que el QuickSort, y es adecuado y muy eficaz cuando se trabaja con un árbol al menos relativamente ordenado y no tan degenerado, ya que mejora mucho el tiempo asintótico de la búsqueda de los elementos

### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.

Nuevamente mencionamos que establecimos una estructura de árbol BST, donde cada nodo de dicho árbol es un elemento de tipo Prenda Ropa y organiza de buena manera la estructura clave para el manejo de datos en ClosetLavadora, aunque los métodos para realizar la organización como tal del árbol y administrar los nodos y leer los datos, se encuentra explicita en la declaración de Arbol.h, cuyas funciones fueron previamente desglosadas, y para hacer uso correcto de los datos, alteraremos un poco el orden de la importación de los datos desde el archivo CSV, para que el algoritmo de búsqueda sea de la mejor manera posible

## SICT0303: Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructras correctos.
Auxiliados de la estructura general del árbol BST, se crearon funciones auxiliares en dich archivo (Arbol.h), que ayudan a extraer valores recorriendo el árbol, en este caso, son las funciones que fueron desglosadas anteriormente que son mostrarDatos(), declarada en la 507 del archivo Arbol.h, que se apoya a su vez de la llamada de la función de Nodo mostrarDatoss(), declarada en la linea 224 del mismo archivo, que a su vez de apoya de la llamada de la función mostrarDatos(), declarada en la linea 216 del archivo PrendaRopa.h, y se muestran la de todo el arbol de closet o tienda respectivamente haciendo uso de la llamada de las funciones mencionadas anteriormente en la funcion consultarCloset(), de la clase ClosetLavadora.h en la linea  312, donde se muestran apiladas y divididas en una tabla por atributo.

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
- En el archivo de ClosetLavadora, con ayuda de las 2 penúltimas funciones (la penúltima y la penúltima), es decir creaCloset y creaTienda, se importan los datos de un archivo .csv a la estructura del árbol, con ayuda de la librería fstream, en el proceso se involucra el proceso de apertura y lectura correcta de archivos para incluirlos correctamente en el árbol. 

### Implementa mecanismos de escritura de archivos para guardar los datos  de las estructuras de manera correcta.
- A su vez en la última función de dicho archivo es decir actualizarArchivo(Arbol* arbol), declarada en la línea 859 del archivo ClosetLavadora.h, nuevamente apoyados de la libreria para editar archivos fstream, hacemos un ciclo para recorrer el arbol por completo, después de todos los cambios efectuados durante el ciclo, para que guarde los cambios efectuados, reescribiendo el archivo, respetando el formato, y de esta manera en proximas corridad del programa no se empieza de 0, sino desde el último cambio o modificación efectuada.

## Consideraciones:
Todos los archivos deben estar en la misma carpeta, para que el prorgrama funcione correctamente

El programa solo corre en la consola o en replit también y esta hecho con c++ standard por lo que corre en todos los sistemas operativos, no incluye bibliotecas extra, mas que la de string, para poder usar este tipo de dato y la de algorithm

-compilar con: la ruta donde se encuentre la carpeta que tiene todos los archivos, y posteriormente "g++ main.cpp"

-correr en linux: "/a.out"

-correr en windows: "a.exe"

- Al iniciar el programa, se mostrará un menú principal con varias opciones numeradas.
- Ingresa solo el número correspondiente a la opción que desea ejecutar y presione Enter.
- Siga las instrucciones en pantalla para completar la operación seleccionada.
- El programa proporcionará retroalimentación y resultados de las operaciones realizada

## Restricciones o casos en los que el programa deja de funcionar:
-Cuando se solicite la entrada de datos, por lo general se dan opciones de numeros para que el usuario escoja o en su defecto, se pide que se escriba un nombre o la palabra si o no. Para estos casos, favor de ser muy cuidadoso e ingresar el tipo de dato que se espera, de lo contrario, el programa deja de funcionar
