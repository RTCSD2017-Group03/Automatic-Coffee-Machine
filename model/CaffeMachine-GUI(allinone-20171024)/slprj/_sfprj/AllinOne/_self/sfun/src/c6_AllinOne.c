/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllinOne_sfun.h"
#include "c6_AllinOne.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "AllinOne_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c6_event_Tick                  (0)
#define CALL_EVENT                     (-1)
#define c6_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c6_IN_GetInFlow                ((uint8_T)1U)
#define c6_IN_OFF                      ((uint8_T)2U)
#define c6_IN_Heating                  ((uint8_T)1U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c6_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c6_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c6_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c6_dataWrittenToVector[2];

/* Function Declarations */
static void initialize_c6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance);
static void initialize_params_c6_AllinOne(SFc6_AllinOneInstanceStruct
  *chartInstance);
static void enable_c6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance);
static void disable_c6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance);
static void c6_update_debugger_state_c6_AllinOne(SFc6_AllinOneInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c6_AllinOne(SFc6_AllinOneInstanceStruct
  *chartInstance);
static void set_sim_state_c6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance,
  const mxArray *c6_st);
static void c6_set_sim_state_side_effects_c6_AllinOne
  (SFc6_AllinOneInstanceStruct *chartInstance);
static void finalize_c6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance);
static void sf_gateway_c6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance);
static void c6_chartstep_c6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance);
static void initSimStructsc6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber);
static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData);
static real_T c6_emlrt_marshallIn(SFc6_AllinOneInstanceStruct *chartInstance,
  const mxArray *c6_nargout, const char_T *c6_identifier);
