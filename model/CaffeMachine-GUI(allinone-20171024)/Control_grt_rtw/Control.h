/*
 * Control.h
 *
 * Code generation for model "Control".
 *
 * Model version              : 1.85
 * Simulink Coder version : 8.7 (R2014b) 08-Sep-2014
 * C source code generated on : Sat Oct 28 15:00:44 2017
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_Control_h_
#define RTW_HEADER_Control_h_
#include <float.h>
#include <string.h>
#include <stddef.h>
#ifndef Control_COMMON_INCLUDES_
# define Control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "rt_logging.h"
#endif                                 /* Control_COMMON_INCLUDES_ */

#include "Control_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  ((rtm)->Timing.taskTime0)
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T CoffeeRecipe;                 /* '<Root>/Control System' */
  real_T MilkRecipe;                   /* '<Root>/Control System' */
  real_T SugarRecipe;                  /* '<Root>/Control System' */
  real_T WaterRecipe;                  /* '<Root>/Control System' */
  int32_T sfEvent;                     /* '<Root>/Control System' */
  uint32_T GetCupEventEventCounter;    /* '<Root>/Control System' */
  uint32_T temporalCounter_i1;         /* '<Root>/Control System' */
  uint16_T temporalCounter_i2;         /* '<Root>/Control System' */
  uint8_T is_active_c12_Control;       /* '<Root>/Control System' */
  uint8_T is_c12_Control;              /* '<Root>/Control System' */
  uint8_T is_WaterState;               /* '<Root>/Control System' */
  uint8_T is_active_WaterState;        /* '<Root>/Control System' */
  uint8_T is_SugarDoserState;          /* '<Root>/Control System' */
  uint8_T is_active_SugarDoserState;   /* '<Root>/Control System' */
  uint8_T is_CoffeeDoserState;         /* '<Root>/Control System' */
  uint8_T is_active_CoffeeDoserState;  /* '<Root>/Control System' */
  uint8_T is_MilkDoserState;           /* '<Root>/Control System' */
  uint8_T is_active_MilkDoserState;    /* '<Root>/Control System' */
} DW_Control_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ControlSystem_Trig_ZCE[11];/* '<Root>/Control System' */
} PrevZCX_Control_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T CoffeeRemain;                 /* '<Root>/CoffeeRemain' */
  real_T MilkRemain;                   /* '<Root>/MilkRemain' */
  real_T SugarRemain;                  /* '<Root>/SugarRemain' */
  real_T WaterRemain;                  /* '<Root>/WaterRemain' */
  real_T WaterTemp;                    /* '<Root>/WaterTemp' */
  boolean_T CupRemain;                 /* '<Root>/CupRemain' */
  boolean_T inputevents[11];           /* '<Root>/ input events ' */
} ExtU_Control_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T CoffeeAmount;                 /* '<Root>/CoffeeAmount' */
  real_T MilkAmount;                   /* '<Root>/MilkAmount' */
  real_T SugarAmount;                  /* '<Root>/SugarAmount' */
  real_T WaterAmount;                  /* '<Root>/WaterAmount' */
  real_T NextStep;                     /* '<Root>/NextStep' */
  boolean_T GetCupEvent;               /* '<Root>/GetCupEvent' */
} ExtY_Control_T;

/* Real-time Model Data Structure */
struct tag_RTM_Control_T {
  const char_T *errorStatus;
  RTWLogInfo *rtwLogInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T taskTime0;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block states (auto storage) */
extern DW_Control_T Control_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_Control_T Control_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Control_T Control_Y;

/* Model entry point functions */
extern void Control_initialize(void);
extern void Control_step(void);
extern void Control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Control_T *const Control_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Note that this particular code originates from a subsystem build,
 * and has its own system numbers different from the parent model.
 * Refer to the system hierarchy for this subsystem below, and use the
 * MATLAB hilite_system command to trace the generated code back
 * to the parent model.  For example,
 *
 * hilite_system('AllinOne/Control System')    - opens subsystem AllinOne/Control System
 * hilite_system('AllinOne/Control System/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'AllinOne'
 * '<S1>'   : 'AllinOne/Control System'
 */
#endif                                 /* RTW_HEADER_Control_h_ */
