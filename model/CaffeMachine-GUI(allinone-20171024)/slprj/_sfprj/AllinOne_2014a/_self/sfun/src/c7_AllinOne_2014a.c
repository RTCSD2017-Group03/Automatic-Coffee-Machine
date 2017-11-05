/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllinOne_2014a_sfun.h"
#include "c7_AllinOne_2014a.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "AllinOne_2014a_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c7_event_Tick                  (0)
#define c7_event_LocalFinishEvent      (2)
#define CALL_EVENT                     (-1)
#define c7_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c7_IN_Adding                   ((uint8_T)1U)
#define c7_IN_Finished                 ((uint8_T)2U)
#define c7_IN_Waiting                  ((uint8_T)3U)
#define c7_b_IN_Finished               ((uint8_T)1U)
#define c7_IN_Mixing                   ((uint8_T)2U)
#define c7_IN_Output                   ((uint8_T)3U)
#define c7_b_IN_Waiting                ((uint8_T)4U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c7_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_d_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_g_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_s_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_u_debug_family_names[2] = { "nargin", "nargout" };

static const char * c7_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_gb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_hb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_ib_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_jb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_kb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c7_lb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static boolean_T c7_dataWrittenToVector[1];

/* Function Declarations */
static void initialize_c7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance);
static void initialize_params_c7_AllinOne_2014a
  (SFc7_AllinOne_2014aInstanceStruct *chartInstance);
static void enable_c7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance);
static void disable_c7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance);
static void c7_update_debugger_state_c7_AllinOne_2014a
  (SFc7_AllinOne_2014aInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c7_AllinOne_2014a
  (SFc7_AllinOne_2014aInstanceStruct *chartInstance);
static void set_sim_state_c7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_st);
static void c7_set_sim_state_side_effects_c7_AllinOne_2014a
  (SFc7_AllinOne_2014aInstanceStruct *chartInstance);
static void finalize_c7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance);
static void sf_gateway_c7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance);
static void c7_c7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance);
static void initSimStructsc7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance);
static void c7_WaterState(SFc7_AllinOne_2014aInstanceStruct *chartInstance);
static void c7_Mix(SFc7_AllinOne_2014aInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber);
static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData);
static real_T c7_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_nargout, const char_T *c7_identifier);
static real_T c7_b_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static boolean_T c7_c_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_sf_internal_predicateOutput, const char_T
  *c7_identifier);
static boolean_T c7_d_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static void c7_broadcast_LocalFinishEvent(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance);
static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int8_T c7_e_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static uint32_T c7_f_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_b_MixFinishEventEventCounter, const char_T
  *c7_identifier);
static uint32_T c7_g_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static int32_T c7_h_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_f_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData);
static uint8_T c7_i_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_b_tp_WaterState, const char_T *c7_identifier);
static uint8_T c7_j_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData);
static const mxArray *c7_k_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_b_setSimStateSideEffectsInfo, const char_T
  *c7_identifier);
