/*
 * authorityServices.h
 *
 *  Created on: 26-12月-08
 *      Author: root
 */

#ifndef AUTHORITYSERIVCES_H_
#define AUTHORITYSERIVCES_H_
#include "../base/base.h"
/*
*功能:验证用户进行操作是否具备相应权限
*@actName :in
*@username :in
*return ,具备权限 return true ,else return false
*/
boolean isAuthorityValid(char *actName,char *username);
#endif /* AUTHORITYSERIVCES_H_ */
