/*
 * Control.c
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
#include "Control.h"
#include "Control_private.h"

/* Named constants for Chart: '<Root>/Control System' */
#define Cont_IN_working_AmerricanCoffee ((uint8_T)8U)
#define Control_IN_Finished            ((uint8_T)1U)
#define Control_IN_GetCup              ((uint8_T)1U)
#define Control_IN_Init                ((uint8_T)2U)
#define Control_IN_NO_ACTIVE_CHILD     ((uint8_T)0U)
#define Control_IN_Step1               ((uint8_T)3U)
#define Control_IN_Step2               ((uint8_T)4U)
#define Control_IN_TakeOut             ((uint8_T)5U)
#define Control_IN_Working             ((uint8_T)2U)
#define Control_IN_error               ((uint8_T)6U)
#define Control_IN_prepare_CoffeeLatte ((uint8_T)7U)
#define Control_IN_working_Cappuccino  ((uint8_T)9U)
#define Control_IN_working_Coffee      ((uint8_T)10U)
#define Control_event_AmericanCoffee   (1)
#define Control_event_Cappuccino       (3)
#define Control_event_CoffeeDoserEvent (9)
#define Control_event_CoffeeLatte      (2)
#define Control_event_FeedFinishEvent  (5)
#define Control_event_MilkDoserEvent   (8)
#define Control_event_MixFinishEvent   (6)
#define Control_event_StepEvent        (4)
#define Control_event_SugarDoserEvent  (7)
#define Control_event_TakeOutEvent     (11)
#define Control_event_Tick             (0)

/* Block states (auto storage) */
DW_Control_T Control_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_Control_T Control_PrevZCX;

/* External inputs (root inport signals with auto storage) */
ExtU_Control_T Control_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_Control_T Control_Y;

/* Real-time model */
RT_MODEL_Control_T Control_M_;
RT_MODEL_Control_T *const Control_M = &Control_M_;

/* Forward declaration for local functions */
static void Co_exit_internal_working_Coffee(void);
static boolean_T Control_checkall(real_T waterRemain, real_T waterRecipe, real_T
  milkRemain, real_T milkRecipe, real_T sugarRemain, real_T sugarRecipe, real_T
  coffeeRemain, real_T coffeeRecipe, real_T cupRemain, real_T waterTemp);
static void Control_chartstep_c12_Control(void);

/* Function for Chart: '<Root>/Control System' */
static void Co_exit_internal_working_Coffee(void)
{
  /* Exit Internal 'working_Coffee': '<S1>:297' */
  /* Exit Internal 'MilkDoserState': '<S1>:666' */
  if (Control_DW.is_MilkDoserState == Control_IN_Working) {
    /* Exit 'Working': '<S1>:664' */
    Control_Y.MilkAmount = 0.0;
    Control_DW.is_MilkDoserState = Control_IN_NO_ACTIVE_CHILD;
  } else {
    Control_DW.is_MilkDoserState = Control_IN_NO_ACTIVE_CHILD;
  }

  Control_DW.is_active_MilkDoserState = 0U;

  /* Exit Internal 'CoffeeDoserState': '<S1>:649' */
  if (Control_DW.is_CoffeeDoserState == Control_IN_Working) {
    /* Exit 'Working': '<S1>:651' */
    Control_Y.CoffeeAmount = 0.0;
    Control_DW.is_CoffeeDoserState = Control_IN_NO_ACTIVE_CHILD;
  } else {
    Control_DW.is_CoffeeDoserState = Control_IN_NO_ACTIVE_CHILD;
  }

  Control_DW.is_active_CoffeeDoserState = 0U;

  /* Exit Internal 'SugarDoserState': '<S1>:657' */
  if (Control_DW.is_SugarDoserState == Control_IN_Working) {
    /* Exit 'Working': '<S1>:655' */
    Control_Y.SugarAmount = 0.0;
    Control_DW.is_SugarDoserState = Control_IN_NO_ACTIVE_CHILD;
  } else {
    Control_DW.is_SugarDoserState = Control_IN_NO_ACTIVE_CHILD;
  }

  Control_DW.is_active_SugarDoserState = 0U;

  /* Exit Internal 'WaterState': '<S1>:661' */
  if (Control_DW.is_WaterState == Control_IN_Working) {
    /* Exit 'Working': '<S1>:659' */
    Control_Y.WaterAmount = 0.0;
    Control_DW.is_WaterState = Control_IN_NO_ACTIVE_CHILD;
  } else {
    Control_DW.is_WaterState = Control_IN_NO_ACTIVE_CHILD;
  }

  Control_DW.is_active_WaterState = 0U;
}