static real_T c6_b_emlrt_marshallIn(SFc6_AllinOneInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static boolean_T c6_c_emlrt_marshallIn(SFc6_AllinOneInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int8_T c6_d_emlrt_marshallIn(SFc6_AllinOneInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static int32_T c6_e_emlrt_marshallIn(SFc6_AllinOneInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData);
static uint8_T c6_f_emlrt_marshallIn(SFc6_AllinOneInstanceStruct *chartInstance,
  const mxArray *c6_b_tp_InFlow, const char_T *c6_identifier);
static uint8_T c6_g_emlrt_marshallIn(SFc6_AllinOneInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData);
static const mxArray *c6_h_emlrt_marshallIn(SFc6_AllinOneInstanceStruct
  *chartInstance, const mxArray *c6_b_setSimStateSideEffectsInfo, const char_T
  *c6_identifier);
static const mxArray *c6_i_emlrt_marshallIn(SFc6_AllinOneInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId);
static void c6_updateDataWrittenToVector(SFc6_AllinOneInstanceStruct
  *chartInstance, uint32_T c6_vectorIndex);
static void init_dsm_address_info(SFc6_AllinOneInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c6_doSetSimStateSideEffects = 0U;
  chartInstance->c6_setSimStateSideEffectsInfo = NULL;
  chartInstance->c6_is_active_Heater = 0U;
  chartInstance->c6_is_Heater = c6_IN_NO_ACTIVE_CHILD;
  chartInstance->c6_tp_Heater = 0U;
  chartInstance->c6_tp_Heating = 0U;
  chartInstance->c6_b_tp_OFF = 0U;
  chartInstance->c6_is_active_InFlow = 0U;
  chartInstance->c6_is_InFlow = c6_IN_NO_ACTIVE_CHILD;
  chartInstance->c6_tp_InFlow = 0U;
  chartInstance->c6_tp_GetInFlow = 0U;
  chartInstance->c6_tp_OFF = 0U;
  chartInstance->c6_is_active_c6_AllinOne = 0U;
}

static void initialize_params_c6_AllinOne(SFc6_AllinOneInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c6_update_debugger_state_c6_AllinOne(SFc6_AllinOneInstanceStruct
  *chartInstance)
{
  uint32_T c6_prevAniVal;
  c6_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c6_is_active_c6_AllinOne == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_active_InFlow == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_InFlow == c6_IN_GetInFlow) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_InFlow == c6_IN_OFF) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_active_Heater == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_Heater == c6_IN_Heating) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
  }

  if (chartInstance->c6_is_Heater == c6_IN_OFF) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
  }

  _SFD_SET_ANIMATION(c6_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c6_AllinOne(SFc6_AllinOneInstanceStruct
  *chartInstance)
{
  const mxArray *c6_st;
  const mxArray *c6_y = NULL;
  real_T c6_hoistedGlobal;
  real_T c6_u;
  const mxArray *c6_b_y = NULL;
  real_T c6_b_hoistedGlobal;
  real_T c6_b_u;
  const mxArray *c6_c_y = NULL;
  uint8_T c6_c_hoistedGlobal;
  uint8_T c6_c_u;
  const mxArray *c6_d_y = NULL;
  uint8_T c6_d_hoistedGlobal;
  uint8_T c6_d_u;
  const mxArray *c6_e_y = NULL;
  uint8_T c6_e_hoistedGlobal;
  uint8_T c6_e_u;
  const mxArray *c6_f_y = NULL;
  uint8_T c6_f_hoistedGlobal;
  uint8_T c6_f_u;
  const mxArray *c6_g_y = NULL;
  uint8_T c6_g_hoistedGlobal;
  uint8_T c6_g_u;
  const mxArray *c6_h_y = NULL;
  real_T *c6_HeatSwitch;
  real_T *c6_InFlowSwitch;
  c6_InFlowSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_HeatSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_st = NULL;
  c6_st = NULL;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_createcellmatrix(7, 1), false);
  c6_hoistedGlobal = *c6_HeatSwitch;
  c6_u = c6_hoistedGlobal;
  c6_b_y = NULL;
  sf_mex_assign(&c6_b_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 0, c6_b_y);
  c6_b_hoistedGlobal = *c6_InFlowSwitch;
  c6_b_u = c6_b_hoistedGlobal;
  c6_c_y = NULL;
  sf_mex_assign(&c6_c_y, sf_mex_create("y", &c6_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 1, c6_c_y);
  c6_c_hoistedGlobal = chartInstance->c6_is_active_c6_AllinOne;
  c6_c_u = c6_c_hoistedGlobal;
  c6_d_y = NULL;
  sf_mex_assign(&c6_d_y, sf_mex_create("y", &c6_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 2, c6_d_y);
  c6_d_hoistedGlobal = chartInstance->c6_is_active_Heater;
  c6_d_u = c6_d_hoistedGlobal;
  c6_e_y = NULL;
  sf_mex_assign(&c6_e_y, sf_mex_create("y", &c6_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 3, c6_e_y);
  c6_e_hoistedGlobal = chartInstance->c6_is_active_InFlow;
  c6_e_u = c6_e_hoistedGlobal;
  c6_f_y = NULL;
  sf_mex_assign(&c6_f_y, sf_mex_create("y", &c6_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 4, c6_f_y);
  c6_f_hoistedGlobal = chartInstance->c6_is_Heater;
  c6_f_u = c6_f_hoistedGlobal;
  c6_g_y = NULL;
  sf_mex_assign(&c6_g_y, sf_mex_create("y", &c6_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 5, c6_g_y);
  c6_g_hoistedGlobal = chartInstance->c6_is_InFlow;
  c6_g_u = c6_g_hoistedGlobal;
  c6_h_y = NULL;
  sf_mex_assign(&c6_h_y, sf_mex_create("y", &c6_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c6_y, 6, c6_h_y);
  sf_mex_assign(&c6_st, c6_y, false);
  return c6_st;
}

static void set_sim_state_c6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance,
  const mxArray *c6_st)
{
  const mxArray *c6_u;
  real_T *c6_HeatSwitch;
  real_T *c6_InFlowSwitch;
  c6_InFlowSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_HeatSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_u = sf_mex_dup(c6_st);
  *c6_HeatSwitch = c6_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c6_u, 0)), "HeatSwitch");
  *c6_InFlowSwitch = c6_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 1)), "InFlowSwitch");
  chartInstance->c6_is_active_c6_AllinOne = c6_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 2)), "is_active_c6_AllinOne");
  chartInstance->c6_is_active_Heater = c6_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 3)), "is_active_Heater");
  chartInstance->c6_is_active_InFlow = c6_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c6_u, 4)), "is_active_InFlow");
  chartInstance->c6_is_Heater = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 5)), "is_Heater");
  chartInstance->c6_is_InFlow = c6_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c6_u, 6)), "is_InFlow");
  sf_mex_assign(&chartInstance->c6_setSimStateSideEffectsInfo,
                c6_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c6_u, 7)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c6_u);
  chartInstance->c6_doSetSimStateSideEffects = 1U;
  c6_update_debugger_state_c6_AllinOne(chartInstance);
  sf_mex_destroy(&c6_st);
}