static const mxArray *c7_l_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId);
static void c7_updateDataWrittenToVector(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, uint32_T c7_vectorIndex);
static void init_dsm_address_info(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[2];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 0.0;
  real_T *c7_OutputSwitch;
  boolean_T *c7_MixFinishEvent;
  c7_MixFinishEvent = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_OutputSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c7_doSetSimStateSideEffects = 0U;
  chartInstance->c7_setSimStateSideEffectsInfo = NULL;
  chartInstance->c7_is_active_CoffeeState = 0U;
  chartInstance->c7_is_CoffeeState = c7_IN_NO_ACTIVE_CHILD;
  chartInstance->c7_tp_CoffeeState = 0U;
  chartInstance->c7_b_tp_Adding = 0U;
  chartInstance->c7_b_tp_Finished = 0U;
  chartInstance->c7_b_tp_Waiting = 0U;
  chartInstance->c7_is_active_MilkState = 0U;
  chartInstance->c7_is_MilkState = c7_IN_NO_ACTIVE_CHILD;
  chartInstance->c7_tp_MilkState = 0U;
  chartInstance->c7_c_tp_Adding = 0U;
  chartInstance->c7_c_tp_Finished = 0U;
  chartInstance->c7_c_tp_Waiting = 0U;
  chartInstance->c7_is_active_Mix = 0U;
  chartInstance->c7_is_Mix = c7_IN_NO_ACTIVE_CHILD;
  chartInstance->c7_tp_Mix = 0U;
  chartInstance->c7_e_tp_Finished = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_Mixing = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_tp_Output = 0U;
  chartInstance->c7_temporalCounter_i1 = 0U;
  chartInstance->c7_e_tp_Waiting = 0U;
  chartInstance->c7_is_active_SugarState = 0U;
  chartInstance->c7_is_SugarState = c7_IN_NO_ACTIVE_CHILD;
  chartInstance->c7_tp_SugarState = 0U;
  chartInstance->c7_d_tp_Adding = 0U;
  chartInstance->c7_d_tp_Finished = 0U;
  chartInstance->c7_d_tp_Waiting = 0U;
  chartInstance->c7_is_active_WaterState = 0U;
  chartInstance->c7_is_WaterState = c7_IN_NO_ACTIVE_CHILD;
  chartInstance->c7_tp_WaterState = 0U;
  chartInstance->c7_tp_Adding = 0U;
  chartInstance->c7_tp_Finished = 0U;
  chartInstance->c7_tp_Waiting = 0U;
  chartInstance->c7_is_active_c7_AllinOne_2014a = 0U;
  chartInstance->c7_MixFinishEventEventCounter = 0U;
  *c7_MixFinishEvent = false;
  chartInstance->c7_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  chartInstance->c7_is_active_c7_AllinOne_2014a = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  chartInstance->c7_is_active_WaterState = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c7_sfEvent);
  chartInstance->c7_tp_WaterState = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
  chartInstance->c7_is_WaterState = c7_IN_Waiting;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c7_sfEvent);
  chartInstance->c7_tp_Waiting = 1U;
  chartInstance->c7_is_active_CoffeeState = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
  chartInstance->c7_tp_CoffeeState = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c7_sfEvent);
  chartInstance->c7_is_CoffeeState = c7_IN_Waiting;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
  chartInstance->c7_b_tp_Waiting = 1U;
  chartInstance->c7_is_active_MilkState = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c7_sfEvent);
  chartInstance->c7_tp_MilkState = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c7_sfEvent);
  chartInstance->c7_is_MilkState = c7_IN_Waiting;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c7_sfEvent);
  chartInstance->c7_c_tp_Waiting = 1U;
  chartInstance->c7_is_active_SugarState = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c7_sfEvent);
  chartInstance->c7_tp_SugarState = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 14U, chartInstance->c7_sfEvent);
  chartInstance->c7_is_SugarState = c7_IN_Waiting;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c7_sfEvent);
  chartInstance->c7_d_tp_Waiting = 1U;
  chartInstance->c7_is_active_Mix = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c7_sfEvent);
  chartInstance->c7_tp_Mix = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 16U, chartInstance->c7_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_s_debug_family_names,
    c7_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_sf_marshallOut,
    c7_sf_marshallIn);
  *c7_OutputSwitch = 0.0;
  c7_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*c7_OutputSwitch, 4U);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c7_is_Mix = c7_b_IN_Waiting;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c7_sfEvent);
  chartInstance->c7_e_tp_Waiting = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_AllinOne_2014aMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initialize_params_c7_AllinOne_2014a
  (SFc7_AllinOne_2014aInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c7_update_debugger_state_c7_AllinOne_2014a
  (SFc7_AllinOne_2014aInstanceStruct *chartInstance)
{
  uint32_T c7_prevAniVal;
  c7_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c7_is_active_c7_AllinOne_2014a == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 6U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_active_WaterState == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 17U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 17U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_WaterState == c7_IN_Waiting) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_WaterState == c7_IN_Adding) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_WaterState == c7_IN_Finished) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_active_CoffeeState == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_CoffeeState == c7_IN_Waiting) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_CoffeeState == c7_IN_Adding) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_CoffeeState == c7_IN_Finished) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_active_MilkState == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_MilkState == c7_IN_Waiting) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_MilkState == c7_IN_Adding) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_MilkState == c7_IN_Finished) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_active_SugarState == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 13U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 13U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_SugarState == c7_IN_Waiting) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_SugarState == c7_IN_Adding) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_SugarState == c7_IN_Finished) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_active_Mix == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_Mix == c7_b_IN_Waiting) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_Mix == c7_IN_Mixing) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_Mix == c7_IN_Output) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_Mix == c7_b_IN_Finished) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c7_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c7_sfEvent);
  }

  _SFD_SET_ANIMATION(c7_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c7_AllinOne_2014a
  (SFc7_AllinOne_2014aInstanceStruct *chartInstance)
{
  const mxArray *c7_st;
  const mxArray *c7_y = NULL;
  real_T c7_hoistedGlobal;
  real_T c7_u;
  const mxArray *c7_b_y = NULL;
  boolean_T c7_b_hoistedGlobal;
  boolean_T c7_b_u;
  const mxArray *c7_c_y = NULL;
  uint32_T c7_c_hoistedGlobal;
  uint32_T c7_c_u;
  const mxArray *c7_d_y = NULL;
  uint8_T c7_d_hoistedGlobal;
  uint8_T c7_d_u;
  const mxArray *c7_e_y = NULL;
  uint8_T c7_e_hoistedGlobal;
  uint8_T c7_e_u;
  const mxArray *c7_f_y = NULL;
  uint8_T c7_f_hoistedGlobal;
  uint8_T c7_f_u;
  const mxArray *c7_g_y = NULL;
  uint8_T c7_g_hoistedGlobal;
  uint8_T c7_g_u;
  const mxArray *c7_h_y = NULL;
  uint8_T c7_h_hoistedGlobal;
  uint8_T c7_h_u;
  const mxArray *c7_i_y = NULL;
  uint8_T c7_i_hoistedGlobal;
  uint8_T c7_i_u;
  const mxArray *c7_j_y = NULL;
  uint8_T c7_j_hoistedGlobal;
  uint8_T c7_j_u;
  const mxArray *c7_k_y = NULL;
  uint8_T c7_k_hoistedGlobal;
  uint8_T c7_k_u;
  const mxArray *c7_l_y = NULL;
  uint8_T c7_l_hoistedGlobal;
  uint8_T c7_l_u;
  const mxArray *c7_m_y = NULL;
  uint8_T c7_m_hoistedGlobal;
  uint8_T c7_m_u;
  const mxArray *c7_n_y = NULL;
  uint8_T c7_n_hoistedGlobal;
  uint8_T c7_n_u;
  const mxArray *c7_o_y = NULL;
  uint8_T c7_o_hoistedGlobal;
  uint8_T c7_o_u;
  const mxArray *c7_p_y = NULL;
  real_T *c7_OutputSwitch;
  boolean_T *c7_MixFinishEvent;
  c7_MixFinishEvent = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_OutputSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_st = NULL;
  c7_st = NULL;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_createcellmatrix(15, 1), false);
  c7_hoistedGlobal = *c7_OutputSwitch;
  c7_u = c7_hoistedGlobal;
  c7_b_y = NULL;
  sf_mex_assign(&c7_b_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 0, c7_b_y);
  c7_b_hoistedGlobal = *c7_MixFinishEvent;
  c7_b_u = c7_b_hoistedGlobal;
  c7_c_y = NULL;
  sf_mex_assign(&c7_c_y, sf_mex_create("y", &c7_b_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 1, c7_c_y);
  c7_c_hoistedGlobal = chartInstance->c7_MixFinishEventEventCounter;
  c7_c_u = c7_c_hoistedGlobal;
  c7_d_y = NULL;
  sf_mex_assign(&c7_d_y, sf_mex_create("y", &c7_c_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 2, c7_d_y);
  c7_d_hoistedGlobal = chartInstance->c7_is_active_c7_AllinOne_2014a;
  c7_d_u = c7_d_hoistedGlobal;
  c7_e_y = NULL;
  sf_mex_assign(&c7_e_y, sf_mex_create("y", &c7_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 3, c7_e_y);
  c7_e_hoistedGlobal = chartInstance->c7_is_active_WaterState;
  c7_e_u = c7_e_hoistedGlobal;
  c7_f_y = NULL;
  sf_mex_assign(&c7_f_y, sf_mex_create("y", &c7_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 4, c7_f_y);
  c7_f_hoistedGlobal = chartInstance->c7_is_active_CoffeeState;
  c7_f_u = c7_f_hoistedGlobal;
  c7_g_y = NULL;
  sf_mex_assign(&c7_g_y, sf_mex_create("y", &c7_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 5, c7_g_y);
  c7_g_hoistedGlobal = chartInstance->c7_is_active_MilkState;
  c7_g_u = c7_g_hoistedGlobal;
  c7_h_y = NULL;
  sf_mex_assign(&c7_h_y, sf_mex_create("y", &c7_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 6, c7_h_y);
  c7_h_hoistedGlobal = chartInstance->c7_is_active_SugarState;
  c7_h_u = c7_h_hoistedGlobal;
  c7_i_y = NULL;
  sf_mex_assign(&c7_i_y, sf_mex_create("y", &c7_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 7, c7_i_y);
  c7_i_hoistedGlobal = chartInstance->c7_is_active_Mix;
  c7_i_u = c7_i_hoistedGlobal;
  c7_j_y = NULL;
  sf_mex_assign(&c7_j_y, sf_mex_create("y", &c7_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 8, c7_j_y);
  c7_j_hoistedGlobal = chartInstance->c7_is_WaterState;
  c7_j_u = c7_j_hoistedGlobal;
  c7_k_y = NULL;
  sf_mex_assign(&c7_k_y, sf_mex_create("y", &c7_j_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 9, c7_k_y);
  c7_k_hoistedGlobal = chartInstance->c7_is_CoffeeState;
  c7_k_u = c7_k_hoistedGlobal;
  c7_l_y = NULL;
  sf_mex_assign(&c7_l_y, sf_mex_create("y", &c7_k_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 10, c7_l_y);
  c7_l_hoistedGlobal = chartInstance->c7_is_MilkState;
  c7_l_u = c7_l_hoistedGlobal;
  c7_m_y = NULL;
  sf_mex_assign(&c7_m_y, sf_mex_create("y", &c7_l_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 11, c7_m_y);
  c7_m_hoistedGlobal = chartInstance->c7_is_SugarState;
  c7_m_u = c7_m_hoistedGlobal;
  c7_n_y = NULL;
  sf_mex_assign(&c7_n_y, sf_mex_create("y", &c7_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 12, c7_n_y);
  c7_n_hoistedGlobal = chartInstance->c7_is_Mix;
  c7_n_u = c7_n_hoistedGlobal;
  c7_o_y = NULL;
  sf_mex_assign(&c7_o_y, sf_mex_create("y", &c7_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 13, c7_o_y);
  c7_o_hoistedGlobal = chartInstance->c7_temporalCounter_i1;
  c7_o_u = c7_o_hoistedGlobal;
  c7_p_y = NULL;
  sf_mex_assign(&c7_p_y, sf_mex_create("y", &c7_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c7_y, 14, c7_p_y);
  sf_mex_assign(&c7_st, c7_y, false);
  return c7_st;
}

static void set_sim_state_c7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_st)
{
  const mxArray *c7_u;
  real_T *c7_OutputSwitch;
  boolean_T *c7_MixFinishEvent;
  c7_MixFinishEvent = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_OutputSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c7_doneDoubleBufferReInit = true;
  c7_u = sf_mex_dup(c7_st);
  *c7_OutputSwitch = c7_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 0)), "OutputSwitch");
  *c7_MixFinishEvent = c7_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 1)), "MixFinishEvent");
  chartInstance->c7_MixFinishEventEventCounter = c7_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 2)),
     "MixFinishEventEventCounter");
  chartInstance->c7_is_active_c7_AllinOne_2014a = c7_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c7_u, 3)),
     "is_active_c7_AllinOne_2014a");
  chartInstance->c7_is_active_WaterState = c7_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 4)), "is_active_WaterState");
  chartInstance->c7_is_active_CoffeeState = c7_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 5)), "is_active_CoffeeState");
  chartInstance->c7_is_active_MilkState = c7_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 6)), "is_active_MilkState");
  chartInstance->c7_is_active_SugarState = c7_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 7)), "is_active_SugarState");
  chartInstance->c7_is_active_Mix = c7_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 8)), "is_active_Mix");
  chartInstance->c7_is_WaterState = c7_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 9)), "is_WaterState");
  chartInstance->c7_is_CoffeeState = c7_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 10)), "is_CoffeeState");
  chartInstance->c7_is_MilkState = c7_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 11)), "is_MilkState");
  chartInstance->c7_is_SugarState = c7_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 12)), "is_SugarState");
  chartInstance->c7_is_Mix = c7_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c7_u, 13)), "is_Mix");
  chartInstance->c7_temporalCounter_i1 = c7_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c7_u, 14)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c7_setSimStateSideEffectsInfo,
                c7_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c7_u, 15)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c7_u);
  chartInstance->c7_doSetSimStateSideEffects = 1U;
  c7_update_debugger_state_c7_AllinOne_2014a(chartInstance);
  sf_mex_destroy(&c7_st);
}

