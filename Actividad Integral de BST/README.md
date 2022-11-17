![Tec de Monterrey](images/logotecmty.png)
# Act 3.4 - Actividad Integral de Árboles (Evidencia Competencia)

## <span style="color: rgb(26, 99, 169);">¿Qué tengo que hacer?</span>
En este repositorio encontrarás los archivos de entrada, así como las salidas esperadas que podrás usar para probar tu implementación. También encontrarás un archivo "main.cpp". Ahí deberás implementar tu solución. En el archivo deberás colocar en la parte superior, en comentarios, tus datos. Por ejemplo:
```
// =========================================================
// File: main.cpp
// Author: Edward Elric - A00123456
// Date: 01/01/2021
// =========================================================
```
<span style="text-decoration: underline;">De manera individual</span>, desarrolla la solución del siguiente problema:

A causa del COVID-19, muchas puertos han reducido sus operaciones. Debido a esto, y con el fin de dar un mejor servicio, la compañía naviera "International Seas, Ltd." ha pedido a sus clientes que envíen sus pedidos en orden creciente por prioridades. De esta manera, la compañía podrá determinar el correcto orden de envío de todos los pedidos.

En un principio, esto parecía una buena idea. Si bien, mezclar dos listas ordenadas, A = {a<sub>1</sub>, a<sub>2</sub>, ..., a<sub>n</sub>} y B = {b<sub>1</sub>, b<span style="font-size: 12px;">2</span>, ..., b<sub>m</sub>}, es un trabajo sencillo (recuerdas el algoritmo Mergesort). De hecho, el número de comparaciones a realizar serían (m + n - 1) en el peor caso. Pero, pronto empezaron a llegar más y más listas de los diversos clientes y pronto el departamento de Logística y envío se han visto sobrepasado.

Veamos cuál es el problema. Por ejemplo, supongamos que tenemos un conjunto de pedidos de envío {P<sub>1</sub>, P<sub>2</sub>, P<sub>3</sub>, P<sub>4</sub>, P<sub>5</sub>} con tamaños {20, 5, 8, 7, 4} respectivamente. Si realizamos las siguientes mezclas:

* P<sub>1</sub> y P<sub>2</sub> ⟶ Z<sub>1</sub>, serían 20 + 5 - 1 = 24 comparaciones.
* Z<sub>1</sub> y P<sub>3</sub> ⟶ Z<sub>2</sub>, serían 24 + 8 - 1 = 31 comparaciones.
* Z<sub>2</sub> y P<sub>4</sub> ⟶ Z<sub>3</sub>, serían 31 + 7 - 1 = 37 comparaciones.
* Z<sub>3</sub> y P<sub>5</sub>, serían 37 + 4 - 1 = 40 comparaciones.  

Lo que nos da un total de 132 comparaciones.

Desarrolla una solución que, dada un conjunto de pedidos y sus tamaños, calcule el menor número de comparaciones posibles.

## <span style="color: rgb(26, 99, 169);">**Entrada**</span>
La primera línea de entrada contiene,  *N*, el número de listas. En la siguiente línea encontrarás *N* números enteros separados por espacios que indican los tamaños de las listas.

## <span style="color: rgb(26, 99, 169);">**Salida**</span>
Despliega el menor número de operaciones posibles.

## <span style="color: rgb(26, 99, 169);">**Ejemplo de entrada**</span>
6 <br>
20 5 8 20 7 4

## <span style="color: rgb(26, 99, 169);">**Ejemplo de salida**</span>
147

Para probar tu implementación, compila tu programa con el comando:
```
g++ -std=c++11 main.cpp -o app
```
Posteriormente, prueba con cada uno de los archivos de entrada de prueba que encontrarás en este repositorio (input1.txt, input2.txt, input3.txt, input4.txt). Los resultados que debes obtener se encuentran en los archivos llamados output1.txt, output1.txt, output1.txt y output1.txt. Para realizar las pruebas, puedes usar las siguientes líneas de código. Por ejemplo, si queremos probar con el archivo de prueba "input1.txt".
```
./app < input1.txt > mysolution1.txt
diff mysolution1.txt output1.txt
```
Si el segundo comando no tenga ninguna salida, sabrás que los resultados que obtuviste son los esperados. Recuerda actualizar tu repositorio (*git push*) cuando hayas terminado tu implementación.

Por último, realiza una investigación y reflexión de la importancia y eficiencia del uso de BST en una situación problema de esta naturaleza. ¿Cómo podrías determinar si una red está infectada o no?, generando un documento llamado **"ReflexAct3.4.pdf"**

## <span style="color: rgb(26, 99, 169);">**¿Bajo qué criterios se evalúa mi evidencia?**</span>

- **80%** - Para cada una de las funcionalidades se evaluará:

    - **Excelente (80%)** - pasa correctamente todos los casos de prueba.
    - **Muy Bien (60%)** - pasa correctamente el 75% de los casos de prueba.
    - **Bien (40%)** - pasa correctamente el 50% de los casos de prueba.
    - **Insuficiente (20%)** - pasa correctamente menos del 50% de los casos de prueba.


- **10%** - El código deberá seguir los lineamientos estipulados en el estándar de codificación: <span class="instructure_file_holder link_holder">[liga_estándar_codificación](estandar.pdf)</span>
- **10%** - Se respetenan los nombres de las funciones en la aplicación.

## <span style="color: rgb(26, 99, 169);">**¿Dónde la entrego?**</span>
Esta actividad forma parte tanto de tu calificación final del curso, así como del portafolio de evidencias de las competencias a desarrollar del curso, por lo que se te pide que en forma individual:
* Realices una entrega del código fuente de la solución del problema, en la sección correspondiente dentro de esta plataforma, así como el documento de reflexión individual (**ReflexAct3.4.pdf**).
En la carpeta personal llamada **TC1031(Portafolio_Final)** que generaste desde la entrega de la actividad 1.3 y que te servirá como preparación para la entrega del portafolio de competencias que se realizará al final del curso, coloca en la subcarpeta **Act3.4** tus archivos que solucionaron la <span style="text-decoration: underline;">actividad 3.4</span> así como el documento de reflexión individual (**ReflexAct3.4.pdf**) .
