#include "RLSystem.h"
#include "RLFSMStateInput.h"

using namespace RLSYSTEM_NMSPC;


RLSystem::RLSystem(RLFSM_NMSPC::RLFSM* fsm, RLENTITY_NMSPC::RLEntity* ent)
{
	this->rlFSM = fsm;
	this->rlEntity = ent;
}

void RLSystem::Do()
{
	for(;;)
	{
		//RLFSMStateInput input;
		//rlFSM ->update(input);
	}
}