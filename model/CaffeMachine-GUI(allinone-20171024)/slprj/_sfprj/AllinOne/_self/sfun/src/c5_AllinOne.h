#ifndef __c5_AllinOne_h__
#define __c5_AllinOne_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_AllinOneInstanceStruct
#define typedef_SFc5_AllinOneInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint32_T c5_FeedFinishEventEventCounter;
  int32_T c5_sfEvent;
  uint8_T c5_tp_Ready;
  uint8_T c5_tp_PutaCup;
  boolean_T c5_isStable;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_AllinOne;
  uint8_T c5_is_c5_AllinOne;
  real_T c5_CupAmount;
  uint8_T c5_temporalCounter_i1;
  boolean_T c5_dataWrittenToVector[3];
  uint8_T c5_doSetSimStateSideEffects;
  const mxArray *c5_setSimStateSideEffectsInfo;
  boolean_T *c5_FeedFinishEvent;
  int8_T *c5_Tick;
  int8_T *c5_NeedCupEvent;
  real_T *c5_JustaCup;
  boolean_T *c5_CupRemain;
} SFc5_AllinOneInstanceStruct;

#endif                                 /*typedef_SFc5_AllinOneInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_AllinOne_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_AllinOne_get_check_sum(mxArray *plhs[]);
extern void c5_AllinOne_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
