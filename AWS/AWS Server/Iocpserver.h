
#ifndef IOCPSERVER_H
#define IOCPSERVER_H

#include <mswsock.h>

#define DEFAULT_PORT        "80"
#define MAX_BUFF_SIZE       8192
#define MAX_WORKER_THREAD   16

typedef enum _IO_OPERATION {
    ClientIoAccept,
    ClientIoRead,
    ClientIoWrite
} IO_OPERATION, *PIO_OPERATION;


typedef struct _PER_IO_CONTEXT {
    WSAOVERLAPPED               Overlapped;
    char                        Buffer[MAX_BUFF_SIZE];
    WSABUF                      wsabuf;
    int                         nTotalBytes;
    int                         nSentBytes;
    IO_OPERATION                IOOperation;
    SOCKET                      SocketAccept; 

    struct _PER_IO_CONTEXT      *pIOContextForward;
} PER_IO_CONTEXT, *PPER_IO_CONTEXT;

typedef struct _PER_SOCKET_CONTEXT {
    SOCKET                      Socket;

    LPFN_ACCEPTEX               fnAcceptEx;

	//
    //linked list for all outstanding i/o on the socket
	//
    PPER_IO_CONTEXT             pIOContext;  
    struct _PER_SOCKET_CONTEXT  *pCtxtBack; 
    struct _PER_SOCKET_CONTEXT  *pCtxtForward;
} PER_SOCKET_CONTEXT, *PPER_SOCKET_CONTEXT;



#endif

#ifdef _IA64_
	#pragma warning(disable:4267)
#endif 

#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
#endif

#define xmalloc(s) HeapAlloc(GetProcessHeap(),HEAP_ZERO_MEMORY,(s))
#define xfree(p)   HeapFree(GetProcessHeap(),0,(p))
#define DEFAULT_PORT "80"
#define WM_TRAY_NOTIFY 0x401
#include "Windows.h"
#include <winsock2.h>
#include <Ws2tcpip.h>
#include <stdio.h>
#include <stdlib.h>
#include <strsafe.h>
#include <time.h>
#include "Shellapi.h"

