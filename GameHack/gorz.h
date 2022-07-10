#pragma once

#include <ntifs.h>

//https://gorz.com/threads/how-to-write-memory-from-kernel-mmcopyvirtualmemory-tutorial.15883/

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath);

NTSTATUS UnloadDriver(PDRIVER_OBJECT pDriverObject);