# UdeATunes - Sistema de Streaming Musical

## Descripción

**UdeATunes** es un plataforma de servicio de streaming musical desarrollado en C++ utilizando programación orientada a objetos (POO), sin hacer uso de la STL (Standard Template Library). El sistema permite gestionar usuarios, artistas, álbumes, canciones y publicidad, ofreciendo funciones específicas según el tipo de usuario (estándar o premium). El programa se ejecuta en consola y gestiona los datos mediante archivos.

## Objetivos del Sistema

- Gestionar usuarios, artistas, álbumes, canciones y publicidad.
- Cargar los datos desde archivos.
- Implementar funciones específicas para cada tipo de usuario (estándar/premium).
- Reproducir canciones de forma aleatoria mostrando la ubicación de los archivos.
- Implementar un sistema de publicidad con prioridad para los usuarios estándar.
- Permitir a los usuarios premium crear y gestionar listas de favoritos y seguir listas de otros usuarios.
- Medir la eficiencia del programa, incluyendo el número de iteraciones ejecutadas y la memoria utilizada por las estructuras dinámicas.

## Funciones principales:

### 1. **Usuario**
   - **Funciones**:
     - Reproducir música.
     - Manejar lista de favoritos (solo premium).
     - Seguir listas de otros usuarios (solo premium).
   - **Diferencias entre tipos de usuario**:
     - **Premium**: Sin publicidad, formato de audio 320 kbps, acceso a listas personalizadas.
     - **Estándar**: Con publicidad, formato de audio 128 kbps.

### 2. **Artista**
   - **Relaciones**:
     - Un artista puede tener varios álbumes.

### 3. **Álbum**
   - **Relaciones**:
     - Un álbum contiene varias canciones.

### 4. **Canción**
   
### 5. **Publicidad**

### 6. **Lista de Favoritos (solo Premium)**
  - **Funciones**:
     - Reproducir canciones en orden o aleatoriamente.
     - Agregar y quitar canciones por ID.
     - Seguir y fusionar listas de otros usuarios.

## Funciones Clave a Implementar

1. **Gestión de usuarios**:
   - Registro, inicio de sesión y control de acceso según el tipo de usuario.
   - Acceso a funciones específicas basadas en el tipo de usuario.

2. **Reproducción de música**:
   - Reproducir canciones aleatorias o en orden.
   - Mostrar la ubicación de los archivos durante la reproducción.
   
3. **Publicidad**:
   - Los usuarios estándar verán anuncios con prioridades (C, B, AAA).
   - Los usuarios premium no tendrán anuncios.

4. **Manejo de listas de favoritos (solo para usuarios premium)**:
   - Los usuarios premium pueden crear listas personalizadas de hasta 10,000 canciones.
   - Pueden seguir listas de otros usuarios y fusionar listas.

## Requisitos

- **Lenguaje**: C++
- **Paradigma**: Programación Orientada a Objetos (POO)
- **Gestión de Memoria**: Uso eficiente de memoria dinámica.
- **Medición de eficiencia**: Evaluar el consumo de recursos (memoria y CPU).


### Archivos de entrada esperados:
- **usuarios.txt**: Información de los usuarios.
- **artistas.txt**: Información de los artistas y sus álbumes.
- **albumes.txt**: Información de los álbumes y sus canciones.
- **canciones.txt**: Información detallada sobre las canciones.
- **publicidad.txt**: Información sobre los anuncios disponibles.

## Eficiencia y Medición de Recursos

- Se deberá medir el número total de iteraciones ejecutadas.
- También se debe controlar el uso de memoria dinámica durante la ejecución.
- Se evaluará el uso eficiente de los recursos, tanto en términos de memoria como de tiempo de ejecución.

