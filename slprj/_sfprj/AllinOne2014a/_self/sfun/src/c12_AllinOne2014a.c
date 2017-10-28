/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllinOne2014a_sfun.h"
#include "c12_AllinOne2014a.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "AllinOne2014a_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c12_event_Tick                 (0)
#define c12_event_AmericanCoffee       (1)
#define c12_event_CoffeeLatte          (2)
#define c12_event_Cappuccino           (3)
#define c12_event_StepEvent            (4)
#define c12_event_FeedFinishEvent      (5)
#define c12_event_MixFinishEvent       (6)
#define c12_event_SugarDoserEvent      (7)
#define c12_event_MilkDoserEvent       (8)
#define c12_event_CoffeeDoserEvent     (9)
#define CALL_EVENT                     (-1)
#define c12_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c12_IN_Init                    ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c12_debug_family_names[2] = { "nargin", "nargout" };

static boolean_T c12_dataWrittenToVector[5];

/* Function Declarations */
static void initialize_c12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance);
static void initialize_params_c12_AllinOne2014a
  (SFc12_AllinOne2014aInstanceStruct *chartInstance);
static void enable_c12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance);
static void disable_c12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance);
static void c12_update_debugger_state_c12_AllinOne2014a
  (SFc12_AllinOne2014aInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c12_AllinOne2014a
  (SFc12_AllinOne2014aInstanceStruct *chartInstance);
static void set_sim_state_c12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_st);
static void c12_set_sim_state_side_effects_c12_AllinOne2014a
  (SFc12_AllinOne2014aInstanceStruct *chartInstance);
static void finalize_c12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance);
static void sf_gateway_c12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance);
static void c12_chartstep_c12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance);
static void initSimStructsc12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_nargout, const char_T *c12_identifier);
static real_T c12_b_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int8_T c12_c_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static uint32_T c12_d_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_b_GetCupEventEventCounter, const char_T
  *c12_identifier);
static uint32_T c12_e_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_f_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static uint8_T c12_g_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_b_tp_Init, const char_T *c12_identifier);
static uint8_T c12_h_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static boolean_T c12_i_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_GetCupEvent, const char_T *c12_identifier);
static boolean_T c12_j_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static const mxArray *c12_k_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_b_setSimStateSideEffectsInfo, const char_T *
  c12_identifier);
static const mxArray *c12_l_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_updateDataWrittenToVector(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, uint32_T c12_vectorIndex);
static void init_dsm_address_info(SFc12_AllinOne2014aInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance)
{
  boolean_T *c12_GetCupEvent;
  c12_GetCupEvent = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c12_doSetSimStateSideEffects = 0U;
  chartInstance->c12_setSimStateSideEffectsInfo = NULL;
  chartInstance->c12_tp_Init = 0U;
  chartInstance->c12_is_active_c12_AllinOne2014a = 0U;
  chartInstance->c12_is_c12_AllinOne2014a = c12_IN_NO_ACTIVE_CHILD;
  chartInstance->c12_GetCupEventEventCounter = 0U;
  *c12_GetCupEvent = false;
}

