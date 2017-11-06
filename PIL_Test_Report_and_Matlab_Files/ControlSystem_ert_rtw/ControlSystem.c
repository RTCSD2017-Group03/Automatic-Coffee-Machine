/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: ControlSystem.c
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

#include "ControlSystem.h"

/* Named constants for Chart: '<S1>/Control System' */
#define IN_BeltStep1                   ((uint8_T)1U)
#define IN_BeltStep2                   ((uint8_T)2U)
#define IN_Finished                    ((uint8_T)1U)
#define IN_GetCup                      ((uint8_T)3U)
#define IN_Init                        ((uint8_T)4U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_TakeOut                     ((uint8_T)5U)
#define IN_Working                     ((uint8_T)2U)
#define IN_error                       ((uint8_T)6U)
#define IN_prepare_AmerricanCoffee     ((uint8_T)7U)
#define IN_prepare_Cappuccino          ((uint8_T)8U)
#define IN_prepare_CoffeeLatte         ((uint8_T)9U)
#define IN_working_Coffee              ((uint8_T)10U)
#define event_AmericanCoffee           (1)
#define event_Cappuccino               (3)
#define event_CoffeeDoserEvent         (9)
#define event_CoffeeLatte              (2)
#define event_FeedFinishEvent          (5)
#define event_MilkDoserEvent           (8)
#define event_MixFinishEvent           (6)
#define event_StepEvent                (4)
#define event_SugarDoserEvent          (7)
#define event_TakeOutEvent             (10)
#define event_Tick                     (0)

/* Block signals and states (auto storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* External inputs (root inport signals with auto storage) */
ExtU rtU;

/* External outputs (root outports fed by signals with auto storage) */
ExtY rtY;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Forward declaration for local functions */
static void exit_internal_working_Coffee(void);
static boolean_T checkall(real_T waterRemain, real_T waterRecipe, real_T
  milkRemain, real_T milkRecipe, real_T sugarRemain, real_T sugarRecipe, real_T
  coffeeRemain, real_T coffeeRecipe, real_T cupRemain, real_T waterTemp);
static void chartstep_c12_ControlSystem(const int32_T *sfEvent);

/* Function for Chart: '<S1>/Control System' */
static void exit_internal_working_Coffee(void)
{
  /* Exit Internal 'working_Coffee': '<S2>:297' */
  /* Exit Internal 'MilkDoserState': '<S2>:666' */
  if (rtDW.is_MilkDoserState == IN_Working) {
    /* Outport: '<Root>/MilkAmount' */
    /* Exit 'Working': '<S2>:664' */
    rtY.MilkAmount = 0.0;
    rtDW.is_MilkDoserState = IN_NO_ACTIVE_CHILD;
  } else {
    rtDW.is_MilkDoserState = IN_NO_ACTIVE_CHILD;
  }

  /* Exit Internal 'CoffeeDoserState': '<S2>:649' */
  if (rtDW.is_CoffeeDoserState == IN_Working) {
    /* Outport: '<Root>/CoffeeAmount' */
    /* Exit 'Working': '<S2>:651' */
    rtY.CoffeeAmount = 0.0;
    rtDW.is_CoffeeDoserState = IN_NO_ACTIVE_CHILD;
  } else {
    rtDW.is_CoffeeDoserState = IN_NO_ACTIVE_CHILD;
  }

  /* Exit Internal 'SugarDoserState': '<S2>:657' */
  if (rtDW.is_SugarDoserState == IN_Working) {
    /* Outport: '<Root>/SugarAmount' */
    /* Exit 'Working': '<S2>:655' */
    rtY.SugarAmount = 0.0;
    rtDW.is_SugarDoserState = IN_NO_ACTIVE_CHILD;
  } else {
    rtDW.is_SugarDoserState = IN_NO_ACTIVE_CHILD;
  }

  /* Exit Internal 'WaterState': '<S2>:661' */
  if (rtDW.is_WaterState == IN_Working) {
    /* Outport: '<Root>/WaterAmount' */
    /* Exit 'Working': '<S2>:659' */
    rtY.WaterAmount = 0.0;
    rtDW.is_WaterState = IN_NO_ACTIVE_CHILD;
  } else {
    rtDW.is_WaterState = IN_NO_ACTIVE_CHILD;
  }
}

