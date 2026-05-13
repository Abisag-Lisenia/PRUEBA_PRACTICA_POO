Algoritmo AplicativoInteractivo
    // 2. DECLARACION DE VARIABLES
    Definir opcion, aprobados, reprobados, i Como Entero
    Definir n1, n2, suma, promedio, mayor, menor Como Real
    Definir nombre Como Cadena
    
    // CORRECCION: Dimensionar el arreglo antes de usarlo
    Dimension notas[5] 
    
    Repetir
        // SUBPROCESO MENU
        Escribir ""
        Escribir "=== MENU PRINCIPAL ==="
        Escribir "1. Operaciones basicas"
        Escribir "2. Registro de notas"
        Escribir "3. Guardar resultados"
        Escribir "4. Salir"
        Escribir "Seleccione una opcion:"
        Leer opcion
        
        Segun opcion Hacer
            1:
                // SUBPROCESO OPERACIONES MATEMATICAS
                Escribir "Ingrese primer numero:"
                Leer n1
                Escribir "Ingrese segundo numero:"
                Leer n2
                Escribir "Suma: ", n1 + n2
                Escribir "Resta: ", n1 - n2
                Escribir "Multiplicacion: ", n1 * n2
                Si n2 <> 0 Entonces
                    Escribir "Division: ", n1 / n2
                Sino
                    Escribir "Error: Division para cero no permitida"
                FinSi
                
            2:
                // SUBPROCESO ARREGLOS Y PROCESAMIENTO
                Escribir "Ingrese nombre del estudiante:"
                Leer nombre
                suma <- 0
                aprobados <- 0
                reprobados <- 0
                
                Para i <- 1 Hasta 5 Hacer
                    Escribir "Ingrese nota ", i, " (0-10):"
                    Leer notas[i]
                    suma <- suma + notas[i] // Acumulador
                    
                    // Calcular mayor y menor
                    Si i = 1 Entonces
                        mayor <- notas[i]
                        menor <- notas[i]
                    Sino
                        Si notas[i] > mayor Entonces
                            mayor <- notas[i]
                        FinSi
                        Si notas[i] < menor Entonces
                            menor <- notas[i]
                        FinSi
                    FinSi
                    
                    // Contadores
                    Si notas[i] >= 7 Entonces
                        aprobados <- aprobados + 1
                    Sino
                        reprobados <- reprobados + 1
                    FinSi
                FinPara
                
                promedio <- suma / 5
                Escribir "--- RESULTADOS ---"
                Escribir "Promedio: ", promedio
                Escribir "Nota Mayor: ", mayor
                Escribir "Nota Menor: ", menor
                Escribir "Aprobados: ", aprobados
                Escribir "Reprobados: ", reprobados
                
            3:
                // SUBPROCESO PERSISTENCIA
                Si nombre = "" Entonces
                    Escribir "Error: Primero debe registrar notas (Opcion 2)"
                Sino
                    Escribir "Guardando en resultados.txt..."
                    Escribir "Estudiante: ", nombre
                    Escribir "Promedio: ", promedio
                    Escribir "Fecha: 13/05/2026"
                    Escribir "Lenguaje: PSeInt"
                    Escribir "Datos guardados con exito."
                FinSi
                
            4:
                Escribir "Saliendo del programa..."
            De Otro Modo:
                Escribir "Opcion no valida, intente de nuevo."
        FinSegun
    Hasta Que opcion = 4
FinAlgoritmo