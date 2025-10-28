# Link del video YouTube: https://www.youtube.com/watch?v=9MlHxC9tEaw 

# UdeATunes - Sistema de Streaming Institucional 

# Integrantes de equipo:
    - Juan Esteban Velez Hincapie
    - Ricardo Yesith Cañas Jorge

## Descripción

**UdeATunes** es una plataforma de servicio de streaming musical desarrollada en C++ utilizando programación orientada a objetos (POO), sin hacer uso de la STL (Standard Template Library). El "plataforma en terminal" el funcionamiento de un servicio de streaming real, permitiendo gestionar usuarios, artistas, álbumes, canciones y publicidad, con funcionalidades específicas según el tipo de membresía del usuario.

## Características Principales

### Tipos de Usuario

#### Usuario Premium
Los usuarios premium disfrutan de beneficios exclusivos:

-  **Sin publicidad**: Reproducción ininterrumpida de música sin anuncios
-  **Alta calidad de audio**: Todas las canciones en formato 320 kbps
-  **Lista de favoritos personalizada**: Hasta 10,000 canciones
-  **Seguir listas de otros usuarios**: Pueden seguir y fusionar listas de favoritos de otros usuarios premium
-  **Control avanzado de reproducción**:
  - Pasar a la siguiente canción
  - Volver a canciones anteriores (hasta 4 canciones hacia atrás en reproducción aleatoria)
  - Volver hasta 6 canciones atrás en listas de favoritos
  - Repetir canción actual indefinidamente
-  **Gestión completa de favoritos**:
  - Agregar/eliminar canciones por ID
  - Reproducir en orden original o aleatorio
  - Sin duplicados en la lista

####  Usuario Estándar 
Los usuarios estándar tienen acceso básico:

-  **Con publicidad**: Visualizan un anuncio cada 2 canciones reproducidas
-  **Calidad de audio estándar**: Reproducción a 128 kbps
-  **Reproducción aleatoria**: Acceso a todas las canciones de la plataforma
-  **Control básico**: Solo pueden avanzar a la siguiente canción
-  **Restricciones**:
  - No pueden retroceder a canciones anteriores
  - No tienen acceso a listas de favoritos personalizadas
  - No pueden seguir listas de otros usuarios

###  Sistema de Publicidad (solo usuarios estándar)

El sistema implementa publicidad inteligente con prioridades:
- **Categoría C**: Prioridad simple (1x)
- **Categoría B**: Prioridad doble (2x)
- **Categoría AAA**: Prioridad triple (3x)
- Los anuncios nunca se repiten consecutivamente
- Máximo 500 caracteres por mensaje
- Base de datos de hasta 50 mensajes publicitarios

## Funcionalidades del Sistema

### 1. Ingreso a la Plataforma (Login)
- Inicio de sesión con credenciales personales
- Verificación de tipo de usuario
- Acceso a menú personalizado según membresía

### 2. Reproducción Aleatoria
- Disponible para **todos los usuarios**
- Selección aleatoria de canciones de toda la plataforma
- Muestra ruta del archivo de audio y portada del álbum
- **Premium**: Control completo (play, pause, siguiente, anterior, repetir)
- **Estándar**: Control básico (play, pause, siguiente) + publicidad

### 3. Mi Lista de Favoritos (Solo Premium)

#### a. Editar Lista de Favoritos
- Buscar canciones por código ID (9 dígitos)
- Agregar canciones a favoritos
- Eliminar canciones de favoritos
- Sin duplicados permitidos

#### b. Seguir Otra Lista de Favoritos
- Buscar usuario por nickname
- Seguir lista de favoritos de otro usuario premium
- Fusión automática con lista existente

#### c. Ejecutar Mi Lista de Favoritos
- Reproducción en orden original
- Reproducción aleatoria
- Retroceder hasta 6 canciones
- Todas las opciones de control premium

### 4. Medición del Consumo de Recursos
Al finalizar cada funcionalidad, el sistema muestra:
- **Iteraciones totales**: Número de iteraciones ejecutadas
- **Memoria consumida**: Total de memoria utilizada por todas las estructuras

## Estructura de Datos

###  Artista
- Código identificador (5 dígitos)
- Edad
- País de origen
- Cantidad de seguidores
- Posición en tendencias globales
- Catálogo de álbumes

###  Álbum
- Código identificador (2 dígitos)
- Nombre
- Fecha de lanzamiento
- Duración total
- Hasta 4 géneros musicales 
- Portada (formato PNG)
- Puntuación (1-10)
- Colección de canciones

### Canción
- Identificador único de 9 dígitos:
  - Primeros 5: ID del artista
  - Siguientes 2: ID del álbum
  - Últimos 2: ID de la canción
- Nombre
- Duración
- Ubicación de archivos (128 kbps y 320 kbps)
- Créditos (Productores, Músicos, Compositores)
- Contador de reproducciones

### Usuario
- Nickname único
- Tipo de membresía (Estándar/Premium)
- Ciudad y país
- Fecha de inscripción
- Lista de favoritos (solo premium)

## Reglas para el Desarollo

- **Lenguaje**: C++ (sin STL)
- **Paradigma**: Programación Orientada a Objetos (POO)
- **Gestión de Memoria**: Memoria dinámica con estructuras propias
- **Interacción**: Consola/Terminal

## Archivos de Datos

El sistema carga información desde archivos CSV:
- `Usuarios.csv` - Información de usuarios y membresías
- `Artistas.csv` - Datos de artistas
- `Albumes.csv` - Información de álbumes
- `Canciones.csv` - Catálogo completo de canciones
- `Publicidad.csv` - Mensajes publicitarios con prioridades

## Uso del Sistema

1. **Iniciar sesión** con credenciales de usuario
2. **Seleccionar funcionalidad** del menú principal
3. **Reproducir música** según tu tipo de membresía
4. **Gestionar favoritos** (solo premium)
5. **Visualizar métricas** de rendimiento

## Objetivos del Proyecto

-  Modelar un sistema real de streaming musical
-  Aplicar conceptos de POO en C++
-  Implementar gestión eficiente de memoria
-  Desarrollar estructuras de datos propias
-  Optimizar rendimiento y recursos

