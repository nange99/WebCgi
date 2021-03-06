/*
 * adstring.h
 *
 *  Created on: 26-12月-08
 *      Author: root
 */

#ifndef ADSTRING_H_
#define ADSTRING_H_
#include "../base/base.h"
/*
   * 功能 找出字符c在字符串str中的位置
 * @str :in 字符串
 * @c   :in 指定的字符
 * @skip :in 要指定第几次出现该字符的位置 skip = 0表示第一次出现该字符的位置
 * return error 表示输入有误，none表示 没有找到，其他表示已经找到，并
   * 返回其位置
 */
int stringIndex(char *str,char c,int skip );
/*
 * 功能：提取子串
 * @ str     :in	父串
 * @ substr  :out	子串
 * @ begin   :in	开始位置
 * @ end     :in	结束位置
 * return 操作成功，返回true ,操作失败 ，返回false
 */
boolean substring(char *str,char *substr,int begin,int end);

/*
 * 功能：字符串内容反向排序
 * @ str :in out  输出覆盖输入
 * return 操作成功，返回 true,失败返回false
 */
boolean stringReverse(char *str);
/*
 * 功能，将字符串转换成长整数
 * @ str in
 * return 转换后的长整数
 */
long str2long(char *str);
/*
 * 功能，将长整形转换成字符串
 * @ str out
 * @ num in
 * return 操作成功，返回true，否则返回false
 */
boolean long2str(char *str,long num);
/*
*功能：将十进制转换为二进制字符串
*@ num :in
*@ binstr :out 输出的二进制字符串
*return 
*/
void int2binstr(const int num,char *binstr);
/*
*功能:去掉字符串后的空格和换行符
*@ str in out
*return 
*/
void trim(char *str);
/*
*功能:将日期转换为常规格式
*@ str :in out
*return 转换后的日期字符串
*/
void dtFormat(char *str);
/*
*功能:将long形时间格式化字符串
*@ lTime :in     以秒为格式的时间
*@ str   :out	 输出准备时间字符串,以"2009-1-1 00:00:00"的格式
*return 
*/
void long2TimeStr(long lTime,char *str);

/*
*功能:将日期字符串转换成long 格式
*@str :in
*return long
*说明:字符串以"2009-1-1 00:00:00"的格式
*/
long str2time_t(char *str);


/*
*功能:将字符串转换为大写字母
*@ str :in out
*return 转换后的字符串
*/
void str2upper(char *str);
/*
*功能:将字符串转换为十六进制字符串
*@ str		:in   输入的字符串
*@ hexstr	:out  输出的字符串
*@ size		:in   要转换的字符串长度,如果是0则表示实际长度
*return 
*/
void str2hexstr(unsigned char *str,char *hexstr,int size);
/*
*功能:将十六进制字符串转换为常规字符串
*@ hexstr :in 十六进制字符串
*return 转换成功 return true,else return false
*/
boolean hextochar(char *hexstr);
/*
*功能:将十六进制字符串转换为常规字符串 替代上面
*@ hexstr :in 十六进制字符串
*return 转换成功 return true,else return false
*/
boolean hextochar1(char *hexstr,unsigned char *outData);
/*
*功能:将十六进制字符串转换为常规字符串 替代上面
*@ hexstr :in 十六进制字符串
*return 转换成功 return true,else return false
*/
boolean dectochar1(char *hexstr,unsigned char *outData);
/*
*功能：将IP转换成long
*@ ip :in  IP地址
*return 转换成功，return long value ,else return error
*/
unsigned long  ip2long(char *ip);
/*
*功能：在字符串中根据指定的分隔符提取第i个元素，i从1开始
*@ str		:in
*@ substr	:out
*@ ch		:分隔符
*@ i		:第几个子串
*return 成功提取第i个元素，则返回真，否则返回假
*/
boolean getItem(char *str,char *substr,char ch,int i);
/*
*功能：在字符串中删除指定元素
*@ str		:in out 父串
*@ delStr	:in     要删除的子串
*return 成功提取第i个元素，则返回真，否则返回假
*/
boolean delItem(char *str,char *delStr);
/*
*功能:将时间字符转换为设备接受的时间字符串
*@ str :in out 
*输入字符串形式 "2009-01-02 12:12:00"
*输出字符串形式 "20090102121200"
*return
*/
void time2str(char *str);
/*
*功能:从字符串中提取变量对应的值
*@str	:in		字符串
*@name	:in		字段名
*@value :out	字段值,输出
*seccess ,return true,else return false
*说明:字符串是"name1=value1;name2=value2;"的形式
*/
boolean getValueByName(const char *str,const char *name,char *value);
/*
*功能:在命令名里提取相关参数
*@ itemName :in
*@ paramName :in
*return 参数值
*/
int getCardNum(char *itemName,char *paramName);
/*
*功能:根据命令执行结果获取结果类型
*@ str  :in
*@ type :out
*return 获取成功 return true,else return false
*/
boolean getItemType(char *str,char *type);
/*
*功能:根据命令执行结果获取结果值
*@ str		:in
*@ value	:out
*return 获取成功 return true,else return false
*/
boolean getItemValue(char *str,char *value);
/*
*功能:将浮点数字符串分为整数部分字符串和小数部分字符串
*@ doubleStr	:in
*@ intStr		:out
*@ decStr		:out
*/
void getIntAndDecOfDoubleStr(char *doubleStr,char *intStr,char *decStr);
/*
*功能:对板卡远端地址进行转换
*@str :in out
*return 
*说明:要转换的字符串形式"-75/-74/-69/-85/"
*/
void tranRemoteAddr(char *str);
/*
*功能:字符串拷贝
*@dest :out
*@src :in
*return 
*说明:用于对远端字符串为40的情况
*/
void copyStrs(char *dest,char *src);
/*
*功能：根据字符串获取机架状态(是否存在该机架)
*@ hasDev	:out
*@ str		:in
*return 
*说明：字符串的形式为"ucDeviceLinkStatus=01 01 01 00 00 00 00 00 00 00 00 00 00 00 00 01;"
*/
void getDevStatusByStr(boolean hasDev[],char *str);
/*
*功能：从字符串中获取各卡类型
*@str	:in
*@sub	:out
*@times :in 第几个子串 从0开始
*return 成功，返回true,否则返回false
*说明：字符串格式"8993 9301 9331 "
*/
boolean getSubItem(char *str,char *sub,int times);
#endif /* ADSTRING_H_ */