static void c7_set_sim_state_side_effects_c7_AllinOne_2014a
  (SFc7_AllinOne_2014aInstanceStruct *chartInstance)
{
  if (chartInstance->c7_doSetSimStateSideEffects != 0) {
    if (chartInstance->c7_is_active_WaterState == 1U) {
      chartInstance->c7_tp_WaterState = 1U;
    } else {
      chartInstance->c7_tp_WaterState = 0U;
    }

    if (chartInstance->c7_is_WaterState == c7_IN_Adding) {
      chartInstance->c7_tp_Adding = 1U;
    } else {
      chartInstance->c7_tp_Adding = 0U;
    }

    if (chartInstance->c7_is_WaterState == c7_IN_Finished) {
      chartInstance->c7_tp_Finished = 1U;
    } else {
      chartInstance->c7_tp_Finished = 0U;
    }

    if (chartInstance->c7_is_WaterState == c7_IN_Waiting) {
      chartInstance->c7_tp_Waiting = 1U;
    } else {
      chartInstance->c7_tp_Waiting = 0U;
    }

    if (chartInstance->c7_is_active_CoffeeState == 1U) {
      chartInstance->c7_tp_CoffeeState = 1U;
    } else {
      chartInstance->c7_tp_CoffeeState = 0U;
    }

    if (chartInstance->c7_is_CoffeeState == c7_IN_Adding) {
      chartInstance->c7_b_tp_Adding = 1U;
    } else {
      chartInstance->c7_b_tp_Adding = 0U;
    }

    if (chartInstance->c7_is_CoffeeState == c7_IN_Finished) {
      chartInstance->c7_b_tp_Finished = 1U;
    } else {
      chartInstance->c7_b_tp_Finished = 0U;
    }

    if (chartInstance->c7_is_CoffeeState == c7_IN_Waiting) {
      chartInstance->c7_b_tp_Waiting = 1U;
    } else {
      chartInstance->c7_b_tp_Waiting = 0U;
    }

    if (chartInstance->c7_is_active_MilkState == 1U) {
      chartInstance->c7_tp_MilkState = 1U;
    } else {
      chartInstance->c7_tp_MilkState = 0U;
    }

    if (chartInstance->c7_is_MilkState == c7_IN_Adding) {
      chartInstance->c7_c_tp_Adding = 1U;
    } else {
      chartInstance->c7_c_tp_Adding = 0U;
    }

    if (chartInstance->c7_is_MilkState == c7_IN_Finished) {
      chartInstance->c7_c_tp_Finished = 1U;
    } else {
      chartInstance->c7_c_tp_Finished = 0U;
    }

    if (chartInstance->c7_is_MilkState == c7_IN_Waiting) {
      chartInstance->c7_c_tp_Waiting = 1U;
    } else {
      chartInstance->c7_c_tp_Waiting = 0U;
    }

    if (chartInstance->c7_is_active_SugarState == 1U) {
      chartInstance->c7_tp_SugarState = 1U;
    } else {
      chartInstance->c7_tp_SugarState = 0U;
    }

    if (chartInstance->c7_is_SugarState == c7_IN_Adding) {
      chartInstance->c7_d_tp_Adding = 1U;
    } else {
      chartInstance->c7_d_tp_Adding = 0U;
    }

    if (chartInstance->c7_is_SugarState == c7_IN_Finished) {
      chartInstance->c7_d_tp_Finished = 1U;
    } else {
      chartInstance->c7_d_tp_Finished = 0U;
    }

    if (chartInstance->c7_is_SugarState == c7_IN_Waiting) {
      chartInstance->c7_d_tp_Waiting = 1U;
    } else {
      chartInstance->c7_d_tp_Waiting = 0U;
    }

    if (chartInstance->c7_is_active_Mix == 1U) {
      chartInstance->c7_tp_Mix = 1U;
    } else {
      chartInstance->c7_tp_Mix = 0U;
    }

    if (chartInstance->c7_is_Mix == c7_b_IN_Finished) {
      chartInstance->c7_e_tp_Finished = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 19) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_e_tp_Finished = 0U;
    }

    if (chartInstance->c7_is_Mix == c7_IN_Mixing) {
      chartInstance->c7_tp_Mixing = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 20) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_Mixing = 0U;
    }

    if (chartInstance->c7_is_Mix == c7_IN_Output) {
      chartInstance->c7_tp_Output = 1U;
      if (sf_mex_sub(chartInstance->c7_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 21) == 0.0) {
        chartInstance->c7_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c7_tp_Output = 0U;
    }

    if (chartInstance->c7_is_Mix == c7_b_IN_Waiting) {
      chartInstance->c7_e_tp_Waiting = 1U;
    } else {
      chartInstance->c7_e_tp_Waiting = 0U;
    }

    chartInstance->c7_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c7_setSimStateSideEffectsInfo);
}

