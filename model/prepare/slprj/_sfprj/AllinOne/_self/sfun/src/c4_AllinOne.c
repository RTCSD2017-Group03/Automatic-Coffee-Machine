/* Include files */

#include "simstruc.h"
#include "fixedpoint.h"
#include "simtarget/slSimTgtLogLoadBlocksSfcnBridge.h"
#include "AllinOne_sfun.h"
#include "c4_AllinOne.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "AllinOne_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c_with_debugger(S, sfGlobalDebugInstanceStruct);

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization);
static void chart_debug_initialize_data_addresses(SimStruct *S);
static const mxArray* sf_opaque_get_hover_data_for_msg(void *chartInstance,
  int32_T msgSSID);

/* Type Definitions */

/* Named Constants */
#define c4_event_Tick                  (0)
#define CALL_EVENT                     (-1)
#define c4_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c4_IN_Finish                   ((uint8_T)1U)
#define c4_IN_Ready                    ((uint8_T)2U)
#define c4_IN_Transmiting              ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c4_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_c_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c4_e_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_f_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c4_g_debug_family_names[2] = { "nargin", "nargout" };

/* Function Declarations */
static void initialize_c4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance);
static void initialize_params_c4_AllinOne(SFc4_AllinOneInstanceStruct
  *chartInstance);
static void enable_c4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance);
static void disable_c4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance);
static void c4_update_debugger_state_c4_AllinOne(SFc4_AllinOneInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c4_AllinOne(SFc4_AllinOneInstanceStruct
  *chartInstance);
static void set_sim_state_c4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_st);
static void c4_set_sim_state_side_effects_c4_AllinOne
  (SFc4_AllinOneInstanceStruct *chartInstance);
static void finalize_c4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance);
static void sf_gateway_c4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance);
static void mdl_start_c4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance);
static void initSimStructsc4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static real_T c4_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_nargout, const char_T *c4_identifier);
static real_T c4_b_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static boolean_T c4_c_emlrt_marshallIn(SFc4_AllinOneInstanceStruct
  *chartInstance, const mxArray *c4_sf_internal_predicateOutput, const char_T
  *c4_identifier);
static boolean_T c4_d_emlrt_marshallIn(SFc4_AllinOneInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint32_T c4_e_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_b_ClearIntegratorEventEventCounter, const char_T
  *c4_identifier);
static uint32_T c4_f_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int8_T c4_g_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_h_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static uint8_T c4_i_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_b_tp_Ready, const char_T *c4_identifier);
static uint8_T c4_j_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static void c4_k_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_b_dataWrittenToVector, const char_T *c4_identifier,
  boolean_T c4_y[2]);
static void c4_l_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T c4_y[2]);
static const mxArray *c4_m_emlrt_marshallIn(SFc4_AllinOneInstanceStruct
  *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T
  *c4_identifier);
static const mxArray *c4_n_emlrt_marshallIn(SFc4_AllinOneInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static const mxArray *sf_get_hover_data_for_msg(SFc4_AllinOneInstanceStruct
  *chartInstance, int32_T c4_ssid);
static void c4_init_sf_message_store_memory(SFc4_AllinOneInstanceStruct
  *chartInstance);
static void init_test_point_addr_map(SFc4_AllinOneInstanceStruct *chartInstance);
static void **get_test_point_address_map(SFc4_AllinOneInstanceStruct
  *chartInstance);
static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc4_AllinOneInstanceStruct *chartInstance);
static void **get_dataset_logging_obj_vector(SFc4_AllinOneInstanceStruct
  *chartInstance);
