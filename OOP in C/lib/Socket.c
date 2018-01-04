#include"Socket.h"
#include"Exception.h"
#include<stdarg.h> // va_arg()
#include<errno.h> // errno
#include<stdio.h> // for debug

#if OS==OS_Unix
#include<arpa/inet.h> // 地址转换(inet_aton inet_addr inet_ntoa / inet_pton inet_ntop)
#include<netinet/in.h> // 套接字地址(sockaddr_in sockaddr_in6 sockaddr_storage)、字节序(htonl ntohl htons ntohs)、地址存储长度(INET_ADDRSTRLEN INET6_ADDRSTRLEN)
#include<stdlib.h> // getenv() atoi()
#include<sys/types.h> // basic system data types
#include<sys/socket.h> // sockaddr socket() connect() bind() listen() accept() recv() send() close()
#include<sys/stat.h> // for S_xxx file mode constants
#include<unistd.h> // sleep() close()

#elif OS==OS_Windows

#endif // OS

Status SocketCreateFailHandler(va_list args);
Status SocketConnectFailHandler(va_list args);
Status SocketBindFailHandler(va_list args);
Status SocketListenFailHandler(va_list args);

Socket Socket_Create(S32 family, S32 type, S32 protocol){
    Socket s;
    if((s = socket(family, type, protocol)) < 0){
        Exception_Print(Exception_SocketCreateFailException, errno, &Exception_Buffer, "%d Socket Create Fail\n", socket);
        Exception_Catch(Exception_SocketCreateFailException, &SocketCreateFailHandler, &s, family, type, protocol);
    }
    return s;
}

Status SocketCreateFailHandler(va_list args){
    Socket *socket = va_arg(args, Socket*);
    S32 family = va_arg(args, S32);
    S32 type = va_arg(args, S32);
    S32 protocol = va_arg(args, S32);
    UT n = 1;

    while(*socket < 0){
        n *= 2;
        #if OS==OS_Unix
            sleep(n); // 挂起n秒
        #elif OS==OS_Windows
            Sleep(n * 1000); // 挂起n秒
        #endif // OS
        *socket = Socket_Create(family, type, protocol);
    }
    Exception_Print(Exception_ResumeException, errno, &Exception_Buffer, "%d Socket Create Succeed\n", *socket);
    return SUCCESS;
}



S32 Socket_Connect(Socket socket, Const SocketAddress *address, S32 length){
    S32 status;
    if((status = connect(socket, address, length)) < 0){
        Exception_Print(Exception_SocketConnectFailException, errno, &Exception_Buffer, "%d Socket Connect Fail\n", status);
        Exception_Catch(Exception_SocketConnectFailException, &SocketConnectFailHandler, &socket, address, length, &status);
    }
    return status;
}

Status SocketConnectFailHandler(va_list args){
    Socket *socket = va_arg(args, Socket*);
    Const SocketAddress *address = va_arg(args, Const SocketAddress*);
    S32 length = va_arg(args, S32);
    S32 *status = va_arg(args, S32*);
    UT n = 1;

    while(*status < 0){
        n *= 2;
        #if OS==OS_Unix
            sleep(n); // 挂起n秒
        #elif OS==OS_Windows
            Sleep(n * 1000); // 挂起n秒
        #endif // OS
        *status = connect(*socket, address, length);
    }
    Exception_Print(Exception_ResumeException, errno, &Exception_Buffer, "%d Socket Connect Succeed\n", *socket);
    return SUCCESS;
}



S32 Socket_Bind(Socket socket, Const SocketAddress *address, S32 length){
    S32 status;
    if((status = bind(socket, address, length)) < 0){
        Exception_Print(Exception_SocketBindFailException, errno, &Exception_Buffer, "%d Socket Bind Fail\n", status);
        Exception_Catch(Exception_SocketBindFailException, &SocketBindFailHandler, &socket, address, length, &status);
    }
    return status;
}

Status SocketBindFailHandler(va_list args){
    Socket *socket = va_arg(args, Socket*);
    Const SocketAddress *address = va_arg(args, Const SocketAddress*);
    S32 length = va_arg(args, S32);
    S32 *status = va_arg(args, S32*);
    UT n = 1;

    while(*status < 0){
        n *= 2;
        #if OS==OS_Unix
            sleep(n); // 挂起n秒
        #elif OS==OS_Windows
            Sleep(n * 1000); // 挂起n秒
        #endif // OS
        *status = bind(*socket, address, length);
    }
    Exception_Print(Exception_ResumeException, errno, &Exception_Buffer, "%d Socket Bind Succeed\n", *socket);
    return SUCCESS;
}




