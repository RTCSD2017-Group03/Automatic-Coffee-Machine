/* Include files */

#include "AllinOne_sfun.h"
#include "AllinOne_sfun_debug_macros.h"
#include "c1_AllinOne.h"
#include "c2_AllinOne.h"
#include "c3_AllinOne.h"
#include "c4_AllinOne.h"
#include "c5_AllinOne.h"
#include "c6_AllinOne.h"
#include "c7_AllinOne.h"
#include "c12_AllinOne.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _AllinOneMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void AllinOne_initializer(void)
{
}

void AllinOne_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_AllinOne_method_dispatcher(SimStruct *simstructPtr, unsigned int
  chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_AllinOne_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_AllinOne_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_AllinOne_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_AllinOne_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_AllinOne_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_AllinOne_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_AllinOne_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_AllinOne_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

unsigned int sf_AllinOne_process_check_sum_call( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2001037353U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1196526240U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3030706750U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2144316357U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3791523643U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2319796451U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3258885275U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1392021912U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_AllinOne_get_check_sum(mxArray *plhs[]);
          sf_c1_AllinOne_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_AllinOne_get_check_sum(mxArray *plhs[]);
          sf_c2_AllinOne_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_AllinOne_get_check_sum(mxArray *plhs[]);
          sf_c3_AllinOne_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_AllinOne_get_check_sum(mxArray *plhs[]);
          sf_c4_AllinOne_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_AllinOne_get_check_sum(mxArray *plhs[]);
          sf_c5_AllinOne_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_AllinOne_get_check_sum(mxArray *plhs[]);
          sf_c6_AllinOne_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_AllinOne_get_check_sum(mxArray *plhs[]);
          sf_c7_AllinOne_get_check_sum(plhs);
          break;
        }

       case 12:
        {
          extern void sf_c12_AllinOne_get_check_sum(mxArray *plhs[]);
          sf_c12_AllinOne_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(733163963U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4237115635U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2173590741U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4013272562U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(315542163U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2790376695U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4278191290U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3271897194U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_AllinOne_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(aiChksum, "xlfuh6IKLwg1YRj19cjXaE") == 0) {
          extern mxArray *sf_c1_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c1_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "v0kNoC3Lp0pl46EOMCrQu") == 0) {
          extern mxArray *sf_c2_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c2_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "v0kNoC3Lp0pl46EOMCrQu") == 0) {
          extern mxArray *sf_c3_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c3_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "v0kNoC3Lp0pl46EOMCrQu") == 0) {
          extern mxArray *sf_c4_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c4_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "I0fSdh8RGl2Ie6j7tUIRbB") == 0) {
          extern mxArray *sf_c5_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c5_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "e4w0fbvKXSPTHnK9sMUwWD") == 0) {
          extern mxArray *sf_c6_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c6_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "yV8WQ4Xv82gcA7sjLJ8J7E") == 0) {
          extern mxArray *sf_c7_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c7_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "716vaUXGFCQ99SWlJzG4C") == 0) {
          extern mxArray *sf_c12_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c12_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_AllinOne_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        extern const mxArray *sf_c1_AllinOne_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_AllinOne_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray *sf_c2_AllinOne_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_AllinOne_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray *sf_c3_AllinOne_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_AllinOne_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray *sf_c4_AllinOne_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_AllinOne_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray *sf_c5_AllinOne_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_AllinOne_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray *sf_c6_AllinOne_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_AllinOne_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray *sf_c7_AllinOne_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_AllinOne_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_AllinOne_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_AllinOne_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_AllinOne_third_party_uses_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "rt9X2NcoWn5qK1X5ACUhXG") == 0) {
          extern mxArray *sf_c1_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c1_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "Rc4mFQGH43nf5mOvh5I66E") == 0) {
          extern mxArray *sf_c2_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c2_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "Rc4mFQGH43nf5mOvh5I66E") == 0) {
          extern mxArray *sf_c3_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c3_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "Rc4mFQGH43nf5mOvh5I66E") == 0) {
          extern mxArray *sf_c4_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c4_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "8DsUEgDXf4OMATufhiy1qC") == 0) {
          extern mxArray *sf_c5_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c5_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "D4FkRXFQpdcLudHeMYfweB") == 0) {
          extern mxArray *sf_c6_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c6_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "hSnk82H0Dy2NCyahC3ZrED") == 0) {
          extern mxArray *sf_c7_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c7_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "bnHkRVvRENM6oJGrNiiUz") == 0) {
          extern mxArray *sf_c12_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c12_AllinOne_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_AllinOne_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 1:
      {
        if (strcmp(tpChksum, "rt9X2NcoWn5qK1X5ACUhXG") == 0) {
          extern mxArray *sf_c1_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "Rc4mFQGH43nf5mOvh5I66E") == 0) {
          extern mxArray *sf_c2_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "Rc4mFQGH43nf5mOvh5I66E") == 0) {
          extern mxArray *sf_c3_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "Rc4mFQGH43nf5mOvh5I66E") == 0) {
          extern mxArray *sf_c4_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "8DsUEgDXf4OMATufhiy1qC") == 0) {
          extern mxArray *sf_c5_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "D4FkRXFQpdcLudHeMYfweB") == 0) {
          extern mxArray *sf_c6_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "hSnk82H0Dy2NCyahC3ZrED") == 0) {
          extern mxArray *sf_c7_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "bnHkRVvRENM6oJGrNiiUz") == 0) {
          extern mxArray *sf_c12_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void AllinOne_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _AllinOneMachineNumber_ = sf_debug_initialize_machine(debugInstance,"AllinOne",
    "sfun",0,8,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_AllinOneMachineNumber_,0,
    0);
  sf_debug_set_machine_data_thresholds(debugInstance,_AllinOneMachineNumber_,0);
}

void AllinOne_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_AllinOne_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("AllinOne",
      "AllinOne");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_AllinOne_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
