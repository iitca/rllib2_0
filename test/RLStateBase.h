#ifndef RLSTATEBASE_H
#define RLSTATEBASE_H

namespace RLENTITY_NMSPC
{
	class RLStateBase
	{
	public:
		virtual bool operator==(RLStateBase&) const = 0;
		virtual bool operator<(RLStateBase&) const = 0;
		virtual bool operator<(const RLStateBase&) const = 0;
	};
}

#endif