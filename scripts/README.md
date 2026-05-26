---
title: "Manual de Scripts de Automatización e Integridad"
author: "Gemini Code Assist"
ia_source: "Gemini Code Assist"
version: "v0.1"
date: "2026-05-21"
status: "validated"
hash: "sha256:965f494c7face19a5c4936e2a89d96d32990020276ea60730e657eafee942ca9"

---


# Scripts de Automatización — Centinela del Monte

Este directorio contiene las herramientas necesarias para garantizar la integridad estructural y técnica de la "Memoria Maestra". Estos scripts son fundamentales para el cumplimiento de los pilares de **Integridad sobre Velocidad** y **Trazabilidad**.

## 1. Update-DocumentMetadata.ps1

### Propósito
Este script actúa como el mecanismo de "sellado" de documentos. Calcula el hash SHA256 del cuerpo de los archivos Markdown (excluyendo el bloque de metadatos YAML) y actualiza automáticamente el campo `hash` en el encabezado.

### Uso
Debe ejecutarse siempre que se realice un cambio en el contenido de un documento `.md` antes de realizar un commit.

```powershell
.\scripts\Update-DocumentMetadata.ps1
```

### Funcionamiento
1. Escanea todos los archivos `.md` de forma recursiva.
2. Identifica el bloque YAML frontal.
3. Calcula el hash SHA256 del contenido posterior al bloque YAML.
4. Actualiza o inserta la clave `hash: "sha256:..."`.

## 2. Validate-Artifact.ps1

### Propósito
Es la herramienta de auditoría técnica. Verifica que el hash registrado en los metadatos de cada archivo coincida con su contenido real, detectando alteraciones no autorizadas o errores de sincronización.

### Uso
Se recomienda su ejecución antes de cada `push` o como parte de un pipeline de Integración Continua (CI).

```powershell
.\scripts\Validate-Artifact.ps1
```

### Resultados
- **Salida en Consola:** Muestra el estado `[PASS]`, `[FAIL]` o `[SKIP]` para cada archivo.
- **Reporte de Auditoría:** Genera un archivo detallado en `/auditorias/ARTIFACT-VALIDATION-YYYY-MM-DD-HHmm.md`.
- **Código de Salida:** Retorna `exit 1` si detecta discrepancias, permitiendo bloquear flujos de trabajo automatizados.

## Notas de Seguridad
Estos scripts utilizan codificación **UTF8** y normalización de finales de línea para garantizar que el cálculo del hash sea determinístico en diferentes entornos operativos.
