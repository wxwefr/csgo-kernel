#pragma warning (disable : 4700)

#include <iostream>
#include "kernelinterface.hpp"
#include "offsets.hpp"


using namespace std;

int main()
{
	int nun = 0;

	KernelInterface Driver = KernelInterface("\\\\.\\gorz");

	ULONG address = Driver.GetClientAddress();
	ULONG processid = Driver.GetProcessId();

	std::cout << " ClientAddress " << std::hex << address << std::endl;
	std::cout << " ProcessID " << processid << std::endl;

	while (true)
	{
		uint32_t LocalPlayerAddress = Driver.ReadVirtualMemory<uint32_t>(processid, address + hazedumper::signatures::dwLocalPlayer, sizeof(uint32_t));

		float num = Driver.ReadVirtualMemory<float>(processid, LocalPlayerAddress + hazedumper::netvars::m_flFlashMaxAlpha, sizeof(float));
		Driver.WriteVirtualMemory(processid, LocalPlayerAddress + hazedumper::netvars::m_flFlashMaxAlpha, 0.f, sizeof(0.f));

		float num2 = Driver.ReadVirtualMemory<int>(processid, LocalPlayerAddress + hazedumper::netvars::m_iFOV, sizeof(bool));
		Driver.WriteVirtualMemory(processid, LocalPlayerAddress + hazedumper::netvars::m_iFOV, 120, sizeof(120));


	}

}