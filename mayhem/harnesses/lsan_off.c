/*
 * Build-time LeakSanitizer off-switch, linked into every ASan-built wamr fuzz target and
 * standalone reproducer. ASan's memory-corruption checks and UBSan stay fully on; only leak
 * detection at exit is disabled. Leaks are not the bug class this fleet fuzzes for, and the wasm
 * loader's early-reject paths can leave partially-built module state that LSan would report at
 * exit, which would flood the queue. Runtime sanitizer options remain owned by Mayhem.
 */
int __lsan_is_turned_off(void) { return 1; }