static void sf_gateway_c7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance)
{
  real_T *c7_CoffeeInput;
  real_T *c7_MilkInput;
  real_T *c7_SugarInput;
  real_T *c7_WaterInput;
  real_T *c7_OutputSwitch;
  boolean_T *c7_MixFinishEvent;
  c7_MixFinishEvent = (boolean_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c7_OutputSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c7_WaterInput = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  c7_SugarInput = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c7_MilkInput = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c7_CoffeeInput = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  c7_set_sim_state_side_effects_c7_AllinOne_2014a(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c7_CoffeeInput, 0U);
  _SFD_DATA_RANGE_CHECK(*c7_MilkInput, 1U);
  _SFD_DATA_RANGE_CHECK(*c7_SugarInput, 2U);
  _SFD_DATA_RANGE_CHECK(*c7_WaterInput, 3U);
  _SFD_DATA_RANGE_CHECK(*c7_OutputSwitch, 4U);
  if (chartInstance->c7_temporalCounter_i1 < 15U) {
    chartInstance->c7_temporalCounter_i1++;
  }

  chartInstance->c7_sfEvent = c7_event_Tick;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c7_event_Tick,
               chartInstance->c7_sfEvent);
  c7_c7_AllinOne_2014a(chartInstance);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c7_event_Tick,
               chartInstance->c7_sfEvent);
  if (chartInstance->c7_MixFinishEventEventCounter > 0U) {
    *c7_MixFinishEvent = !*c7_MixFinishEvent;
    chartInstance->c7_MixFinishEventEventCounter--;
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_AllinOne_2014aMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void c7_c7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 1.0;
  boolean_T c7_b_out;
  real_T c7_c_nargin = 0.0;
  real_T c7_c_nargout = 1.0;
  boolean_T c7_c_out;
  real_T c7_d_nargin = 0.0;
  real_T c7_d_nargout = 1.0;
  boolean_T c7_d_out;
  real_T c7_e_nargin = 0.0;
  real_T c7_e_nargout = 1.0;
  boolean_T c7_e_out;
  real_T c7_f_nargin = 0.0;
  real_T c7_f_nargout = 1.0;
  boolean_T c7_f_out;
  real_T c7_g_nargin = 0.0;
  real_T c7_g_nargout = 1.0;
  boolean_T c7_g_out;
  real_T c7_h_nargin = 0.0;
  real_T c7_h_nargout = 1.0;
  boolean_T c7_h_out;
  real_T c7_i_nargin = 0.0;
  real_T c7_i_nargout = 1.0;
  boolean_T c7_i_out;
  real_T *c7_CoffeeInput;
  real_T *c7_MilkInput;
  real_T *c7_SugarInput;
  c7_SugarInput = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c7_MilkInput = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c7_CoffeeInput = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
  if (chartInstance->c7_is_active_WaterState == 0U) {
  } else {
    c7_WaterState(chartInstance);
  }

  if (chartInstance->c7_is_active_CoffeeState == 0U) {
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c7_sfEvent);
    switch (chartInstance->c7_is_CoffeeState) {
     case c7_IN_Adding:
      CV_STATE_EVAL(0, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_i_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      c7_out = CV_EML_IF(7, 0, 0, *c7_CoffeeInput < 1.0E-5);
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c7_sfEvent);
        chartInstance->c7_b_tp_Adding = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_CoffeeState = c7_IN_Finished;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c7_sfEvent);
        chartInstance->c7_b_tp_Finished = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                     chartInstance->c7_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c7_sfEvent);
      break;

     case c7_IN_Finished:
      CV_STATE_EVAL(0, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_g_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_out, 2U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      c7_b_out = CV_EML_IF(4, 0, 0, chartInstance->c7_sfEvent ==
                           c7_event_LocalFinishEvent);
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c7_sfEvent);
        chartInstance->c7_b_tp_Finished = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_CoffeeState = c7_IN_Waiting;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
        chartInstance->c7_b_tp_Waiting = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                     chartInstance->c7_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c7_sfEvent);
      break;

     case c7_IN_Waiting:
      CV_STATE_EVAL(0, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_h_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_out, 2U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      c7_c_out = CV_EML_IF(5, 0, 0, *c7_CoffeeInput > 1.0E-5);
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c7_sfEvent);
        chartInstance->c7_b_tp_Waiting = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_CoffeeState = c7_IN_Adding;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
        chartInstance->c7_b_tp_Adding = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                     chartInstance->c7_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c7_sfEvent);
      break;

     default:
      CV_STATE_EVAL(0, 0, 0);
      chartInstance->c7_is_CoffeeState = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_active_MilkState == 0U) {
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c7_sfEvent);
    switch (chartInstance->c7_is_MilkState) {
     case c7_IN_Adding:
      CV_STATE_EVAL(4, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                   chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_l_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_out, 2U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      c7_d_out = CV_EML_IF(11, 0, 0, *c7_MilkInput < 1.0E-5);
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c7_sfEvent);
        chartInstance->c7_c_tp_Adding = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_MilkState = c7_IN_Finished;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c7_sfEvent);
        chartInstance->c7_c_tp_Finished = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                     chartInstance->c7_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c7_sfEvent);
      break;

     case c7_IN_Finished:
      CV_STATE_EVAL(4, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                   chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_j_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_out, 2U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      c7_e_out = CV_EML_IF(8, 0, 0, chartInstance->c7_sfEvent ==
                           c7_event_LocalFinishEvent);
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c7_sfEvent);
        chartInstance->c7_c_tp_Finished = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_MilkState = c7_IN_Waiting;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c7_sfEvent);
        chartInstance->c7_c_tp_Waiting = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     chartInstance->c7_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
      break;

     case c7_IN_Waiting:
      CV_STATE_EVAL(4, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                   chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_k_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_out, 2U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      c7_f_out = CV_EML_IF(9, 0, 0, *c7_MilkInput > 1.0E-5);
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c7_sfEvent);
        chartInstance->c7_c_tp_Waiting = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_MilkState = c7_IN_Adding;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c7_sfEvent);
        chartInstance->c7_c_tp_Adding = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                     chartInstance->c7_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c7_sfEvent);
      break;

     default:
      CV_STATE_EVAL(4, 0, 0);
      chartInstance->c7_is_MilkState = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c7_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_active_SugarState == 0U) {
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 13U, chartInstance->c7_sfEvent);
    switch (chartInstance->c7_is_SugarState) {
     case c7_IN_Adding:
      CV_STATE_EVAL(13, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 15U,
                   chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_o_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_g_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_g_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_g_out, 2U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      c7_g_out = CV_EML_IF(15, 0, 0, *c7_SugarInput < 1.0E-5);
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_g_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 15U, chartInstance->c7_sfEvent);
        chartInstance->c7_d_tp_Adding = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_SugarState = c7_IN_Finished;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 15U, chartInstance->c7_sfEvent);
        chartInstance->c7_d_tp_Finished = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 14U,
                     chartInstance->c7_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c7_sfEvent);
      break;

     case c7_IN_Finished:
      CV_STATE_EVAL(13, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                   chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_m_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_h_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_h_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_h_out, 2U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      c7_h_out = CV_EML_IF(12, 0, 0, chartInstance->c7_sfEvent ==
                           c7_event_LocalFinishEvent);
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_h_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c7_sfEvent);
        chartInstance->c7_d_tp_Finished = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 15U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_SugarState = c7_IN_Waiting;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 16U, chartInstance->c7_sfEvent);
        chartInstance->c7_d_tp_Waiting = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 15U,
                     chartInstance->c7_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c7_sfEvent);
      break;

     case c7_IN_Waiting:
      CV_STATE_EVAL(13, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                   chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_n_debug_family_names,
        c7_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_i_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_i_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_i_out, 2U, c7_b_sf_marshallOut,
        c7_b_sf_marshallIn);
      c7_i_out = CV_EML_IF(13, 0, 0, *c7_SugarInput > 1.0E-5);
      _SFD_SYMBOL_SCOPE_POP();
      if (c7_i_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c7_sfEvent);
        chartInstance->c7_d_tp_Waiting = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 16U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_SugarState = c7_IN_Adding;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 14U, chartInstance->c7_sfEvent);
        chartInstance->c7_d_tp_Adding = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 16U,
                     chartInstance->c7_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c7_sfEvent);
      break;

     default:
      CV_STATE_EVAL(13, 0, 0);
      chartInstance->c7_is_SugarState = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 14U, chartInstance->c7_sfEvent);
      break;
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 13U, chartInstance->c7_sfEvent);
  }

  if (chartInstance->c7_is_active_Mix == 0U) {
  } else {
    c7_Mix(chartInstance);
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c7_sfEvent);
}

