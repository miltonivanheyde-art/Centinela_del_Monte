---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:9c3085cb2dfec08690a4a3970fb612d5363869981273d8b197f821f321b8f9bf"
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