static void c6_set_sim_state_side_effects_c6_AllinOne
  (SFc6_AllinOneInstanceStruct *chartInstance)
{
  if (chartInstance->c6_doSetSimStateSideEffects != 0) {
    if (chartInstance->c6_is_active_Heater == 1U) {
      chartInstance->c6_tp_Heater = 1U;
    } else {
      chartInstance->c6_tp_Heater = 0U;
    }

    if (chartInstance->c6_is_Heater == c6_IN_Heating) {
      chartInstance->c6_tp_Heating = 1U;
    } else {
      chartInstance->c6_tp_Heating = 0U;
    }

    if (chartInstance->c6_is_Heater == c6_IN_OFF) {
      chartInstance->c6_b_tp_OFF = 1U;
    } else {
      chartInstance->c6_b_tp_OFF = 0U;
    }

    if (chartInstance->c6_is_active_InFlow == 1U) {
      chartInstance->c6_tp_InFlow = 1U;
    } else {
      chartInstance->c6_tp_InFlow = 0U;
    }

    if (chartInstance->c6_is_InFlow == c6_IN_GetInFlow) {
      chartInstance->c6_tp_GetInFlow = 1U;
    } else {
      chartInstance->c6_tp_GetInFlow = 0U;
    }

    if (chartInstance->c6_is_InFlow == c6_IN_OFF) {
      chartInstance->c6_tp_OFF = 1U;
    } else {
      chartInstance->c6_tp_OFF = 0U;
    }

    chartInstance->c6_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c6_setSimStateSideEffectsInfo);
}

