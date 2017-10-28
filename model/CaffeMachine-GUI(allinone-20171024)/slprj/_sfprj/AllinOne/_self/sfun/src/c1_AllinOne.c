/* Include files */

#include <stddef.h>
#include "blas.h"
#include "AllinOne_sfun.h"
#include "c1_AllinOne.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "AllinOne_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define c1_event_Tick                  (0)
#define c1_event_TakeOutEvent          (2)
#define CALL_EVENT                     (-1)
#define c1_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c1_IN_Adding                   ((uint8_T)1U)
#define c1_IN_Waiting                  ((uint8_T)2U)
#define c1_IN_Finished                 ((uint8_T)1U)
#define c1_IN_Output                   ((uint8_T)2U)
#define c1_IN_Prepare                  ((uint8_T)3U)
#define c1_IN_Running                  ((uint8_T)4U)
#define c1_IN_Start                    ((uint8_T)5U)
#define c1_IN_Stepping                 ((uint8_T)6U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c1_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c1_h_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_i_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c1_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance);
static void initialize_params_c1_AllinOne(SFc1_AllinOneInstanceStruct
  *chartInstance);
static void enable_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance);
static void disable_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance);
static void c1_update_debugger_state_c1_AllinOne(SFc1_AllinOneInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c1_AllinOne(SFc1_AllinOneInstanceStruct
  *chartInstance);
static void set_sim_state_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_st);
static void c1_set_sim_state_side_effects_c1_AllinOne
  (SFc1_AllinOneInstanceStruct *chartInstance);
static void finalize_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance);
static void sf_gateway_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance);
static void mdl_start_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance);
static void c1_chartstep_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance);
static void initSimStructsc1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance);
static void c1_CupTransmit(SFc1_AllinOneInstanceStruct *chartInstance);
static void c1_eps(SFc1_AllinOneInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber);
static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData);
static real_T c1_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_nargout, const char_T *c1_identifier);
static real_T c1_b_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static boolean_T c1_c_emlrt_marshallIn(SFc1_AllinOneInstanceStruct
  *chartInstance, const mxArray *c1_sf_internal_predicateOutput, const char_T
  *c1_identifier);
static boolean_T c1_d_emlrt_marshallIn(SFc1_AllinOneInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_info_helper(const mxArray **c1_info);
static const mxArray *c1_emlrt_marshallOut(const char * c1_u);
static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u);
static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int8_T c1_e_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint32_T c1_f_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_b_StepEventEventCounter, const char_T *c1_identifier);
static uint32_T c1_g_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static int32_T c1_h_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static uint8_T c1_i_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_b_tp_MixtrueMonitor, const char_T *c1_identifier);
static uint8_T c1_j_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static const mxArray *c1_InMixtrue_bus_io(void *chartInstanceVoid, void
  *c1_pData);
static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData);
static c1_Mixtrue c1_k_emlrt_marshallIn(SFc1_AllinOneInstanceStruct
  *chartInstance, const mxArray *c1_b_LocalMixtrue, const char_T *c1_identifier);
static c1_Mixtrue c1_l_emlrt_marshallIn(SFc1_AllinOneInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_m_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2]);
static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData);
static void c1_n_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_b_dataWrittenToVector, const char_T *c1_identifier,
  boolean_T c1_y[4]);
static void c1_o_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, boolean_T c1_y[4]);
static const mxArray *c1_p_emlrt_marshallIn(SFc1_AllinOneInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier);
static const mxArray *c1_q_emlrt_marshallIn(SFc1_AllinOneInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId);
static void c1_updateDataWrittenToVector(SFc1_AllinOneInstanceStruct
  *chartInstance, uint32_T c1_vectorIndex);
static void c1_errorIfDataNotWrittenToFcn(SFc1_AllinOneInstanceStruct
  *chartInstance, uint32_T c1_vectorIndex, uint32_T c1_dataNumber, uint32_T
  c1_ssIdOfSourceObject, int32_T c1_offsetInSourceObject, int32_T
  c1_lengthInSourceObject);