/* Function for Chart: '<Root>/Control System' */
static boolean_T Control_checkall(real_T waterRemain, real_T waterRecipe, real_T
  milkRemain, real_T milkRecipe, real_T sugarRemain, real_T sugarRecipe, real_T
  coffeeRemain, real_T coffeeRecipe, real_T cupRemain, real_T waterTemp)
{
  boolean_T flg;

  /* Graphical Function 'checkall': '<S1>:192' */
  /* Transition: '<S1>:194' */
  if (waterRemain < waterRecipe) {
    /* Transition: '<S1>:195' */
    /* Transition: '<S1>:197' */
    flg = false;
  } else {
    /* Transition: '<S1>:340' */
    if (milkRemain < milkRecipe) {
      /* Transition: '<S1>:309' */
      /* Transition: '<S1>:307' */
      flg = false;
    } else {
      /* Transition: '<S1>:342' */
      if (sugarRemain < sugarRecipe) {
        /* Transition: '<S1>:319' */
        /* Transition: '<S1>:320' */
        flg = false;
      } else {
        /* Transition: '<S1>:343' */
        if (coffeeRemain < coffeeRecipe) {
          /* Transition: '<S1>:330' */
          /* Transition: '<S1>:329' */
          flg = false;
        } else {
          /* Transition: '<S1>:354' */
          if (cupRemain <= 0.0) {
            /* Transition: '<S1>:356' */
            /* Transition: '<S1>:357' */
            flg = false;
          } else {
            /* Transition: '<S1>:407' */
            if (waterTemp <= 80.0) {
              /* Transition: '<S1>:410' */
              /* Transition: '<S1>:411' */
              flg = false;
            } else {
              /* Transition: '<S1>:408' */
              flg = true;
            }
          }
        }
      }
    }
  }

  return flg;
}