static void initSimStructsc7_AllinOne_2014a(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c7_WaterState(SFc7_AllinOne_2014aInstanceStruct *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 1.0;
  boolean_T c7_b_out;
  real_T c7_c_nargin = 0.0;
  real_T c7_c_nargout = 1.0;
  boolean_T c7_c_out;
  real_T *c7_WaterInput;
  c7_WaterInput = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c7_sfEvent);
  switch (chartInstance->c7_is_WaterState) {
   case c7_IN_Adding:
    CV_STATE_EVAL(17, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_f_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_out = CV_EML_IF(2, 0, 0, *c7_WaterInput < 1.0E-5);
    _SFD_SYMBOL_SCOPE_POP();
    if (c7_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_Adding = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c7_sfEvent);
      chartInstance->c7_is_WaterState = c7_IN_Finished;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 19U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_Finished = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 18U,
                   chartInstance->c7_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_Finished:
    CV_STATE_EVAL(17, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_d_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_out, 2U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_b_out = CV_EML_IF(3, 0, 0, chartInstance->c7_sfEvent ==
                         c7_event_LocalFinishEvent);
    _SFD_SYMBOL_SCOPE_POP();
    if (c7_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_Finished = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 19U, chartInstance->c7_sfEvent);
      chartInstance->c7_is_WaterState = c7_IN_Waiting;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 20U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_Waiting = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 19U,
                   chartInstance->c7_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_Waiting:
    CV_STATE_EVAL(17, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_e_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargin, 0U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargout, 1U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_out, 2U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_c_out = CV_EML_IF(1, 0, 0, *c7_WaterInput > 1.0E-5);
    _SFD_SYMBOL_SCOPE_POP();
    if (c7_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_Waiting = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 20U, chartInstance->c7_sfEvent);
      chartInstance->c7_is_WaterState = c7_IN_Adding;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 18U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_Adding = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 20U,
                   chartInstance->c7_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 20U, chartInstance->c7_sfEvent);
    break;

   default:
    CV_STATE_EVAL(17, 0, 0);
    chartInstance->c7_is_WaterState = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 18U, chartInstance->c7_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c7_sfEvent);
}

static void c7_Mix(SFc7_AllinOne_2014aInstanceStruct *chartInstance)
{
  uint32_T c7_debug_family_var_map[3];
  real_T c7_nargin = 0.0;
  real_T c7_nargout = 1.0;
  boolean_T c7_out;
  uint32_T c7_b_debug_family_var_map[2];
  real_T c7_b_nargin = 0.0;
  real_T c7_b_nargout = 0.0;
  real_T c7_c_nargin = 0.0;
  real_T c7_c_nargout = 1.0;
  boolean_T c7_b_out;
  real_T c7_d_nargin = 0.0;
  real_T c7_d_nargout = 0.0;
  real_T c7_e_nargin = 0.0;
  real_T c7_e_nargout = 1.0;
  boolean_T c7_c_out;
  real_T c7_f_nargin = 0.0;
  real_T c7_f_nargout = 0.0;
  real_T c7_g_nargin = 0.0;
  real_T c7_g_nargout = 0.0;
  real_T c7_h_nargin = 0.0;
  real_T c7_h_nargout = 1.0;
  boolean_T c7_d_out;
  real_T *c7_OutputSwitch;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T guard9 = false;
  c7_OutputSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c7_sfEvent);
  switch (chartInstance->c7_is_Mix) {
   case c7_b_IN_Finished:
    CV_STATE_EVAL(8, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 19U,
                 chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_t_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargin, 0U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_nargout, 1U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_out, 2U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    guard6 = false;
    guard7 = false;
    guard8 = false;
    guard9 = false;
    if (CV_EML_COND(19, 0, 0, chartInstance->c7_temporalCounter_i1 >= 10)) {
      if (CV_EML_COND(19, 0, 1, chartInstance->c7_is_WaterState == c7_IN_Waiting))
      {
        if (CV_EML_COND(19, 0, 2, chartInstance->c7_is_CoffeeState ==
                        c7_IN_Waiting)) {
          if (CV_EML_COND(19, 0, 3, chartInstance->c7_is_MilkState ==
                          c7_IN_Waiting)) {
            if (CV_EML_COND(19, 0, 4, chartInstance->c7_is_SugarState ==
                            c7_IN_Waiting)) {
              CV_EML_MCDC(19, 0, 0, true);
              CV_EML_IF(19, 0, 0, true);
              c7_out = true;
            } else {
              guard6 = true;
            }
          } else {
            guard7 = true;
          }
        } else {
          guard8 = true;
        }
      } else {
        guard9 = true;
      }
    } else {
      guard9 = true;
    }

    if (guard9 == true) {
      guard8 = true;
    }

    if (guard8 == true) {
      guard7 = true;
    }

    if (guard7 == true) {
      guard6 = true;
    }

    if (guard6 == true) {
      CV_EML_MCDC(19, 0, 0, false);
      CV_EML_IF(19, 0, 0, false);
      c7_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    guard5 = false;
    if (c7_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 19U, chartInstance->c7_sfEvent);
      chartInstance->c7_e_tp_Finished = 0U;
      chartInstance->c7_is_Mix = c7_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c7_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_u_debug_family_names,
        c7_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      chartInstance->c7_MixFinishEventEventCounter++;
      c7_broadcast_LocalFinishEvent(chartInstance);
      if (chartInstance->c7_is_Mix == c7_IN_NO_ACTIVE_CHILD) {
        if (chartInstance->c7_is_active_Mix == 0) {
        } else {
          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      if (chartInstance->c7_is_Mix == c7_IN_NO_ACTIVE_CHILD) {
        if (chartInstance->c7_is_active_Mix == 0U) {
          _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 19U, chartInstance->c7_sfEvent);
        } else {
          chartInstance->c7_is_Mix = c7_b_IN_Waiting;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c7_sfEvent);
          chartInstance->c7_e_tp_Waiting = 1U;
          guard5 = true;
        }
      } else {
        _SFD_CT_CALL(TRANSITION_INACTIVE_TAG, 19U, chartInstance->c7_sfEvent);
      }
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c7_sfEvent);
      guard5 = true;
    }

    if (guard5 == true) {
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c7_sfEvent);
    }
    break;

   case c7_IN_Mixing:
    CV_STATE_EVAL(8, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 18U,
                 chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_r_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargin, 0U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_nargout, 1U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_b_out, 2U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_b_out = CV_EML_IF(18, 0, 0, (chartInstance->c7_sfEvent == c7_event_Tick) &&
                         (chartInstance->c7_temporalCounter_i1 >= 5));
    _SFD_SYMBOL_SCOPE_POP();
    if (c7_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 18U, chartInstance->c7_sfEvent);
      chartInstance->c7_tp_Mixing = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c7_sfEvent);
      chartInstance->c7_is_Mix = c7_IN_Output;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c7_sfEvent);
      chartInstance->c7_temporalCounter_i1 = 0U;
      chartInstance->c7_tp_Output = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_debug_family_names,
        c7_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargin, 0U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_nargout, 1U, c7_sf_marshallOut,
        c7_sf_marshallIn);
      *c7_OutputSwitch = 1.0;
      c7_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(*c7_OutputSwitch, 4U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U,
                   chartInstance->c7_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c7_sfEvent);
    break;

   case c7_IN_Output:
    CV_STATE_EVAL(8, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 20U,
                 chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_q_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargin, 0U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_e_nargout, 1U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_c_out, 2U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    c7_c_out = CV_EML_IF(20, 0, 0, (chartInstance->c7_sfEvent == c7_event_Tick) &&
                         (chartInstance->c7_temporalCounter_i1 >= 5));
    _SFD_SYMBOL_SCOPE_POP();
    guard4 = false;
    if (c7_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 20U, chartInstance->c7_sfEvent);
      if (chartInstance->c7_is_Mix != c7_IN_Output) {
      } else {
        chartInstance->c7_tp_Output = 0U;
        _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 11U,
                     chartInstance->c7_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_b_debug_family_names,
          c7_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargin, 0U, c7_sf_marshallOut,
          c7_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_f_nargout, 1U,
          c7_sf_marshallOut, c7_sf_marshallIn);
        *c7_OutputSwitch = 0.0;
        c7_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*c7_OutputSwitch, 4U);
        _SFD_SYMBOL_SCOPE_POP();
        _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c7_sfEvent);
        chartInstance->c7_is_Mix = c7_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c7_sfEvent);
      }

      if (chartInstance->c7_is_Mix == c7_b_IN_Finished) {
      } else {
        chartInstance->c7_is_Mix = c7_b_IN_Finished;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c7_sfEvent);
        chartInstance->c7_temporalCounter_i1 = 0U;
        chartInstance->c7_e_tp_Finished = 1U;
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c7_c_debug_family_names,
          c7_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_g_nargin, 0U, c7_sf_marshallOut,
          c7_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_g_nargout, 1U,
          c7_sf_marshallOut, c7_sf_marshallIn);
        chartInstance->c7_MixFinishEventEventCounter++;
        c7_broadcast_LocalFinishEvent(chartInstance);
        if (chartInstance->c7_is_Mix != c7_b_IN_Finished) {
        } else {
          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      if (chartInstance->c7_is_Mix != c7_b_IN_Finished) {
      } else {
        guard4 = true;
      }
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                   chartInstance->c7_sfEvent);
      guard4 = true;
    }

    if (guard4 == true) {
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c7_sfEvent);
    }
    break;

   case c7_b_IN_Waiting:
    CV_STATE_EVAL(8, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 17U,
                 chartInstance->c7_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c7_p_debug_family_names,
      c7_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_h_nargin, 0U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_h_nargout, 1U, c7_sf_marshallOut,
      c7_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c7_d_out, 2U, c7_b_sf_marshallOut,
      c7_b_sf_marshallIn);
    guard1 = false;
    guard2 = false;
    guard3 = false;
    if (CV_EML_COND(17, 0, 0, chartInstance->c7_is_WaterState == c7_IN_Finished))
    {
      if (CV_EML_COND(17, 0, 1, chartInstance->c7_is_CoffeeState ==
                      c7_IN_Finished)) {
        if (CV_EML_COND(17, 0, 2, chartInstance->c7_is_MilkState ==
                        c7_IN_Finished)) {
          if (CV_EML_COND(17, 0, 3, chartInstance->c7_is_SugarState ==
                          c7_IN_Finished)) {
            CV_EML_MCDC(17, 0, 0, true);
            CV_EML_IF(17, 0, 0, true);
            c7_d_out = true;
          } else {
            guard1 = true;
          }
        } else {
          guard2 = true;
        }
      } else {
        guard3 = true;
      }
    } else {
      guard3 = true;
    }

    if (guard3 == true) {
      guard2 = true;
    }

    if (guard2 == true) {
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(17, 0, 0, false);
      CV_EML_IF(17, 0, 0, false);
      c7_d_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c7_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 17U, chartInstance->c7_sfEvent);
      chartInstance->c7_e_tp_Waiting = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c7_sfEvent);
      chartInstance->c7_is_Mix = c7_IN_Mixing;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c7_sfEvent);
      chartInstance->c7_temporalCounter_i1 = 0U;
      chartInstance->c7_tp_Mixing = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                   chartInstance->c7_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c7_sfEvent);
    break;

   default:
    CV_STATE_EVAL(8, 0, 0);
    chartInstance->c7_is_Mix = c7_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c7_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c7_sfEvent);
}

