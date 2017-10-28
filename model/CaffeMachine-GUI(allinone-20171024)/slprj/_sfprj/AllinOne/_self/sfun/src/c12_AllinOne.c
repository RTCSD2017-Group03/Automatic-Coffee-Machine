/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllinOne_sfun.h"
#include "c12_AllinOne.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "AllinOne_sfun_debug_macros.h"
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
#define c12_event_TakeOutEvent         (11)
#define CALL_EVENT                     (-1)
#define c12_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c12_IN_GetCup                  ((uint8_T)1U)
#define c12_IN_Init                    ((uint8_T)2U)
#define c12_IN_Step1                   ((uint8_T)3U)
#define c12_IN_Step2                   ((uint8_T)4U)
#define c12_IN_TakeOut                 ((uint8_T)5U)
#define c12_IN_error                   ((uint8_T)6U)
#define c12_IN_prepare_CoffeeLatte     ((uint8_T)7U)
#define c12_IN_working_AmerricanCoffee ((uint8_T)8U)
#define c12_IN_working_Cappuccino      ((uint8_T)9U)
#define c12_IN_working_Coffee          ((uint8_T)10U)
#define c12_IN_Finished                ((uint8_T)1U)
#define c12_IN_Working                 ((uint8_T)2U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;

/* Function Declarations */
static void initialize_c12_AllinOne(SFc12_AllinOneInstanceStruct *chartInstance);
static void initialize_params_c12_AllinOne(SFc12_AllinOneInstanceStruct
  *chartInstance);
static void enable_c12_AllinOne(SFc12_AllinOneInstanceStruct *chartInstance);
static void disable_c12_AllinOne(SFc12_AllinOneInstanceStruct *chartInstance);
static void c12_update_debugger_state_c12_AllinOne(SFc12_AllinOneInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c12_AllinOne(SFc12_AllinOneInstanceStruct
  *chartInstance);
static void set_sim_state_c12_AllinOne(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_st);
static void c12_set_sim_state_side_effects_c12_AllinOne
  (SFc12_AllinOneInstanceStruct *chartInstance);
static void finalize_c12_AllinOne(SFc12_AllinOneInstanceStruct *chartInstance);
static void sf_gateway_c12_AllinOne(SFc12_AllinOneInstanceStruct *chartInstance);
static void mdl_start_c12_AllinOne(SFc12_AllinOneInstanceStruct *chartInstance);
static void c12_chartstep_c12_AllinOne(SFc12_AllinOneInstanceStruct
  *chartInstance);
static void initSimStructsc12_AllinOne(SFc12_AllinOneInstanceStruct
  *chartInstance);
static void c12_Init(SFc12_AllinOneInstanceStruct *chartInstance);
static void c12_GetCup(SFc12_AllinOneInstanceStruct *chartInstance);
static void c12_working_Coffee(SFc12_AllinOneInstanceStruct *chartInstance);
static void c12_exit_internal_working_Coffee(SFc12_AllinOneInstanceStruct
  *chartInstance);
static void c12_Step1(SFc12_AllinOneInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber);
static boolean_T c12_checkall(SFc12_AllinOneInstanceStruct *chartInstance,
  real_T c12_waterRemain, real_T c12_waterRecipe, real_T c12_milkRemain, real_T
  c12_milkRecipe, real_T c12_sugarRemain, real_T c12_sugarRecipe, real_T
  c12_coffeeRemain, real_T c12_coffeeRecipe, real_T c12_cupRemain, real_T
  c12_waterTemp);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int8_T c12_emlrt_marshallIn(SFc12_AllinOneInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static uint32_T c12_b_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_b_GetCupEventEventCounter, const char_T
  *c12_identifier);
static uint32_T c12_c_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_d_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static uint8_T c12_e_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_b_tp_Init, const char_T *c12_identifier);
static uint8_T c12_f_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_g_emlrt_marshallIn(SFc12_AllinOneInstanceStruct *chartInstance,
  const mxArray *c12_b_CoffeeAmount, const char_T *c12_identifier);
static real_T c12_h_emlrt_marshallIn(SFc12_AllinOneInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static boolean_T c12_i_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_flg, const char_T *c12_identifier);
static boolean_T c12_j_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static uint16_T c12_k_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_b_temporalCounter_i2, const char_T
  *c12_identifier);
static uint16_T c12_l_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static const mxArray *c12_m_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_b_setSimStateSideEffectsInfo, const char_T *
  c12_identifier);
static const mxArray *c12_n_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void init_dsm_address_info(SFc12_AllinOneInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc12_AllinOneInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c12_AllinOne(SFc12_AllinOneInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c12_doSetSimStateSideEffects = 0U;
  chartInstance->c12_setSimStateSideEffectsInfo = NULL;
  chartInstance->c12_tp_GetCup = 0U;
  chartInstance->c12_temporalCounter_i1 = 0U;
  chartInstance->c12_tp_Init = 0U;
  chartInstance->c12_tp_Step1 = 0U;
  chartInstance->c12_temporalCounter_i1 = 0U;
  chartInstance->c12_tp_Step2 = 0U;
  chartInstance->c12_temporalCounter_i1 = 0U;
  chartInstance->c12_tp_TakeOut = 0U;
  chartInstance->c12_tp_error = 0U;
  chartInstance->c12_tp_prepare_CoffeeLatte = 0U;
  chartInstance->c12_tp_working_AmerricanCoffee = 0U;
  chartInstance->c12_tp_working_Cappuccino = 0U;
  chartInstance->c12_tp_working_Coffee = 0U;
  chartInstance->c12_temporalCounter_i2 = 0U;
  chartInstance->c12_is_active_CoffeeDoserState = 0U;
  chartInstance->c12_is_CoffeeDoserState = c12_IN_NO_ACTIVE_CHILD;
  chartInstance->c12_tp_CoffeeDoserState = 0U;
  chartInstance->c12_c_tp_Finished = 0U;
  chartInstance->c12_c_tp_Working = 0U;
  chartInstance->c12_is_active_MilkDoserState = 0U;
  chartInstance->c12_is_MilkDoserState = c12_IN_NO_ACTIVE_CHILD;
  chartInstance->c12_tp_MilkDoserState = 0U;
  chartInstance->c12_d_tp_Finished = 0U;
  chartInstance->c12_d_tp_Working = 0U;
  chartInstance->c12_is_active_SugarDoserState = 0U;
  chartInstance->c12_is_SugarDoserState = c12_IN_NO_ACTIVE_CHILD;
  chartInstance->c12_tp_SugarDoserState = 0U;
  chartInstance->c12_b_tp_Finished = 0U;
  chartInstance->c12_b_tp_Working = 0U;
  chartInstance->c12_is_active_WaterState = 0U;
  chartInstance->c12_is_WaterState = c12_IN_NO_ACTIVE_CHILD;
  chartInstance->c12_tp_WaterState = 0U;
  chartInstance->c12_tp_Finished = 0U;
  chartInstance->c12_tp_Working = 0U;
  chartInstance->c12_temporalCounter_i1 = 0U;
  chartInstance->c12_is_active_c12_AllinOne = 0U;
  chartInstance->c12_is_c12_AllinOne = c12_IN_NO_ACTIVE_CHILD;
  chartInstance->c12_CoffeeRecipe = 0.0;
  chartInstance->c12_MilkRecipe = 0.0;
  chartInstance->c12_SugarRecipe = 0.0;
  chartInstance->c12_WaterRecipe = 0.0;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c12_CoffeeAmount = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *chartInstance->c12_MilkAmount = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 3) != 0)) {
    *chartInstance->c12_SugarAmount = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 4) != 0)) {
    *chartInstance->c12_WaterAmount = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 5) != 0)) {
    *chartInstance->c12_NextStep = 0.0;
  }

  chartInstance->c12_GetCupEventEventCounter = 0U;
  *chartInstance->c12_GetCupEvent = false;
}

