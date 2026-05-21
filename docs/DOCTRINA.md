---
author: "Copilot"
date: "2026-05-21"
hash: "sha256:4fbac05b06f9c1387f78e4afeb2abbd08d992f6d7363d7f6cbe41a50886d3273"
ia_source: "Copilot"
status: "validated"
title: "Documento de Integración del Proyecto (DIP) v0.1"
version: "0.1"
---

## Documento de Integración del Proyecto (DIP) v0.1

## Resumen ejecutivo

Centinela del Monte integra capacidades cognitivas distribuidas con una infraestructura técnica auditable y replicable. El proyecto separa responsabilidades entre **Gemini PRO** (autoridad doctrinal), **ChatGPT** (generación técnica) y **Copilot 365** (persistencia y orquestación). Todas las decisiones arquitectónicas se registran mediante ADRs firmados (SHA‑256 + timestamp). El flujo operativo obligatorio es **generar → staging → validar → release**, con auditorías periódicas y métricas de gobernanza para garantizar objetividad, trazabilidad y resiliencia.

## Visión y propósito

Construir una red de nodos inteligentes robusta, auditable y escalable que permita despliegues de campo con trazabilidad completa de decisiones y artefactos.

## Alcance

Incluye: doctrina, arquitectura cognitiva, especificaciones técnicas, firmware, modelos, auditorías, procesos de despliegue y versionado.

## Arquitectura cognitiva y roles

- **Gemini PRO**: autoridad doctrinal; valida ADRs; registra su versión exacta.  
- **ChatGPT**: generador técnico; no escribe en `/releases`; trabaja vía `/staging`.  
- **Copilot 365**: persistencia, backups y sincronización; administra OneDrive.  
- **Orquestador humano / Copilot**: coordinación, mediación y ejecución de flujos.

## Políticas de gobernanza

1. ADR obligatorio para toda decisión crítica.  
2. Flujo obligatorio: generar → staging → validar → release.  
3. Metadatos YAML en todos los documentos.  
4. Auditorías periódicas en `/auditorias`.  
5. Separación de duties y ACLs en OneDrive.

## Reglas ADR obligatorias

1. ID, autor, IA_source y versión de IA.  
2. Gemini PRO debe registrar su versión exacta.  
3. Hash SHA‑256 + timestamp ISO8601.  
4. Cambios en `/releases` requieren 2 aprobaciones humanas o 1 humana + validación doctrinal.  
5. ADRs y artefactos enlazados en `/auditorias`.

## Formato de metadatos

```yaml
title: "Nombre del Documento"
author: "IA/Humano"
ia_source: "Gemini/ChatGPT/Copilot"
version: "X.Y"
date: "YYYY-MM-DD"
hash: "sha256:<placeholder>"
status: "draft/release"