static void initialize_params_c12_AllinOne2014a
  (SFc12_AllinOne2014aInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c12_update_debugger_state_c12_AllinOne2014a
  (SFc12_AllinOne2014aInstanceStruct *chartInstance)
{
  uint32_T c12_prevAniVal;
  c12_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c12_is_active_c12_AllinOne2014a == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 7U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_c12_AllinOne2014a == c12_IN_Init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c12_sfEvent);
  }

  _SFD_SET_ANIMATION(c12_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c12_AllinOne2014a
  (SFc12_AllinOne2014aInstanceStruct *chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_y = NULL;
  real_T c12_hoistedGlobal;
  real_T c12_u;
  const mxArray *c12_b_y = NULL;
  real_T c12_b_hoistedGlobal;
  real_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  real_T c12_c_hoistedGlobal;
  real_T c12_c_u;
  const mxArray *c12_d_y = NULL;
  real_T c12_d_hoistedGlobal;
  real_T c12_d_u;
  const mxArray *c12_e_y = NULL;
  real_T c12_e_hoistedGlobal;
  real_T c12_e_u;
  const mxArray *c12_f_y = NULL;
  boolean_T c12_f_hoistedGlobal;
  boolean_T c12_f_u;
  const mxArray *c12_g_y = NULL;
  uint32_T c12_g_hoistedGlobal;
  uint32_T c12_g_u;
  const mxArray *c12_h_y = NULL;
  uint8_T c12_h_hoistedGlobal;
  uint8_T c12_h_u;
  const mxArray *c12_i_y = NULL;
  uint8_T c12_i_hoistedGlobal;
  uint8_T c12_i_u;
  const mxArray *c12_j_y = NULL;
  real_T *c12_CoffeeAmount;
  real_T *c12_MilkAmount;
  real_T *c12_NextStep;
  real_T *c12_SugarAmount;
  real_T *c12_WaterAmount;
  boolean_T *c12_GetCupEvent;
  c12_GetCupEvent = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c12_NextStep = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c12_WaterAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c12_SugarAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c12_MilkAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c12_CoffeeAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellmatrix(9, 1), false);
  c12_hoistedGlobal = *c12_CoffeeAmount;
  c12_u = c12_hoistedGlobal;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_b_hoistedGlobal = *c12_MilkAmount;
  c12_b_u = c12_b_hoistedGlobal;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 1, c12_c_y);
  c12_c_hoistedGlobal = *c12_NextStep;
  c12_c_u = c12_c_hoistedGlobal;
  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_create("y", &c12_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 2, c12_d_y);
  c12_d_hoistedGlobal = *c12_SugarAmount;
  c12_d_u = c12_d_hoistedGlobal;
  c12_e_y = NULL;
  sf_mex_assign(&c12_e_y, sf_mex_create("y", &c12_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 3, c12_e_y);
  c12_e_hoistedGlobal = *c12_WaterAmount;
  c12_e_u = c12_e_hoistedGlobal;
  c12_f_y = NULL;
  sf_mex_assign(&c12_f_y, sf_mex_create("y", &c12_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 4, c12_f_y);
  c12_f_hoistedGlobal = *c12_GetCupEvent;
  c12_f_u = c12_f_hoistedGlobal;
  c12_g_y = NULL;
  sf_mex_assign(&c12_g_y, sf_mex_create("y", &c12_f_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 5, c12_g_y);
  c12_g_hoistedGlobal = chartInstance->c12_GetCupEventEventCounter;
  c12_g_u = c12_g_hoistedGlobal;
  c12_h_y = NULL;
  sf_mex_assign(&c12_h_y, sf_mex_create("y", &c12_g_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 6, c12_h_y);
  c12_h_hoistedGlobal = chartInstance->c12_is_active_c12_AllinOne2014a;
  c12_h_u = c12_h_hoistedGlobal;
  c12_i_y = NULL;
  sf_mex_assign(&c12_i_y, sf_mex_create("y", &c12_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 7, c12_i_y);
  c12_i_hoistedGlobal = chartInstance->c12_is_c12_AllinOne2014a;
  c12_i_u = c12_i_hoistedGlobal;
  c12_j_y = NULL;
  sf_mex_assign(&c12_j_y, sf_mex_create("y", &c12_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 8, c12_j_y);
  sf_mex_assign(&c12_st, c12_y, false);
  return c12_st;
}

static void set_sim_state_c12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_st)
{
  const mxArray *c12_u;
  real_T *c12_CoffeeAmount;
  real_T *c12_MilkAmount;
  real_T *c12_NextStep;
  real_T *c12_SugarAmount;
  real_T *c12_WaterAmount;
  boolean_T *c12_GetCupEvent;
  c12_GetCupEvent = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c12_NextStep = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c12_WaterAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c12_SugarAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c12_MilkAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c12_CoffeeAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c12_u = sf_mex_dup(c12_st);
  *c12_CoffeeAmount = c12_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 0)), "CoffeeAmount");
  *c12_MilkAmount = c12_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 1)), "MilkAmount");
  *c12_NextStep = c12_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c12_u, 2)), "NextStep");
  *c12_SugarAmount = c12_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 3)), "SugarAmount");
  *c12_WaterAmount = c12_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 4)), "WaterAmount");
  *c12_GetCupEvent = c12_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 5)), "GetCupEvent");
  chartInstance->c12_GetCupEventEventCounter = c12_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 6)),
     "GetCupEventEventCounter");
  chartInstance->c12_is_active_c12_AllinOne2014a = c12_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 7)),
     "is_active_c12_AllinOne2014a");
  chartInstance->c12_is_c12_AllinOne2014a = c12_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 8)), "is_c12_AllinOne2014a");
  sf_mex_assign(&chartInstance->c12_setSimStateSideEffectsInfo,
                c12_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c12_u, 9)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c12_u);
  chartInstance->c12_doSetSimStateSideEffects = 1U;
  c12_update_debugger_state_c12_AllinOne2014a(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void c12_set_sim_state_side_effects_c12_AllinOne2014a
  (SFc12_AllinOne2014aInstanceStruct *chartInstance)
{
  if (chartInstance->c12_doSetSimStateSideEffects != 0) {
    if (chartInstance->c12_is_c12_AllinOne2014a == c12_IN_Init) {
      chartInstance->c12_tp_Init = 1U;
    } else {
      chartInstance->c12_tp_Init = 0U;
    }

    chartInstance->c12_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c12_setSimStateSideEffectsInfo);
}

static void sf_gateway_c12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance)
{
  int32_T c12_inputEventFiredFlag;
  real_T *c12_CoffeeRemain;
  real_T *c12_MilkRemain;
  real_T *c12_SugarRemain;
  real_T *c12_CoffeeAmount;
  real_T *c12_MilkAmount;
  real_T *c12_SugarAmount;
  real_T *c12_WaterAmount;
  real_T *c12_NextStep;
  real_T *c12_WaterRemain;
  real_T *c12_WaterTemp;
  boolean_T *c12_CupRemain;
  int8_T *c12_Tick;
  int8_T *c12_AmericanCoffee;
  int8_T *c12_CoffeeLatte;
  int8_T *c12_Cappuccino;
  int8_T *c12_StepEvent;
  int8_T *c12_FeedFinishEvent;
  int8_T *c12_MixFinishEvent;
  int8_T *c12_SugarDoserEvent;
  int8_T *c12_MilkDoserEvent;
  int8_T *c12_CoffeeDoserEvent;
  boolean_T *c12_GetCupEvent;
  c12_GetCupEvent = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 6);
  c12_CoffeeDoserEvent = (int8_T *)*(ssGetInputPortSignalPtrs(chartInstance->S,
    6) + 9);
  c12_MilkDoserEvent = (int8_T *)*(ssGetInputPortSignalPtrs(chartInstance->S, 6)
    + 8);
  c12_SugarDoserEvent = (int8_T *)*(ssGetInputPortSignalPtrs(chartInstance->S, 6)
    + 7);
  c12_MixFinishEvent = (int8_T *)*(ssGetInputPortSignalPtrs(chartInstance->S, 6)
    + 6);
  c12_FeedFinishEvent = (int8_T *)*(ssGetInputPortSignalPtrs(chartInstance->S, 6)
    + 5);
  c12_StepEvent = (int8_T *)*(ssGetInputPortSignalPtrs(chartInstance->S, 6) + 4);
  c12_Cappuccino = (int8_T *)*(ssGetInputPortSignalPtrs(chartInstance->S, 6) + 3);
  c12_CoffeeLatte = (int8_T *)*(ssGetInputPortSignalPtrs(chartInstance->S, 6) +
    2);
  c12_AmericanCoffee = (int8_T *)*(ssGetInputPortSignalPtrs(chartInstance->S, 6)
    + 1);
  c12_Tick = (int8_T *)*(ssGetInputPortSignalPtrs(chartInstance->S, 6) + 0);
  c12_CupRemain = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 5);
  c12_WaterTemp = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
  c12_WaterRemain = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c12_NextStep = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c12_WaterAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c12_SugarAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c12_MilkAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c12_CoffeeAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c12_SugarRemain = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c12_MilkRemain = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c12_CoffeeRemain = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c12_set_sim_state_side_effects_c12_AllinOne2014a(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c12_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c12_CoffeeRemain, 0U);
  _SFD_DATA_RANGE_CHECK(*c12_MilkRemain, 1U);
  _SFD_DATA_RANGE_CHECK(*c12_SugarRemain, 2U);
  _SFD_DATA_RANGE_CHECK(*c12_CoffeeAmount, 3U);
  _SFD_DATA_RANGE_CHECK(*c12_MilkAmount, 4U);
  _SFD_DATA_RANGE_CHECK(*c12_SugarAmount, 5U);
  _SFD_DATA_RANGE_CHECK(*c12_WaterAmount, 6U);
  _SFD_DATA_RANGE_CHECK(*c12_NextStep, 7U);
  _SFD_DATA_RANGE_CHECK(*c12_WaterRemain, 8U);
  _SFD_DATA_RANGE_CHECK(*c12_WaterTemp, 9U);
  _SFD_DATA_RANGE_CHECK((real_T)*c12_CupRemain, 10U);
  c12_inputEventFiredFlag = 0;
  if (*c12_Tick == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_Tick;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_Tick,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne2014a(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_Tick,
                 chartInstance->c12_sfEvent);
  }

  if (*c12_AmericanCoffee == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_AmericanCoffee;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_AmericanCoffee,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne2014a(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_AmericanCoffee,
                 chartInstance->c12_sfEvent);
  }

  if (*c12_CoffeeLatte == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_CoffeeLatte;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_CoffeeLatte,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne2014a(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_CoffeeLatte,
                 chartInstance->c12_sfEvent);
  }

  if (*c12_Cappuccino == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_Cappuccino;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_Cappuccino,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne2014a(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_Cappuccino,
                 chartInstance->c12_sfEvent);
  }

  if (*c12_StepEvent == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_StepEvent;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_StepEvent,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne2014a(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_StepEvent,
                 chartInstance->c12_sfEvent);
  }

  if (*c12_FeedFinishEvent == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_FeedFinishEvent;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_FeedFinishEvent,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne2014a(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_FeedFinishEvent,
                 chartInstance->c12_sfEvent);
  }

  if (*c12_MixFinishEvent == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_MixFinishEvent;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_MixFinishEvent,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne2014a(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_MixFinishEvent,
                 chartInstance->c12_sfEvent);
  }

  if (*c12_SugarDoserEvent == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_SugarDoserEvent;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_SugarDoserEvent,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne2014a(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_SugarDoserEvent,
                 chartInstance->c12_sfEvent);
  }

  if (*c12_MilkDoserEvent == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_MilkDoserEvent;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_MilkDoserEvent,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne2014a(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_MilkDoserEvent,
                 chartInstance->c12_sfEvent);
  }

  if (*c12_CoffeeDoserEvent == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_CoffeeDoserEvent;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_CoffeeDoserEvent,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne2014a(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_CoffeeDoserEvent,
                 chartInstance->c12_sfEvent);
  }

  if (c12_inputEventFiredFlag != 0) {
    if (chartInstance->c12_GetCupEventEventCounter > 0U) {
      *c12_GetCupEvent = !*c12_GetCupEvent;
      chartInstance->c12_GetCupEventEventCounter--;
    }
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_AllinOne2014aMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c12_chartstep_c12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance)
{
  uint32_T c12_debug_family_var_map[2];
  real_T c12_nargin = 0.0;
  real_T c12_nargout = 0.0;
  real_T *c12_CoffeeAmount;
  real_T *c12_MilkAmount;
  real_T *c12_SugarAmount;
  real_T *c12_WaterAmount;
  real_T *c12_NextStep;
  c12_NextStep = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
  c12_WaterAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c12_SugarAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c12_MilkAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c12_CoffeeAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c12_sfEvent);
  if (chartInstance->c12_is_active_c12_AllinOne2014a == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 7U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_active_c12_AllinOne2014a = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c12_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_c12_AllinOne2014a = c12_IN_Init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c12_sfEvent);
    chartInstance->c12_tp_Init = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c12_debug_family_names,
      c12_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargin, 0U, c12_sf_marshallOut,
      c12_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargout, 1U, c12_sf_marshallOut,
      c12_sf_marshallIn);
    *c12_CoffeeAmount = 0.0;
    c12_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c12_CoffeeAmount, 3U);
    *c12_MilkAmount = 0.0;
    c12_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*c12_MilkAmount, 4U);
    *c12_SugarAmount = 0.0;
    c12_updateDataWrittenToVector(chartInstance, 2U);
    _SFD_DATA_RANGE_CHECK(*c12_SugarAmount, 5U);
    *c12_WaterAmount = 0.0;
    c12_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*c12_WaterAmount, 6U);
    *c12_NextStep = 0.0;
    c12_updateDataWrittenToVector(chartInstance, 4U);
    _SFD_DATA_RANGE_CHECK(*c12_NextStep, 7U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c12_sfEvent);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c12_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c12_sfEvent);
}