/* Function for Chart: '<Root>/Control System' */
static void Control_chartstep_c12_Control(void)
{
  /* During: Control System */
  if (Control_DW.is_active_c12_Control == 0U) {
    /* Entry: Control System */
    Control_DW.is_active_c12_Control = 1U;

    /* Entry Internal: Control System */
    /* Transition: '<S1>:31' */
    Control_DW.is_c12_Control = Control_IN_Init;

    /* Entry 'Init': '<S1>:30' */
    Control_Y.CoffeeAmount = 0.0;
    Control_Y.MilkAmount = 0.0;
    Control_Y.SugarAmount = 0.0;
    Control_Y.WaterAmount = 0.0;
    Control_Y.NextStep = 0.0;
  } else {
    switch (Control_DW.is_c12_Control) {
     case Control_IN_GetCup:
      /* During 'GetCup': '<S1>:414' */
      if (Control_DW.sfEvent == Control_event_FeedFinishEvent) {
        /* Transition: '<S1>:418' */
        /* Exit 'GetCup': '<S1>:414' */
        /* Event: '<S1>:13' */
        Control_DW.GetCupEventEventCounter++;
        Control_DW.is_c12_Control = Control_IN_Step1;
        Control_DW.temporalCounter_i1 = 0U;

        /* Entry 'Step1': '<S1>:417' */
        Control_Y.NextStep = 50.0;
      } else {
        if ((Control_DW.sfEvent == Control_event_Tick) &&
            (Control_DW.temporalCounter_i1 >= 10000U)) {
          /* Transition: '<S1>:677' */
          /* Transition: '<S1>:682' */
          /* Exit 'GetCup': '<S1>:414' */
          /* Event: '<S1>:13' */
          Control_DW.GetCupEventEventCounter++;
          Control_DW.is_c12_Control = Control_IN_error;
        }
      }
      break;

     case Control_IN_Init:
      /* During 'Init': '<S1>:30' */
      if (Control_DW.sfEvent == Control_event_AmericanCoffee) {
        /* Transition: '<S1>:124' */
        Control_DW.is_c12_Control = Control_IN_prepare_CoffeeLatte;

        /* Entry 'prepare_CoffeeLatte': '<S1>:119' */
        Control_DW.CoffeeRecipe = 10.0;
        Control_DW.MilkRecipe = 80.0;
        Control_DW.SugarRecipe = 10.0;
        Control_DW.WaterRecipe = 40.0;
      } else if (Control_DW.sfEvent == Control_event_CoffeeLatte) {
        /* Transition: '<S1>:424' */
        Control_DW.is_c12_Control = Control_IN_working_Cappuccino;

        /* Entry 'working_Cappuccino': '<S1>:422' */
        Control_DW.CoffeeRecipe = 10.0;
        Control_DW.MilkRecipe = 100.0;
        Control_DW.SugarRecipe = 10.0;
        Control_DW.WaterRecipe = 20.0;
      } else {
        if (Control_DW.sfEvent == Control_event_Cappuccino) {
          /* Transition: '<S1>:425' */
          Control_DW.is_c12_Control = Cont_IN_working_AmerricanCoffee;

          /* Entry 'working_AmerricanCoffee': '<S1>:423' */
          Control_DW.CoffeeRecipe = 10.0;
          Control_DW.MilkRecipe = 60.0;
          Control_DW.SugarRecipe = 10.0;
          Control_DW.WaterRecipe = 60.0;
        }
      }
      break;

     case Control_IN_Step1:
      /* During 'Step1': '<S1>:417' */
      if (Control_DW.sfEvent == Control_event_StepEvent) {
        /* Transition: '<S1>:669' */
        /* Exit 'Step1': '<S1>:417' */
        Control_Y.NextStep = 0.0;
        Control_DW.is_c12_Control = Control_IN_working_Coffee;
        Control_DW.temporalCounter_i2 = 0U;

        /* Entry Internal 'working_Coffee': '<S1>:297' */
        Control_DW.is_active_WaterState = 1U;

        /* Entry Internal 'WaterState': '<S1>:661' */
        /* Transition: '<S1>:660' */
        Control_DW.is_WaterState = Control_IN_Working;
        Control_DW.temporalCounter_i1 = 0U;

        /* Entry 'Working': '<S1>:659' */
        Control_Y.WaterAmount = 1.0;
        Control_DW.is_active_SugarDoserState = 1U;

        /* Entry Internal 'SugarDoserState': '<S1>:657' */
        /* Transition: '<S1>:658' */
        Control_DW.is_SugarDoserState = Control_IN_Working;

        /* Entry 'Working': '<S1>:655' */
        Control_Y.SugarAmount = Control_DW.SugarRecipe;
        Control_DW.is_active_CoffeeDoserState = 1U;

        /* Entry Internal 'CoffeeDoserState': '<S1>:649' */
        /* Transition: '<S1>:650' */
        Control_DW.is_CoffeeDoserState = Control_IN_Working;

        /* Entry 'Working': '<S1>:651' */
        Control_Y.CoffeeAmount = Control_DW.CoffeeRecipe;
        Control_DW.is_active_MilkDoserState = 1U;

        /* Entry Internal 'MilkDoserState': '<S1>:666' */
        /* Transition: '<S1>:668' */
        Control_DW.is_MilkDoserState = Control_IN_Working;

        /* Entry 'Working': '<S1>:664' */
        Control_Y.MilkAmount = Control_DW.MilkRecipe;
      } else {
        if ((Control_DW.sfEvent == Control_event_Tick) &&
            (Control_DW.temporalCounter_i1 >= 10000U)) {
          /* Transition: '<S1>:675' */
          /* Transition: '<S1>:682' */
          /* Exit 'Step1': '<S1>:417' */
          Control_Y.NextStep = 0.0;
          Control_DW.is_c12_Control = Control_IN_error;
        }
      }
      break;

     case Control_IN_Step2:
      /* During 'Step2': '<S1>:404' */
      if (Control_DW.sfEvent == Control_event_StepEvent) {
        /* Transition: '<S1>:421' */
        /* Exit 'Step2': '<S1>:404' */
        Control_Y.NextStep = 0.0;
        Control_DW.is_c12_Control = Control_IN_TakeOut;
      } else {
        if ((Control_DW.sfEvent == Control_event_Tick) &&
            (Control_DW.temporalCounter_i1 >= 10000U)) {
          /* Transition: '<S1>:680' */
          /* Transition: '<S1>:682' */
          /* Exit 'Step2': '<S1>:404' */
          Control_Y.NextStep = 0.0;
          Control_DW.is_c12_Control = Control_IN_error;
        }
      }
      break;

     case Control_IN_TakeOut:
      /* During 'TakeOut': '<S1>:687' */
      if (Control_DW.sfEvent == Control_event_TakeOutEvent) {
        /* Transition: '<S1>:688' */
        Control_DW.is_c12_Control = Control_IN_Init;

        /* Entry 'Init': '<S1>:30' */
        Control_Y.CoffeeAmount = 0.0;
        Control_Y.MilkAmount = 0.0;
        Control_Y.SugarAmount = 0.0;
        Control_Y.WaterAmount = 0.0;
        Control_Y.NextStep = 0.0;
      }
      break;

     case Control_IN_error:
      /* During 'error': '<S1>:681' */
      break;

     case Control_IN_prepare_CoffeeLatte:
      /* Inport: '<Root>/WaterRemain' incorporates:
       *  Inport: '<Root>/CoffeeRemain'
       *  Inport: '<Root>/CupRemain'
       *  Inport: '<Root>/MilkRemain'
       *  Inport: '<Root>/SugarRemain'
       *  Inport: '<Root>/WaterTemp'
       */
      /* During 'prepare_CoffeeLatte': '<S1>:119' */
      if (Control_checkall(Control_U.WaterRemain, Control_DW.WaterRecipe,
                           Control_U.MilkRemain, Control_DW.MilkRecipe,
                           Control_U.SugarRemain, Control_DW.SugarRecipe,
                           Control_U.CoffeeRemain, Control_DW.CoffeeRecipe,
                           (real_T)Control_U.CupRemain, Control_U.WaterTemp)) {
        /* Transition: '<S1>:298' */
        Control_DW.is_c12_Control = Control_IN_GetCup;
        Control_DW.temporalCounter_i1 = 0U;

        /* Entry 'GetCup': '<S1>:414' */
        /* Event: '<S1>:13' */
        Control_DW.GetCupEventEventCounter++;
      } else {
        /* Transition: '<S1>:360' */
        Control_DW.is_c12_Control = Control_IN_Init;

        /* Entry 'Init': '<S1>:30' */
        Control_Y.CoffeeAmount = 0.0;
        Control_Y.MilkAmount = 0.0;
        Control_Y.SugarAmount = 0.0;
        Control_Y.WaterAmount = 0.0;
        Control_Y.NextStep = 0.0;
      }
      break;

     case Cont_IN_working_AmerricanCoffee:
      /* Inport: '<Root>/WaterRemain' incorporates:
       *  Inport: '<Root>/CoffeeRemain'
       *  Inport: '<Root>/CupRemain'
       *  Inport: '<Root>/MilkRemain'
       *  Inport: '<Root>/SugarRemain'
       *  Inport: '<Root>/WaterTemp'
       */
      /* During 'working_AmerricanCoffee': '<S1>:423' */
      if (Control_checkall(Control_U.WaterRemain, Control_DW.WaterRecipe,
                           Control_U.MilkRemain, Control_DW.MilkRecipe,
                           Control_U.SugarRemain, Control_DW.SugarRecipe,
                           Control_U.CoffeeRemain, Control_DW.CoffeeRecipe,
                           (real_T)Control_U.CupRemain, Control_U.WaterTemp)) {
        /* Transition: '<S1>:427' */
        Control_DW.is_c12_Control = Control_IN_GetCup;
        Control_DW.temporalCounter_i1 = 0U;

        /* Entry 'GetCup': '<S1>:414' */
        /* Event: '<S1>:13' */
        Control_DW.GetCupEventEventCounter++;
      } else {
        /* Transition: '<S1>:428' */
        Control_DW.is_c12_Control = Control_IN_Init;

        /* Entry 'Init': '<S1>:30' */
        Control_Y.CoffeeAmount = 0.0;
        Control_Y.MilkAmount = 0.0;
        Control_Y.SugarAmount = 0.0;
        Control_Y.WaterAmount = 0.0;
        Control_Y.NextStep = 0.0;
      }
      break;

     case Control_IN_working_Cappuccino:
      /* Inport: '<Root>/WaterRemain' incorporates:
       *  Inport: '<Root>/CoffeeRemain'
       *  Inport: '<Root>/CupRemain'
       *  Inport: '<Root>/MilkRemain'
       *  Inport: '<Root>/SugarRemain'
       *  Inport: '<Root>/WaterTemp'
       */
      /* During 'working_Cappuccino': '<S1>:422' */
      if (Control_checkall(Control_U.WaterRemain, Control_DW.WaterRecipe,
                           Control_U.MilkRemain, Control_DW.MilkRecipe,
                           Control_U.SugarRemain, Control_DW.SugarRecipe,
                           Control_U.CoffeeRemain, Control_DW.CoffeeRecipe,
                           (real_T)Control_U.CupRemain, Control_U.WaterTemp)) {
        /* Transition: '<S1>:426' */
        Control_DW.is_c12_Control = Control_IN_GetCup;
        Control_DW.temporalCounter_i1 = 0U;

        /* Entry 'GetCup': '<S1>:414' */
        /* Event: '<S1>:13' */
        Control_DW.GetCupEventEventCounter++;
      } else {
        /* Transition: '<S1>:429' */
        Control_DW.is_c12_Control = Control_IN_Init;

        /* Entry 'Init': '<S1>:30' */
        Control_Y.CoffeeAmount = 0.0;
        Control_Y.MilkAmount = 0.0;
        Control_Y.SugarAmount = 0.0;
        Control_Y.WaterAmount = 0.0;
        Control_Y.NextStep = 0.0;
      }
      break;

     default:
      /* During 'working_Coffee': '<S1>:297' */
      if (Control_DW.sfEvent == Control_event_MixFinishEvent) {
        /* Transition: '<S1>:405' */
        Co_exit_internal_working_Coffee();
        Control_DW.is_c12_Control = Control_IN_Step2;
        Control_DW.temporalCounter_i1 = 0U;

        /* Entry 'Step2': '<S1>:404' */
        Control_Y.NextStep = 50.0;
      } else if ((Control_DW.sfEvent == Control_event_Tick) &&
                 (Control_DW.temporalCounter_i2 >= 10000)) {
        /* Transition: '<S1>:679' */
        /* Transition: '<S1>:682' */
        Co_exit_internal_working_Coffee();
        Control_DW.is_c12_Control = Control_IN_error;
      } else {
        /* During 'WaterState': '<S1>:661' */
        if ((Control_DW.is_WaterState != Control_IN_Finished) &&
            ((Control_DW.sfEvent == Control_event_Tick) &&
             (Control_DW.temporalCounter_i1 >= (uint32_T)Control_DW.WaterRecipe)))
        {
          /* During 'Working': '<S1>:659' */
          /* Transition: '<S1>:662' */
          /* Exit 'Working': '<S1>:659' */
          Control_Y.WaterAmount = 0.0;
          Control_DW.is_WaterState = Control_IN_Finished;
        } else {
          /* During 'Finished': '<S1>:663' */
        }

        /* During 'SugarDoserState': '<S1>:657' */
        if ((Control_DW.is_SugarDoserState != Control_IN_Finished) &&
            (Control_DW.sfEvent == Control_event_SugarDoserEvent)) {
          /* During 'Working': '<S1>:655' */
          /* Transition: '<S1>:656' */
          /* Exit 'Working': '<S1>:655' */
          Control_Y.SugarAmount = 0.0;
          Control_DW.is_SugarDoserState = Control_IN_Finished;
        } else {
          /* During 'Finished': '<S1>:654' */
        }

        /* During 'CoffeeDoserState': '<S1>:649' */
        if ((Control_DW.is_CoffeeDoserState != Control_IN_Finished) &&
            (Control_DW.sfEvent == Control_event_CoffeeDoserEvent)) {
          /* During 'Working': '<S1>:651' */
          /* Transition: '<S1>:652' */
          /* Exit 'Working': '<S1>:651' */
          Control_Y.CoffeeAmount = 0.0;
          Control_DW.is_CoffeeDoserState = Control_IN_Finished;
        } else {
          /* During 'Finished': '<S1>:653' */
        }

        /* During 'MilkDoserState': '<S1>:666' */
        if ((Control_DW.is_MilkDoserState != Control_IN_Finished) &&
            (Control_DW.sfEvent == Control_event_MilkDoserEvent)) {
          /* During 'Working': '<S1>:664' */
          /* Transition: '<S1>:667' */
          /* Exit 'Working': '<S1>:664' */
          Control_Y.MilkAmount = 0.0;
          Control_DW.is_MilkDoserState = Control_IN_Finished;
        } else {
          /* During 'Finished': '<S1>:665' */
        }
      }
      break;
    }
  }
}

