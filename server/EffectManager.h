/*
	This is a SampVoice project file
	Author: CyberMor <cyber.mor.2020@gmail.ru>
	open.mp version author: AmyrAhmady (iAmir) <hhm6@yahoo.com>

	See more here https://github.com/AmyrAhmady/sampvoice

	Copyright (c) Daniel (CyberMor) 2020 All rights reserved
*/

#pragma once

#include <set>
#include <mutex>

#include "Effect.h"

class EffectManager {
public: 
    static void RegisterEffect(Effect* effect);
    static void UnregisterEffect(Effect* effect);
    static bool IsValidEffect(Effect* effect);

private:
    static std::set<Effect*> effects_;
    static std::mutex mutex_;
};