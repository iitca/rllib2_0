#ifndef RLFSM_H
#define RLFSM_H

#include "RLFSMStateInput.h"
#include "RLFSMTransitionTable.h"
#include "RLEntityBase.h"


namespace RLFSM_NMSPC
{
	
	/*forward declaration*/
	template<typename Ty1, typename Ty2> class RLFSMState;

	/*fsm for rl*/
	template<typename Ty1, typename Ty2>
	class RLFSM
	{
	public:
		RLFSM(RLFSMTransitionTable*, RLENTITY_NMSPC::RLEntityBase<Ty1, Ty2>*);
		void Update();
		void SetFSMState(RLFSMState<Ty1, Ty2>*);
		RLFSMTransitionTable* GetTransitionTable();
		RLENTITY_NMSPC::RLEntityBase<Ty1, Ty2>* GetRLEntity();
	private:
		RLFSMState<Ty1, Ty2>* currentFSMState;
		RLFSMTransitionTable* rltt;
		RLENTITY_NMSPC::RLEntityBase<Ty1, Ty2>* rlent;
	};

	template<typename Ty1, typename Ty2>
	RLFSM<Ty1, Ty2>::RLFSM(RLFSMTransitionTable* rltt, RLENTITY_NMSPC::RLEntityBase<Ty1, Ty2>* rlent)
	{
		this->rltt = rltt;
		this->rlent = rlent;
		this->currentFSMState = nullptr;
	}

	template<typename Ty1, typename Ty2>
	void RLFSM<Ty1, Ty2>::Update()
	{
		for (;;)
		{
			if (currentFSMState != nullptr){
				//print out the state name
				currentFSMState->Print();
				//execute the actions for the state

				//TO DO:
				//do function should return input to the next state
				unsigned int t = currentFSMState->Do(this);
				//then 'data' is fed to the transit function
				//also a transition table should be more flexible
				//transit to another state
				currentFSMState->Transit(this, t);
			}
		}
	}

	template<typename Ty1, typename Ty2>
	void RLFSM<Ty1, Ty2>::SetFSMState(RLFSMState<Ty1, Ty2>* fsmState)
	{
		currentFSMState = fsmState;
	}

	template<typename Ty1, typename Ty2>
	RLFSMTransitionTable* RLFSM<Ty1, Ty2>::GetTransitionTable()
	{
		return this->rltt;
	}

	template<typename Ty1, typename Ty2>
	RLENTITY_NMSPC::RLEntityBase<Ty1, Ty2>* RLFSM<Ty1, Ty2>::GetRLEntity()
	{
		return this->rlent;
	}

}


#endif