/* Function for Chart: '<S1>/Control System' */
static boolean_T checkall(real_T waterRemain, real_T waterRecipe, real_T
  milkRemain, real_T milkRecipe, real_T sugarRemain, real_T sugarRecipe, real_T
  coffeeRemain, real_T coffeeRecipe, real_T cupRemain, real_T waterTemp)
{
  boolean_T flg;

  /* Graphical Function 'checkall': '<S2>:192' */
  /* Transition: '<S2>:194' */
  if (waterRemain < waterRecipe) {
    /* Transition: '<S2>:195' */
    printf("water is not enough");

    /* Transition: '<S2>:197' */
    flg = false;
  } else {
    /* Transition: '<S2>:340' */
    if (milkRemain < milkRecipe) {
      /* Transition: '<S2>:309' */
      printf("milk is not enough");

      /* Transition: '<S2>:307' */
      flg = false;
    } else {
      /* Transition: '<S2>:342' */
      if (sugarRemain < sugarRecipe) {
        /* Transition: '<S2>:319' */
        printf("sugar is not enough");

        /* Transition: '<S2>:320' */
        flg = false;
      } else {
        /* Transition: '<S2>:343' */
        if (coffeeRemain < coffeeRecipe) {
          /* Transition: '<S2>:330' */
          printf("coffee is not enough");

          /* Transition: '<S2>:329' */
          flg = false;
        } else {
          /* Transition: '<S2>:354' */
          if (cupRemain <= 0.0) {
            /* Transition: '<S2>:356' */
            printf("cup is not enough");

            /* Transition: '<S2>:357' */
            flg = false;
          } else {
            /* Transition: '<S2>:407' */
            if (waterTemp <= 80.0) {
              /* Transition: '<S2>:410' */
              printf("water is not heat enough; \n");

              /* Transition: '<S2>:411' */
              flg = false;
            } else {
              /* Transition: '<S2>:408' */
              flg = true;
            }
          }
        }
      }
    }
  }

  return flg;
}

