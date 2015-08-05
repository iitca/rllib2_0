#ifndef RLSYSTEM_H
#define RLSYSTEM_H

#include "RLFSM.h"
#include "RLEntity.h"

namespace RLSYSTEM_NMSPC
{
	template<typename Ty1, typename Ty2>
	class RLSystem
	{
	public:
		RLSystem(RLFSM_NMSPC::RLFSM<Ty1, Ty2>*, RLENTITY_NMSPC::RLEntity<Ty1, Ty2>*);
		void Do(void);
	private:

		RLFSM_NMSPC::RLFSM* rlFSM;
		RLENTITY_NMSPC::RLEntity<Ty1, Ty2>* rlEntity;

	};

	template<typename Ty1, typename Ty2>
	RLSystem<Ty1, Ty2>::RLSystem(RLFSM_NMSPC::RLFSM<Ty1, Ty2>* fsm, RLENTITY_NMSPC::RLEntity<Ty1, Ty2>* ent)
	{
		this->rlFSM = fsm;
		this->rlEntity = ent;
	}

	template<typename Ty1, typename Ty2>
	void RLSystem<Ty1, Ty2>::Do()
	{
		for (;;)
		{
			//RLFSMStateInput input;
			//rlFSM ->update(input);
		}
	}
}

#endif