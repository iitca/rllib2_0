#ifndef RLACTIONBASE_H
#define RLACTIONBASE_H


namespace RLENTITY_NMSPC
{
	class RLActionBase
	{
	public:
		virtual bool operator==(RLActionBase&) const = 0;
		virtual void Randomize() = 0;
	};
}

#endif