#ifndef RLACTION
#define RLACTION

#include "RLActionBase.h"

namespace RLENTITY_NMSPC
{
	class RLDefaultAction : public RLActionBase
	{
	public:
		RLDefaultAction(int mVal) : maxVal(mVal), value(0) {};
		virtual bool operator==(RLActionBase&) const override;
		virtual bool operator<(const RLActionBase&) const override;
		virtual void Randomize() override;
		virtual int GetValue() const override;
		virtual void SetValue(int) override;
	private:
		int maxVal;
	protected:
		int value;
	};
}

#endif