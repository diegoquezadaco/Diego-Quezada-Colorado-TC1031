# Diego-Quezada-Colorado-TC1031

## Proyecto Closet-Lavadora
## Diego Quezada Colorado A01710024

El objetivo de este proyecto es modelar el funcionamiento de una idea que podría ser útil para nuestras generaciones futuras. Con el uso de la IA y su incorporación cada vez más cercana con nuestra vida diaria, se propone este proyecto que nos ayudaría en el ámbito personal. Lo que hace este Closet-Lavadora inteligente es tener un sistema lleva un control de las prendas de ropa que usas (playeras, pantalones, zapatos, accesorios, etc.) y de su uso y en base al mismo uso las lava y las vuleve a poner. Asímismo es posible adquirir más prendas y desechar las que ya no quieras. Y también te permite filtrat tu closet por tipo de prenda, color, material, veces de uso y talla.

## SICT0301: Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

- Quicksort:  Al inicio, hice uso la función de sort, de la biblioteca de algorithm, que varía segun el caso, pero por lo general opta por usar el algoritmo de ordenamiento de Quicksort, que usa pivotes para ordenar parcialmente los arreglos, de tal manera que al final ordena arreglos mucho más ordenados que implica menos ciclos.
Sin embargo, aunque en su caso promedio tiene una complejidad de Θ(n log (n)), en el peor de los casos tiene un tiempo asinótico de O(n^2). Y una complejidad de espacio de O(log(n))

- Busqueda Binaria: Con la implementación de la nueva estructura de datos, había que cambiar también el algoritmo principal de búsqueda, que en este caso es el de la búsqueda binaria. Eset algoritmo es altamente eficiente, en especial, por que reduce mucho los tiempos asíntóticos, al segmentar un poco la parte de la búsqueda, y mejora el algoritmo que teníamos antes en cuando a su caso promedio que es de complejidad Θ(log (n)), sin embargo, si nuestro programa llega a generar un árbol completamente degenerado, es decir, en su peor caso, tiene un tiempo asinótico de O(n), aún mejor que el de nuestro anterior algoritmo. Y una complejidad espacial de O(n)

### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa.

Respecto a la estructura de datos, hago uso de un árbol BST, que según su análisis de tiempos asintóticos que en promedio tienden a ser Θ(n log (n)), lo que significa que reducen exponencialmente debido en este caso a la estructura estable de un árbol, y teniendo sus peores casos con un tiempo asintótico de  O(n). Esta estructura, se encuentra declarada en el archivo Arbol.h, los nodos a partir de la línea 28 y la estructura principal del árbol como tal a partir de la línea 377 del mismo archivo. 

#### Análisis de los usos de dicha estructura:

- Constructor Arbol():
Complejidad de tiempo: O(1)
Complejidad de espacio: O(1)
Justificación:
La inicialización del árbol simplemente asigna el puntero root a nullptr. Esta operación es constante, independientemente del tamaño del árbol, por lo que tanto la complejidad de tiempo como la complejidad de espacio son O(1).

- Destructor ~Arbol():
Complejidad de tiempo: O(n)
Complejidad de espacio: O(1)
Justificación:
El destructor invoca el método removeAll(), que elimina todos los nodos del árbol. La complejidad de tiempo de removeAll() es O(n), ya que tiene que visitar cada nodo del árbol para liberar la memoria.
La complejidad de espacio es O(1) porque la eliminación de nodos se realiza en su lugar y no requiere espacio adicional en función del tamaño del árbol.

- Método add(PrendaRopa val):
Complejidad de tiempo: O(log(n))
Complejidad de espacio: O(log(n))
Justificación:
El método add busca el valor val en el árbol antes de agregarlo para evitar duplicados. Si el árbol no está vacío (root != 0), invoca el método find que tiene una complejidad de tiempo de O(log(n)) en un árbol balanceado, ya que realiza una búsqueda binaria.
Si el valor no se encuentra, entonces se llama al método add en el nodo raíz (root->add(val)). La inserción en un árbol binario de búsqueda balanceado tiene una complejidad de tiempo de O(log(n)) ya que implica recorrer el árbol hacia abajo a través de "sub-árboles" en función del valor.
La complejidad de espacio también es O(log(n)) ya que la inserción y búsqueda se realizan de manera recursiva, creando una llamada de pila para cada nivel del árbol.

- Método find(PrendaRopa val) const:
Complejidad de tiempo: O(log(n))
Complejidad de espacio: O(1)
Justificación:
El método find busca el valor val en el árbol. Si el árbol no está vacío (root != 0), invoca el método find en el nodo raíz (root->find(val)).
La búsqueda en un árbol binario de búsqueda balanceado tiene una complejidad de tiempo de O(log(n)), ya que en cada paso se reduce la búsqueda a la mitad del árbol.
La complejidad de espacio es O(1), ya que no se utiliza memoria adicional en función del tamaño del árbol.