static void initSimStructsc12_AllinOne2014a(SFc12_AllinOne2014aInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber)
{
  (void)c12_machineNumber;
  (void)c12_chartNumber;
  (void)c12_instanceNumber;
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_AllinOne2014aInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOne2014aInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static real_T c12_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_nargout, const char_T *c12_identifier)
{
  real_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_nargout),
    &c12_thisId);
  sf_mex_destroy(&c12_nargout);
  return c12_y;
}

static real_T c12_b_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d0, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_nargout;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_AllinOne2014aInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOne2014aInstanceStruct *)chartInstanceVoid;
  c12_nargout = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_nargout),
    &c12_thisId);
  sf_mex_destroy(&c12_nargout);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

const mxArray *sf_c12_AllinOne2014a_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  sf_mex_assign(&c12_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c12_nameCaptureInfo;
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int8_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_AllinOne2014aInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOne2014aInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int8_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static int8_T c12_c_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int8_T c12_y;
  int8_T c12_i0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i0, 1, 2, 0U, 0, 0U, 0);
  c12_y = c12_i0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_Tick;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int8_T c12_y;
  SFc12_AllinOne2014aInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOne2014aInstanceStruct *)chartInstanceVoid;
  c12_Tick = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_Tick),
    &c12_thisId);
  sf_mex_destroy(&c12_Tick);
  *(int8_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  uint32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_AllinOne2014aInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOne2014aInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(uint32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static uint32_T c12_d_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_b_GetCupEventEventCounter, const char_T
  *c12_identifier)
{
  uint32_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_GetCupEventEventCounter), &c12_thisId);
  sf_mex_destroy(&c12_b_GetCupEventEventCounter);
  return c12_y;
}