static void init_dsm_address_info(SFc1_AllinOneInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc1_AllinOneInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[2];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 0.0;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c1_doSetSimStateSideEffects = 0U;
  chartInstance->c1_setSimStateSideEffectsInfo = NULL;
  chartInstance->c1_is_active_CupMonitor = 0U;
  chartInstance->c1_is_CupMonitor = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_CupMonitor = 0U;
  chartInstance->c1_b_tp_Adding = 0U;
  chartInstance->c1_b_tp_Waiting = 0U;
  chartInstance->c1_is_active_CupTransmit = 0U;
  chartInstance->c1_is_CupTransmit = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_CupTransmit = 0U;
  chartInstance->c1_tp_Finished = 0U;
  chartInstance->c1_tp_Output = 0U;
  chartInstance->c1_tp_Prepare = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_tp_Running = 0U;
  chartInstance->c1_tp_Start = 0U;
  chartInstance->c1_tp_Stepping = 0U;
  chartInstance->c1_temporalCounter_i1 = 0U;
  chartInstance->c1_is_active_MixtrueMonitor = 0U;
  chartInstance->c1_is_MixtrueMonitor = c1_IN_NO_ACTIVE_CHILD;
  chartInstance->c1_tp_MixtrueMonitor = 0U;
  chartInstance->c1_tp_Adding = 0U;
  chartInstance->c1_tp_Waiting = 0U;
  chartInstance->c1_is_active_c1_AllinOne = 0U;
  chartInstance->c1_StepEventEventCounter = 0U;
  *chartInstance->c1_StepEvent = false;
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_active_c1_AllinOne = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_active_CupTransmit = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_CupTransmit = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_CupTransmit = c1_IN_Start;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_Start = 1U;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_c_debug_family_names,
    c1_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
    c1_sf_marshallIn);
  chartInstance->c1_CupLocation = -1.0;
  c1_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_CupLocation, 1U);
  c1_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U, 119U, 9, 11);
  sf_mex_printf("%s =\\n", "CupLocation");
  c1_hoistedGlobal = chartInstance->c1_CupLocation;
  c1_u = c1_hoistedGlobal;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
  _SFD_SYMBOL_SCOPE_POP();
  chartInstance->c1_is_active_MixtrueMonitor = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_MixtrueMonitor = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_MixtrueMonitor = c1_IN_Waiting;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_Waiting = 1U;
  chartInstance->c1_is_active_CupMonitor = 1U;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  chartInstance->c1_tp_CupMonitor = 1U;
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  chartInstance->c1_is_CupMonitor = c1_IN_Waiting;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  chartInstance->c1_b_tp_Waiting = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_AllinOneMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initialize_params_c1_AllinOne(SFc1_AllinOneInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c1_update_debugger_state_c1_AllinOne(SFc1_AllinOneInstanceStruct
  *chartInstance)
{
  uint32_T c1_prevAniVal;
  c1_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c1_is_active_c1_AllinOne == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_MixtrueMonitor == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_MixtrueMonitor == c1_IN_Waiting) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_MixtrueMonitor == c1_IN_Adding) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_CupMonitor == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_CupMonitor == c1_IN_Waiting) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_CupMonitor == c1_IN_Adding) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_active_CupTransmit == 1U) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_CupTransmit == c1_IN_Start) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_CupTransmit == c1_IN_Running) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_CupTransmit == c1_IN_Output) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_CupTransmit == c1_IN_Prepare) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_CupTransmit == c1_IN_Stepping) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
  }

  if (chartInstance->c1_is_CupTransmit == c1_IN_Finished) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
  }

  _SFD_SET_ANIMATION(c1_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c1_AllinOne(SFc1_AllinOneInstanceStruct
  *chartInstance)
{
  const mxArray *c1_st;
  const mxArray *c1_y = NULL;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_b_y = NULL;
  const mxArray *c1_c_y = NULL;
  int32_T c1_i0;
  real_T c1_b_u[2];
  const mxArray *c1_d_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_f_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_g_y = NULL;
  real_T c1_b_hoistedGlobal;
  real_T c1_f_u;
  const mxArray *c1_h_y = NULL;
  const mxArray *c1_i_y = NULL;
  int32_T c1_i1;
  real_T c1_g_u[2];
  const mxArray *c1_j_y = NULL;
  real_T c1_h_u;
  const mxArray *c1_k_y = NULL;
  real_T c1_i_u;
  const mxArray *c1_l_y = NULL;
  real_T c1_j_u;
  const mxArray *c1_m_y = NULL;
  boolean_T c1_c_hoistedGlobal;
  boolean_T c1_k_u;
  const mxArray *c1_n_y = NULL;
  uint32_T c1_d_hoistedGlobal;
  uint32_T c1_l_u;
  const mxArray *c1_o_y = NULL;
  uint8_T c1_e_hoistedGlobal;
  uint8_T c1_m_u;
  const mxArray *c1_p_y = NULL;
  uint8_T c1_f_hoistedGlobal;
  uint8_T c1_n_u;
  const mxArray *c1_q_y = NULL;
  uint8_T c1_g_hoistedGlobal;
  uint8_T c1_o_u;
  const mxArray *c1_r_y = NULL;
  uint8_T c1_h_hoistedGlobal;
  uint8_T c1_p_u;
  const mxArray *c1_s_y = NULL;
  uint8_T c1_i_hoistedGlobal;
  uint8_T c1_q_u;
  const mxArray *c1_t_y = NULL;
  uint8_T c1_j_hoistedGlobal;
  uint8_T c1_r_u;
  const mxArray *c1_u_y = NULL;
  uint8_T c1_k_hoistedGlobal;
  uint8_T c1_s_u;
  const mxArray *c1_v_y = NULL;
  uint32_T c1_l_hoistedGlobal;
  uint32_T c1_t_u;
  const mxArray *c1_w_y = NULL;
  int32_T c1_i2;
  boolean_T c1_u_u[4];
  const mxArray *c1_x_y = NULL;
  c1_st = NULL;
  c1_st = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createcellmatrix(15, 1), false);
  c1_hoistedGlobal = *chartInstance->c1_OutCup;
  c1_u = c1_hoistedGlobal;
  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 0, c1_b_y);
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c1_i0 = 0; c1_i0 < 2; c1_i0++) {
    c1_b_u[c1_i0] = ((real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[0])
      [c1_i0];
  }

  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_addfield(c1_c_y, c1_d_y, "Water", "Water", 0);
  c1_c_u = *(real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[16];
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_c_y, c1_e_y, "Coffee", "Coffee", 0);
  c1_d_u = *(real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[24];
  c1_f_y = NULL;
  sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_c_y, c1_f_y, "Milk", "Milk", 0);
  c1_e_u = *(real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[32];
  c1_g_y = NULL;
  sf_mex_assign(&c1_g_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_c_y, c1_g_y, "Sugar", "Sugar", 0);
  sf_mex_setcell(c1_y, 1, c1_c_y);
  c1_b_hoistedGlobal = chartInstance->c1_CupLocation;
  c1_f_u = c1_b_hoistedGlobal;
  c1_h_y = NULL;
  sf_mex_assign(&c1_h_y, sf_mex_create("y", &c1_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 2, c1_h_y);
  c1_i_y = NULL;
  sf_mex_assign(&c1_i_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c1_i1 = 0; c1_i1 < 2; c1_i1++) {
    c1_g_u[c1_i1] = chartInstance->c1_LocalMixtrue.Water[c1_i1];
  }

  c1_j_y = NULL;
  sf_mex_assign(&c1_j_y, sf_mex_create("y", c1_g_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_addfield(c1_i_y, c1_j_y, "Water", "Water", 0);
  c1_h_u = chartInstance->c1_LocalMixtrue.Coffee;
  c1_k_y = NULL;
  sf_mex_assign(&c1_k_y, sf_mex_create("y", &c1_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_i_y, c1_k_y, "Coffee", "Coffee", 0);
  c1_i_u = chartInstance->c1_LocalMixtrue.Milk;
  c1_l_y = NULL;
  sf_mex_assign(&c1_l_y, sf_mex_create("y", &c1_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_i_y, c1_l_y, "Milk", "Milk", 0);
  c1_j_u = chartInstance->c1_LocalMixtrue.Sugar;
  c1_m_y = NULL;
  sf_mex_assign(&c1_m_y, sf_mex_create("y", &c1_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_i_y, c1_m_y, "Sugar", "Sugar", 0);
  sf_mex_setcell(c1_y, 3, c1_i_y);
  c1_c_hoistedGlobal = *chartInstance->c1_StepEvent;
  c1_k_u = c1_c_hoistedGlobal;
  c1_n_y = NULL;
  sf_mex_assign(&c1_n_y, sf_mex_create("y", &c1_k_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 4, c1_n_y);
  c1_d_hoistedGlobal = chartInstance->c1_StepEventEventCounter;
  c1_l_u = c1_d_hoistedGlobal;
  c1_o_y = NULL;
  sf_mex_assign(&c1_o_y, sf_mex_create("y", &c1_l_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 5, c1_o_y);
  c1_e_hoistedGlobal = chartInstance->c1_is_active_c1_AllinOne;
  c1_m_u = c1_e_hoistedGlobal;
  c1_p_y = NULL;
  sf_mex_assign(&c1_p_y, sf_mex_create("y", &c1_m_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 6, c1_p_y);
  c1_f_hoistedGlobal = chartInstance->c1_is_active_CupTransmit;
  c1_n_u = c1_f_hoistedGlobal;
  c1_q_y = NULL;
  sf_mex_assign(&c1_q_y, sf_mex_create("y", &c1_n_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 7, c1_q_y);
  c1_g_hoistedGlobal = chartInstance->c1_is_active_MixtrueMonitor;
  c1_o_u = c1_g_hoistedGlobal;
  c1_r_y = NULL;
  sf_mex_assign(&c1_r_y, sf_mex_create("y", &c1_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 8, c1_r_y);
  c1_h_hoistedGlobal = chartInstance->c1_is_active_CupMonitor;
  c1_p_u = c1_h_hoistedGlobal;
  c1_s_y = NULL;
  sf_mex_assign(&c1_s_y, sf_mex_create("y", &c1_p_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 9, c1_s_y);
  c1_i_hoistedGlobal = chartInstance->c1_is_CupTransmit;
  c1_q_u = c1_i_hoistedGlobal;
  c1_t_y = NULL;
  sf_mex_assign(&c1_t_y, sf_mex_create("y", &c1_q_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 10, c1_t_y);
  c1_j_hoistedGlobal = chartInstance->c1_is_MixtrueMonitor;
  c1_r_u = c1_j_hoistedGlobal;
  c1_u_y = NULL;
  sf_mex_assign(&c1_u_y, sf_mex_create("y", &c1_r_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 11, c1_u_y);
  c1_k_hoistedGlobal = chartInstance->c1_is_CupMonitor;
  c1_s_u = c1_k_hoistedGlobal;
  c1_v_y = NULL;
  sf_mex_assign(&c1_v_y, sf_mex_create("y", &c1_s_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 12, c1_v_y);
  c1_l_hoistedGlobal = chartInstance->c1_temporalCounter_i1;
  c1_t_u = c1_l_hoistedGlobal;
  c1_w_y = NULL;
  sf_mex_assign(&c1_w_y, sf_mex_create("y", &c1_t_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c1_y, 13, c1_w_y);
  for (c1_i2 = 0; c1_i2 < 4; c1_i2++) {
    c1_u_u[c1_i2] = chartInstance->c1_dataWrittenToVector[c1_i2];
  }

  c1_x_y = NULL;
  sf_mex_assign(&c1_x_y, sf_mex_create("y", c1_u_u, 11, 0U, 1U, 0U, 1, 4), false);
  sf_mex_setcell(c1_y, 14, c1_x_y);
  sf_mex_assign(&c1_st, c1_y, false);
  return c1_st;
}

static void set_sim_state_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_st)
{
  const mxArray *c1_u;
  c1_Mixtrue c1_r0;
  int32_T c1_i3;
  boolean_T c1_bv0[4];
  int32_T c1_i4;
  chartInstance->c1_doneDoubleBufferReInit = true;
  c1_u = sf_mex_dup(c1_st);
  *chartInstance->c1_OutCup = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 0)), "OutCup");
  c1_r0 = c1_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 1)),
    "OutMixtrue");
  for (c1_i3 = 0; c1_i3 < 2; c1_i3++) {
    ((real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[0])[c1_i3] =
      c1_r0.Water[c1_i3];
  }

  *(real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[16] = c1_r0.Coffee;
  *(real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[24] = c1_r0.Milk;
  *(real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[32] = c1_r0.Sugar;
  chartInstance->c1_CupLocation = c1_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 2)), "CupLocation");
  chartInstance->c1_LocalMixtrue = c1_k_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 3)), "LocalMixtrue");
  *chartInstance->c1_StepEvent = c1_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c1_u, 4)), "StepEvent");
  chartInstance->c1_StepEventEventCounter = c1_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 5)), "StepEventEventCounter");
  chartInstance->c1_is_active_c1_AllinOne = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 6)), "is_active_c1_AllinOne");
  chartInstance->c1_is_active_CupTransmit = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 7)), "is_active_CupTransmit");
  chartInstance->c1_is_active_MixtrueMonitor = c1_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 8)),
     "is_active_MixtrueMonitor");
  chartInstance->c1_is_active_CupMonitor = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 9)), "is_active_CupMonitor");
  chartInstance->c1_is_CupTransmit = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 10)), "is_CupTransmit");
  chartInstance->c1_is_MixtrueMonitor = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 11)), "is_MixtrueMonitor");
  chartInstance->c1_is_CupMonitor = c1_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 12)), "is_CupMonitor");
  chartInstance->c1_temporalCounter_i1 = c1_f_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c1_u, 13)), "temporalCounter_i1");
  c1_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c1_u, 14)),
                        "dataWrittenToVector", c1_bv0);
  for (c1_i4 = 0; c1_i4 < 4; c1_i4++) {
    chartInstance->c1_dataWrittenToVector[c1_i4] = c1_bv0[c1_i4];
  }

  sf_mex_assign(&chartInstance->c1_setSimStateSideEffectsInfo,
                c1_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c1_u, 15)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c1_u);
  chartInstance->c1_doSetSimStateSideEffects = 1U;
  c1_update_debugger_state_c1_AllinOne(chartInstance);
  sf_mex_destroy(&c1_st);
}

