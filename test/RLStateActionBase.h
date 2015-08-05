#ifndef RLSTATEACTION_H
#define RLSTATEACTION_H

#include "RLStateBase.h"
#include "RLActionBase.h"

namespace RLENTITY_NMSPC
{
	//types: state, action
	template<typename Ty1, typename Ty2> 
		class RLStateActionBase
	{
	public:
		RLStateActionBase(Ty1, Ty2);
		virtual bool operator==(RLStateActionBase&) const;
		virtual bool operator==(const RLStateActionBase&) const;
		virtual bool operator<(RLStateActionBase&) const;
		virtual bool operator<(const RLStateActionBase&) const;
		virtual Ty1 GetState() const;
		virtual Ty2 GetAction() const;
	private:
		Ty1 state;
		Ty2 action;
	};

		template<typename Ty1, typename Ty2>
		RLStateActionBase<Ty1, Ty2>::RLStateActionBase(Ty1 state, Ty2 action)
		{
			this->state = state;
			this->action = action;
		}

		template<typename Ty1, typename Ty2>
		bool RLStateActionBase<Ty1, Ty2>::operator==(RLStateActionBase& rlStateAction) const
		{
			return (this->state == rlStateAction.GetState() &&
				this->action == rlStateAction.GetAction());
		}

		template<typename Ty1, typename Ty2>
		bool RLStateActionBase<Ty1, Ty2>::operator==(const RLStateActionBase& rlStateAction) const
		{
			return (this->state == rlStateAction.GetState() &&
				this->action == rlStateAction.GetAction());
		}

		template<typename Ty1, typename Ty2>
		bool RLStateActionBase<Ty1, Ty2>::operator<(RLStateActionBase& rlStateAction) const
		{
			return (this->state < rlStateAction.state &&
				this->action < rlStateAction.action);
		}

		template<typename Ty1, typename Ty2>
		bool RLStateActionBase<Ty1, Ty2>::operator<(const RLStateActionBase& rlStateAction) const
		{
			return (this->state < rlStateAction.state &&
				this->action < rlStateAction.action);
		}

		template<typename Ty1, typename Ty2>
		Ty1 RLStateActionBase<Ty1, Ty2>::GetState() const
		{
			return this->state;
		}

		template<typename Ty1, typename Ty2>
		Ty2 RLStateActionBase<Ty1, Ty2>::GetAction() const
		{
			return this->action;
		}

}

#endif