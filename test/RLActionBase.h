#ifndef RLACTIONBASE_H
#define RLACTIONBASE_H


namespace RLENTITY_NMSPC
{
	class RLActionBase
	{
	public:
		virtual bool operator==(RLActionBase&) const = 0;
		virtual void Randomize() = 0; 
		virtual int GetValue() = 0;
		virtual void SetValue(int) = 0;
	};
}

#endif