static void c1_set_sim_state_side_effects_c1_AllinOne
  (SFc1_AllinOneInstanceStruct *chartInstance)
{
  if (chartInstance->c1_doSetSimStateSideEffects != 0) {
    if (chartInstance->c1_is_active_CupTransmit == 1U) {
      chartInstance->c1_tp_CupTransmit = 1U;
    } else {
      chartInstance->c1_tp_CupTransmit = 0U;
    }

    if (chartInstance->c1_is_CupTransmit == c1_IN_Finished) {
      chartInstance->c1_tp_Finished = 1U;
    } else {
      chartInstance->c1_tp_Finished = 0U;
    }

    if (chartInstance->c1_is_CupTransmit == c1_IN_Output) {
      chartInstance->c1_tp_Output = 1U;
    } else {
      chartInstance->c1_tp_Output = 0U;
    }

    if (chartInstance->c1_is_CupTransmit == c1_IN_Prepare) {
      chartInstance->c1_tp_Prepare = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 5) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_Prepare = 0U;
    }

    if (chartInstance->c1_is_CupTransmit == c1_IN_Running) {
      chartInstance->c1_tp_Running = 1U;
    } else {
      chartInstance->c1_tp_Running = 0U;
    }

    if (chartInstance->c1_is_CupTransmit == c1_IN_Start) {
      chartInstance->c1_tp_Start = 1U;
    } else {
      chartInstance->c1_tp_Start = 0U;
    }

    if (chartInstance->c1_is_CupTransmit == c1_IN_Stepping) {
      chartInstance->c1_tp_Stepping = 1U;
      if (sf_mex_sub(chartInstance->c1_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 8) == 0.0) {
        chartInstance->c1_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c1_tp_Stepping = 0U;
    }

    if (chartInstance->c1_is_active_MixtrueMonitor == 1U) {
      chartInstance->c1_tp_MixtrueMonitor = 1U;
    } else {
      chartInstance->c1_tp_MixtrueMonitor = 0U;
    }

    if (chartInstance->c1_is_MixtrueMonitor == c1_IN_Adding) {
      chartInstance->c1_tp_Adding = 1U;
    } else {
      chartInstance->c1_tp_Adding = 0U;
    }

    if (chartInstance->c1_is_MixtrueMonitor == c1_IN_Waiting) {
      chartInstance->c1_tp_Waiting = 1U;
    } else {
      chartInstance->c1_tp_Waiting = 0U;
    }

    if (chartInstance->c1_is_active_CupMonitor == 1U) {
      chartInstance->c1_tp_CupMonitor = 1U;
    } else {
      chartInstance->c1_tp_CupMonitor = 0U;
    }

    if (chartInstance->c1_is_CupMonitor == c1_IN_Adding) {
      chartInstance->c1_b_tp_Adding = 1U;
    } else {
      chartInstance->c1_b_tp_Adding = 0U;
    }

    if (chartInstance->c1_is_CupMonitor == c1_IN_Waiting) {
      chartInstance->c1_b_tp_Waiting = 1U;
    } else {
      chartInstance->c1_b_tp_Waiting = 0U;
    }

    chartInstance->c1_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c1_setSimStateSideEffectsInfo);
}

