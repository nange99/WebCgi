/*
 * base.h
 *
 *  Created on: 26-12月-08
 *      Author: root
 */

#ifndef BASE_H_
#define BASE_H_
#include <string.h>
//定义布尔值，1为真，0为假
#define true 1
#define false 0
//定义布尔类型 boolean
#define boolean int
//定义出错常量
#define error -2
//定义无相关结果常量
#define none -1
#define uchar unsigned char 
//定义错误信息的最大长度
//#define MAX_ERROR_MSG_SIZE 200

//定义全局变量 数据表最大记录数  
#define MAX_TABLE_RECORDS 4000


//定义全局变量 临时文件,用于数据交换
static char tempFilePath[50]="/info/tempfile"; 
 
//定义全局变量 用户数据库路径
static char userFilePath[50]="/app/webapp/datas/user.db";

//定义全局变量 会话数据库路径
static char sessionFilePath[50]="/app/webapp/datas/session.db";

//定义全局变量 系统运行数据库日志路径
static char loginLogFilePath[50]="/app/webapp/datas/loginLog.db";

//定义全局变量 系统操作数据库日志路径
static char setupLogFilePath[50]="/app/webapp/datas/setupLog.db";

////定义全局变量 供读取数据库日志路径
static char readLogFilePath[70]="/app/webapp/datas/readLog.db";
//定义全局变量 设备告警文件路径
static char alertFilePath[70]="/app/webapp/datas/alert.db";

//定义全局变量 设备光口和电口告警文件路径
//static char FTAlertFilePath[70]="/app/webapp/datas/FTAlert.db";
static char currentAlertFilePath[70]="/app/webapp/datas/currentAlert.db";
//定义全局变量 WEB版本信息文件路径
static char versionFilePath[70]="/app/webapp/datas/web_version.db";
//定义命令输出文件路径
//static char commandOutputFile[70]="/app/webapp/datas/commandInfo.txt";
static char commandOutputFile[70]="/info/snmp";//为防止对flash多次读写 
//定义日记文件路径
static char logFilePath[50]="/app/log/syslog";
//系统参数文件路径 
static char systemInfoPath[50] = "/app/webapp/datas/system.db";
//定义空文件
static char blankFilePath[50]="/app/webapp/datas/blank.txt";
//snmp代理参数配置导入文件
static char uploadAgentConfPath[128]="/app/webapp/httpd/html/file/agent.conf";
//snmp代理参数配置文件路径
static char srcAgentConfPath[128]="/app/etc/agent.conf";
//备份snmp代理参数配置文件的输出路径
static char bakAgentConfPath[128]="/app/webapp/httpd/html/file/agent.gtb";

//定义会话有效时长,10分钟
static long sessionExpireTime = 10 * 60;
//定义设备IP
static char hostIp[20]="127.0.0.1";
//static char hostIp[20]="192.168.0.100";
//SNMP获取数据命令
//static char snmpGetCom[100]="/app/webapp/softwave/snmpget -v 2c -c GLBLTECH ";
static char snmpGetCom[100]="/app/bin/snmpget -v 2c -c GLBLTECH ";
//SNMP设置数据命令
//static char snmpSetCom[100]="/app/webapp/softwave/snmpset -v 2c -c GLBLTECH ";
static char snmpSetCom[100]="/app/bin/snmpset -v 2c -c GLBLTECH ";

//定义时间结构
struct datetime{
	char year[5];
	char month[3];
	char date[3];
	char hour[3];
	char minute[3];
	char second[3];
};
//定义分页结构
struct Page{
	int current;//当前页
	int start;//开始索引 索引从1开始
	int end;//结束索引
	int total;//总页数
	int pageSize;//每页大小
};
//定义时间范围
struct TimeRange{
	long from;
	long to;
};
//扩展Trap地址和端口（支持4个Trap服务器）
typedef struct tagNETWORK_TRAP_ADDR
{   
    unsigned long	ulIpAddress[4];		/*TRAP服务器IP地址*/
    unsigned long	ulPort[4];			/*TRAP服务器端口*/
    unsigned char	ucIsFlag[4];		/*该记录是否有效标记*/
} NETWORK_TRAP_ADDR;

/*
 * 功能：设置错误信息
 * @ msg in
 * 返回 空
 */
//void  webLog(char *msg);
void webLog(const char *fmt, ...);

/***********************************************************
this function is use to format conversion 
for example,
"05 19 04 4B 41 00 5A 0A 00 00 00 00 00 00 00 00 00 40 00 00 00 01 00 0
0 00 01 3C"
to 
"0519044B41005A0A0000000000000000004000000001000000013C"
***************************************************************/
char *trimEx(char *s);

/***********************************************************
this function is use to format conversion 
for example,
"0519044B41005A0A0000000000000000004000000001000000013C"  
to 
"05 19 04 4B 41 00 5A 0A 00 00 00 00 00 00 00 00 00 40 00 00 00 01 00 0
0 00 01 3C"
***************************************************************/
char *AddBlank(char *src, char *dst);

/* 
*对数据表记录合法性检验 
*@str		:in	记录	
*@fieldNum		:in 	记录字段数
*return ,合法返回 true,else return false
*/
static boolean checkTableRecordValid(const char *str,const int fieldNum){
	boolean valid = false;
	int i = 0;
	int fieldCounter=0;
	int strLen = strlen(str);
	for(i = 0;i < strLen; i++){
		//field 
		if(str[i] != ' ' && str[i] != '\n' && str[i] !='\t' && str[i] != '\r'){
			valid = true;
		}else{
			if(valid){
				++fieldCounter;
				valid = false;
			}
		}
	}
	if(fieldCounter != fieldNum){
		return false;
	}
	return true;
}

#endif /* BASE_H_ */