static uint32_T c12_e_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint32_T c12_y;
  uint32_T c12_u0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 7, 0U, 0, 0U, 0);
  c12_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_GetCupEventEventCounter;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  uint32_T c12_y;
  SFc12_AllinOne2014aInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOne2014aInstanceStruct *)chartInstanceVoid;
  c12_b_GetCupEventEventCounter = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_GetCupEventEventCounter), &c12_thisId);
  sf_mex_destroy(&c12_b_GetCupEventEventCounter);
  *(uint32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_AllinOne2014aInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOne2014aInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static int32_T c12_f_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_y;
  int32_T c12_i1;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i1, 1, 6, 0U, 0, 0U, 0);
  c12_y = c12_i1;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_AllinOne2014aInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOne2014aInstanceStruct *)chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  uint8_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_AllinOne2014aInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOne2014aInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(uint8_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static uint8_T c12_g_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_b_tp_Init, const char_T *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_tp_Init),
    &c12_thisId);
  sf_mex_destroy(&c12_b_tp_Init);
  return c12_y;
}

static uint8_T c12_h_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u1;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u1, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u1;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_tp_Init;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  uint8_T c12_y;
  SFc12_AllinOne2014aInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOne2014aInstanceStruct *)chartInstanceVoid;
  c12_b_tp_Init = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_tp_Init),
    &c12_thisId);
  sf_mex_destroy(&c12_b_tp_Init);
  *(uint8_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  boolean_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_AllinOne2014aInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOne2014aInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(boolean_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static boolean_T c12_i_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_GetCupEvent, const char_T *c12_identifier)
{
  boolean_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_GetCupEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_GetCupEvent);
  return c12_y;
}