static void init_dsm_address_info(SFc4_AllinOneInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc4_AllinOneInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance)
{
  if (sf_is_first_init_cond(chartInstance->S)) {
    initSimStructsc4_AllinOne(chartInstance);
    chart_debug_initialize_data_addresses(chartInstance->S);
  }

  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_doSetSimStateSideEffects = 0U;
  chartInstance->c4_setSimStateSideEffectsInfo = NULL;
  chartInstance->c4_tp_Finish = 0U;
  chartInstance->c4_temporalCounter_i1 = 0U;
  chartInstance->c4_tp_Ready = 0U;
  chartInstance->c4_tp_Transmiting = 0U;
  ssLoggerUpdateTimeseries(chartInstance->S,
    chartInstance->c4_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
    &chartInstance->c4_tp_Transmiting);
  chartInstance->c4_is_active_c4_AllinOne = 0U;
  chartInstance->c4_is_c4_AllinOne = c4_IN_NO_ACTIVE_CHILD;
  chartInstance->c4_ClearIntegratorEventEventCounter = 0U;
  *chartInstance->c4_ClearIntegratorEvent = false;
  _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  chartInstance->c4_is_active_c4_AllinOne = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
  chartInstance->c4_is_c4_AllinOne = c4_IN_Ready;
  _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
  chartInstance->c4_tp_Ready = 1U;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_AllinOneMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initialize_params_c4_AllinOne(SFc4_AllinOneInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_AllinOne(SFc4_AllinOneInstanceStruct
  *chartInstance)
{
  uint32_T c4_prevAniVal;
  c4_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (chartInstance->c4_is_active_c4_AllinOne == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_AllinOne == c4_IN_Ready) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_AllinOne == c4_IN_Finish) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
  }

  if (chartInstance->c4_is_c4_AllinOne == c4_IN_Transmiting) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
  }

  _SFD_SET_ANIMATION(c4_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static const mxArray *get_sim_state_c4_AllinOne(SFc4_AllinOneInstanceStruct
  *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  real_T c4_hoistedGlobal;
  const mxArray *c4_b_y = NULL;
  real_T c4_b_hoistedGlobal;
  const mxArray *c4_c_y = NULL;
  boolean_T c4_c_hoistedGlobal;
  const mxArray *c4_d_y = NULL;
  uint32_T c4_d_hoistedGlobal;
  const mxArray *c4_e_y = NULL;
  uint8_T c4_e_hoistedGlobal;
  const mxArray *c4_f_y = NULL;
  uint8_T c4_f_hoistedGlobal;
  const mxArray *c4_g_y = NULL;
  uint8_T c4_g_hoistedGlobal;
  const mxArray *c4_h_y = NULL;
  const mxArray *c4_i_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(8, 1), false);
  c4_hoistedGlobal = *chartInstance->c4_RemainLiquid;
  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", &c4_hoistedGlobal, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  c4_b_hoistedGlobal = chartInstance->c4_TargetAmount;
  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", &c4_b_hoistedGlobal, 0, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_c_hoistedGlobal = *chartInstance->c4_ClearIntegratorEvent;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_hoistedGlobal, 11, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  c4_d_hoistedGlobal = chartInstance->c4_ClearIntegratorEventEventCounter;
  c4_e_y = NULL;
  sf_mex_assign(&c4_e_y, sf_mex_create("y", &c4_d_hoistedGlobal, 7, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 3, c4_e_y);
  c4_e_hoistedGlobal = chartInstance->c4_is_active_c4_AllinOne;
  c4_f_y = NULL;
  sf_mex_assign(&c4_f_y, sf_mex_create("y", &c4_e_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 4, c4_f_y);
  c4_f_hoistedGlobal = chartInstance->c4_is_c4_AllinOne;
  c4_g_y = NULL;
  sf_mex_assign(&c4_g_y, sf_mex_create("y", &c4_f_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 5, c4_g_y);
  c4_g_hoistedGlobal = chartInstance->c4_temporalCounter_i1;
  c4_h_y = NULL;
  sf_mex_assign(&c4_h_y, sf_mex_create("y", &c4_g_hoistedGlobal, 3, 0U, 0U, 0U,
    0), false);
  sf_mex_setcell(c4_y, 6, c4_h_y);
  c4_i_y = NULL;
  sf_mex_assign(&c4_i_y, sf_mex_create("y",
    chartInstance->c4_dataWrittenToVector, 11, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c4_y, 7, c4_i_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_st)
{
  const mxArray *c4_u;
  boolean_T c4_bv0[2];
  int32_T c4_i0;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  *chartInstance->c4_RemainLiquid = c4_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("RemainLiquid", c4_u, 0)), "RemainLiquid");
  chartInstance->c4_TargetAmount = c4_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell("TargetAmount", c4_u, 1)), "TargetAmount");
  *chartInstance->c4_ClearIntegratorEvent = c4_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("ClearIntegratorEvent", c4_u, 2)),
    "ClearIntegratorEvent");
  chartInstance->c4_ClearIntegratorEventEventCounter = c4_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell("ClearIntegratorEventEventCounter",
       c4_u, 3)), "ClearIntegratorEventEventCounter");
  chartInstance->c4_is_active_c4_AllinOne = c4_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_active_c4_AllinOne", c4_u, 4)),
    "is_active_c4_AllinOne");
  chartInstance->c4_is_c4_AllinOne = c4_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("is_c4_AllinOne", c4_u, 5)), "is_c4_AllinOne");
  chartInstance->c4_temporalCounter_i1 = c4_i_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell("temporalCounter_i1", c4_u, 6)),
    "temporalCounter_i1");
  c4_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "dataWrittenToVector", c4_u, 7)), "dataWrittenToVector", c4_bv0);
  for (c4_i0 = 0; c4_i0 < 2; c4_i0++) {
    chartInstance->c4_dataWrittenToVector[c4_i0] = c4_bv0[c4_i0];
  }

  sf_mex_assign(&chartInstance->c4_setSimStateSideEffectsInfo,
                c4_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(
    "setSimStateSideEffectsInfo", c4_u, 8)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c4_u);
  chartInstance->c4_doSetSimStateSideEffects = 1U;
  c4_update_debugger_state_c4_AllinOne(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void c4_set_sim_state_side_effects_c4_AllinOne
  (SFc4_AllinOneInstanceStruct *chartInstance)
{
  if (chartInstance->c4_doSetSimStateSideEffects != 0) {
    if (chartInstance->c4_is_c4_AllinOne == c4_IN_Finish) {
      chartInstance->c4_tp_Finish = 1U;
      if (sf_mex_sub(chartInstance->c4_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        chartInstance->c4_temporalCounter_i1 = 0U;
      }
    } else {
      chartInstance->c4_tp_Finish = 0U;
    }

    chartInstance->c4_tp_Ready = (uint8_T)(chartInstance->c4_is_c4_AllinOne ==
      c4_IN_Ready);
    chartInstance->c4_tp_Transmiting = (uint8_T)
      (chartInstance->c4_is_c4_AllinOne == c4_IN_Transmiting);
    chartInstance->c4_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c4_setSimStateSideEffectsInfo);
}

static void sf_gateway_c4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance)
{
  uint32_T c4_debug_family_var_map[3];
  real_T c4_nargin = 0.0;
  real_T c4_b_nargin = 0.0;
  real_T c4_c_nargin = 0.0;
  real_T c4_nargout = 1.0;
  real_T c4_b_nargout = 1.0;
  real_T c4_c_nargout = 1.0;
  boolean_T c4_out;
  boolean_T c4_b_out;
  boolean_T c4_c_out;
  uint32_T c4_b_debug_family_var_map[2];
  real_T c4_d_nargin = 0.0;
  real_T c4_d_nargout = 0.0;
  real_T c4_e_nargin = 0.0;
  real_T c4_e_nargout = 0.0;
  real_T c4_f_nargin = 0.0;
  real_T c4_f_nargout = 0.0;
  real_T c4_g_nargin = 0.0;
  real_T c4_g_nargout = 0.0;
  real_T c4_hoistedGlobal;
  real_T c4_A;
  real_T c4_x;
  real_T c4_b_x;
  c4_set_sim_state_side_effects_c4_AllinOne(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_OutLiquid, 2U, 1U, 0U,
                        chartInstance->c4_sfEvent, false);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c4_SettingAmount, 1U, 1U, 0U,
                        chartInstance->c4_sfEvent, false);
  if (chartInstance->c4_temporalCounter_i1 < 7U) {
    chartInstance->c4_temporalCounter_i1++;
  }

  chartInstance->c4_sfEvent = c4_event_Tick;
  _SFD_CE_CALL(EVENT_BEFORE_BROADCAST_TAG, c4_event_Tick,
               chartInstance->c4_sfEvent);
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  switch (chartInstance->c4_is_c4_AllinOne) {
   case c4_IN_Finish:
    CV_CHART_EVAL(3, 0, 1);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_c_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_out, 2U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    if (CV_EML_COND(3, 0, 0, chartInstance->c4_temporalCounter_i1 >= 5) &&
        CV_EML_COND(3, 0, 1, *chartInstance->c4_SettingAmount == 0.0)) {
      CV_EML_MCDC(3, 0, 0, true);
      CV_EML_IF(3, 0, 0, true);
      c4_out = true;
    } else {
      CV_EML_MCDC(3, 0, 0, false);
      CV_EML_IF(3, 0, 0, false);
      c4_out = false;
    }

    _SFD_SYMBOL_SCOPE_POP();
    if (c4_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_d_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_e_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      chartInstance->c4_ClearIntegratorEventEventCounter++;
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c4_tp_Finish = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
      chartInstance->c4_is_c4_AllinOne = c4_IN_Ready;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_Ready = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   chartInstance->c4_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_Ready:
    CV_CHART_EVAL(3, 0, 2);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_e_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_b_out, 2U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    c4_b_out = CV_EML_IF(0, 0, 0, CV_RELATIONAL_EVAL(5U, 0U, 0,
      *chartInstance->c4_SettingAmount, 0.0, -1, 4U,
      *chartInstance->c4_SettingAmount > 0.0));
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_b_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_Ready = 0U;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
      chartInstance->c4_is_c4_AllinOne = c4_IN_Transmiting;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
      chartInstance->c4_tp_Transmiting = 1U;
      ssLoggerUpdateTimeseries(chartInstance->S,
        chartInstance->c4_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
        &chartInstance->c4_tp_Transmiting);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_f_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      chartInstance->c4_TargetAmount = *chartInstance->c4_SettingAmount;
      chartInstance->c4_dataWrittenToVector[1U] = true;
      _SFD_DATA_RANGE_CHECK(chartInstance->c4_TargetAmount, 0U, 4U, 2U,
                            chartInstance->c4_sfEvent, false);
      if (!chartInstance->c4_dataWrittenToVector[1U]) {
        _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 4U, 2U, chartInstance->c4_sfEvent,
          false);
      }

      c4_hoistedGlobal = chartInstance->c4_TargetAmount;
      c4_A = c4_hoistedGlobal;
      c4_x = c4_A;
      c4_b_x = c4_x;
      *chartInstance->c4_RemainLiquid = c4_b_x / 3.0;
      chartInstance->c4_dataWrittenToVector[0U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c4_RemainLiquid, 3U, 4U, 2U,
                            chartInstance->c4_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                   chartInstance->c4_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c4_sfEvent);
    break;

   case c4_IN_Transmiting:
    CV_CHART_EVAL(3, 0, 3);
    _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U, chartInstance->c4_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c4_f_debug_family_names,
      c4_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargin, 0U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_nargout, 1U, c4_sf_marshallOut,
      c4_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_c_out, 2U, c4_b_sf_marshallOut,
      c4_b_sf_marshallIn);
    if (!chartInstance->c4_dataWrittenToVector[1U]) {
      _SFD_DATA_READ_BEFORE_WRITE_ERROR(0U, 5U, 1U, chartInstance->c4_sfEvent,
        false);
    }

    c4_c_out = CV_EML_IF(1, 0, 0, chartInstance->c4_TargetAmount -
                         *chartInstance->c4_OutLiquid <= 0.0);
    _SFD_SYMBOL_SCOPE_POP();
    if (c4_c_out) {
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_g_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_d_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      chartInstance->c4_ClearIntegratorEventEventCounter++;
      _SFD_SYMBOL_SCOPE_POP();
      chartInstance->c4_tp_Transmiting = 0U;
      ssLoggerUpdateTimeseries(chartInstance->S,
        chartInstance->c4_dataSetLogObjVector[0], 0, _sfTime_, (char_T *)
        &chartInstance->c4_tp_Transmiting);
      _SFD_CS_CALL(STATE_ENTER_EXIT_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c4_b_debug_family_names,
        c4_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargin, 0U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_g_nargout, 1U, c4_sf_marshallOut,
        c4_sf_marshallIn);
      *chartInstance->c4_RemainLiquid = 0.0;
      chartInstance->c4_dataWrittenToVector[0U] = true;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c4_RemainLiquid, 3U, 4U, 2U,
                            chartInstance->c4_sfEvent, false);
      _SFD_SYMBOL_SCOPE_POP();
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, chartInstance->c4_sfEvent);
      chartInstance->c4_is_c4_AllinOne = c4_IN_Finish;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
      chartInstance->c4_temporalCounter_i1 = 0U;
      chartInstance->c4_tp_Finish = 1U;
    } else {
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                   chartInstance->c4_sfEvent);
    }

    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
    break;

   default:
    CV_CHART_EVAL(3, 0, 0);

    /* Unreachable state, for coverage only */
    chartInstance->c4_is_c4_AllinOne = c4_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, chartInstance->c4_sfEvent);
    break;
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, chartInstance->c4_sfEvent);
  _SFD_CE_CALL(EVENT_AFTER_BROADCAST_TAG, c4_event_Tick,
               chartInstance->c4_sfEvent);
  if (chartInstance->c4_ClearIntegratorEventEventCounter > 0U) {
    *chartInstance->c4_ClearIntegratorEvent =
      !*chartInstance->c4_ClearIntegratorEvent;
    chartInstance->c4_ClearIntegratorEventEventCounter--;
  }

  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_AllinOneMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance)
{
  c4_init_sf_message_store_memory(chartInstance);
}