static void sf_gateway_c6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance)
{
  real_T *c6_InnerTemp;
  real_T *c6_InnerAmount;
  real_T *c6_HeatSwitch;
  real_T *c6_InFlowSwitch;
  c6_InFlowSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_HeatSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_InnerAmount = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_InnerTemp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c6_set_sim_state_side_effects_c6_AllinOne(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c6_InnerTemp, 0U);
  _SFD_DATA_RANGE_CHECK(*c6_InnerAmount, 1U);
  _SFD_DATA_RANGE_CHECK(*c6_HeatSwitch, 2U);
  _SFD_DATA_RANGE_CHECK(*c6_InFlowSwitch, 3U);
  chartInstance->c6_sfEvent = c6_event_Tick;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c6_event_Tick,
               chartInstance->c6_sfEvent);
  c6_chartstep_c6_AllinOne(chartInstance);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c6_event_Tick,
               chartInstance->c6_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_AllinOneMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c6_chartstep_c6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance)
{
  uint32_T c6_debug_family_var_map[2];
  real_T c6_nargin = 0.0;
  real_T c6_nargout = 0.0;
  real_T c6_b_nargin = 0.0;
  real_T c6_b_nargout = 0.0;
  uint32_T c6_b_debug_family_var_map[3];
  real_T c6_c_nargin = 0.0;
  real_T c6_c_nargout = 1.0;
  boolean_T c6_out;
  real_T c6_d_nargin = 0.0;
  real_T c6_d_nargout = 0.0;
  real_T c6_e_nargin = 0.0;
  real_T c6_e_nargout = 1.0;
  boolean_T c6_b_out;
  real_T c6_f_nargin = 0.0;
  real_T c6_f_nargout = 0.0;
  real_T c6_g_nargin = 0.0;
  real_T c6_g_nargout = 1.0;
  boolean_T c6_c_out;
  real_T c6_h_nargin = 0.0;
  real_T c6_h_nargout = 0.0;
  real_T c6_i_nargin = 0.0;
  real_T c6_i_nargout = 1.0;
  boolean_T c6_d_out;
  real_T c6_j_nargin = 0.0;
  real_T c6_j_nargout = 0.0;
  real_T *c6_InnerTemp;
  real_T *c6_HeatSwitch;
  real_T *c6_InnerAmount;
  real_T *c6_InFlowSwitch;
  c6_InFlowSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c6_HeatSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c6_InnerAmount = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c6_InnerTemp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
  if (chartInstance->c6_is_active_c6_AllinOne == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
    chartInstance->c6_is_active_c6_AllinOne = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
    chartInstance->c6_is_active_Heater = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
    chartInstance->c6_tp_Heater = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
    chartInstance->c6_is_Heater = c6_IN_OFF;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
    chartInstance->c6_b_tp_OFF = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_d_debug_family_names,
      c6_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    *c6_HeatSwitch = 0.0;
    c6_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*c6_HeatSwitch, 2U);
    _SFD_SYMBOL_SCOPE_POP();
    chartInstance->c6_is_active_InFlow = 1U;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
    chartInstance->c6_tp_InFlow = 1U;
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
    chartInstance->c6_is_InFlow = c6_IN_OFF;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
    chartInstance->c6_tp_OFF = 1U;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_b_debug_family_names,
      c6_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargin, 0U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_nargout, 1U, c6_sf_marshallOut,
      c6_sf_marshallIn);
    *c6_InFlowSwitch = 0.0;
    c6_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*c6_InFlowSwitch, 3U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c6_sfEvent);
    switch (chartInstance->c6_is_Heater) {
     case c6_IN_Heating:
      CV_STATE_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_g_debug_family_names,
        c6_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      c6_out = CV_EML_IF(0, 0, 0, *c6_InnerTemp > 95.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c6_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_Heating = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_Heater = c6_IN_OFF;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
        chartInstance->c6_b_tp_OFF = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_d_debug_family_names,
          c6_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        *c6_HeatSwitch = 0.0;
        c6_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*c6_HeatSwitch, 2U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c6_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c6_sfEvent);
      break;

     case c6_IN_OFF:
      CV_STATE_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_h_debug_family_names,
        c6_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_e_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_b_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      c6_b_out = CV_EML_IF(1, 0, 0, *c6_InnerTemp < 80.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c6_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
        chartInstance->c6_b_tp_OFF = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_Heater = c6_IN_Heating;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_Heating = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_c_debug_family_names,
          c6_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_f_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        *c6_HeatSwitch = 1.0;
        c6_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*c6_HeatSwitch, 2U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c6_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c6_sfEvent);
      break;

     default:
      CV_STATE_EVAL(0, 0, 0);
      chartInstance->c6_is_Heater = c6_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c6_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c6_sfEvent);
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c6_sfEvent);
    switch (chartInstance->c6_is_InFlow) {
     case c6_IN_GetInFlow:
      CV_STATE_EVAL(3, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_e_debug_family_names,
        c6_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_g_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_g_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_c_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      c6_c_out = CV_EML_IF(5, 0, 0, *c6_InnerAmount > 2000.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c6_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_GetInFlow = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_InFlow = c6_IN_OFF;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_OFF = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_b_debug_family_names,
          c6_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_h_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_h_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        *c6_InFlowSwitch = 0.0;
        c6_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*c6_InFlowSwitch, 3U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                     chartInstance->c6_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c6_sfEvent);
      break;

     case c6_IN_OFF:
      CV_STATE_EVAL(3, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   chartInstance->c6_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c6_f_debug_family_names,
        c6_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_i_nargin, 0U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_i_nargout, 1U, c6_sf_marshallOut,
        c6_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_d_out, 2U, c6_b_sf_marshallOut,
        c6_b_sf_marshallIn);
      c6_d_out = CV_EML_IF(3, 0, 0, *c6_InnerAmount < 1900.0);
      _SFD_SYMBOL_SCOPE_POP();
      if (c6_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_OFF = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c6_sfEvent);
        chartInstance->c6_is_InFlow = c6_IN_GetInFlow;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
        chartInstance->c6_tp_GetInFlow = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c6_debug_family_names,
          c6_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_j_nargin, 0U, c6_sf_marshallOut,
          c6_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c6_j_nargout, 1U,
          c6_sf_marshallOut, c6_sf_marshallIn);
        *c6_InFlowSwitch = 1.0;
        c6_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*c6_InFlowSwitch, 3U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                     chartInstance->c6_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
      break;

     default:
      CV_STATE_EVAL(3, 0, 0);
      chartInstance->c6_is_InFlow = c6_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c6_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c6_sfEvent);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c6_sfEvent);
}

