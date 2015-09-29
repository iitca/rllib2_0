#ifndef RLACTIONBASE_H
#define RLACTIONBASE_H

#include <string>


namespace RLENTITY_NMSPC
{
	class RLActionBase
	{
	public:
		virtual bool operator==(RLActionBase&) const = 0;
		virtual bool operator<(const RLActionBase&) const = 0;
		virtual void Randomize() = 0; 
		virtual int GetValue() const = 0;
		virtual void SetValue(int) = 0;
	};
}

#endif 