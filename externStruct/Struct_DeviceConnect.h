
#ifndef   _STRUCTDEVICE_CONNECT_
#define   _STRUCTDEVICE_CONNECT_

#define N1758UDI  3   //число модулей
#define N1758UDO  7
#define N1724     3
#define N1715     1
#define N1747     3

#define KANAL_1758UDI  128 //число каналов
#define KANAL_1758UDO  128
#define KANAL_1724     32
#define KANAL_1715     32
#define KANAL_1747     64

#define MAT_UDI_UDO   1280

#pragma pack(push, 1)

// Вход-Выходные параметры от железа
struct SH_DEVICE_CONNECT
{
      bool    IN_MAT [MAT_UDI_UDO]    ;
      bool    OUT_D[N1758UDO][KANAL_1758UDO];
      double  OUT_A[N1747]   [KANAL_1747];
      bool    IN_D[N1758UDI] [KANAL_1758UDI];
      double  IN_A[N1747]    [KANAL_1747];
      double  IN_A15[N1715]  [KANAL_1715];

};


#pragma pack(pop)

#endif

