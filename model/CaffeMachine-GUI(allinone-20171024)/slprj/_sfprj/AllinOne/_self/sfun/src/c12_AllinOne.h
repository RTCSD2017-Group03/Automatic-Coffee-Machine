#ifndef __c12_AllinOne_h__
#define __c12_AllinOne_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc12_AllinOneInstanceStruct
#define typedef_SFc12_AllinOneInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  uint32_T c12_GetCupEventEventCounter;
  int32_T c12_sfEvent;
  uint8_T c12_tp_Init;
  uint8_T c12_tp_TakeOut;
  uint8_T c12_tp_error;
  uint8_T c12_tp_prepare_AmerricanCoffee;
  uint8_T c12_tp_prepare_Cappuccino;
  uint8_T c12_tp_prepare_CoffeeLatte;
  uint8_T c12_tp_BeltStep2;
  uint8_T c12_tp_GetCup;
  uint8_T c12_tp_working_Coffee;
  uint8_T c12_tp_WaterState;
  uint8_T c12_tp_Working;
  uint8_T c12_tp_Finished;
  uint8_T c12_tp_SugarDoserState;
  uint8_T c12_b_tp_Working;
  uint8_T c12_b_tp_Finished;
  uint8_T c12_tp_CoffeeDoserState;
  uint8_T c12_c_tp_Working;
  uint8_T c12_c_tp_Finished;
  uint8_T c12_tp_MilkDoserState;
  uint8_T c12_d_tp_Working;
  uint8_T c12_d_tp_Finished;
  uint8_T c12_tp_BeltStep1;
  boolean_T c12_isStable;
  uint8_T c12_is_active_c12_AllinOne;
  uint8_T c12_is_c12_AllinOne;
  uint8_T c12_is_WaterState;
  uint8_T c12_is_active_WaterState;
  uint8_T c12_is_SugarDoserState;
  uint8_T c12_is_active_SugarDoserState;
  uint8_T c12_is_CoffeeDoserState;
  uint8_T c12_is_active_CoffeeDoserState;
  uint8_T c12_is_MilkDoserState;
  uint8_T c12_is_active_MilkDoserState;
  real_T c12_CoffeeRecipe;
  real_T c12_MilkRecipe;
  real_T c12_SugarRecipe;
  real_T c12_WaterRecipe;
  uint32_T c12_temporalCounter_i1;
  uint16_T c12_temporalCounter_i2;
  uint8_T c12_doSetSimStateSideEffects;
  const mxArray *c12_setSimStateSideEffectsInfo;
} SFc12_AllinOneInstanceStruct;

#endif                                 /*typedef_SFc12_AllinOneInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c12_AllinOne_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c12_AllinOne_get_check_sum(mxArray *plhs[]);
extern void c12_AllinOne_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