static void init_script_number_translation(uint32_T c7_machineNumber, uint32_T
  c7_chartNumber, uint32_T c7_instanceNumber)
{
  (void)c7_machineNumber;
  (void)c7_chartNumber;
  (void)c7_instanceNumber;
}

static const mxArray *c7_sf_marshallOut(void *chartInstanceVoid, void *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  real_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_AllinOne_2014aInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllinOne_2014aInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(real_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static real_T c7_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_nargout, const char_T *c7_identifier)
{
  real_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_nargout), &c7_thisId);
  sf_mex_destroy(&c7_nargout);
  return c7_y;
}

static real_T c7_b_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  real_T c7_y;
  real_T c7_d0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_d0, 1, 0, 0U, 0, 0U, 0);
  c7_y = c7_d0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_nargout;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  real_T c7_y;
  SFc7_AllinOne_2014aInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllinOne_2014aInstanceStruct *)chartInstanceVoid;
  c7_nargout = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_nargout), &c7_thisId);
  sf_mex_destroy(&c7_nargout);
  *(real_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_b_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  boolean_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_AllinOne_2014aInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllinOne_2014aInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(boolean_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static boolean_T c7_c_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_sf_internal_predicateOutput, const char_T
  *c7_identifier)
{
  boolean_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_sf_internal_predicateOutput), &c7_thisId);
  sf_mex_destroy(&c7_sf_internal_predicateOutput);
  return c7_y;
}

static boolean_T c7_d_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  boolean_T c7_y;
  boolean_T c7_b0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_b0, 1, 11, 0U, 0, 0U, 0);
  c7_y = c7_b0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_sf_internal_predicateOutput;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  boolean_T c7_y;
  SFc7_AllinOne_2014aInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllinOne_2014aInstanceStruct *)chartInstanceVoid;
  c7_sf_internal_predicateOutput = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_sf_internal_predicateOutput), &c7_thisId);
  sf_mex_destroy(&c7_sf_internal_predicateOutput);
  *(boolean_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

const mxArray *sf_c7_AllinOne_2014a_get_eml_resolved_functions_info(void)
{
  const mxArray *c7_nameCaptureInfo = NULL;
  c7_nameCaptureInfo = NULL;
  sf_mex_assign(&c7_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c7_nameCaptureInfo;
}

static void c7_broadcast_LocalFinishEvent(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance)
{
  int32_T c7_previousEvent;
  c7_previousEvent = chartInstance->c7_sfEvent;
  chartInstance->c7_sfEvent = c7_event_LocalFinishEvent;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c7_event_LocalFinishEvent,
               chartInstance->c7_sfEvent);
  c7_c7_AllinOne_2014a(chartInstance);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c7_event_LocalFinishEvent,
               chartInstance->c7_sfEvent);
  chartInstance->c7_sfEvent = c7_previousEvent;
}

static const mxArray *c7_c_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int8_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_AllinOne_2014aInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllinOne_2014aInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int8_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static int8_T c7_e_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int8_T c7_y;
  int8_T c7_i0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i0, 1, 2, 0U, 0, 0U, 0);
  c7_y = c7_i0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_Tick;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int8_T c7_y;
  SFc7_AllinOne_2014aInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllinOne_2014aInstanceStruct *)chartInstanceVoid;
  c7_Tick = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_Tick), &c7_thisId);
  sf_mex_destroy(&c7_Tick);
  *(int8_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_d_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  uint32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_AllinOne_2014aInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllinOne_2014aInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(uint32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static uint32_T c7_f_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_b_MixFinishEventEventCounter, const char_T
  *c7_identifier)
{
  uint32_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_MixFinishEventEventCounter), &c7_thisId);
  sf_mex_destroy(&c7_b_MixFinishEventEventCounter);
  return c7_y;
}