static void initSimStructsc6_AllinOne(SFc6_AllinOneInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c6_machineNumber, uint32_T
  c6_chartNumber, uint32_T c6_instanceNumber)
{
  (void)c6_machineNumber;
  (void)c6_chartNumber;
  (void)c6_instanceNumber;
}

static const mxArray *c6_sf_marshallOut(void *chartInstanceVoid, void *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  real_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc6_AllinOneInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(real_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static real_T c6_emlrt_marshallIn(SFc6_AllinOneInstanceStruct *chartInstance,
  const mxArray *c6_nargout, const char_T *c6_identifier)
{
  real_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  return c6_y;
}

static real_T c6_b_emlrt_marshallIn(SFc6_AllinOneInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  real_T c6_y;
  real_T c6_d0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_d0, 1, 0, 0U, 0, 0U, 0);
  c6_y = c6_d0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_nargout;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  real_T c6_y;
  SFc6_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc6_AllinOneInstanceStruct *)chartInstanceVoid;
  c6_nargout = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_nargout), &c6_thisId);
  sf_mex_destroy(&c6_nargout);
  *(real_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_b_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  boolean_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc6_AllinOneInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(boolean_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static boolean_T c6_c_emlrt_marshallIn(SFc6_AllinOneInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  boolean_T c6_y;
  boolean_T c6_b0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_b0, 1, 11, 0U, 0, 0U, 0);
  c6_y = c6_b0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_sf_internal_predicateOutput;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  boolean_T c6_y;
  SFc6_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc6_AllinOneInstanceStruct *)chartInstanceVoid;
  c6_sf_internal_predicateOutput = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_sf_internal_predicateOutput), &c6_thisId);
  sf_mex_destroy(&c6_sf_internal_predicateOutput);
  *(boolean_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

const mxArray *sf_c6_AllinOne_get_eml_resolved_functions_info(void)
{
  const mxArray *c6_nameCaptureInfo = NULL;
  c6_nameCaptureInfo = NULL;
  sf_mex_assign(&c6_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c6_nameCaptureInfo;
}

static const mxArray *c6_c_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int8_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc6_AllinOneInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int8_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int8_T c6_d_emlrt_marshallIn(SFc6_AllinOneInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int8_T c6_y;
  int8_T c6_i0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i0, 1, 2, 0U, 0, 0U, 0);
  c6_y = c6_i0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_Tick;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int8_T c6_y;
  SFc6_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc6_AllinOneInstanceStruct *)chartInstanceVoid;
  c6_Tick = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_Tick), &c6_thisId);
  sf_mex_destroy(&c6_Tick);
  *(int8_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_d_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  int32_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc6_AllinOneInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(int32_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static int32_T c6_e_emlrt_marshallIn(SFc6_AllinOneInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  int32_T c6_y;
  int32_T c6_i1;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_i1, 1, 6, 0U, 0, 0U, 0);
  c6_y = c6_i1;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_sfEvent;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  int32_T c6_y;
  SFc6_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc6_AllinOneInstanceStruct *)chartInstanceVoid;
  c6_b_sfEvent = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_sfEvent),
    &c6_thisId);
  sf_mex_destroy(&c6_b_sfEvent);
  *(int32_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_e_sf_marshallOut(void *chartInstanceVoid, void
  *c6_inData)
{
  const mxArray *c6_mxArrayOutData = NULL;
  uint8_T c6_u;
  const mxArray *c6_y = NULL;
  SFc6_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc6_AllinOneInstanceStruct *)chartInstanceVoid;
  c6_mxArrayOutData = NULL;
  c6_u = *(uint8_T *)c6_inData;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_create("y", &c6_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c6_mxArrayOutData, c6_y, false);
  return c6_mxArrayOutData;
}

