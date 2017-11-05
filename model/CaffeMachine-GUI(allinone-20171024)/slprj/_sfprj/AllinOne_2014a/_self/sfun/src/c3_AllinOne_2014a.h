#ifndef __c3_AllinOne_2014a_h__
#define __c3_AllinOne_2014a_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
#ifndef typedef_SFc3_AllinOne_2014aInstanceStruct
#define typedef_SFc3_AllinOne_2014aInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint32_T c3_ClearIntegratorEventEventCounter;
  int32_T c3_sfEvent;
  uint8_T c3_tp_Ready;
  uint8_T c3_tp_Finish;
  uint8_T c3_tp_Transmiting;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_AllinOne_2014a;
  uint8_T c3_is_c3_AllinOne_2014a;
  real_T c3_TargetAmount;
  uint8_T c3_temporalCounter_i1;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  void *c3_dataSetLogObjVector[1];
  rtwCAPI_ModelMappingInfo c3_testPointMappingInfo;
  void *c3_testPointAddrMap[1];
} SFc3_AllinOne_2014aInstanceStruct;

#endif                                 /*typedef_SFc3_AllinOne_2014aInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_AllinOne_2014a_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_AllinOne_2014a_get_check_sum(mxArray *plhs[]);
extern void c3_AllinOne_2014a_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
