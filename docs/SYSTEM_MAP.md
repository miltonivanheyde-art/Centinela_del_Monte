---
author: "Gemini PRO"
date: "2026-05-20"
hash: "sha256:6d64284402a569c645c0b2ed07572b5d31331ff2455e172b30df18c245aa37fc"
ia_source: "Gemini Code Assist"
model_version: "1.5-Pro"
status: "validated"
title: "Mapa de Arquitectura del Sistema Centinela del Monte"
version: "v0.1"










































---











































## Visión General de Capas y Flujos

```mermaid
graph TD
    subgraph Gobernanza y Doctrina (Capa Cognitiva Canónica)
        DOC_D[docs/DOCTRINA.md] --> DOC_PC[docs/PROJECT_CONTEXT.md]
        DOC_D --> DOC_EA[docs/ESTADO_ACTUAL.md]
        DOC_D --> DOC_SM[docs/SYSTEM_MAP.md]
        DOC_D --> DOC_RM[docs/ROADMAP.md]
        DOC_D --> DOC_RL[docs/REGLAS_IA.md]
        DOC_D --> DOC_MR[docs/MANIFIESTO_DE_RELACIONES.md]
        DOC_D --> ADRS[docs/ADRs/]
        ADRS --> DOC_DL[docs/DECISION_LOG.md]
    end

    subgraph Especificaciones Canónicas (Capa Cognitiva Canónica)
        SPEC_E[docs/ESTADOS_DEL_NODO_v0.1.md]
        SPEC_H[docs/HEARTBEAT_v0.1.md]
        SPEC_P[docs/POWER_STRATEGY_v0.1.md]
    end

    subgraph Derivación Técnica (Capa de Ingeniería)
        SPEC_E --> F_DOC_E[firmware/docs/ESTADOS_DEL_NODO_IMPL_v0.1.md]
        SPEC_H --> F_DOC_H[firmware/docs/HEARTBEAT_IMPL_v0.1.md]
        SPEC_P --> F_DOC_P[firmware/docs/POWER_STRATEGY_IMPL_v0.1.md]
    end

    subgraph Implementación de Firmware (Capa de Ingeniería)
        F_DOC_E --> F_SRC_FSM[firmware/src/node_fsm.c]
        F_DOC_H --> F_SRC_HB[firmware/src/heartbeat.c]
        F_DOC_P --> F_SRC_PM[firmware/src/power_manager.c]
        F_SRC_FSM & F_SRC_HB & F_SRC_PM --> F_SRC_MAIN[firmware/src/main.c]
        F_SRC_MAIN --> F_INC[firmware/include/]
    end

    subgraph Hardware (Capa de Ingeniería)
        HW_PCB[hardware/pcb/]
        HW_CASE[hardware/case/]
        HW_BOM[hardware/bom/]
    end

    subgraph Backend (Capa de Ingeniería)
        BE[backend/]
    end

    subgraph Tests
        TEST_FSM[tests/test_fsm.md]
        TEST_POWER[tests/test_power.md]
        TEST_THERMAL[tests/test_thermal.md]
        F_SRC_MAIN --> TEST_FSM & TEST_POWER & TEST_THERMAL
    end

    subgraph Operaciones y Trazabilidad
        SCRIPTS[scripts/]
        AUDIT[auditorias/]
        STAGING[staging/]
        RELEASE[release/]
        F_SRC_MAIN --> RELEASE
        TEST_FSM --> AUDIT
        SCRIPTS --> AUDIT
    end

    DOC_D --> F_DOC_E
    ADRS --> F_DOC_H
    SPEC_P --> F_DOC_P
    F_SRC_MAIN --> RELEASE
    RELEASE --> AUDIT
    STAGING --> RELEASE
    SCRIPTS --> STAGING
    SCRIPTS --> AUDIT
```

## Subsistemas
1.  **Gobernanza y Doctrina**: Define el "por qué" y las reglas del proyecto.
2.  **Especificaciones Canónicas**: Documentos maestros de requisitos.
3.  **Derivación Técnica**: Traducción de requisitos a detalles de implementación.
4.  **Firmware**: Código embebido para el nodo Centinela.
5.  **Hardware**: Diseño físico y componentes del nodo.
6.  **Backend**: Infraestructura para la recolección y gestión de datos.
7.  **Tests**: Verificación de la conformidad de la implementación.
8.  **Operaciones y Trazabilidad**: Automatización, auditoría y gestión del ciclo de vida del artefacto.









































