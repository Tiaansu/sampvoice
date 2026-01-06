#pragma once

#include "Effect.h"
#include "EffectManager.h"

template<class ParametersType>
Effect::Effect(const uint32_t number, const int priority, const ParametersType& parameters)
{
    PackWrap(this->packetCreateEffect, SV::ControlPacketType::createEffect, sizeof(SV::CreateEffectPacket) + sizeof(parameters));

    PackGetStruct(&*this->packetCreateEffect, SV::CreateEffectPacket)->effect = reinterpret_cast<uint32_t>(this);
    std::memcpy(PackGetStruct(&*this->packetCreateEffect, SV::CreateEffectPacket)->params, &parameters, sizeof(parameters));
    PackGetStruct(&*this->packetCreateEffect, SV::CreateEffectPacket)->priority = priority;
    PackGetStruct(&*this->packetCreateEffect, SV::CreateEffectPacket)->number = number;

    PackWrap(this->packetDeleteEffect, SV::ControlPacketType::deleteEffect, sizeof(SV::DeleteEffectPacket));

    PackGetStruct(&*this->packetDeleteEffect, SV::DeleteEffectPacket)->effect = reinterpret_cast<uint32_t>(this);

    EffectManager::RegisterEffect(this);
}