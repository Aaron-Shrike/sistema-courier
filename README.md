# Sistema Courier - C
Sistema de una Courier en lenguaje C. Crea una Courier con el máximo de encomiendas y el precio por kilogramo para luego registra las encomiendas y actualiza su estado de envió, este estado puede ser consultado en el sistema, así como el dinero recaudado del día.
<br>
Proyecto del **segundo semestre** de estudios en Ingeniería Informática, presentado el **24/07/18**.

## Uso
1. **Inicializar**: Se inicializa la courier y sus variables.
2. **Depósito**: Se ingresa el nombre del Courier, el peso máximo de encomiendas diarias y el precio por kilogramo.
3. **Recepción de encomiendas**: Se ingresan los datos del cliente (DNI y nombre), la cantidad de paquetes que enviará el cliente, los datos de cada paquete (Descripción, destinatario, DNI del destinatario y peso) y se muestra el precio por paquete, total a pagar y si cada envío saldrá en el día actual o al día siguiente. Para cada paquete recibido se genera un código de envío de 3 dígitos. En esta opción el estado de todo paquete queda como pendiente.
4. **Actualización de estado**: Se ingresa el código de envío de un paquete para modificar su estado entre 4 opciones disponibles (Pendiente, en viaje, en destino y entregado).
5. **Consulta**: Se ingresa el código de envío de un paquete para mostrar sus detalles (Remitente, DNI del remitente, destinatario, DNI del destinatario, descripción, peso, costo y estado).
6. **Reporte general**: Aquí se muestra el nombre del Courier, el número de clientes atendidos y una lista detallada de todos los envíos.
7. **Balance del día**: Aquí se muestra el total de dinero recaudado.
9. **Salir**: Finaliza la ejecución del programa.

### Nota
- Después de entrar a una opción y haber terminado con la ejecución es necesario volver a teclear ```enter``` para regresar al menú principal.
- En la opción **Consulta** se ingresa el código del producto, dicho código se asigna automáticamente desde el número 100 en adelante.

## Autores
- Ramirez Benites Rafael
- [Rojas Vera Aarón](https://github.com/Aaron-Shrike)