static void initialize_params_c12_AllinOne(SFc12_AllinOneInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c12_AllinOne(SFc12_AllinOneInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c12_AllinOne(SFc12_AllinOneInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c12_update_debugger_state_c12_AllinOne(SFc12_AllinOneInstanceStruct *
  chartInstance)
{
  uint32_T c12_prevAniVal;
  c12_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c12_is_active_c12_AllinOne == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 7U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_c12_AllinOne == c12_IN_Init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_c12_AllinOne == c12_IN_TakeOut) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_c12_AllinOne == c12_IN_error) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_c12_AllinOne == c12_IN_working_AmerricanCoffee) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_c12_AllinOne == c12_IN_working_Cappuccino) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_c12_AllinOne == c12_IN_prepare_CoffeeLatte) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_c12_AllinOne == c12_IN_Step2) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_c12_AllinOne == c12_IN_GetCup) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_c12_AllinOne == c12_IN_working_Coffee) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_active_WaterState == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_WaterState == c12_IN_Working) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_WaterState == c12_IN_Finished) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_active_SugarDoserState == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_SugarDoserState == c12_IN_Working) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_SugarDoserState == c12_IN_Finished) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_active_CoffeeDoserState == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_CoffeeDoserState == c12_IN_Working) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_CoffeeDoserState == c12_IN_Finished) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_active_MilkDoserState == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_MilkDoserState == c12_IN_Working) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_MilkDoserState == c12_IN_Finished) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c12_sfEvent);
  }

  if (chartInstance->c12_is_c12_AllinOne == c12_IN_Step1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c12_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c12_sfEvent);
  }

  _SFD_SET_ANIMATION(c12_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c12_AllinOne(SFc12_AllinOneInstanceStruct
  *chartInstance)
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
  real_T c12_f_hoistedGlobal;
  real_T c12_f_u;
  const mxArray *c12_g_y = NULL;
  real_T c12_g_hoistedGlobal;
  real_T c12_g_u;
  const mxArray *c12_h_y = NULL;
  real_T c12_h_hoistedGlobal;
  real_T c12_h_u;
  const mxArray *c12_i_y = NULL;
  real_T c12_i_hoistedGlobal;
  real_T c12_i_u;
  const mxArray *c12_j_y = NULL;
  boolean_T c12_j_hoistedGlobal;
  boolean_T c12_j_u;
  const mxArray *c12_k_y = NULL;
  uint32_T c12_k_hoistedGlobal;
  uint32_T c12_k_u;
  const mxArray *c12_l_y = NULL;
  uint8_T c12_l_hoistedGlobal;
  uint8_T c12_l_u;
  const mxArray *c12_m_y = NULL;
  uint8_T c12_m_hoistedGlobal;
  uint8_T c12_m_u;
  const mxArray *c12_n_y = NULL;
  uint8_T c12_n_hoistedGlobal;
  uint8_T c12_n_u;
  const mxArray *c12_o_y = NULL;
  uint8_T c12_o_hoistedGlobal;
  uint8_T c12_o_u;
  const mxArray *c12_p_y = NULL;
  uint8_T c12_p_hoistedGlobal;
  uint8_T c12_p_u;
  const mxArray *c12_q_y = NULL;
  uint8_T c12_q_hoistedGlobal;
  uint8_T c12_q_u;
  const mxArray *c12_r_y = NULL;
  uint8_T c12_r_hoistedGlobal;
  uint8_T c12_r_u;
  const mxArray *c12_s_y = NULL;
  uint8_T c12_s_hoistedGlobal;
  uint8_T c12_s_u;
  const mxArray *c12_t_y = NULL;
  uint8_T c12_t_hoistedGlobal;
  uint8_T c12_t_u;
  const mxArray *c12_u_y = NULL;
  uint8_T c12_u_hoistedGlobal;
  uint8_T c12_u_u;
  const mxArray *c12_v_y = NULL;
  uint16_T c12_v_hoistedGlobal;
  uint16_T c12_v_u;
  const mxArray *c12_w_y = NULL;
  uint32_T c12_w_hoistedGlobal;
  uint32_T c12_w_u;
  const mxArray *c12_x_y = NULL;
  c12_st = NULL;
  c12_st = NULL;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_createcellmatrix(23, 1), false);
  c12_hoistedGlobal = *chartInstance->c12_CoffeeAmount;
  c12_u = c12_hoistedGlobal;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 0, c12_b_y);
  c12_b_hoistedGlobal = *chartInstance->c12_MilkAmount;
  c12_b_u = c12_b_hoistedGlobal;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 1, c12_c_y);
  c12_c_hoistedGlobal = *chartInstance->c12_NextStep;
  c12_c_u = c12_c_hoistedGlobal;
  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_create("y", &c12_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 2, c12_d_y);
  c12_d_hoistedGlobal = *chartInstance->c12_SugarAmount;
  c12_d_u = c12_d_hoistedGlobal;
  c12_e_y = NULL;
  sf_mex_assign(&c12_e_y, sf_mex_create("y", &c12_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 3, c12_e_y);
  c12_e_hoistedGlobal = *chartInstance->c12_WaterAmount;
  c12_e_u = c12_e_hoistedGlobal;
  c12_f_y = NULL;
  sf_mex_assign(&c12_f_y, sf_mex_create("y", &c12_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 4, c12_f_y);
  c12_f_hoistedGlobal = chartInstance->c12_CoffeeRecipe;
  c12_f_u = c12_f_hoistedGlobal;
  c12_g_y = NULL;
  sf_mex_assign(&c12_g_y, sf_mex_create("y", &c12_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 5, c12_g_y);
  c12_g_hoistedGlobal = chartInstance->c12_MilkRecipe;
  c12_g_u = c12_g_hoistedGlobal;
  c12_h_y = NULL;
  sf_mex_assign(&c12_h_y, sf_mex_create("y", &c12_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 6, c12_h_y);
  c12_h_hoistedGlobal = chartInstance->c12_SugarRecipe;
  c12_h_u = c12_h_hoistedGlobal;
  c12_i_y = NULL;
  sf_mex_assign(&c12_i_y, sf_mex_create("y", &c12_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 7, c12_i_y);
  c12_i_hoistedGlobal = chartInstance->c12_WaterRecipe;
  c12_i_u = c12_i_hoistedGlobal;
  c12_j_y = NULL;
  sf_mex_assign(&c12_j_y, sf_mex_create("y", &c12_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 8, c12_j_y);
  c12_j_hoistedGlobal = *chartInstance->c12_GetCupEvent;
  c12_j_u = c12_j_hoistedGlobal;
  c12_k_y = NULL;
  sf_mex_assign(&c12_k_y, sf_mex_create("y", &c12_j_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 9, c12_k_y);
  c12_k_hoistedGlobal = chartInstance->c12_GetCupEventEventCounter;
  c12_k_u = c12_k_hoistedGlobal;
  c12_l_y = NULL;
  sf_mex_assign(&c12_l_y, sf_mex_create("y", &c12_k_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 10, c12_l_y);
  c12_l_hoistedGlobal = chartInstance->c12_is_active_c12_AllinOne;
  c12_l_u = c12_l_hoistedGlobal;
  c12_m_y = NULL;
  sf_mex_assign(&c12_m_y, sf_mex_create("y", &c12_l_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 11, c12_m_y);
  c12_m_hoistedGlobal = chartInstance->c12_is_active_CoffeeDoserState;
  c12_m_u = c12_m_hoistedGlobal;
  c12_n_y = NULL;
  sf_mex_assign(&c12_n_y, sf_mex_create("y", &c12_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 12, c12_n_y);
  c12_n_hoistedGlobal = chartInstance->c12_is_active_SugarDoserState;
  c12_n_u = c12_n_hoistedGlobal;
  c12_o_y = NULL;
  sf_mex_assign(&c12_o_y, sf_mex_create("y", &c12_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 13, c12_o_y);
  c12_o_hoistedGlobal = chartInstance->c12_is_active_WaterState;
  c12_o_u = c12_o_hoistedGlobal;
  c12_p_y = NULL;
  sf_mex_assign(&c12_p_y, sf_mex_create("y", &c12_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 14, c12_p_y);
  c12_p_hoistedGlobal = chartInstance->c12_is_active_MilkDoserState;
  c12_p_u = c12_p_hoistedGlobal;
  c12_q_y = NULL;
  sf_mex_assign(&c12_q_y, sf_mex_create("y", &c12_p_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 15, c12_q_y);
  c12_q_hoistedGlobal = chartInstance->c12_is_c12_AllinOne;
  c12_q_u = c12_q_hoistedGlobal;
  c12_r_y = NULL;
  sf_mex_assign(&c12_r_y, sf_mex_create("y", &c12_q_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 16, c12_r_y);
  c12_r_hoistedGlobal = chartInstance->c12_is_CoffeeDoserState;
  c12_r_u = c12_r_hoistedGlobal;
  c12_s_y = NULL;
  sf_mex_assign(&c12_s_y, sf_mex_create("y", &c12_r_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 17, c12_s_y);
  c12_s_hoistedGlobal = chartInstance->c12_is_SugarDoserState;
  c12_s_u = c12_s_hoistedGlobal;
  c12_t_y = NULL;
  sf_mex_assign(&c12_t_y, sf_mex_create("y", &c12_s_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 18, c12_t_y);
  c12_t_hoistedGlobal = chartInstance->c12_is_WaterState;
  c12_t_u = c12_t_hoistedGlobal;
  c12_u_y = NULL;
  sf_mex_assign(&c12_u_y, sf_mex_create("y", &c12_t_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 19, c12_u_y);
  c12_u_hoistedGlobal = chartInstance->c12_is_MilkDoserState;
  c12_u_u = c12_u_hoistedGlobal;
  c12_v_y = NULL;
  sf_mex_assign(&c12_v_y, sf_mex_create("y", &c12_u_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 20, c12_v_y);
  c12_v_hoistedGlobal = chartInstance->c12_temporalCounter_i2;
  c12_v_u = c12_v_hoistedGlobal;
  c12_w_y = NULL;
  sf_mex_assign(&c12_w_y, sf_mex_create("y", &c12_v_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 21, c12_w_y);
  c12_w_hoistedGlobal = chartInstance->c12_temporalCounter_i1;
  c12_w_u = c12_w_hoistedGlobal;
  c12_x_y = NULL;
  sf_mex_assign(&c12_x_y, sf_mex_create("y", &c12_w_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_y, 22, c12_x_y);
  sf_mex_assign(&c12_st, c12_y, false);
  return c12_st;
}

static void set_sim_state_c12_AllinOne(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_st)
{
  const mxArray *c12_u;
  c12_u = sf_mex_dup(c12_st);
  *chartInstance->c12_CoffeeAmount = c12_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 0)), "CoffeeAmount");
  *chartInstance->c12_MilkAmount = c12_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 1)), "MilkAmount");
  *chartInstance->c12_NextStep = c12_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 2)), "NextStep");
  *chartInstance->c12_SugarAmount = c12_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 3)), "SugarAmount");
  *chartInstance->c12_WaterAmount = c12_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 4)), "WaterAmount");
  chartInstance->c12_CoffeeRecipe = c12_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 5)), "CoffeeRecipe");
  chartInstance->c12_MilkRecipe = c12_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 6)), "MilkRecipe");
  chartInstance->c12_SugarRecipe = c12_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 7)), "SugarRecipe");
  chartInstance->c12_WaterRecipe = c12_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 8)), "WaterRecipe");
  *chartInstance->c12_GetCupEvent = c12_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 9)), "GetCupEvent");
  chartInstance->c12_GetCupEventEventCounter = c12_b_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 10)),
     "GetCupEventEventCounter");
  chartInstance->c12_is_active_c12_AllinOne = c12_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 11)),
     "is_active_c12_AllinOne");
  chartInstance->c12_is_active_CoffeeDoserState = c12_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 12)),
     "is_active_CoffeeDoserState");
  chartInstance->c12_is_active_SugarDoserState = c12_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 13)),
     "is_active_SugarDoserState");
  chartInstance->c12_is_active_WaterState = c12_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 14)), "is_active_WaterState");
  chartInstance->c12_is_active_MilkDoserState = c12_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 15)),
     "is_active_MilkDoserState");
  chartInstance->c12_is_c12_AllinOne = c12_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 16)), "is_c12_AllinOne");
  chartInstance->c12_is_CoffeeDoserState = c12_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 17)), "is_CoffeeDoserState");
  chartInstance->c12_is_SugarDoserState = c12_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 18)), "is_SugarDoserState");
  chartInstance->c12_is_WaterState = c12_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 19)), "is_WaterState");
  chartInstance->c12_is_MilkDoserState = c12_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 20)), "is_MilkDoserState");
  chartInstance->c12_temporalCounter_i2 = c12_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 21)), "temporalCounter_i2");
  chartInstance->c12_temporalCounter_i1 = c12_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 22)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c12_setSimStateSideEffectsInfo,
                c12_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c12_u, 23)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c12_u);
  chartInstance->c12_doSetSimStateSideEffects = 1U;
  c12_update_debugger_state_c12_AllinOne(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void c12_set_sim_state_side_effects_c12_AllinOne
  (SFc12_AllinOneInstanceStruct *chartInstance)
{
  if (chartInstance->c12_doSetSimStateSideEffects != 0) {
    if (chartInstance->c12_is_c12_AllinOne == c12_IN_GetCup) {
      chartInstance->c12_tp_GetCup = 1U;
      if (sf_mex_sub(chartInstance->c12_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c12_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c12_tp_GetCup = 0U;
    }

    if (chartInstance->c12_is_c12_AllinOne == c12_IN_Init) {
      chartInstance->c12_tp_Init = 1U;
    } else {
      chartInstance->c12_tp_Init = 0U;
    }

    if (chartInstance->c12_is_c12_AllinOne == c12_IN_Step1) {
      chartInstance->c12_tp_Step1 = 1U;
      if (sf_mex_sub(chartInstance->c12_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 4) == 0.0) {
        chartInstance->c12_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c12_tp_Step1 = 0U;
    }

    if (chartInstance->c12_is_c12_AllinOne == c12_IN_Step2) {
      chartInstance->c12_tp_Step2 = 1U;
      if (sf_mex_sub(chartInstance->c12_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c12_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c12_tp_Step2 = 0U;
    }

    if (chartInstance->c12_is_c12_AllinOne == c12_IN_TakeOut) {
      chartInstance->c12_tp_TakeOut = 1U;
    } else {
      chartInstance->c12_tp_TakeOut = 0U;
    }

    if (chartInstance->c12_is_c12_AllinOne == c12_IN_error) {
      chartInstance->c12_tp_error = 1U;
    } else {
      chartInstance->c12_tp_error = 0U;
    }

    if (chartInstance->c12_is_c12_AllinOne == c12_IN_prepare_CoffeeLatte) {
      chartInstance->c12_tp_prepare_CoffeeLatte = 1U;
    } else {
      chartInstance->c12_tp_prepare_CoffeeLatte = 0U;
    }

    if (chartInstance->c12_is_c12_AllinOne == c12_IN_working_AmerricanCoffee) {
      chartInstance->c12_tp_working_AmerricanCoffee = 1U;
    } else {
      chartInstance->c12_tp_working_AmerricanCoffee = 0U;
    }

    if (chartInstance->c12_is_c12_AllinOne == c12_IN_working_Cappuccino) {
      chartInstance->c12_tp_working_Cappuccino = 1U;
    } else {
      chartInstance->c12_tp_working_Cappuccino = 0U;
    }

    if (chartInstance->c12_is_c12_AllinOne == c12_IN_working_Coffee) {
      chartInstance->c12_tp_working_Coffee = 1U;
      if (sf_mex_sub(chartInstance->c12_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 11) == 0.0) {
        chartInstance->c12_temporalCounter_i2 = 0U;
      }
    } else {
      chartInstance->c12_tp_working_Coffee = 0U;
    }

    if (chartInstance->c12_is_active_WaterState == 1U) {
      chartInstance->c12_tp_WaterState = 1U;
    } else {
      chartInstance->c12_tp_WaterState = 0U;
    }

    if (chartInstance->c12_is_WaterState == c12_IN_Finished) {
      chartInstance->c12_tp_Finished = 1U;
    } else {
      chartInstance->c12_tp_Finished = 0U;
    }

    if (chartInstance->c12_is_WaterState == c12_IN_Working) {
      chartInstance->c12_tp_Working = 1U;
      if (sf_mex_sub(chartInstance->c12_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 14) == 0.0) {
        chartInstance->c12_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c12_tp_Working = 0U;
    }

    if (chartInstance->c12_is_active_SugarDoserState == 1U) {
      chartInstance->c12_tp_SugarDoserState = 1U;
    } else {
      chartInstance->c12_tp_SugarDoserState = 0U;
    }

    if (chartInstance->c12_is_SugarDoserState == c12_IN_Finished) {
      chartInstance->c12_b_tp_Finished = 1U;
    } else {
      chartInstance->c12_b_tp_Finished = 0U;
    }

    if (chartInstance->c12_is_SugarDoserState == c12_IN_Working) {
      chartInstance->c12_b_tp_Working = 1U;
    } else {
      chartInstance->c12_b_tp_Working = 0U;
    }

    if (chartInstance->c12_is_active_CoffeeDoserState == 1U) {
      chartInstance->c12_tp_CoffeeDoserState = 1U;
    } else {
      chartInstance->c12_tp_CoffeeDoserState = 0U;
    }

    if (chartInstance->c12_is_CoffeeDoserState == c12_IN_Finished) {
      chartInstance->c12_c_tp_Finished = 1U;
    } else {
      chartInstance->c12_c_tp_Finished = 0U;
    }

    if (chartInstance->c12_is_CoffeeDoserState == c12_IN_Working) {
      chartInstance->c12_c_tp_Working = 1U;
    } else {
      chartInstance->c12_c_tp_Working = 0U;
    }

    if (chartInstance->c12_is_active_MilkDoserState == 1U) {
      chartInstance->c12_tp_MilkDoserState = 1U;
    } else {
      chartInstance->c12_tp_MilkDoserState = 0U;
    }

    if (chartInstance->c12_is_MilkDoserState == c12_IN_Finished) {
      chartInstance->c12_d_tp_Finished = 1U;
    } else {
      chartInstance->c12_d_tp_Finished = 0U;
    }

    if (chartInstance->c12_is_MilkDoserState == c12_IN_Working) {
      chartInstance->c12_d_tp_Working = 1U;
    } else {
      chartInstance->c12_d_tp_Working = 0U;
    }

    chartInstance->c12_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c12_AllinOne(SFc12_AllinOneInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c12_setSimStateSideEffectsInfo);
}

static void sf_gateway_c12_AllinOne(SFc12_AllinOneInstanceStruct *chartInstance)
{
  int32_T c12_inputEventFiredFlag;
  c12_set_sim_state_side_effects_c12_AllinOne(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c12_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_CoffeeRemain, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_MilkRemain, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_SugarRemain, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_CoffeeAmount, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_MilkAmount, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_SugarAmount, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_WaterAmount, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_NextStep, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_WaterRemain, 8U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_WaterTemp, 9U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c12_CupRemain, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_CoffeeRecipe, 11U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_MilkRecipe, 12U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_SugarRecipe, 13U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c12_WaterRecipe, 14U);
  c12_inputEventFiredFlag = 0;
  if (*chartInstance->c12_Tick == 1) {
    c12_inputEventFiredFlag = 1;
    if (chartInstance->c12_temporalCounter_i1 < MAX_uint32_T) {
      chartInstance->c12_temporalCounter_i1++;
    }

    if (chartInstance->c12_temporalCounter_i2 < 16383U) {
      chartInstance->c12_temporalCounter_i2++;
    }

    chartInstance->c12_sfEvent = c12_event_Tick;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_Tick,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_Tick,
                 chartInstance->c12_sfEvent);
  }

  if (*chartInstance->c12_AmericanCoffee == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_AmericanCoffee;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_AmericanCoffee,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_AmericanCoffee,
                 chartInstance->c12_sfEvent);
  }

  if (*chartInstance->c12_CoffeeLatte == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_CoffeeLatte;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_CoffeeLatte,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_CoffeeLatte,
                 chartInstance->c12_sfEvent);
  }

  if (*chartInstance->c12_Cappuccino == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_Cappuccino;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_Cappuccino,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_Cappuccino,
                 chartInstance->c12_sfEvent);
  }

  if (*chartInstance->c12_StepEvent == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_StepEvent;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_StepEvent,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_StepEvent,
                 chartInstance->c12_sfEvent);
  }

  if (*chartInstance->c12_FeedFinishEvent == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_FeedFinishEvent;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_FeedFinishEvent,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_FeedFinishEvent,
                 chartInstance->c12_sfEvent);
  }

  if (*chartInstance->c12_MixFinishEvent == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_MixFinishEvent;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_MixFinishEvent,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_MixFinishEvent,
                 chartInstance->c12_sfEvent);
  }

  if (*chartInstance->c12_SugarDoserEvent == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_SugarDoserEvent;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_SugarDoserEvent,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_SugarDoserEvent,
                 chartInstance->c12_sfEvent);
  }

  if (*chartInstance->c12_MilkDoserEvent == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_MilkDoserEvent;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_MilkDoserEvent,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_MilkDoserEvent,
                 chartInstance->c12_sfEvent);
  }

  if (*chartInstance->c12_CoffeeDoserEvent == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_CoffeeDoserEvent;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_CoffeeDoserEvent,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_CoffeeDoserEvent,
                 chartInstance->c12_sfEvent);
  }

  if (*chartInstance->c12_TakeOutEvent == 1) {
    c12_inputEventFiredFlag = 1;
    chartInstance->c12_sfEvent = c12_event_TakeOutEvent;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c12_event_TakeOutEvent,
                 chartInstance->c12_sfEvent);
    c12_chartstep_c12_AllinOne(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c12_event_TakeOutEvent,
                 chartInstance->c12_sfEvent);
  }

  if (c12_inputEventFiredFlag != 0) {
    if (chartInstance->c12_GetCupEventEventCounter > 0U) {
      *chartInstance->c12_GetCupEvent = !*chartInstance->c12_GetCupEvent;
      chartInstance->c12_GetCupEventEventCounter--;
    }
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_AllinOneMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c12_AllinOne(SFc12_AllinOneInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c12_chartstep_c12_AllinOne(SFc12_AllinOneInstanceStruct
  *chartInstance)
{
  boolean_T c12_out;
  boolean_T c12_temp;
  boolean_T c12_b_out;
  boolean_T c12_c_out;
  boolean_T c12_d_out;
  boolean_T c12_e_out;
  boolean_T c12_f_out;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c12_sfEvent);
  if (chartInstance->c12_is_active_c12_AllinOne == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 7U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_active_c12_AllinOne = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c12_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_c12_AllinOne = c12_IN_Init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c12_sfEvent);
    chartInstance->c12_tp_Init = 1U;
    *chartInstance->c12_CoffeeAmount = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_CoffeeAmount, 3U);
    *chartInstance->c12_MilkAmount = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_MilkAmount, 4U);
    *chartInstance->c12_SugarAmount = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_SugarAmount, 5U);
    *chartInstance->c12_WaterAmount = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_WaterAmount, 6U);
    *chartInstance->c12_NextStep = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_NextStep, 7U);
  } else {
    switch (chartInstance->c12_is_c12_AllinOne) {
     case c12_IN_GetCup:
      CV_CHART_EVAL(7, 0, 1);
      c12_GetCup(chartInstance);
      break;

     case c12_IN_Init:
      CV_CHART_EVAL(7, 0, 2);
      c12_Init(chartInstance);
      break;

     case c12_IN_Step1:
      CV_CHART_EVAL(7, 0, 3);
      c12_Step1(chartInstance);
      break;

     case c12_IN_Step2:
      CV_CHART_EVAL(7, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 25U,
                   chartInstance->c12_sfEvent);
      c12_out = (CV_TRANSITION_EVAL(25U, (int32_T)_SFD_CCP_CALL(25U, 0,
        chartInstance->c12_sfEvent == c12_event_StepEvent != 0U,
        chartInstance->c12_sfEvent)) != 0);
      if (c12_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 25U, chartInstance->c12_sfEvent);
        chartInstance->c12_tp_Step2 = 0U;
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 3U,
                     chartInstance->c12_sfEvent);
        *chartInstance->c12_NextStep = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_NextStep, 7U);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c12_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c12_sfEvent);
        chartInstance->c12_is_c12_AllinOne = c12_IN_TakeOut;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c12_sfEvent);
        chartInstance->c12_tp_TakeOut = 1U;
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 44U,
                     chartInstance->c12_sfEvent);
        c12_temp = (_SFD_CCP_CALL(44U, 0, chartInstance->c12_sfEvent ==
          c12_event_Tick != 0U, chartInstance->c12_sfEvent) != 0);
        if (c12_temp) {
          c12_temp = (_SFD_CCP_CALL(44U, 1,
            chartInstance->c12_temporalCounter_i1 >= 10000U != 0U,
            chartInstance->c12_sfEvent) != 0);
        }

        c12_b_out = (CV_TRANSITION_EVAL(44U, (int32_T)c12_temp) != 0);
        if (c12_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 44U, chartInstance->c12_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, chartInstance->c12_sfEvent);
          chartInstance->c12_tp_Step2 = 0U;
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 3U,
                       chartInstance->c12_sfEvent);
          *chartInstance->c12_NextStep = 0.0;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c12_NextStep, 7U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c12_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c12_sfEvent);
          chartInstance->c12_is_c12_AllinOne = c12_IN_error;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c12_sfEvent);
          chartInstance->c12_tp_error = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                       chartInstance->c12_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c12_sfEvent);
      break;

     case c12_IN_TakeOut:
      CV_CHART_EVAL(7, 0, 5);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 46U,
                   chartInstance->c12_sfEvent);
      c12_c_out = (CV_TRANSITION_EVAL(46U, (int32_T)_SFD_CCP_CALL(46U, 0,
        chartInstance->c12_sfEvent == c12_event_TakeOutEvent != 0U,
        chartInstance->c12_sfEvent)) != 0);
      if (c12_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 46U, chartInstance->c12_sfEvent);
        chartInstance->c12_tp_TakeOut = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c12_sfEvent);
        chartInstance->c12_is_c12_AllinOne = c12_IN_Init;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c12_sfEvent);
        chartInstance->c12_tp_Init = 1U;
        *chartInstance->c12_CoffeeAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_CoffeeAmount, 3U);
        *chartInstance->c12_MilkAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_MilkAmount, 4U);
        *chartInstance->c12_SugarAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_SugarAmount, 5U);
        *chartInstance->c12_WaterAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_WaterAmount, 6U);
        *chartInstance->c12_NextStep = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_NextStep, 7U);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c12_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c12_sfEvent);
      break;

     case c12_IN_error:
      CV_CHART_EVAL(7, 0, 6);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   chartInstance->c12_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c12_sfEvent);
      break;

     case c12_IN_prepare_CoffeeLatte:
      CV_CHART_EVAL(7, 0, 7);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   chartInstance->c12_sfEvent);
      c12_d_out = (CV_TRANSITION_EVAL(5U, (int32_T)_SFD_CCP_CALL(5U, 0,
        c12_checkall(chartInstance, *chartInstance->c12_WaterRemain,
                     chartInstance->c12_WaterRecipe,
                     *chartInstance->c12_MilkRemain,
                     chartInstance->c12_MilkRecipe,
                     *chartInstance->c12_SugarRemain,
                     chartInstance->c12_SugarRecipe,
                     *chartInstance->c12_CoffeeRemain,
                     chartInstance->c12_CoffeeRecipe, (real_T)
                     *chartInstance->c12_CupRemain,
                     *chartInstance->c12_WaterTemp) != 0U,
        chartInstance->c12_sfEvent)) != 0);
      if (c12_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c12_sfEvent);
        chartInstance->c12_tp_prepare_CoffeeLatte = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c12_sfEvent);
        chartInstance->c12_is_c12_AllinOne = c12_IN_GetCup;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c12_sfEvent);
        chartInstance->c12_temporalCounter_i1 = 0U;
        chartInstance->c12_tp_GetCup = 1U;
        chartInstance->c12_GetCupEventEventCounter++;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c12_sfEvent);
        chartInstance->c12_tp_prepare_CoffeeLatte = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c12_sfEvent);
        chartInstance->c12_is_c12_AllinOne = c12_IN_Init;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c12_sfEvent);
        chartInstance->c12_tp_Init = 1U;
        *chartInstance->c12_CoffeeAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_CoffeeAmount, 3U);
        *chartInstance->c12_MilkAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_MilkAmount, 4U);
        *chartInstance->c12_SugarAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_SugarAmount, 5U);
        *chartInstance->c12_WaterAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_WaterAmount, 6U);
        *chartInstance->c12_NextStep = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_NextStep, 7U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c12_sfEvent);
      break;

     case c12_IN_working_AmerricanCoffee:
      CV_CHART_EVAL(7, 0, 8);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 29U,
                   chartInstance->c12_sfEvent);
      c12_e_out = (CV_TRANSITION_EVAL(29U, (int32_T)_SFD_CCP_CALL(29U, 0,
        c12_checkall(chartInstance, *chartInstance->c12_WaterRemain,
                     chartInstance->c12_WaterRecipe,
                     *chartInstance->c12_MilkRemain,
                     chartInstance->c12_MilkRecipe,
                     *chartInstance->c12_SugarRemain,
                     chartInstance->c12_SugarRecipe,
                     *chartInstance->c12_CoffeeRemain,
                     chartInstance->c12_CoffeeRecipe, (real_T)
                     *chartInstance->c12_CupRemain,
                     *chartInstance->c12_WaterTemp) != 0U,
        chartInstance->c12_sfEvent)) != 0);
      if (c12_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 29U, chartInstance->c12_sfEvent);
        chartInstance->c12_tp_working_AmerricanCoffee = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c12_sfEvent);
        chartInstance->c12_is_c12_AllinOne = c12_IN_GetCup;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c12_sfEvent);
        chartInstance->c12_temporalCounter_i1 = 0U;
        chartInstance->c12_tp_GetCup = 1U;
        chartInstance->c12_GetCupEventEventCounter++;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 30U, chartInstance->c12_sfEvent);
        chartInstance->c12_tp_working_AmerricanCoffee = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c12_sfEvent);
        chartInstance->c12_is_c12_AllinOne = c12_IN_Init;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c12_sfEvent);
        chartInstance->c12_tp_Init = 1U;
        *chartInstance->c12_CoffeeAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_CoffeeAmount, 3U);
        *chartInstance->c12_MilkAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_MilkAmount, 4U);
        *chartInstance->c12_SugarAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_SugarAmount, 5U);
        *chartInstance->c12_WaterAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_WaterAmount, 6U);
        *chartInstance->c12_NextStep = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_NextStep, 7U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c12_sfEvent);
      break;

     case c12_IN_working_Cappuccino:
      CV_CHART_EVAL(7, 0, 9);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 28U,
                   chartInstance->c12_sfEvent);
      c12_f_out = (CV_TRANSITION_EVAL(28U, (int32_T)_SFD_CCP_CALL(28U, 0,
        c12_checkall(chartInstance, *chartInstance->c12_WaterRemain,
                     chartInstance->c12_WaterRecipe,
                     *chartInstance->c12_MilkRemain,
                     chartInstance->c12_MilkRecipe,
                     *chartInstance->c12_SugarRemain,
                     chartInstance->c12_SugarRecipe,
                     *chartInstance->c12_CoffeeRemain,
                     chartInstance->c12_CoffeeRecipe, (real_T)
                     *chartInstance->c12_CupRemain,
                     *chartInstance->c12_WaterTemp) != 0U,
        chartInstance->c12_sfEvent)) != 0);
      if (c12_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 28U, chartInstance->c12_sfEvent);
        chartInstance->c12_tp_working_Cappuccino = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c12_sfEvent);
        chartInstance->c12_is_c12_AllinOne = c12_IN_GetCup;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c12_sfEvent);
        chartInstance->c12_temporalCounter_i1 = 0U;
        chartInstance->c12_tp_GetCup = 1U;
        chartInstance->c12_GetCupEventEventCounter++;
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 31U, chartInstance->c12_sfEvent);
        chartInstance->c12_tp_working_Cappuccino = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c12_sfEvent);
        chartInstance->c12_is_c12_AllinOne = c12_IN_Init;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c12_sfEvent);
        chartInstance->c12_tp_Init = 1U;
        *chartInstance->c12_CoffeeAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_CoffeeAmount, 3U);
        *chartInstance->c12_MilkAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_MilkAmount, 4U);
        *chartInstance->c12_SugarAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_SugarAmount, 5U);
        *chartInstance->c12_WaterAmount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_WaterAmount, 6U);
        *chartInstance->c12_NextStep = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c12_NextStep, 7U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c12_sfEvent);
      break;

     case c12_IN_working_Coffee:
      CV_CHART_EVAL(7, 0, 10);
      c12_working_Coffee(chartInstance);
      break;

     default:
      CV_CHART_EVAL(7, 0, 0);
      chartInstance->c12_is_c12_AllinOne = c12_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c12_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c12_sfEvent);
}

