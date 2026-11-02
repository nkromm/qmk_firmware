#pragma once

// default but used in macros
#undef TAPPING_TERM
#define TAPPING_TERM 210

// A home-row key acts as a modifier only when the next key is on the other hand.
#define CHORDAL_HOLD
// An opposite-hand chord counts as hold once the other key is released.
#define PERMISSIVE_HOLD
