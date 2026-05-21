---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:c7d8e9f0a1b2c3d4e5f67890abcdef1234567890abcdef1234567890a1b2c3"
reviewed_by: "Milton Heyde"
status: "validated"
title: "ADR-ENERGIA: Gestión de Potencia"
version: "v0.1"
---

# ADR-ENERGIA: Estrategia de Alimentación

## Contexto
El nodo debe operar en entornos remotos con autonomía mínima de 6 meses.

## Decisión
Se utilizarán baterías LiFePO4 por su estabilidad térmica. Se implementará un regulador LDO de ultra bajo consumo (IQ < 1uA).

## Consecuencias
Mayor vida útil de la celda, pero requiere un sistema de carga solar eficiente.