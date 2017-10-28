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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(426470914U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3433192016U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1119476781U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1997662310U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4142856473U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2473994914U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(884735068U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2568847656U);
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3061339410U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1991824845U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3599338742U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2357874978U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2891345737U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2332786789U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1839988722U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3433415310U);
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
        if (strcmp(aiChksum, "3yuxwpQdv8FVs4bVHgzvoH") == 0) {
          extern mxArray *sf_c1_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c1_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "oDOsdmxqhbT6vbYvkYJ0GD") == 0) {
          extern mxArray *sf_c2_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c2_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "oDOsdmxqhbT6vbYvkYJ0GD") == 0) {
          extern mxArray *sf_c3_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c3_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "oDOsdmxqhbT6vbYvkYJ0GD") == 0) {
          extern mxArray *sf_c4_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c4_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "18LdmSaYemkEJXBtsABOZC") == 0) {
          extern mxArray *sf_c5_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c5_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "zhe03H0KICfzuwungCAIb") == 0) {
          extern mxArray *sf_c6_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c6_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "Pz9snTQ0lG0MjgKMDFaeLF") == 0) {
          extern mxArray *sf_c7_AllinOne_get_autoinheritance_info(void);
          plhs[0] = sf_c7_AllinOne_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "n3H6cCYDFgF202lYDuyzOC") == 0) {
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
        if (strcmp(tpChksum, "HgWaE9XjDfimpxiUiPbkWB") == 0) {
          extern mxArray *sf_c1_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c1_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "GdmMH01CyxvIZW3O0366HD") == 0) {
          extern mxArray *sf_c2_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c2_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "GdmMH01CyxvIZW3O0366HD") == 0) {
          extern mxArray *sf_c3_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c3_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "GdmMH01CyxvIZW3O0366HD") == 0) {
          extern mxArray *sf_c4_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c4_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "mc0rC8c3boi0qyYj6oPCeG") == 0) {
          extern mxArray *sf_c5_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c5_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "Zti2IJFaQokb4Nfxwfw1DC") == 0) {
          extern mxArray *sf_c6_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c6_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "DD3QDg0agVCz5ruVRIDGUD") == 0) {
          extern mxArray *sf_c7_AllinOne_third_party_uses_info(void);
          plhs[0] = sf_c7_AllinOne_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "yI6kvSkp3aF4GtKlctv9OE") == 0) {
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
     case 1:
      {
        if (strcmp(tpChksum, "HgWaE9XjDfimpxiUiPbkWB") == 0) {
          extern mxArray *sf_c1_AllinOne_jit_fallback_info(void);
          plhs[0] = sf_c1_AllinOne_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "GdmMH01CyxvIZW3O0366HD") == 0) {
          extern mxArray *sf_c2_AllinOne_jit_fallback_info(void);
          plhs[0] = sf_c2_AllinOne_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "GdmMH01CyxvIZW3O0366HD") == 0) {
          extern mxArray *sf_c3_AllinOne_jit_fallback_info(void);
          plhs[0] = sf_c3_AllinOne_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "GdmMH01CyxvIZW3O0366HD") == 0) {
          extern mxArray *sf_c4_AllinOne_jit_fallback_info(void);
          plhs[0] = sf_c4_AllinOne_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "mc0rC8c3boi0qyYj6oPCeG") == 0) {
          extern mxArray *sf_c5_AllinOne_jit_fallback_info(void);
          plhs[0] = sf_c5_AllinOne_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "Zti2IJFaQokb4Nfxwfw1DC") == 0) {
          extern mxArray *sf_c6_AllinOne_jit_fallback_info(void);
          plhs[0] = sf_c6_AllinOne_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "DD3QDg0agVCz5ruVRIDGUD") == 0) {
          extern mxArray *sf_c7_AllinOne_jit_fallback_info(void);
          plhs[0] = sf_c7_AllinOne_jit_fallback_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "yI6kvSkp3aF4GtKlctv9OE") == 0) {
          extern mxArray *sf_c12_AllinOne_jit_fallback_info(void);
          plhs[0] = sf_c12_AllinOne_jit_fallback_info();
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
        if (strcmp(tpChksum, "HgWaE9XjDfimpxiUiPbkWB") == 0) {
          extern mxArray *sf_c1_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "GdmMH01CyxvIZW3O0366HD") == 0) {
          extern mxArray *sf_c2_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "GdmMH01CyxvIZW3O0366HD") == 0) {
          extern mxArray *sf_c3_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "GdmMH01CyxvIZW3O0366HD") == 0) {
          extern mxArray *sf_c4_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "mc0rC8c3boi0qyYj6oPCeG") == 0) {
          extern mxArray *sf_c5_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "Zti2IJFaQokb4Nfxwfw1DC") == 0) {
          extern mxArray *sf_c6_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c6_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "DD3QDg0agVCz5ruVRIDGUD") == 0) {
          extern mxArray *sf_c7_AllinOne_updateBuildInfo_args_info(void);
          plhs[0] = sf_c7_AllinOne_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "yI6kvSkp3aF4GtKlctv9OE") == 0) {
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

void sf_AllinOne_get_post_codegen_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "HgWaE9XjDfimpxiUiPbkWB") == 0) {
        extern mxArray *sf_c1_AllinOne_get_post_codegen_info(void);
        plhs[0] = sf_c1_AllinOne_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "GdmMH01CyxvIZW3O0366HD") == 0) {
        extern mxArray *sf_c2_AllinOne_get_post_codegen_info(void);
        plhs[0] = sf_c2_AllinOne_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "GdmMH01CyxvIZW3O0366HD") == 0) {
        extern mxArray *sf_c3_AllinOne_get_post_codegen_info(void);
        plhs[0] = sf_c3_AllinOne_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "GdmMH01CyxvIZW3O0366HD") == 0) {
        extern mxArray *sf_c4_AllinOne_get_post_codegen_info(void);
        plhs[0] = sf_c4_AllinOne_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "mc0rC8c3boi0qyYj6oPCeG") == 0) {
        extern mxArray *sf_c5_AllinOne_get_post_codegen_info(void);
        plhs[0] = sf_c5_AllinOne_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "Zti2IJFaQokb4Nfxwfw1DC") == 0) {
        extern mxArray *sf_c6_AllinOne_get_post_codegen_info(void);
        plhs[0] = sf_c6_AllinOne_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "DD3QDg0agVCz5ruVRIDGUD") == 0) {
        extern mxArray *sf_c7_AllinOne_get_post_codegen_info(void);
        plhs[0] = sf_c7_AllinOne_get_post_codegen_info();
        return;
      }
    }
    break;

   case 12:
    {
      if (strcmp(tpChksum, "yI6kvSkp3aF4GtKlctv9OE") == 0) {
        extern mxArray *sf_c12_AllinOne_get_post_codegen_info(void);
        plhs[0] = sf_c12_AllinOne_get_post_codegen_info();
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
