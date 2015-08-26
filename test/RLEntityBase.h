#ifndef RLENTITYBASE_H
#define RLENTITYBASE_H

#include "RLAgentBase.h"
#include "RLEnvironmentBase.h"

namespace RLENTITY_NMSPC
{
	//the interface for the RLFSM to be connected
	template<typename Ty1, typename Ty2>
	class RLEntityBase
	{
	public:
		RLEntityBase(RLAgentBase<Ty1, Ty2>* agent, RLEnvironmentBase<Ty1, Ty2>* env) : rlAgent(agent), rlEnv(env){}
		virtual unsigned int ObsrvCurrState() = 0;
		virtual unsigned int SelAction() = 0;
		virtual unsigned int PerfAction() = 0;
		virtual unsigned int ObsrvNextState() = 0;
		virtual unsigned int GetReward() = 0;
		virtual unsigned int AdjQ() = 0;
		virtual unsigned int Reset() = 0;
		virtual unsigned int Exit() = 0;
	protected:
		RLAgentBase<Ty1, Ty2>* rlAgent;
		RLEnvironmentBase<Ty1, Ty2>* rlEnv;
	};
}


#endif