S32 Socket_Listen(Socket socket, S32 backlog){
    C *ptr;
    if((ptr = getenv("LISTENQ")) != NULL){
        backlog = atoi(ptr) > backlog ? atoi(ptr) : backlog;
    }

    S32 status;
    if((status = listen(socket, backlog)) < 0){
        Exception_Print(Exception_SocketListenFailException, errno, &Exception_Buffer, "%d Socket Listen Fail\n", status);
        Exception_Catch(Exception_SocketListenFailException, &SocketListenFailHandler, &socket, backlog, &status);
    }
    return status;
}

Status SocketListenFailHandler(va_list args){
    Socket *socket = va_arg(args, Socket*);
    S32 backlog = va_arg(args, S32);
    S32 *status = va_arg(args, S32*);
    UT n = 1;

    while(*status < 0){
        n *= 2;
        #if OS==OS_Unix
            sleep(n); // 挂起n秒
        #elif OS==OS_Windows
            Sleep(n * 1000); // 挂起n秒
        #endif // OS
        *status = listen(*socket, backlog);
    }
    Exception_Print(Exception_ResumeException, errno, &Exception_Buffer, "%d Socket Bind Succeed\n", *socket);
    return SUCCESS;
}



Socket Socket_Accept(Socket listen, SocketAddress *address, S32 *length){
    Socket connect;
    while((connect = accept(listen, address, length)) < 0){
        Exception_Print(Exception_SocketAcceptFailException, errno, &Exception_Buffer, "%d Socket Accept Fail\n", connect);
    }
    return connect;
}



S32 Socket_Close(Socket socket){
    #if OS==OS_Unix
        return close(socket);
    #elif OS==OS_Windows
        return closesocket(socket);
    #endif // OS
}



UT Socket_Receive(Socket socket, BT *buffer, UT offset, UT length, S32 flags){
    if(buffer == NULL || buffer->Buffer == NULL || buffer->Size == 0){
        Exception_Print(Exception_NullPointerException, errno, &Exception_Buffer, "%d Socket ReadBuffer Is NULL\n", socket);
        Exception_Catch(Exception_NullPointerException, NULL);
        return 0;
    }

    UT readable = length;
    if((offset + length) > buffer->Size){
        readable = (buffer->Size > offset ? (buffer->Size - offset) : 0);
        Exception_Print(Exception_ArrayIndexOutOfBoundsException, errno, &Exception_Buffer, "%d Socket ReceiveBuffer Is Not Enough\n", socket);
        Exception_Catch(Exception_ArrayIndexOutOfBoundsException, NULL);
    }

    ST n;
    buffer->Length = offset;
    while(readable > 0){
        if((n = recv(socket, buffer->Buffer + buffer->Length, readable, flags)) < 0){
            if(errno == EINTR || errno == EAGAIN){
                continue;
            }else{ // 可能超时或其他原因
                Exception_Print(Exception_SocketReceiveFailException, errno, &Exception_Buffer, "%d Socket Receive Fail [Timeout HostUnreachable Or Other Reasons]\n", socket);
                Exception_Catch(Exception_SocketReceiveFailException, NULL);
                break;
            }
        }else if(n == 0){ // 可能对方关闭Socket
            Exception_Print(Exception_SocketReceiveFailException, errno, &Exception_Buffer, "%d Connection Disable [SocketClosed Or Other Reasons]\n", socket);
            Exception_Catch(Exception_SocketReceiveFailException, NULL);
            break;
        }else{
            buffer->Length += n;
            readable -=n;
        }
    }
    return buffer->Length - offset;
}

UT Socket_ReceiveLine(Socket socket, BT* buffer, UT offset, S32 flags){
    if(buffer == NULL || buffer->Buffer == NULL || buffer->Size == 0){
        Exception_Print(Exception_NullPointerException, errno, &Exception_Buffer, "%d Socket ReceiveLineBuffer Is NULL\n", socket);
        Exception_Catch(Exception_NullPointerException, NULL);
        return 0;
    }

    C peekBuffer[Socket_ReceiveLine_PeekBufferSize];
    UT peekLength;

    buffer->Length = offset;
    UT position = buffer->Size;
    ST n, i;
    while(buffer->Length < position){
        peekLength = (buffer->Length + Socket_ReceiveLine_PeekBufferSize) > position ?  (position - buffer->Length) : Socket_ReceiveLine_PeekBufferSize;
        n = recv(socket, peekBuffer, peekLength, flags|MSG_PEEK);
        for(i = 0; i < n; i++){
            if((buffer->Buffer[buffer->Length + i] = peekBuffer[i]) == '\n'){
                i += 1;
                position = buffer->Length + i;
                break;
            }
        }
        n = recv(socket, peekBuffer, i, flags);
        buffer->Length += n;
    }

    if(buffer->Buffer[buffer->Length - 1] == '\n')
        return buffer->Length - offset;
    else
        return 0; // 接收长度超过buffer.Size
}

