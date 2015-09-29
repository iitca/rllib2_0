#ifndef RLENTITY_H
#define RLENTITY_H

#include "RLEntityBase.h"
#include "RLAgentBase.h"
#include "RLEnvironmentBase.h"
#include "RLStateActionBase.h"
#include <iostream>
#include <fstream>
#include <string>


namespace RLENTITY_NMSPC
{
	template<typename Ty1, typename Ty2>
	class RLEntity : public RLEntityBase<Ty1, Ty2>
	{
	public:
		RLEntity(RLAgentBase<Ty1, Ty2>* agent, RLEnvironmentBase<Ty1, Ty2>* env) : RLEntityBase(agent, env){ this->LoadQFile(); };
		virtual unsigned int ObsrvCurrState() override;
		virtual unsigned int SelAction() override;
		virtual unsigned int PerfAction() override;
		virtual unsigned int ObsrvNextState() override;
		virtual unsigned int GetReward() override;
		virtual unsigned int AdjQ() override;
		virtual unsigned int Reset() override;
		virtual unsigned int Exit() override;
	private:
		void StoreQFile();
		void LoadQFile();
		double GetQ(std::string);
	};


	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::ObsrvCurrState()
	{
		std::cout << "Observing the current state" << std::endl;
		return rlEnv->GetState();
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::SelAction()
	{
		std::cout << "Selecting the action" << std::endl;
		return rlAgent->SelAction(rlEnv->GetStoredCurrState());
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::PerfAction()
	{
		std::cout << "Performing the action" << std::endl;
		return rlEnv->PerformAction(rlAgent->GetStoredAction());
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::ObsrvNextState()
	{
		std::cout << "Observing the next state" << std::endl;
		return rlEnv->GetState();
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::GetReward()
	{
		std::cout << "Getting the reward" << std::endl;
		return rlEnv->GetReward();
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::AdjQ()
	{
		std::cout << "Adjusting Q value" << std::endl;
		rlAgent->AdjQ(rlEnv->GetStoredPrevState(),
			rlEnv->GetStoredCurrState(),
			rlEnv->GetStoredReward());
		//the returned value will be used to select the next state
		return (unsigned int)rlEnv->IsInGoalState();
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::Reset()
	{
		std::cout << "Reseting....." << std::endl;
		//store in a file
		this->StoreQFile();
		//reset the experiment
		return rlEnv->Reset();
	}

	template<typename Ty1, typename Ty2>
	unsigned int RLEntity<Ty1, Ty2>::Exit()
	{
		std::cout << "Exit" << std::endl;
		return rlEnv->Exit();
	}

	template<typename Ty1, typename Ty2>
	void RLEntity<Ty1, Ty2>::StoreQFile()
	{
		//get the table and the iterator 
		std::map<RLStateActionBase<Ty1, Ty2>, double> table = this->rlAgent->GetTable();
		std::map<RLStateActionBase<Ty1, Ty2>, double>::iterator it = table.begin();
		
		//open a file
		std::ofstream qFile;
		qFile.open("Q_file.txt");
		qFile.clear();
		//store the vals
		for (; it != table.end(); it++){
			qFile << it->first.GetState() << " " << it->first.GetAction() << " Q(" << it->second << ")" << std::endl;
		}
		qFile.close();
	}

	template<typename Ty1, typename Ty2>
	void RLEntity<Ty1, Ty2>::LoadQFile()
	{
		std::ifstream qFile;
		std::string line;
		qFile.open("Q_file.txt");
		if (qFile.is_open()){
			while (std::getline(qFile, line)){
				//if the file is not empty, load the table from the file
				if (line.length() == 0)
					break;
				//the line is not empty - send it to a state and an action
				//create a state
				Ty1 state(line);
				//create an action
				Ty2 action(line);
				//create an state-action
				RLStateActionBase<Ty1, Ty2> stateAction(state, action);
				//get Q
				double Q = this->GetQ(line);
				//store to the table
				this->rlAgent->StoreToTable(stateAction, Q);
			}
			qFile.close();
		}
	}

	template<typename Ty1, typename Ty2>
	double RLEntity<Ty1, Ty2>::GetQ(std::string line)
	{
		int qStart = line.find("Q(")+2;
		int qEnd = 0;
		double Q = 0.0;
		if (qStart != std::string::npos){
			qEnd = line.find(")", qStart);
			if (qEnd != std::string::npos){
				//all the needed tokens found
				std::string val = line.substr(qStart, qEnd - qStart);
				//set value
				std::istringstream(val) >> Q;
			}
		}
		return Q;
	}
}

#endif