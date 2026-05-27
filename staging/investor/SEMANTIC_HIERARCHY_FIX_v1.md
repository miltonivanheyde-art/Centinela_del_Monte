# SEMANTIC_HIERARCHY_FIX_v1

## Objetivo
Eliminar solapamiento conceptual entre capas de narrativa sin alterar estructura documental existente.

## Capas consideradas
- `INVESTOR_DECK_v1` (capa ejecutiva)
- `SYSTEM_OVERVIEW_v1` (capa operacional)
- `VISUAL_ARCHITECTURE_v1` (capa de representación visual)

## Regla general de jerarquía
- INVESTOR_DECK: define problema, tesis, priorización estratégica y solicitud de inversión.
- SYSTEM_OVERVIEW: define mecánica de operación del sistema y flujo funcional.
- VISUAL_ARCHITECTURE: define cómo se representa visualmente el sistema y sus activos.

Ninguna capa debe replicar en detalle el rol de otra.

## Concept -> Allowed Layer

- **Tesis del problema (incertidumbre rural)** -> `INVESTOR_DECK_v1` (canónico); `SYSTEM_OVERVIEW_v1` (solo referencia breve); `VISUAL_ARCHITECTURE_v1` (prohibido).
- **Infraestructura territorial resiliente (marco estratégico)** -> `INVESTOR_DECK_v1` (canónico); `SYSTEM_OVERVIEW_v1` (contexto técnico breve); `VISUAL_ARCHITECTURE_v1` (solo como criterio visual, no como argumentación).
- **Persistencia operativa (definición operacional)** -> `SYSTEM_OVERVIEW_v1` (canónico); `INVESTOR_DECK_v1` (uso resumido); `VISUAL_ARCHITECTURE_v1` (prohibido como definición técnica).
- **Reducción de incertidumbre rural (resultado estratégico)** -> `INVESTOR_DECK_v1` (canónico); `SYSTEM_OVERVIEW_v1` (solo consecuencia operacional); `VISUAL_ARCHITECTURE_v1` (prohibido).
- **Flujo territorial nodo -> gateway -> supervisión** -> `SYSTEM_OVERVIEW_v1` (canónico); `INVESTOR_DECK_v1` (mención sintética); `VISUAL_ARCHITECTURE_v1` (solo referencia a visual, sin explicar mecánica).
- **Componentes del sistema (nodo, gateway, supervisión)** -> `SYSTEM_OVERVIEW_v1` (canónico); `INVESTOR_DECK_v1` (resumen); `VISUAL_ARCHITECTURE_v1` (solo implicación para assets).
- **Conectividad limitada (supuesto operativo)** -> `SYSTEM_OVERVIEW_v1` (canónico); `INVESTOR_DECK_v1` (contexto de riesgo); `VISUAL_ARCHITECTURE_v1` (solo criterio estético/contextual).
- **Riesgo operativo y desriesgo por etapas** -> `INVESTOR_DECK_v1` (canónico); `SYSTEM_OVERVIEW_v1` (prohibido salvo referencia); `VISUAL_ARCHITECTURE_v1` (prohibido).
- **Representación visual de nodos/gateway/territorio** -> `VISUAL_ARCHITECTURE_v1` (canónico); `INVESTOR_DECK_v1` (solo puntero a visual sugerido); `SYSTEM_OVERVIEW_v1` (prohibido como guía estética).
- **Tipos de activos visuales (renders, mapas, diagramas, mockups)** -> `VISUAL_ARCHITECTURE_v1` (canónico); `INVESTOR_DECK_v1` (solo selección por slide); `SYSTEM_OVERVIEW_v1` (prohibido).
- **Composición narrativa de escenas** -> `VISUAL_ARCHITECTURE_v1` (canónico); `INVESTOR_DECK_v1` (prohibido); `SYSTEM_OVERVIEW_v1` (prohibido).
- **Solicitud de inversión (Ask) y uso de capital** -> `INVESTOR_DECK_v1` (canónico); `SYSTEM_OVERVIEW_v1` (prohibido); `VISUAL_ARCHITECTURE_v1` (prohibido).

## Conceptos prohibidos por capa

### Prohibidos en `INVESTOR_DECK_v1`
- Explicación técnica extensa de flujo y arquitectura interna.
- Guía de estilo visual detallada.

### Prohibidos en `SYSTEM_OVERVIEW_v1`
- Argumentación de fundraising.
- Detalle de composición estética o narrativa visual.

### Prohibidos en `VISUAL_ARCHITECTURE_v1`
- Desarrollo técnico del sistema como especificación operacional.
- Tesis de inversión y narrativa de riesgo financiero.

## Regla de uso cruzado
Cuando un concepto de otra capa deba aparecer:
- usar solo una frase de contexto,
- no redefinir el concepto,
- referenciar implícitamente la capa canónica.

## Resultado esperado
Con esta jerarquía, cada documento conserva su rol:
- deck para decisión inversora,
- overview para comprensión operacional,
- visual architecture para coherencia de representación.
