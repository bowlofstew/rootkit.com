#include <winsock2.h>
#include <windows.h>
#include <time.h>
#include "ntdll.h"

#define UNICODE_MAX_PATH MAX_PATH*2

typedef NTSTATUS (WINAPI* NTQUERYVOLUMEINFORMATIONFILE)(HANDLE,PIO_STATUS_BLOCK,PVOID,ULONG,FS_INFORMATION_CLASS);

ULONG getSectorsPerAllocationUnit(PVOID,FS_INFORMATION_CLASS);
ULONG getBytesPerSector(PVOID,FS_INFORMATION_CLASS);
void setAvailableAllocationUnits(PVOID,FS_INFORMATION_CLASS,ULONGLONG);
void setAvailableQuotaAllocationUnits(PVOID,FS_INFORMATION_CLASS,ULONGLONG);
HANDLE OpenHdHidingRegKey(void);
ULONGLONG GetEnumValue(HANDLE,ULONG,PANSI_STRING);

#ifndef __NTQUERYVOLUMEINFORMATIONFILE__
#define __NTQUERYVOLUMEINFORMATIONFILE__

NTQUERYVOLUMEINFORMATIONFILE OldNtQueryVolumeInformationFile;
NTSTATUS WINAPI NewNtQueryVolumeInformationFile(HANDLE,PIO_STATUS_BLOCK,PVOID,ULONG,FS_INFORMATION_CLASS);

#endif