static uint8_T c6_f_emlrt_marshallIn(SFc6_AllinOneInstanceStruct *chartInstance,
  const mxArray *c6_b_tp_InFlow, const char_T *c6_identifier)
{
  uint8_T c6_y;
  emlrtMsgIdentifier c6_thisId;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_tp_InFlow),
    &c6_thisId);
  sf_mex_destroy(&c6_b_tp_InFlow);
  return c6_y;
}

static uint8_T c6_g_emlrt_marshallIn(SFc6_AllinOneInstanceStruct *chartInstance,
  const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  uint8_T c6_y;
  uint8_T c6_u0;
  (void)chartInstance;
  sf_mex_import(c6_parentId, sf_mex_dup(c6_u), &c6_u0, 1, 3, 0U, 0, 0U, 0);
  c6_y = c6_u0;
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c6_mxArrayInData, const char_T *c6_varName, void *c6_outData)
{
  const mxArray *c6_b_tp_InFlow;
  const char_T *c6_identifier;
  emlrtMsgIdentifier c6_thisId;
  uint8_T c6_y;
  SFc6_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc6_AllinOneInstanceStruct *)chartInstanceVoid;
  c6_b_tp_InFlow = sf_mex_dup(c6_mxArrayInData);
  c6_identifier = c6_varName;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  c6_y = c6_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c6_b_tp_InFlow),
    &c6_thisId);
  sf_mex_destroy(&c6_b_tp_InFlow);
  *(uint8_T *)c6_outData = c6_y;
  sf_mex_destroy(&c6_mxArrayInData);
}

static const mxArray *c6_h_emlrt_marshallIn(SFc6_AllinOneInstanceStruct
  *chartInstance, const mxArray *c6_b_setSimStateSideEffectsInfo, const char_T
  *c6_identifier)
{
  const mxArray *c6_y = NULL;
  emlrtMsgIdentifier c6_thisId;
  c6_y = NULL;
  c6_thisId.fIdentifier = c6_identifier;
  c6_thisId.fParent = NULL;
  sf_mex_assign(&c6_y, c6_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c6_b_setSimStateSideEffectsInfo), &c6_thisId), false);
  sf_mex_destroy(&c6_b_setSimStateSideEffectsInfo);
  return c6_y;
}

static const mxArray *c6_i_emlrt_marshallIn(SFc6_AllinOneInstanceStruct
  *chartInstance, const mxArray *c6_u, const emlrtMsgIdentifier *c6_parentId)
{
  const mxArray *c6_y = NULL;
  (void)chartInstance;
  (void)c6_parentId;
  c6_y = NULL;
  sf_mex_assign(&c6_y, sf_mex_duplicatearraysafe(&c6_u), false);
  sf_mex_destroy(&c6_u);
  return c6_y;
}

static void c6_updateDataWrittenToVector(SFc6_AllinOneInstanceStruct
  *chartInstance, uint32_T c6_vectorIndex)
{
  (void)chartInstance;
  c6_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c6_vectorIndex, 0, 1, 1, 0)] = true;
}

static void init_dsm_address_info(SFc6_AllinOneInstanceStruct *chartInstance)
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

