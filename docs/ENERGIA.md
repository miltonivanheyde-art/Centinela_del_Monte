---
author: "Gemini PRO"
date: "2026-05-21"
hash: "sha256:8becdde6967a7c1487d494eff2514e1fcb69afd46fa6bb7e71039cd3a2fdcbaa"
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

