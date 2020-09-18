# Emb2_p01_Vargas_Gomez

En esta práctica se realizaron las siguientes funciones que son parte de la API:

- rtos_start_scheduler
  Se añadió la inicialización del global tick, current task y y el sysTick de la tarjeta según lo necesario, 
  se carga el tick del sistema y por ultimo se añadió la función para crear una IDLE Task.{
  
- rtos_create_task
  Primero se verifica si hay espacio disponible para crear la tarea, después se verifica si fue solicitada su 
  creación con un autostart o no, si lo fue se procede a la inicialización de todos los elementos de la estructura 
  task_list, y se pone la tarea en un estado de ready. De lo contrario se pone en un estado de suspendido.

- rtos_get_clock
  Devuelve el valor del Systick.
  
- rtos_delay
  La tarea se pone en estado "waiting", se le asignan los ticks y se llama al "dispatcher" indicándole que fue 
  la ejecución de la tarea.
  
- rtos_suspend_task
  La tarea se pone en estado "suspend" y se llama al "dispatcher" indicándole que fue la ejecución de la tarea.
  
- rtos_activate_task
  La tarea se pone en estado "ready" y se llama al "dispatcher" indicándole que fue la ejecución de la tarea.
  
- dispatcher 
  Verificamos cuál tarea es la siguiente en ejecutar dependiendo de su prioridad y viendo si está "ready" o 
  "running", una vez encontrada la tarea a ejecutar comprobamos que no esté en ejecución, para  realizar el 
  cambio de contexto, de lo contrario la dejamos en ejecución y no realizamos ningún cambio en el contexto. 
  
- context_switch
  Con ayuda de una bandera nos aseguramos de que no sea la primera ejecución del sistema. Si es así, se 
  accede a la función donde se realiza el cambio de tarea y se pone la bandera del PENDSV. Si no es la primera, 
  se comprueba de dónde vino el cambio de contexto, para ver cómo se ajustará el SP.
  
- activate_waiting_tasks
  Se verifica si cada tarea está en estado de "waiting", si alguna tarea sí está en este estado se va decrementando
  el número de ticks y se va verificando si llega a cero esta variable. Si es así se cambia su estado a "ready".
  
- SysTick_Handler
  Primero se llama a una función que permite al usuario asegurarse de que el programa sigue ejecutándose, con la 
  finalidad de mostrar un “funcionamiento correcto”, despues se activan las tareas que se encuentran en espera y 
  reinicia el systick. Por último se llama al dispatcher indicándole que es desde una interrupción.
  
- PendSV_Handler
  Simplemente carga el stack pointer del procesador con el stack pointer de la tarea actual.
  
  Conclsuiones:
  
  Esta práctica fue particualrmente difícil por el tema de calcular bien los offset del stack pointer al hacer un
  cambio de contexto. Era necesario saber cómo se genero dicho cambio de contexto y conociendo esto se sabría qué valor 
  añadir o restar al SP. 
  
  Hubo también dificultades con el IDE de MCUExpresso y una buena parte del desarrollo se realizó en conjunto en Atom. 
  
  Finalmente consideramos que esta práctica ha hecho que comprendamos de mejor manera el funcionamiento de este miniRTOS.
  Las consideraciones que hay que tener al implementarlo pero más que nada entender cada paso de la secuencia del SO. 
  
  Alberto Vargas Garrido IE710231
  Emiliano Gómez Guerrero IE708504
