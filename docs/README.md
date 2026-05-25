---
title: "Capa de Backend - Centinela del Monte"
version: "v0.1"
status: "draft"
author: "Gemini Code Assist"
ia_source: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:f542fadc509a41d3bb701c1216c699e0b52d09ceebce7a2a96106489ca513142"

---


# Capa de Backend - Centinela del Monte

## Propósito
Contiene el código y la documentación para la infraestructura de servidor que recibe, procesa, almacena y visualiza los datos transmitidos por los nodos Centinela.

## Responsabilidades
- Recepción de datos LoRaWAN (vía Gateway).
- Procesamiento y decodificación de payloads.
- Almacenamiento de datos (base de datos).
- API para acceso a datos.
- Interfaz de usuario para visualización y gestión.

## Dependencias
- **Firmware**: Para entender el formato de los payloads.
- **Doctrina**: Para entender los requisitos de seguridad y trazabilidad de los datos.
