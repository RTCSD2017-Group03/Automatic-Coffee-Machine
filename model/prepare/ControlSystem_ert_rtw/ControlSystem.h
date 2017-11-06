/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlSystem.h
 *
 * Code generated for Simulink model 'ControlSystem'.
 *
 * Model version                  : 1.107
 * Simulink Coder version         : 8.12 (R2017a) 16-Feb-2017
 * C/C++ source code generated on : Mon Nov 06 14:44:49 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ControlSystem_h_
#define RTW_HEADER_ControlSystem_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include <stddef.h>
#ifndef ControlSystem_COMMON_INCLUDES_
# define ControlSystem_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* ControlSystem_COMMON_INCLUDES_ */

#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#define ControlSystem_M                (rtM)

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real_T CoffeeRecipe;                 /* '<S1>/Control System' */
  real_T MilkRecipe;                   /* '<S1>/Control System' */
  real_T SugarRecipe;                  /* '<S1>/Control System' */
  real_T WaterRecipe;                  /* '<S1>/Control System' */
  int32_T clockTickCounter;            /* '<S1>/Tick' */
  uint32_T GetCupEventEventCounter;    /* '<S1>/Control System' */
  uint32_T temporalCounter_i1;         /* '<S1>/Control System' */
  uint16_T temporalCounter_i2;         /* '<S1>/Control System' */
  uint8_T is_active_c12_ControlSystem; /* '<S1>/Control System' */
  uint8_T is_c12_ControlSystem;        /* '<S1>/Control System' */
  uint8_T is_WaterState;               /* '<S1>/Control System' */
  uint8_T is_SugarDoserState;          /* '<S1>/Control System' */
  uint8_T is_CoffeeDoserState;         /* '<S1>/Control System' */
  uint8_T is_MilkDoserState;           /* '<S1>/Control System' */
  boolean_T Memory2_PreviousInput[11]; /* '<S1>/Memory2' */
  boolean_T GetCupEvent;               /* '<S1>/Control System' */
  boolean_T Memory1_PreviousInput;     /* '<S1>/Memory1' */
} DW;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState ControlSystem_Trig_ZCE[11];/* '<S1>/Control System' */
} PrevZCX;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  boolean_T AmericanCoffee;            /* '<Root>/AmericanCoffee' */
  boolean_T CoffeeLatte;               /* '<Root>/CoffeeLatte' */
  boolean_T Cappuccino;                /* '<Root>/Cappuccino' */
  boolean_T TakeOutEvent;              /* '<Root>/TakeOutEvent' */
  boolean_T ClearIntegratorEvent;      /* '<Root>/CoffeeDoserEvent' */
  boolean_T ClearIntegratorEvent_n;    /* '<Root>/MilkDoserEvent' */
  boolean_T ClearIntegratorEvent_j;    /* '<Root>/SugarDoserEvent' */
  boolean_T FeedFinishEvent;           /* '<Root>/FeedFinishEvent' */
  boolean_T MixFinishEvent;            /* '<Root>/MixFinishEvent' */
  boolean_T StepEvent;                 /* '<Root>/StepEvent' */
  real_T CoffeeRemain;                 /* '<Root>/CoffeeRemain' */
  real_T MilkRemain;                   /* '<Root>/MilkRemain' */
  real_T SugarRemain;                  /* '<Root>/SugarRemain' */
  real_T WaterRemain;                  /* '<Root>/WaterRemain' */
  real_T WaterTemp;                    /* '<Root>/WaterTemp' */
  boolean_T CupRemain;                 /* '<Root>/CupRemain' */
} ExtU;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T CoffeeAmount;                 /* '<Root>/CoffeeAmount' */
  real_T MilkAmount;                   /* '<Root>/MilkAmount' */
  real_T SugarAmount;                  /* '<Root>/SugarAmount' */
  real_T WaterAmount;                  /* '<Root>/WaterAmount' */
  real_T NextStep;                     /* '<Root>/NextStep' */
  boolean_T GetCupEvent;               /* '<Root>/GetCupEvent' */
} ExtY;

/* Parameters (auto storage) */
struct P_ {
  real_T Tick_Amp;                     /* Expression: 1
                                        * Referenced by: '<S1>/Tick'
                                        */
  real_T Tick_Period;                  /* Computed Parameter: Tick_Period
                                        * Referenced by: '<S1>/Tick'
                                        */
  real_T Tick_Duty;                    /* Computed Parameter: Tick_Duty
                                        * Referenced by: '<S1>/Tick'
                                        */
  real_T Tick_PhaseDelay;              /* Expression: 0
                                        * Referenced by: '<S1>/Tick'
                                        */
  boolean_T Memory2_X0;                /* Computed Parameter: Memory2_X0
                                        * Referenced by: '<S1>/Memory2'
                                        */
  boolean_T Memory1_X0;                /* Computed Parameter: Memory1_X0
                                        * Referenced by: '<S1>/Memory1'
                                        */
};

/* Parameters (auto storage) */
typedef struct P_ P;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P rtP;

/* Block signals and states (auto storage) */
extern DW rtDW;

/* External inputs (root inport signals with auto storage) */
extern ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY rtY;

/* Model entry point functions */
extern void ControlSystem_initialize(void);
extern void ControlSystem_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

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
 * hilite_system('AllinOne/ControlSystem')    - opens subsystem AllinOne/ControlSystem
 * hilite_system('AllinOne/ControlSystem/Kp') - opens and selects block Kp
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'AllinOne'
 * '<S1>'   : 'AllinOne/ControlSystem'
 * '<S2>'   : 'AllinOne/ControlSystem/Control System'
 */
#endif                                 /* RTW_HEADER_ControlSystem_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
