#ifndef __SOCKET_H
#define __SOCKET_H

#include"Type.h"
#include"SocketConfig.h"

#if OS==OS_Unix

#elif OS==OS_Windows
#include<WINSOCK2.H>

#endif // OS

typedef struct sockaddr             SocketAddress; // 通用套接字地址
typedef struct sockaddr_in          IPv4Address; // IPv4套接字地址
typedef struct sockaddr_storage     SocketAddressStorage; // 新通用套接字地址
typedef struct sockaddr_in6         IPv6Address; // IPv6套接字地址

typedef S32                         Socket;



Socket  Socket_Create(S32 family, S32 type, S32 protocol);
S32     Socket_Connect(Socket socket, Const SocketAddress *address, S32 length);
S32     Socket_Bind(Socket socket, Const SocketAddress *address, S32 length);
S32     Socket_Listen(Socket socket, S32 backlog);
Socket  Socket_Accept(Socket listen, SocketAddress *address, S32 *length);
S32     Socket_Close(Socket socket);

S32     Socket_SetOption(Socket socket, S32 level, S32 optname, Const V *optval, S32 optlen); // 连接套接字的状态可以从监听套接字继承
S32     Socket_GetOption(Socket socket, S32 level, S32 optname, V *optval, S32 *optlen);

UT      Socket_Receive(Socket socket, BT *buffer, UT offset, UT length, S32 flags); // 只有完全接收到length个字节才会返回，否则一直阻塞，(offset + length)超过buffer.Size时只接收(buffer.Size - offset)长度
#define Socket_ReceiveLine_PeekBufferSize       256
UT      Socket_ReceiveLine(Socket socket, BT* buffer, UT offset, S32 flags); // 接收直到换行，若接收长度超过buffer.Size则截断并返回0，实际接收长度可见(buffer.Length-offset)
UT      Socket_Send(Socket socket, BT *buffer, UT offset, UT length, S32 flags); // (offset + length)不能超过buffer.Length和buffer.Size

Status  SocketAddress_TransformIntoDotdec(S32 family, Const V *numeric, C *dotdec, UT length);
Status  SocketAddress_TransformIntoNumeric(S32 family, Const C *dotdec, V *numeric);
Status  SocketAddress_Set(S32 family, V *socketaddress, Const C *dotdec, U16 port);


#endif // __SOCKET_H