static boolean_T c12_j_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  boolean_T c12_y;
  boolean_T c12_b0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_b0, 1, 11, 0U, 0, 0U, 0);
  c12_y = c12_b0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static const mxArray *c12_k_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_b_setSimStateSideEffectsInfo, const char_T *
  c12_identifier)
{
  const mxArray *c12_y = NULL;
  emlrtMsgIdentifier c12_thisId;
  c12_y = NULL;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  sf_mex_assign(&c12_y, c12_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_setSimStateSideEffectsInfo), &c12_thisId), false);
  sf_mex_destroy(&c12_b_setSimStateSideEffectsInfo);
  return c12_y;
}

static const mxArray *c12_l_emlrt_marshallIn(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  const mxArray *c12_y = NULL;
  (void)chartInstance;
  (void)c12_parentId;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_duplicatearraysafe(&c12_u), false);
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_updateDataWrittenToVector(SFc12_AllinOne2014aInstanceStruct
  *chartInstance, uint32_T c12_vectorIndex)
{
  (void)chartInstance;
  c12_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c12_vectorIndex, 0, 4, 1, 0)] = true;
}

static void init_dsm_address_info(SFc12_AllinOne2014aInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c12_AllinOne2014a_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2369592993U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4225824179U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(872911285U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2649062695U);
}

