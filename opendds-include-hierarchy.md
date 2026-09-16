# OpenDDS Include Hierarchy Rule

Reference: https://opendds.readthedocs.io/en/master/internal/dev_guidelines.html#includes

## Why it exists

Ordering headers from most-local to most-system-level exposes hidden
dependencies. If a header only compiles because something included
before it happened to define a symbol first, a strict order makes that
fragility visible instead of hiding it.

## The 12-step order

Each numbered group gets a blank line between it and the next group
that's actually used (skip groups with nothing in them, no blank line
for an empty group).

1. Precompiled header (Windows-only, MSVC requirement)
2. The header matching this `.cpp` file (`Foo.h` for `Foo.cpp`)
3. Headers from the local project (same directory)
4. Headers from external OpenDDS-based libraries
5. Headers from `dds/DCPS`
6. `dds/*C.h` headers (generated IDL code)
7. Headers from external TAO-based libraries
8. Headers from TAO itself
9. Headers from external ACE-based libraries
10. Headers from ACE itself
11. Headers from external non-ACE libraries
12. System and C++ standard library headers

## Quoting rule (runs alongside the order)

- **Quotes** (`"foo.h"`) — only when the header is relative to the
  current file's directory (i.e., it's a true local/sibling header).
- **Angle brackets** (`<foo.h>`) — everything else, even other OpenDDS
  headers, if they're not in the same folder. This signals "found via
  the include search path," not a relative path.

## Worked example — `UpdateManager.cpp` in `dds/InfoRepo/`

```cpp
#include "DCPSInfo_pch.h"

#include "UpdateManager.h"
#include "Updater.h"
#include "DCPSInfo_i.h"

#include <dds/DCPS/debug.h>

#include <tao/CDR.h>

#include <vector>
```

- `UpdateManager.h`, `Updater.h`, `DCPSInfo_i.h` → quoted (same dir as
  the `.cpp` file → group 3)
- `dds/DCPS/debug.h` → angle brackets, not local to `InfoRepo` → group 5
- `tao/CDR.h` → angle brackets, TAO header → group 8
- `debug.h` sorts above `CDR.h` because group 5 comes before group 8
- `<vector>` → system header → group 12, always last

## Quick gut-check when reviewing an include block

1. Is this header in the same directory as the file I'm editing?
   → quotes. Otherwise → angle brackets.
2. Which of the 12 groups does it belong to?
3. Sort groups in order, blank line between each non-empty group used.
