// XFAIL: *

// We check that the Finalizer is run using FileCheck, and that the expected
// files are generated by deleting them (leaving things tidy)
// RUN: %cmc -emit-llvm -march=skl -Qxcm_asm_output=asm_output -- %s 2>&1 \
// RUN:     | FileCheck %s

#include <cm/cm.h>

_GENX_MAIN_
void test() {
}

#ifdef CM_GENX
#warning CM_GENX defined
#endif

#ifdef CM_GEN7_5
#warning CM_GEN7_5 defined
#endif

#ifdef CM_GEN8
#warning CM_GEN8 defined
#endif

#ifdef CM_GEN8_5
#warning CM_GEN8_5 defined
#endif

#ifdef CM_GEN9
#warning CM_GEN9 defined
#endif

#ifdef CM_GEN9_5
#warning CM_GEN9_5 defined
#endif

#ifdef CM_GEN10
#warning CM_GEN10 defined
#endif

// CHECK: cm_asm_output.cpp(14,2):  warning: CM_GENX defined [-W#warnings]
// CHECK: cm_asm_output.cpp(30,2):  warning: CM_GEN9 defined [-W#warnings]
// CHECK: 2 warnings generated.
// CHECK: -platform SKL