static void sf_gateway_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance)
{
  int32_T c1_inputEventFiredFlag;
  c1_set_sim_state_side_effects_c1_AllinOne(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_Step, 0U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c1_CupLocation, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_InCup, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c1_OutCup, 5U);
  c1_inputEventFiredFlag = 0;
  if (*chartInstance->c1_Tick == 1) {
    c1_inputEventFiredFlag = 1;
    if (chartInstance->c1_temporalCounter_i1 < MAX_uint32_T) {
      chartInstance->c1_temporalCounter_i1++;
    }

    chartInstance->c1_sfEvent = c1_event_Tick;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_Tick,
                 chartInstance->c1_sfEvent);
    c1_chartstep_c1_AllinOne(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_Tick,
                 chartInstance->c1_sfEvent);
  }

  if (*chartInstance->c1_TakeOutEvent == 1) {
    c1_inputEventFiredFlag = 1;
    chartInstance->c1_sfEvent = c1_event_TakeOutEvent;
    _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c1_event_TakeOutEvent,
                 chartInstance->c1_sfEvent);
    c1_chartstep_c1_AllinOne(chartInstance);
    _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c1_event_TakeOutEvent,
                 chartInstance->c1_sfEvent);
  }

  if (c1_inputEventFiredFlag != 0) {
    if (chartInstance->c1_StepEventEventCounter > 0U) {
      *chartInstance->c1_StepEvent = !*chartInstance->c1_StepEvent;
      chartInstance->c1_StepEventEventCounter--;
    }
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_AllinOneMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_chartstep_c1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  real_T c1_hoistedGlobal;
  real_T c1_x;
  real_T c1_b_x;
  real_T c1_d0;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  int32_T c1_i5;
  const mxArray *c1_y = NULL;
  int32_T c1_i6;
  real_T c1_u[2];
  const mxArray *c1_b_y = NULL;
  real_T c1_b_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_e_y = NULL;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T c1_b_hoistedGlobal;
  real_T c1_e_u;
  const mxArray *c1_f_y = NULL;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  c1_CupTransmit(chartInstance);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_MixtrueMonitor) {
   case c1_IN_Adding:
    CV_STATE_EVAL(10, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_i_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_eps(chartInstance);
    c1_out = CV_EML_IF(9, 0, 0, CV_RELATIONAL_EVAL(5U, 9U, 0, *(real_T *)
      &((char_T *)chartInstance->c1_InMixtrue)[16], 2.2204460492503131E-16, -1,
      4U, *(real_T *)&((char_T *)chartInstance->c1_InMixtrue)[16] >
      2.2204460492503131E-16));
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Adding = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_MixtrueMonitor = c1_IN_Waiting;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Waiting = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 11U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Waiting:
    CV_STATE_EVAL(10, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_h_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_eps(chartInstance);
    guard2 = false;
    if (CV_EML_COND(8, 0, 0, CV_RELATIONAL_EVAL(5U, 8U, 0, *(real_T *)&((char_T *)
           chartInstance->c1_InMixtrue)[16], 2.2204460492503131E-16, -1, 4U,
          *(real_T *)&((char_T *)chartInstance->c1_InMixtrue)[16] >
          2.2204460492503131E-16))) {
      c1_hoistedGlobal = chartInstance->c1_CupLocation;
      c1_x = c1_hoistedGlobal - 50.0;
      c1_b_x = c1_x;
      c1_d0 = muDoubleScalarAbs(c1_b_x);
      if (CV_EML_COND(8, 0, 1, CV_RELATIONAL_EVAL(5U, 8U, 1, c1_d0, 5.0, -1, 2U,
            c1_d0 < 5.0))) {
        CV_EML_MCDC(8, 0, 0, true);
        CV_EML_IF(8, 0, 0, true);
        c1_b_out = true;
      } else {
        guard2 = true;
      }
    } else {
      c1_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U, 135U, 35, 11);
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(8, 0, 0, false);
      CV_EML_IF(8, 0, 0, false);
      c1_b_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Waiting = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 12U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_MixtrueMonitor = c1_IN_Adding;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Adding = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      for (c1_i5 = 0; c1_i5 < 2; c1_i5++) {
        chartInstance->c1_LocalMixtrue.Water[c1_i5] = ((real_T *)&((char_T *)
          chartInstance->c1_InMixtrue)[0])[c1_i5];
      }

      chartInstance->c1_LocalMixtrue.Coffee = *(real_T *)&((char_T *)
        chartInstance->c1_InMixtrue)[16];
      chartInstance->c1_LocalMixtrue.Milk = *(real_T *)&((char_T *)
        chartInstance->c1_InMixtrue)[24];
      chartInstance->c1_LocalMixtrue.Sugar = *(real_T *)&((char_T *)
        chartInstance->c1_InMixtrue)[32];
      c1_updateDataWrittenToVector(chartInstance, 3U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 3U, 6U, 134U, 11, 12);
      sf_mex_printf("%s =\\n", "LocalMixtrue");
      c1_y = NULL;
      sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), false);
      for (c1_i6 = 0; c1_i6 < 2; c1_i6++) {
        c1_u[c1_i6] = chartInstance->c1_LocalMixtrue.Water[c1_i6];
      }

      c1_b_y = NULL;
      sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_u, 0, 0U, 1U, 0U, 1, 2),
                    false);
      sf_mex_addfield(c1_y, c1_b_y, "Water", "Water", 0);
      c1_b_u = chartInstance->c1_LocalMixtrue.Coffee;
      c1_c_y = NULL;
      sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_addfield(c1_y, c1_c_y, "Coffee", "Coffee", 0);
      c1_c_u = chartInstance->c1_LocalMixtrue.Milk;
      c1_d_y = NULL;
      sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_addfield(c1_y, c1_d_y, "Milk", "Milk", 0);
      c1_d_u = chartInstance->c1_LocalMixtrue.Sugar;
      c1_e_y = NULL;
      sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_addfield(c1_y, c1_e_y, "Sugar", "Sugar", 0);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 12U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(10, 0, 0);
    chartInstance->c1_is_MixtrueMonitor = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 10U, chartInstance->c1_sfEvent);
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_CupMonitor) {
   case c1_IN_Adding:
    CV_STATE_EVAL(0, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_k_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_eps(chartInstance);
    c1_c_out = CV_EML_IF(11, 0, 0, CV_RELATIONAL_EVAL(5U, 11U, 0,
      *chartInstance->c1_InCup, 2.2204460492503131E-16, -1, 4U,
      *chartInstance->c1_InCup > 2.2204460492503131E-16));
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_Adding = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_CupMonitor = c1_IN_Waiting;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_Waiting = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Waiting:
    CV_STATE_EVAL(0, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_j_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_eps(chartInstance);
    guard1 = false;
    if (CV_EML_COND(10, 0, 0, CV_RELATIONAL_EVAL(5U, 10U, 0,
          *chartInstance->c1_InCup, 2.2204460492503131E-16, -1, 4U,
          *chartInstance->c1_InCup > 2.2204460492503131E-16))) {
      if (CV_EML_COND(10, 0, 1, CV_RELATIONAL_EVAL(5U, 10U, 1,
            chartInstance->c1_CupLocation, 0.0, -1, 2U,
            chartInstance->c1_CupLocation < 0.0))) {
        CV_EML_MCDC(10, 0, 0, true);
        CV_EML_IF(10, 0, 0, true);
        c1_d_out = true;
      } else {
        guard1 = true;
      }
    } else {
      c1_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U, 138U, 20, 11);
      guard1 = true;
    }

    if (guard1 == true) {
      CV_EML_MCDC(10, 0, 0, false);
      CV_EML_IF(10, 0, 0, false);
      c1_d_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c1_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_Waiting = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_CupMonitor = c1_IN_Adding;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
      chartInstance->c1_b_tp_Adding = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_b_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      chartInstance->c1_CupLocation = 0.0;
      c1_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_CupLocation, 1U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U, 139U, 11, 11);
      sf_mex_printf("%s =\\n", "CupLocation");
      c1_b_hoistedGlobal = chartInstance->c1_CupLocation;
      c1_e_u = c1_b_hoistedGlobal;
      c1_f_y = NULL;
      sf_mex_assign(&c1_f_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_f_y);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(0, 0, 0);
    chartInstance->c1_is_CupMonitor = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c1_sfEvent);
}