static uint32_T c7_g_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint32_T c7_y;
  uint32_T c7_u0;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u0, 1, 7, 0U, 0, 0U, 0);
  c7_y = c7_u0;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_MixFinishEventEventCounter;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  uint32_T c7_y;
  SFc7_AllinOne_2014aInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllinOne_2014aInstanceStruct *)chartInstanceVoid;
  c7_b_MixFinishEventEventCounter = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_MixFinishEventEventCounter), &c7_thisId);
  sf_mex_destroy(&c7_b_MixFinishEventEventCounter);
  *(uint32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_e_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  int32_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_AllinOne_2014aInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllinOne_2014aInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(int32_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static int32_T c7_h_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  int32_T c7_y;
  int32_T c7_i1;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_i1, 1, 6, 0U, 0, 0U, 0);
  c7_y = c7_i1;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_sfEvent;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  int32_T c7_y;
  SFc7_AllinOne_2014aInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllinOne_2014aInstanceStruct *)chartInstanceVoid;
  c7_b_sfEvent = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_sfEvent),
    &c7_thisId);
  sf_mex_destroy(&c7_b_sfEvent);
  *(int32_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_f_sf_marshallOut(void *chartInstanceVoid, void
  *c7_inData)
{
  const mxArray *c7_mxArrayOutData = NULL;
  uint8_T c7_u;
  const mxArray *c7_y = NULL;
  SFc7_AllinOne_2014aInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllinOne_2014aInstanceStruct *)chartInstanceVoid;
  c7_mxArrayOutData = NULL;
  c7_u = *(uint8_T *)c7_inData;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_create("y", &c7_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c7_mxArrayOutData, c7_y, false);
  return c7_mxArrayOutData;
}

static uint8_T c7_i_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_b_tp_WaterState, const char_T *c7_identifier)
{
  uint8_T c7_y;
  emlrtMsgIdentifier c7_thisId;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_tp_WaterState),
    &c7_thisId);
  sf_mex_destroy(&c7_b_tp_WaterState);
  return c7_y;
}

static uint8_T c7_j_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  uint8_T c7_y;
  uint8_T c7_u1;
  (void)chartInstance;
  sf_mex_import(c7_parentId, sf_mex_dup(c7_u), &c7_u1, 1, 3, 0U, 0, 0U, 0);
  c7_y = c7_u1;
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c7_mxArrayInData, const char_T *c7_varName, void *c7_outData)
{
  const mxArray *c7_b_tp_WaterState;
  const char_T *c7_identifier;
  emlrtMsgIdentifier c7_thisId;
  uint8_T c7_y;
  SFc7_AllinOne_2014aInstanceStruct *chartInstance;
  chartInstance = (SFc7_AllinOne_2014aInstanceStruct *)chartInstanceVoid;
  c7_b_tp_WaterState = sf_mex_dup(c7_mxArrayInData);
  c7_identifier = c7_varName;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  c7_y = c7_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c7_b_tp_WaterState),
    &c7_thisId);
  sf_mex_destroy(&c7_b_tp_WaterState);
  *(uint8_T *)c7_outData = c7_y;
  sf_mex_destroy(&c7_mxArrayInData);
}

static const mxArray *c7_k_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_b_setSimStateSideEffectsInfo, const char_T
  *c7_identifier)
{
  const mxArray *c7_y = NULL;
  emlrtMsgIdentifier c7_thisId;
  c7_y = NULL;
  c7_thisId.fIdentifier = c7_identifier;
  c7_thisId.fParent = NULL;
  sf_mex_assign(&c7_y, c7_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c7_b_setSimStateSideEffectsInfo), &c7_thisId), false);
  sf_mex_destroy(&c7_b_setSimStateSideEffectsInfo);
  return c7_y;
}

static const mxArray *c7_l_emlrt_marshallIn(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, const mxArray *c7_u, const emlrtMsgIdentifier *c7_parentId)
{
  const mxArray *c7_y = NULL;
  (void)chartInstance;
  (void)c7_parentId;
  c7_y = NULL;
  sf_mex_assign(&c7_y, sf_mex_duplicatearraysafe(&c7_u), false);
  sf_mex_destroy(&c7_u);
  return c7_y;
}

static void c7_updateDataWrittenToVector(SFc7_AllinOne_2014aInstanceStruct
  *chartInstance, uint32_T c7_vectorIndex)
{
  (void)chartInstance;
  c7_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0, (int32_T)
    c7_vectorIndex, 0, 0, 1, 0)] = true;
}