static void initSimStructsc12_AllinOne(SFc12_AllinOneInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c12_Init(SFc12_AllinOneInstanceStruct *chartInstance)
{
  boolean_T c12_out;
  boolean_T c12_b_out;
  boolean_T c12_c_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c12_sfEvent);
  c12_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
    chartInstance->c12_sfEvent == c12_event_AmericanCoffee != 0U,
    chartInstance->c12_sfEvent)) != 0);
  if (c12_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c12_sfEvent);
    chartInstance->c12_tp_Init = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_c12_AllinOne = c12_IN_prepare_CoffeeLatte;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c12_sfEvent);
    chartInstance->c12_tp_prepare_CoffeeLatte = 1U;
    chartInstance->c12_CoffeeRecipe = 10.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c12_CoffeeRecipe, 11U);
    chartInstance->c12_MilkRecipe = 80.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c12_MilkRecipe, 12U);
    chartInstance->c12_SugarRecipe = 10.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c12_SugarRecipe, 13U);
    chartInstance->c12_WaterRecipe = 40.0;
    _SFD_DATA_RANGE_CHECK(chartInstance->c12_WaterRecipe, 14U);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 26U,
                 chartInstance->c12_sfEvent);
    c12_b_out = (CV_TRANSITION_EVAL(26U, (int32_T)_SFD_CCP_CALL(26U, 0,
      chartInstance->c12_sfEvent == c12_event_CoffeeLatte != 0U,
      chartInstance->c12_sfEvent)) != 0);
    if (c12_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 26U, chartInstance->c12_sfEvent);
      chartInstance->c12_tp_Init = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c12_sfEvent);
      chartInstance->c12_is_c12_AllinOne = c12_IN_working_Cappuccino;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c12_sfEvent);
      chartInstance->c12_tp_working_Cappuccino = 1U;
      chartInstance->c12_CoffeeRecipe = 10.0;
      _SFD_DATA_RANGE_CHECK(chartInstance->c12_CoffeeRecipe, 11U);
      chartInstance->c12_MilkRecipe = 100.0;
      _SFD_DATA_RANGE_CHECK(chartInstance->c12_MilkRecipe, 12U);
      chartInstance->c12_SugarRecipe = 10.0;
      _SFD_DATA_RANGE_CHECK(chartInstance->c12_SugarRecipe, 13U);
      chartInstance->c12_WaterRecipe = 20.0;
      _SFD_DATA_RANGE_CHECK(chartInstance->c12_WaterRecipe, 14U);
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 27U,
                   chartInstance->c12_sfEvent);
      c12_c_out = (CV_TRANSITION_EVAL(27U, (int32_T)_SFD_CCP_CALL(27U, 0,
        chartInstance->c12_sfEvent == c12_event_Cappuccino != 0U,
        chartInstance->c12_sfEvent)) != 0);
      if (c12_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 27U, chartInstance->c12_sfEvent);
        chartInstance->c12_tp_Init = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c12_sfEvent);
        chartInstance->c12_is_c12_AllinOne = c12_IN_working_AmerricanCoffee;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c12_sfEvent);
        chartInstance->c12_tp_working_AmerricanCoffee = 1U;
        chartInstance->c12_CoffeeRecipe = 10.0;
        _SFD_DATA_RANGE_CHECK(chartInstance->c12_CoffeeRecipe, 11U);
        chartInstance->c12_MilkRecipe = 60.0;
        _SFD_DATA_RANGE_CHECK(chartInstance->c12_MilkRecipe, 12U);
        chartInstance->c12_SugarRecipe = 10.0;
        _SFD_DATA_RANGE_CHECK(chartInstance->c12_SugarRecipe, 13U);
        chartInstance->c12_WaterRecipe = 60.0;
        _SFD_DATA_RANGE_CHECK(chartInstance->c12_WaterRecipe, 14U);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c12_sfEvent);
      }
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c12_sfEvent);
}

