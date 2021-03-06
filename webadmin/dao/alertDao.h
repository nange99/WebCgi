/*
 * alertDao.h
 *
 *  Created on: 26-12月-08
 *      Author: root
 */

#ifndef ALERTDAO_H_
#define ALERTDAO_H_
#include "../base/base.h"
#include "../model/alertModel.h"

/*
*功能：清空所有告警 
*success return true,else return false;
*/
boolean deleteAllAlertsDao();
/*
*功能：根据数据结构中设置的数据作为条件查询符合条件的用户
*@condition :in　在这里设置要查询用户的条件
*@page :in out 分页信息
*@list :out 查询结果指针
*success return true,else return false;
*/
boolean queryAlertsDao(struct Alert *condition,struct Page *page,struct TimeRange *tr,struct Alerts **list);
/*
*功能：查询当前告警
*@condition :in　在这里设置要查询用户的条件
*@page :in out 分页信息
*@list :out 查询结果指针
*success return true,else return false;
*/
boolean queryCurrentAlertsDao(struct Alert *condition,struct Page *page,struct TimeRange *tr,struct Alerts **list);

struct Alerts *getAlertSortByTime(char *alertDB);

boolean sortAlerts(struct Alerts *head);

void distroyAlert(struct Alerts *head);

struct Alerts *getAlertsLinkHead();

boolean  addAlertTolinks(const struct Alerts *head,const struct Alert *alert);

boolean queryAlertsDao1(struct Alert *condition,struct Page *page,struct TimeRange *tr,struct Alerts **list);
#endif /* ALERTDAO_H_ */