static void initSimStructsc1_AllinOne(SFc1_AllinOneInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c1_CupTransmit(SFc1_AllinOneInstanceStruct *chartInstance)
{
  uint32_T c1_debug_family_var_map[3];
  real_T c1_nargin = 0.0;
  real_T c1_nargout = 1.0;
  boolean_T c1_out;
  real_T c1_b_nargin = 0.0;
  real_T c1_b_nargout = 1.0;
  boolean_T c1_b_out;
  uint32_T c1_b_debug_family_var_map[2];
  real_T c1_c_nargin = 0.0;
  real_T c1_c_nargout = 0.0;
  int32_T c1_i7;
  real_T c1_d_nargin = 0.0;
  real_T c1_d_nargout = 0.0;
  real_T c1_hoistedGlobal;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  real_T c1_e_nargin = 0.0;
  real_T c1_e_nargout = 1.0;
  boolean_T c1_c_out;
  real_T c1_f_nargin = 0.0;
  real_T c1_f_nargout = 0.0;
  real_T c1_b_hoistedGlobal;
  real_T c1_b_u;
  const mxArray *c1_b_y = NULL;
  real_T c1_g_nargin = 0.0;
  real_T c1_g_nargout = 1.0;
  boolean_T c1_d_out;
  real_T c1_h_nargin = 0.0;
  real_T c1_h_nargout = 0.0;
  int32_T c1_i8;
  real_T c1_i_nargin = 0.0;
  real_T c1_i_nargout = 1.0;
  boolean_T c1_e_out;
  real_T c1_j_nargin = 0.0;
  real_T c1_j_nargout = 1.0;
  boolean_T c1_f_out;
  real_T c1_k_nargin = 0.0;
  real_T c1_k_nargout = 1.0;
  boolean_T c1_g_out;
  real_T c1_l_nargin = 0.0;
  real_T c1_l_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
  switch (chartInstance->c1_is_CupTransmit) {
   case c1_IN_Finished:
    CV_STATE_EVAL(3, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_o_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_eps(chartInstance);
    c1_out = CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0,
      *chartInstance->c1_Step, 2.2204460492503131E-16, -1, 2U,
      *chartInstance->c1_Step < 2.2204460492503131E-16));
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Finished = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_CupTransmit = c1_IN_Running;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Running = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Output:
    CV_STATE_EVAL(3, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_l_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_b_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_b_out = CV_EML_IF(2, 0, 0, chartInstance->c1_sfEvent ==
                         c1_event_TakeOutEvent);
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Output = 0U;
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_e_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      for (c1_i7 = 0; c1_i7 < 2; c1_i7++) {
        ((real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[0])[c1_i7] = 0.0;
      }

      c1_updateDataWrittenToVector(chartInstance, 1U);
      *(real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[16] = 0.0;
      c1_updateDataWrittenToVector(chartInstance, 1U);
      *(real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[24] = 0.0;
      c1_updateDataWrittenToVector(chartInstance, 1U);
      *(real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[32] = 0.0;
      c1_updateDataWrittenToVector(chartInstance, 1U);
      *chartInstance->c1_OutCup = 0.0;
      c1_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_DATA_RANGE_CHECK(*chartInstance->c1_OutCup, 5U);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_CupTransmit = c1_IN_Start;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Start = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_c_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      chartInstance->c1_CupLocation = -1.0;
      c1_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_CupLocation, 1U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U, 119U, 9, 11);
      sf_mex_printf("%s =\\n", "CupLocation");
      c1_hoistedGlobal = chartInstance->c1_CupLocation;
      c1_u = c1_hoistedGlobal;
      c1_y = NULL;
      sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_y);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Prepare:
    CV_STATE_EVAL(3, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_q_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_c_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_c_out = CV_EML_IF(6, 0, 0, chartInstance->c1_temporalCounter_i1 >=
                         _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
      *chartInstance->c1_Step, 32U, 6U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Prepare = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_CupTransmit = c1_IN_Stepping;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      chartInstance->c1_temporalCounter_i1 = 0U;
      chartInstance->c1_tp_Stepping = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_f_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U, 128U, 27, 11);
      chartInstance->c1_CupLocation += *chartInstance->c1_Step;
      c1_updateDataWrittenToVector(chartInstance, 0U);
      _SFD_DATA_RANGE_CHECK(chartInstance->c1_CupLocation, 1U);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U, 128U, 13, 11);
      sf_mex_printf("%s =\\n", "CupLocation");
      c1_b_hoistedGlobal = chartInstance->c1_CupLocation;
      c1_b_u = c1_b_hoistedGlobal;
      c1_b_y = NULL;
      sf_mex_assign(&c1_b_y, sf_mex_create("y", &c1_b_u, 0, 0U, 0U, 0U, 0),
                    false);
      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "disp", 0U, 1U, 14, c1_b_y);
      chartInstance->c1_StepEventEventCounter++;
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Running:
    CV_STATE_EVAL(3, 0, 4);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_n_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_d_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U, 124U, 1, 11);
    c1_d_out = CV_EML_IF(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0,
      chartInstance->c1_CupLocation, 100.0, -1, 5U,
      chartInstance->c1_CupLocation >= 100.0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_d_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Running = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_CupTransmit = c1_IN_Output;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Output = 1U;
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_d_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_h_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      c1_errorIfDataNotWrittenToFcn(chartInstance, 3U, 6U, 120U, 24, 12);
      for (c1_i8 = 0; c1_i8 < 2; c1_i8++) {
        ((real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[0])[c1_i8] =
          chartInstance->c1_LocalMixtrue.Water[c1_i8];
      }

      *(real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[16] =
        chartInstance->c1_LocalMixtrue.Coffee;
      *(real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[24] =
        chartInstance->c1_LocalMixtrue.Milk;
      *(real_T *)&((char_T *)chartInstance->c1_OutMixtrue)[32] =
        chartInstance->c1_LocalMixtrue.Sugar;
      c1_updateDataWrittenToVector(chartInstance, 1U);
      *chartInstance->c1_OutCup = 1.0;
      c1_updateDataWrittenToVector(chartInstance, 2U);
      _SFD_DATA_RANGE_CHECK(*chartInstance->c1_OutCup, 5U);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                   chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_p_debug_family_names,
        c1_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_i_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_e_out, 2U, c1_b_sf_marshallOut,
        c1_b_sf_marshallIn);
      c1_eps(chartInstance);
      guard1 = false;
      if (CV_EML_COND(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0,
            *chartInstance->c1_Step, 2.2204460492503131E-16, -1, 4U,
            *chartInstance->c1_Step > 2.2204460492503131E-16))) {
        if (CV_EML_COND(4, 0, 1, CV_RELATIONAL_EVAL(5U, 4U, 1,
              chartInstance->c1_CupLocation, 0.0, -1, 5U,
              chartInstance->c1_CupLocation >= 0.0))) {
          CV_EML_MCDC(4, 0, 0, true);
          CV_EML_IF(4, 0, 0, true);
          c1_e_out = true;
        } else {
          guard1 = true;
        }
      } else {
        c1_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U, 126U, 15, 11);
        guard1 = true;
      }

      if (guard1 == true) {
        CV_EML_MCDC(4, 0, 0, false);
        CV_EML_IF(4, 0, 0, false);
        c1_e_out = false;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c1_e_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
        chartInstance->c1_tp_Running = 0U;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
        chartInstance->c1_is_CupTransmit = c1_IN_Prepare;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, chartInstance->c1_sfEvent);
        chartInstance->c1_temporalCounter_i1 = 0U;
        chartInstance->c1_tp_Prepare = 1U;
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 7U,
                     chartInstance->c1_sfEvent);
      }
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Start:
    CV_STATE_EVAL(3, 0, 5);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_m_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_j_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_f_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_errorIfDataNotWrittenToFcn(chartInstance, 0U, 1U, 121U, 1, 11);
    c1_f_out = CV_EML_IF(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0,
      chartInstance->c1_CupLocation, 0.0, -1, 5U, chartInstance->c1_CupLocation >=
      0.0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_f_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Start = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 8U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_CupTransmit = c1_IN_Running;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 7U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Running = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 8U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c1_sfEvent);
    break;

   case c1_IN_Stepping:
    CV_STATE_EVAL(3, 0, 6);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                 chartInstance->c1_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c1_r_debug_family_names,
      c1_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargin, 0U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_k_nargout, 1U, c1_sf_marshallOut,
      c1_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_g_out, 2U, c1_b_sf_marshallOut,
      c1_b_sf_marshallIn);
    c1_g_out = CV_EML_IF(13, 0, 0, (chartInstance->c1_sfEvent == c1_event_Tick) &&
                         (chartInstance->c1_temporalCounter_i1 >= 10U));
    _SFD_SYMBOL_SCOPE_POP();
    if (c1_g_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Stepping = 0U;
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c1_g_debug_family_names,
        c1_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargin, 0U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c1_l_nargout, 1U, c1_sf_marshallOut,
        c1_sf_marshallIn);
      chartInstance->c1_StepEventEventCounter++;
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 9U, chartInstance->c1_sfEvent);
      chartInstance->c1_is_CupTransmit = c1_IN_Finished;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
      chartInstance->c1_tp_Finished = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 9U,
                   chartInstance->c1_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c1_sfEvent);
    break;

   default:
    CV_STATE_EVAL(3, 0, 0);
    chartInstance->c1_is_CupTransmit = c1_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, chartInstance->c1_sfEvent);
    break;
  }

  _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c1_sfEvent);
}

static void c1_eps(SFc1_AllinOneInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c1_machineNumber, uint32_T
  c1_chartNumber, uint32_T c1_instanceNumber)
{
  (void)c1_machineNumber;
  (void)c1_chartNumber;
  (void)c1_instanceNumber;
}

