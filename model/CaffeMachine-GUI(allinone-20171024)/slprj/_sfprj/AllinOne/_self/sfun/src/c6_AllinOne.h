#ifndef __c6_AllinOne_h__
#define __c6_AllinOne_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc6_AllinOneInstanceStruct
#define typedef_SFc6_AllinOneInstanceStruct

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
  uint8_T c6_is_active_c6_AllinOne;
  uint8_T c6_is_InFlow;
  uint8_T c6_is_active_InFlow;
  uint8_T c6_is_Heater;
  uint8_T c6_is_active_Heater;
  boolean_T c6_dataWrittenToVector[2];
  uint8_T c6_doSetSimStateSideEffects;
  const mxArray *c6_setSimStateSideEffectsInfo;
  int8_T *c6_Tick;
  real_T *c6_InnerTemp;
  real_T *c6_InnerAmount;
  real_T *c6_HeatSwitch;
  real_T *c6_InFlowSwitch;
} SFc6_AllinOneInstanceStruct;

#endif                                 /*typedef_SFc6_AllinOneInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_AllinOne_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c6_AllinOne_get_check_sum(mxArray *plhs[]);
extern void c6_AllinOne_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
