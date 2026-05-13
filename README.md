# PRUEBA_PRACTICA_POO
# 🚀 Aplicativo Interactivo de Lógica y Algoritmos (C++)

![Estado: Completado](https://img.shields.io/badge/Estado-Completado-success?style=for-the-badge)
![Lenguaje: C++](https://img.shields.io/badge/Lenguaje-C%2B%2B-blue?style=for-the-badge&logo=c%2B%2B)
![Curso: Algoritmos y Lógica](https://img.shields.io/badge/Asignatura-Algoritmos%20y%20Lógica-orange?style=for-the-badge)

Este proyecto es una solución integral desarrollada para la **Prueba Práctica Individual** de la asignatura Algoritmos y Lógica de Programación. El aplicativo demuestra el dominio de estructuras de control, manejo de arreglos unidimensionales, validación de datos y persistencia en archivos físicos utilizando **C++**.

---

## 🛠️ Funcionalidades Principales

El sistema está diseñado de forma modular para ofrecer una experiencia interactiva y robusta:

* **🔢 Módulo de Operaciones Matemáticas:** * Cálculo dinámico de Suma, Resta, Multiplicación y División.
    * **Seguridad:** Validación activa para evitar errores críticos como la división por cero.
* **📊 Registro y Procesamiento de Notas:** * Captura de 5 notas académicas mediante arreglos.
    * Cálculo automático de **Promedio**, identificación de la **Nota Mayor** y **Nota Menor**.
    * Contador de estados: **Aprobados** (≥ 7) y **Reprobados**.
* **💾 Persistencia de Datos:** * Generación automática del archivo `resultados.txt`.
    * Almacena historial con nombre del estudiante, fecha exacta (timestamp) y resultados del proceso.
* **🛡️ Validación de Entradas:** * Protección contra ingresos de caracteres no numéricos y rangos de notas inválidos (0-10).

---

## 📂 Estructura del Repositorio

Siguiendo las directrices institucionales, el proyecto se organiza de la siguiente manera:

```text
repositorio/
├── src/                # Código fuente principal (.cpp)
├── resultados/         # Archivo resultados.txt generado
├── capturas/           # Evidencia visual del funcionamiento
└── README.md           # Documentación del proyecto
