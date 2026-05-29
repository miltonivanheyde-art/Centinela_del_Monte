---
title: "Contexto del Proyecto - Centinela del Monte"
author: "Gemini PRO"
ia_source: "Gemini Code Assist"
version: "v0.1"
date: "2026-05-20"
status: "validated"
hash: "sha256:5bc4075dc0ecc01afa7465172aeda3fd1b635a71dd2a08975bf6afa4ad5cf83d"


---



## Visión General
Centinela del Monte es un sistema de monitoreo ambiental autónomo diseñado para operar en condiciones extremas. Utiliza hardware de bajo consumo (ESP32-S3) y comunicación de largo alcance (LoRa) para garantizar la integridad de los datos en zonas sin infraestructura.

## Propósito del Repositorio
Este repositorio actúa como la "Memoria Maestra" del sistema, donde cada decisión técnica (ADR), esquema de hardware y código fuente está vinculado por una cadena de confianza basada en hashes de integridad.

## Reglas de interpretación para IA
1. **Determinismo:** Las IAs deben operar bajo un modelo determinístico.
2. **Gobernanza cognitiva:** Respetar DOCTRINA.md y flujo de trabajo.
3. **Continuidad semántica:** Mantener coherencia entre `/docs` y `/main`.
4. **No duplicación:** Nunca generar metadata duplicada.

## Arquitectura del repositorio
- `/docs`: Doctrina y ADRs
- `/main`: Implementación de firmware operativo
- `/hardware`: Diseño físico
- `/scripts`: Automatización
- `/auditorias`: Evidencia

## Pilares Doctrinarios
1. Integridad sobre Velocidad
2. Resiliencia de Hardware
3. Trazabilidad IA-Humano

