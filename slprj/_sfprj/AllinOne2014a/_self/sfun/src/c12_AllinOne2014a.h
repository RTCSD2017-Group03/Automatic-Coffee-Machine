#ifndef __c12_AllinOne2014a_h__
#define __c12_AllinOne2014a_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc12_AllinOne2014aInstanceStruct
#define typedef_SFc12_AllinOne2014aInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint32_T c12_GetCupEventEventCounter;
  int32_T c12_sfEvent;
  uint8_T c12_tp_Init;
  boolean_T c12_isStable;
  uint8_T c12_is_active_c12_AllinOne2014a;
  uint8_T c12_is_c12_AllinOne2014a;
  uint8_T c12_doSetSimStateSideEffects;
  const mxArray *c12_setSimStateSideEffectsInfo;
} SFc12_AllinOne2014aInstanceStruct;

#endif                                 /*typedef_SFc12_AllinOne2014aInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c12_AllinOne2014a_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c12_AllinOne2014a_get_check_sum(mxArray *plhs[]);
extern void c12_AllinOne2014a_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