static const mxArray *c1_sf_marshallOut(void *chartInstanceVoid, void *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  real_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllinOneInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(real_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static real_T c1_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_nargout, const char_T *c1_identifier)
{
  real_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  return c1_y;
}

static real_T c1_b_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  real_T c1_y;
  real_T c1_d1;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_d1, 1, 0, 0U, 0, 0U, 0);
  c1_y = c1_d1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_nargout;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  real_T c1_y;
  SFc1_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllinOneInstanceStruct *)chartInstanceVoid;
  c1_nargout = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_nargout), &c1_thisId);
  sf_mex_destroy(&c1_nargout);
  *(real_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_b_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  boolean_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllinOneInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(boolean_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static boolean_T c1_c_emlrt_marshallIn(SFc1_AllinOneInstanceStruct
  *chartInstance, const mxArray *c1_sf_internal_predicateOutput, const char_T
  *c1_identifier)
{
  boolean_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_sf_internal_predicateOutput), &c1_thisId);
  sf_mex_destroy(&c1_sf_internal_predicateOutput);
  return c1_y;
}

static boolean_T c1_d_emlrt_marshallIn(SFc1_AllinOneInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  boolean_T c1_y;
  boolean_T c1_b0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_b0, 1, 11, 0U, 0, 0U, 0);
  c1_y = c1_b0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_sf_internal_predicateOutput;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  boolean_T c1_y;
  SFc1_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllinOneInstanceStruct *)chartInstanceVoid;
  c1_sf_internal_predicateOutput = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_sf_internal_predicateOutput), &c1_thisId);
  sf_mex_destroy(&c1_sf_internal_predicateOutput);
  *(boolean_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

const mxArray *sf_c1_AllinOne_get_eml_resolved_functions_info(void)
{
  const mxArray *c1_nameCaptureInfo = NULL;
  c1_nameCaptureInfo = NULL;
  sf_mex_assign(&c1_nameCaptureInfo, sf_mex_createstruct("structure", 2, 6, 1),
                false);
  c1_info_helper(&c1_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c1_nameCaptureInfo);
  return c1_nameCaptureInfo;
}

static void c1_info_helper(const mxArray **c1_info)
{
  const mxArray *c1_rhs0 = NULL;
  const mxArray *c1_lhs0 = NULL;
  const mxArray *c1_rhs1 = NULL;
  const mxArray *c1_lhs1 = NULL;
  const mxArray *c1_rhs2 = NULL;
  const mxArray *c1_lhs2 = NULL;
  const mxArray *c1_rhs3 = NULL;
  const mxArray *c1_lhs3 = NULL;
  const mxArray *c1_rhs4 = NULL;
  const mxArray *c1_lhs4 = NULL;
  const mxArray *c1_rhs5 = NULL;
  const mxArray *c1_lhs5 = NULL;
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eps"), "name", "name", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1326702796U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c1_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_eps"), "name", "name", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1326702796U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c1_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1326702796U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c1_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(""), "context", "context", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("abs"), "name", "name", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1363688652U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c1_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1395906656U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c1_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c1_info, c1_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(1286797112U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c1_info, c1_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c1_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c1_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c1_info, sf_mex_duplicatearraysafe(&c1_lhs5), "lhs", "lhs", 5);
  sf_mex_destroy(&c1_rhs0);
  sf_mex_destroy(&c1_lhs0);
  sf_mex_destroy(&c1_rhs1);
  sf_mex_destroy(&c1_lhs1);
  sf_mex_destroy(&c1_rhs2);
  sf_mex_destroy(&c1_lhs2);
  sf_mex_destroy(&c1_rhs3);
  sf_mex_destroy(&c1_lhs3);
  sf_mex_destroy(&c1_rhs4);
  sf_mex_destroy(&c1_lhs4);
  sf_mex_destroy(&c1_rhs5);
  sf_mex_destroy(&c1_lhs5);
}

static const mxArray *c1_emlrt_marshallOut(const char * c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", c1_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c1_u)), false);
  return c1_y;
}

static const mxArray *c1_b_emlrt_marshallOut(const uint32_T c1_u)
{
  const mxArray *c1_y = NULL;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  return c1_y;
}

static const mxArray *c1_c_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllinOneInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int8_T c1_e_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int8_T c1_y;
  int8_T c1_i9;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i9, 1, 2, 0U, 0, 0U, 0);
  c1_y = c1_i9;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_Tick;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int8_T c1_y;
  SFc1_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllinOneInstanceStruct *)chartInstanceVoid;
  c1_b_Tick = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_Tick), &c1_thisId);
  sf_mex_destroy(&c1_b_Tick);
  *(int8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_d_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllinOneInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint32_T c1_f_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_b_StepEventEventCounter, const char_T *c1_identifier)
{
  uint32_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_StepEventEventCounter), &c1_thisId);
  sf_mex_destroy(&c1_b_StepEventEventCounter);
  return c1_y;
}

static uint32_T c1_g_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint32_T c1_y;
  uint32_T c1_u0;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u0, 1, 7, 0U, 0, 0U, 0);
  c1_y = c1_u0;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_StepEventEventCounter;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint32_T c1_y;
  SFc1_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllinOneInstanceStruct *)chartInstanceVoid;
  c1_b_StepEventEventCounter = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_StepEventEventCounter), &c1_thisId);
  sf_mex_destroy(&c1_b_StepEventEventCounter);
  *(uint32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_e_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  int32_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllinOneInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(int32_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static int32_T c1_h_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  int32_T c1_y;
  int32_T c1_i10;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_i10, 1, 6, 0U, 0, 0U, 0);
  c1_y = c1_i10;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_sfEvent;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  int32_T c1_y;
  SFc1_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllinOneInstanceStruct *)chartInstanceVoid;
  c1_b_sfEvent = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_sfEvent),
    &c1_thisId);
  sf_mex_destroy(&c1_b_sfEvent);
  *(int32_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_f_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  uint8_T c1_u;
  const mxArray *c1_y = NULL;
  SFc1_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllinOneInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(uint8_T *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_create("y", &c1_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static uint8_T c1_i_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_b_tp_MixtrueMonitor, const char_T *c1_identifier)
{
  uint8_T c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_MixtrueMonitor),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_MixtrueMonitor);
  return c1_y;
}

static uint8_T c1_j_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  uint8_T c1_y;
  uint8_T c1_u1;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), &c1_u1, 1, 3, 0U, 0, 0U, 0);
  c1_y = c1_u1;
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_tp_MixtrueMonitor;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  uint8_T c1_y;
  SFc1_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllinOneInstanceStruct *)chartInstanceVoid;
  c1_b_tp_MixtrueMonitor = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_tp_MixtrueMonitor),
    &c1_thisId);
  sf_mex_destroy(&c1_b_tp_MixtrueMonitor);
  *(uint8_T *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static const mxArray *c1_InMixtrue_bus_io(void *chartInstanceVoid, void
  *c1_pData)
{
  const mxArray *c1_mxVal = NULL;
  int32_T c1_i11;
  c1_Mixtrue c1_tmp;
  SFc1_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllinOneInstanceStruct *)chartInstanceVoid;
  c1_mxVal = NULL;
  for (c1_i11 = 0; c1_i11 < 2; c1_i11++) {
    c1_tmp.Water[c1_i11] = ((real_T *)&((char_T *)(c1_Mixtrue *)c1_pData)[0])
      [c1_i11];
  }

  c1_tmp.Coffee = *(real_T *)&((char_T *)(c1_Mixtrue *)c1_pData)[16];
  c1_tmp.Milk = *(real_T *)&((char_T *)(c1_Mixtrue *)c1_pData)[24];
  c1_tmp.Sugar = *(real_T *)&((char_T *)(c1_Mixtrue *)c1_pData)[32];
  sf_mex_assign(&c1_mxVal, c1_g_sf_marshallOut(chartInstance, &c1_tmp), false);
  return c1_mxVal;
}