mxArray *sf_c12_AllinOne2014a_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("X2egji6hnLkkZRn26gVLAF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c12_AllinOne2014a_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c12_AllinOne2014a_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c12_AllinOne2014a(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[14],T\"CoffeeAmount\",},{M[1],M[15],T\"MilkAmount\",},{M[1],M[23],T\"NextStep\",},{M[1],M[16],T\"SugarAmount\",},{M[1],M[17],T\"WaterAmount\",},{M[6],M[13],T\"GetCupEvent\",},{M[7],M[13],T\"GetCupEventEventCounter\",},{M[8],M[0],T\"is_active_c12_AllinOne2014a\",},{M[9],M[0],T\"is_c12_AllinOne2014a\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_AllinOne2014a_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_AllinOne2014aInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc12_AllinOne2014aInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllinOne2014aMachineNumber_,
           12,
           1,
           1,
           0,
           11,
           11,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_AllinOne2014aMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_AllinOne2014aMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _AllinOne2014aMachineNumber_,
            chartInstance->chartNumber,
            11,
            11,
            11);
          _SFD_SET_DATA_PROPS(0,1,1,0,"CoffeeRemain");
          _SFD_SET_DATA_PROPS(1,1,1,0,"MilkRemain");
          _SFD_SET_DATA_PROPS(2,1,1,0,"SugarRemain");
          _SFD_SET_DATA_PROPS(3,2,0,1,"CoffeeAmount");
          _SFD_SET_DATA_PROPS(4,2,0,1,"MilkAmount");
          _SFD_SET_DATA_PROPS(5,2,0,1,"SugarAmount");
          _SFD_SET_DATA_PROPS(6,2,0,1,"WaterAmount");
          _SFD_SET_DATA_PROPS(7,2,0,1,"NextStep");
          _SFD_SET_DATA_PROPS(8,1,1,0,"WaterRemain");
          _SFD_SET_DATA_PROPS(9,1,1,0,"WaterTemp");
          _SFD_SET_DATA_PROPS(10,1,1,0,"CupRemain");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_EVENT_SCOPE(1,1);
          _SFD_EVENT_SCOPE(2,1);
          _SFD_EVENT_SCOPE(3,1);
          _SFD_EVENT_SCOPE(4,1);
          _SFD_EVENT_SCOPE(5,1);
          _SFD_EVENT_SCOPE(6,1);
          _SFD_EVENT_SCOPE(7,1);
          _SFD_EVENT_SCOPE(8,1);
          _SFD_EVENT_SCOPE(9,1);
          _SFD_EVENT_SCOPE(10,2);
          _SFD_STATE_INFO(0,0,0);
          _SFD_CH_SUBSTATE_COUNT(1);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_ST_SUBSTATE_COUNT(0,0);
        }

        _SFD_CV_INIT_CHART(1,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)c12_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)c12_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)c12_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)c12_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)c12_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_f_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c12_CoffeeRemain;
          real_T *c12_MilkRemain;
          real_T *c12_SugarRemain;
          real_T *c12_CoffeeAmount;
          real_T *c12_MilkAmount;
          real_T *c12_SugarAmount;
          real_T *c12_WaterAmount;
          real_T *c12_NextStep;
          real_T *c12_WaterRemain;
          real_T *c12_WaterTemp;
          boolean_T *c12_CupRemain;
          c12_CupRemain = (boolean_T *)ssGetInputPortSignal(chartInstance->S, 5);
          c12_WaterTemp = (real_T *)ssGetInputPortSignal(chartInstance->S, 4);
          c12_WaterRemain = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c12_NextStep = (real_T *)ssGetOutputPortSignal(chartInstance->S, 5);
          c12_WaterAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c12_SugarAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c12_MilkAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c12_CoffeeAmount = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c12_SugarRemain = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c12_MilkRemain = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c12_CoffeeRemain = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c12_CoffeeRemain);
          _SFD_SET_DATA_VALUE_PTR(1U, c12_MilkRemain);
          _SFD_SET_DATA_VALUE_PTR(2U, c12_SugarRemain);
          _SFD_SET_DATA_VALUE_PTR(3U, c12_CoffeeAmount);
          _SFD_SET_DATA_VALUE_PTR(4U, c12_MilkAmount);
          _SFD_SET_DATA_VALUE_PTR(5U, c12_SugarAmount);
          _SFD_SET_DATA_VALUE_PTR(6U, c12_WaterAmount);
          _SFD_SET_DATA_VALUE_PTR(7U, c12_NextStep);
          _SFD_SET_DATA_VALUE_PTR(8U, c12_WaterRemain);
          _SFD_SET_DATA_VALUE_PTR(9U, c12_WaterTemp);
          _SFD_SET_DATA_VALUE_PTR(10U, c12_CupRemain);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _AllinOne2014aMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "NwoeidFv7G7bRfqGPyxQJH";
}

