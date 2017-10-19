![](http://upload-images.jianshu.io/upload_images/3810775-4f694b29cf8e984d.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

**软件需求规范文档**
**Software Requirements Specifications Document (SRS)**

> 本文档参照IEEE Guide to Software Requirements Specifications (Std 830-1993). 本文档只用于定义软件的需求分析、功能和接口定义，不涉及软件的具体实现方法。

- 项目名称：**自动咖啡机**

- 开发团队：华中科技大学RTCSD第三小组

- 版本号：(1.0)	

- 日期： (10/18/2017)


# 1. 引言
本项目是华中科技大学2017年14级机械本科《实施控制软件设计》课程第四次作业，也是课程设计的作业内容。需要各小组组成开发团队进行协同合作。本小组成员以及分工如下：
* 张照博 （C语言代码编写、软件设计规格书撰写）
* 彭彦毓 （物理建模、模块导出）
* 陈志平 （C语言代码编写、Debug）
* 李佳杰 （单元测试、概要设计说明书）
* 刘玉松 （项目总结、说明文档）

## 1.1 编写目的

本文档用于指导自动咖啡机硬件及软件开发过程，与软件用户定义和明确软件的功能需求。本文档的目标读者为软件用户和软件开发项目组成员。

## 1.2 背景

### 1.2.1 立项目标
用户在咖啡机面板上选择自己想要喝的咖啡（美式、拿铁、卡布奇诺...）并按下开始按钮后，咖啡机开始按照设定的配方制作咖啡。


### 1.2.2 类似产品分析
   主校区图书馆一楼大厅进门右侧就有一台自动咖啡机，支持联网付费，全自动咖啡现磨冲泡。支持多品种选择，价格从10元到30元不等。与本项目产品高度相似，但是外部无操作界面，全部由服务器通过移动端进行操作，远程控制咖啡机进行生产。

![](http://upload-images.jianshu.io/upload_images/3810775-969bfd85665f2057.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

   全自动咖啡机是整个咖啡机行业里发展最快的。从1999年GAGGIA发布了第一台能制作Espresso（意式浓缩咖啡）的全自动咖啡机，各个不同的咖啡机厂商都在致力于研究开发，使得其功能不断的完善，已经有能加热牛奶并把它按比例配在咖啡里的高端机型面市。好的全自动咖啡机制作出来的咖啡完全可以和商用专业机相媲美，而因其能自动磨豆且相对于专业机来说价格又低很多，所以从问世以来便一直受到家庭及办公场所的青睐。


## 1.3 定义和缩写
自动咖啡机能依靠机械电动磨粉、填充和烧煮咖啡，全部免除了手工的操作。或称全自动咖啡机，内部装有电子控制系统，用来控制磨豆粗细的调节，每杯的水量。

Automatic Coffee Machine  （ACM？？）

## 1.4 参考资料
[自动咖啡机_百度百科](https://baike.baidu.com/item/%E8%87%AA%E5%8A%A8%E5%92%96%E5%95%A1%E6%9C%BA/342029?fr=aladdin)
[全自动咖啡机_百度百科](https://baike.baidu.com/item/%E5%85%A8%E8%87%AA%E5%8A%A8%E5%92%96%E5%95%A1%E6%9C%BA/342271)

# 2. 任务概述

## 2.1 目标

   制作流程为：Feeder机构取一空杯放到传送带上，传送带把空杯送到龙头下，牛奶、糖浆、浓缩咖啡液和热水按照配方比例混合后装入空杯，传送带把满杯的咖啡送到用户取杯处，用户取走咖啡后，自动咖啡机可以继续响应面板上的按钮制作下一杯咖啡。


## 2.2 用户的特点
身体健康，手指无残疾现象。有喝咖啡的习惯，并且愿意接受现冲咖啡。

## 2.3 假定和约束

- 实验条件： 一块STM32的板子。可编程的的电脑。Github分布式协作管理。
- 开发期限：2017年10月完成软件开发，2017年11月完成集成调试。
- 开发流程：按照软件流程规范，进行需求分析文档撰写和评审、系统架构方案撰写和评审、单元模块代码开发和单元测试、软件集成测试、现场调试和bug修复等工作。

# 3. 需求规定
## 3.1 功能需求规定

### 3.1.1 功能1--美式咖啡
* #### 功能描述：
美式咖啡的原料就是沸水和咖啡粉，所以只需要Coffee 和 Water Part 正常工作即可。

*  输入：按下“美式咖啡”
* 参数：无

* 处理过程：Feeder取空杯，传送带传动。两个Part的阀门打开，加热器加热。按照比例调节咖啡粉和沸水的配比。
* 输出：美式清咖

### 3.1.2 功能2--拿铁
* #### 功能描述：
拿铁的原料是咖啡粉，沸水，牛奶。所以只需要Coffee、Milk 和 Water Part 正常工作即可


*  输入：按下“拿铁”
*  参数：无

* 处理过程：Feeder取空杯，传送带传动。三个Part的阀门打开，加热器加热。按照比例调节咖啡粉和沸水以及牛奶的配比。
*  输出：拿铁咖啡


### 3.1.3 功能3--卡布奇诺
* #### 功能描述：
卡布奇诺的原料是咖啡粉，沸水，糖、牛奶。所以需要Coffee、Milk、Sugar 和 Water Part 正常工作方可运行。


* 输入：按下“卡布奇诺”
* 参数：无

*  处理过程：Feeder取空杯，传送带传动。四个Part的阀门打开，加热器加热。按照1：1：1比例调节咖啡粉和糖以及牛奶的配比。
*  输出：卡布奇诺



## 3.2 性能需求的规定

### 3.2.1 精度要求
  
由于实力有限，目前只规定了产品类型，具体的口味清淡暂时无法顾及

### 3.2.2 实时性要求
对于实时性的需求不大，反应时间控制在五秒内即可。生产过程不予考虑

### 3.2.3 开放性和扩展性
后期添加产品类型的浓淡之分。本质上是添加了不同的输入按钮。或者可以添加二级输入。需要扩展命令集。

## 3.3 输入输出要求

### 硬件接口：
按钮

### 软件接口：
I/O接口

## 3.4 数据存储和管理能力要求

### 数据保存
在按钮被按下后，需要保存当前的输入。确保不会因为生产期间再次被按下按钮从而产生信号冲突。

## 3.5 故障和错误处理要求
不存在的。
## 3.6 其他特殊要求
要求生产过程中不接受按钮的信号量，短暂屏蔽，生产完成后才可以接受新的输入。

# 4. 用例

## 4.1 用例1：***操作过程

![](http://upload-images.jianshu.io/upload_images/3810775-12b416b1fd6f5758.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

## 4.2 用例2：***实时画面

![](http://upload-images.jianshu.io/upload_images/3810775-36d0b3740845e243.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

# 5. 运行环境规定
## 5.1 硬件设备及接口
STM32、PLC可编程控制器
## 5.2 软件平台及配置
Matlab/Simulink物理建模以及代码模块生成、gcc-ubuntu整体代码生成

## 5.3 通信协议
   超文本咖啡壶控制协议（英文：Hyper Text Coffee Pot Control Protocol，HTCPCP）是一种用于控制、监测和诊断咖啡壶的协议。

# 6. 附录

## 6.1 **协议定义
   这个协议在文档RFC 2324（发布于1998年4月1日）中被定义。尽管互联网国际标准机构经常在4月1日发布一些恶搞之作，他们还是让这个协议看上去像是一个真的、非虚构的协议（比如HTTP）。文本编辑器Emacs甚至完全兼容于这个协议，Mozilla也发布了数个补丁来扩展旗下产品的功能。Mosaic浏览器可能支持此协议。
    HTCPCP是HTTP协议的扩展。HTCPCP请求通过URI架构coffee:来引用，并且还包含了若干种HTTP请求：
    BREW或POST：令HTCPCP服务器（咖啡壶）煮咖啡。GET：从服务器获取咖啡。PROPFIND：获取咖啡的元数据。WHEN：让服务器停止向咖啡中加入牛奶（如适用），即英文"say when"之意。这个协议还定义了两种错误答复：
    406 Not Acceptable（不能接受的）：HTCPCP服务器由于某种原因而暂时不能煮咖啡。服务器在回复中应当包含一组可接受的咖啡类型列表。418 I'm a teapot（我是茶壶）：HTCPCP服务器是一个茶壶。这个错误答复可能是由一个又矮又胖的东西发出的。
    
##### 6.1.1 The BREW method, and the use of POST


   Commands to control a coffee pot are sent from client to coffee
   server using either the BREW or POST method, and a message body with
   Content-Type set to "application/coffee-pot-command".

   A coffee pot server MUST accept both the BREW and POST method
   equivalently.  However, the use of POST for causing actions to happen
   is deprecated.

   Coffee pots heat water using electronic mechanisms, so there is no
   fire. Thus, no firewalls are necessary, and firewall control policy
   is irrelevant. However, POST may be a trademark for coffee, and so
   the BREW method has been added. The BREW method may be used with
   other HTTP-based protocols (e.g., the Hyper Text Brewery Control
   Protocol).

##### 6.1.2 GET method


   In HTTP, the GET method is used to mean "retrieve whatever
   information (in the form of an entity) identified by the Request-
   URI." If the Request-URI refers to a data-producing process, it is
   the produced data which shall be returned as the entity in the
   response and not the source text of the process, unless that text
   happens to be the output of the process.


   In HTCPCP, the resources associated with a coffee pot are physical,
   and not information resources. The "data" for most coffee URIs
   contain no caffeine.

##### 6.1.3 PROPFIND method


   If a cup of coffee is data, metadata about the brewed resource is
   discovered using the PROPFIND method [WEBDAV].

##### 6.1.4 WHEN method


   When coffee is poured, and milk is offered, it is necessary for the
   holder of the recipient of milk to say "when" at the time when
   sufficient milk has been introduced into the coffee. For this
   purpose, the "WHEN" method has been added to HTCPCP. Enough? Say
   WHEN.