static const mxArray *c1_g_sf_marshallOut(void *chartInstanceVoid, void
  *c1_inData)
{
  const mxArray *c1_mxArrayOutData = NULL;
  c1_Mixtrue c1_u;
  const mxArray *c1_y = NULL;
  int32_T c1_i12;
  real_T c1_b_u[2];
  const mxArray *c1_b_y = NULL;
  real_T c1_c_u;
  const mxArray *c1_c_y = NULL;
  real_T c1_d_u;
  const mxArray *c1_d_y = NULL;
  real_T c1_e_u;
  const mxArray *c1_e_y = NULL;
  SFc1_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllinOneInstanceStruct *)chartInstanceVoid;
  c1_mxArrayOutData = NULL;
  c1_u = *(c1_Mixtrue *)c1_inData;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c1_i12 = 0; c1_i12 < 2; c1_i12++) {
    c1_b_u[c1_i12] = c1_u.Water[c1_i12];
  }

  c1_b_y = NULL;
  sf_mex_assign(&c1_b_y, sf_mex_create("y", c1_b_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_addfield(c1_y, c1_b_y, "Water", "Water", 0);
  c1_c_u = c1_u.Coffee;
  c1_c_y = NULL;
  sf_mex_assign(&c1_c_y, sf_mex_create("y", &c1_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_c_y, "Coffee", "Coffee", 0);
  c1_d_u = c1_u.Milk;
  c1_d_y = NULL;
  sf_mex_assign(&c1_d_y, sf_mex_create("y", &c1_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_d_y, "Milk", "Milk", 0);
  c1_e_u = c1_u.Sugar;
  c1_e_y = NULL;
  sf_mex_assign(&c1_e_y, sf_mex_create("y", &c1_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c1_y, c1_e_y, "Sugar", "Sugar", 0);
  sf_mex_assign(&c1_mxArrayOutData, c1_y, false);
  return c1_mxArrayOutData;
}

static c1_Mixtrue c1_k_emlrt_marshallIn(SFc1_AllinOneInstanceStruct
  *chartInstance, const mxArray *c1_b_LocalMixtrue, const char_T *c1_identifier)
{
  c1_Mixtrue c1_y;
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_LocalMixtrue),
    &c1_thisId);
  sf_mex_destroy(&c1_b_LocalMixtrue);
  return c1_y;
}

static c1_Mixtrue c1_l_emlrt_marshallIn(SFc1_AllinOneInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  c1_Mixtrue c1_y;
  emlrtMsgIdentifier c1_thisId;
  static const char * c1_fieldNames[4] = { "Water", "Coffee", "Milk", "Sugar" };

  c1_thisId.fParent = c1_parentId;
  sf_mex_check_struct(c1_parentId, c1_u, 4, c1_fieldNames, 0U, NULL);
  c1_thisId.fIdentifier = "Water";
  c1_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c1_u, "Water",
    "Water", 0)), &c1_thisId, c1_y.Water);
  c1_thisId.fIdentifier = "Coffee";
  c1_y.Coffee = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Coffee", "Coffee", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Milk";
  c1_y.Milk = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Milk", "Milk", 0)), &c1_thisId);
  c1_thisId.fIdentifier = "Sugar";
  c1_y.Sugar = c1_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c1_u, "Sugar", "Sugar", 0)), &c1_thisId);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_m_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, real_T c1_y[2])
{
  real_T c1_dv0[2];
  int32_T c1_i13;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_dv0, 1, 0, 0U, 1, 0U, 1, 2);
  for (c1_i13 = 0; c1_i13 < 2; c1_i13++) {
    c1_y[c1_i13] = c1_dv0[c1_i13];
  }

  sf_mex_destroy(&c1_u);
}

static void c1_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c1_mxArrayInData, const char_T *c1_varName, void *c1_outData)
{
  const mxArray *c1_b_LocalMixtrue;
  const char_T *c1_identifier;
  emlrtMsgIdentifier c1_thisId;
  c1_Mixtrue c1_y;
  SFc1_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc1_AllinOneInstanceStruct *)chartInstanceVoid;
  c1_b_LocalMixtrue = sf_mex_dup(c1_mxArrayInData);
  c1_identifier = c1_varName;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_y = c1_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_LocalMixtrue),
    &c1_thisId);
  sf_mex_destroy(&c1_b_LocalMixtrue);
  *(c1_Mixtrue *)c1_outData = c1_y;
  sf_mex_destroy(&c1_mxArrayInData);
}

static void c1_n_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_b_dataWrittenToVector, const char_T *c1_identifier,
  boolean_T c1_y[4])
{
  emlrtMsgIdentifier c1_thisId;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  c1_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c1_b_dataWrittenToVector),
                        &c1_thisId, c1_y);
  sf_mex_destroy(&c1_b_dataWrittenToVector);
}

static void c1_o_emlrt_marshallIn(SFc1_AllinOneInstanceStruct *chartInstance,
  const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId, boolean_T c1_y[4])
{
  boolean_T c1_bv1[4];
  int32_T c1_i14;
  (void)chartInstance;
  sf_mex_import(c1_parentId, sf_mex_dup(c1_u), c1_bv1, 1, 11, 0U, 1, 0U, 1, 4);
  for (c1_i14 = 0; c1_i14 < 4; c1_i14++) {
    c1_y[c1_i14] = c1_bv1[c1_i14];
  }

  sf_mex_destroy(&c1_u);
}

static const mxArray *c1_p_emlrt_marshallIn(SFc1_AllinOneInstanceStruct
  *chartInstance, const mxArray *c1_b_setSimStateSideEffectsInfo, const char_T
  *c1_identifier)
{
  const mxArray *c1_y = NULL;
  emlrtMsgIdentifier c1_thisId;
  c1_y = NULL;
  c1_thisId.fIdentifier = c1_identifier;
  c1_thisId.fParent = NULL;
  sf_mex_assign(&c1_y, c1_q_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c1_b_setSimStateSideEffectsInfo), &c1_thisId), false);
  sf_mex_destroy(&c1_b_setSimStateSideEffectsInfo);
  return c1_y;
}

static const mxArray *c1_q_emlrt_marshallIn(SFc1_AllinOneInstanceStruct
  *chartInstance, const mxArray *c1_u, const emlrtMsgIdentifier *c1_parentId)
{
  const mxArray *c1_y = NULL;
  (void)chartInstance;
  (void)c1_parentId;
  c1_y = NULL;
  sf_mex_assign(&c1_y, sf_mex_duplicatearraysafe(&c1_u), false);
  sf_mex_destroy(&c1_u);
  return c1_y;
}

static void c1_updateDataWrittenToVector(SFc1_AllinOneInstanceStruct
  *chartInstance, uint32_T c1_vectorIndex)
{
  chartInstance->c1_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK(0U,
    (int32_T)c1_vectorIndex, 0, 3, 1, 0)] = true;
}

