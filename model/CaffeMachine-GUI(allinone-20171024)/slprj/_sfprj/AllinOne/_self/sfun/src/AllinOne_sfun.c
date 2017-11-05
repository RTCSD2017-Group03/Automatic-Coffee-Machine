/* Include files */

#include "AllinOne_sfun.h"
#include "AllinOne_sfun_debug_macros.h"
#include "c2_AllinOne.h"
#include "c3_AllinOne.h"
#include "c4_AllinOne.h"

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

  return 0;
}

extern void sf_AllinOne_uses_exported_functions(int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(267568544U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3543501794U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2494743422U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2263389394U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
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

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2228015324U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1719833054U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4047056744U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3399837229U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3309691709U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2979347428U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3314027490U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(958967991U);
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
     case 2:
      {
        if (strcmp(aiChksum, "G6UTELF8wXKjkaLqlsdLZ") == 0) {
          extern mxArray *sf_c2_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c2_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "G6UTELF8wXKjkaLqlsdLZ") == 0) {
          extern mxArray *sf_c3_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c3_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "G6UTELF8wXKjkaLqlsdLZ") == 0) {
          extern mxArray *sf_c4_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c4_AllinOne_get_autoinheritance_info();
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
     case 2:
      {
        if (strcmp(tpChksum, "soRKVxL3Ge1NMYg2POcNOU") == 0) {
          extern mxArray *sf_c2_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c2_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "soRKVxL3Ge1NMYg2POcNOU") == 0) {
          extern mxArray *sf_c3_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c3_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "soRKVxL3Ge1NMYg2POcNOU") == 0) {
          extern mxArray *sf_c4_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c4_AllinOne_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_AllinOne_jit_fallback_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 2:
      {
        if (strcmp(tpChksum, "soRKVxL3Ge1NMYg2POcNOU") == 0) {
          extern mxArray *sf_c2_AllinOne_jit_fallback_info(void);
          plhs[0] = sf_c2_AllinOne_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "soRKVxL3Ge1NMYg2POcNOU") == 0) {
          extern mxArray *sf_c3_AllinOne_jit_fallback_info(void);
          plhs[0] = sf_c3_AllinOne_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "soRKVxL3Ge1NMYg2POcNOU") == 0) {
          extern mxArray *sf_c4_AllinOne_jit_fallback_info(void);
          plhs[0] = sf_c4_AllinOne_jit_fallback_info();
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
     case 2:
      {
        if (strcmp(tpChksum, "soRKVxL3Ge1NMYg2POcNOU") == 0) {
          extern mxArray *sf_c2_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "soRKVxL3Ge1NMYg2POcNOU") == 0) {
          extern mxArray *sf_c3_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "soRKVxL3Ge1NMYg2POcNOU") == 0) {
          extern mxArray *sf_c4_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_AllinOne_get_post_codegen_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 2:
    {
      if (strcmp(tpChksum, "soRKVxL3Ge1NMYg2POcNOU") == 0) {
        extern mxArray *sf_c2_AllinOne_get_post_codegen_info(void);
        plhs[0] = sf_c2_AllinOne_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "soRKVxL3Ge1NMYg2POcNOU") == 0) {
        extern mxArray *sf_c3_AllinOne_get_post_codegen_info(void);
        plhs[0] = sf_c3_AllinOne_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "soRKVxL3Ge1NMYg2POcNOU") == 0) {
        extern mxArray *sf_c4_AllinOne_get_post_codegen_info(void);
        plhs[0] = sf_c4_AllinOne_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
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