static void sf_opaque_initialize_c12_AllinOne2014a(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_AllinOne2014aInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c12_AllinOne2014a((SFc12_AllinOne2014aInstanceStruct*)
    chartInstanceVar);
  initialize_c12_AllinOne2014a((SFc12_AllinOne2014aInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c12_AllinOne2014a(void *chartInstanceVar)
{
  enable_c12_AllinOne2014a((SFc12_AllinOne2014aInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c12_AllinOne2014a(void *chartInstanceVar)
{
  disable_c12_AllinOne2014a((SFc12_AllinOne2014aInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c12_AllinOne2014a(void *chartInstanceVar)
{
  sf_gateway_c12_AllinOne2014a((SFc12_AllinOne2014aInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c12_AllinOne2014a(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c12_AllinOne2014a
    ((SFc12_AllinOne2014aInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c12_AllinOne2014a();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c12_AllinOne2014a(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c12_AllinOne2014a();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c12_AllinOne2014a((SFc12_AllinOne2014aInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c12_AllinOne2014a(SimStruct* S)
{
  return sf_internal_get_sim_state_c12_AllinOne2014a(S);
}

static void sf_opaque_set_sim_state_c12_AllinOne2014a(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c12_AllinOne2014a(S, st);
}

static void sf_opaque_terminate_c12_AllinOne2014a(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_AllinOne2014aInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllinOne2014a_optimization_info();
    }

    finalize_c12_AllinOne2014a((SFc12_AllinOne2014aInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_AllinOne2014a((SFc12_AllinOne2014aInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_AllinOne2014a(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c12_AllinOne2014a((SFc12_AllinOne2014aInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_AllinOne2014a(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_AllinOne2014a_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,12,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,12);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,12,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,12,6);
    }

    ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=6; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2313452799U));
  ssSetChecksum1(S,(2685500902U));
  ssSetChecksum2(S,(1332584241U));
  ssSetChecksum3(S,(2569733029U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c12_AllinOne2014a(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c12_AllinOne2014a(SimStruct *S)
{
  SFc12_AllinOne2014aInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc12_AllinOne2014aInstanceStruct *)utMalloc(sizeof
    (SFc12_AllinOne2014aInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc12_AllinOne2014aInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c12_AllinOne2014a;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c12_AllinOne2014a;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c12_AllinOne2014a;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c12_AllinOne2014a;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c12_AllinOne2014a;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c12_AllinOne2014a;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c12_AllinOne2014a;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c12_AllinOne2014a;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_AllinOne2014a;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_AllinOne2014a;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c12_AllinOne2014a;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c12_AllinOne2014a_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_AllinOne2014a(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_AllinOne2014a(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_AllinOne2014a(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_AllinOne2014a_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