static void c12_GetCup(SFc12_AllinOneInstanceStruct *chartInstance)
{
  boolean_T c12_out;
  boolean_T c12_temp;
  boolean_T c12_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 24U, chartInstance->c12_sfEvent);
  c12_out = (CV_TRANSITION_EVAL(24U, (int32_T)_SFD_CCP_CALL(24U, 0,
    chartInstance->c12_sfEvent == c12_event_FeedFinishEvent != 0U,
    chartInstance->c12_sfEvent)) != 0);
  if (c12_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 24U, chartInstance->c12_sfEvent);
    chartInstance->c12_tp_GetCup = 0U;
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 0U, chartInstance->c12_sfEvent);
    chartInstance->c12_GetCupEventEventCounter++;
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c12_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_c12_AllinOne = c12_IN_Step1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c12_sfEvent);
    chartInstance->c12_temporalCounter_i1 = 0U;
    chartInstance->c12_tp_Step1 = 1U;
    *chartInstance->c12_NextStep = 50.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_NextStep, 7U);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 42U,
                 chartInstance->c12_sfEvent);
    c12_temp = (_SFD_CCP_CALL(42U, 0, chartInstance->c12_sfEvent ==
      c12_event_Tick != 0U, chartInstance->c12_sfEvent) != 0);
    if (c12_temp) {
      c12_temp = (_SFD_CCP_CALL(42U, 1, chartInstance->c12_temporalCounter_i1 >=
        10000U != 0U, chartInstance->c12_sfEvent) != 0);
    }

    c12_b_out = (CV_TRANSITION_EVAL(42U, (int32_T)c12_temp) != 0);
    if (c12_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 42U, chartInstance->c12_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, chartInstance->c12_sfEvent);
      chartInstance->c12_tp_GetCup = 0U;
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 0U, chartInstance->c12_sfEvent);
      chartInstance->c12_GetCupEventEventCounter++;
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c12_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c12_sfEvent);
      chartInstance->c12_is_c12_AllinOne = c12_IN_error;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c12_sfEvent);
      chartInstance->c12_tp_error = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c12_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c12_sfEvent);
}

