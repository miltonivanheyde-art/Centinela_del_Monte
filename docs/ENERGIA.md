---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:23fe12c70cc557db0356c93ad71862a92693d945354cbfcbc676a5eca1f55935"
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


