#ifndef __c2_AllinOne_h__
#define __c2_AllinOne_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
#ifndef typedef_SFc2_AllinOneInstanceStruct
#define typedef_SFc2_AllinOneInstanceStruct

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
  uint8_T c2_is_active_c2_AllinOne;
  uint8_T c2_is_c2_AllinOne;
  real_T c2_TargetAmount;
  uint8_T c2_temporalCounter_i1;
  boolean_T c2_dataWrittenToVector[2];
  uint8_T c2_doSetSimStateSideEffects;
  const mxArray *c2_setSimStateSideEffectsInfo;
  void *c2_dataSetLogObjVector[1];
  rtwCAPI_ModelMappingInfo c2_testPointMappingInfo;
  void *c2_testPointAddrMap[1];
  boolean_T *c2_ClearIntegratorEvent;
  int8_T *c2_Tick;
  real_T *c2_SettingAmount;
  real_T *c2_RemainLiquid;
  real_T *c2_OutLiquid;
} SFc2_AllinOneInstanceStruct;

#endif                                 /*typedef_SFc2_AllinOneInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_AllinOne_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_AllinOne_get_check_sum(mxArray *plhs[]);
extern void c2_AllinOne_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