/* Model step function */
void Control_step(void)
{
  boolean_T zcEvent[11];
  int8_T rtb_inputevents[11];
  int32_T i;
  boolean_T tmp;
  boolean_T zcEvent_0;

  /* Chart: '<Root>/Control System' incorporates:
   *  TriggerPort: '<S1>/ input events '
   */
  tmp = false;
  for (i = 0; i < 11; i++) {
    /* Inport: '<Root>/ input events ' */
    zcEvent_0 = (Control_U.inputevents[i] &&
                 (Control_PrevZCX.ControlSystem_Trig_ZCE[i] != POS_ZCSIG));
    tmp = (tmp || zcEvent_0);
    zcEvent[i] = zcEvent_0;
  }

  if (tmp) {
    for (i = 0; i < 11; i++) {
      rtb_inputevents[i] = (int8_T)zcEvent[i];
    }

    /* Gateway: Control System */
    i = 0;
    if (rtb_inputevents[0U] == 1) {
      i = 1;
      if (Control_DW.temporalCounter_i1 < MAX_uint32_T) {
        Control_DW.temporalCounter_i1++;
      }

      if (Control_DW.temporalCounter_i2 < 16383U) {
        Control_DW.temporalCounter_i2++;
      }

      /* Event: '<S1>:26' */
      Control_DW.sfEvent = Control_event_Tick;
      Control_chartstep_c12_Control();
    }

    if (rtb_inputevents[1U] == 1) {
      i = 1;

      /* Event: '<S1>:27' */
      Control_DW.sfEvent = Control_event_AmericanCoffee;
      Control_chartstep_c12_Control();
    }

    if (rtb_inputevents[2U] == 1) {
      i = 1;

      /* Event: '<S1>:28' */
      Control_DW.sfEvent = Control_event_CoffeeLatte;
      Control_chartstep_c12_Control();
    }

    if (rtb_inputevents[3U] == 1) {
      i = 1;

      /* Event: '<S1>:29' */
      Control_DW.sfEvent = Control_event_Cappuccino;
      Control_chartstep_c12_Control();
    }

    if (rtb_inputevents[4U] == 1) {
      i = 1;

      /* Event: '<S1>:6' */
      Control_DW.sfEvent = Control_event_StepEvent;
      Control_chartstep_c12_Control();
    }

    if (rtb_inputevents[5U] == 1) {
      i = 1;

      /* Event: '<S1>:5' */
      Control_DW.sfEvent = Control_event_FeedFinishEvent;
      Control_chartstep_c12_Control();
    }

    if (rtb_inputevents[6U] == 1) {
      i = 1;

      /* Event: '<S1>:22' */
      Control_DW.sfEvent = Control_event_MixFinishEvent;
      Control_chartstep_c12_Control();
    }

    if (rtb_inputevents[7U] == 1) {
      i = 1;

      /* Event: '<S1>:12' */
      Control_DW.sfEvent = Control_event_SugarDoserEvent;
      Control_chartstep_c12_Control();
    }

    if (rtb_inputevents[8U] == 1) {
      i = 1;

      /* Event: '<S1>:10' */
      Control_DW.sfEvent = Control_event_MilkDoserEvent;
      Control_chartstep_c12_Control();
    }

    if (rtb_inputevents[9U] == 1) {
      i = 1;

      /* Event: '<S1>:9' */
      Control_DW.sfEvent = Control_event_CoffeeDoserEvent;
      Control_chartstep_c12_Control();
    }

    if (rtb_inputevents[10U] == 1) {
      i = 1;

      /* Event: '<S1>:686' */
      Control_DW.sfEvent = Control_event_TakeOutEvent;
      Control_chartstep_c12_Control();
    }

    if ((i != 0) && (Control_DW.GetCupEventEventCounter > 0U)) {
      /* Outport: '<Root>/GetCupEvent' */
      Control_Y.GetCupEvent = !Control_Y.GetCupEvent;
      Control_DW.GetCupEventEventCounter--;
    }
  }

  for (i = 0; i < 11; i++) {
    /* Inport: '<Root>/ input events ' */
    Control_PrevZCX.ControlSystem_Trig_ZCE[i] = (uint8_T)
      (Control_U.inputevents[i] ? (int32_T)POS_ZCSIG : (int32_T)ZERO_ZCSIG);
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(Control_M->rtwLogInfo, (&Control_M->Timing.taskTime0));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.005s, 0.0s] */
    if ((rtmGetTFinal(Control_M)!=-1) &&
        !((rtmGetTFinal(Control_M)-Control_M->Timing.taskTime0) >
          Control_M->Timing.taskTime0 * (DBL_EPSILON))) {
      rtmSetErrorStatus(Control_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Control_M->Timing.clockTick0)) {
    ++Control_M->Timing.clockTickH0;
  }

  Control_M->Timing.taskTime0 = Control_M->Timing.clockTick0 *
    Control_M->Timing.stepSize0 + Control_M->Timing.clockTickH0 *
    Control_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void Control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)Control_M, 0,
                sizeof(RT_MODEL_Control_T));
  rtmSetTFinal(Control_M, -1);
  Control_M->Timing.stepSize0 = 0.005;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    Control_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(Control_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(Control_M->rtwLogInfo, (NULL));
    rtliSetLogT(Control_M->rtwLogInfo, "tout");
    rtliSetLogX(Control_M->rtwLogInfo, "");
    rtliSetLogXFinal(Control_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(Control_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(Control_M->rtwLogInfo, 1);
    rtliSetLogMaxRows(Control_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(Control_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &Control_Y.CoffeeAmount,
        &Control_Y.MilkAmount,
        &Control_Y.SugarAmount,
        &Control_Y.WaterAmount,
        &Control_Y.NextStep,
        &Control_Y.GetCupEvent
      };

      rtliSetLogYSignalPtrs(Control_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0,
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4,
        4,
        4,
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_BOOLEAN
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0,
        0,
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "CoffeeAmount",
        "MilkAmount",
        "SugarAmount",
        "WaterAmount",
        "NextStep",
        "GetCupEvent" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "Control/CoffeeAmount",
        "Control/MilkAmount",
        "Control/SugarAmount",
        "Control/WaterAmount",
        "Control/NextStep",
        "Control/GetCupEvent" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_BOOLEAN, SS_BOOLEAN, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          6,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(Control_M->rtwLogInfo, rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[3] = &rt_LoggedOutputWidths[3];
      rt_LoggedCurrentSignalDimensions[4] = &rt_LoggedOutputWidths[4];
      rt_LoggedCurrentSignalDimensions[5] = &rt_LoggedOutputWidths[5];
    }

    rtliSetLogY(Control_M->rtwLogInfo, "yout");
  }

  /* states (dwork) */
  (void) memset((void *)&Control_DW, 0,
                sizeof(DW_Control_T));

  /* external inputs */
  (void) memset((void *)&Control_U, 0,
                sizeof(ExtU_Control_T));

  /* external outputs */
  (void) memset((void *)&Control_Y, 0,
                sizeof(ExtY_Control_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(Control_M->rtwLogInfo, 0.0, rtmGetTFinal
    (Control_M), Control_M->Timing.stepSize0, (&rtmGetErrorStatus(Control_M)));

  {
    int32_T i;
    for (i = 0; i < 11; i++) {
      Control_PrevZCX.ControlSystem_Trig_ZCE[i] = POS_ZCSIG;
    }
  }

  /* InitializeConditions for Chart: '<Root>/Control System' */
  Control_DW.temporalCounter_i2 = 0U;
  Control_DW.is_active_CoffeeDoserState = 0U;
  Control_DW.is_CoffeeDoserState = Control_IN_NO_ACTIVE_CHILD;
  Control_DW.is_active_MilkDoserState = 0U;
  Control_DW.is_MilkDoserState = Control_IN_NO_ACTIVE_CHILD;
  Control_DW.is_active_SugarDoserState = 0U;
  Control_DW.is_SugarDoserState = Control_IN_NO_ACTIVE_CHILD;
  Control_DW.is_active_WaterState = 0U;
  Control_DW.is_WaterState = Control_IN_NO_ACTIVE_CHILD;
  Control_DW.temporalCounter_i1 = 0U;
  Control_DW.is_active_c12_Control = 0U;
  Control_DW.is_c12_Control = Control_IN_NO_ACTIVE_CHILD;
  Control_DW.CoffeeRecipe = 0.0;
  Control_DW.MilkRecipe = 0.0;
  Control_DW.SugarRecipe = 0.0;
  Control_DW.WaterRecipe = 0.0;

  /* InitializeConditions for Outport: '<Root>/CoffeeAmount' incorporates:
   *  InitializeConditions for Chart: '<Root>/Control System'
   */
  Control_Y.CoffeeAmount = 0.0;

  /* InitializeConditions for Outport: '<Root>/MilkAmount' incorporates:
   *  InitializeConditions for Chart: '<Root>/Control System'
   */
  Control_Y.MilkAmount = 0.0;

  /* InitializeConditions for Outport: '<Root>/SugarAmount' incorporates:
   *  InitializeConditions for Chart: '<Root>/Control System'
   */
  Control_Y.SugarAmount = 0.0;

  /* InitializeConditions for Outport: '<Root>/WaterAmount' incorporates:
   *  InitializeConditions for Chart: '<Root>/Control System'
   */
  Control_Y.WaterAmount = 0.0;

  /* InitializeConditions for Outport: '<Root>/NextStep' incorporates:
   *  InitializeConditions for Chart: '<Root>/Control System'
   */
  Control_Y.NextStep = 0.0;

  /* InitializeConditions for Chart: '<Root>/Control System' */
  Control_DW.GetCupEventEventCounter = 0U;

  /* InitializeConditions for Outport: '<Root>/GetCupEvent' incorporates:
   *  InitializeConditions for Chart: '<Root>/Control System'
   */
  Control_Y.GetCupEvent = false;
}

/* Model terminate function */
void Control_terminate(void)
{
  /* (no terminate code required) */
}
