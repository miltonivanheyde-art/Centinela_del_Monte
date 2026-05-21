---
author: "Gemini PRO"
date: "2026-05-21"
ia_source: "Gemini Code Assist"
reviewed_by: "Milton Heyde"
status: "draft"
title: "Lógica de Estados Doctrinales"
version: "v0.1"
---

# Estados Doctrinales del Nodo

## Definición de Estados Oficiales
| Estado | Descripción |
| :--- | :--- |
| **PRESENTE** | El nodo opera normalmente y mantiene el heartbeat regular. |
| **ACTIVO** | Detección de movimiento o evento detectado; incremento de logs. |
| **RESERVA** | Modo de bajo consumo activo por batería baja o estrés térmico. |
| **ALERTA** | Anomalía crítica detectada (sabotaje o fallo de sensor). |
| **SIN_CONTACTO** | Fallo en la ventana de transmisión; estado de incomunicación. |
| **RECUPERADO** | Retorno a la operación tras un estado de ALERTA o SIN_CONTACTO. |

## Variables de Control
- **Temperatura:** Monitoreo del SoC y ambiente.
- **Batería:** Voltaje nominal y porcentaje de carga LiFePO4.
- **Movimiento:** Datos del acelerómetro/giroscopio.
- **Tiempo sin transmisión:** Contador desde el último Heartbeat exitoso.

## Reglas de Transición
1. **Temperatura > Umbral Crítico (60°C):** Transición inmediata a **RESERVA** para proteger integridad física.
2. **Batería < 15%:** Transición a **RESERVA**; desactivación de periféricos no esenciales.
3. **Timer Heartbeat > 125% del intervalo:** El sistema central marca el nodo como **SIN_CONTACTO**.
4. **Detección de Movimiento (en reposo):** Transición a **ACTIVO** y envío de trama de interrupción.

## Validación Doctrinal
Este esquema reemplaza cualquier nomenclatura anterior (colores) para alinearse con la semántica de la fase operativa.