static void c12_working_Coffee(SFc12_AllinOneInstanceStruct *chartInstance)
{
  boolean_T c12_out;
  boolean_T c12_temp;
  boolean_T c12_b_out;
  boolean_T c12_b_temp;
  uint32_T c12_u0;
  boolean_T c12_c_out;
  boolean_T c12_d_out;
  boolean_T c12_e_out;
  boolean_T c12_f_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U, chartInstance->c12_sfEvent);
  c12_out = (CV_TRANSITION_EVAL(19U, (int32_T)_SFD_CCP_CALL(19U, 0,
    chartInstance->c12_sfEvent == c12_event_MixFinishEvent != 0U,
    chartInstance->c12_sfEvent)) != 0);
  if (c12_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c12_sfEvent);
    c12_exit_internal_working_Coffee(chartInstance);
    chartInstance->c12_tp_working_Coffee = 0U;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_c12_AllinOne = c12_IN_Step2;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c12_sfEvent);
    chartInstance->c12_temporalCounter_i1 = 0U;
    chartInstance->c12_tp_Step2 = 1U;
    *chartInstance->c12_NextStep = 50.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_NextStep, 7U);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 43U,
                 chartInstance->c12_sfEvent);
    c12_temp = (_SFD_CCP_CALL(43U, 0, chartInstance->c12_sfEvent ==
      c12_event_Tick != 0U, chartInstance->c12_sfEvent) != 0);
    if (c12_temp) {
      c12_temp = (_SFD_CCP_CALL(43U, 1, chartInstance->c12_temporalCounter_i2 >=
        10000 != 0U, chartInstance->c12_sfEvent) != 0);
    }

    c12_b_out = (CV_TRANSITION_EVAL(43U, (int32_T)c12_temp) != 0);
    if (c12_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 43U, chartInstance->c12_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, chartInstance->c12_sfEvent);
      c12_exit_internal_working_Coffee(chartInstance);
      chartInstance->c12_tp_working_Coffee = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c12_sfEvent);
      chartInstance->c12_is_c12_AllinOne = c12_IN_error;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c12_sfEvent);
      chartInstance->c12_tp_error = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                   chartInstance->c12_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U,
                   chartInstance->c12_sfEvent);
      switch (chartInstance->c12_is_WaterState) {
       case c12_IN_Finished:
        CV_STATE_EVAL(20, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 21U,
                     chartInstance->c12_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 21U, chartInstance->c12_sfEvent);
        break;

       case c12_IN_Working:
        CV_STATE_EVAL(20, 0, 2);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 37U,
                     chartInstance->c12_sfEvent);
        c12_b_temp = (_SFD_CCP_CALL(37U, 0, chartInstance->c12_sfEvent ==
          c12_event_Tick != 0U, chartInstance->c12_sfEvent) != 0);
        if (c12_b_temp) {
          c12_u0 = _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
            chartInstance->c12_WaterRecipe, 32U, 37U);
          c12_b_temp = (_SFD_CCP_CALL(37U, 1,
            chartInstance->c12_temporalCounter_i1 >= c12_u0 != 0U,
            chartInstance->c12_sfEvent) != 0);
        }

        c12_c_out = (CV_TRANSITION_EVAL(37U, (int32_T)c12_b_temp) != 0);
        if (c12_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 37U, chartInstance->c12_sfEvent);
          chartInstance->c12_tp_Working = 0U;
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 22U,
                       chartInstance->c12_sfEvent);
          *chartInstance->c12_WaterAmount = 0.0;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c12_WaterAmount, 6U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c12_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c12_sfEvent);
          chartInstance->c12_is_WaterState = c12_IN_Finished;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 21U, chartInstance->c12_sfEvent);
          chartInstance->c12_tp_Finished = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 22U,
                       chartInstance->c12_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c12_sfEvent);
        break;

       default:
        CV_STATE_EVAL(20, 0, 0);
        chartInstance->c12_is_WaterState = c12_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c12_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c12_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U,
                   chartInstance->c12_sfEvent);
      switch (chartInstance->c12_is_SugarDoserState) {
       case c12_IN_Finished:
        CV_STATE_EVAL(17, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U,
                     chartInstance->c12_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c12_sfEvent);
        break;

       case c12_IN_Working:
        CV_STATE_EVAL(17, 0, 2);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 34U,
                     chartInstance->c12_sfEvent);
        c12_d_out = (CV_TRANSITION_EVAL(34U, (int32_T)_SFD_CCP_CALL(34U, 0,
          chartInstance->c12_sfEvent == c12_event_SugarDoserEvent != 0U,
          chartInstance->c12_sfEvent)) != 0);
        if (c12_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 34U, chartInstance->c12_sfEvent);
          chartInstance->c12_b_tp_Working = 0U;
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 19U,
                       chartInstance->c12_sfEvent);
          *chartInstance->c12_SugarAmount = 0.0;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c12_SugarAmount, 5U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c12_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c12_sfEvent);
          chartInstance->c12_is_SugarDoserState = c12_IN_Finished;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c12_sfEvent);
          chartInstance->c12_b_tp_Finished = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U,
                       chartInstance->c12_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c12_sfEvent);
        break;

       default:
        CV_STATE_EVAL(17, 0, 0);
        chartInstance->c12_is_SugarDoserState = c12_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c12_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c12_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                   chartInstance->c12_sfEvent);
      switch (chartInstance->c12_is_CoffeeDoserState) {
       case c12_IN_Finished:
        CV_STATE_EVAL(11, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                     chartInstance->c12_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c12_sfEvent);
        break;

       case c12_IN_Working:
        CV_STATE_EVAL(11, 0, 2);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 33U,
                     chartInstance->c12_sfEvent);
        c12_e_out = (CV_TRANSITION_EVAL(33U, (int32_T)_SFD_CCP_CALL(33U, 0,
          chartInstance->c12_sfEvent == c12_event_CoffeeDoserEvent != 0U,
          chartInstance->c12_sfEvent)) != 0);
        if (c12_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 33U, chartInstance->c12_sfEvent);
          chartInstance->c12_c_tp_Working = 0U;
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 13U,
                       chartInstance->c12_sfEvent);
          *chartInstance->c12_CoffeeAmount = 0.0;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c12_CoffeeAmount, 3U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c12_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c12_sfEvent);
          chartInstance->c12_is_CoffeeDoserState = c12_IN_Finished;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c12_sfEvent);
          chartInstance->c12_c_tp_Finished = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U,
                       chartInstance->c12_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c12_sfEvent);
        break;

       default:
        CV_STATE_EVAL(11, 0, 0);
        chartInstance->c12_is_CoffeeDoserState = c12_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c12_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c12_sfEvent);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                   chartInstance->c12_sfEvent);
      switch (chartInstance->c12_is_MilkDoserState) {
       case c12_IN_Finished:
        CV_STATE_EVAL(14, 0, 1);
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                     chartInstance->c12_sfEvent);
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c12_sfEvent);
        break;

       case c12_IN_Working:
        CV_STATE_EVAL(14, 0, 2);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 38U,
                     chartInstance->c12_sfEvent);
        c12_f_out = (CV_TRANSITION_EVAL(38U, (int32_T)_SFD_CCP_CALL(38U, 0,
          chartInstance->c12_sfEvent == c12_event_MilkDoserEvent != 0U,
          chartInstance->c12_sfEvent)) != 0);
        if (c12_f_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 38U, chartInstance->c12_sfEvent);
          chartInstance->c12_d_tp_Working = 0U;
          _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 16U,
                       chartInstance->c12_sfEvent);
          *chartInstance->c12_MilkAmount = 0.0;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c12_MilkAmount, 4U);
          _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c12_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c12_sfEvent);
          chartInstance->c12_is_MilkDoserState = c12_IN_Finished;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c12_sfEvent);
          chartInstance->c12_d_tp_Finished = 1U;
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U,
                       chartInstance->c12_sfEvent);
        }

        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c12_sfEvent);
        break;

       default:
        CV_STATE_EVAL(14, 0, 0);
        chartInstance->c12_is_MilkDoserState = c12_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c12_sfEvent);
        break;
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c12_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c12_sfEvent);
}

