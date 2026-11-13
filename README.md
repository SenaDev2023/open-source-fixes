# open-source-fixes

Field notes from active open-source C/C++ contribution. OpenDDS · LibreOffice (VCL, Calc, Writer, Gerrit).

## Contributions

| Project | Bug/Issue ID | Module | Status |
|---------|--------------|--------|--------|
| OpenDDS | [#5232](https://github.com/OpenDDS/OpenDDS/issues/5232) | UpdateManager | Partial fix merged ([PR #5275](https://github.com/OpenDDS/OpenDDS/pull/5275)); 14 sites remaining |
| LibreOffice | [tdf#98856](https://bugs.documentfoundation.org/show_bug.cgi?id=98856) | VCL | Fixed (26.8.0) · [Gerrit change](https://gerrit.libreoffice.org/c/core/+/201201) |

## In Flight

| Project | Work | Status |
|---------|------|--------|
| OpenDDS | #5232: 6 push-before-validate sites (`pushImage()` / `SeqGuard`) | In progress |
| OpenDDS | #5232: 8 stack-local argument sites | Queued (next PR) |
| OpenDDS | Map remaining `cdr >>` / `cdr <<` sites across core | Planning, awaiting maintainer input on priority |
| PX4-Autopilot | DDS/uORB track (extends OpenDDS work) | Ramping up |

## Reference Docs

- [opendds-include-hierarchy.md](./opendds-include-hierarchy.md): OpenDDS's include-ordering convention (most-local to most-system-level), per project dev guidelines
- [templatesGloss.md](./templatesGloss.md): C++ class template glossary
- [libreoffice_field_guide.pdf](./libreoffice_field_guide.pdf): onboarding doc for C++ devs new to open-source contribution, built from 6 months of active patches
