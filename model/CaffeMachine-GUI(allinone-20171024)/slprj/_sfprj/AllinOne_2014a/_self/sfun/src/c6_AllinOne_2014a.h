#ifndef __c6_AllinOne_2014a_h__
#define __c6_AllinOne_2014a_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc6_AllinOne_2014aInstanceStruct
#define typedef_SFc6_AllinOne_2014aInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  uint8_T c6_tp_InFlow;
  uint8_T c6_tp_GetInFlow;
  uint8_T c6_tp_OFF;
  uint8_T c6_tp_Heater;
  uint8_T c6_tp_Heating;
  uint8_T c6_b_tp_OFF;
  boolean_T c6_isStable;
  uint8_T c6_is_active_c6_AllinOne_2014a;
  uint8_T c6_is_InFlow;
  uint8_T c6_is_active_InFlow;
  uint8_T c6_is_Heater;
  uint8_T c6_is_active_Heater;
  uint8_T c6_doSetSimStateSideEffects;
  const mxArray *c6_setSimStateSideEffectsInfo;
} SFc6_AllinOne_2014aInstanceStruct;

#endif                                 /*typedef_SFc6_AllinOne_2014aInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_AllinOne_2014a_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_AllinOne_2014a_get_check_sum(mxArray *plhs[]);
extern void c6_AllinOne_2014a_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
