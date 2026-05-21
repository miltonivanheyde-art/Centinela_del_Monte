# WORKFLOW del Proyecto Centinela del Monte

Este workflow está basado en `docs/DOCTRINA.md` y describe el proceso operativo obligatorio de generación, revisión, validación y liberación.

## 1. Roles clave
- **Gemini PRO**: autoridad doctrinal y validadora de gobernanza.
- **ChatGPT**: generador técnico que produce artefactos y propuestas, pero no escribe directamente en `/releases`.
- **Copilot 365**: responsable de persistencia, backups y sincronización.
- **Orquestador humano / Copilot**: coordina el flujo, ejecuta auditorías y asegura el cumplimiento.

## 2. Flujo obligatorio

1. **Generar**
   - Crear artefactos y ADRs en `/staging`.
   - Incluir metadatos YAML obligatorios.
   - Aplicar formato y preparar el contenido para revisión.

2. **Staging**
   - Revisar la propuesta internamente.
   - Verificar que los metadatos incluyan hash y versión de IA.
   - Registrar evidencia en `/auditorias` si corresponde.

3. **Validar**
   - Validación humana mínima de un revisor.
   - Validación doctrinal por Gemini PRO para decisiones de alto impacto.
   - Para cambios en `/releases`, aplicar 2 aprobaciones humanas o 1 humana + validación doctrinal.

4. **Release**
   - Solo mover artefactos a `/releases` después de la validación.
   - Actualizar el registro de auditoría con el resultado final.
   - Asegurar que el estado metadata sea `release`.

## 3. Auditorías
- El flujo de auditorías es un proceso paralelo y obligatorio.
- Documentar cada auditoría en `/auditorias` con:
  - Fecha
  - Responsable
  - Alcance
  - Resultado
  - Referencia a ADRs y artefactos
- Realizar revisiones periódicas y registrar hallazgos.

## 4. Políticas de gobernanza
- Todos los cambios críticos requieren ADR.
- Los artefactos deben llevar metadata YAML estándar.
- No se realizan cambios directos en `/releases` sin pasar por el flujo.
- El backup y la sincronización son parte del proceso de resiliencia.

## 5. Buenas prácticas
- Mantener commits pequeños y atómicos.
- Documentar decisiones técnicas con ADRs.
- Usar `scripts/Update-DocumentMetadata.ps1` para generar hashes fiables.
- Mantener copias de seguridad periódicas con `scripts/Backup-CENTINELA.ps1`.
