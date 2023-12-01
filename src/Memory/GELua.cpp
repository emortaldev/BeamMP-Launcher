///
/// Created by Anonymous275 on 1/30/22
/// Copyright (c) 2021-present Anonymous275 read the LICENSE file for more info.
///

#include "Memory/GELua.h"
#include "Memory/Memory.h"
#include "Memory/Patterns.h"

const char* GameModule = "BeamNG.drive.x64.exe";
const char* DllModule  = "libbeamng.x64.dll";

void GELua::FindAddresses() {
   GELua::State = nullptr;
   auto Base    = Memory::GetModuleBase(GameModule);
   GetTickCount = reinterpret_cast<def::GetTickCount>(
       Memory::FindPattern(GameModule, Patterns::GetTickCount));
   Memory::Print("GetTickCount -> " +
                         Memory::GetHex(reinterpret_cast<uint64_t>(GetTickCount) - Base));
   lua_open_jit = reinterpret_cast<def::lua_open_jit>(
       Memory::FindPattern(GameModule, Patterns::open_jit));
   Memory::Print("lua_open_jit -> " +
                         Memory::GetHex(reinterpret_cast<uint64_t>(lua_open_jit) - Base));
   lua_push_fstring = reinterpret_cast<def::lua_push_fstring>(
       Memory::FindPattern(GameModule, Patterns::push_fstring));
   Memory::Print("lua_push_fstring -> " +
                         Memory::GetHex(reinterpret_cast<uint64_t>(lua_push_fstring) - Base));
   lua_get_field = reinterpret_cast<def::lua_get_field>(
       Memory::FindPattern(GameModule, Patterns::get_field));
   Memory::Print("lua_get_field -> " +
                         Memory::GetHex(reinterpret_cast<uint64_t>(lua_get_field) - Base));
   lua_p_call = reinterpret_cast<def::lua_p_call>(
       Memory::FindPattern(GameModule, Patterns::p_call));
   Memory::Print("lua_p_call -> " +
                         Memory::GetHex(reinterpret_cast<uint64_t>(lua_p_call) - Base));
   lua_createtable = reinterpret_cast<def::lua_createtable>(
       Memory::FindPattern(GameModule, Patterns::lua_createtable));
   Memory::Print("lua_createtable -> " +
                         Memory::GetHex(reinterpret_cast<uint64_t>(lua_createtable) - Base));
   lua_pushcclosure = reinterpret_cast<def::lua_pushcclosure>(
       Memory::FindPattern(GameModule, Patterns::lua_pushcclosure));
   Memory::Print("lua_pushcclosure -> " +
                         Memory::GetHex(reinterpret_cast<uint64_t>(lua_pushcclosure) - Base));
   lua_setfield = reinterpret_cast<def::lua_setfield>(
       Memory::FindPattern(GameModule, Patterns::lua_setfield));
   Memory::Print("lua_setfield -> " +
                         Memory::GetHex(reinterpret_cast<uint64_t>(lua_setfield) - Base));
   lua_settable = reinterpret_cast<def::lua_settable>(
       Memory::FindPattern(GameModule, Patterns::lua_settable));
   Memory::Print("lua_settable -> " +
                         Memory::GetHex(reinterpret_cast<uint64_t>(lua_settable) - Base));
   lua_tolstring = reinterpret_cast<def::lua_tolstring>(
       Memory::FindPattern(GameModule, Patterns::lua_tolstring));
   Memory::Print("lua_tolstring -> " +
                         Memory::GetHex(reinterpret_cast<uint64_t>(lua_tolstring) - Base));
   GEUpdate = reinterpret_cast<def::GEUpdate>(
       Memory::FindPattern(GameModule, Patterns::GEUpdate));
   Memory::Print("GEUpdate -> " +
                         Memory::GetHex(reinterpret_cast<uint64_t>(GEUpdate) - Base));
   lua_settop = reinterpret_cast<def::lua_settop>(
       Memory::FindPattern(GameModule, Patterns::lua_settop));
   Memory::Print("lua_settop -> " +
                         Memory::GetHex(reinterpret_cast<uint64_t>(lua_settop) - Base));

    update_function = reinterpret_cast<def::update_function>(
            Memory::FindPattern(GameModule, Patterns::update_function));
    Memory::Print("testupdatefunction -> " +
                          Memory::GetHex(reinterpret_cast<uint64_t>(update_function) - Base));
}