static void initSimStructsc4_AllinOne(SFc4_AllinOneInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)(c4_machineNumber);
  (void)(c4_chartNumber);
  (void)(c4_instanceNumber);
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllinOneInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_nargout, const char_T *c4_identifier)
{
  real_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  return c4_y;
}

static real_T c4_b_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllinOneInstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  boolean_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllinOneInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(boolean_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static boolean_T c4_c_emlrt_marshallIn(SFc4_AllinOneInstanceStruct
  *chartInstance, const mxArray *c4_sf_internal_predicateOutput, const char_T
  *c4_identifier)
{
  boolean_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_sf_internal_predicateOutput), &c4_thisId);
  sf_mex_destroy(&c4_sf_internal_predicateOutput);
  return c4_y;
}

static boolean_T c4_d_emlrt_marshallIn(SFc4_AllinOneInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  boolean_T c4_y;
  boolean_T c4_b0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_b0, 1, 11, 0U, 0, 0U, 0);
  c4_y = c4_b0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_sf_internal_predicateOutput;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  boolean_T c4_y;
  SFc4_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllinOneInstanceStruct *)chartInstanceVoid;
  c4_sf_internal_predicateOutput = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_sf_internal_predicateOutput), &c4_thisId);
  sf_mex_destroy(&c4_sf_internal_predicateOutput);
  *(boolean_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_AllinOne_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  uint32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllinOneInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(uint32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static uint32_T c4_e_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_b_ClearIntegratorEventEventCounter, const char_T
  *c4_identifier)
{
  uint32_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_ClearIntegratorEventEventCounter), &c4_thisId);
  sf_mex_destroy(&c4_b_ClearIntegratorEventEventCounter);
  return c4_y;
}