void sf_c6_AllinOne_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(191031977U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(640484726U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3798622728U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(662173713U);
}

mxArray *sf_c6_AllinOne_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("e4w0fbvKXSPTHnK9sMUwWD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c6_AllinOne_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c6_AllinOne_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c6_AllinOne(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[26],T\"HeatSwitch\",},{M[1],M[27],T\"InFlowSwitch\",},{M[8],M[0],T\"is_active_c6_AllinOne\",},{M[8],M[1],T\"is_active_Heater\",},{M[8],M[16],T\"is_active_InFlow\",},{M[9],M[1],T\"is_Heater\",},{M[9],M[16],T\"is_InFlow\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c6_AllinOne_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc6_AllinOneInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc6_AllinOneInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllinOneMachineNumber_,
           6,
           6,
           6,
           0,
           4,
           1,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
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
            1,
            1,
            1);
          _SFD_SET_DATA_PROPS(0,1,1,0,"InnerTemp");
          _SFD_SET_DATA_PROPS(1,1,1,0,"InnerAmount");
          _SFD_SET_DATA_PROPS(2,2,0,1,"HeatSwitch");
          _SFD_SET_DATA_PROPS(3,2,0,1,"InFlowSwitch");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,1);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,3);
          _SFD_ST_SUBSTATE_COUNT(0,2);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,2);
          _SFD_ST_SUBSTATE_INDEX(3,0,4);
          _SFD_ST_SUBSTATE_INDEX(3,1,5);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
        }

        _SFD_CV_INIT_CHART(2,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,13,1,13);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,13,1,13);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c6_sf_marshallOut,(MexInFcnForType)c6_sf_marshallIn);

        {
          real_T *c6_InnerTemp;
          real_T *c6_InnerAmount;
          real_T *c6_HeatSwitch;
          real_T *c6_InFlowSwitch;
          c6_InFlowSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c6_HeatSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c6_InnerAmount = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c6_InnerTemp = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c6_InnerTemp);
          _SFD_SET_DATA_VALUE_PTR(1U, c6_InnerAmount);
          _SFD_SET_DATA_VALUE_PTR(2U, c6_HeatSwitch);
          _SFD_SET_DATA_VALUE_PTR(3U, c6_InFlowSwitch);
        }
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
  return "D4FkRXFQpdcLudHeMYfweB";
}

static void sf_opaque_initialize_c6_AllinOne(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc6_AllinOneInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c6_AllinOne((SFc6_AllinOneInstanceStruct*) chartInstanceVar);
  initialize_c6_AllinOne((SFc6_AllinOneInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c6_AllinOne(void *chartInstanceVar)
{
  enable_c6_AllinOne((SFc6_AllinOneInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c6_AllinOne(void *chartInstanceVar)
{
  disable_c6_AllinOne((SFc6_AllinOneInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c6_AllinOne(void *chartInstanceVar)
{
  sf_gateway_c6_AllinOne((SFc6_AllinOneInstanceStruct*) chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c6_AllinOne(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c6_AllinOne((SFc6_AllinOneInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c6_AllinOne();/* state var info */
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

extern void sf_internal_set_sim_state_c6_AllinOne(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c6_AllinOne();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c6_AllinOne((SFc6_AllinOneInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c6_AllinOne(SimStruct* S)
{
  return sf_internal_get_sim_state_c6_AllinOne(S);
}

static void sf_opaque_set_sim_state_c6_AllinOne(SimStruct* S, const mxArray *st)
{
  sf_internal_set_sim_state_c6_AllinOne(S, st);
}

static void sf_opaque_terminate_c6_AllinOne(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc6_AllinOneInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllinOne_optimization_info();
    }

    finalize_c6_AllinOne((SFc6_AllinOneInstanceStruct*) chartInstanceVar);
    utFree((void *)chartInstanceVar);
    if (crtInfo != NULL) {
      utFree((void *)crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc6_AllinOne((SFc6_AllinOneInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c6_AllinOne(SimStruct *S)
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
    initialize_params_c6_AllinOne((SFc6_AllinOneInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c6_AllinOne(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_AllinOne_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,6);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,6,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,6,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,6);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,6,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,6,2);
    }

    ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,6);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(987000536U));
  ssSetChecksum1(S,(3572285956U));
  ssSetChecksum2(S,(913540024U));
  ssSetChecksum3(S,(3978753783U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c6_AllinOne(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c6_AllinOne(SimStruct *S)
{
  SFc6_AllinOneInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc6_AllinOneInstanceStruct *)utMalloc(sizeof
    (SFc6_AllinOneInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc6_AllinOneInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c6_AllinOne;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c6_AllinOne;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c6_AllinOne;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c6_AllinOne;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c6_AllinOne;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c6_AllinOne;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c6_AllinOne;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c6_AllinOne;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c6_AllinOne;
  chartInstance->chartInfo.mdlStart = mdlStart_c6_AllinOne;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c6_AllinOne;
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

void c6_AllinOne_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c6_AllinOne(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c6_AllinOne(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c6_AllinOne(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c6_AllinOne_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
