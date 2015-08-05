#ifndef RLFSMSTATE_H
#define RLFSMSTATE_H

#include "RLFSMStatesEnum.h"
#include "RLResources.h"
#include <iostream>


namespace RLFSM_NMSPC
{
	/*forward declaration*/
	template<typename Ty1, typename Ty2>
	class RLFSM;
	/*the base fsm_state class */
	template<typename Ty1, typename Ty2>
	class RLFSMState
	{
	protected:
		RLFSMStatesEnum thisStateName;
		
	public:
		//the state's activity
		virtual void Do(RLFSM<Ty1, Ty2>*) = 0;
		//transition to the next state
		void Transit(RLFSM<Ty1, Ty2>*);
		//print the name of the state
		void Print();
	};

	template<typename Ty1, typename Ty2>
	void RLFSMState<Ty1, Ty2>::Print()
	{
		std::cout << "State name : " << this->thisStateName << std::endl;
	}

	template<typename Ty1, typename Ty2>
	void RLFSMState<Ty1, Ty2>::Transit(RLFSM<Ty1, Ty2>* rlfsm)
	{
		/*here we get the next state from the transition table
		and create an instance of the new state through the factory*/
		//get the next state's name
		RLFSMStatesEnum nextStateName = rlfsm->GetTransitionTable()->GetNextFSMState(this->thisStateName);
		//create the next state instance
		RLFSMState<Ty1, Ty2>* state = RLFSMFactory<Ty1, Ty2>::CreateState(nextStateName);
		//assign the next state to the FSM
		rlfsm->SetFSMState(state);
		//delete this object
		delete this;
	}
}

#endif