static uint32_T c4_f_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint32_T c4_y;
  uint32_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 7, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_ClearIntegratorEventEventCounter;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint32_T c4_y;
  SFc4_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllinOneInstanceStruct *)chartInstanceVoid;
  c4_b_ClearIntegratorEventEventCounter = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_ClearIntegratorEventEventCounter), &c4_thisId);
  sf_mex_destroy(&c4_b_ClearIntegratorEventEventCounter);
  *(uint32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int8_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllinOneInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(int8_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 2, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int8_T c4_g_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int8_T c4_y;
  int8_T c4_i1;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i1, 1, 2, 0U, 0, 0U, 0);
  c4_y = c4_i1;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_Tick;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int8_T c4_y;
  SFc4_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllinOneInstanceStruct *)chartInstanceVoid;
  c4_b_Tick = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_Tick), &c4_thisId);
  sf_mex_destroy(&c4_b_Tick);
  *(int8_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_e_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllinOneInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_h_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i2;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i2, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i2;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllinOneInstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_f_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData;
  uint8_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllinOneInstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_mxArrayOutData = NULL;
  c4_u = *(uint8_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static uint8_T c4_i_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_b_tp_Ready, const char_T *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_tp_Ready),
    &c4_thisId);
  sf_mex_destroy(&c4_b_tp_Ready);
  return c4_y;
}

