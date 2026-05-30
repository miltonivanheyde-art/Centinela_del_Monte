# EXECUTIVE_SUMMARY_v1

## Problema
Amplias zonas rurales operan con baja conectividad, infraestructura limitada y alta exposición ambiental. En ese contexto, la operación territorial depende de información tardía, fragmentada o inexistente. El resultado no es solo falta de datos: es aumento de incertidumbre para tomar decisiones de campo, priorizar recursos y sostener continuidad operativa.

## Solución
Centinela del Monte propone una infraestructura territorial resiliente para captura y persistencia de señales operativas en entornos hostiles. El enfoque no es una app de consumo, sino una capa de instrumentación distribuida que prioriza robustez, trazabilidad y funcionamiento bajo restricciones reales de energía y conectividad.

## Arquitectura
La base técnica actual está implementada en firmware embebido sobre ESP32, con gestión explícita de estados operativos, lógica de energía y ciclo de heartbeat. La arquitectura documental y de gobernanza separa:
- core técnico operativo (`main/` y documentación doctrinal),
- capa investor-ready (`docs/pitch/`),
permitiendo evolucionar narrativa y despliegue sin introducir riesgo en el núcleo de ejecución.

## Viabilidad técnica
El baseline técnico se encuentra compilando en entorno ESP-IDF validado, con estructura de firmware estable y criterios de determinismo aplicados. La lógica central de operación (FSM, energía, heartbeat y deep sleep) permanece congelada en esta fase para reducir riesgo de regresión mientras se prepara material de inversión y plan de despliegue.

## Roadmap
Fase actual: **Investor Ready Baseline v1**.

Secuencia prevista:
1. Consolidar narrativa ejecutiva, arquitectura visual y registro de riesgos.
2. Preparar escenarios de demostración controlada y guión operativo.
3. Definir pilotos territoriales acotados con supuestos explícitos y criterios de validación.
4. Ejecutar pruebas de campo con trazabilidad técnica y cierre de aprendizaje.

## Modelo operativo
El modelo operativo previsto se apoya en nodos de campo, gateway y rutina de supervisión técnica con foco en continuidad. Centinela se plantea como infraestructura de soporte para actores territoriales (operación rural, mantenimiento, monitoreo ambiental), no como sustituto de procesos locales. La propuesta de valor inicial es reducir incertidumbre operativa mediante señales confiables y oportunas en condiciones adversas.

## Riesgos
- Riesgo de despliegue físico: disponibilidad y mantenimiento de hardware en territorio.
- Riesgo de conectividad: variabilidad de enlace en zonas de baja cobertura.
- Riesgo de integración operativa: adopción gradual por equipos de campo.
- Riesgo de escalamiento: necesidad de validar costos y procesos antes de expansión.

La mitigación en esta fase se centra en gobernanza documental, trazabilidad técnica y pilotos acotados.

## Solicitud de Inversión
Se busca habilitar una etapa pre-seed enfocada en:
- financiar validación en campo de la infraestructura base,
- completar activos de demostración investor-ready,
- ejecutar pilotos territoriales con métricas verificables de continuidad operativa.

El objetivo de inversión no es acelerar features, sino desriesgar despliegue real y confirmar viabilidad operativa en territorio.