- Método remove(PrendaRopa val):
Complejidad de tiempo: O(log(n))
Complejidad de espacio: O(log(n))
Justificación:
El método remove elimina un nodo con el valor val del árbol. Si el árbol no está vacío (root != 0), primero verifica si el valor a eliminar está en el nodo raíz (val == root->value). Si es así, encuentra el sucesor del nodo raíz, conecta los subárboles del sucesor con el nodo raíz y luego elimina el nodo raíz. Esto tiene una complejidad de tiempo constante O(1) porque involucra operaciones simples.
Si el valor a eliminar no está en el nodo raíz, llama al método remove en el nodo raíz (root->remove(val)), que tiene una complejidad de tiempo de O(log(n)) en un árbol balanceado, ya que implica recorrer el árbol hacia abajo.
La complejidad de espacio también es O(log(n)), ya que la eliminación se realiza de manera recursiva, creando una llamada de pila para cada nivel del árbol.

- Método removeAll():
Complejidad de tiempo: O(n)
Complejidad de espacio: O(n)
Justificación:
El método removeAll elimina todos los nodos del árbol. Si el árbol no está vacío (root != 0), invoca el método removeChilds() en el nodo raíz (root->removeChilds()). Este método elimina recursivamente todos los hijos de un nodo dado.
La complejidad de tiempo es O(n) porque se llama al método removeChilds() para cada nodo del árbol, y cada llamada a este método implica visitar todos los nodos de un subárbol. En el peor caso, se recorren todos los nodos del árbol una vez.
La complejidad de espacio también es O(n) debido a las llamadas recursivas. Cada llamada crea una nueva instancia de la pila, y en el peor caso, hay n llamadas de función pendientes en la pila, lo que lleva a un uso de espacio proporcional a n.

- Método inorder() const:
Complejidad de tiempo: O(n)
Complejidad de espacio: O(n)
Justificación:
El método inorder realiza un recorrido inorden en el árbol, que visita todos los nodos en el orden correcto. Si el árbol no está vacío (!empty()), invoca el método inorder en el nodo raíz (root->inorder(aux)).
La complejidad de tiempo es O(n), donde n es el número de nodos en el árbol. En cada llamada recursiva, se procesa un nodo, y como máximo se procesa cada nodo una vez.
La complejidad de espacio es O(n) debido a las llamadas recursivas. En el peor caso, hay n llamadas de función pendientes en la pila, lo que lleva a un uso de espacio proporcional al número de nodos.
La operación principal dentro del método (aux << "[") y aux << "]";) tiene una complejidad constante ya que son operaciones simples de inserción en un stringstream.

- Método preorder() const:
Complejidad de tiempo: O(n)
Complejidad de espacio: O(n)
Justificación:
El método preorder realiza un recorrido en preorden en el árbol, que visita todos los nodos en el orden correcto. Si el árbol no está vacío (!empty()), invoca el método preorder en el nodo raíz (root->preorder(aux)).
La complejidad de tiempo es O(n), donde n es el número de nodos en el árbol. En cada llamada recursiva, se procesa un nodo, y como máximo se procesa cada nodo una vez.
La complejidad de espacio es O(n) debido a las llamadas recursivas. En el peor caso, hay n llamadas de función pendientes en la pila, lo que lleva a un uso de espacio proporcional al número de nodos.
La operación principal dentro del método (aux << "[") y aux << "]";) tiene una complejidad constante ya que son operaciones simples de inserción en un stringstream.
En resumen, el método preorder() const tiene una complejidad de tiempo y espacio lineal O(n) en un árbol binario de búsqueda balanceado, ya que procesa cada nodo exactamente una vez.

- Método mostrarDatos():
Complejidad de tiempo: O(n)
Complejidad de espacio: O(n)
Justificación:
El método mostrarDatos parece invocar el método mostrarDatoss en el nodo raíz del árbol, que probablemente es un método que devuelve una representación en cadena de los datos del nodo. Si el árbol no está vacío (root != 0), invoca el método mostrarDatoss en el nodo raíz (root->mostrarDatoss()).
La complejidad de tiempo es O(n), donde n es el número de nodos en el árbol. En cada llamada recursiva, se procesa un nodo, y como máximo se procesa cada nodo una vez.
La complejidad de espacio es O(n) debido a las llamadas recursivas. En el peor caso, hay n llamadas de función pendientes en la pila, lo que lleva a un uso de espacio proporcional al número de nodos.
La operación principal dentro del método (datos += root->mostrarDatoss();) tiene una complejidad constante en cada llamada recursiva.

- Método search(int _id):
Complejidad de tiempo: O(log(n)) en promedio para un árbol balanceado, O(n) en el peor caso
Complejidad de espacio: O(1)
Justificación:
El método search busca un nodo con el ID proporcionado en el árbol. Si el árbol no está vacío (root != 0), invoca el método search en el nodo raíz (root->search(_id)).
La complejidad de tiempo es O(log(n)) en promedio para un árbol balanceado, ya que en cada paso se reduce la búsqueda a la mitad del árbol. Sin embargo, en el peor caso, donde el árbol no está balanceado y tiene una estructura de lista enlazada, la complejidad sería O(n), ya que podría ser necesario recorrer todo el árbol.
La complejidad de espacio es O(1), ya que no se utiliza memoria adicional en función del tamaño del árbol.

