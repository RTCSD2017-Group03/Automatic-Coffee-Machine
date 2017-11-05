#ifndef __c2_AllinOne_2014a_h__
#define __c2_AllinOne_2014a_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
#ifndef typedef_SFc2_AllinOne_2014aInstanceStruct
#define typedef_SFc2_AllinOne_2014aInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint32_T c2_ClearIntegratorEventEventCounter;
  int32_T c2_sfEvent;
  uint8_T c2_tp_Ready;
  uint8_T c2_tp_Finish;
  uint8_T c2_tp_Transmiting;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_AllinOne_2014a;
  uint8_T c2_is_c2_AllinOne_2014a;
  real_T c2_TargetAmount;
  uint8_T c2_temporalCounter_i1;
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
  void *c2_dataSetLogObjVector[1];
  rtwCAPI_ModelMappingInfo c2_testPointMappingInfo;
  void *c2_testPointAddrMap[1];
} SFc2_AllinOne_2014aInstanceStruct;

#endif                                 /*typedef_SFc2_AllinOne_2014aInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_AllinOne_2014a_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_AllinOne_2014a_get_check_sum(mxArray *plhs[]);
extern void c2_AllinOne_2014a_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
