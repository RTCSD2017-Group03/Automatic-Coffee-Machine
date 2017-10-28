#ifndef __c3_AllinOne_h__
#define __c3_AllinOne_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
#ifndef typedef_SFc3_AllinOneInstanceStruct
#define typedef_SFc3_AllinOneInstanceStruct

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
  uint8_T c3_is_active_c3_AllinOne;
  uint8_T c3_is_c3_AllinOne;
  real_T c3_TargetAmount;
  uint8_T c3_temporalCounter_i1;
  boolean_T c3_dataWrittenToVector[2];
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  void *c3_dataSetLogObjVector[1];
  rtwCAPI_ModelMappingInfo c3_testPointMappingInfo;
  void *c3_testPointAddrMap[1];
  boolean_T *c3_ClearIntegratorEvent;
  int8_T *c3_Tick;
  real_T *c3_SettingAmount;
  real_T *c3_RemainLiquid;
  real_T *c3_OutLiquid;
} SFc3_AllinOneInstanceStruct;

#endif                                 /*typedef_SFc3_AllinOneInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_AllinOne_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_AllinOne_get_check_sum(mxArray *plhs[]);
extern void c3_AllinOne_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