/* Function for Chart: '<S1>/Control System' */
static void chartstep_c12_ControlSystem(const int32_T *sfEvent)
{
  /* During: ControlSystem/Control System */
  if (rtDW.is_active_c12_ControlSystem == 0U) {
    /* Entry: ControlSystem/Control System */
    rtDW.is_active_c12_ControlSystem = 1U;

    /* Entry Internal: ControlSystem/Control System */
    /* Transition: '<S2>:31' */
    rtDW.is_c12_ControlSystem = IN_Init;

    /* Outport: '<Root>/CoffeeAmount' */
    /* Entry 'Init': '<S2>:30' */
    rtY.CoffeeAmount = 0.0;

    /* Outport: '<Root>/MilkAmount' */
    rtY.MilkAmount = 0.0;

    /* Outport: '<Root>/SugarAmount' */
    rtY.SugarAmount = 0.0;

    /* Outport: '<Root>/WaterAmount' */
    rtY.WaterAmount = 0.0;

    /* Outport: '<Root>/NextStep' */
    rtY.NextStep = 0.0;
  } else {
    switch (rtDW.is_c12_ControlSystem) {
     case IN_BeltStep1:
      /* During 'BeltStep1': '<S2>:417' */
      if (*sfEvent == event_StepEvent) {
        /* Outport: '<Root>/NextStep' */
        /* Transition: '<S2>:669' */
        /* Exit 'BeltStep1': '<S2>:417' */
        rtY.NextStep = 0.0;
        rtDW.is_c12_ControlSystem = IN_working_Coffee;
        rtDW.temporalCounter_i2 = 0U;

        /* Entry Internal 'working_Coffee': '<S2>:297' */
        /* Entry Internal 'WaterState': '<S2>:661' */
        /* Transition: '<S2>:660' */
        rtDW.is_WaterState = IN_Working;
        rtDW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/WaterAmount' */
        /* Entry 'Working': '<S2>:659' */
        rtY.WaterAmount = 1.0;

        /* Entry Internal 'SugarDoserState': '<S2>:657' */
        /* Transition: '<S2>:658' */
        rtDW.is_SugarDoserState = IN_Working;

        /* Outport: '<Root>/SugarAmount' */
        /* Entry 'Working': '<S2>:655' */
        rtY.SugarAmount = rtDW.SugarRecipe;

        /* Entry Internal 'CoffeeDoserState': '<S2>:649' */
        /* Transition: '<S2>:650' */
        rtDW.is_CoffeeDoserState = IN_Working;

        /* Outport: '<Root>/CoffeeAmount' */
        /* Entry 'Working': '<S2>:651' */
        rtY.CoffeeAmount = rtDW.CoffeeRecipe;

        /* Entry Internal 'MilkDoserState': '<S2>:666' */
        /* Transition: '<S2>:668' */
        rtDW.is_MilkDoserState = IN_Working;

        /* Outport: '<Root>/MilkAmount' */
        /* Entry 'Working': '<S2>:664' */
        rtY.MilkAmount = rtDW.MilkRecipe;
      } else {
        if ((*sfEvent == event_Tick) && (rtDW.temporalCounter_i1 >= 10000U)) {
          /* Outport: '<Root>/NextStep' */
          /* Transition: '<S2>:675' */
          /* Transition: '<S2>:682' */
          /* Exit 'BeltStep1': '<S2>:417' */
          rtY.NextStep = 0.0;
          rtDW.is_c12_ControlSystem = IN_error;
        }
      }
      break;

     case IN_BeltStep2:
      /* During 'BeltStep2': '<S2>:404' */
      if (*sfEvent == event_StepEvent) {
        /* Outport: '<Root>/NextStep' */
        /* Transition: '<S2>:421' */
        /* Exit 'BeltStep2': '<S2>:404' */
        rtY.NextStep = 0.0;
        rtDW.is_c12_ControlSystem = IN_TakeOut;

        /* Entry 'TakeOut': '<S2>:687' */
        printf("please take out the coffee; \n");
      } else {
        if ((*sfEvent == event_Tick) && (rtDW.temporalCounter_i1 >= 10000U)) {
          /* Outport: '<Root>/NextStep' */
          /* Transition: '<S2>:680' */
          /* Transition: '<S2>:682' */
          /* Exit 'BeltStep2': '<S2>:404' */
          rtY.NextStep = 0.0;
          rtDW.is_c12_ControlSystem = IN_error;
        }
      }
      break;

     case IN_GetCup:
      /* During 'GetCup': '<S2>:414' */
      if (*sfEvent == event_FeedFinishEvent) {
        /* Transition: '<S2>:418' */
        /* Exit 'GetCup': '<S2>:414' */
        /* Event: '<S2>:13' */
        rtDW.GetCupEventEventCounter++;
        rtDW.is_c12_ControlSystem = IN_BeltStep1;
        rtDW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/NextStep' */
        /* Entry 'BeltStep1': '<S2>:417' */
        rtY.NextStep = 50.0;
      } else {
        if ((*sfEvent == event_Tick) && (rtDW.temporalCounter_i1 >= 10000U)) {
          /* Transition: '<S2>:677' */
          /* Transition: '<S2>:682' */
          /* Exit 'GetCup': '<S2>:414' */
          /* Event: '<S2>:13' */
          rtDW.GetCupEventEventCounter++;
          rtDW.is_c12_ControlSystem = IN_error;
        }
      }
      break;

     case IN_Init:
      /* During 'Init': '<S2>:30' */
      if (*sfEvent == event_AmericanCoffee) {
        /* Transition: '<S2>:124' */
        rtDW.is_c12_ControlSystem = IN_prepare_CoffeeLatte;

        /* Entry 'prepare_CoffeeLatte': '<S2>:119' */
        rtDW.CoffeeRecipe = 25.0;
        rtDW.MilkRecipe = 15.0;
        rtDW.SugarRecipe = 10.0;
        rtDW.WaterRecipe = 50.0;
      } else if (*sfEvent == event_CoffeeLatte) {
        /* Transition: '<S2>:424' */
        rtDW.is_c12_ControlSystem = IN_prepare_Cappuccino;

        /* Entry 'prepare_Cappuccino': '<S2>:422' */
        rtDW.CoffeeRecipe = 25.0;
        rtDW.MilkRecipe = 20.0;
        rtDW.SugarRecipe = 5.0;
        rtDW.WaterRecipe = 50.0;
      } else {
        if (*sfEvent == event_Cappuccino) {
          /* Transition: '<S2>:425' */
          rtDW.is_c12_ControlSystem = IN_prepare_AmerricanCoffee;

          /* Entry 'prepare_AmerricanCoffee': '<S2>:423' */
          rtDW.CoffeeRecipe = 35.0;
          rtDW.MilkRecipe = 10.0;
          rtDW.SugarRecipe = 5.0;
          rtDW.WaterRecipe = 50.0;
        }
      }
      break;

     case IN_TakeOut:
      /* During 'TakeOut': '<S2>:687' */
      if (*sfEvent == event_TakeOutEvent) {
        /* Transition: '<S2>:688' */
        rtDW.is_c12_ControlSystem = IN_Init;

        /* Outport: '<Root>/CoffeeAmount' */
        /* Entry 'Init': '<S2>:30' */
        rtY.CoffeeAmount = 0.0;

        /* Outport: '<Root>/MilkAmount' */
        rtY.MilkAmount = 0.0;

        /* Outport: '<Root>/SugarAmount' */
        rtY.SugarAmount = 0.0;

        /* Outport: '<Root>/WaterAmount' */
        rtY.WaterAmount = 0.0;

        /* Outport: '<Root>/NextStep' */
        rtY.NextStep = 0.0;
      }
      break;

     case IN_error:
      /* During 'error': '<S2>:681' */
      break;

     case IN_prepare_AmerricanCoffee:
      /* Inport: '<Root>/WaterRemain' incorporates:
       *  Inport: '<Root>/CoffeeRemain'
       *  Inport: '<Root>/CupRemain'
       *  Inport: '<Root>/MilkRemain'
       *  Inport: '<Root>/SugarRemain'
       *  Inport: '<Root>/WaterTemp'
       */
      /* During 'prepare_AmerricanCoffee': '<S2>:423' */
      if (checkall(rtU.WaterRemain, rtDW.WaterRecipe, rtU.MilkRemain,
                   rtDW.MilkRecipe, rtU.SugarRemain, rtDW.SugarRecipe,
                   rtU.CoffeeRemain, rtDW.CoffeeRecipe, (real_T)rtU.CupRemain,
                   rtU.WaterTemp)) {
        /* Transition: '<S2>:427' */
        rtDW.is_c12_ControlSystem = IN_GetCup;
        rtDW.temporalCounter_i1 = 0U;

        /* Entry 'GetCup': '<S2>:414' */
        printf("Coffee has started to be made; \n");
        printf("please wait a minute; \n");

        /* Event: '<S2>:13' */
        rtDW.GetCupEventEventCounter++;
      } else {
        /* Transition: '<S2>:428' */
        rtDW.is_c12_ControlSystem = IN_Init;

        /* Outport: '<Root>/CoffeeAmount' */
        /* Entry 'Init': '<S2>:30' */
        rtY.CoffeeAmount = 0.0;

        /* Outport: '<Root>/MilkAmount' */
        rtY.MilkAmount = 0.0;

        /* Outport: '<Root>/SugarAmount' */
        rtY.SugarAmount = 0.0;

        /* Outport: '<Root>/WaterAmount' */
        rtY.WaterAmount = 0.0;

        /* Outport: '<Root>/NextStep' */
        rtY.NextStep = 0.0;
      }
      break;

     case IN_prepare_Cappuccino:
      /* Inport: '<Root>/WaterRemain' incorporates:
       *  Inport: '<Root>/CoffeeRemain'
       *  Inport: '<Root>/CupRemain'
       *  Inport: '<Root>/MilkRemain'
       *  Inport: '<Root>/SugarRemain'
       *  Inport: '<Root>/WaterTemp'
       */
      /* During 'prepare_Cappuccino': '<S2>:422' */
      if (checkall(rtU.WaterRemain, rtDW.WaterRecipe, rtU.MilkRemain,
                   rtDW.MilkRecipe, rtU.SugarRemain, rtDW.SugarRecipe,
                   rtU.CoffeeRemain, rtDW.CoffeeRecipe, (real_T)rtU.CupRemain,
                   rtU.WaterTemp)) {
        /* Transition: '<S2>:426' */
        rtDW.is_c12_ControlSystem = IN_GetCup;
        rtDW.temporalCounter_i1 = 0U;

        /* Entry 'GetCup': '<S2>:414' */
        printf("Coffee has started to be made; \n");
        printf("please wait a minute; \n");

        /* Event: '<S2>:13' */
        rtDW.GetCupEventEventCounter++;
      } else {
        /* Transition: '<S2>:429' */
        rtDW.is_c12_ControlSystem = IN_Init;

        /* Outport: '<Root>/CoffeeAmount' */
        /* Entry 'Init': '<S2>:30' */
        rtY.CoffeeAmount = 0.0;

        /* Outport: '<Root>/MilkAmount' */
        rtY.MilkAmount = 0.0;

        /* Outport: '<Root>/SugarAmount' */
        rtY.SugarAmount = 0.0;

        /* Outport: '<Root>/WaterAmount' */
        rtY.WaterAmount = 0.0;

        /* Outport: '<Root>/NextStep' */
        rtY.NextStep = 0.0;
      }
      break;

     case IN_prepare_CoffeeLatte:
      /* Inport: '<Root>/WaterRemain' incorporates:
       *  Inport: '<Root>/CoffeeRemain'
       *  Inport: '<Root>/CupRemain'
       *  Inport: '<Root>/MilkRemain'
       *  Inport: '<Root>/SugarRemain'
       *  Inport: '<Root>/WaterTemp'
       */
      /* During 'prepare_CoffeeLatte': '<S2>:119' */
      if (checkall(rtU.WaterRemain, rtDW.WaterRecipe, rtU.MilkRemain,
                   rtDW.MilkRecipe, rtU.SugarRemain, rtDW.SugarRecipe,
                   rtU.CoffeeRemain, rtDW.CoffeeRecipe, (real_T)rtU.CupRemain,
                   rtU.WaterTemp)) {
        /* Transition: '<S2>:298' */
        rtDW.is_c12_ControlSystem = IN_GetCup;
        rtDW.temporalCounter_i1 = 0U;

        /* Entry 'GetCup': '<S2>:414' */
        printf("Coffee has started to be made; \n");
        printf("please wait a minute; \n");

        /* Event: '<S2>:13' */
        rtDW.GetCupEventEventCounter++;
      } else {
        /* Transition: '<S2>:360' */
        rtDW.is_c12_ControlSystem = IN_Init;

        /* Outport: '<Root>/CoffeeAmount' */
        /* Entry 'Init': '<S2>:30' */
        rtY.CoffeeAmount = 0.0;

        /* Outport: '<Root>/MilkAmount' */
        rtY.MilkAmount = 0.0;

        /* Outport: '<Root>/SugarAmount' */
        rtY.SugarAmount = 0.0;

        /* Outport: '<Root>/WaterAmount' */
        rtY.WaterAmount = 0.0;

        /* Outport: '<Root>/NextStep' */
        rtY.NextStep = 0.0;
      }
      break;

     default:
      /* During 'working_Coffee': '<S2>:297' */
      if (*sfEvent == event_MixFinishEvent) {
        /* Transition: '<S2>:405' */
        exit_internal_working_Coffee();
        rtDW.is_c12_ControlSystem = IN_BeltStep2;
        rtDW.temporalCounter_i1 = 0U;

        /* Outport: '<Root>/NextStep' */
        /* Entry 'BeltStep2': '<S2>:404' */
        rtY.NextStep = 50.0;
      } else if ((*sfEvent == event_Tick) && (rtDW.temporalCounter_i2 >= 10000))
      {
        /* Transition: '<S2>:679' */
        /* Transition: '<S2>:682' */
        exit_internal_working_Coffee();
        rtDW.is_c12_ControlSystem = IN_error;
      } else {
        /* During 'WaterState': '<S2>:661' */
        if ((rtDW.is_WaterState != IN_Finished) && ((*sfEvent == event_Tick) &&
             (rtDW.temporalCounter_i1 >= (uint32_T)(rtDW.WaterRecipe * 100.0))))
        {
          /* Outport: '<Root>/WaterAmount' */
          /* During 'Working': '<S2>:659' */
          /* Transition: '<S2>:662' */
          /* Exit 'Working': '<S2>:659' */
          rtY.WaterAmount = 0.0;
          rtDW.is_WaterState = IN_Finished;
        } else {
          /* During 'Finished': '<S2>:663' */
        }

        /* During 'SugarDoserState': '<S2>:657' */
        if ((rtDW.is_SugarDoserState != IN_Finished) && (*sfEvent ==
             event_SugarDoserEvent)) {
          /* Outport: '<Root>/SugarAmount' */
          /* During 'Working': '<S2>:655' */
          /* Transition: '<S2>:656' */
          /* Exit 'Working': '<S2>:655' */
          rtY.SugarAmount = 0.0;
          rtDW.is_SugarDoserState = IN_Finished;
        } else {
          /* During 'Finished': '<S2>:654' */
        }

        /* During 'CoffeeDoserState': '<S2>:649' */
        if ((rtDW.is_CoffeeDoserState != IN_Finished) && (*sfEvent ==
             event_CoffeeDoserEvent)) {
          /* Outport: '<Root>/CoffeeAmount' */
          /* During 'Working': '<S2>:651' */
          /* Transition: '<S2>:652' */
          /* Exit 'Working': '<S2>:651' */
          rtY.CoffeeAmount = 0.0;
          rtDW.is_CoffeeDoserState = IN_Finished;
        } else {
          /* During 'Finished': '<S2>:653' */
        }

        /* During 'MilkDoserState': '<S2>:666' */
        if ((rtDW.is_MilkDoserState != IN_Finished) && (*sfEvent ==
             event_MilkDoserEvent)) {
          /* Outport: '<Root>/MilkAmount' */
          /* During 'Working': '<S2>:664' */
          /* Transition: '<S2>:667' */
          /* Exit 'Working': '<S2>:664' */
          rtY.MilkAmount = 0.0;
          rtDW.is_MilkDoserState = IN_Finished;
        } else {
          /* During 'Finished': '<S2>:665' */
        }
      }
      break;
    }
  }
}

