/*
 * sessionServices.h
 *
 *  Created on: 26-12月-08
 *      Author: root
 */

#ifndef SESSIONSERVICES_H_
#define SESSIONSERVICES_H_
#include "../base/base.h"
#include "../model/sessionModel.h"

/*
*功能:确定该session是否有效
*@ sessionId :in 
*@ username  :in
* return 如果session有效,返回真
* 说明:如果会话存在且未过期则返回真
*/
boolean isSessionValid(long sessionId,char *username);
/*
 * 功能，保存会话信息
 * @ username :in
 * @ loginIp :in
 * return sessionId
 */
boolean saveSessionService(char *username,char *loginIp);
/*
*功能:根据sessionId 更新最后访问时间,将过期的会话删除
*sessionId :in
*return ,success return true,else return false
*/
boolean updateSessionService(long sessionId);
/*
*功能:根据sessionId 删除会话
*@ sessionId :in out
*return 
*/
boolean deleteSessionService(long sessionId);
/*
*功能：根据数据结构中设置的数据作为条件查询符合条件的会话
*@conditions :in　在这里设置要查询会话的条件
*return 
*说明:查询条件字符串采用"name1=value1;name2=value2;"的形式,支持模糊查询
*暂未用到
*/
boolean querySessionsService(char *conditions);
/*
*功能:确定该用户是否登录
*@ username in 
* return 如果已登录,返回真
*/
boolean isUserLogin(char *username);
/*
*功能:通过sessionId或username获取会话各字段的值
*@session :in out
*success return true,else return false
*说明:如果sessionId username同时存在,则只匹配sessionId
*/
boolean getSessionService(struct Session *session);
#endif /* SESSIONSERVICES_H_ */

