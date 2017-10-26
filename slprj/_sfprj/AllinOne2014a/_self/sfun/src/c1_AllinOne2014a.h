#ifndef __c1_AllinOne2014a_h__
#define __c1_AllinOne2014a_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_Mixtrue_tag
#define struct_Mixtrue_tag

struct Mixtrue_tag
{
  real_T Water[2];
  real_T Coffee;
  real_T Milk;
  real_T Sugar;
};

#endif                                 /*struct_Mixtrue_tag*/

#ifndef typedef_c1_Mixtrue
#define typedef_c1_Mixtrue

typedef struct Mixtrue_tag c1_Mixtrue;

#endif                                 /*typedef_c1_Mixtrue*/

#ifndef typedef_SFc1_AllinOne2014aInstanceStruct
#define typedef_SFc1_AllinOne2014aInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint32_T c1_StepEventEventCounter;
  int32_T c1_sfEvent;
  uint8_T c1_tp_MixtrueMonitor;
  uint8_T c1_tp_Waiting;
  uint8_T c1_tp_Adding;
  uint8_T c1_tp_CupMonitor;
  uint8_T c1_b_tp_Waiting;
  uint8_T c1_b_tp_Adding;
  uint8_T c1_tp_CupTransmit;
  uint8_T c1_tp_Start;
  uint8_T c1_tp_Running;
  uint8_T c1_tp_Output;
  uint8_T c1_tp_Prepare;
  uint8_T c1_tp_Stepping;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_AllinOne2014a;
  uint8_T c1_is_MixtrueMonitor;
  uint8_T c1_is_active_MixtrueMonitor;
  uint8_T c1_is_CupMonitor;
  uint8_T c1_is_active_CupMonitor;
  uint8_T c1_is_CupTransmit;
  uint8_T c1_is_active_CupTransmit;
  real_T c1_CupLocation;
  c1_Mixtrue c1_LocalMixtrue;
  uint32_T c1_temporalCounter_i1;
  uint8_T c1_doSetSimStateSideEffects;
  const mxArray *c1_setSimStateSideEffectsInfo;
} SFc1_AllinOne2014aInstanceStruct;

#endif                                 /*typedef_SFc1_AllinOne2014aInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_AllinOne2014a_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_AllinOne2014a_get_check_sum(mxArray *plhs[]);
extern void c1_AllinOne2014a_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