static void c1_errorIfDataNotWrittenToFcn(SFc1_AllinOneInstanceStruct
  *chartInstance, uint32_T c1_vectorIndex, uint32_T c1_dataNumber, uint32_T
  c1_ssIdOfSourceObject, int32_T c1_offsetInSourceObject, int32_T
  c1_lengthInSourceObject)
{
  (void)c1_ssIdOfSourceObject;
  (void)c1_offsetInSourceObject;
  (void)c1_lengthInSourceObject;
  if (!chartInstance->c1_dataWrittenToVector[(uint32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK(0U, (int32_T)c1_vectorIndex, 0, 3, 1, 0)]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(c1_dataNumber);
  }
}

static void init_dsm_address_info(SFc1_AllinOneInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc1_AllinOneInstanceStruct *chartInstance)
{
  chartInstance->c1_Tick = (int8_T *)(ssGetInputPortSignalPtrs_wrapper
    (chartInstance->S, 3))[0U];
  chartInstance->c1_StepEvent = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c1_TakeOutEvent = (int8_T *)(ssGetInputPortSignalPtrs_wrapper
    (chartInstance->S, 3))[1U];
  chartInstance->c1_Step = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c1_InMixtrue = (c1_Mixtrue *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_OutMixtrue = (c1_Mixtrue *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c1_InCup = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c1_OutCup = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c1_AllinOne_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(535383529U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3995047988U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(234467067U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2662145631U);
}

mxArray* sf_c1_AllinOne_get_post_codegen_info(void);
mxArray *sf_c1_AllinOne_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("3yuxwpQdv8FVs4bVHgzvoH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c1_AllinOne_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c1_AllinOne_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c1_AllinOne_jit_fallback_info(void)
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

mxArray *sf_c1_AllinOne_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c1_AllinOne_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c1_AllinOne(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[80],T\"OutCup\",},{M[1],M[78],T\"OutMixtrue\",},{M[3],M[76],T\"CupLocation\",},{M[3],M[118],T\"LocalMixtrue\",},{M[6],M[81],T\"StepEvent\",},{M[7],M[81],T\"StepEventEventCounter\",},{M[8],M[0],T\"is_active_c1_AllinOne\",},{M[8],M[130],T\"is_active_CupTransmit\",},{M[8],M[131],T\"is_active_MixtrueMonitor\",},{M[8],M[137],T\"is_active_CupMonitor\",}}",
    "100 S1x5'type','srcId','name','auxInfo'{{M[9],M[130],T\"is_CupTransmit\",},{M[9],M[131],T\"is_MixtrueMonitor\",},{M[9],M[137],T\"is_CupMonitor\",},{M[11],M[21],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M1x2[125 128],M[1]}}},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 15, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c1_AllinOne_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc1_AllinOneInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc1_AllinOneInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllinOneMachineNumber_,
           1,
           13,
           14,
           0,
           7,
           3,
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
            3,
            3,
            3);
          _SFD_SET_DATA_PROPS(0,1,1,0,"Step");
          _SFD_SET_DATA_PROPS(1,0,0,0,"CupLocation");
          _SFD_SET_DATA_PROPS(2,1,1,0,"InMixtrue");
          _SFD_SET_DATA_PROPS(3,2,0,1,"OutMixtrue");
          _SFD_SET_DATA_PROPS(4,1,1,0,"InCup");
          _SFD_SET_DATA_PROPS(5,2,0,1,"OutCup");
          _SFD_SET_DATA_PROPS(6,0,0,0,"LocalMixtrue");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_EVENT_SCOPE(1,2);
          _SFD_EVENT_SCOPE(2,1);
          _SFD_STATE_INFO(0,0,1);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,1);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_STATE_INFO(7,0,0);
          _SFD_STATE_INFO(8,0,0);
          _SFD_STATE_INFO(9,0,0);
          _SFD_STATE_INFO(10,0,1);
          _SFD_STATE_INFO(11,0,0);
          _SFD_STATE_INFO(12,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(1);
          _SFD_CH_SUBSTATE_INDEX(0,3);
          _SFD_CH_SUBSTATE_INDEX(1,10);
          _SFD_CH_SUBSTATE_INDEX(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,6);
          _SFD_ST_SUBSTATE_INDEX(3,0,4);
          _SFD_ST_SUBSTATE_INDEX(3,1,5);
          _SFD_ST_SUBSTATE_INDEX(3,2,6);
          _SFD_ST_SUBSTATE_INDEX(3,3,7);
          _SFD_ST_SUBSTATE_INDEX(3,4,8);
          _SFD_ST_SUBSTATE_INDEX(3,5,9);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
          _SFD_ST_SUBSTATE_COUNT(7,0);
          _SFD_ST_SUBSTATE_COUNT(8,0);
          _SFD_ST_SUBSTATE_COUNT(9,0);
          _SFD_ST_SUBSTATE_COUNT(10,2);
          _SFD_ST_SUBSTATE_INDEX(10,0,11);
          _SFD_ST_SUBSTATE_INDEX(10,1,12);
          _SFD_ST_SUBSTATE_COUNT(11,0);
          _SFD_ST_SUBSTATE_COUNT(12,0);
          _SFD_ST_SUBSTATE_COUNT(0,2);
          _SFD_ST_SUBSTATE_INDEX(0,0,1);
          _SFD_ST_SUBSTATE_INDEX(0,1,2);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(3,0,0,0);

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
          _SFD_CV_INIT_STATE(3,6,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
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
          _SFD_CV_INIT_STATE(8,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(9,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(10,2,1,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(11,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(12,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(11,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(1,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(9,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(8,0,0,1,56,1,48);

        {
          static int condStart[] = { 1, 31 };

          static int condEnd[] = { 23, 56 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(8,0,0,1,56,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(8,0,0,1,23,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(8,0,1,31,56,-1,2);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(9,0,0,1,23,1,23);
        _SFD_CV_INIT_EML_RELATIONAL(9,0,0,1,23,-1,4);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(10,0,0,1,35,1,35);

        {
          static int condStart[] = { 1, 20 };

          static int condEnd[] = { 12, 35 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(10,0,0,1,35,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(10,0,0,1,12,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(10,0,1,20,35,-1,2);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,12,1,12);
        _SFD_CV_INIT_EML_RELATIONAL(11,0,0,1,12,-1,4);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,0,12,0,12);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,17,1,17);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,17,-1,5);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,19,1,19);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,19,-1,5);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,11,1,11);
        _SFD_CV_INIT_EML_RELATIONAL(5,0,0,1,11,-1,2);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(4,0,0,1,31,1,31);

        {
          static int condStart[] = { 1, 15 };

          static int condEnd[] = { 11, 31 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(4,0,0,1,31,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(4,0,0,1,11,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(4,0,1,15,31,-1,5);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,18,1,18);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,0,15,0,15);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_InMixtrue_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_InMixtrue_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_sf_marshallOut,(MexInFcnForType)c1_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c1_g_sf_marshallOut,(MexInFcnForType)c1_g_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c1_Step);
        _SFD_SET_DATA_VALUE_PTR(1U, &chartInstance->c1_CupLocation);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c1_InMixtrue);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c1_OutMixtrue);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c1_InCup);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c1_OutCup);
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c1_LocalMixtrue);
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
  return "HgWaE9XjDfimpxiUiPbkWB";
}

static void sf_opaque_initialize_c1_AllinOne(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc1_AllinOneInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c1_AllinOne((SFc1_AllinOneInstanceStruct*) chartInstanceVar);
  initialize_c1_AllinOne((SFc1_AllinOneInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c1_AllinOne(void *chartInstanceVar)
{
  enable_c1_AllinOne((SFc1_AllinOneInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c1_AllinOne(void *chartInstanceVar)
{
  disable_c1_AllinOne((SFc1_AllinOneInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c1_AllinOne(void *chartInstanceVar)
{
  sf_gateway_c1_AllinOne((SFc1_AllinOneInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c1_AllinOne(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c1_AllinOne((SFc1_AllinOneInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c1_AllinOne(SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c1_AllinOne((SFc1_AllinOneInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c1_AllinOne(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc1_AllinOneInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllinOne_optimization_info();
    }

    finalize_c1_AllinOne((SFc1_AllinOneInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc1_AllinOne((SFc1_AllinOneInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c1_AllinOne(SimStruct *S)
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
    initialize_params_c1_AllinOne((SFc1_AllinOneInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c1_AllinOne(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_AllinOne_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,1);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,1,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,1,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,1);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,1,3);
    }

    ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,1);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetCallsOutputInInitFcn(S,1);
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(761111347U));
  ssSetChecksum1(S,(80786989U));
  ssSetChecksum2(S,(2778586661U));
  ssSetChecksum3(S,(4250720344U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c1_AllinOne(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c1_AllinOne(SimStruct *S)
{
  SFc1_AllinOneInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc1_AllinOneInstanceStruct *)utMalloc(sizeof
    (SFc1_AllinOneInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc1_AllinOneInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c1_AllinOne;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c1_AllinOne;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c1_AllinOne;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c1_AllinOne;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c1_AllinOne;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c1_AllinOne;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c1_AllinOne;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c1_AllinOne;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c1_AllinOne;
  chartInstance->chartInfo.mdlStart = mdlStart_c1_AllinOne;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c1_AllinOne;
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

void c1_AllinOne_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c1_AllinOne(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c1_AllinOne(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c1_AllinOne(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c1_AllinOne_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
