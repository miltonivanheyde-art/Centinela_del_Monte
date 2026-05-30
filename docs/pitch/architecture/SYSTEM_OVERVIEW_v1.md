# SYSTEM_OVERVIEW_v1

## 1. Identidad del sistema
Centinela del Monte es una infraestructura territorial resiliente orientada a sostener señales operativas en contextos rurales de baja conectividad.

## 2. Función operativa
Mantener continuidad de observación y estado en campo para habilitar decisión territorial con menor incertidumbre.

## 3. Componentes / flujo
- Nodo de campo: captura y persistencia local de señal operativa.
- Gateway rural: punto de agregación y enlace.
- Capa de supervisión operativa: lectura de estado y continuidad del sistema.

Flujo base:
1. Captura de condición en nodo territorial.
2. Persistencia y transmisión de estado operativo.
3. Agregación por gateway.
4. Disponibilización para supervisión y decisión de campo.

Diagrama sintético:
```mermaid
flowchart LR
    T["Territorio rural"] --> N["Nodo de campo"]
    N --> G["Gateway rural"]
    G --> S["Supervisión operativa"]
    S --> D["Decisión territorial"]
```

## 4. Relación doctrinal
Ver definición canónica en secciones 1 y 2 de este documento.

## 5. Relevancia para inversor
Proporciona comprensión operacional del sistema para interpretar riesgo de despliegue y factibilidad de validación territorial.
