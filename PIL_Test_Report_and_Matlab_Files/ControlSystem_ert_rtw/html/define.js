function CodeDefine() { 
this.def = new Array();
this.def["IsrOverrun"] = {file: "ert_main_c.html",line:27,type:"var"};
this.def["OverrunFlag"] = {file: "ert_main_c.html",line:28,type:"var"};
this.def["rt_OneStep"] = {file: "ert_main_c.html",line:29,type:"fcn"};
this.def["main"] = {file: "ert_main_c.html",line:46,type:"fcn"};
this.def["rtDW"] = {file: "ControlSystem_c.html",line:53,type:"var"};
this.def["rtPrevZCX"] = {file: "ControlSystem_c.html",line:56,type:"var"};
this.def["rtU"] = {file: "ControlSystem_c.html",line:59,type:"var"};
this.def["rtY"] = {file: "ControlSystem_c.html",line:62,type:"var"};
this.def["rtM_"] = {file: "ControlSystem_c.html",line:65,type:"var"};
this.def["rtM"] = {file: "ControlSystem_c.html",line:66,type:"var"};
this.def["exit_internal_working_Coffee"] = {file: "ControlSystem_c.html",line:76,type:"fcn"};
this.def["checkall"] = {file: "ControlSystem_c.html",line:121,type:"fcn"};
this.def["chartstep_c12_ControlSystem"] = {file: "ControlSystem_c.html",line:189,type:"fcn"};
this.def["ControlSystem_step"] = {file: "ControlSystem_c.html",line:594,type:"fcn"};
this.def["ControlSystem_initialize"] = {file: "ControlSystem_c.html",line:778,type:"fcn"};
this.def["RT_MODEL"] = {file: "ControlSystem_h.html",line:49,type:"type"};
this.def["DW"] = {file: "ControlSystem_h.html",line:70,type:"type"};
this.def["PrevZCX"] = {file: "ControlSystem_h.html",line:75,type:"type"};
this.def["ExtU"] = {file: "ControlSystem_h.html",line:95,type:"type"};
this.def["ExtY"] = {file: "ControlSystem_h.html",line:105,type:"type"};
this.def["P"] = {file: "ControlSystem_h.html",line:130,type:"type"};
this.def["rtP"] = {file: "ControlSystem_data_c.html",line:27,type:"var"};
this.def["int8_T"] = {file: "rtwtypes_h.html",line:55,type:"type"};
this.def["uint8_T"] = {file: "rtwtypes_h.html",line:56,type:"type"};
this.def["int16_T"] = {file: "rtwtypes_h.html",line:57,type:"type"};
this.def["uint16_T"] = {file: "rtwtypes_h.html",line:58,type:"type"};
this.def["int32_T"] = {file: "rtwtypes_h.html",line:59,type:"type"};
this.def["uint32_T"] = {file: "rtwtypes_h.html",line:60,type:"type"};
this.def["int64_T"] = {file: "rtwtypes_h.html",line:61,type:"type"};
this.def["uint64_T"] = {file: "rtwtypes_h.html",line:62,type:"type"};
this.def["real32_T"] = {file: "rtwtypes_h.html",line:63,type:"type"};
this.def["real64_T"] = {file: "rtwtypes_h.html",line:64,type:"type"};
this.def["real_T"] = {file: "rtwtypes_h.html",line:70,type:"type"};
this.def["time_T"] = {file: "rtwtypes_h.html",line:71,type:"type"};
this.def["boolean_T"] = {file: "rtwtypes_h.html",line:72,type:"type"};
this.def["int_T"] = {file: "rtwtypes_h.html",line:73,type:"type"};
this.def["uint_T"] = {file: "rtwtypes_h.html",line:74,type:"type"};
this.def["ulong_T"] = {file: "rtwtypes_h.html",line:75,type:"type"};
this.def["ulonglong_T"] = {file: "rtwtypes_h.html",line:76,type:"type"};
this.def["char_T"] = {file: "rtwtypes_h.html",line:77,type:"type"};
this.def["uchar_T"] = {file: "rtwtypes_h.html",line:78,type:"type"};
this.def["byte_T"] = {file: "rtwtypes_h.html",line:79,type:"type"};
this.def["creal32_T"] = {file: "rtwtypes_h.html",line:89,type:"type"};
this.def["creal64_T"] = {file: "rtwtypes_h.html",line:94,type:"type"};
this.def["creal_T"] = {file: "rtwtypes_h.html",line:99,type:"type"};
this.def["cint8_T"] = {file: "rtwtypes_h.html",line:106,type:"type"};
this.def["cuint8_T"] = {file: "rtwtypes_h.html",line:113,type:"type"};
this.def["cint16_T"] = {file: "rtwtypes_h.html",line:120,type:"type"};
this.def["cuint16_T"] = {file: "rtwtypes_h.html",line:127,type:"type"};
this.def["cint32_T"] = {file: "rtwtypes_h.html",line:134,type:"type"};
this.def["cuint32_T"] = {file: "rtwtypes_h.html",line:141,type:"type"};
this.def["cint64_T"] = {file: "rtwtypes_h.html",line:148,type:"type"};
this.def["cuint64_T"] = {file: "rtwtypes_h.html",line:155,type:"type"};
this.def["pointer_T"] = {file: "rtwtypes_h.html",line:176,type:"type"};
this.def["ZCDirection"] = {file: "zero_crossing_types_h.html",line:33,type:"type"};
this.def["ZCSigState"] = {file: "zero_crossing_types_h.html",line:36,type:"type"};
this.def["ZCEventType"] = {file: "zero_crossing_types_h.html",line:49,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["ert_main_c.html"] = "../ert_main.c";
	this.html2Root["ert_main_c.html"] = "ert_main_c.html";
	this.html2SrcPath["ControlSystem_c.html"] = "../ControlSystem.c";
	this.html2Root["ControlSystem_c.html"] = "ControlSystem_c.html";
	this.html2SrcPath["ControlSystem_h.html"] = "../ControlSystem.h";
	this.html2Root["ControlSystem_h.html"] = "ControlSystem_h.html";
	this.html2SrcPath["ControlSystem_data_c.html"] = "../ControlSystem_data.c";
	this.html2Root["ControlSystem_data_c.html"] = "ControlSystem_data_c.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "rtwtypes_h.html";
	this.html2SrcPath["zero_crossing_types_h.html"] = "../zero_crossing_types.h";
	this.html2Root["zero_crossing_types_h.html"] = "zero_crossing_types_h.html";
	this.html2SrcPath["rtmodel_h.html"] = "../rtmodel.h";
	this.html2Root["rtmodel_h.html"] = "rtmodel_h.html";
	this.html2SrcPath["MW_target_hardware_resources_h.html"] = "../MW_target_hardware_resources.h";
	this.html2Root["MW_target_hardware_resources_h.html"] = "MW_target_hardware_resources_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"ert_main_c.html","ControlSystem_c.html","ControlSystem_h.html","ControlSystem_data_c.html","rtwtypes_h.html","zero_crossing_types_h.html","rtmodel_h.html","MW_target_hardware_resources_h.html"];
