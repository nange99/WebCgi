/*
*sessionModel.h
*�Ự���ݽṹ����
*/
#ifndef SESSIONMODEL_H_
#define SESSIONMODEL_H_
struct Session{
	long sessionId;         //�ỰID
	char username[40];      //�û���
	long acessTime;         //����ʱ��
	char loginIp[20];       //��¼IP
};
/*
* �Ự��Ϣ��������
*/

struct Sessions{
	struct Session *session;   //�Ự��Ϣָ��
	struct Sessions *next;     //��һ���Ự��Ϣָ��
};

#endif /* SESSIONMODEL_H_ */