/* Model step function */
void ControlSystem_step(void)
{
  boolean_T rtb_Memory2[11];
  boolean_T rtb_Memory1;
  boolean_T zcEvent[11];
  int8_T rtb_inputevents[11];
  real_T rtb_Tick;
  int32_T sfEvent;
  int32_T i;
  boolean_T tmp;
  boolean_T zcEvent_0;

  /* Memory: '<S1>/Memory1' */
  rtb_Memory1 = rtDW.Memory1_PreviousInput;

  /* Chart: '<S1>/Control System' incorporates:
   *  TriggerPort: '<S2>/ input events '
   */
  tmp = false;
  for (i = 0; i < 11; i++) {
    /* Memory: '<S1>/Memory2' */
    rtb_Memory2[i] = rtDW.Memory2_PreviousInput[i];
    zcEvent_0 = (rtDW.Memory2_PreviousInput[i] &&
                 (rtPrevZCX.ControlSystem_Trig_ZCE[i] != POS_ZCSIG));
    tmp = (tmp || zcEvent_0);
    zcEvent[i] = zcEvent_0;
  }

  if (tmp) {
    for (i = 0; i < 11; i++) {
      rtb_inputevents[i] = (int8_T)zcEvent[i];
    }

    /* Gateway: ControlSystem/Control System */
    i = 0;
    if (rtb_inputevents[0U] == 1) {
      i = 1;
      if (rtDW.temporalCounter_i1 < MAX_uint32_T) {
        rtDW.temporalCounter_i1++;
      }

      if (rtDW.temporalCounter_i2 < 16383U) {
        rtDW.temporalCounter_i2++;
      }

      /* Event: '<S2>:26' */
      sfEvent = event_Tick;
      chartstep_c12_ControlSystem(&sfEvent);
    }

    if (rtb_inputevents[1U] == 1) {
      i = 1;

      /* Event: '<S2>:27' */
      sfEvent = event_AmericanCoffee;
      chartstep_c12_ControlSystem(&sfEvent);
    }

    if (rtb_inputevents[2U] == 1) {
      i = 1;

      /* Event: '<S2>:28' */
      sfEvent = event_CoffeeLatte;
      chartstep_c12_ControlSystem(&sfEvent);
    }

    if (rtb_inputevents[3U] == 1) {
      i = 1;

      /* Event: '<S2>:29' */
      sfEvent = event_Cappuccino;
      chartstep_c12_ControlSystem(&sfEvent);
    }

    if (rtb_inputevents[4U] == 1) {
      i = 1;

      /* Event: '<S2>:6' */
      sfEvent = event_StepEvent;
      chartstep_c12_ControlSystem(&sfEvent);
    }

    if (rtb_inputevents[5U] == 1) {
      i = 1;

      /* Event: '<S2>:5' */
      sfEvent = event_FeedFinishEvent;
      chartstep_c12_ControlSystem(&sfEvent);
    }

    if (rtb_inputevents[6U] == 1) {
      i = 1;

      /* Event: '<S2>:22' */
      sfEvent = event_MixFinishEvent;
      chartstep_c12_ControlSystem(&sfEvent);
    }

    if (rtb_inputevents[7U] == 1) {
      i = 1;

      /* Event: '<S2>:12' */
      sfEvent = event_SugarDoserEvent;
      chartstep_c12_ControlSystem(&sfEvent);
    }

    if (rtb_inputevents[8U] == 1) {
      i = 1;

      /* Event: '<S2>:10' */
      sfEvent = event_MilkDoserEvent;
      chartstep_c12_ControlSystem(&sfEvent);
    }

    if (rtb_inputevents[9U] == 1) {
      i = 1;

      /* Event: '<S2>:9' */
      sfEvent = event_CoffeeDoserEvent;
      chartstep_c12_ControlSystem(&sfEvent);
    }

    if (rtb_inputevents[10U] == 1) {
      i = 1;

      /* Event: '<S2>:686' */
      sfEvent = event_TakeOutEvent;
      chartstep_c12_ControlSystem(&sfEvent);
    }

    if ((i != 0) && (rtDW.GetCupEventEventCounter > 0U)) {
      rtDW.GetCupEvent = !rtDW.GetCupEvent;
      rtDW.GetCupEventEventCounter--;
    }
  }

  for (i = 0; i < 11; i++) {
    rtPrevZCX.ControlSystem_Trig_ZCE[i] = rtb_Memory2[i];
  }

  /* Outport: '<Root>/GetCupEvent' */
  rtY.GetCupEvent = rtb_Memory1;

  /* DiscretePulseGenerator: '<S1>/Tick' */
  rtb_Tick = (rtDW.clockTickCounter < rtP.Tick_Duty) && (rtDW.clockTickCounter >=
    0) ? rtP.Tick_Amp : 0.0;
  if (rtDW.clockTickCounter >= rtP.Tick_Period - 1.0) {
    rtDW.clockTickCounter = 0;
  } else {
    rtDW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S1>/Tick' */

  /* Update for Memory: '<S1>/Memory2' incorporates:
   *  DataTypeConversion: '<S1>/Data Type Conversion'
   *  Update for Inport: '<Root>/AmericanCoffee'
   *  Update for Inport: '<Root>/Cappuccino'
   *  Update for Inport: '<Root>/CoffeeDoserEvent'
   *  Update for Inport: '<Root>/CoffeeLatte'
   *  Update for Inport: '<Root>/FeedFinishEvent'
   *  Update for Inport: '<Root>/MilkDoserEvent'
   *  Update for Inport: '<Root>/MixFinishEvent'
   *  Update for Inport: '<Root>/StepEvent'
   *  Update for Inport: '<Root>/SugarDoserEvent'
   *  Update for Inport: '<Root>/TakeOutEvent'
   */
  rtDW.Memory2_PreviousInput[0] = (rtb_Tick != 0.0);
  rtDW.Memory2_PreviousInput[1] = rtU.AmericanCoffee;
  rtDW.Memory2_PreviousInput[2] = rtU.CoffeeLatte;
  rtDW.Memory2_PreviousInput[3] = rtU.Cappuccino;
  rtDW.Memory2_PreviousInput[4] = rtU.StepEvent;
  rtDW.Memory2_PreviousInput[5] = rtU.FeedFinishEvent;
  rtDW.Memory2_PreviousInput[6] = rtU.MixFinishEvent;
  rtDW.Memory2_PreviousInput[7] = rtU.ClearIntegratorEvent_j;
  rtDW.Memory2_PreviousInput[8] = rtU.ClearIntegratorEvent_n;
  rtDW.Memory2_PreviousInput[9] = rtU.ClearIntegratorEvent;
  rtDW.Memory2_PreviousInput[10] = rtU.TakeOutEvent;

  /* Update for Memory: '<S1>/Memory1' */
  rtDW.Memory1_PreviousInput = rtDW.GetCupEvent;
}

/* Model initialize function */
void ControlSystem_initialize(void)
{
  {
    int32_T i;

    /* InitializeConditions for Memory: '<S1>/Memory2' */
    for (i = 0; i < 11; i++) {
      rtPrevZCX.ControlSystem_Trig_ZCE[i] = POS_ZCSIG;
      rtDW.Memory2_PreviousInput[i] = rtP.Memory2_X0;
    }

    /* End of InitializeConditions for Memory: '<S1>/Memory2' */

    /* InitializeConditions for Memory: '<S1>/Memory1' */
    rtDW.Memory1_PreviousInput = rtP.Memory1_X0;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
