# C++ Class Template Glossary

Frequency-tiered reference for template vocabulary — prioritized by how often each term actually shows up in code and interviews, not textbook completeness.

## Tier 1 — Cold recall required (constant use)

| Term | Plain meaning |
|---|---|
| **template parameter** | The placeholder (`T`) you fill in later — type or value |
| **type parameter** | A template parameter that's a *type* (`typename T`) |
| **non-type template parameter** | A template parameter that's a *value*, not a type — e.g. a function pointer like `void(*Deleter)(T)` |
| **template argument** | The actual thing you plug in when you use the template (`UniqueHandle<FILE*, CloseFile>` — `FILE*` and `CloseFile` are the arguments) |
| **instantiation** | The compiler generating real code from the template once you use it with specific arguments — nothing exists until this happens |
| **typename vs class** | Functionally identical in `template<typename T>` vs `template<class T>` — pick one, `typename` is more common now |

Reference: [cppreference: templates](https://en.cppreference.com/w/cpp/language/templates)

## Tier 2 — Known within weeks, worth cold

| Term | Plain meaning |
|---|---|
| **specialization (full)** | A hand-written override of the template for one exact set of arguments — "when T is `bool`, do this instead" |
| **specialization (partial)** | Same idea but for a *pattern* of arguments, not one exact type — "when T is any pointer type" |
| **default template argument** | `template<typename T = int>` — lets you omit the argument at the call site |
| **member template** | A template function/class *inside* another class — doesn't have to match the outer class's template parameters |
| **template argument deduction** | The compiler figuring out `T` from context so you don't have to spell it out (`std::make_unique<int>(42)` deduces without help) |

Reference: [cppreference: partial specialization](https://en.cppreference.com/w/cpp/language/partial_specialization)

## Tier 3 — Recognize, not cold recall (unless heavy metaprogramming)

| Term | Plain meaning |
|---|---|
| **SFINAE** ("Substitution Failure Is Not An Error") | A trick where a bad template substitution silently removes that overload from consideration instead of erroring |
| **template template parameter** | A template parameter that is itself a template (`template<template<typename> class Container>`) |
| **CRTP** (Curiously Recurring Template Pattern) | A class inherits from a template instantiated with itself — used for compile-time (static) polymorphism instead of virtual functions |
| **type trait** | A compile-time query about a type, e.g. `std::is_pointer<T>` — lives in `<type_traits>` |
| **concept** (C++20 only) | A named, checkable constraint on a template parameter — replaces a lot of manual SFINAE |

References: [cppreference: SFINAE](https://en.cppreference.com/w/cpp/language/sfinae) · [cppreference: type traits](https://en.cppreference.com/w/cpp/header/type_traits)
