#ifndef __c7_AllinOne_h__
#define __c7_AllinOne_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc7_AllinOneInstanceStruct
#define typedef_SFc7_AllinOneInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint32_T c7_MixFinishEventEventCounter;
  int32_T c7_sfEvent;
  uint8_T c7_tp_WaterState;
  uint8_T c7_tp_Waiting;
  uint8_T c7_tp_Adding;
  uint8_T c7_tp_Finished;
  uint8_T c7_tp_CoffeeState;
  uint8_T c7_b_tp_Waiting;
  uint8_T c7_b_tp_Adding;
  uint8_T c7_b_tp_Finished;
  uint8_T c7_tp_MilkState;
  uint8_T c7_c_tp_Waiting;
  uint8_T c7_c_tp_Adding;
  uint8_T c7_c_tp_Finished;
  uint8_T c7_tp_SugarState;
  uint8_T c7_d_tp_Waiting;
  uint8_T c7_d_tp_Adding;
  uint8_T c7_d_tp_Finished;
  uint8_T c7_tp_Mix;
  uint8_T c7_e_tp_Waiting;
  uint8_T c7_tp_Mixing;
  uint8_T c7_tp_Output;
  uint8_T c7_e_tp_Finished;
  boolean_T c7_isStable;
  boolean_T c7_doneDoubleBufferReInit;
  uint8_T c7_is_active_c7_AllinOne;
  uint8_T c7_is_WaterState;
  uint8_T c7_is_active_WaterState;
  uint8_T c7_is_CoffeeState;
  uint8_T c7_is_active_CoffeeState;
  uint8_T c7_is_MilkState;
  uint8_T c7_is_active_MilkState;
  uint8_T c7_is_SugarState;
  uint8_T c7_is_active_SugarState;
  uint8_T c7_is_Mix;
  uint8_T c7_is_active_Mix;
  uint8_T c7_temporalCounter_i1;
  uint8_T c7_doSetSimStateSideEffects;
  const mxArray *c7_setSimStateSideEffectsInfo;
} SFc7_AllinOneInstanceStruct;

#endif                                 /*typedef_SFc7_AllinOneInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c7_AllinOne_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c7_AllinOne_get_check_sum(mxArray *plhs[]);
extern void c7_AllinOne_method_dispatcher(SimStruct *S, int_T method, void *data);

#endif
