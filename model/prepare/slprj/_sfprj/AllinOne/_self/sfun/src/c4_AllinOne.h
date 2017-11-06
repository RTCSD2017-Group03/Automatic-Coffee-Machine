#ifndef __c4_AllinOne_h__
#define __c4_AllinOne_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "rtw_capi.h"
#include "rtw_modelmap.h"

/* Type Definitions */
#ifndef typedef_SFc4_AllinOneInstanceStruct
#define typedef_SFc4_AllinOneInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint32_T c4_ClearIntegratorEventEventCounter;
  int32_T c4_sfEvent;
  uint8_T c4_tp_Ready;
  uint8_T c4_tp_Finish;
  uint8_T c4_tp_Transmiting;
  boolean_T c4_doneDoubleBufferReInit;
  uint8_T c4_is_active_c4_AllinOne;
  uint8_T c4_is_c4_AllinOne;
  real_T c4_TargetAmount;
  uint8_T c4_temporalCounter_i1;
  boolean_T c4_dataWrittenToVector[2];
  uint8_T c4_doSetSimStateSideEffects;
  const mxArray *c4_setSimStateSideEffectsInfo;
  void *c4_dataSetLogObjVector[1];
  rtwCAPI_ModelMappingInfo c4_testPointMappingInfo;
  void *c4_testPointAddrMap[1];
  boolean_T *c4_ClearIntegratorEvent;
  int8_T *c4_Tick;
  void *c4_fEmlrtCtx;
  real_T *c4_SettingAmount;
  real_T *c4_RemainLiquid;
  real_T *c4_OutLiquid;
} SFc4_AllinOneInstanceStruct;

#endif                                 /*typedef_SFc4_AllinOneInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c4_AllinOne_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c4_AllinOne_get_check_sum(mxArray *plhs[]);
extern void c4_AllinOne_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
