function CodeMetrics() {
	 this.metricsArray = {};
	 this.metricsArray.var = new Array();
	 this.metricsArray.fcn = new Array();
	 this.metricsArray.var["rtDW"] = {file: "C:\\Users\\zhiping\\Desktop\\CaffeMachine-GUI(allinone-20171024)\\ControlSystem_ert_rtw\\ControlSystem.c",
	size: 73};
	 this.metricsArray.var["rtM_"] = {file: "C:\\Users\\zhiping\\Desktop\\CaffeMachine-GUI(allinone-20171024)\\ControlSystem_ert_rtw\\ControlSystem.c",
	size: 8};
	 this.metricsArray.var["rtPrevZCX"] = {file: "C:\\Users\\zhiping\\Desktop\\CaffeMachine-GUI(allinone-20171024)\\ControlSystem_ert_rtw\\ControlSystem.c",
	size: 11};
	 this.metricsArray.var["rtU"] = {file: "C:\\Users\\zhiping\\Desktop\\CaffeMachine-GUI(allinone-20171024)\\ControlSystem_ert_rtw\\ControlSystem.c",
	size: 51};
	 this.metricsArray.var["rtY"] = {file: "C:\\Users\\zhiping\\Desktop\\CaffeMachine-GUI(allinone-20171024)\\ControlSystem_ert_rtw\\ControlSystem.c",
	size: 41};
	 this.metricsArray.fcn["ControlSystem.c:chartstep_c12_ControlSystem"] = {file: "C:\\Users\\zhiping\\Desktop\\CaffeMachine-GUI(allinone-20171024)\\ControlSystem_ert_rtw\\ControlSystem.c",
	stack: 0,
	stackTotal: 1};
	 this.metricsArray.fcn["ControlSystem.c:checkall"] = {file: "C:\\Users\\zhiping\\Desktop\\CaffeMachine-GUI(allinone-20171024)\\ControlSystem_ert_rtw\\ControlSystem.c",
	stack: 1,
	stackTotal: 1};
	 this.metricsArray.fcn["ControlSystem.c:exit_internal_working_Coffee"] = {file: "C:\\Users\\zhiping\\Desktop\\CaffeMachine-GUI(allinone-20171024)\\ControlSystem_ert_rtw\\ControlSystem.c",
	stack: 0,
	stackTotal: 0};
	 this.metricsArray.fcn["ControlSystem_initialize"] = {file: "C:\\Users\\zhiping\\Desktop\\CaffeMachine-GUI(allinone-20171024)\\ControlSystem_ert_rtw\\ControlSystem.c",
	stack: 4,
	stackTotal: 4};
	 this.metricsArray.fcn["ControlSystem_step"] = {file: "C:\\Users\\zhiping\\Desktop\\CaffeMachine-GUI(allinone-20171024)\\ControlSystem_ert_rtw\\ControlSystem.c",
	stack: 40,
	stackTotal: 41};
	 this.metricsArray.fcn["printf"] = {file: "C:\\Users\\zhiping\\Desktop\\CaffeMachine-GUI(allinone-20171024)\\ControlSystem_ert_rtw\\ControlSystem.c",
	stack: 0,
	stackTotal: 0};
	 this.getMetrics = function(token) { 
		 var data;
		 data = this.metricsArray.var[token];
		 if (!data) {
			 data = this.metricsArray.fcn[token];
			 if (data) data.type = "fcn";
		 } else { 
			 data.type = "var";
		 }
	 return data;}
}
	 CodeMetrics.instance = new CodeMetrics();
