# Diego-Quezada-Colorado-TC1031

## Proyecto Closet-Lavadora
## Diego Quezada Colorado A01710024

El objetivo de este proyecto es modelar el funcionamiento de una idea que podría ser útil para nuestras generaciones futuras. Con el uso de la IA y su incorporación cada vez más cercana con nuestra vida diaria, se propone este proyecto que nos ayudaría en el ámbito personal. Lo que hace este Closet-Lavadora inteligente es tener un sistema lleva un control de las prendas de ropa que usas (playeras, pantalones, zapatos, accesorios, etc.) y de su uso y en base al mismo uso las lava y las vuleve a poner. Asímismo es posible adquirir más prendas y desechar las que ya no quieras. Y también te permite filtrat tu closet por tipo de prenda, color, material, veces de uso y talla.

## SICT0301: Evalúa los componentes
### Hace un análisis de complejidad correcto y completo para los algoritmos de ordenamiento usados en el programa.

De momento uso la función de sort, de la biblioteca de algorithm, que varía segun el caso, pero por lo general opta por usar el algoritmo de ordenamiento de Quicksort, que usa pivotes para ordenar parcialmente los arreglos, de tal manera que al final ordena arreglos mucho más ordenados que implica menos ciclos.
Sin embargo, aunque en su caso promedio tiene una complejidad de Θ(n log (n)), en el peor de os casos tiene un tiempo asinótico de O(n^2).

### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa.
Respecto a la estructura de datos, hago uso de un árbol AVL, que según su análisis de tiempos asintóticos que en promedio tienden a ser Θ(n log (n)), lo que significa que reducen exponencialmente debido en este caso a la estructura estable de un árbol, y teniendo sus peores casos con un tiempo asintótico de también O(n log (n))

## SICT0302: Toma decisiones
### Selecciona un algoritmo de ordenamiento adecuado al problema y lo usa correctamente.
QuickSort es una elección sólida para ordenar un closet de prendas de vestir, especialmente si valoras la eficiencia promedio y la adaptabilidad a datos parcialmente ordenados. Aunque ahora con la incorporación de la estructura de árbol AVL, el algoritmo de búsqueda prácticamente viene incluido con la estructura y es aún más eficiente que el QuickSort

### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.
Nuevamente mencionamos que establecimos una estructura de árbol AVL, donde cada nodo de dicho árbol es un elemento de tipo Prenda Ropa y organiza de buena manera la estructura clave para el manejo de datos en ClosetLavadora

## SICT0303: Implementa acciones científicas

### Implementa mecanismos para consultar información de las estructras correctos.
Auxiliados de la estructura general del árbol AVL, se crearon funciones auxiliares en dich archivo (AVL.h), que ayudan a extraer valores recorriendo el árbol

### Implementa mecanismos de lectura de archivos para cargar datos a las estructuras de manera correcta.
En el archivo de ClosetLavadora, con ayuda de las 2 últimas funciones, es decir creaCloset y creaTienda, se importan los datos de un archivo .csv a la estructura del árbol, con ayuda de la librería ifstream, en el proceso se involucra el proceso de apertura y lectura correcta de archivos para incluirlos correctamente en el árbol

## Consideraciones:
Todos los archivos deben estar en la misma carpeta, para que el prorgrama funcione correctamente

El programa solo corre en la consola o en replit también y esta hecho con c++ standard por lo que corre en todos los sistemas operativos, no incluye bibliotecas extra, mas que la de string, para poder usar este tipo de dato y la de algorithm

-compilar con: la ruta donde se encuentre la carpeta que tiene todos los archivos, y posteriormente "g++ main.cpp"

-correr en linux: "/a.out"

-correr en windows: "a.exe"

## Restricciones o casos en los que el programa deja de funcionar:
-Cuando se solicite la entrada de datos, por lo general se dan opciones de numeros para que el usuario escoja o en su defecto, se pide que se escriba un nombre o la palabra si o no. Para estos casos, favor de ser muy cuidadoso e ingresar el tipo de dato que se espera, de lo contrario, el programa deja de funcionar