static void c12_exit_internal_working_Coffee(SFc12_AllinOneInstanceStruct
  *chartInstance)
{
  switch (chartInstance->c12_is_MilkDoserState) {
   case c12_IN_Finished:
    CV_STATE_EVAL(14, 1, 1);
    chartInstance->c12_d_tp_Finished = 0U;
    chartInstance->c12_is_MilkDoserState = c12_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c12_sfEvent);
    break;

   case c12_IN_Working:
    CV_STATE_EVAL(14, 1, 2);
    chartInstance->c12_d_tp_Working = 0U;
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 16U, chartInstance->c12_sfEvent);
    *chartInstance->c12_MilkAmount = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_MilkAmount, 4U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_MilkDoserState = c12_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c12_sfEvent);
    break;

   default:
    CV_STATE_EVAL(14, 1, 0);
    chartInstance->c12_is_MilkDoserState = c12_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c12_sfEvent);
    break;
  }

  chartInstance->c12_tp_MilkDoserState = 0U;
  chartInstance->c12_is_active_MilkDoserState = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c12_sfEvent);
  switch (chartInstance->c12_is_CoffeeDoserState) {
   case c12_IN_Finished:
    CV_STATE_EVAL(11, 1, 1);
    chartInstance->c12_c_tp_Finished = 0U;
    chartInstance->c12_is_CoffeeDoserState = c12_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c12_sfEvent);
    break;

   case c12_IN_Working:
    CV_STATE_EVAL(11, 1, 2);
    chartInstance->c12_c_tp_Working = 0U;
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 13U, chartInstance->c12_sfEvent);
    *chartInstance->c12_CoffeeAmount = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_CoffeeAmount, 3U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_CoffeeDoserState = c12_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c12_sfEvent);
    break;

   default:
    CV_STATE_EVAL(11, 1, 0);
    chartInstance->c12_is_CoffeeDoserState = c12_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c12_sfEvent);
    break;
  }

  chartInstance->c12_tp_CoffeeDoserState = 0U;
  chartInstance->c12_is_active_CoffeeDoserState = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c12_sfEvent);
  switch (chartInstance->c12_is_SugarDoserState) {
   case c12_IN_Finished:
    CV_STATE_EVAL(17, 1, 1);
    chartInstance->c12_b_tp_Finished = 0U;
    chartInstance->c12_is_SugarDoserState = c12_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c12_sfEvent);
    break;

   case c12_IN_Working:
    CV_STATE_EVAL(17, 1, 2);
    chartInstance->c12_b_tp_Working = 0U;
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 19U, chartInstance->c12_sfEvent);
    *chartInstance->c12_SugarAmount = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_SugarAmount, 5U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_SugarDoserState = c12_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c12_sfEvent);
    break;

   default:
    CV_STATE_EVAL(17, 1, 0);
    chartInstance->c12_is_SugarDoserState = c12_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c12_sfEvent);
    break;
  }

  chartInstance->c12_tp_SugarDoserState = 0U;
  chartInstance->c12_is_active_SugarDoserState = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c12_sfEvent);
  switch (chartInstance->c12_is_WaterState) {
   case c12_IN_Finished:
    CV_STATE_EVAL(20, 1, 1);
    chartInstance->c12_tp_Finished = 0U;
    chartInstance->c12_is_WaterState = c12_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c12_sfEvent);
    break;

   case c12_IN_Working:
    CV_STATE_EVAL(20, 1, 2);
    chartInstance->c12_tp_Working = 0U;
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 22U, chartInstance->c12_sfEvent);
    *chartInstance->c12_WaterAmount = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_WaterAmount, 6U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 22U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_WaterState = c12_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 22U, chartInstance->c12_sfEvent);
    break;

   default:
    CV_STATE_EVAL(20, 1, 0);
    chartInstance->c12_is_WaterState = c12_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 21U, chartInstance->c12_sfEvent);
    break;
  }

  chartInstance->c12_tp_WaterState = 0U;
  chartInstance->c12_is_active_WaterState = 0U;
  _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c12_sfEvent);
}

static void c12_Step1(SFc12_AllinOneInstanceStruct *chartInstance)
{
  boolean_T c12_out;
  boolean_T c12_temp;
  boolean_T c12_b_out;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 40U, chartInstance->c12_sfEvent);
  c12_out = (CV_TRANSITION_EVAL(40U, (int32_T)_SFD_CCP_CALL(40U, 0,
    chartInstance->c12_sfEvent == c12_event_StepEvent != 0U,
    chartInstance->c12_sfEvent)) != 0);
  if (c12_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 40U, chartInstance->c12_sfEvent);
    chartInstance->c12_tp_Step1 = 0U;
    _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 2U, chartInstance->c12_sfEvent);
    *chartInstance->c12_NextStep = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_NextStep, 7U);
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c12_sfEvent);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_c12_AllinOne = c12_IN_working_Coffee;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c12_sfEvent);
    chartInstance->c12_temporalCounter_i2 = 0U;
    chartInstance->c12_tp_working_Coffee = 1U;
    chartInstance->c12_is_active_WaterState = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c12_sfEvent);
    chartInstance->c12_tp_WaterState = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 36U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_WaterState = c12_IN_Working;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 22U, chartInstance->c12_sfEvent);
    chartInstance->c12_temporalCounter_i1 = 0U;
    chartInstance->c12_tp_Working = 1U;
    *chartInstance->c12_WaterAmount = 1.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_WaterAmount, 6U);
    chartInstance->c12_is_active_SugarDoserState = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c12_sfEvent);
    chartInstance->c12_tp_SugarDoserState = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 35U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_SugarDoserState = c12_IN_Working;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c12_sfEvent);
    chartInstance->c12_b_tp_Working = 1U;
    *chartInstance->c12_SugarAmount = chartInstance->c12_SugarRecipe;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_SugarAmount, 5U);
    chartInstance->c12_is_active_CoffeeDoserState = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c12_sfEvent);
    chartInstance->c12_tp_CoffeeDoserState = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 32U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_CoffeeDoserState = c12_IN_Working;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c12_sfEvent);
    chartInstance->c12_c_tp_Working = 1U;
    *chartInstance->c12_CoffeeAmount = chartInstance->c12_CoffeeRecipe;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_CoffeeAmount, 3U);
    chartInstance->c12_is_active_MilkDoserState = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c12_sfEvent);
    chartInstance->c12_tp_MilkDoserState = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 39U, chartInstance->c12_sfEvent);
    chartInstance->c12_is_MilkDoserState = c12_IN_Working;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c12_sfEvent);
    chartInstance->c12_d_tp_Working = 1U;
    *chartInstance->c12_MilkAmount = chartInstance->c12_MilkRecipe;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c12_MilkAmount, 4U);
  } else {
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 41U,
                 chartInstance->c12_sfEvent);
    c12_temp = (_SFD_CCP_CALL(41U, 0, chartInstance->c12_sfEvent ==
      c12_event_Tick != 0U, chartInstance->c12_sfEvent) != 0);
    if (c12_temp) {
      c12_temp = (_SFD_CCP_CALL(41U, 1, chartInstance->c12_temporalCounter_i1 >=
        10000U != 0U, chartInstance->c12_sfEvent) != 0);
    }

    c12_b_out = (CV_TRANSITION_EVAL(41U, (int32_T)c12_temp) != 0);
    if (c12_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 41U, chartInstance->c12_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 45U, chartInstance->c12_sfEvent);
      chartInstance->c12_tp_Step1 = 0U;
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 2U, chartInstance->c12_sfEvent);
      *chartInstance->c12_NextStep = 0.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c12_NextStep, 7U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c12_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c12_sfEvent);
      chartInstance->c12_is_c12_AllinOne = c12_IN_error;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c12_sfEvent);
      chartInstance->c12_tp_error = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c12_sfEvent);
    }
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c12_sfEvent);
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber)
{
  (void)c12_machineNumber;
  (void)c12_chartNumber;
  (void)c12_instanceNumber;
}

const mxArray *sf_c12_AllinOne_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  sf_mex_assign(&c12_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c12_nameCaptureInfo;
}

