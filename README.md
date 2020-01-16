# CanSat
Un CanSat es un pico satélite que tiene el tamaño de una lata de refresco.
 Dentro de este van todos los componentes que permiten su funcionamiento,
 como lo son sensores que obtienen datos, las baterías que permiten que se mantenga
 encendido, un paracaídas y demás implementos que dependen del objetivo de este.

 El objetivo de este CanSat es el medir variables relacionados con el movimiento,
 la altura y la temperatura que se presentan dentro de su contenedor.

 Este proyecto se deriva de la OBC (On Board Computer) hecha para el cohete modelo POA en la Universidad Distrital Francisco José de Caldas.

### Sensores y electrónicos utilizados
* Arduino pro mini (5v)
* BMP 280 (Versión China)
* MPU 6050
* Xbee S1 (con antena)
* Adaptador Xbee
* Bateria Lipo 7.4 V - 1100 mAh

### Datos que se obtienen :
 * tiempo que ha transcurrido desde que es encendido
 * altura relativa
 * si está en caída libre
 * temperatura
 * presión atmosférica
 * pitch
 * roll
 * yaw
 * aceleración en X
 * aceleración en Y
 * aceleración en Z

 La toma de datos se hace cada 500 ms, parametro que puede ser modificado en
 la pestaña `CanSat-codigo.ino`