static void init_dsm_address_info(SFc7_AllinOne_2014aInstanceStruct
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

void sf_c7_AllinOne_2014a_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2595567062U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(737808702U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(971298411U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(644844688U);
}

mxArray *sf_c7_AllinOne_2014a_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("yV8WQ4Xv82gcA7sjLJ8J7E");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c7_AllinOne_2014a_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c7_AllinOne_2014a_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

static const mxArray *sf_get_sim_state_info_c7_AllinOne_2014a(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[71],T\"OutputSwitch\",},{M[6],M[70],T\"MixFinishEvent\",},{M[7],M[70],T\"MixFinishEventEventCounter\",},{M[8],M[0],T\"is_active_c7_AllinOne_2014a\",},{M[8],M[26],T\"is_active_WaterState\",},{M[8],M[34],T\"is_active_CoffeeState\",},{M[8],M[42],T\"is_active_MilkState\",},{M[8],M[50],T\"is_active_SugarState\",},{M[8],M[58],T\"is_active_Mix\",},{M[9],M[26],T\"is_WaterState\",}}",
    "100 S1x5'type','srcId','name','auxInfo'{{M[9],M[34],T\"is_CoffeeState\",},{M[9],M[42],T\"is_MilkState\",},{M[9],M[50],T\"is_SugarState\",},{M[9],M[58],T\"is_Mix\",},{M[11],M[21],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x3[73 63 67],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 15, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c7_AllinOne_2014a_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc7_AllinOne_2014aInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc7_AllinOne_2014aInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllinOne_2014aMachineNumber_,
           7,
           21,
           21,
           0,
           5,
           3,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize ist own list of scripts */
        init_script_number_translation(_AllinOne_2014aMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_AllinOne_2014aMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _AllinOne_2014aMachineNumber_,
            chartInstance->chartNumber,
            3,
            3,
            3);
          _SFD_SET_DATA_PROPS(0,1,1,0,"CoffeeInput");
          _SFD_SET_DATA_PROPS(1,1,1,0,"MilkInput");
          _SFD_SET_DATA_PROPS(2,1,1,0,"SugarInput");
          _SFD_SET_DATA_PROPS(3,1,1,0,"WaterInput");
          _SFD_SET_DATA_PROPS(4,2,0,1,"OutputSwitch");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_EVENT_SCOPE(1,2);
          _SFD_EVENT_SCOPE(2,0);
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,1);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,1);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,0);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_STATE_INFO(13,0,1);
          _SFD_STATE_INFO(14,0,0);
          _SFD_STATE_INFO(15,0,0);
          _SFD_STATE_INFO(16,0,0);
          _SFD_STATE_INFO(17,0,1);
          _SFD_STATE_INFO(18,0,0);
          _SFD_STATE_INFO(19,0,0);
          _SFD_STATE_INFO(20,0,0);
          _SFD_CH_SUBSTATE_COUNT(5);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,17);
          _SFD_CH_SUBSTATE_INDEX(1,0);
          _SFD_CH_SUBSTATE_INDEX(2,4);
          _SFD_CH_SUBSTATE_INDEX(3,13);
          _SFD_CH_SUBSTATE_INDEX(4,8);
          _SFD_ST_SUBSTATE_COUNT(17,3);
          _SFD_ST_SUBSTATE_INDEX(17,0,18);
          _SFD_ST_SUBSTATE_INDEX(17,1,19);
          _SFD_ST_SUBSTATE_INDEX(17,2,20);
          _SFD_ST_SUBSTATE_COUNT(18,0);
          _SFD_ST_SUBSTATE_COUNT(19,0);
          _SFD_ST_SUBSTATE_COUNT(20,0);
          _SFD_ST_SUBSTATE_COUNT(0,3);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_INDEX(0,2,3);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,3);
          _SFD_ST_SUBSTATE_INDEX(4,0,5);
          _SFD_ST_SUBSTATE_INDEX(4,1,6);
          _SFD_ST_SUBSTATE_INDEX(4,2,7);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(13,3);
          _SFD_ST_SUBSTATE_INDEX(13,0,14);
          _SFD_ST_SUBSTATE_INDEX(13,1,15);
          _SFD_ST_SUBSTATE_INDEX(13,2,16);
          _SFD_ST_SUBSTATE_COUNT(14,0);
          _SFD_ST_SUBSTATE_COUNT(15,0);
          _SFD_ST_SUBSTATE_COUNT(16,0);
          _SFD_ST_SUBSTATE_COUNT(8,4);
          _SFD_ST_SUBSTATE_INDEX(8,0,9);
          _SFD_ST_SUBSTATE_INDEX(8,1,10);
          _SFD_ST_SUBSTATE_INDEX(8,2,11);
          _SFD_ST_SUBSTATE_INDEX(8,3,12);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,0);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,0);
        }

        _SFD_CV_INIT_CHART(5,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,3,1,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(4,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(7,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(8,4,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(13,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(14,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(15,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(16,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(17,3,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(18,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(19,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(20,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(14,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(15,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(17,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(20,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(18,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(16,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(19,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,0,16,0,16);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,0,16,0,16);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,19,1,19);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,19,1,19);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(8,0,0,0,16,0,16);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,17,1,17);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,0,16,0,16);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(15,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(15,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(17,0,0,1,0,0,0,0,0,4,1);
        _SFD_CV_INIT_EML_IF(17,0,0,1,117,1,48);

        {
          static int condStart[] = { 1, 32, 64, 94 };

          static int condEnd[] = { 24, 56, 86, 117 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3 };

          _SFD_CV_INIT_EML_MCDC(17,0,0,1,117,4,0,&(condStart[0]),&(condEnd[0]),7,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(20,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(20,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(18,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(18,0,0,0,14,0,14);
        _SFD_CV_INIT_EML(16,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(19,0,0,1,0,0,0,0,0,5,1);
        _SFD_CV_INIT_EML_IF(19,0,0,1,135,1,48);

        {
          static int condStart[] = { 1, 23, 53, 84, 113 };

          static int condEnd[] = { 15, 45, 76, 105, 135 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3, 3, -3, 4, -3 };

          _SFD_CV_INIT_EML_MCDC(19,0,0,1,135,5,0,&(condStart[0]),&(condEnd[0]),9,
                                &(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c7_sf_marshallOut,(MexInFcnForType)c7_sf_marshallIn);

        {
          real_T *c7_CoffeeInput;
          real_T *c7_MilkInput;
          real_T *c7_SugarInput;
          real_T *c7_WaterInput;
          real_T *c7_OutputSwitch;
          c7_OutputSwitch = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c7_WaterInput = (real_T *)ssGetInputPortSignal(chartInstance->S, 3);
          c7_SugarInput = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c7_MilkInput = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c7_CoffeeInput = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c7_CoffeeInput);
          _SFD_SET_DATA_VALUE_PTR(1U, c7_MilkInput);
          _SFD_SET_DATA_VALUE_PTR(2U, c7_SugarInput);
          _SFD_SET_DATA_VALUE_PTR(3U, c7_WaterInput);
          _SFD_SET_DATA_VALUE_PTR(4U, c7_OutputSwitch);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _AllinOne_2014aMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "hSnk82H0Dy2NCyahC3ZrED";
}

static void sf_opaque_initialize_c7_AllinOne_2014a(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc7_AllinOne_2014aInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c7_AllinOne_2014a((SFc7_AllinOne_2014aInstanceStruct*)
    chartInstanceVar);
  initialize_c7_AllinOne_2014a((SFc7_AllinOne_2014aInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c7_AllinOne_2014a(void *chartInstanceVar)
{
  enable_c7_AllinOne_2014a((SFc7_AllinOne_2014aInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c7_AllinOne_2014a(void *chartInstanceVar)
{
  disable_c7_AllinOne_2014a((SFc7_AllinOne_2014aInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c7_AllinOne_2014a(void *chartInstanceVar)
{
  sf_gateway_c7_AllinOne_2014a((SFc7_AllinOne_2014aInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c7_AllinOne_2014a(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c7_AllinOne_2014a
    ((SFc7_AllinOne_2014aInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c7_AllinOne_2014a();/* state var info */
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

extern void sf_internal_set_sim_state_c7_AllinOne_2014a(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[3];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxDuplicateArray(st);      /* high level simctx */
  prhs[2] = (mxArray*) sf_get_sim_state_info_c7_AllinOne_2014a();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 3, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c7_AllinOne_2014a((SFc7_AllinOne_2014aInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c7_AllinOne_2014a(SimStruct* S)
{
  return sf_internal_get_sim_state_c7_AllinOne_2014a(S);
}

static void sf_opaque_set_sim_state_c7_AllinOne_2014a(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c7_AllinOne_2014a(S, st);
}

static void sf_opaque_terminate_c7_AllinOne_2014a(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc7_AllinOne_2014aInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllinOne_2014a_optimization_info();
    }

    finalize_c7_AllinOne_2014a((SFc7_AllinOne_2014aInstanceStruct*)
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
  initSimStructsc7_AllinOne_2014a((SFc7_AllinOne_2014aInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c7_AllinOne_2014a(SimStruct *S)
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
    initialize_params_c7_AllinOne_2014a((SFc7_AllinOne_2014aInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c7_AllinOne_2014a(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_AllinOne_2014a_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,7);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,7,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,7,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,7);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,7,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,7,2);
    }

    ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,7);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetCallsOutputInInitFcn(S,1);
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(433937749U));
  ssSetChecksum1(S,(1009146210U));
  ssSetChecksum2(S,(173113098U));
  ssSetChecksum3(S,(2027400757U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c7_AllinOne_2014a(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c7_AllinOne_2014a(SimStruct *S)
{
  SFc7_AllinOne_2014aInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc7_AllinOne_2014aInstanceStruct *)utMalloc(sizeof
    (SFc7_AllinOne_2014aInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc7_AllinOne_2014aInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c7_AllinOne_2014a;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c7_AllinOne_2014a;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c7_AllinOne_2014a;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c7_AllinOne_2014a;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c7_AllinOne_2014a;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c7_AllinOne_2014a;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c7_AllinOne_2014a;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c7_AllinOne_2014a;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c7_AllinOne_2014a;
  chartInstance->chartInfo.mdlStart = mdlStart_c7_AllinOne_2014a;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c7_AllinOne_2014a;
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

void c7_AllinOne_2014a_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c7_AllinOne_2014a(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c7_AllinOne_2014a(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c7_AllinOne_2014a(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c7_AllinOne_2014a_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
