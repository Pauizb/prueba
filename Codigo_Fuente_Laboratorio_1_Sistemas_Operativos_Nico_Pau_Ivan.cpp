#include<stdio.h>
#include<stdlib.h>
#define MAX 100

// Integrantes Paula Ruiz Bustos 20.676.661-1 | Nicolas Manuel Ruiz Riesco 20.206.651-8 | Ivan De la O 20.627.901-k

void ascendente(int *tiempo_llegada, int *rafaga,int numero_proceso); //Prototipo de la funcion que ordena los tiempos de llegada desde el mas bajo hasta el mayor para los procesos
int main()
{
    int opcion;
    int numero_de_procesos;  //variable donde se guardaran la cantidad de procesos asignados por el usuario
        printf("\n                         -------------------------------\n");
        printf("\n                         PROGRAMA PARA COLA DE PROCESOS\n");
        printf("               Paula Ruiz Bustos | Nicolas Ruiz Riesco | Ivan De la O\n");
        printf("\n                         -------------------------------\n\n");
        printf("\nIngresar cuantos procesos (jobs) tendran las colas: ");
        scanf("%d",&numero_de_procesos);
        printf("\n");
        int yaentro1 = 0;   //variables que se ocuparan como switch y saber si entro o no a las opciones del menu
        int yaentro2 = 0;   // y asi dar mas opciones y restricciones
        int yaentro3 = 0;
        int tiempo_de_llegada1[numero_de_procesos];
        int tiempo_de_llegadaq3[numero_de_procesos];
        int tiempo_de_llegadaq8[numero_de_procesos];
        int rafaga1[numero_de_procesos];
        int rafaga_de_q3[numero_de_procesos];
        int rafaga_de_q8[numero_de_procesos];            //Todas estas son vectores que se declaran con tamaño del n° de procesos que dice el usuario y seran utilizadas
        int rafaga_copiaq3[numero_de_procesos];
        int rafaga_copiaq8[numero_de_procesos];
        int tiempo1[numero_de_procesos];
        int tiempo_de_q3[numero_de_procesos];
        int tiempo_de_q8[numero_de_procesos];
        int auxq8,coefq3=0,coefq8=0,lim3=0,lim8=0,MIN=2,contador1,contadorqu3,contadorqu8,valor_quantumq3,valor_quantumq8,auxq3; // el valor del quantum podria ser modificable pero esta fijo para abarcar lo pedido
        int swap3[MAX][MIN];
        int swap8[MAX][MIN];
        for(int i=0; i<numero_de_procesos; i++){
        printf("Ingresar el tiempo de llegada del proceso %d: ",i+1);
		scanf("%d",&tiempo_de_llegada1[i]);

		tiempo_de_llegadaq3[i] = tiempo_de_llegada1[i]; // Creacion de copia de los tiempos de llegada para q3
		tiempo_de_llegadaq8[i] = tiempo_de_llegada1[i]; // Creacion de copia de los tiempos de llegada para q8
 		printf("Ingresar la rafaga del proceso %d: ",i+1);
        scanf("%d",&rafaga1[i]);

        rafaga_de_q3[i] = rafaga1[i]; // Creacion de copia de la rafaga para q3
		rafaga_de_q8[i] = rafaga1[i]; // Creacion de copia de la rafaga para q8
            }
        printf("\n");

    do{
        printf("1) Generar la cola Q1 (RR quantum = 3).\n");
        printf("2) Generar la cola Q2 (RR quantum = 8).\n");
        printf("3) Generar la cola Q3 (FCFS).\n");
        printf("4) Salir.\n");

        printf("\n    Ingrese opcion: ");
        scanf("%d",&opcion);
        if((yaentro1 == 1 && opcion == 1) || (yaentro2 == 2 && opcion == 2)|| (yaentro3 == 3 && opcion == 3))
        {
            printf("\n\nYa ingreso esta opcion seleccione otra opcion o puede Salir con opcion 4\n\n");
        }
        if(opcion==1 && yaentro1==0)
        {
            yaentro1 = 1;
            valor_quantumq3 = 3; //aqui es modificable el valor del quantum en este caso es 3
            ascendente(tiempo_de_llegadaq3,rafaga_de_q3,numero_de_procesos); //se ordenan por orden de llegada menor primero mayor ultimo
            for(int i=0; i<numero_de_procesos; i++){
            rafaga_copiaq3[i]=rafaga_de_q3[i];}     //se guarda una copia de la rafaga en otro vector
            if(rafaga_de_q3[0]>valor_quantumq3){
            auxq3=tiempo_de_llegadaq3[0]+valor_quantumq3;
            rafaga_de_q3[0]=rafaga_de_q3[0]-valor_quantumq3;
            tiempo_de_q3[0]=auxq3;                            //el calculo se hacen mediante la sustraccion del valor del quantum a la rafaga de cada proceso es decir se ejecuta la cantidad de veces igual a la de numero de proceso
            swap3[coefq3][0]=auxq3;
            swap3[coefq3][1]=0;
            coefq3++;
            }
            else{   // pero si la rafaga es mayor al numero del quantum pasa al else donde se hace directo la suma para calcular la variable auxq3 que es la que guarda el valor del tiempo total que se demora cada proceso sub i
            auxq3=tiempo_de_llegadaq3[0]+rafaga_de_q3[0];
            tiempo_de_q3[0]=auxq3;
            }
            int i=1;
            while(i<numero_de_procesos){
            if(coefq3!=0 && tiempo_de_llegadaq3[i]<=swap3[lim3][0]){ //
              if(rafaga_de_q3[i]>valor_quantumq3){
                auxq3=auxq3+valor_quantumq3;
                tiempo_de_q3[i]=auxq3;
                rafaga_de_q3[i]=rafaga_de_q3[i]-valor_quantumq3;
                swap3[coefq3][0]=auxq3;
                swap3[coefq3][1]=i;
                coefq3++; }
                else{
                auxq3=auxq3+rafaga_de_q3[i];
                tiempo_de_q3[i]=auxq3;}
                i++;}
                else if(coefq3==0){
                 if(rafaga_de_q3[i]>valor_quantumq3){
                  auxq3=auxq3+valor_quantumq3;
                  rafaga_de_q3[i]=rafaga_de_q3[i]-valor_quantumq3;
                  swap3[coefq3][0]=tiempo_de_q3[i];
                  swap3[coefq3][1]=i;
                  coefq3++; }
                 else{
                  auxq3=auxq3+rafaga_de_q3[i];
                  tiempo_de_q3[i]=auxq3; }
                  i++;}
                else{
                  contadorqu3=swap3[lim3][1];
                  lim3++;
                  if(rafaga_de_q3[contadorqu3]>valor_quantumq3){
                  auxq3=auxq3+valor_quantumq3;
                  tiempo_de_q3[contadorqu3]=auxq3;
                  rafaga_de_q3[contadorqu3]=rafaga_de_q3[contadorqu3]-valor_quantumq3;
                  swap3[coefq3][0]=tiempo_de_q3[contadorqu3];
                  swap3[coefq3][1]=contadorqu3;
                  coefq3++; }
                  else{
                    auxq3=auxq3+rafaga_de_q3[contadorqu3];
                    tiempo_de_q3[contadorqu3]=auxq3;}
                   }
                   }
            while(lim3<coefq3){
                contadorqu3=swap3[lim3][1];
                lim3++;
                if(rafaga_de_q3[contadorqu3]>valor_quantumq3){
                  auxq3=auxq3+valor_quantumq3;
                  tiempo_de_q3[contadorqu3]=auxq3;
                  rafaga_de_q3[contadorqu3]=rafaga_de_q3[contadorqu3]-valor_quantumq3;
                  swap3[coefq3][0]=tiempo_de_q3[contadorqu3];
                  swap3[coefq3][1]=contadorqu3;
                  coefq3++;}
                else{
                  auxq3=auxq3+rafaga_de_q3[contadorqu3];
                  tiempo_de_q3[contadorqu3]=auxq3;}
                  }

          int turnaroundtime[numero_de_procesos];
          float suma_turnaroundtime=0,suma_waitingtime=0;
          for(int i=0; i<numero_de_procesos; i++){
          turnaroundtime[i]=tiempo_de_q3[i]-tiempo_de_llegadaq3[i];
          suma_turnaroundtime+=turnaroundtime[i];}

          int waitingtime[numero_de_procesos];
          for(int i=0; i<numero_de_procesos; i++){
          waitingtime[i]=turnaroundtime[i]-rafaga_copiaq3[i];
          suma_waitingtime+=waitingtime[i];}

            printf("\n\t\t||| TABLA DE ROUND ROBIN QUANTUM = 3 |||\n\n");
            printf("Tiempos de llegada | Rafaga/Burst | Turnaround-Time(tt) |  Waiting-Time(wt)\n\n"); //orden de los datos mostrados en tabla
            for(int i=0; i<numero_de_procesos; i++){
            printf("        %d    \t           %d\t            %d\t              %d\n",tiempo_de_llegadaq3[i],rafaga_copiaq3[i],turnaroundtime[i],waitingtime[i]);
            printf("---------------------------------------------------------------------------\n"); //estetica de tabla
                                                  }
          float promedio_TT,promedio_WT;
          promedio_TT = suma_turnaroundtime/numero_de_procesos; // sumas y division para promedio lo mismo descrito
          promedio_WT = suma_waitingtime/numero_de_procesos;

          printf("\nPromedio de Turnaround-Time: %.2f\nPromedio de Wating-Time: %.2f\n\n",promedio_TT,promedio_WT); //promedios con 2 decimales de tt y wt
        }
        if(opcion==2 && yaentro2 == 0)
        {
            yaentro2 = 2;
            valor_quantumq8 = 8;
            ascendente(tiempo_de_llegadaq8,rafaga_de_q8,numero_de_procesos); //se ordenan por orden de llegada menor primero mayor ultimo

            for(int i=0; i<numero_de_procesos; i++)
            rafaga_copiaq8[i]=rafaga_de_q8[i];

            if(rafaga_de_q8[0]>valor_quantumq8){
            auxq8=tiempo_de_llegadaq8[0]+valor_quantumq8;
            rafaga_de_q8[0]=rafaga_de_q8[0]-valor_quantumq8;
            tiempo_de_q8[0]=auxq8;
            swap8[coefq8][0]=auxq8;
            swap8[coefq8][1]=0;
            coefq8++;}
            else{
            auxq8=tiempo_de_llegadaq8[0]+rafaga_de_q8[0];
            tiempo_de_q8[0]=auxq8;}

            int i=1;
            while(i<numero_de_procesos){
            if(coefq8!=0 && tiempo_de_llegadaq8[i]<=swap8[lim8][0]){ //
              if(rafaga_de_q8[i]>valor_quantumq8){
              auxq8=auxq8+valor_quantumq8;
              tiempo_de_q8[i]=auxq8;
              rafaga_de_q8[i]=rafaga_de_q8[i]-valor_quantumq8;
              swap8[coefq8][0]=auxq8;
              swap8[coefq8][1]=i;
              coefq8++; }
              else{
              auxq8=auxq8+rafaga_de_q8[i];
              tiempo_de_q8[i]=auxq8; }
              i++;}
            else if(coefq8==0){
              if(rafaga_de_q8[i]>valor_quantumq8){
              auxq8=auxq8+valor_quantumq8;
              rafaga_de_q8[i]=rafaga_de_q8[i]-valor_quantumq8;
              swap8[coefq8][0]=tiempo_de_q8[i];
              swap8[coefq8][1]=i;
              coefq8++;}
              else{
              auxq8=auxq8+rafaga_de_q8[i];
              tiempo_de_q8[i]=auxq8;}
              i++;}
            else{
              contadorqu8=swap8[lim8][1];
              lim8++;
              if(rafaga_de_q8[contadorqu8]>valor_quantumq8){
              auxq8=auxq8+valor_quantumq8;
              tiempo_de_q8[contadorqu8]=auxq8;
              rafaga_de_q8[contadorqu8]=rafaga_de_q8[contadorqu8]-valor_quantumq8;
              swap8[coefq8][0]=tiempo_de_q8[contadorqu8];
              swap8[coefq8][1]=contadorqu8;
              coefq8++;}
            else{
              auxq8=auxq8+rafaga_de_q8[contadorqu8];
              tiempo_de_q8[contadorqu8]=auxq8;}
                }
            }
            while(lim8<coefq8){
                contadorqu8=swap8[lim8][1];
                lim8++;
                if(rafaga_de_q8[contadorqu8]>valor_quantumq8){
                  auxq8=auxq8+valor_quantumq8;
                  tiempo_de_q8[contadorqu8]=auxq8;
                  rafaga_de_q8[contadorqu8]=rafaga_de_q8[contadorqu8]-valor_quantumq8;
                  swap8[coefq8][0]=tiempo_de_q8[contadorqu8];
                  swap8[coefq8][1]=contadorqu8;
                  coefq8++;}
                else{
                  auxq8=auxq8+rafaga_de_q8[contadorqu8];
                  tiempo_de_q8[contadorqu8]=auxq8;}
                             }
            int turnaroundtime[numero_de_procesos];
            float suma_turnaroundtime=0,suma_waitingtime=0;
            for(int i=0; i<numero_de_procesos; i++){
            turnaroundtime[i]=tiempo_de_q8[i]-tiempo_de_llegadaq8[i];
            suma_turnaroundtime+=turnaroundtime[i];}

            int waitingtime[numero_de_procesos];
            for(int i=0; i<numero_de_procesos; i++){
            waitingtime[i]=turnaroundtime[i]-rafaga_copiaq8[i];
            suma_waitingtime+=waitingtime[i];}

            printf("\n\t\t||| TABLA DE ROUND ROBIN QUANTUM = 8 |||\n\n");
            printf("Tiempos de llegada | Rafaga/Burst | Turnaround-Time(tt) |  Waiting-Time(wt)\n\n"); //orden de los datos mostrados en tabla
            for(int i=0; i<numero_de_procesos; i++){
            printf("        %d    \t           %d\t            %d\t              %d\n",tiempo_de_llegadaq8[i],rafaga_copiaq8[i],turnaroundtime[i],waitingtime[i]);
            printf("---------------------------------------------------------------------------\n"); //estetica de tabla
            }
            float promedio_TT,promedio_WT;
            promedio_TT = suma_turnaroundtime/numero_de_procesos;  // sumas lo mismo descrito mas abajo en la opcion 3
            promedio_WT = suma_waitingtime/numero_de_procesos;      // es decir suma para calcular promedios y dividir

            printf("\nPromedio de Turnaround-Time: %.2f\nPromedio de Wating-Time: %.2f\n\n",promedio_TT,promedio_WT); //promedios con 2 decimales de tt y wt

        }

        if(opcion==3 && yaentro3 == 0) // opcion 3 solo se entra si se selecciona en el menu y esta dispoible la opcion.
        {
            yaentro3 = 3;
            ascendente(tiempo_de_llegada1,rafaga1,numero_de_procesos); //ordenamiento de menor tiempo de llegada a mayor tiempo de llegada
            int tiempo1[numero_de_procesos];
            tiempo1[0]=tiempo_de_llegada1[0]+rafaga1[0];
            for(int i=1;i<numero_de_procesos;i++){
              if(tiempo1[i-1]>tiempo_de_llegada1[i])
              tiempo1[i]=rafaga1[i]+tiempo1[i-1]; // ecuacion para calcular tiempo total o completo
              else
              tiempo1[i]=(tiempo_de_llegada1[i]-tiempo1[i-1])+rafaga1[i]+tiempo1[i-1];} //segunda opcion de calcular tiempo completo o total

            int turnaroundtime[numero_de_procesos]; // declaraciones
            int waitingtime[numero_de_procesos];
            float suma_turnaroundtime=0,suma_waitingtime=0;
            for(int i=0; i<numero_de_procesos; i++){
              turnaroundtime[i]=tiempo1[i]-tiempo_de_llegada1[i]; //ecuaciones para obtener tt
              waitingtime[i]=turnaroundtime[i]-rafaga1[i]; //ecuacion para obtener wt
              suma_turnaroundtime+=turnaroundtime[i]; // acumulando la suma de tt para cada sub i del vector
              suma_waitingtime+=waitingtime[i];}       // acumulando la suma de cada wt para cada sub i del array

            printf("\n\t\t\t||| TABLA DE FCFS |||\n\n"); //titulo de la tabla fcfs
            printf("Tiempos de llegada | Rafaga/Burst | Turnaround-Time(tt) |  Waiting-Time(wt)\n\n");
            for(int i=0; i<numero_de_procesos; i++){
                printf("        %d    \t           %d\t            %d\t              %d\n",tiempo_de_llegada1[i],rafaga1[i],turnaroundtime[i],waitingtime[i]); // imprime los valores correspondientes
            printf("---------------------------------------------------------------------------\n");} // linea para crear tabla

            float promedio_TT,promedio_WT;
            promedio_TT = suma_turnaroundtime/numero_de_procesos; // aqui se calcula el promedio de tt con suma y division
            promedio_WT = suma_waitingtime/numero_de_procesos;  // aqui se calcula el promedio de wt con suma y division

            printf("\nPromedio de Turnaround-Time: %.2f\nPromedio de Waiting-Time: %.2f\n\n",promedio_TT,promedio_WT); //aqui se imprime el promedio de Turnaround time y waiting time

         }

        if(opcion!=1 && opcion!=2 && opcion!=3 && opcion!=4)  // descarte de opciones no validas
        {
            printf("\nLa Opcion Ingresada No Es Valida.\n\n");
        }

    }
while(opcion!=4);  // opcion para salir y terminar el programa la 4
    printf("\nFin Del Programa!\n");
    return 0;
}
// funcion para dejar en orden de menor a mayor tiempo de llegada y mostrar se asi en la tabla grafica.
void ascendente(int *tiempo_llegada, int *rafaga,int numero_proceso){
	  int a,b,c,d;
	  for(int i=0; i<numero_proceso; i++){ //for que iteral hasta la cantidas de procesos
    a=i-1; // se resetean las variables a y b
		b=i-1;
		c=tiempo_llegada[i];
		d=rafaga[i];
		while(b>=0 && c<tiempo_llegada[b]){ //While que se detiene cuando b sea 0 en la resta y comprueba si c que toma el valor de tiempo de llegada original es menor que el timepo de llegada b
		tiempo_llegada[b+1]=tiempo_llegada[b]; //copia el valor del mayor mas arriba
		rafaga[a+1]=rafaga[a]; //copia el valor del mayor mas arriba
    a = b-1;  // a y b adoptan valores que se cambian con el codigo fuera del while
		b = b-1;}
		tiempo_llegada[b+1]=c; // cuando termina el while o no entra se hace otro cambio del guardado
		rafaga[a+1]=d;
	}
}
