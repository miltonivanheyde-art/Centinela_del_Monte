---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:b1c2d3e4f5a67890abcdef1234567890abcdef1234567890abcdef123456789"
reviewed_by: "Milton Heyde"
status: "validated"
title: "ADR-HEARTBEAT: Protocolo de Sincronización"
version: "v0.1"
---

# ADR-HEARTBEAT: Intervalo de Comunicación

## Contexto
Es necesario equilibrar la visibilidad del estado del nodo con el ahorro de energía y ancho de banda.

## Decisión
Establecer un intervalo de 2 horas (120 min) para el mensaje de estado estándar.

## Consecuencias
Optimización del ciclo de vida de la batería; latencia máxima de 2 horas para detección de fallos no críticos.