UT Socket_Send(Socket socket, BT *buffer, UT offset, UT length, S32 flags){
    if(buffer == NULL || buffer->Buffer == NULL || buffer->Size == 0){
        Exception_Print(Exception_NullPointerException, errno, &Exception_Buffer, "%d Socket SendBuffer Is NULL\n", socket);
        Exception_Catch(Exception_NullPointerException, NULL);
        return 0;
    }

    UT writeable = length;
    UT written = (buffer->Size > buffer->Length ? buffer->Length : buffer->Size);
    if((offset + length) > written){
        writeable = (written > offset ? (written - offset) : 0);
        Exception_Print(Exception_ArrayIndexOutOfBoundsException, errno, &Exception_Buffer, "%d Socket SendBuffer Is Not Enough\n", socket);
        Exception_Catch(Exception_ArrayIndexOutOfBoundsException, NULL);
    }

    ST n;
    written = offset;
    while(writeable > 0){
        if((n = send(socket, buffer->Buffer + written, writeable, flags)) <= 0){
            if(errno == EINTR || errno == EAGAIN){
                continue;
            }else{ // 可能超时或其他原因
                Exception_Print(Exception_SocketSendFailException, errno, &Exception_Buffer, "%d Socket Send Fail [Timeout Or Other Reasons]\n", socket);
                Exception_Catch(Exception_SocketSendFailException, NULL);
                break;
            }
        }else{
            written += n;
            writeable -= n;
        }
    }
    return written - offset;
}



S32 Socket_SetOption(Socket socket, S32 level, S32 optname, Const V *optval, S32 optlen){

    S32 n;
    if((n = setsockopt(socket, level, optname, optval, optlen)) < 0){
        Exception_Print(Exception_SocketSetOptionFailException, errno, &Exception_Buffer, "%d Socket Set Option Fail\n", socket);
        Exception_Catch(Exception_SocketSetOptionFailException, NULL);
    }
    return n;
}

S32 Socket_GetOption(Socket socket, S32 level, S32 optname, V *optval, S32 *optlen){

    S32 n;
    if((n = getsockopt(socket, level, optname, optval, optlen)) < 0){
        Exception_Print(Exception_SocketGetOptionFailException, errno, &Exception_Buffer, "%d Socket Get Option Fail\n", socket);
        Exception_Catch(Exception_SocketGetOptionFailException, NULL);
    }
    return n;
}



Status SocketAddress_TransformIntoDotdec(S32 family, Const V *numeric, C *dotdec, UT length){
    #if OS == OS_Unix
    if(inet_ntop(family, numeric, dotdec, length) != NULL){
        return SUCCESS;
    #elif OS == OS_Windows
    C *ptr; // 仅支持IPv4
    if((ptr =inet_ntoa((*(struct in_addr *)numeric))) != NULL){
        strncpy(dotdec, ptr, length);
        return SUCCESS;
    #endif // OS
    }else{
        Exception_Print(Exception_SocketAddressTransformFailException, errno, &Exception_Buffer, "0x%X... Can Not Be Tansform Into Dotdec\n", ((S32 *)numeric));
        Exception_Catch(Exception_SocketAddressTransformFailException, NULL);
        return FAILURE;
    }

}

Status SocketAddress_TransformIntoNumeric(S32 family, Const C *dotdec, V *numeric){

    #if OS == OS_Unix
    S32 n;
    if((n = inet_pton(family, dotdec, numeric)) > 0){
    return SUCCESS;
    } else if(n == 0){
        Exception_Print(Exception_IllegalSocketAddressException, errno, &Exception_Buffer, "%s Illegal Socket Address\n", dotdec);
        Exception_Catch(Exception_IllegalSocketAddressException, NULL);
        return FAILURE;
    #elif OS == OS_Windows
    U32 n; //仅支持IPv4
    if((n = inet_addr(dotdec)) != INADDR_NONE){
        ((struct in_addr *)numeric)->S_un.S_addr = n;
        return SUCCESS;
    #endif // OS
    }else{
        Exception_Print(Exception_SocketAddressTransformFailException, errno, &Exception_Buffer, "%s Can Not Be Tansform Into Numeric\n", dotdec);
        Exception_Catch(Exception_SocketAddressTransformFailException, NULL);
        return FAILURE;
    }
}

Status SocketAddress_Set(S32 family, V *socketaddress, Const C *dotdec, U16 port){

    if(family == AF_INET){
        memset(socketaddress, 0, sizeof(IPv4Address));
        ((IPv4Address *)socketaddress)->sin_family = AF_INET;
        ((IPv4Address *)socketaddress)->sin_port = htons(port);
        if(dotdec == NULL){
            ((IPv4Address *)socketaddress)->sin_addr.s_addr = htonl(INADDR_ANY);
        }else{
            SocketAddress_TransformIntoNumeric(family, dotdec, &(((IPv4Address *)socketaddress)->sin_addr));
        }
        return SUCCESS;
    }

    return FAILURE;
}

