static uint8_T c4_j_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u1;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u1, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u1;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_tp_Ready;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  uint8_T c4_y;
  SFc4_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllinOneInstanceStruct *)chartInstanceVoid;
  c4_b_tp_Ready = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_y = c4_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_tp_Ready),
    &c4_thisId);
  sf_mex_destroy(&c4_b_tp_Ready);
  *(uint8_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static void c4_k_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_b_dataWrittenToVector, const char_T *c4_identifier,
  boolean_T c4_y[2])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  c4_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_dataWrittenToVector),
                        &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_dataWrittenToVector);
}

static void c4_l_emlrt_marshallIn(SFc4_AllinOneInstanceStruct *chartInstance,
  const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId, boolean_T c4_y[2])
{
  boolean_T c4_bv1[2];
  int32_T c4_i3;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_bv1, 1, 11, 0U, 1, 0U, 1, 2);
  for (c4_i3 = 0; c4_i3 < 2; c4_i3++) {
    c4_y[c4_i3] = c4_bv1[c4_i3];
  }

  sf_mex_destroy(&c4_u);
}

static const mxArray *c4_m_emlrt_marshallIn(SFc4_AllinOneInstanceStruct
  *chartInstance, const mxArray *c4_b_setSimStateSideEffectsInfo, const char_T
  *c4_identifier)
{
  const mxArray *c4_y = NULL;
  emlrtMsgIdentifier c4_thisId;
  c4_y = NULL;
  c4_thisId.fIdentifier = (const char *)c4_identifier;
  c4_thisId.fParent = NULL;
  c4_thisId.bParentIsCell = false;
  sf_mex_assign(&c4_y, c4_n_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_setSimStateSideEffectsInfo), &c4_thisId), false);
  sf_mex_destroy(&c4_b_setSimStateSideEffectsInfo);
  return c4_y;
}

static const mxArray *c4_n_emlrt_marshallIn(SFc4_AllinOneInstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  const mxArray *c4_y = NULL;
  (void)chartInstance;
  (void)c4_parentId;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_duplicatearraysafe(&c4_u), false);
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static const mxArray *sf_get_hover_data_for_msg(SFc4_AllinOneInstanceStruct
  *chartInstance, int32_T c4_ssid)
{
  const mxArray *c4_msgInfo;
  (void)chartInstance;
  (void)c4_ssid;
  c4_msgInfo = NULL;
  return NULL;
}

