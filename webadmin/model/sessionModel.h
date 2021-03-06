/*
*sessionModel.h
*会话数据结构定义
*/
#ifndef SESSIONMODEL_H_
#define SESSIONMODEL_H_
struct Session{
	long sessionId;         //会话ID
	char username[40];      //用户名
	long acessTime;         //访问时间
	char loginIp[20];       //登录IP
};
/*
* 会话信息链表定义
*/

struct Sessions{
	struct Session *session;   //会话信息指针
	struct Sessions *next;     //下一个会话信息指针
};

#endif /* SESSIONMODEL_H_ */