static boolean_T c12_checkall(SFc12_AllinOneInstanceStruct *chartInstance,
  real_T c12_waterRemain, real_T c12_waterRecipe, real_T c12_milkRemain, real_T
  c12_milkRecipe, real_T c12_sugarRemain, real_T c12_sugarRecipe, real_T
  c12_coffeeRemain, real_T c12_coffeeRecipe, real_T c12_cupRemain, real_T
  c12_waterTemp)
{
  boolean_T c12_flg;
  boolean_T c12_out;
  boolean_T c12_b_out;
  boolean_T c12_c_out;
  boolean_T c12_d_out;
  boolean_T c12_e_out;
  boolean_T c12_f_out;
  _SFD_DATA_RANGE_CHECK(c12_waterRemain, 15U);
  _SFD_DATA_RANGE_CHECK(c12_waterRecipe, 16U);
  _SFD_DATA_RANGE_CHECK(c12_milkRemain, 17U);
  _SFD_DATA_RANGE_CHECK(c12_milkRecipe, 18U);
  _SFD_DATA_RANGE_CHECK(c12_sugarRemain, 19U);
  _SFD_DATA_RANGE_CHECK(c12_sugarRecipe, 20U);
  _SFD_DATA_RANGE_CHECK(c12_coffeeRemain, 21U);
  _SFD_DATA_RANGE_CHECK(c12_coffeeRecipe, 22U);
  _SFD_DATA_RANGE_CHECK(c12_cupRemain, 23U);
  _SFD_DATA_RANGE_CHECK(c12_waterTemp, 24U);
  _SFD_SET_DATA_VALUE_PTR(25U, &c12_flg);
  _SFD_SET_DATA_VALUE_PTR(24U, &c12_waterTemp);
  _SFD_SET_DATA_VALUE_PTR(23U, &c12_cupRemain);
  _SFD_SET_DATA_VALUE_PTR(22U, &c12_coffeeRecipe);
  _SFD_SET_DATA_VALUE_PTR(21U, &c12_coffeeRemain);
  _SFD_SET_DATA_VALUE_PTR(20U, &c12_sugarRecipe);
  _SFD_SET_DATA_VALUE_PTR(19U, &c12_sugarRemain);
  _SFD_SET_DATA_VALUE_PTR(18U, &c12_milkRecipe);
  _SFD_SET_DATA_VALUE_PTR(17U, &c12_milkRemain);
  _SFD_SET_DATA_VALUE_PTR(16U, &c12_waterRecipe);
  _SFD_SET_DATA_VALUE_PTR(15U, &c12_waterRemain);
  _SFD_CS_CALL(FUNCTION_ACTIVE_TAG, 5U, chartInstance->c12_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH(11U, 0U);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("waterRemain", &c12_waterRemain,
    c12_e_sf_marshallOut, c12_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("waterRecipe", &c12_waterRecipe,
    c12_e_sf_marshallOut, c12_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("milkRemain", &c12_milkRemain,
    c12_e_sf_marshallOut, c12_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("milkRecipe", &c12_milkRecipe,
    c12_e_sf_marshallOut, c12_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("sugarRemain", &c12_sugarRemain,
    c12_e_sf_marshallOut, c12_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("sugarRecipe", &c12_sugarRecipe,
    c12_e_sf_marshallOut, c12_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("coffeeRemain", &c12_coffeeRemain,
    c12_e_sf_marshallOut, c12_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("coffeeRecipe", &c12_coffeeRecipe,
    c12_e_sf_marshallOut, c12_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("cupRemain", &c12_cupRemain,
    c12_e_sf_marshallOut, c12_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("waterTemp", &c12_waterTemp,
    c12_e_sf_marshallOut, c12_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_IMPORTABLE("flg", &c12_flg, c12_f_sf_marshallOut,
    c12_f_sf_marshallIn);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c12_sfEvent);
  c12_flg = false;
  _SFD_DATA_RANGE_CHECK((real_T)c12_flg, 25U);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c12_sfEvent);
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c12_sfEvent);
  c12_out = (CV_TRANSITION_EVAL(3U, (int32_T)_SFD_CCP_CALL(3U, 0,
    CV_RELATIONAL_EVAL(5U, 3U, 0, c12_waterRemain, c12_waterRecipe, -1, 2U,
                       c12_waterRemain < c12_waterRecipe) != 0U,
    chartInstance->c12_sfEvent)) != 0);
  if (c12_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c12_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c12_sfEvent);
    c12_flg = false;
    _SFD_DATA_RANGE_CHECK((real_T)c12_flg, 25U);
  } else {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c12_sfEvent);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                 chartInstance->c12_sfEvent);
    c12_b_out = (CV_TRANSITION_EVAL(7U, (int32_T)_SFD_CCP_CALL(7U, 0,
      CV_RELATIONAL_EVAL(5U, 7U, 0, c12_milkRemain, c12_milkRecipe, -1, 2U,
                         c12_milkRemain < c12_milkRecipe) != 0U,
      chartInstance->c12_sfEvent)) != 0);
    if (c12_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c12_sfEvent);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c12_sfEvent);
      c12_flg = false;
      _SFD_DATA_RANGE_CHECK((real_T)c12_flg, 25U);
    } else {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c12_sfEvent);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                   chartInstance->c12_sfEvent);
      c12_c_out = (CV_TRANSITION_EVAL(8U, (int32_T)_SFD_CCP_CALL(8U, 0,
        CV_RELATIONAL_EVAL(5U, 8U, 0, c12_sugarRemain, c12_sugarRecipe, -1, 2U,
                           c12_sugarRemain < c12_sugarRecipe) != 0U,
        chartInstance->c12_sfEvent)) != 0);
      if (c12_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c12_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c12_sfEvent);
        c12_flg = false;
        _SFD_DATA_RANGE_CHECK((real_T)c12_flg, 25U);
      } else {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c12_sfEvent);
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                     chartInstance->c12_sfEvent);
        c12_d_out = (CV_TRANSITION_EVAL(11U, (int32_T)_SFD_CCP_CALL(11U, 0,
          CV_RELATIONAL_EVAL(5U, 11U, 0, c12_coffeeRemain, c12_coffeeRecipe, -1,
                             2U, c12_coffeeRemain < c12_coffeeRecipe) != 0U,
          chartInstance->c12_sfEvent)) != 0);
        if (c12_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c12_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c12_sfEvent);
          c12_flg = false;
          _SFD_DATA_RANGE_CHECK((real_T)c12_flg, 25U);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c12_sfEvent);
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 16U,
                       chartInstance->c12_sfEvent);
          c12_e_out = (CV_TRANSITION_EVAL(16U, (int32_T)_SFD_CCP_CALL(16U, 0,
            CV_RELATIONAL_EVAL(5U, 16U, 0, c12_cupRemain, 0.0, -1, 3U,
                               c12_cupRemain <= 0.0) != 0U,
            chartInstance->c12_sfEvent)) != 0);
          if (c12_e_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c12_sfEvent);
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c12_sfEvent);
            c12_flg = false;
            _SFD_DATA_RANGE_CHECK((real_T)c12_flg, 25U);
          } else {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c12_sfEvent);
            _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 22U,
                         chartInstance->c12_sfEvent);
            c12_f_out = (CV_TRANSITION_EVAL(22U, (int32_T)_SFD_CCP_CALL(22U, 0,
              CV_RELATIONAL_EVAL(5U, 22U, 0, c12_waterTemp, 80.0, -1, 3U,
                                 c12_waterTemp <= 80.0) != 0U,
              chartInstance->c12_sfEvent)) != 0);
            if (c12_f_out) {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 22U,
                           chartInstance->c12_sfEvent);
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 23U,
                           chartInstance->c12_sfEvent);
              c12_flg = false;
              _SFD_DATA_RANGE_CHECK((real_T)c12_flg, 25U);
            } else {
              _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 21U,
                           chartInstance->c12_sfEvent);
              c12_flg = true;
              _SFD_DATA_RANGE_CHECK((real_T)c12_flg, 25U);
            }
          }
        }
      }
    }
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CS_CALL(FUNCTION_INACTIVE_TAG, 5U, chartInstance->c12_sfEvent);
  _SFD_UNSET_DATA_VALUE_PTR(25U);
  _SFD_UNSET_DATA_VALUE_PTR(24U);
  _SFD_UNSET_DATA_VALUE_PTR(23U);
  _SFD_UNSET_DATA_VALUE_PTR(22U);
  _SFD_UNSET_DATA_VALUE_PTR(21U);
  _SFD_UNSET_DATA_VALUE_PTR(20U);
  _SFD_UNSET_DATA_VALUE_PTR(19U);
  _SFD_UNSET_DATA_VALUE_PTR(18U);
  _SFD_UNSET_DATA_VALUE_PTR(17U);
  _SFD_UNSET_DATA_VALUE_PTR(16U);
  _SFD_UNSET_DATA_VALUE_PTR(15U);
  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c12_sfEvent);
  return c12_flg;
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int8_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOneInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int8_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static int8_T c12_emlrt_marshallIn(SFc12_AllinOneInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int8_T c12_y;
  int8_T c12_i0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i0, 1, 2, 0U, 0, 0U, 0);
  c12_y = c12_i0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_Tick;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int8_T c12_y;
  SFc12_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOneInstanceStruct *)chartInstanceVoid;
  c12_b_Tick = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_Tick),
    &c12_thisId);
  sf_mex_destroy(&c12_b_Tick);
  *(int8_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  uint32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOneInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(uint32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static uint32_T c12_b_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_b_GetCupEventEventCounter, const char_T
  *c12_identifier)
{
  uint32_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_GetCupEventEventCounter), &c12_thisId);
  sf_mex_destroy(&c12_b_GetCupEventEventCounter);
  return c12_y;
}

static uint32_T c12_c_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint32_T c12_y;
  uint32_T c12_u1;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u1, 1, 7, 0U, 0, 0U, 0);
  c12_y = c12_u1;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_GetCupEventEventCounter;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  uint32_T c12_y;
  SFc12_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOneInstanceStruct *)chartInstanceVoid;
  c12_b_GetCupEventEventCounter = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_GetCupEventEventCounter), &c12_thisId);
  sf_mex_destroy(&c12_b_GetCupEventEventCounter);
  *(uint32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOneInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static int32_T c12_d_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
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

static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_y;
  SFc12_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOneInstanceStruct *)chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  uint8_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOneInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(uint8_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static uint8_T c12_e_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_b_tp_Init, const char_T *c12_identifier)
{
  uint8_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_tp_Init),
    &c12_thisId);
  sf_mex_destroy(&c12_b_tp_Init);
  return c12_y;
}

static uint8_T c12_f_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_y;
  uint8_T c12_u2;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u2, 1, 3, 0U, 0, 0U, 0);
  c12_y = c12_u2;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_tp_Init;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  uint8_T c12_y;
  SFc12_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOneInstanceStruct *)chartInstanceVoid;
  c12_b_tp_Init = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_tp_Init),
    &c12_thisId);
  sf_mex_destroy(&c12_b_tp_Init);
  *(uint8_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOneInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static real_T c12_g_emlrt_marshallIn(SFc12_AllinOneInstanceStruct *chartInstance,
  const mxArray *c12_b_CoffeeAmount, const char_T *c12_identifier)
{
  real_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_CoffeeAmount),
    &c12_thisId);
  sf_mex_destroy(&c12_b_CoffeeAmount);
  return c12_y;
}

static real_T c12_h_emlrt_marshallIn(SFc12_AllinOneInstanceStruct *chartInstance,
  const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_y;
  real_T c12_d0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d0, 1, 0, 0U, 0, 0U, 0);
  c12_y = c12_d0;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static void c12_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_CoffeeAmount;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_y;
  SFc12_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOneInstanceStruct *)chartInstanceVoid;
  c12_b_CoffeeAmount = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_CoffeeAmount),
    &c12_thisId);
  sf_mex_destroy(&c12_b_CoffeeAmount);
  *(real_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  boolean_T c12_u;
  const mxArray *c12_y = NULL;
  SFc12_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOneInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(boolean_T *)c12_inData;
  c12_y = NULL;
  sf_mex_assign(&c12_y, sf_mex_create("y", &c12_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_y, false);
  return c12_mxArrayOutData;
}

static boolean_T c12_i_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_flg, const char_T *c12_identifier)
{
  boolean_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_flg), &c12_thisId);
  sf_mex_destroy(&c12_flg);
  return c12_y;
}

static boolean_T c12_j_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
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

static void c12_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_flg;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  boolean_T c12_y;
  SFc12_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc12_AllinOneInstanceStruct *)chartInstanceVoid;
  c12_flg = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_flg), &c12_thisId);
  sf_mex_destroy(&c12_flg);
  *(boolean_T *)c12_outData = c12_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static uint16_T c12_k_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_b_temporalCounter_i2, const char_T
  *c12_identifier)
{
  uint16_T c12_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_y = c12_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_temporalCounter_i2), &c12_thisId);
  sf_mex_destroy(&c12_b_temporalCounter_i2);
  return c12_y;
}

static uint16_T c12_l_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint16_T c12_y;
  uint16_T c12_u3;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u3, 1, 5, 0U, 0, 0U, 0);
  c12_y = c12_u3;
  sf_mex_destroy(&c12_u);
  return c12_y;
}

static const mxArray *c12_m_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
  *chartInstance, const mxArray *c12_b_setSimStateSideEffectsInfo, const char_T *
  c12_identifier)
{
  const mxArray *c12_y = NULL;
  emlrtMsgIdentifier c12_thisId;
  c12_y = NULL;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  sf_mex_assign(&c12_y, c12_n_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_setSimStateSideEffectsInfo), &c12_thisId), false);
  sf_mex_destroy(&c12_b_setSimStateSideEffectsInfo);
  return c12_y;
}

