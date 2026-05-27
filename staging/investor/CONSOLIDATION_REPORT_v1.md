# CONSOLIDATION_REPORT_v1

## Alcance
Analisis de redundancias y posicionamiento canonico entre:
- `docs/pitch/investor_deck/INVESTOR_DECK_v1.md`
- `docs/pitch/architecture/SYSTEM_OVERVIEW_v1.md`
- `docs/pitch/architecture/VISUAL_ARCHITECTURE_v1.md`

No se modificaron archivos existentes.

## Que documentos sobran
No sobra ningun documento completo en este estado.

Diagnostico:
- Los tres cumplen funciones distintas (deck ejecutivo, arquitectura operacional, arquitectura visual).
- El solapamiento actual es de contenido narrativo, no de proposito documental.

## Que partes se solapan
1. Tesis central repetida en los tres:
- "infraestructura territorial resiliente"
- "persistencia operativa"
- "reduccion de incertidumbre rural"

2. Bloque de arquitectura/flujo repetido:
- En `INVESTOR_DECK_v1` (slides 4 y 5)
- En `SYSTEM_OVERVIEW_v1` (componentes + flujo)
- En `VISUAL_ARCHITECTURE_v1` (flujo visual de activos)

3. Enlace a los mismos activos visuales:
- Deck sugiere visuales de arquitectura y red.
- `VISUAL_ARCHITECTURE_v1` define esos mismos activos en detalle.

4. Riesgo de duplicacion editorial:
- El deck incluye suficiente detalle para competir con `SYSTEM_OVERVIEW_v1` si se sigue densificando sin limite.

## Que debe mantenerse como canonico
Canon propuesto por capa:

1. Canónico ejecutivo:
- `docs/pitch/investor_deck/INVESTOR_DECK_v1.md`
- Funcion: narrativa de presentacion para inversor (lectura rapida).

2. Canónico de arquitectura operacional:
- `docs/pitch/architecture/SYSTEM_OVERVIEW_v1.md`
- Funcion: explicar sistema completo (nodo, gateway, supervision, decision).

3. Canónico de arquitectura visual:
- `docs/pitch/architecture/VISUAL_ARCHITECTURE_v1.md`
- Funcion: gobernar como se representa visualmente la arquitectura.

4. Referencia de red:
- `docs/pitch/architecture/NETWORK_FLOW_v1.md`
- Funcion: detalle de conectividad limitada y flujo territorial.

## Que debe eliminarse o archivarse
No se recomienda eliminar documentos completos en esta fase.

Se recomienda archivar o recortar en siguiente ciclo (sin ejecutar ahora):
- En `INVESTOR_DECK_v1`, mantener nivel de sintesis y evitar nueva expansion tecnica en slides 4-5.
- Evitar que `VISUAL_ARCHITECTURE_v1` replique texto operacional de `SYSTEM_OVERVIEW_v1`.
- Tratar los diagramas del deck como "punteros" a documentos canonicos, no como fuente primaria.

## Regla de consolidacion sugerida
Para evitar divergencia futura:
- Deck = "que y por que" (mensaje ejecutivo).
- System Overview = "como opera" (mecanica del sistema).
- Visual Architecture = "como se comunica" (sistema visual).

Si aparece contenido nuevo de arquitectura, se escribe primero en `SYSTEM_OVERVIEW_v1` y luego se referencia en deck.
