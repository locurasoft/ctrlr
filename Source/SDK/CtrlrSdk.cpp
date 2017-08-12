#include "stdafx.h"
#include <luabind/luabind.hpp>
#include <iostream>

extern "C"
{
#include "lua.h"
}

#include "JuceClasses/LJuce.h"


extern "C"
{
	int __declspec(dllexport) luaopen_ctrlrsdk(lua_State* L)
	{
		std::cout << "Registering CtrlrSDK..." << std::endl;

		using namespace luabind;

		open(L);

		LFile::wrapForLua(L);
		LMemoryBlock::wrapForLua(L);
		LMidiMessage::wrapForLua(L);
		LMidiBuffer::wrapForLua(L);
		LString::wrapForLua(L);
		LValueTree::wrapForLua(L);
		LBigInteger::wrapForLua(L);

		return 1;
	}
} // end extern "C"