static const mxArray *c12_n_emlrt_marshallIn(SFc12_AllinOneInstanceStruct
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

static void init_dsm_address_info(SFc12_AllinOneInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc12_AllinOneInstanceStruct *chartInstance)
{
  chartInstance->c12_Tick = (int8_T *)(ssGetInputPortSignalPtrs_wrapper
    (chartInstance->S, 6))[0U];
  chartInstance->c12_AmericanCoffee = (int8_T *)
    (ssGetInputPortSignalPtrs_wrapper(chartInstance->S, 6))[1U];
  chartInstance->c12_CoffeeLatte = (int8_T *)(ssGetInputPortSignalPtrs_wrapper
    (chartInstance->S, 6))[2U];
  chartInstance->c12_Cappuccino = (int8_T *)(ssGetInputPortSignalPtrs_wrapper
    (chartInstance->S, 6))[3U];
  chartInstance->c12_StepEvent = (int8_T *)(ssGetInputPortSignalPtrs_wrapper
    (chartInstance->S, 6))[4U];
  chartInstance->c12_FeedFinishEvent = (int8_T *)
    (ssGetInputPortSignalPtrs_wrapper(chartInstance->S, 6))[5U];
  chartInstance->c12_MixFinishEvent = (int8_T *)
    (ssGetInputPortSignalPtrs_wrapper(chartInstance->S, 6))[6U];
  chartInstance->c12_SugarDoserEvent = (int8_T *)
    (ssGetInputPortSignalPtrs_wrapper(chartInstance->S, 6))[7U];
  chartInstance->c12_MilkDoserEvent = (int8_T *)
    (ssGetInputPortSignalPtrs_wrapper(chartInstance->S, 6))[8U];
  chartInstance->c12_CoffeeDoserEvent = (int8_T *)
    (ssGetInputPortSignalPtrs_wrapper(chartInstance->S, 6))[9U];
  chartInstance->c12_GetCupEvent = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c12_TakeOutEvent = (int8_T *)(ssGetInputPortSignalPtrs_wrapper
    (chartInstance->S, 6))[10U];
  chartInstance->c12_CoffeeRemain = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c12_MilkRemain = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c12_SugarRemain = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c12_CoffeeAmount = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c12_MilkAmount = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c12_SugarAmount = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c12_WaterAmount = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c12_NextStep = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c12_WaterRemain = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c12_WaterTemp = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c12_CupRemain = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
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

void sf_c12_AllinOne_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3458852723U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3658478632U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1386882413U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2048323324U);
}

mxArray* sf_c12_AllinOne_get_post_codegen_info(void);
mxArray *sf_c12_AllinOne_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("n3H6cCYDFgF202lYDuyzOC");
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

  {
    mxArray* mxPostCodegenInfo = sf_c12_AllinOne_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c12_AllinOne_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c12_AllinOne_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c12_AllinOne_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c12_AllinOne_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c12_AllinOne(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[14],T\"CoffeeAmount\",},{M[1],M[15],T\"MilkAmount\",},{M[1],M[23],T\"NextStep\",},{M[1],M[16],T\"SugarAmount\",},{M[1],M[17],T\"WaterAmount\",},{M[3],M[671],T\"CoffeeRecipe\",},{M[3],M[672],T\"MilkRecipe\",},{M[3],M[673],T\"SugarRecipe\",},{M[3],M[674],T\"WaterRecipe\",},{M[6],M[13],T\"GetCupEvent\",}}",
    "100 S1x10'type','srcId','name','auxInfo'{{M[7],M[13],T\"GetCupEventEventCounter\",},{M[8],M[0],T\"is_active_c12_AllinOne\",},{M[8],M[649],T\"is_active_CoffeeDoserState\",},{M[8],M[657],T\"is_active_SugarDoserState\",},{M[8],M[661],T\"is_active_WaterState\",},{M[8],M[666],T\"is_active_MilkDoserState\",},{M[9],M[0],T\"is_c12_AllinOne\",},{M[9],M[649],T\"is_CoffeeDoserState\",},{M[9],M[657],T\"is_SugarDoserState\",},{M[9],M[661],T\"is_WaterState\",}}",
    "100 S1x3'type','srcId','name','auxInfo'{{M[9],M[666],T\"is_MilkDoserState\",},{M[11],M[26],T\"temporalCounter_i2\",S'et','os','ct'{{T\"ev\",M[297],M[1]}}},{M[11],M[26],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x4[659 404 414 417],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 23, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_AllinOne_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_AllinOneInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc12_AllinOneInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllinOneMachineNumber_,
           12,
           23,
           47,
           0,
           26,
           12,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_AllinOneMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_AllinOneMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _AllinOneMachineNumber_,
            chartInstance->chartNumber,
            12,
            12,
            12);
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
          _SFD_SET_DATA_PROPS(11,0,0,0,"CoffeeRecipe");
          _SFD_SET_DATA_PROPS(12,0,0,0,"MilkRecipe");
          _SFD_SET_DATA_PROPS(13,0,0,0,"SugarRecipe");
          _SFD_SET_DATA_PROPS(14,0,0,0,"WaterRecipe");
          _SFD_SET_DATA_PROPS(15,8,0,0,"");
          _SFD_SET_DATA_PROPS(16,8,0,0,"");
          _SFD_SET_DATA_PROPS(17,8,0,0,"");
          _SFD_SET_DATA_PROPS(18,8,0,0,"");
          _SFD_SET_DATA_PROPS(19,8,0,0,"");
          _SFD_SET_DATA_PROPS(20,8,0,0,"");
          _SFD_SET_DATA_PROPS(21,8,0,0,"");
          _SFD_SET_DATA_PROPS(22,8,0,0,"");
          _SFD_SET_DATA_PROPS(23,8,0,0,"");
          _SFD_SET_DATA_PROPS(24,8,0,0,"");
          _SFD_SET_DATA_PROPS(25,9,0,0,"");
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
          _SFD_EVENT_SCOPE(11,1);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,1,0);
          _SFD_STATE_INFO(11,0,1);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,0);
          _SFD_STATE_INFO(14,0,1);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(17,0,1);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(20,0,1);
          _SFD_STATE_INFO(21,0,0);
          _SFD_STATE_INFO(22,0,0);
          _SFD_STATE_INFO(5,0,2);
          _SFD_CH_SUBSTATE_COUNT(10);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_CH_SUBSTATE_INDEX(3,3);
          _SFD_CH_SUBSTATE_INDEX(4,4);
          _SFD_CH_SUBSTATE_INDEX(5,6);
          _SFD_CH_SUBSTATE_INDEX(6,7);
          _SFD_CH_SUBSTATE_INDEX(7,8);
          _SFD_CH_SUBSTATE_INDEX(8,9);
          _SFD_CH_SUBSTATE_INDEX(9,10);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,4);
          _SFD_ST_SUBSTATE_INDEX(10,0,20);
          _SFD_ST_SUBSTATE_INDEX(10,1,17);
          _SFD_ST_SUBSTATE_INDEX(10,2,11);
          _SFD_ST_SUBSTATE_INDEX(10,3,14);
          _SFD_ST_SUBSTATE_COUNT(20,2);
          _SFD_ST_SUBSTATE_INDEX(20,0,21);
          _SFD_ST_SUBSTATE_INDEX(20,1,22);
          _SFD_ST_SUBSTATE_COUNT(21,0);
          _SFD_ST_SUBSTATE_COUNT(22,0);
          _SFD_ST_SUBSTATE_COUNT(17,2);
          _SFD_ST_SUBSTATE_INDEX(17,0,18);
          _SFD_ST_SUBSTATE_INDEX(17,1,19);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(19,0);
          _SFD_ST_SUBSTATE_COUNT(11,2);
          _SFD_ST_SUBSTATE_INDEX(11,0,12);
          _SFD_ST_SUBSTATE_INDEX(11,1,13);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(13,0);
          _SFD_ST_SUBSTATE_COUNT(14,2);
          _SFD_ST_SUBSTATE_INDEX(14,0,15);
          _SFD_ST_SUBSTATE_INDEX(14,1,16);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(16,0);
        }

        _SFD_CV_INIT_CHART(10,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,4,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(19,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(20,2,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(21,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(22,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 10 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(27,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(30,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 11 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(26,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(31,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 12 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(46,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(25,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(45,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 12, 0 };

          static unsigned int sEndGuardMap[] = { 16, 17 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(44,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 138 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(29,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 138 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(28,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 138 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(5,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(19,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 12, 0 };

          static unsigned int sEndGuardMap[] = { 16, 17 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(42,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 12, 0 };

          static unsigned int sEndGuardMap[] = { 16, 17 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(43,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 12, 0 };

          static unsigned int sEndGuardMap[] = { 16, 17 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(41,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 9 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(40,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 15 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(24,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(21,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(3,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 24 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 2, 2, 2 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(3,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 22 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(7,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 22 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 2, 2, 2 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(7,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 24 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(8,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 24 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 2, 2, 2 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(8,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 26 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(11,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 26 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 2, 2, 2 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(11,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 13 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(16,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 13 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 3, 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(16,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(22,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 14 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 3, 3, 3 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(22,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(23,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(36,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 19, 0 };

          static unsigned int sEndGuardMap[] = { 23, 24 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(37,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(35,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 15 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(34,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(32,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 16 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(33,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_CV_INIT_TRANS(39,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 0 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(38,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_f_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(23,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(24,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)
          c12_e_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(25,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_f_sf_marshallOut,(MexInFcnForType)
          c12_f_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(15,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(16,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(17,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(18,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(19,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(20,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(21,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(22,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(23,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(24,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(25,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c12_CoffeeRemain);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c12_MilkRemain);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c12_SugarRemain);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c12_CoffeeAmount);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c12_MilkAmount);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c12_SugarAmount);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c12_WaterAmount);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c12_NextStep);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c12_WaterRemain);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c12_WaterTemp);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c12_CupRemain);
        _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c12_CoffeeRecipe);
        _SFD_SET_DATA_VALUE_PTR(12U, &chartInstance->c12_MilkRecipe);
        _SFD_SET_DATA_VALUE_PTR(13U, &chartInstance->c12_SugarRecipe);
        _SFD_SET_DATA_VALUE_PTR(14U, &chartInstance->c12_WaterRecipe);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _AllinOneMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "AdtYVb8COUYR90eJPBEZyG";
}

static void sf_opaque_initialize_c12_AllinOne(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_AllinOneInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c12_AllinOne((SFc12_AllinOneInstanceStruct*)
    chartInstanceVar);
  initialize_c12_AllinOne((SFc12_AllinOneInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c12_AllinOne(void *chartInstanceVar)
{
  enable_c12_AllinOne((SFc12_AllinOneInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c12_AllinOne(void *chartInstanceVar)
{
  disable_c12_AllinOne((SFc12_AllinOneInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c12_AllinOne(void *chartInstanceVar)
{
  sf_gateway_c12_AllinOne((SFc12_AllinOneInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c12_AllinOne(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c12_AllinOne((SFc12_AllinOneInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c12_AllinOne(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c12_AllinOne((SFc12_AllinOneInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c12_AllinOne(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_AllinOneInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllinOne_optimization_info();
    }

    finalize_c12_AllinOne((SFc12_AllinOneInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_AllinOne((SFc12_AllinOneInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_AllinOne(SimStruct *S)
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
    initialize_params_c12_AllinOne((SFc12_AllinOneInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_AllinOne(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_AllinOne_optimization_info();
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
  ssSetChecksum0(S,(2352448292U));
  ssSetChecksum1(S,(2843228166U));
  ssSetChecksum2(S,(2166155163U));
  ssSetChecksum3(S,(3074671326U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c12_AllinOne(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c12_AllinOne(SimStruct *S)
{
  SFc12_AllinOneInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc12_AllinOneInstanceStruct *)utMalloc(sizeof
    (SFc12_AllinOneInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc12_AllinOneInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c12_AllinOne;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c12_AllinOne;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c12_AllinOne;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c12_AllinOne;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c12_AllinOne;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c12_AllinOne;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c12_AllinOne;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c12_AllinOne;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_AllinOne;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_AllinOne;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c12_AllinOne;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c12_AllinOne_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_AllinOne(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_AllinOne(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_AllinOne(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_AllinOne_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
