#pragma once
#include <vector>
#include <string>

// Global hook for Sparse-Animator MAC event injection from PE-level multipliers.
// Set by the active memory controller at the start of each cycle();
// populated by MSwitch/MultiplierOS::cycle() during the same simulation step;
// flushed by the memory controller's flushTracer() after msnet->cycle() completes.
//
// Safe for single-threaded STONNE simulation.
struct SparseAnimatorHook {
    std::vector<std::string>* events = nullptr; // current-cycle events buffer (owned by mem controller)
    int base_row = 0;   // absolute tile base row in C matrix
    int base_col = 0;   // absolute tile base col in C matrix
    int n_cols   = 0;   // MSwitch only: row = ms_num / n_cols, col = ms_num % n_cols
};

inline SparseAnimatorHook g_sa_hook;