static void c4_init_sf_message_store_memory(SFc4_AllinOneInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_test_point_addr_map(SFc4_AllinOneInstanceStruct *chartInstance)
{
  chartInstance->c4_testPointAddrMap[0] = &chartInstance->c4_tp_Transmiting;
}

static void **get_test_point_address_map(SFc4_AllinOneInstanceStruct
  *chartInstance)
{
  return &chartInstance->c4_testPointAddrMap[0];
}

static rtwCAPI_ModelMappingInfo *get_test_point_mapping_info
  (SFc4_AllinOneInstanceStruct *chartInstance)
{
  return &chartInstance->c4_testPointMappingInfo;
}

static void **get_dataset_logging_obj_vector(SFc4_AllinOneInstanceStruct
  *chartInstance)
{
  return &chartInstance->c4_dataSetLogObjVector[0];
}

static void init_dsm_address_info(SFc4_AllinOneInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_AllinOneInstanceStruct *chartInstance)
{
  chartInstance->c4_ClearIntegratorEvent = (boolean_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c4_Tick = (int8_T *)(ssGetInputPortSignalPtrs_wrapper
    (chartInstance->S, 2))[0U];
  chartInstance->c4_fEmlrtCtx = (void *)sfrtGetEmlrtCtx(chartInstance->S);
  chartInstance->c4_SettingAmount = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_RemainLiquid = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_OutLiquid = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
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

static void init_test_point_mapping_info(SimStruct *S);
void sf_c4_AllinOne_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2044242143U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(836839244U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2008961677U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2671551559U);
}

mxArray* sf_c4_AllinOne_get_post_codegen_info(void);
mxArray *sf_c4_AllinOne_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("6x4HTUQy9mBWYFxma0J9bC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
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

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,0,mxREAL);
      double *pr = mxGetPr(mxSize);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt", "isFixedPointType" };

      mxArray *mxType = mxCreateStructMatrix(1,1,sizeof(typeFields)/sizeof
        (typeFields[0]),typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxType,0,"isFixedPointType",mxCreateDoubleScalar(0));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c4_AllinOne_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_AllinOne_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_AllinOne_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "hiddenFallbackType", "hiddenFallbackReason", "incompatibleSymbol" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 5, infoFields);
  mxArray *fallbackType = mxCreateString("early");
  mxArray *fallbackReason = mxCreateString("logging");
  mxArray *hiddenFallbackType = mxCreateString("");
  mxArray *hiddenFallbackReason = mxCreateString("");
  mxArray *incompatibleSymbol = mxCreateString("Transmiting");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], hiddenFallbackType);
  mxSetField(mxInfo, 0, infoFields[3], hiddenFallbackReason);
  mxSetField(mxInfo, 0, infoFields[4], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c4_AllinOne_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_AllinOne_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c4_AllinOne(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[3],T\"RemainLiquid\",},{M[3],M[11],T\"TargetAmount\",},{M[6],M[4],T\"ClearIntegratorEvent\",},{M[7],M[4],T\"ClearIntegratorEventEventCounter\",},{M[8],M[0],T\"is_active_c4_AllinOne\",},{M[9],M[0],T\"is_c4_AllinOne\",},{M[11],M[17],T\"temporalCounter_i1\",S'et','os','ct'{{T\"ev\",M[15],M[1]}}},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_AllinOne_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static const mxArray* sf_opaque_get_hover_data_for_msg(void* chartInstance,
  int32_T msgSSID)
{
  return sf_get_hover_data_for_msg( (SFc4_AllinOneInstanceStruct *)
    chartInstance, msgSSID);
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_AllinOneInstanceStruct *chartInstance = (SFc4_AllinOneInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _AllinOneMachineNumber_,
           4,
           3,
           4,
           0,
           4,
           2,
           0,
           0,
           0,
           0,
           &chartInstance->chartNumber,
           &chartInstance->instanceNumber,
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
            2,
            2,
            2);
          _SFD_SET_DATA_PROPS(0,0,0,0,"TargetAmount");
          _SFD_SET_DATA_PROPS(1,1,1,0,"SettingAmount");
          _SFD_SET_DATA_PROPS(2,1,1,0,"OutLiquid");
          _SFD_SET_DATA_PROPS(3,2,0,1,"RemainLiquid");
          _SFD_EVENT_SCOPE(0,1);
          _SFD_EVENT_SCOPE(1,2);
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_CH_SUBSTATE_COUNT(3);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,2);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,0);
          _SFD_ST_SUBSTATE_COUNT(2,0);
        }

        _SFD_CV_INIT_CHART(3,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(3,0,0,1,35,1,35);

        {
          static int condStart[] = { 1, 19 };

          static int condEnd[] = { 15, 35 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(3,0,0,1,35,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML(0,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,18,1,18);
        _SFD_CV_INIT_EML_RELATIONAL(0,0,0,1,18,-1,4);
        _SFD_CV_INIT_EML(1,0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,30,1,30);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)c4_sf_marshallIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _AllinOneMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static void chart_debug_initialize_data_addresses(SimStruct *S)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_AllinOneInstanceStruct *chartInstance = (SFc4_AllinOneInstanceStruct *)
      sf_get_chart_instance_ptr(S);
    if (ssIsFirstInitCond(S)) {
      /* do this only if simulation is starting and after we know the addresses of all data */
      {
        _SFD_SET_DATA_VALUE_PTR(1U, (void *)chartInstance->c4_SettingAmount);
        _SFD_SET_DATA_VALUE_PTR(3U, (void *)chartInstance->c4_RemainLiquid);
        _SFD_SET_DATA_VALUE_PTR(2U, (void *)chartInstance->c4_OutLiquid);
        _SFD_SET_DATA_VALUE_PTR(0U, (void *)&chartInstance->c4_TargetAmount);
      }
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "slHMg57zRE5cmTVK6YiGJSF";
}

static void sf_opaque_initialize_c4_AllinOne(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_AllinOneInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c4_AllinOne((SFc4_AllinOneInstanceStruct*) chartInstanceVar);
  initialize_c4_AllinOne((SFc4_AllinOneInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c4_AllinOne(void *chartInstanceVar)
{
  enable_c4_AllinOne((SFc4_AllinOneInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_AllinOne(void *chartInstanceVar)
{
  disable_c4_AllinOne((SFc4_AllinOneInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_AllinOne(void *chartInstanceVar)
{
  sf_gateway_c4_AllinOne((SFc4_AllinOneInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_AllinOne(SimStruct* S)
{
  return get_sim_state_c4_AllinOne((SFc4_AllinOneInstanceStruct *)
    sf_get_chart_instance_ptr(S));     /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_AllinOne(SimStruct* S, const mxArray *st)
{
  set_sim_state_c4_AllinOne((SFc4_AllinOneInstanceStruct*)
    sf_get_chart_instance_ptr(S), st);
}

static void sf_opaque_terminate_c4_AllinOne(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_AllinOneInstanceStruct*) chartInstanceVar)->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_AllinOne_optimization_info();
    }

    finalize_c4_AllinOne((SFc4_AllinOneInstanceStruct*) chartInstanceVar);
    if (!sim_mode_is_rtw_gen(S)) {
      ssSetModelMappingInfoPtr(S, NULL);
    }

    utFree(chartInstanceVar);
    if (ssGetUserData(S)!= NULL) {
      sf_free_ChartRunTimeInfo(S);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc4_AllinOne((SFc4_AllinOneInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_AllinOne(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c4_AllinOne((SFc4_AllinOneInstanceStruct*)
      sf_get_chart_instance_ptr(S));
  }
}

static void mdlSetWorkWidths_c4_AllinOne(SimStruct *S)
{
  ssSetStatesModifiedOnlyInUpdate(S, 0);
  ssMdlUpdateIsEmpty(S, 1);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_AllinOne_optimization_info(sim_mode_is_rtw_gen(S),
      sim_mode_is_modelref_sim(S), sim_mode_is_external(S));
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,1);
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_set_chart_accesses_machine_info(S, sf_get_instance_specialization(),
      infoStruct, 4);
    sf_update_buildInfo(S, sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    sf_register_codegen_names_for_scoped_functions_defined_by_chart(S);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
    ssSetCallsOutputInInitFcn(S,1);
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  if (sim_mode_is_modelref_sim(S)) {
    mxArray *prhs[4];
    mxArray *plhs[1];
    uint32_T newChkSum[4];
    double *inPr, *outPr;
    int i;
    int firstSlashIdx = 0;
    for (i = 0; i < 999 && S->path[i] != '\0' ; ++i) {
      if (S->path[i] == '/') {
        firstSlashIdx = i;
        break;
      }
    }

    prhs[0] = mxCreateString("Private");
    prhs[1] = mxCreateString("md5");
    prhs[2] = mxCreateDoubleMatrix(1, 4, mxREAL);
    prhs[3] = mxCreateString(S->path + firstSlashIdx + 1);
    inPr = mxGetPr(prhs[2]);
    inPr[0] = 1384996932U;
    inPr[1] = 3962450646U;
    inPr[2] = 3787633275U;
    inPr[3] = 2429910632U;
    mexCallMATLAB(1, plhs, 4, prhs, "sf");
    outPr = mxGetPr(plhs[0]);
    for (i = 0; i < 4; ++i) {
      newChkSum[i] = (uint32_T) outPr[i];
    }

    ssSetChecksum0(S, newChkSum[0]);
    ssSetChecksum1(S, newChkSum[1]);
    ssSetChecksum2(S, newChkSum[2]);
    ssSetChecksum3(S, newChkSum[3]);
    mxDestroyArray(plhs[0]);
    mxDestroyArray(prhs[0]);
    mxDestroyArray(prhs[1]);
    mxDestroyArray(prhs[2]);
    mxDestroyArray(prhs[3]);
  } else {
    ssSetChecksum0(S,(1384996932U));
    ssSetChecksum1(S,(3962450646U));
    ssSetChecksum2(S,(3787633275U));
    ssSetChecksum3(S,(2429910632U));
  }

  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSetStateSemanticsClassicAndSynchronous(S, true);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_AllinOne(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c4_AllinOne(SimStruct *S)
{
  SFc4_AllinOneInstanceStruct *chartInstance;
  chartInstance = (SFc4_AllinOneInstanceStruct *)utMalloc(sizeof
    (SFc4_AllinOneInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  memset(chartInstance, 0, sizeof(SFc4_AllinOneInstanceStruct));
  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_AllinOne;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c4_AllinOne;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_AllinOne;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_AllinOne;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_AllinOne;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c4_AllinOne;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c4_AllinOne;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c4_AllinOne;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_AllinOne;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_AllinOne;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_AllinOne;
  chartInstance->chartInfo.callGetHoverDataForMsg =
    sf_opaque_get_hover_data_for_msg;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  sf_init_ChartRunTimeInfo(S, &(chartInstance->chartInfo), false, 0);
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
    init_test_point_mapping_info(S);
  }

  chart_debug_initialization(S,1);
  mdl_start_c4_AllinOne(chartInstance);
}

void c4_AllinOne_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_AllinOne(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_AllinOne(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_AllinOne(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_AllinOne_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}

static const rtwCAPI_DataTypeMap dataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, isComplex, isPointer */
  { "uint8_T", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 } };

static real_T sfCAPIsampleTimeZero = 0.0;
static const rtwCAPI_SampleTimeMap sampleTimeMap[] = {
  /* *period, *offset, taskId, mode */
  { &sfCAPIsampleTimeZero, &sfCAPIsampleTimeZero, 0, 0 }
};

static const rtwCAPI_DimensionMap dimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims*/
  { rtwCAPI_SCALAR, 0, 2 } };

static const rtwCAPI_Signals testPointSignals[] = {
  /* addrMapIndex, sysNum, SFRelativePath, dataName, portNumber, dataTypeIndex, dimIndex, fixPtIdx, sTimeIndex */
  { 0, 0, "StateflowChart/Transmiting", "Transmiting", 0, 0, 0, 0, 0 } };

static const rtwCAPI_FixPtMap fixedPointMap[] = {
  /* *fracSlope, *bias, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 64, 0, 0 } };

static const uint_T dimensionArray[] = {
  1, 1 };

static rtwCAPI_ModelMappingStaticInfo testPointMappingStaticInfo = {
  /* block signal monitoring */
  {
    testPointSignals,                  /* Block signals Array  */
    1,                                 /* Num Block IO signals */
    NULL,                              /* Root Inputs Array    */
    0,                                 /* Num root inputs      */
    NULL,                              /* Root Outputs Array */
    0                                  /* Num root outputs   */
  },

  /* parameter tuning */
  {
    NULL,                              /* Block parameters Array    */
    0,                                 /* Num block parameters      */
    NULL,                              /* Variable parameters Array */
    0                                  /* Num variable parameters   */
  },

  /* block states */
  {
    NULL,                              /* Block States array        */
    0                                  /* Num Block States          */
  },

  /* Static maps */
  {
    dataTypeMap,                       /* Data Type Map            */
    dimensionMap,                      /* Data Dimension Map       */
    fixedPointMap,                     /* Fixed Point Map          */
    NULL,                              /* Structure Element map    */
    sampleTimeMap,                     /* Sample Times Map         */
    dimensionArray                     /* Dimension Array          */
  },

  /* Target type */
  "float",

  {
    1384996932U,
    3962450646U,
    3787633275U,
    2429910632U
  }
};

static void init_signal_logging_objects(SimStruct *S, rtwCAPI_ModelMappingInfo
  *testPointMappingInfo)
{
  void ** chartDatasetLoggingObjs;
  void *pSetDescr;
  int i;
  size_t lastSlashIdx = 0;
  chartDatasetLoggingObjs = get_dataset_logging_obj_vector
    ((SFc4_AllinOneInstanceStruct *)sf_get_chart_instance_ptr(S));

  /* Initialize signal log vector */
  for (i = 0; i < 1; ++i) {
    chartDatasetLoggingObjs[i] = NULL;
  }

  _ssLoggerCreateDatasetDescriptWithMMI(S, testPointMappingInfo, 0, NULL,
    NULL, &pSetDescr);
  if (pSetDescr) {
    {
      void *pElementDescr;
      int_T dimArray[] = { 1 };

      ssLoggerAddStateflowElementDescription(S, &pSetDescr,
        "Stateflow.SimulationData.State",
        "Transmiting",
        NULL,
        "StateflowChart/Transmiting",
        NULL,
        &pElementDescr);
      ssLoggerAddTimeseriesDescriptionWithInterpolation(S, &pSetDescr,
        &pElementDescr,
        "Transmiting",
        1,
        dimArray,
        SS_UINT8,
        0,
        SS_ZOH_INTERPOLATION);
    }

    ssLoggerCreateElementFromDescription(S, &pSetDescr,
      chartDatasetLoggingObjs);
    if (chartDatasetLoggingObjs[0] != NULL) {
      mxArray *pVal = mxCreateDoubleScalar(8);
      ssLoggerAddElementProperty(S,
        chartDatasetLoggingObjs[0],
        "SSIdNumber",
        pVal);
    }
  }
}

static void init_test_point_mapping_info(SimStruct *S)
{
  rtwCAPI_ModelMappingInfo *testPointMappingInfo;
  void **testPointAddrMap;
  SFc4_AllinOneInstanceStruct *chartInstance = (SFc4_AllinOneInstanceStruct *)
    sf_get_chart_instance_ptr(S);
  init_test_point_addr_map(chartInstance);
  testPointMappingInfo = get_test_point_mapping_info(chartInstance);
  testPointAddrMap = get_test_point_address_map(chartInstance);
  rtwCAPI_SetStaticMap(*testPointMappingInfo, &testPointMappingStaticInfo);
  rtwCAPI_SetLoggingStaticMap(*testPointMappingInfo, NULL);
  rtwCAPI_SetInstanceLoggingInfo(*testPointMappingInfo, NULL);
  rtwCAPI_SetPath(*testPointMappingInfo, "");
  rtwCAPI_SetFullPath(*testPointMappingInfo, NULL);
  rtwCAPI_SetDataAddressMap(*testPointMappingInfo, testPointAddrMap);
  rtwCAPI_SetChildMMIArray(*testPointMappingInfo, NULL);
  rtwCAPI_SetChildMMIArrayLen(*testPointMappingInfo, 0);
  ssSetModelMappingInfoPtr(S, testPointMappingInfo);
  init_signal_logging_objects(S, testPointMappingInfo);
}
