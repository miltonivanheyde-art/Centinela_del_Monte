---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:662fb38d6dc4ab2945eefef24531c29d9607f125e9ac7e679b2d2ff0ead4e1f9"
ia_source: "Gemini Code Assist"
reviewed_by: "Milton Heyde"
status: "validated"
title: "Especificaciones Detalladas de Energía"
version: "v0.1"










































---











































## Especificaciones Detalladas de Energía

## 1. Batería (Ref: ADR-ENERGIA)

- **Tipo:** LiFePO4 (Litio-Ferrofosfato).
- **Capacidad Mínima:** 3000 mAh.
- **Voltaje Nominal:** 3.2V - 3.7V (según celda).
- **Protección:** Circuito de protección de sobrecarga, sobredescarga y cortocircuito.

## 2. Regulación de Voltaje

- **Componente:** Regulador LDO (Low-Dropout) de ultra bajo consumo.
- **Corriente de Quiescencia (Iq):** < 1 µA.
- **Voltaje de Salida:** 3.3V o 5V (según MCU).

## 3. Carga Solar

- **Controlador:** MPPT (Maximum Power Point Tracking) integrado.
- **Panel Solar:** 5V / 10W (mínimo).
- **Eficiencia:** > 90% de eficiencia de conversión.










