- Métodos filtrar(string _query): //tipo, color, talla, material, estado
Complejidad de tiempo: O(n)
Complejidad de espacio: O(1)
Justificación:
El método filtrar parece realizar un filtrado de nodos basado en un tipo de consulta _query. Si el árbol no está vacío (root != 0), invoca el método filtrar en el nodo raíz (root->filtrar(_query)).
La complejidad de tiempo es O(n), donde n es el número de nodos en el árbol. En el peor caso, se debe visitar cada nodo del árbol para aplicar el filtro.
La complejidad de espacio es O(1), ya que no se utiliza memoria adicional en función del tamaño del árbol.

- Método ordenarPuestas(int _p, string _tipo):
Complejidad de tiempo: O(n)
Complejidad de espacio: O(1)
Justificación:
El método ordenarPuestas parece realizar alguna operación de ordenamiento o clasificación de nodos basada en un parámetro _p y un tipo _tipo. Si el árbol no está vacío (root != 0), invoca el método ordenarPuestas en el nodo raíz (root->ordenarPuestas(_p, _tipo)).
La complejidad de tiempo es O(n), donde n es el número de nodos en el árbol. En el peor caso, se debe visitar cada nodo del árbol para realizar la operación de ordenamiento.
La complejidad de espacio es O(1), ya que no se utiliza memoria adicional en función del tamaño del árbol.

- Método contar_prendas():
Complejidad de tiempo: O(n)
Complejidad de espacio: O(1)
Justificación:
El método contar_prendas parece contar la cantidad total de prendas en el árbol. Si el árbol no está vacío (root != 0), invoca el método contar_prendas en el nodo raíz (root->contar_prendas()).
La complejidad de tiempo es O(n), donde n es el número de nodos en el árbol. En el peor caso, se debe visitar cada nodo del árbol para contar las prendas.
La complejidad de espacio es O(1), ya que no se utiliza memoria adicional en función del tamaño del árbol.

- Método reasignarID():
Complejidad de tiempo: O(n)
Complejidad de espacio: O(1)
Justificación:
El método reasignarID parece realizar alguna operación de reasignación de identificadores (IDs) en los nodos del árbol. Si el árbol no está vacío (root != 0), invoca el método reasignarID en el nodo raíz (root->reasignarID(1)).
La complejidad de tiempo es O(n), donde n es el número de nodos en el árbol. En el peor caso, se debe visitar cada nodo del árbol para realizar la operación de reasignación de IDs.
La complejidad de espacio es O(1), ya que no se utiliza memoria adicional en función del tamaño del árbol.

### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.

##### Hay métodos que no fueron mencionados en los anteriores, porque van más en cuanto a la administración de archivos, en cuanto a lectura y escritura de los mismos, los englobaré en el mismo análisis asintótico debido a que hacen acciones realmente similares y están declarados en el archivo ClosetLavadora.h a partor de la línea 667
- Método creaCloset(), creaTienda(), y actualizaArchivo(Arbol* arbol):
Complejidad de tiempo: O(n)
Complejidad de espacio: O(1)
Justificación:
El método lee información desde un archivo CSV línea por línea utilizando un bucle while, por lo que la complejidad de tiempo está dominada por el número de líneas en el archivo.
En cada línea, se realiza un análisis adicional para separar los campos y luego se invoca el método crearPrenda que probablemente crea un nodo en el árbol. La creación de cada prenda y la invocación de crearPrenda son operaciones de tiempo constante O(1).
La complejidad de espacio es O(1) ya que las variables adicionales (por ejemplo, las cadenas nombre, tipo, etc.) ocupan una cantidad constante de espacio independientemente del tamaño del archivo.
Por otro lado, para el actualizaArchivo, realiza una operación de escritura en un archivo CSV basada en la información almacenada en un árbol.
La complejidad de tiempo está dominada por el número total de prendas en el árbol, ya que se recorre el árbol y se escribe la información de cada prenda en el archivo.
En cada iteración del bucle for, se realiza una operación constante de escritura en el archivo, y el bucle se ejecuta una vez por cada prenda en el árbol.
La complejidad de espacio es constante O(1) ya que las variables adicionales (por ejemplo, la variable prenda) ocupan una cantidad constante de espacio independientemente del tamaño del árbol.
El método no utiliza memoria adicional en función del tamaño del árbol.

#### Complejidad final del programa:
 Es posible conseguir que aunque se comience con un árbol no degenerado, existe la posibilidad de que haciendo uso de muchos de los métodos mencionados con anterioridad que modifican el árbol, en este caso, add y remove, para que el árbol quede completamente degenerado, lo que implicaría que el árbol ya no sería un árbol de búsqueda binaria como tal, sino más una Singly-Linked List, aunque sin la particularidad de la tail que esta tiene, por lo que para incersiones, eliminaciones y búsquedas, en el peor de los casos tenemos una complejidad temporal de O(n), teniendo que recorrer todos los nodos y su complejidad espacial sería nuevamente de O(n). En este caso, perdería toda la eficiencia que caracteriza al BST como tal.

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
