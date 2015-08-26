#ifndef RLENTITY_H
#define RLENTITY_H

#include "RLEntityBase.h"
#include "RLAgentBase.h"
#include "RLEnvironmentBase.h"
#include <iostream>

namespace RLENTITY_NMSPC
{
	template<typename Ty1, typename Ty2>
	class RLEntity : public RLEntityBase<Ty1, Ty2>
	{
	public:
		RLEntity(RLAgentBase<Ty1, Ty2>* agent, RLEnvironmentBase<Ty1, Ty2>* env) : RLEntityBase(agent, env){};
		virtual unsigned int ObsrvCurrState() override;
		virtual unsigned int SelAction() override;
		virtual unsigned int PerfAction() override;
		virtual unsigned int ObsrvNextState() override;
		virtual unsigned int GetReward() override;
		virtual unsigned int AdjQ() override;
		virtual unsigned int Reset() override;
		virtual unsigned int Exit() override;
	};

	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::ObsrvCurrState()
	{
		std::cout << "Observing the current state" << std::endl;
		rlEnv->GetState();
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::SelAction()
	{
		std::cout << "Selecting the action" << std::endl;
		rlAgent->SelAction(rlEnv->GetStoredCurrState());
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::PerfAction()
	{
		std::cout << "Performing the action" << std::endl;
		rlEnv->PerformAction(rlAgent->GetStoredAction());
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::ObsrvNextState()
	{
		std::cout << "Observing the next state" << std::endl;
		rlEnv->GetState();
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::GetReward()
	{
		std::cout << "Getting the reward" << std::endl;
		rlEnv->GetReward();
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::AdjQ()
	{
		std::cout << "Adjusting Q value" << std::endl;
		rlAgent->AdjQ(rlEnv->GetStoredPrevState(),
			rlEnv->GetStoredCurrState(),
			rlEnv->GetStoredReward());
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::Reset()
	{
		std::cout << "Reseting....." << std::endl;
		rlEnv->Reset();
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::Exit()
	{
		std::cout << "Exit" << std::endl;
		return 1;
	}

}

#endif